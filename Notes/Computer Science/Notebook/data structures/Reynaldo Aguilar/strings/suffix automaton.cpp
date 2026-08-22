// The glory is for GOD
/*
	Author:			Reynaldo Lázaro Aguilar Casajuana
	
	Nickname:		rlac
	
	Date:			13/02/13 22:46
	
	Topic:			Strings - Suffix Automaton
	
	Description: 	go[st][c] = Transition from st with symbol c.
			slink[st] = State of largest length that is suffix of st.
			final[st] = Indicates if st is a terminal state.
			length[st] = Length of the largest string that corresponds to st.
			last = state that corresponds to the whole string that have been processed.
			lcs = Longest common substring in strings s and t.
			MAXS = Maximum number of states in the automaton.
			K = Size of alphabet.
					
	
	Complexity:	build = O(NK)					
			lcs   = O(N)		
	
  	Verified:	TIMUS 1517. Freedom of Choice (Best solution)
  			TIMUS 1937. Davy Jones’s Organ (Best solution)
*/

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> ii;

const int LEN = 1e5 + 5, MAXS = 2 * LEN, K = 26;
int go[MAXS][K], slink[MAXS], length[MAXS], final[MAXS], p, q, size = 2, last = 1, n;
char s[LEN], t[LEN];

void extend (int c)
{
	for (p = last; !go[p][c]; p = slink[p])
	    go[p][c] = size;
	    
	q = go[p][c];
	length[size] = length[last] + 1;
	last = size++;
	
	if (!p)
	    slink[last] =  1;
	else if (length[p] + 1 == length[q])
		slink[last] = q;
	else
	{
		for (length[size] = length[p] + 1; go[p][c] == q; p = slink[p])
		    go[p][c] = size;
		    
		memcpy(go[size], go[q], sizeof go[size]);
		slink[size] = slink[q];
		slink[last] = slink[q] = size++;
	}
}

void build ()
{
	fill(go[0], go[0] + K, 1);
	length[0] = -1;
	
	for (int i = 0; s[i]; ++i)
	    extend(s[i] - 'A');
	    
	for (; last > 0; last = slink[last])
		final[last] = 1; 
}

void lcs ()
{
	int pos, best = 0;
	
	for (int i = 0, len = 0, st = 1; t[i]; ++i)
	{
		char c = t[i] - 'A';
		
		if (!go[st][c])
		{
			for (; !go[st][c]; st = slink[st]); 
			
			len = length[st];
		}
		
		st = go[st][c];
		
		if (++len > best)  
			best = len, pos = i - len + 1;
	}
		
	t[pos + best] = 0;
	cout << t + pos << endl;
}
