// The glory is for GOD

// Solution to TIMUS 1553: Caves and tunnels

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

const int MAXN = 1e5 + 5;
int n, q, u, v, timer, tin[MAXN], tout[MAXN], buf[2 * MAXN], paths, *tree[MAXN], root[MAXN], num, size[MAXN], p[MAXN], cnt[MAXN], off[MAXN], id[MAXN];
vector<int> g[MAXN];
char c;

int dfs (int u, int pr)
{
	tin[u] = ++timer, p[u] = pr, size[u] = 1;
	
	for (int i = 0, v; i < g[u].size(); ++i)
	{		
		if ((v = g[u][i]) != pr)
			size[u] += dfs(v, u);
	}
	
	return tout[u] = ++timer, size[u];
}

int new_node (int u)
{
	root[num++] = u;
	return u;
}

void build (int u, int root)
{
	off[u] = cnt[id[u] = root]++;
	
	for (int i = 0, v; i < g[u].size(); ++i)
	{
		if ((v = g[u][i]) != p[u])
			build(v, size[v] * 2 > size[u] ? root : new_node(v));
	}
}

void update (int id, int i, int val)
{
	int *tree = ::tree[id], n = cnt[id];	
	tree[i += n] += val;
	
	while (i >>= 1)
		tree[i] = max(tree[i + i], tree[i + i + 1]);
}

int get (int id, int l, int r)
{
	int *tree = ::tree[id], n = cnt[id], ans = 0;
	
	if (l == 0 && r == n - 1)
		return tree[1];
	
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
	{		
		if ((l & 1) == 1)	
			ans = max(ans, tree[l++]);
		
		if ((r & 1) == 0)	
			ans = max(ans, tree[r--]);			
	}
	
	return ans;
}

#define ancestor(u, v) (tin[u] <= tin[v] && tout[v] <= tout[u])

int query (int u, int v)
{
	int ans = 0;
	
	for (int it = 0, root; it < 2; ++it)
	{
		while (!ancestor(root = id[u], v))
		{
			ans = max(ans, get(root, 0, off[u]));
			u = p[root];
		}
		
		swap(u, v);
	}
	
	if (off[u] > off[v])
		swap(u, v);
	
	return max(ans, get(id[u], off[u], off[v]));
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 0);
	build(1, new_node(1));
	
	for (int i = 0, last = 0; i < num; ++i)
	{
		tree[root[i]] = buf + last;
		last += cnt[root[i]] << 1;
	}
	
	for (cin >> q; q--; )
	{
		cin >> c >> u >> v;
		
		if (c == 'I')
			update(id[u], off[u], v);
		else
			cout << query(u, v) << "\n";
	}	
	
	return 0;
}
