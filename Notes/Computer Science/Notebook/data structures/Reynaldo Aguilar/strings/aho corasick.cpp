// The glory is for GOD

/*
	Author:			Reynaldo Lázaro Aguilar Casajuana
	
	Nickname:		rlac
	
	Date:			21/12/12 19:30
	
	Topic:			Strings - Aho Corasick
	
	Description: 		go[st][c] = Transition from st with symbol c.
				slink[st] = State of largest length that is suffix of st.
				final[st] = Indicates if st is a terminal st.
				next[st] = Next node to st in the suffix links path to the root.
				MAXS = Maximum number of nodes in the trie.
				K = Size of alphabet.
					
	
	Complexity:		add_pattern = O(|p|)		
				build_ac = O(MAXS * K)
				match = O(|t| + number of ocurrences)
	
  	Verified:		TIMUS 	1158 - Censored!   
  				SPOJ 	2175 - EMOTICON (3rd best solution)
*/

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int LEN = 10000, MAXS = 10000, K = 0x100;
int go[MAXS][K], slink[MAXS], next[MAXS], final[MAXS], q[MAXS], ql, qr, sz, n, m;
char p[LEN], t[LEN];

void initialize ()
{
	sz = 1;
	ql = qr = 0;
	memset(final, 0, sizeof final);
	memset(go, 0, sizeof go);
	memset(slink, 0, sizeof slink);
}

void add_pattern (char * p, int idx)
{
	int st = 0;
	
	for (int i = 0; p[i]; ++i)
	{
		int &aux = go[st][p[i]];
		
		if (!aux)
		    aux = sz++;
		    
		st = aux;
	}
	
	final[st] = idx;
}

void build_ac ()
{
	for (int i = 0; i < K; ++i)
	{
		if (go[0][i])
		    q[qr++] = go[0][i]; /* Suffix link of these states are equal to 0   */
	}
	
	for (; ql < qr; ++ql)
	{
		int st = q[ql];
		int suf = slink[st];
		next[st] = final[suf] ? suf : next[suf];
		
		for (int i = 0; i < K; ++i)
		{
			int &aux = go[st][i];
			
			if (aux)
			{
				slink[aux] = go[suf][i];
				q[qr++] = aux;
			}
			else
			    aux = go[suf][i];
		}
	}
}

void match (char * t)
{
	cout << "MATCHING" << endl;
	
	for (int st = 0, i = 0; t[i]; ++i)
	{
		st = go[st][t[i]];
		
		if (final[st])
		    cout << final[st] << " at position " << i << endl;
		    
		for (int j = next[st]; j; j = next[j])
		    cout << final[j] << " at position " << i << endl;
	}
}

int main()
{
    /*  Improvement region    */
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << boolalpha << setprecision(6) << fixed;
	clog.copyfmt (cout);
	/*  Input region.   */
	#ifdef RLAC_HOME
		system("notepad "NAME".in");
		freopen(NAME".in", "r", stdin);
		FILE * FILE_NAME = freopen(NAME".out", "w", stdout);
		int TIME = clock();
	#endif
	//Add your code here...
	cin >> n >> m;
	initialize();
	
	for (int i = 0; i < n; ++i)
	{
		cin >> p;
		add_pattern(p, i + 1);
	}
	
	build_ac();
	
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		match(t);
	}
	/*  Output region.  */
	#ifdef  RLAC_HOME
	    clog << clock() - TIME << endl;
		fclose(FILE_NAME);
		system("notepad "NAME".out");
	#endif
	return 0;
}
