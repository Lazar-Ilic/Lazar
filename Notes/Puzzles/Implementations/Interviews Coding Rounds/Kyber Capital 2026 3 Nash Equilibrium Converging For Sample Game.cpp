/*
 * Nash Equilibrium Solver: Best-Response Dynamics on Fixed Grid Sample
 *
 * Method:
 *   1. Load top-K strategies by probability from a CSV file.
 *   2. Sample M grids (random base capacities) once and fix them.
 *   3. Iterate best-response dynamics:
 *        - Compute EV(s, P) for every strategy s under current mix P
 *          using the fixed grid set.
 *        - Find best response (min EV strategy).
 *        - Mix: P <- (1 - alpha) * P + alpha * e_{best_response}
 *          where alpha = 1 / (iter + 1)  [equal-weight averaging]
 *        - Repeat until max_regret < EPSILON.
 *
 * Compile:
 *   g++ -O3 -fopenmp -std=c++17 -o nash_br_solver nash_br_solver.cpp
 *
 * Run:
 *   ./nash_br_solver [path/to/nash_floodfill_result.csv]
 *   Defaults to ./nash_floodfill_result.csv
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <memory>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <omp.h>

// ── Game constants (must match the original solver) ───────────────────────────
static const int    N        = 50;
static const int    TOLL     = 40;
static const int    MIN_CAP  = 5;
static const int    MAX_CAP  = 30;
static const int    NUM_CAPS = MAX_CAP - MIN_CAP + 1;   // 26
static const int    NEDGE    = 2 * N * (N + 1);         // 5100
static const int    NNODES   = (N + 1) * (N + 1);       // 2601

// ── Solver parameters ─────────────────────────────────────────────────────────
static const int    TOP_K    = 20;       // strategies to load from CSV
static const int    M_GRIDS  = 20000;    // fixed grid sample size
static const int    MAX_ITER = 50000;   // iteration cap
static const long double EPSILON  = 0.01;    // convergence: max regret < EPSILON
static const int    PRINT_EVERY = 40;

// ── Grid helpers ──────────────────────────────────────────────────────────────
inline int eid_R(int x, int y) { return y * N + x; }
inline int eid_U(int x, int y) { return N * (N + 1) + x * N + y; }
inline int nid  (int x, int y) { return x * (N + 1) + y; }

// ── Poisson PMF (running product, no factorial overflow) ──────────────────────
static long double pmf(int k, long double lam) {
    if (k < 0 || lam < 0) return 0.0;
    if (k == 0) return std::exp(-lam);
    if (k > 170) return 0.0;
    long double r = std::exp(-lam);
    for (int i = 1; i <= k; ++i) r *= lam / i;
    return r;
}

// ── Route tables (same structure as original solver) ─────────────────────────
struct RouteTables {
    long double pR [NUM_CAPS][NUM_CAPS];   // routing prob right, per (cR_idx, cU_idx)
    long double ccR[NUM_CAPS][NUM_CAPS];   // E[private cost | go right]
    long double ccU[NUM_CAPS][NUM_CAPS];   // E[private cost | go up]
    long double ec1[NUM_CAPS];             // E[cost | single forced edge]
};

static void build_tables(int a, int h, RouteTables& tab) {
    long double lambda = (2.0 * a) / NEDGE;

    // ec1: forced single edge
    for (int ci = 0; ci < NUM_CAPS; ++ci) {
        int c = ci + MIN_CAP;
        tab.ec1[ci] = static_cast<long double>(c + TOLL * lambda);
    }

    // Per-capacity: P(cost <= h), E[cost | cost<=h], E[cost | cost>h]
    std::vector<long double> pb(NUM_CAPS), ecb(NUM_CAPS), eca(NUM_CAPS);
    for (int ci = 0; ci < NUM_CAPS; ++ci) {
        int c = ci + MIN_CAP;
        long double pp = 0, sb = 0, pa = 0, sa = 0;
        for (int k = 0; k <= 40; ++k) {
            long double p = pmf(k, lambda);
            if (p < 1e-15) break;
            long double cost = c + TOLL * (long double)k;
            if (cost <= h) { pp += p; sb += p * cost; }
            else           { pa += p; sa += p * cost; }
        }
        pb [ci] = pp;
        ecb[ci] = (pp > 1e-15) ? sb / pp : (long double)c;
        eca[ci] = (pa > 1e-15) ? sa / pa : (long double)(c + TOLL);
    }

    // Routing tables
    for (int ri = 0; ri < NUM_CAPS; ++ri) {
        for (int ui = 0; ui < NUM_CAPS; ++ui) {
            long double pbR = pb[ri], paR = 1.0 - pbR;
            long double pbU = pb[ui], paU = 1.0 - pbU;

            long double w00 = paR * paU;
            long double w01 = paR * pbU;
            long double w10 = pbR * paU;
            long double w11 = pbR * pbU;

            long double pr = w10 + 0.5 * (w11 + w00);
            long double pu = w01 + 0.5 * (w11 + w00);

            tab.pR[ri][ui] = static_cast<long double>(pr);

            if (pr > 1e-15) {
                long double nR = w10 * ecb[ri] + 0.5 * w11 * ecb[ri] + 0.5 * w00 * eca[ri];
                tab.ccR[ri][ui] = static_cast<long double>(nR / pr);
            } else {
                tab.ccR[ri][ui] = static_cast<long double>(MIN_CAP + ri);
            }

            if (pu > 1e-15) {
                long double nU = w01 * ecb[ui] + 0.5 * w11 * ecb[ui] + 0.5 * w00 * eca[ui];
                tab.ccU[ri][ui] = static_cast<long double>(nU / pu);
            } else {
                tab.ccU[ri][ui] = static_cast<long double>(MIN_CAP + ui);
            }
        }
    }
}

// ── Strategy ──────────────────────────────────────────────────────────────────
struct Strategy {
    int    a_val;
    int    h_val;
    long double csv_prob;   // original probability from CSV (for reference)
};

// ── Fixed grid sample ─────────────────────────────────────────────────────────
// Each grid is just a flat array of base capacities for each edge.
struct Grid {
    int base[NEDGE];
};

// ── Per-thread workspace ──────────────────────────────────────────────────────
struct Workspace {
    long double flow [NEDGE];
    long double pmass[NNODES];   // reused per strategy in pass 1
    long double probe_mass [NNODES];
    long double probe_score[NNODES];
};

// ── Evaluate all strategies on one fixed grid ─────────────────────────────────
//
// Pass 1: build the flow field from the population mix P (weights Pf[s]).
//         Only strategies with Pf[s] > 0 contribute.
// Pass 2: for each strategy s, walk the probe through the flow field and
//         accumulate expected cost.
//
static void eval_grid(
    const Grid&                        grid,
    const std::vector<long double>&          Pf,          // population weights
    const std::vector<Strategy>&       strats,
    const std::vector<RouteTables>&    tabs,        // one per strategy
    std::vector<long double>&               ev_acc,      // accumulated EV per strategy
    Workspace&                         ws)
{
    int K = (int)strats.size();

    // ── Pass 1: flow field ────────────────────────────────────────────────────
    std::memset(ws.flow, 0, sizeof(long double) * NEDGE);

    for (int s = 0; s < K; ++s) {
        if (Pf[s] < 1e-20f) continue;
        std::memset(ws.pmass, 0, sizeof(long double) * NNODES);
        ws.pmass[nid(0,0)] = Pf[s];

        for (int d = 0; d < 2 * N; ++d) {
            int x0 = (d >= N) ? d - N : 0;
            int x1 = (d <  N) ? d     : N;
            for (int x = x0; x <= x1; ++x) {
                int y  = d - x;
                bool cR = (x < N), cU = (y < N);
                int  v  = nid(x, y);
                long double m = ws.pmass[v];
                if (m < 1e-20f) continue;

                if (cR && cU) {
                    int ir = eid_R(x, y), iu = eid_U(x, y);
                    int ri = grid.base[ir] - MIN_CAP;
                    int ui = grid.base[iu] - MIN_CAP;
                    long double pr = tabs[s].pR[ri][ui];
                    ws.flow[ir] += m * pr;
                    ws.flow[iu] += m * (1.0f - pr);
                    ws.pmass[nid(x+1, y)] += m * pr;
                    ws.pmass[nid(x, y+1)] += m * (1.0f - pr);
                } else if (cR) {
                    ws.flow[eid_R(x,y)] += m;
                    ws.pmass[nid(x+1, y)] += m;
                } else {
                    ws.flow[eid_U(x,y)] += m;
                    ws.pmass[nid(x, y+1)] += m;
                }
            }
        }
    }

    // ── Pass 2: evaluate each strategy as a probe ─────────────────────────────
    for (int s = 0; s < K; ++s) {
        std::memset(ws.probe_mass,  0, sizeof(long double) * NNODES);
        std::memset(ws.probe_score, 0, sizeof(long double) * NNODES);
        ws.probe_mass[nid(0,0)] = 1.0f;

        const RouteTables& tab = tabs[s];

        for (int d = 0; d < 2 * N; ++d) {
            int x0 = (d >= N) ? d - N : 0;
            int x1 = (d <  N) ? d     : N;
            for (int x = x0; x <= x1; ++x) {
                int y  = d - x;
                bool cR = (x < N), cU = (y < N);
                int  v  = nid(x, y);
                long double pm = ws.probe_mass[v];
                if (pm < 1e-20f) continue;
                long double sc = ws.probe_score[v];

                if (cR && cU) {
                    int ir = eid_R(x, y), iu = eid_U(x, y);
                    int ri = grid.base[ir] - MIN_CAP;
                    int ui = grid.base[iu] - MIN_CAP;

                    long double pr  = tab.pR [ri][ui];
                    long double pu  = 1.0f - pr;
                    long double fR  = ws.flow[ir];
                    long double fU  = ws.flow[iu];
                    long double cgR = (1.0f + fR) * (1.0f + fR) * (1.0f + fR);
                    long double cgU = (1.0f + fU) * (1.0f + fU) * (1.0f + fU);
                    long double eR  = tab.ccR[ri][ui] * cgR;
                    long double eU  = tab.ccU[ri][ui] * cgU;

                    long double mR = pm * pr, mU = pm * pu;
                    ws.probe_mass [nid(x+1, y)] += mR;
                    ws.probe_score[nid(x+1, y)] += sc * pr + mR * eR;
                    ws.probe_mass [nid(x, y+1)] += mU;
                    ws.probe_score[nid(x, y+1)] += sc * pu + mU * eU;
                } else if (cR) {
                    int ir = eid_R(x, y);
                    int ci = grid.base[ir] - MIN_CAP;
                    long double cg = (1.0f + ws.flow[ir]);
                    cg = cg * cg * cg;
                    long double ec = tab.ec1[ci] * cg;
                    ws.probe_mass [nid(x+1, y)] += pm;
                    ws.probe_score[nid(x+1, y)] += sc + pm * ec;
                } else {
                    int iu = eid_U(x, y);
                    int ci = grid.base[iu] - MIN_CAP;
                    long double cg = (1.0f + ws.flow[iu]);
                    cg = cg * cg * cg;
                    long double ec = tab.ec1[ci] * cg;
                    ws.probe_mass [nid(x, y+1)] += pm;
                    ws.probe_score[nid(x, y+1)] += sc + pm * ec;
                }
            }
        }

        long double dest_m = ws.probe_mass[nid(N, N)];
        if (dest_m > 1e-10f)
            ev_acc[s] += static_cast<long double>(ws.probe_score[nid(N,N)] / dest_m);
    }
}

// ── CSV loading ───────────────────────────────────────────────────────────────
static std::vector<Strategy> load_top_k(const std::string& path, int k) {
    std::ifstream f(path);
    if (!f.is_open()) {
        fprintf(stderr, "Cannot open CSV: %s\n", path.c_str());
        std::exit(1);
    }

    std::string line;
    std::getline(f, line);   // header

    struct Row { int a, h; long double prob; };
    std::vector<Row> rows;

    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string sa, sh, sprob, sev, sreg;
        if (!std::getline(ss, sa,    ',')) continue;
        if (!std::getline(ss, sh,    ',')) continue;
        if (!std::getline(ss, sprob, ',')) continue;

        int    a    = std::stoi(sa);
        long double prob = std::stod(sprob);

        // h may be "30-44" — treat as 30
        int h;
        if (sh.find('-') != std::string::npos) h = 30;
        else h = std::stoi(sh);

        rows.push_back({a, h, prob});
    }

    // Sort descending by prob
    std::sort(rows.begin(), rows.end(),
              [](const Row& x, const Row& y){ return x.prob > y.prob; });

    int take = std::min(k, (int)rows.size());
    std::vector<Strategy> result;
    result.reserve(take);
    for (int i = 0; i < take; ++i)
        result.push_back({rows[i].a, rows[i].h, rows[i].prob});

    return result;
}

// ── Main ──────────────────────────────────────────────────────────────────────
int main(int argc, char* argv[]) {
    const std::string csv_path = (argc > 1) ? argv[1] : "./nash_floodfill_result.csv";

    // ── Load strategies ───────────────────────────────────────────────────────
    printf("Loading top %d strategies from %s ...\n", TOP_K, csv_path.c_str());
    std::vector<Strategy> strats = load_top_k(csv_path, TOP_K);

	// Manually filter to exactly the strategies we want
	std::vector<std::pair<int,int>> whitelist = {
	{300,30},{300,29},{300,28},{300,27},{300,26},
	{0,21},{0,20},{0,19},{0,18},{0,17},{0,16},{0,15},{0,14},{0,13},{0,12},{0,11}
	,{59,22},{60,22},{61,22},{62,22},{63,22},{64,22},{140,23},{141,23},{142,23},{143,23},{144,23},{216,24},{217,24},{218,24},{219,24},{220,24},{291,25},{292,25},{293,25}
	};

	std::vector<Strategy> filtered;
	for (auto& [wa, wh] : whitelist) {
		// find in loaded strats
		bool found = false;
		for (auto& s : strats) {
			if (s.a_val == wa && s.h_val == wh) {
				filtered.push_back(s);
				found = true;
				break;
			}
		}
		if (!found) {
			// not in CSV — add with zero csv_prob
			filtered.push_back({wa, wh, 0.0});
		}
	}

	strats = filtered;

    int K = (int)strats.size();
    printf("Loaded %d strategies:\n", K);
    printf("  %-6s %-6s %-12s\n", "a", "h", "csv_prob");
    for (int s = 0; s < K; ++s)
        printf("  %-6d %-6d %.8f\n", strats[s].a_val, strats[s].h_val, strats[s].csv_prob);

    // ── Build route tables ────────────────────────────────────────────────────
    printf("\nBuilding route tables...\n");
    std::vector<RouteTables> tabs(K);
    #pragma omp parallel for schedule(dynamic)
    for (int s = 0; s < K; ++s)
        build_tables(strats[s].a_val, strats[s].h_val, tabs[s]);

    // ── Sample M fixed grids ──────────────────────────────────────────────────
    printf("Sampling %d fixed grids...\n", M_GRIDS);
    std::vector<Grid> grids(M_GRIDS);
    {
        std::mt19937 rng(739572);
        std::uniform_int_distribution<int> cap_dist(MIN_CAP, MAX_CAP);
        for (int m = 0; m < M_GRIDS; ++m)
            for (int e = 0; e < NEDGE; ++e)
                grids[m].base[e] = cap_dist(rng);
    }

    // ── Initialize P from CSV probabilities (renormalized over top-K) ─────────
    std::vector<long double> P(K);
    {
        long double sum = 0;
        for (int s = 0; s < K; ++s) sum += strats[s].csv_prob;
        for (int s = 0; s < K; ++s) P[s] = strats[s].csv_prob / sum;
    }

    // ── Per-thread workspaces ─────────────────────────────────────────────────
    int nthreads = 1;
    #ifdef _OPENMP
    nthreads = omp_get_max_threads();
    #endif
    std::vector<std::unique_ptr<Workspace>> workspaces(nthreads);
    for (int t = 0; t < nthreads; ++t)
        workspaces[t] = std::make_unique<Workspace>();

    printf("Running best-response dynamics (%d threads)...\n\n", nthreads);

    // ── Best-response dynamics ────────────────────────────────────────────────
    for (int iter = 0; iter < MAX_ITER; ++iter) {

        // Build long double population weights
        std::vector<long double> Pf(K);
        for (int s = 0; s < K; ++s) Pf[s] = static_cast<long double>(P[s]);

        // Accumulate EV over all M fixed grids in parallel
        std::vector<long double> ev_acc(K, 0.0);

        #pragma omp parallel
        {
            std::vector<long double> local_acc(K, 0.0);
            int tid = 0;
            #ifdef _OPENMP
            tid = omp_get_thread_num();
            #endif
            Workspace& ws = *workspaces[tid];

            #pragma omp for schedule(dynamic, 20)
            for (int m = 0; m < M_GRIDS; ++m)
                eval_grid(grids[m], Pf, strats, tabs, local_acc, ws);

            #pragma omp critical
            for (int s = 0; s < K; ++s)
                ev_acc[s] += local_acc[s];
        }

        // EV = average cost - rebate a
        std::vector<long double> ev(K);
        for (int s = 0; s < K; ++s)
            ev[s] = ev_acc[s] / M_GRIDS - strats[s].a_val;

        long double ev_min = *std::min_element(ev.begin(), ev.end());
        long double ev_max = *std::max_element(ev.begin(), ev.end());
        long double max_regret = ev_max - ev_min;

        // Best response: strategy with minimum EV
        int br = (int)(std::min_element(ev.begin(), ev.end()) - ev.begin());

        // Equal-weight averaging step: alpha = 1 / (iter + 1)
        long double alpha = 0.5 / (std::max(iter,200) + 1);
        for (int s = 0; s < K; ++s)
            P[s] = (1.0 - alpha) * P[s] + alpha * (s == br ? 1.0 : 0.0);

        if (iter % PRINT_EVERY == 0 || max_regret < EPSILON) {
            printf("Iter %5d | BR=(%d,%d) | ev_min=%8.8f | max_regret=%7.8f | alpha=%.8f\n",
                   iter + 1,
                   strats[br].a_val, strats[br].h_val,
                   ev_min, max_regret, alpha);
            fflush(stdout);
        }

        if ((iter) % PRINT_EVERY == 0) {
            printf("\n  P distribution at iter %d:\n", iter + 1);
            for (int s = 0; s < K; ++s) {
                if (1)
                    printf("    a=%-4d h=%-4d P=%.8f  EV=%10.8f  regret=%8.8f\n",
                           strats[s].a_val, strats[s].h_val,
                           P[s], ev[s], ev[s] - ev_min);
            }
            printf("\n");
            fflush(stdout);
        }

        if (max_regret < EPSILON) {
            printf("\nConverged at iteration %d (max_regret=%.6f < %.6f)\n",
                   iter + 1, max_regret, EPSILON);
            break;
        }
    }

    // ── Final EV computation ──────────────────────────────────────────────────
    printf("\nRunning final EV computation...\n");
    std::vector<long double> Pf(K);
    for (int s = 0; s < K; ++s) Pf[s] = static_cast<long double>(P[s]);

    std::vector<long double> ev_acc(K, 0.0);
    #pragma omp parallel
    {
        std::vector<long double> local_acc(K, 0.0);
        int tid = 0;
        #ifdef _OPENMP
        tid = omp_get_thread_num();
        #endif
        Workspace& ws = *workspaces[tid];
        #pragma omp for schedule(dynamic, 20)
        for (int m = 0; m < M_GRIDS; ++m)
            eval_grid(grids[m], Pf, strats, tabs, local_acc, ws);
        #pragma omp critical
        for (int s = 0; s < K; ++s)
            ev_acc[s] += local_acc[s];
    }

    std::vector<long double> ev_final(K);
    long double ev_min = 1e18;
    for (int s = 0; s < K; ++s) {
        ev_final[s] = ev_acc[s] / M_GRIDS - strats[s].a_val;
        if (ev_final[s] < ev_min) ev_min = ev_final[s];
    }

    // ── Output ────────────────────────────────────────────────────────────────
    printf("\n=== Fixed-Point Nash Equilibrium (top-%d strategies, %d grids) ===\n", K, M_GRIDS);
    printf("%-6s %-6s %-12s %-12s %-10s\n", "a", "h", "P", "EV", "Regret");
    printf("------------------------------------------------------------\n");
    for (int s = 0; s < K; ++s) {
        if (P[s] > 1e-6) {
            printf("%-6d %-6d %.8f   %10.8f   %10.8f\n",
                   strats[s].a_val, strats[s].h_val,
                   P[s], ev_final[s], ev_final[s] - ev_min);
        }
    }

    // Write CSV
    FILE* f = fopen("nash_br_result.csv", "w");
    if (f) {
        fprintf(f, "a,h,prob,ev,regret\n");
        for (int s = 0; s < K; ++s) {
            fprintf(f, "%d,%d,%.8f,%.8f,%.8f\n",
                    strats[s].a_val, strats[s].h_val,
                    P[s], ev_final[s], ev_final[s] - ev_min);
        }
        fclose(f);
        printf("\nResults written to nash_br_result.csv\n");
    }

    return 0;
}
