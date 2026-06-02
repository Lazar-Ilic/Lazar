// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

/*  <persistent array>  */
const int MAXN = 1e5 + 5, MAXQ = MAXN, MAXS = 1e8;
int lch[MAXS], rch[MAXS], cnt;

int new_node (int l, int r)
{
    assert(cnt < MAXS);
    lch[cnt] = l;
    rch[cnt] = r;
    return cnt++;
}

struct p_array
{
    int n, root;
    
    int build (int *a, int n)
    {        
        if (n == 1)
            return new_node(*a, *a);
            
        int m = n / 2;
        return new_node(build(a, m), build(a + m, n - m));
    }
    
    p_array (int *a, int n) : n(n)
    {
        root = build(a, n);
    }    
    
    p_array (int n = 0, int root = 0) : n(n), root(root)
    {}
    
    int get (int v, int n, int i)
    {
        if (n == 1)
            return lch[v];
            
        int m = n / 2;
        
        return i < m ? get(lch[v], m, i) : get(rch[v], n - m, i - m);
    }
    
    // get the value at potition i.
    int operator [] (int i)
    {
        return get(root, n, i);
    }
    
    int set (int v, int n, int i, int x)
    {
        if (i < 0 || i >= n)
            return v;
                    
        if (n == 1)
            return new_node(x, x);            
        
        int m = n / 2;
        return new_node(set(lch[v], m, i, x), set(rch[v], n - m, i - m, x));
    }
    
    // get the resultant array of setting value x to position i.
    p_array set (int i, int x)
    {
        return p_array(n, set(root, n, i, x));
    }
}root[MAXQ];    // root[v] = root of the tree that represent the version # v of the array.

/*  </persistent array>    */

int n, k, a, b, v, data[MAXN];
char c;

int find_set (p_array &data, int a)
{
    int p = data[a];    
    
    if (p < 0)
        return a;

    int ans = find_set(data, p);
    //data = data.set(a, ans);
    return ans;
}

p_array union_set (p_array &data, int a, int b)
{
    a = find_set(data, a);
    b = find_set(data, b);
        
    if (a != b)
    {
        int cnt_a = data[a], cnt_b = data[b];
        
        if (cnt_a > cnt_b)
            swap(a, b);
        
        p_array ans = data.set(a, cnt_a + cnt_b);        
        ans = ans.set(b, a);
        return ans;        
    }
    else
        return data;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(data, -1, sizeof data);
    root[0] = p_array(data, n + 1);
    
    for (int i = 1; i <= k; ++i)
    {
        cin >> c >> v >> a >> b;
        
        if (c == '+')
            root[i] = union_set(root[v], a, b);
        else
        {            
            int id_b = find_set(root[v], b);
            int id_a = find_set(root[v], a);
            cout << ((id_a == id_b) ? "YES" : "NO") << '\n';
        }    
    }    
 
    return 0;
}
