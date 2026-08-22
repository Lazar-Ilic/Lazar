// The glory if for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e6 + 5, MAXS = 15e6, NIL = 0;
int num = 1, fr[MAXS], fr_sz, in[MAXN];

int used[MAXS];

//Begin persistent treap

int random ()	{	return (rand() << 15) + rand();	}

typedef int node;
int val[MAXS], cnt[MAXS], lch[MAXS], rch[MAXS], root;
ll msum[MAXS];

int size (node t) 	{	return t != NIL ? cnt[t] : 0;	}

ll sum (node t)		{	return t != NIL ? msum[t] : 0;	}

void update (node t)
{
	if (t != NIL)
	{
		msum[t] = sum(lch[t]) + sum(rch[t]) + val[t];
		cnt[t] = size(lch[t]) + size(rch[t]) + 1;
	}
}

node new_node (int v, node l, node r, int num)
{		
	assert(num < MAXS);	
	used[num] = -1;
	val[num] = v;
	lch[num] = l;
	rch[num] = r;	
	update(num);
	return num;
}

void dfs (node t, int cv)
{
	if (t != NIL)
	{
		used[t] = cv;
		dfs(lch[t], cv);
		dfs(rch[t], cv);
	}	
}

void collect (int cv)
{
	dfs(root, cv);
	
	for (int i = 1; i < num; ++i)
	{
		if (used[i] && used[i] != cv)
		{
			used[i] = 0;
			fr[fr_sz++] = i;
		}
	}
}

node new_node (int v, node l, node r)
{
	if (fr_sz > 0)
		return new_node(v, l, r, fr[--fr_sz]);
		
	return new_node(v, l, r, num++);
}

node build (int b, int e)
{
	if (b > e)
		return NIL;
		
	int m = (b + e) / 2;
	return new_node(in[m], build(b, m - 1), build(m + 1, e));
}

void split (node t, int cnt, node &l, node &r)
{
	if (t == NIL)
		l = r = NIL;
	else
	{
		int aux = size(lch[t]);
		
		if (aux >= cnt)
		{
			split(lch[t], cnt, l, r);
			r = new_node(val[t], r, rch[t]);
		}
		else
		{
			split(rch[t], cnt - aux - 1, l, r);
			l = new_node(val[t], lch[t], l);
		}
	}
}

node merge (node l, node r)
{
	if (l == NIL || r == NIL)
		return l != NIL ? l : r;
		
	if (random() % (cnt[l] + cnt[r]) < cnt[l])
	{
		return new_node(val[l], lch[l], merge(rch[l], r));
	}
	
	return new_node(val[r], merge(l, lch[r]), rch[r]);
}

//End persistent treap

int n, x, a, b, m, k, l;
char q[5];

void copy (int a, int b, int l)
{
	node n1, n2, n3, n4, n5;
	split(root, a, n1, n3);
	split(n3, l, n2, n1);
	split(root, b, n1, n4);
	split(n4, l, n5, n3);
	root = merge(n1, n2);
	root = merge(root, n3);
}

ll sumq (node t, int cnt)
{
	if (t == NIL || cnt == 0)
		return 0;
		
	int aux = size(lch[t]);
	
	if (aux >= cnt)
		return sumq(lch[t], cnt);
		
	return sum(lch[t]) + val[t] + sumq(rch[t], cnt - aux - 1);
}

ll sum (int a, int b)
{
	return sumq(root, b + 1) - sumq(root, a);
}

void print (node t, int a, int b)
{
	if (t == NIL)
		return;
		
	int cnt = size(lch[t]);
	
	if (a < cnt)
		print(lch[t], a, b);
		
	if (a <= cnt && cnt <= b)
		cout << val[t] << " ";
		
	if (cnt < b)
		print(rch[t], a - cnt - 1, b - cnt - 1);
}

void print (int a, int b)
{
	print(root, a, b);
	cout << '\n';
}

int main ()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> a >> b >> m;
	
	for (int i = 0; i < n; ++i)
	{		
		in[i] = x;
		x = (x * 1ll * a + b) % m;
	}

	root = build(0, n - 1);
	cin >> k;
	
	for (int i = 0, it = 0; i < k; ++i, ++it)
	{
		cin >> q >> a >> b;
		
		if (q[0] == 'c')
		{
			cin >> l;
			copy(a - 1, b - 1, l);
		}
		else if (q[0] == 's')
			cout << sum(a - 1, b - 1) << '\n';
		else
			print(a - 1, b - 1);
		
		if (it == 50000)
		{
			collect(i);
			it = 0;
		}
	}
	
	//cerr << "Sys test" << endl;
	//fprintf(stderr, "Number of nodes = %d\n", num);
	return 0;
}
