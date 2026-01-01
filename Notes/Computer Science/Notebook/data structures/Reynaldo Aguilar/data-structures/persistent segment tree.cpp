// The glory if for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

const int MAXN = 1e5 + 5, MAXS = 1e7, MAXV = MAXN;
int n, m, a, b, k, in[MAXN], tin[MAXN];

//Begin persistent segment tree
int lch[MAXS], rch[MAXS], f[MAXS], sz, root[MAXV];

int new_node (int val)
{
	f[sz] = val;
	assert(sz < MAXS);
	return sz++;
}

int new_node (int l, int r)
{
	lch[sz] = l;
	rch[sz] = r;
	return new_node(f[l] + f[r]);
}

int build (int b, int e)
{
	if (b == e)
		return new_node(0);
		
	int m = b + e >> 1;
	return new_node(build(b, m), build(m + 1, e));
}

int update (int v, int b, int e, int pos, int val)
{
	if (b > pos || e < pos)
		return v;
		
	if (b == e)
		return new_node(f[v] + val);
		
	int m = b + e >> 1;
	int l = update(lch[v], b, m, pos, val);
	int r = update(rch[v], m + 1, e, pos, val);
	return new_node(l, r);
}
//end persistent segment tree

int query (int r1, int r2, int k)
{
	int b = 0, e = n - 1;
	
	while (b < e)
	{
		int m = b + e >> 1;
		int aux = f[lch[r2]] - f[lch[r1]];
		
		if (aux >= k)
		{
			r1 = lch[r1];
			r2 = lch[r2];
			e = m;
		}
		else
		{
			r1 = rch[r1];
			r2 = rch[r2];
			b = m + 1;
			k -= aux;
		}
	}
	
	return tin[b];
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	root[0] = build(0, n - 1);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> in[i];
		tin[i] = in[i];
	}
	
	sort(tin, tin + n);
	int len = unique(tin, tin + n) - tin;
	
	for (int i = 0; i < n; ++i)
	{
		in[i] = lower_bound(tin, tin + len, in[i]) - tin;
		root[i + 1] = update(root[i], 0, n - 1, in[i], 1);
	}
		
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> k; //a and b are 1-based
		cout << query(root[a - 1], root[b], k) << '\n';
	}
	return 0;
}
