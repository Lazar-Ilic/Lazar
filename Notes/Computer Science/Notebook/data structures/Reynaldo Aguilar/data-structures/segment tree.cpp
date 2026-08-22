// The glory if for GOD

/*
  coder:        rlac

  topic:        Data structures - Segment tree

  description:  Given an array of N elements and a binary and associative function f, answer queries in the form L R,
  				wich means to compute f(a[L], ..., a[R]). It's possible to update single elements in the array.

  complexity:   build = O(N)
                update = O(logN)
                query = O(logN)
*/

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef complex<double> point;

const int MAXN = 100000, oo = 0x3f3f3f3f;
int tree[4 * MAXN], a[MAXN];

int f (int a, int b = oo)
{
	return min(a, b);
}

void build (int v, int b, int e)
{
	if (b == e)
	    tree[v] = a[b];
	else
	{
		int m = (b + e) / 2;
		build(2 * v, b, m);
		build(2 * v + 1, m + 1, e);
		tree[v] = f(tree[2 * v], tree[2 * v + 1]);
	}
}

void update (int v, int b, int e, int pos, int val)
{
	if (b == e)
		tree[v] = a[b] = val;
	else
	{
		int m = (b + e) / 2;
		
		if (pos <= m)
		    update(2 * v, b, m, pos, val);
		else
		    update(2 * v + 1, m + 1, e, pos, val);
		    
		tree[v] = f(tree[2 * v], tree[2 * v + 1]);
	}
}

int query (int v, int b, int e, int l, int r)
{
	if (b > r || e < l)
	    return oo;
	    
	if (b >= l && e <= r)
	    return tree[v];
	    
	int m = (b + e) / 2;
	int lt = query(2 * v, b, m, l, r);
	int rt = query(2 * v + 1, m + 1, e, l, r);
	return f(lt, rt);
}

int main()
{    
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	return 0;
}
