// The glory if for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

#ifdef RLAC
    #define DEB(a)          clog << __LINE__ << ": " << #a << " = " << (a) << endl
    #define OUT(a, n)       for (int J = 0; J < (n); ++J)   clog << (a)[J] << " \n"[J == (n) - 1];
    #define NAME            "B"
#else
    #define DEB(a)
    #define OUT(a, n)
#endif

using namespace std;

const int MAXN = 1e5 + 5;
int n, k, v, a[MAXN], b[MAXN], ans[MAXN], *addr[2 * MAXN], sp, value[2 * MAXN], data[MAXN];
char c[MAXN];

void set_value (int *ad, int val)
{    
    assert(sp < 2 * MAXN);
    value[sp] = *ad;
    addr[sp++] = ad;
    *ad = val;
}

void rollback (int tsp)
{
    for (; sp > tsp; --sp)
        *addr[sp - 1] = value[sp - 1];
}

int find_set (int a)
{
    while (data[a] >= 0)
        a = data[a];
        
    return a;
}

void union_set (int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    
    if (a != b)
    {
        if (data[a] > data[b])
            swap(a, b);
            
        set_value(data + a, data[a] + data[b]);
        set_value(data + b, a);        
    }
}

const int MAXS = 2 * MAXN;
int VQ[MAXN], VR[MAXN], E[MAXS], next[MAXS], sz;

void add_edge(int V[], int u, int v)
{
    next[sz] = V[u]; E[sz] = v; V[u] = sz++;
}


void dfs (int u)
{    
    for (int i = VQ[u]; i >= 0; i = next[i])
    {
        int idx = E[i];
        ans[idx] = find_set(a[idx]) == find_set(b[idx]);
    }
    
    int curr = sp;
    
    for (int i = VR[u]; i >= 0; i = next[i])
    {
        int idx = E[i];
        union_set(a[idx], b[idx]);
        dfs(idx);
        rollback(curr);
    }
}

int main ()
{
    //Improvement region
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //Input region
    #ifdef RLAC
        system("notepad "NAME".in");
        freopen(NAME".in", "r", stdin);
        FILE * FILE_NAME = freopen(NAME".out", "w", stdout);
        int TIME = clock();
    #endif
    //Add your code here...
    memset(data, -1, sizeof data);
    memset(VQ, -1, sizeof VQ);
    memset(VR, -1, sizeof VR);
    cin >> n >> k;
    
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i] >> v >> a[i] >> b[i];
        
        if (c[i] == '?')
        {
            add_edge(VQ, v, i);
        }
        else
        {
            add_edge(VR, v, i);
        }
    }
    
    dfs(0);
    
    for (int i = 1; i <= k; ++i)
    {
        if (c[i] == '?')
            cout << (ans[i] ? "Si" : "No") << '\n';
    }

    //Output region
    #ifdef RLAC
        cout << flush;
        clog << clock() - TIME << endl;
        fclose(FILE_NAME);
        system("notepad "NAME".out");
    #endif
    return 0;
}
