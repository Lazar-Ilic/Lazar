// https://faculty.math.illinois.edu/~mlavrov/docs/482-spring-2020/lecture29.pdf

#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
template <typename Cap, typename Cost>
struct primal_dual{
	struct edge{
		int to, rev, id;
		Cap cap;
		Cost cost;
		edge(int to, int rev, int id, Cap cap, Cost cost): to(to), rev(rev), id(id), cap(cap), cost(cost){
		}
	};
	int N, M;
	vector<vector<edge>> G;
	primal_dual(){
	}
	primal_dual(int N): N(N), M(0), G(N){
	}
	void add_edge(int from, int to, Cap cap, Cost cost){
		int id1 = G[from].size();
		int id2 = G[to].size();
		G[from].push_back(edge(to, id2, M, cap, cost));
		G[to].push_back(edge(from, id1, ~M, 0, - cost));
		M++;
	}
	pair<Cap, Cost> min_cost_flow(int s, int t, Cap F){
		Cap flow = 0;
		Cost cost = 0;
		vector<Cost> h(N, 0);
		while (flow < F){
			vector<Cap> m(N, INF);
			vector<Cost> d(N, INF);
			vector<int> pv(N, -1);
			vector<int> pe(N, -1);
			vector<bool> used(N, false);
			priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;
			pq.push(make_pair(0, s));
			d[s] = 0;
			while (!pq.empty()){
				int v = pq.top().second;
				pq.pop();
				if (!used[v]){
					used[v] = true;
					if (v == t){
						break;
					}
					int cnt = G[v].size();
					for (int i = 0; i < cnt; i++){
						int w = G[v][i].to;
						if (!used[w] && G[v][i].cap > 0){
							Cost tmp = G[v][i].cost - h[w] + h[v];
							if (d[w] > d[v] + tmp){
								d[w] = d[v] + tmp;
								m[w] = min(m[v], G[v][i].cap);
								pv[w] = v;
								pe[w] = i;
								pq.push(make_pair(d[w], w));
							}
						}
					}
				}
			}
			if (!used[t]){
				break;
			}
			for (int i = 0; i < N; i++){
				if (used[i]){
					h[i] -= d[t] - d[i];
				}
			}
			Cap c = min(m[t], F - flow);
			for (int i = t; i != s; i = pv[i]){
				G[pv[i]][pe[i]].cap -= c;
				G[i][G[pv[i]][pe[i]].rev].cap += c;
			}
			flow += c;
			cost += c * (- h[s]);
		}
		return make_pair(flow, cost);
	}
};

// https://codeforces.com/contest/1766/problem/F

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m), c(m), w(m);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> y[i] >> c[i] >> w[i];
    x[i]--;
    y[i]--;
  }
  vector<int> b(n, 0);
  primal_dual<int, int> G(n + 2);
  for (int i = 0; i < m; i++){
    if (c[i] % 2 == 1){
      b[x[i]]--;
      b[y[i]]++;
    }
    int c2 = c[i] / 2 * 2;
    if (w[i] >= 0){
      G.add_edge(x[i], y[i], c2, w[i]);
    } else {
      b[x[i]] -= c2;
      b[y[i]] += c2;
      G.add_edge(y[i], x[i], c2, -w[i]);
    }
  }
  G.add_edge(n - 1, 0, INF, 0);
  bool ok = true;
  for (int i = 1; i < n - 1; i++){
    if (b[i] % 2 != 0){
      ok = false;
    }
  }
  if (!ok){
    cout << "Impossible" << endl;
  } else {
    if (b[0] % 2 != 0){
      b[0]++;
      b[n - 1]--;
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
      if (b[i] > 0){
        G.add_edge(n, i, b[i], 0);
        sum += b[i];
      }
      if (b[i] < 0){
        G.add_edge(i, n + 1, -b[i], 0);
      }
    }
    pair<int, int> res = G.min_cost_flow(n, n + 1, INF);
    if (res.first != sum){
      cout << "Impossible" << endl;
    } else {
      vector<int> ans(m);
      for (int i = 0; i < n; i++){
        for (primal_dual<int, int>::edge e : G.G[i]){
          if (0 <= e.id && e.id < m){
            if (w[e.id] >= 0){
              ans[e.id] = c[e.id] - e.cap;
            } else {
              ans[e.id] = c[e.id] % 2 + e.cap;
            }
          }
        }
      }
      cout << "Possible" << endl;
      for (int i = 0; i < m; i++){
        cout << ans[i];
        if (i < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}