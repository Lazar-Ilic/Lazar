#include <bits/stdc++.h>
using namespace std;
struct dual_invertible_binary_indexed_tree{
  int N;
  vector<int> BIT;
  dual_invertible_binary_indexed_tree(){
  }
  dual_invertible_binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, int x){
    while (i > 0){
      BIT[i] += x;
      i -= i & -i;
    }
  }
  void add(int l, int r, int x){
    add(l, -x);
    add(r, x);
  }
  int operator [](int i){
    i++;
    int ans = 0;
    while (i <= N){
      ans += BIT[i];
      i += i & -i;
    }
    return ans;
  }
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  array<dual_invertible_binary_indexed_tree, 21> BIT;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, N - 1);
    in = vector<int>(N);
    next = vector<int>(N);
    next[0] = 0;
    int t = 0;
    dfs2(c, t, N - 1);
    for (int i = 0; i < 21; i++){
      BIT[i] = dual_invertible_binary_indexed_tree(N);
    }
  }
  void dfs1(vector<vector<int>> &c, int v){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
  int get(int v, int d){
    return BIT[d][in[v]];
  }
  void path_add(int u, int v, int d, int x){
    int w = lca(u, v);
    while (next[u] != next[w]){
      BIT[d].add(in[next[u]], in[u] + 1, x);
      u = p[next[u]];
    }
    BIT[d].add(in[w] + 1, in[u] + 1, x);
    while (next[v] != next[w]){
      BIT[d].add(in[next[v]], in[v] + 1, x);
      v = p[next[v]];
    }
    BIT[d].add(in[w] + 1, in[v] + 1, x);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> p(n + 20, -1);
  vector<vector<int>> c(n + 20);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  p[0] = n;
  c[n].push_back(0);
  for (int i = 0; i < 19; i++){
    p[n + i] = n + i + 1;
    c[n + i + 1].push_back(n + i);
  }
  int m;
  cin >> m;
  vector<vector<int>> A(21, vector<int>(n + 20, 0));
  heavy_light_decomposition HLD(p, c);
  for (int i = 0; i < m; i++){
    int t;
    cin >> t;
    if (t == 1){
      int v;
      cin >> v;
      v--;
      int ans = 0;
      for (int j = 0; j <= 20; j++){
        ans += A[j][v];
        ans += HLD.get(v, j);
        if (j < 20){
          v = p[v];
        }
      }
      cout << ans << "\n";
    }
    if (t == 2){
      int u, v, k, d;
      cin >> u >> v >> k >> d;
      u--;
      v--;
      HLD.path_add(u, v, d, k);
      int w = HLD.lca(u, v);
      for (int j = 0; j <= d; j++){
        A[d - j][w] += k;
        if (j < d){
          A[d - 1 - j][w] += k;
          w = p[w];
        }
      }
    }
  }
}