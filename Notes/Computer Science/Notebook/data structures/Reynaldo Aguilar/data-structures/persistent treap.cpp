// The glory if for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXM = 2e5 + 5, MAXS = 10e6, NIL = 0, oo = 1e8;

struct segment
{
	int a, b, c;
	
	segment(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c)
	{}
	
	bool operator < (segment &s) const
	{
		return b > s.b;
	}
	
	bool operator <= (segment &s) const 
	{
		return b == s.b || *this < s;
	}	
}in[MAXM], seg[2 * MAXM];

ostream& operator << (ostream &out, segment s)
{
	return out << s.a << " " << s.b << " (" << s.c << ")";
}

//Begin persistent treap
typedef int node;

segment val[MAXS];
int root, buf[MAXS], buf_sz = 1, y[MAXS], qval[MAXS], lch[MAXS], rch[MAXS];

int m_rand ()	{	return (rand() << 15) + rand();	}

int get_seat (node t)
{
	return t != NIL ? qval[t] : oo;
}

void update (node t)
{
	if (t != NIL)
		qval[t] = min(val[t].c, min(get_seat(lch[t]), get_seat(rch[t])));
}

node new_node (segment v, node l, node r)
{
	node t = buf_sz;
	val[t] = v;
	lch[t] = l;
	rch[t] = r;
	y[t] = m_rand();
	update(t);
	return buf_sz++;
}

void split (node t, segment x, node &l, node &r)
{
	if (t == NIL)
		l = r = NIL;
	else if (x <= val[t])
	{
		split(lch[t], x, l, r);
		r = new_node(val[t], r, rch[t]);
	}
	else
	{
		split(rch[t], x, l, r);
		l = new_node(val[t], lch[t], l);
	}
}

node insert (node t, node x)
{
	if (t == NIL)
		return x;
	else if (y[x] > y[t])
	{
		split(t, val[x], lch[x], rch[x]);
		update(x);
		return x;
	}
	else if (val[x] < val[t])
		return new_node(val[t], insert(lch[t], x), rch[t]);
	else
		return new_node(val[t], lch[t], insert(rch[t], x));
}

node insert (node t, segment s)
{
	return insert(t, new_node(s, NIL, NIL));
}

//End persistent treap

int query (node t, int x)
{
	if (t == NIL)
		return oo;
		
	if (val[t].b < x)
		return query(lch[t], x);
		
	int tans = min(get_seat(lch[t]), val[t].c);
	return min(tans, query(rch[t], x));
}

int a, b, c, n, s, m, q, p, sz, tree[MAXM], start[2 * MAXM], seg_sz;

bool cmp1 (const segment &a, const segment &b)
{
	return a.c == b.c ? a.a < b.a : a.c < b.c;
}

bool cmp2 (const segment &a, const segment &b)
{
	return a.a < b.a;
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//Add your code here...
	cin >> n >> s >> m;
	
	for (int i = 0; i < m; ++i)
		cin >> in[i].c >> in[i].a >> in[i].b;
		
	in[m++] = segment(0, n, s + 1); //Just for implementation aims
	sort(in, in + m, cmp1);
		
	//Computing free intervals.
	for (int i = 0, pr = 0, right; i < m; pr = in[i++].c)
	{
		if (pr != in[i].c)
		{
			//Add empty interval after the last seat.
			if (pr > 0 && right < n)
				seg[seg_sz++] = segment(right, n, pr);
				
			//Add empty interval
			if (pr + 1 < in[i].c)
				seg[seg_sz++] = segment(1, n, pr + 1);
				
			//Add free interval that begins before current
			if (in[i].a > 1)
				seg[seg_sz++] = segment(1, in[i].a, in[i].c);
				
			right = in[i].b;
		}
		else
		{
			if (right < in[i].a)
				seg[seg_sz++] = segment(right, in[i].a, pr);
				
			right = max(right, in[i].b);
		}
	}

	sort(seg, seg + seg_sz, cmp2);
	root = NIL;
	
	//Building persistent treap
	for (int i = 0, j = 0; i < seg_sz; i = j)
	{
		start[sz] = seg[i].a;
		
		for (j = i; j < seg_sz && seg[i].a == seg[j].a; ++j)
			root = insert(root, seg[j]);
		
		tree[sz++] = root;		
	}
	
	for (cin >> q; q--; )
	{
		cin >> a >> b;
		a += p, b += p;
		int idx = upper_bound(start, start + sz, a) - start - 1;
		
		if (idx < 0)
		{
			cout << (p = 0) << '\n';
			continue;
		}
		
		int aux = query(tree[idx], b);
		p = aux != oo ? aux : 0;
		
		cout << p << '\n';
	}
	return 0;
}
