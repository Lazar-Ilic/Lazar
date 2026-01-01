// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef complex<double> point;

const int MAXN = 100000;
char s[MAXN];
int pref[MAXN],     // pref[i] = longest common prefix of s and s[i....n - 1]
    suff[MAXN],     // suff[i[ = longest common suffix of s and s[0...i]
    n;

void build_pref ()
{
	pref[0] = n;
	int g = 0, f;
	
	for (int i = 1; s[i]; ++i)
	{
		if (i < g && pref[i - f] != g - i)
		    pref[i] = min(pref[i - f], g - i);
		else
		{
			for (g = max(g, i), f = i; s[g] == s[g - f]; ++g);
			
			pref[i] = g - f;
		}
	}
}

void build_suff ()
{
	int g = n - 1, f;
	suff[g] = n;
	
	for (int i = n - 2; i >= 0; --i)
	{
		if (i > g && suff[i + n - 1 - f] != i - g)
		    suff[i] = min(suff[i + n - 1 - f], i - g);
		else
		{
			for (g = min(g, f = i); g >= 0 && s[g] == s[g + n - 1 - f]; --g);
			
			suff[i] = f - g;
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = strlen(s);
	build_pref();
	build_suff();
	
	// output z-function
	for (int i = 0; s[i]; ++i)
	    cout << pref[i] << " \n"[i == n - 1];
	    
	// output reverse z-function
	for (int i = 0; s[i]; ++i)
	    cout << suff[i] << " \n"[i == n - 1];
	
	return 0;
}
