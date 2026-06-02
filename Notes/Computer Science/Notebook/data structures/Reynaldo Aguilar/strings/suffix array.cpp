// The glory is for GOD
/*
	Name:			Reynaldo Lázaro Aguilar Casajuana
	
	Nickname:		rlac
	
	Date:			13/12/12 2:36
	
	Topic:			Strings - Suffix array
	
	Description: 	LCA[i] = Longest common preffix of SA[i] and SA[i + 1].
					diff_subs = Number of differents non empty substrings in string s					
					lcp = Longest common preffix of substrings from position b to position e.
					lcs = Longest common substring in strings s and t. m represents the position of symbol $ in the string s$t
					n = strlen(s) + 1
	
	Complexity:		build_sa = O(NlogN)
					build_sa_tiny = O(N(logN)^2)
					build_lcp = O(N)
					lcs = O(N)
					diff_subs = O(N)	
					lcp = O(1)					
	
  	Verified:		COJ 	1639 - Freedom of Choice
  					MOJ 	1220 - Bacon’s Cipher
  					SPOJ 	0687 - REPEATS
  					TIMUS 	1393 - Average Common Prefix
					TIMUS 	1517 - Freedom of Choice					
					TIMUS	1706 - Cipher Message 2
					TIMUS 	1713 - Key Substrings (Best solution)
                    TIMUS   1835 - Swamp Doctor
*/

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int LEN = 1e5;
char s[LEN];
int n, _sa[LEN], _b[LEN], _tmp[LEN], top[LEN], LCP[LEN], *SA = _sa, *B = _b, *tmp = _tmp;

void build_sa ()
{ 
	int na = (n < 256 ? 256 : n);
	
	for (int i = 0; i < n ; ++i) 
		top[B[i] = s[i]]++;
		
	for (int i = 1; i < na; ++i) 
		top[i] += top[i - 1];
		
	for (int i = 0; i < n ; ++i) 
		SA[--top[B[i]]] = i;
		
	for (int ok = 1, j = 0; ok < n && j < n - 1; ok <<= 1) 
	{
		for (int i = 0; i < n; ++i) 
		{
			j = SA[i] - ok; 
			
			if (j < 0) 
				j += n;
				
			tmp[top[B[j]]++] = j;
		}
		
		SA[tmp[top[0] = 0]] = j = 0;
		
		for (int i = 1; i < n; ++i) 
		{
			if (B[tmp[i]] != B[tmp[i - 1]] || B[tmp[i] + ok] != B[tmp[i - 1] + ok])
				top[++j] = i;
				
			SA[tmp[i]] = j;
		}
		
		swap(B, SA), swap(SA, tmp);
	}
}

int ok, T[LEN];

bool cmp (int i, int j)
{
	return B[i] != B[j] ? B[i] < B[j] : B[i + ok] < B[j + ok];
}

void build_sa_tiny ()
{
	for (int i = 0; i < n; ++i)
		SA[i] = i, B[i] = s[i];
		
	for (ok = 1; T[n - 1] != n - 1; ok <<= 1)
	{
		sort(SA, SA + n, cmp);
		
		for (int i = 1; i < n; ++i)
			T[i] = T[i - 1] + cmp(SA[i - 1], SA[i]);
			
		for (int i = 0; i < n; ++i)
			B[SA[i]] = T[i];
	}
}

void build_lcp ()
{
	for (int i = 0, k = 0; i < n; ++i)
	{
		if (B[i] == n - 1)
			continue;
			
		for (int j = SA[B[i] + 1]; s[i + k] == s[j + k]; ++k);
		
		LCP[B[i]] = k;
		
		if (k)
			--k;
	}
}

void lcs (int m)
{
	int idx, best = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (SA[i] < m != SA[i + 1] < m && LCP[i] > best)
			best = LCP[i], idx = SA[i];
	}
	
	s[idx + best] = 0;
	cout << s + idx << endl;
}

ll diff_subs ()
{
	ll ans = 0;
	
	for (int i = 0; i < n; ++i)
	{
		ll l = n - 1 - SA[i] - LCP[i];
		ans += l;
	}
	
	return ans;	
}

int query (int b, int e)
{
	int len = LEN[e - b + 1];					
	return min(RMQ[len][b], RMQ[len][e - (1 << len) + 1]);
}

int lcp (int b, int e)
{
	if (b < 0 || b > n || e < 0 || e > n)
		return 0;
		
	if (b == e)
		return n - b - 1;
		
	b = B[b], e = B[e];
	
	if (b > e)
		swap(b, e);
		
	return query(b, e - 1);
}
