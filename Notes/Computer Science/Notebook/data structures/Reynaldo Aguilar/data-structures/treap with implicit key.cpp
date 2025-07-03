// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

namespace treap //WARNING: NOT VERIFIED
{
	/*
	 	QUERY TYPES:
		1. ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example, performing "ADD 2 4 1" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5, 5}
		2. REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example, performing "REVERSE 2 4" on {1, 2, 3, 4, 5} results in {1, 4, 3, 2, 5}
		3. REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example, performing "REVOLVE 2 4 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 2, 5}
		4. INSERT x P: insert P after Ax. For example, performing "INSERT 2 4" on {1, 2, 3, 4, 5} results in {1, 2, 4, 3, 4, 5}
		5. DELETE x: delete Ax. For example, performing "DELETE 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5}
		6. MIN x y: what is the minimum number in sub-sequence {Ax ... Ay}. For example, the correct answer to "MIN 2 4" on {1, 2, 3, 4, 5} is 2
		7. SUM x y: what is the sum of all numbers in sub-sequence {Ax...Ay}. For example, the answer to "SUM 3 5" on {1, 2, 3, 4, 5} is 12
	*/
	typedef int node;

	const int MAXN = 2e5 + 5, MAXS = 8e6, NIL = 0, oo = 1e9 + 5;

	node lch[MAXS], rch[MAXS], root;
	int val[MAXS],	//val[i] = value of array at corresponding index to node i
		cnt[MAXS], 	//cnt[i] = gets the number of nodes in the subtree rooted at node i
		rev[MAXS],  //rev[i] = says if the node i is reversed
		acc[MAXS],	//acc[i] = accumulated value for sum in all the subtree rooted at node i
		sum[MAXS],  //sum[i] = gets the sum of values of all nodes in the subtree rooted at node i
		mim[MAXS],	//mim[i] = gets the minimum value of all nodes in the subreee rooted at node i
		arr[MAXN],	//arr[i] = value of initial array at index i
		sz;

	int random ()	{	return (rand() << 15) + rand();	}

	void init ()
	{
		sz = 1; //important!!!
	}

	int get_cnt (node t)	{	return t != NIL ? cnt[t] : 0;	}

	int get_sum (node t)	{	return t != NIL ? sum[t] : 0;	}

	int get_min (node t)	{ 	return t != NIL ? mim[t] : oo;	}

	void push (node t)
	{
		if (t != NIL)
		{
			if (rev[t])	//handling reverse query
			{
				rev[t] = false;

				if (lch[t] != NIL)
					rev[lch[t]] ^= 1;

				if (rch[t] != NIL)
					rev[rch[t]] ^= 1;

				swap(lch[t], rch[t]);
			}

			if (acc[t]) //handling interval sum query
			{
				val[t] += acc[t];

				if (lch[t] != NIL)
					acc[lch[t]] += acc[t];

				if (rch[t] != NIL)
					acc[rch[t]] += acc[t];

				acc[t] = 0;
			}
		}
	}

	void debug2 (node t)
	{
		if (t != NIL)
		{
			push(t);
			debug2(lch[t]);
			//cerr << "(val = " << val[t] << " min = " << get_min(t) << ") ";
			cerr << val[t] << " ";
			debug2(rch[t]);
		}
	}

	void debug ()
	{
		cerr << "debugging" << endl;
		debug2(root);
		cerr << endl;
	}

	void debug (node t)
	{
		cerr << "debugging" << endl;
		debug2(t);
		cerr << endl;
	}

	void update (node t)
	{
		if (t != NIL)
		{
			cnt[t] = get_cnt(lch[t]) + get_cnt(rch[t]) + 1;
			sum[t] = get_sum(lch[t]) + get_sum(rch[t]) + val[t];
			int mc = min(get_min(lch[t]), get_min(rch[t]));
			mim[t] = min(mc, val[t]);
		}
	}

	node new_node (int v, node l, node r)
	{
		assert(sz < MAXS);
		val[sz] = v;
		mim[sz] = v;
		lch[sz] = l;
		rch[sz] = r;
		update(sz);
		return sz++;
	}

	//WARNING: Call root = build(0, n - 1)
	node build (int b, int e)
	{
		if (b > e)
			return NIL;

		int m = (b + e) >> 1;
		return new_node(arr[m], build(b, m - 1), build(m + 1, e));
	}

	void split (node t, node &l, node &r, int cnt)
	{
		if (t == NIL)
			l = r = NIL;
		else
		{
			push(t);
			int tmp = get_cnt(lch[t]);

			if (tmp >= cnt)
			{
				split(lch[t], l, lch[t], cnt);
				r = t;
			}
			else
			{
				split(rch[t], rch[t], r, cnt - tmp - 1);
				l = t;
			}

			update(t);
		}
	}

	node merge (node l, node r)
	{
		if (l == NIL || r == NIL)
			return l == NIL ? r : l;

		push(l);
		push(r);

		if (random() % (cnt[l] + cnt[r]) < cnt[l])
		{
			rch[l] = merge(rch[l], r);
			update(l);
			return l;
		}

		lch[r] = merge(l, lch[r]);
		update(r);
		return r;
	}

	void insert (int idx, int val)
	{
		if (idx > get_cnt(root))
			return;

		node n1, n2;
		split(root, n1, n2, idx);
		root = merge(n1, new_node(val, NIL, NIL));
		root = merge(root, n2);
	}

	void erase (int idx)
	{
		if (get_cnt(root) <= idx)
			return;

		node n1, n2, n3;
		split(root, n1, n2, idx);
		split(n2, n2, n3, 1);
		root = merge(n1, n3);
	}

	void reverse (int l, int r)
	{
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		rev[n2] ^= 1;
		root = merge(n1, n2);
		root = merge(root, n3);
	}

	//Rotate arr[l...r] k times to the right (WARNING: TO THE RIGHT!!!)
	void rotate (int l, int r, int k)
	{
		if (l > r)
			return;
		node n1, n2, n3, n4;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		k %= get_cnt(n2);
		split(n2, n2, n4, get_cnt(n2) - k);
		root = merge(n1, n4);
		root = merge(root, n2);
		root = merge(root, n3);
	}

	//WARNING: Check overflow in sum
	int sum_query (int l, int r)
	{
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		int ans = get_sum(n2);
		root = merge(n1, n2);
		root = merge(root, n3);
		return ans;
	}

	void sum_query (int l, int r, int v)
	{
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		acc[n2] += v;
		root = merge(n1, n2);
		root = merge(root, n3);
	}

	int min_query (int l, int r)
	{
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		int ans = get_min(n2);
		root = merge(n1, n2);
		root = merge(root, n3);
		return ans;
	}
}; //end namespace implicit_key_treap

int n, q, l, r, v, type;
char s[30];

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> treap::arr[i];

	treap::init();
	treap::root = treap::build(0, n - 1);

#ifndef ONLINE_JUDGE
	treap::debug();
#endif

	for (cin >> q; q--; )
	{
		//cin >> s;
		cin >> type;

		//if (s[0] == 'A')
		if (type == 1)
		{
			cin >> l >> r >> v;
			assert(l <= r);

			treap::sum_query(l - 1, r - 1, v);
		}
		//else if (s[0] == 'R' && s[3] == 'E')
		else if (type == 2)
		{
			cin >> l >> r;
			assert(l <= r);

			treap::reverse(l - 1, r - 1);
		}
		//else if (s[0] == 'R')
		else if (type == 3)
		{
			cin >> l >> r >> v;
			assert(l <= r);

			treap::rotate(l - 1, r - 1, v);
		}
		//else if (s[0] == 'I')
		else if (type == 4)
		{
			cin >> l >> r;
			treap::insert(l - 1, r);
		}
		//else if (s[0] == 'D')
		else if (type == 5)
		{
			cin >> l;
			treap::erase(l - 1);
		}
		else if (type == 6)
		{
			cin >> l >> r;
			assert(l <= r);

			cout << treap::min_query(l - 1, r - 1) << '\n';
		}
		else if (type == 7)
		{
			cin >> l >> r;
			assert(l <= r);

			cout << treap::sum_query(l - 1, r - 1) << '\n';
		}
		else
			throw ~0;

#ifndef ONLINE_JUDGE
		treap::debug();
		cout << flush;
#endif
	}
	return 0;
}

