#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>
#include <stdio.h>
#include <vector>
#include <memory>
#include <omp.h>
#include <string>

static const int N          = 50;
static const int TOLL       = 40;
static const int EW_ITERS   = 1000;
static const int MAX_ACTIVE = 20000;
static const int SEED_A     = 90;
static const int SEED_H     = 5;
static const int MC_BASE    = 1000;
static const int MC_BOOST   = 10000;
static const int BOOST_MARK = 20;   
static const int VS_GRIDS   = 50000;
static const long double EXPAND_TOLERANCE = 0.0;
static const int NEDGE      = 2 * N * (N + 1);

static const int NEW_CHECK  = 50; // Global random samples per iteration

static const int N_H_STRAT = 42;
static const int MIN_CAP = 5;
static const int MAX_CAP = 30;
static const int NUM_CAPS = MAX_CAP - MIN_CAP + 1;  // 26

static int H_VALS[N_H_STRAT]; // Other version checked that > 44 Is Silly

void build_h() {
    int i = 0;
    for (int h = 5;  h <= 30; ++h) H_VALS[i++] = h;
    for (int h = 45; h <= 60; ++h) H_VALS[i++] = h;
}

// Exact Joint Probability Distributions
double get_multinomial(int a, int kR, int kU) {
    if (kR + kU > 2 * a) return 0.0;
    if (a == 0) {
        return (kR == 0 && kU == 0) ? 1.0 : 0.0;
    }
    int n = 2 * a;
    double p = 1.0 / NEDGE;
    
    double log_prob = std::lgamma(n + 1) 
                    - std::lgamma(kR + 1) 
                    - std::lgamma(kU + 1) 
                    - std::lgamma(n - kR - kU + 1)
                    + (kR + kU) * std::log(p)
                    + (n - kR - kU) * std::log(1.0 - 2.0 * p);
    return std::exp(log_prob);
}

double get_binomial(int a, int k) {
    if (k > 2 * a) return 0.0;
    if (a == 0) return (k == 0) ? 1.0 : 0.0;
    int n = 2 * a;
    double p = 1.0 / NEDGE;
    
    double log_prob = std::lgamma(n + 1)
                    - std::lgamma(k + 1)
                    - std::lgamma(n - k + 1)
                    + k * std::log(p)
                    + (n - k) * std::log(1.0 - p);
    return std::exp(log_prob);
}

// Memory block for a single 'a' value's physics
struct RouteTables {
    long double pR [NUM_CAPS][NUM_CAPS][N_H_STRAT];   
    long double ccR[NUM_CAPS][NUM_CAPS][N_H_STRAT];
    long double ccU[NUM_CAPS][NUM_CAPS][N_H_STRAT];
    long double ec1[NUM_CAPS];  
};

struct Strategy {
    int h_val;
    int h_idx;
    int a_val;
};

void build_tables_for_a(int a, RouteTables& tab) {
    // 1. Calculate Expected Cost (ec1) using Exact Binomial Distribution
    for (int c_idx = 0; c_idx < NUM_CAPS; ++c_idx) {
        int c = c_idx + MIN_CAP;
        long double expected_cost = 0.0;
        long double weight_sum = 0.0;
        
        for (int k = 0; k <= std::min(40, 2 * a); ++k) {
            long double p = get_binomial(a, k);
            if (p < 1e-15) continue;
            
            expected_cost += p * (c + TOLL * k);
            weight_sum += p;
        }
        tab.ec1[c_idx] = (weight_sum > 1e-15) ? (expected_cost / weight_sum) : static_cast<long double>(c);
    }

    // 2. Calculate Exact Joint Probabilities and Edge Conditions using Multinomial
    for (int s = 0; s < N_H_STRAT; ++s) {
        int h = H_VALS[s];
        
        for (int cR_idx = 0; cR_idx < NUM_CAPS; ++cR_idx) {
            for (int cU_idx = 0; cU_idx < NUM_CAPS; ++cU_idx) {
                int cR = cR_idx + MIN_CAP;
                int cU = cU_idx + MIN_CAP;
                
                long double pr = 0.0;
                long double expected_cost_R = 0.0;
                long double expected_cost_U = 0.0;
                
                for (int kR = 0; kR <= std::min(40, 2 * a); ++kR) {
                    for (int kU = 0; kU <= std::min(40, 2 * a - kR); ++kU) {
                        long double p_joint = get_multinomial(a, kR, kU);
                        if (p_joint < 1e-15) continue;
                        
                        long double costR = cR + TOLL * kR;
                        long double costU = cU + TOLL * kU;
                        
                        bool bR = (costR <= h);
                        bool bU = (costU <= h);
                        
                        long double prob_R_given_k = 0.0;
                        if (bR && !bU) {
                            prob_R_given_k = 1.0;
                        } else if (!bR && bU) {
                            prob_R_given_k = 0.0;
                        } else {
                            prob_R_given_k = 0.5;
                        }
                        
                        pr += p_joint * prob_R_given_k;
                        expected_cost_R += p_joint * prob_R_given_k * costR;
                        expected_cost_U += p_joint * (1.0 - prob_R_given_k) * costU;
                    }
                }
                
                tab.pR[cR_idx][cU_idx][s] = pr;
                
                if (pr > 1e-15) {
                    tab.ccR[cR_idx][cU_idx][s] = expected_cost_R / pr;
                } else {
                    tab.ccR[cR_idx][cU_idx][s] = static_cast<long double>(cR);
                }
                
                long double pu = 1.0 - pr;
                if (pu > 1e-15) {
                    tab.ccU[cR_idx][cU_idx][s] = expected_cost_U / pu;
                } else {
                    tab.ccU[cR_idx][cU_idx][s] = static_cast<long double>(cU);
                }
            }
        }
    }
}

inline int eid_R(int x, int y) { return y * N + x; }
inline int eid_U(int x, int y) { return N * (N + 1) + x * N + y; }
inline int nid(int x, int y)   { return x * (N + 1) + y; }

struct SimState {
    int   base[NEDGE];
    long double flow[NEDGE];
    long double pmass[MAX_ACTIVE][(N + 1) * (N + 1)];
    long double probe_mass [(N + 1) * (N + 1)];   
    long double probe_score[(N + 1) * (N + 1)];   
};

void simulate_grid(SimState& st, 
                   const std::vector<long double>& Pf, 
                   const std::vector<Strategy>& probes, 
                   int num_active, 
                   const std::vector<RouteTables>& tables, 
                   std::vector<long double>& local_ev_acc, 
                   std::mt19937_64& rng, 
                   std::uniform_int_distribution<int>& bdist) {
    
    for (int i = 0; i < NEDGE; ++i) {
        st.base[i] = bdist(rng);
        st.flow[i] = 0.0;
    }
    
    // Pass 1: Traffic is ONLY generated by active strategies
    for (int s = 0; s < num_active; ++s) {
        for (int v = 0; v < (N + 1) * (N + 1); ++v) {
            st.pmass[s][v] = 0.0;
        }
        st.pmass[s][nid(0, 0)] = Pf[s];
    }

    for (int d = 0; d < 2 * N; ++d) {
        int x0 = (d >= N) ? d - N : 0;
        int x1 = (d < N) ? d : N;
        
        for (int x = x0; x <= x1; ++x) {
            int y = d - x;
            bool cR = (x < N);
            bool cU = (y < N);
            int v = nid(x, y);
            
            if (cR && cU) {
                int ir = eid_R(x, y);
                int iu = eid_U(x, y);
                
                int r5 = st.base[ir] - MIN_CAP;
                int u5 = st.base[iu] - MIN_CAP;
                
                if (r5 >= 0 && r5 < NUM_CAPS && u5 >= 0 && u5 < NUM_CAPS) {
                    for (int s = 0; s < num_active; ++s) {
                        long double m = st.pmass[s][v];
                        if (m < 1e-20f) continue;
                        
                        long double pr = tables[probes[s].a_val].pR[r5][u5][probes[s].h_idx];
                        long double mR = m * pr;
                        long double mU = m * (1.0 - pr);
                        
                        st.flow[ir] += mR;
                        st.flow[iu] += mU;
                        st.pmass[s][nid(x + 1, y)] += mR;
                        st.pmass[s][nid(x, y + 1)] += mU;
                    }
                }
            } else if (cR) {
                int ir = eid_R(x, y);
                for (int s = 0; s < num_active; ++s) {
                    long double m = st.pmass[s][v];
                    if (m < 1e-20f) continue;
                    st.flow[ir] += m;
                    st.pmass[s][nid(x + 1, y)] += m;
                }
            } else {  
                int iu = eid_U(x, y);
                for (int s = 0; s < num_active; ++s) {
                    long double m = st.pmass[s][v];
                    if (m < 1e-20f) continue;
                    st.flow[iu] += m;
                    st.pmass[s][nid(x, y + 1)] += m;
                }
            }
        }
    }

    // Pass 2: Evaluate ALL probes
    int K = probes.size();
    for (int s = 0; s < K; ++s) {
        for (int v = 0; v < (N + 1) * (N + 1); ++v) {
            st.probe_mass[v] = 0.0;
            st.probe_score[v] = 0.0;
        }
        st.probe_mass[nid(0, 0)] = 1.0;
        
        int a_val = probes[s].a_val;
        int h_idx = probes[s].h_idx;
        const RouteTables& tab = tables[a_val];

        for (int d = 0; d < 2 * N; ++d) {
            int x0 = (d >= N) ? d - N : 0;
            int x1 = (d < N) ? d : N;
            
            for (int x = x0; x <= x1; ++x) {
                int y = d - x;
                bool cR = (x < N);
                bool cU = (y < N);
                int v = nid(x, y);
                
                long double pm = st.probe_mass[v];
                if (pm < 1e-20f) continue;
                long double sc = st.probe_score[v];

                if (cR && cU) {
                    int ir = eid_R(x, y);
                    int iu = eid_U(x, y);
                    
                    int r5 = st.base[ir] - MIN_CAP;
                    int u5 = st.base[iu] - MIN_CAP;
                    
                    if (r5 >= 0 && r5 < NUM_CAPS && u5 >= 0 && u5 < NUM_CAPS) {
                        long double pr = tab.pR[r5][u5][h_idx];
                        long double pu = 1.0 - pr;
                        long double fR = st.flow[ir];
                        long double fU = st.flow[iu];
                        
                        long double cgR = (1.0 + fR) * (1.0 + fR) * (1.0 + fR);
                        long double cgU = (1.0 + fU) * (1.0 + fU) * (1.0 + fU);
                        long double eR = tab.ccR[r5][u5][h_idx] * cgR;
                        long double eU = tab.ccU[r5][u5][h_idx] * cgU;
                        
                        long double mR = pm * pr;
                        long double mU = pm * pu;
                        
                        st.probe_mass[nid(x + 1, y)]  += mR;
                        st.probe_score[nid(x + 1, y)] += sc * pr + mR * eR;
                        st.probe_mass[nid(x, y + 1)]  += mU;
                        st.probe_score[nid(x, y + 1)] += sc * pu + mU * eU;
                    }
                } else if (cR) {
                    int ir = eid_R(x, y);
                    int cap_idx = st.base[ir] - MIN_CAP;
                    
                    if (cap_idx >= 0 && cap_idx < NUM_CAPS) {
                        long double fR = st.flow[ir];
                        long double cgR = (1.0 + fR) * (1.0 + fR) * (1.0 + fR);
                        long double ec = tab.ec1[cap_idx] * cgR;
                        
                        st.probe_mass[nid(x + 1, y)]  += pm;
                        st.probe_score[nid(x + 1, y)] += sc + pm * ec;
                    }
                } else {  
                    int iu = eid_U(x, y);
                    int cap_idx = st.base[iu] - MIN_CAP;
                    
                    if (cap_idx >= 0 && cap_idx < NUM_CAPS) {
                        long double fU = st.flow[iu];
                        long double cgU = (1.0 + fU) * (1.0 + fU) * (1.0 + fU);
                        long double ec = tab.ec1[cap_idx] * cgU;
                        
                        st.probe_mass[nid(x, y + 1)]  += pm;
                        st.probe_score[nid(x, y + 1)] += sc + pm * ec;
                    }
                }
            }
        }
        
        long double dest_m = st.probe_mass[nid(N, N)];
        if (dest_m > 1e-10f) {
            local_ev_acc[s] += static_cast<long double>(st.probe_score[nid(N, N)] / dest_m);
        }
    }
}

int main() {
    build_h();
    int nthreads = 1;
#ifdef _OPENMP
    nthreads = omp_get_max_threads();
#endif

    printf("Precomputing exact multinomial physics tables for a in [0, 300]... \n");
    fflush(stdout);
    std::vector<RouteTables> all_tables(301);
    
    #pragma omp parallel for
    for (int a = 0; a <= 300; ++a) {
        build_tables_for_a(a, all_tables[a]);
    }

    printf("Tables generated. Initializing Engine with Global Search...\n\n");
    fflush(stdout);

    int seed_h_idx = -1;
    for (int i = 0; i < N_H_STRAT; ++i) {
        if (H_VALS[i] == SEED_H) {
            seed_h_idx = i;
            break;
        }
    }
    if (seed_h_idx == -1) return 1;

    std::vector<Strategy> active_strats = {{SEED_H, seed_h_idx, SEED_A}};
    std::vector<long double> P = {1.0};
    std::vector<long double> ema = {0.0};
    
    std::vector<std::vector<bool>> is_active(301, std::vector<bool>(N_H_STRAT, false));
    is_active[SEED_A][seed_h_idx] = true;

    std::vector<std::unique_ptr<SimState>> states(nthreads);
    for (int t = 0; t < nthreads; ++t) {
        states[t] = std::make_unique<SimState>();
    }

    // Generator for global random scouting
    std::mt19937 rng_scout(SEED_A + SEED_H + 1337); 
    std::uniform_int_distribution<int> dist_a(0, 300);
    // Indices 0-25 correspond to h = 5 to 30 in H_VALS
    std::uniform_int_distribution<int> dist_h_idx(0, 25); 

    for (int iter = 0; iter < EW_ITERS; ++iter) {
        long double t0 = omp_get_wtime();
        int current_mc = (iter >= EW_ITERS - BOOST_MARK) ? MC_BOOST : MC_BASE;

        // --- STEP 1: Scout valid neighbors + Global randoms ---
        std::vector<Strategy> neighbors;
        std::vector<std::vector<bool>> is_scouted(301, std::vector<bool>(N_H_STRAT, false));
        int num_active = active_strats.size();

        if (num_active < MAX_ACTIVE) {
            // Local flood-fill
            const int da[] = {-1, 1, 0, 0};
            const int dh[] = {0, 0, -1, 1};
            
            for (const auto& strat : active_strats) {
                for (int i = 0; i < 4; ++i) {
                    int na = strat.a_val + da[i];
                    int nh = strat.h_idx + dh[i];
                    
                    if (na >= 0 && na <= 300 && nh >= 0 && nh < N_H_STRAT) {
                        if (!is_active[na][nh] && !is_scouted[na][nh]) {
                            neighbors.push_back({H_VALS[nh], nh, na});
                            is_scouted[na][nh] = true;
                        }
                    }
                }
            }

            // Global random sampling
            for (int i = 0; i < NEW_CHECK; ++i) {
                int ra = dist_a(rng_scout);
                int rh = dist_h_idx(rng_scout);
                
                if (!is_active[ra][rh] && !is_scouted[ra][rh]) {
                    neighbors.push_back({H_VALS[rh], rh, ra});
                    is_scouted[ra][rh] = true;
                }
            }
        }

        std::vector<Strategy> probes = active_strats;
        probes.insert(probes.end(), neighbors.begin(), neighbors.end());
        int num_probes = probes.size();

        std::vector<long double> ev_acc(num_probes, 0.0);
        std::vector<long double> Pf(num_active);
        for (int s = 0; s < num_active; ++s) {
            Pf[s] = static_cast<long double>(P[s]);
        }

        // --- STEP 2: Monte Carlo Simulation ---
        #pragma omp parallel
        {
            std::vector<long double> local_ev_acc(num_probes, 0.0);
            int tid = 0;
#ifdef _OPENMP
            tid = omp_get_thread_num();
#endif
            SimState& st = *states[tid];
            std::mt19937_64 rng(42 + static_cast<uint64_t>(iter) * 10000 + tid);
            std::uniform_int_distribution<int> bdist(MIN_CAP, MAX_CAP);

            #pragma omp for schedule(dynamic, 50)
            for (int mc = 0; mc < current_mc; ++mc) {
                simulate_grid(st, Pf, probes, num_active, all_tables, local_ev_acc, rng, bdist);
            }
            
            #pragma omp critical
            {
                for (int s = 0; s < num_probes; ++s) {
                    ev_acc[s] += local_ev_acc[s];
                }
            }
        }

        // --- STEP 3: Evaluation & Active Set Expansion ---
        std::vector<long double> ev(num_probes);
        long double min_active_ev = 1e18;
        
        for (int s = 0; s < num_probes; ++s) {
            ev[s] = (ev_acc[s] / current_mc) - probes[s].a_val;
            if (s < num_active && ev[s] < min_active_ev) {
                min_active_ev = ev[s];
            }
        }

        int added = 0;
        for (int s = num_active; s < num_probes; ++s) {
            if (active_strats.size() >= MAX_ACTIVE) break;
            if (ev[s] <= min_active_ev + EXPAND_TOLERANCE) {
                active_strats.push_back(probes[s]);
                is_active[probes[s].a_val][probes[s].h_idx] = true;
                P.push_back(0.003);
                ema.push_back(ev[s]);
                added++;
            }
        }

        // --- STEP 4: Exponential Weights Update ---
        int old_num_active = num_active;
        num_active = active_strats.size();
        
        long double ema_min = 1e18, ema_max = -1e18;
        for (int s = 0; s < num_active; ++s) {
            if (s < old_num_active) {
                ema[s] = (iter == 0) ? ev[s] : (0.9 * ev[s] + 0.1 * ema[s]);
            }
            if (ema[s] < ema_min) ema_min = ema[s];
            if (ema[s] > ema_max) ema_max = ema[s];
        }

        long double lr = 0.25 / std::sqrt(1.0 + iter);
        long double sum_w = 0.0;
        std::vector<long double> w(num_active);
        
        for (int s = 0; s < num_active; ++s) {
            w[s] = P[s] * exp(-lr * (ema[s] - ema_min));
            sum_w += w[s];
        }
        
        for (int s = 0; s < num_active; ++s) {
            P[s] = w[s] / sum_w;
        }

        printf("Iter %2d/%d [Active: %d | Promoted: %d | ema_min=%7.2f] time=%.1fs\n",
               iter + 1, EW_ITERS, static_cast<int>(active_strats.size()), added, ema_min, omp_get_wtime() - t0);
        fflush(stdout);
    }

    // --- PHASE 2: Final High-Precision Evaluation ---
    int final_k = active_strats.size();
    printf("\nRunning Final Evaluation on %d survived strategies (%d grids)...\n", final_k, VS_GRIDS);
    
    std::vector<long double> fAvg_acc(final_k, 0.0);
    std::vector<long double> Pfinal(final_k);
    for (int s = 0; s < final_k; ++s) {
        Pfinal[s] = static_cast<long double>(P[s]);
    }

    #pragma omp parallel
    {
        std::vector<long double> local_fAvg(final_k, 0.0);
        int tid = 0;
#ifdef _OPENMP
        tid = omp_get_thread_num();
#endif
        SimState& st = *states[tid];
        std::mt19937_64 rng(99999 + tid);
        std::uniform_int_distribution<int> bdist(MIN_CAP, MAX_CAP);

        #pragma omp for schedule(dynamic, 50)
        for (int mc = 0; mc < VS_GRIDS; ++mc) {
            simulate_grid(st, Pfinal, active_strats, final_k, all_tables, local_fAvg, rng, bdist);
        }
        
        #pragma omp critical
        {
            for (int s = 0; s < final_k; ++s) {
                fAvg_acc[s] += local_fAvg[s];
            }
        }
    }

    std::vector<long double> fAvg(final_k);
    long double fmin = 1e18;
    for (int s = 0; s < final_k; ++s) {
        fAvg[s] = (fAvg_acc[s] / VS_GRIDS) - active_strats[s].a_val;
        if (fAvg[s] < fmin) fmin = fAvg[s];
    }

    // --- Output Results ---
    printf("\n=== Nash Equilibrium Distribution P(a, h) ===\n");
    printf("%-5s %-7s %-10s %-10s %-10s\n", "a", "h", "P", "EV", "Regret");
    printf("--------------------------------------------------\n");
    
    for (int s = 0; s < final_k; ++s) {
        if (1) {
            std::string label = (active_strats[s].h_val == 30) ? "30-44" : std::to_string(active_strats[s].h_val);
            printf("%-5d %-7s %.6f   %10.4f   %10.4f\n", 
                   active_strats[s].a_val, label.c_str(), P[s], fAvg[s], fAvg[s] - fmin);
        }
    }

    FILE* f = fopen("nash_floodfill_result.csv", "w");
    if (f) {
        fprintf(f, "a,h,prob,ev,regret\n");
        for (int s = 0; s < final_k; ++s) {
            std::string label = (active_strats[s].h_val == 30) ? "30-44" : std::to_string(active_strats[s].h_val);
            fprintf(f, "%d,%s,%.8f,%.4f,%.4f\n", 
                    active_strats[s].a_val, label.c_str(), P[s], fAvg[s], fAvg[s] - fmin);
        }
        fclose(f);
    }
    
    return 0;
}