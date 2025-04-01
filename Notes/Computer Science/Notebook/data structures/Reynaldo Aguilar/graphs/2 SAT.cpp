// The glory is for GOD

#include <bits/stdc++.h>

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 2 * 20005;
int n, m, a, b, sz, ans[MAXN], ans_sz, order[MAXN], order_n, used[MAXN], num[MAXN];
ii clauses[MAXN];
vector<int> g[MAXN], gr[MAXN];

void dfs1 (int u)
{
    used[u] = 1;
    
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        
        if (!used[v])
            dfs1(v);
    }
    
    order[order_n++] = u;
}

void dfs2 (int u, int n)
{
    num[u] = n;
    
    for (int i = 0; i < gr[u].size(); ++i)
    {
        int v = gr[u][i];
        
        if (num[v] == -1)
            dfs2(v, n);
    }
}

bool solve ()
{
    memset(num, -1, sizeof num);
    
    for (int i = 0; i < sz; ++i)
    {
        int u = clauses[i].first, v = clauses[i].second;
        g[NOT(u)].push_back(v);
        g[NOT(v)].push_back(u);
        gr[v].push_back(NOT(u));
        gr[u].push_back(NOT(v));
    }
    
    for (int i = 0; i < 2 * m; ++i)
    {
        if (!used[i])
            dfs1(i);
    }
    
    for (int i = order_n - 1; i >= 0; --i)
    {
        int u = order[i];
        
        if (num[u] == -1)
            dfs2(u, i);
    }
    
    for (int i = 0; i < order_n; ++i)
    {
        int u = order[i];
        
        if (num[u] == num[NOT(u)])
            return false;    
            
        if (u % 2 == 0 && num[u] < num[NOT(u)])
            ans[ans_sz++] = u / 2 + 1;
    }
    
    return true;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        //--a, --b;
        int ta = VAR(abs(a) - 1), tb = VAR(abs(b) - 1);
        
        if (a < 0)
            ta = NOT(ta);
            
        if (b < 0)
            tb = NOT(tb);
            
        clauses[sz++] = make_pair(ta, tb);
    }
    
    if (!solve())
        cout << "NO" << endl;
    else
    {
        cout << ans_sz << endl;
        
        for (int i = 0; i < ans_sz; ++i)
            cout << ans[i] << " \n"[i == ans_sz - 1];
    }
    return 0;
}
