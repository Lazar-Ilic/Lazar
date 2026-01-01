// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef complex<double> point;

const int MAXL = 10000;
char t[MAXL], p[MAXL];
int n, m, pi[MAXL];

void build_pi ()
{
	int k = pi[0] = -1;
	
	for (int i = 0; i < m; ++i)
	{
		for (; k >= 0 && p[i] != p[k]; k = pi[k]);
		
		pi[i + 1] = ++k;
	}
}

void kmp_match ()
{
	build_pi();
	
	for (int i = 0, k = 0; i < n; ++i)
	{
		for (; k >= 0 && t[i] != p[k]; k = pi[k]);
		
		if (++k == m)
			cout << "MATCH AT: " << i - m + 1 << endl;
	}
}

int main()
{
    /*  Improvement region    */
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> t >> p;
	n = strlen(t);
	m = strlen(p);
	kmp_match();
	
	return 0;
}
