// the glory is for GOD

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

typedef long long ll;

const int MAXV = 5005, MAXE = 60005, oo = 0x3f3f3f3f;
int E, N, M, u, v, c, last[MAXV], next1[MAXE], adj[MAXE], src[MAXE], level[MAXV], now[MAXV], Q[MAXV], source, sink;
ll cap[MAXE], flow[MAXE];


void add_edge (int u, int v, int c)
{
    cap[E] = c, flow[E] = 0, adj[E] = v, src[E] = u, next1[E] = last[u], last[u] = E++;
    cap[E] = 0, flow[E] = 0, adj[E] = u, src[E] = v, next1[E] = last[v], last[v] = E++; //if it's a back edge (e.g the graph is directed), the capacity of this edge is 0.
}

#define RES(e)  (cap[e] - flow[e])

bool bfs (int s, int t)
{
    memset(level, -1, sizeof level);
    level[s] = 0;
    Q[0] = s;

    for (int ql = 0, qr = 1; ql < qr && level[t] == - 1; ++ql)
    {
        int u = Q[ql];

        for (int e = last[u]; e != -1; e = next1[e])
        {
            int v = adj[e];

            if (level[v] == -1 && RES(e) > 0)
            {
                level[v] = level[u] + 1;
                Q[qr++] = v;
            }
        }
    }

    return level[t] != -1;
}

ll dfs (int u, ll curr)
{
    if (u == sink)
        return curr;

    for (int e = now[u]; e != -1; now[u] = e = next1[e])
    {
        int v = adj[e];

        if (level[v] == level[u] + 1 && RES(e) > 0)
        {
            ll ans = dfs(v, min(curr, RES(e)));

            if (ans > 0)
            {
                flow[e] += ans;
                flow[e ^ 1] -= ans;
                return ans;
            }
        }
    }

    return 0;
}

ll max_flow ()
{
    ll ans = 0, res;

    while (bfs(source, sink))
    {
        memcpy(now, last, sizeof now);

        while ((res = dfs(source, oo)) > 0)
            ans += res;
    }

    return ans;
}

const int MAXN = 205;

int a[MAXN], b[MAXN], t[MAXN][MAXN];
ll sum1, sum2;

ll solve ()
{
    cin >> N >> M;
    sink = 2 * N + 1;
    memset(last, -1, sizeof last);

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i + 1];
        sum1 += a[i + 1];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> b[i + 1];
        sum2 += b[i + 1];
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;
        add_edge(u, N + v, 100);
        add_edge(v, N + u, 100);
    }

    for (int i = 1; i <= N; ++i)
    {
        add_edge(0, i, a[i]);
        add_edge(i + N, sink, b[i]);
        add_edge(i, i + N, a[i]);
    }

    return max_flow();
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    ll ans = solve();
    
    if (sum1 == sum2 && ans == sum1)
    {
        cout << "YES" << endl;

        for (int i = 0; i < E; i += 2)
        {
            int u = src[i];
            int v = adj[i];

            if (1 <= u && u <= N)
            {
                t[u][v - N] += flow[i];
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout << t[i + 1][j + 1] << " \n"[j == N - 1];
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}