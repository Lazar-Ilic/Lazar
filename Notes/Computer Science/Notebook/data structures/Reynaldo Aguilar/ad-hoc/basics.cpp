// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
	NOTES:
		Implementations marked as (?) are not verified
*/

/*
	INDEX
		1. Roman numbers
		
		2. Cycle detection
*/

/*
	TODO:
		Print polynomial
*/

namespace ad_hoc
{
	/*	1. Roman numbers */
	string int_to_roman (int n)
	{
	    if (n < 4) 
			return string(n, 'I');
			
	    if (n < 6) 
			return string(5 - n, 'I') + "V";
			
	    if (n < 9) 
			return string("V") + string(n - 5, 'I');
			
	    if (n < 11) 
			return string(10 - n, 'I') + "X";
			
	    if (n < 40) 
			return string(n / 10, 'X') + int_to_roman(n % 10);
			
	    if (n < 60) 
			return string(5 - n / 10, 'X') + 'L' + int_to_roman(n % 10);
			
	    if (n < 90) 
			return string("L") + string(n / 10 - 5, 'X') + int_to_roman(n % 10);
			
	    if (n < 110) 
			return string(10 - n / 10, 'X') + "C" + int_to_roman(n % 10);
			
	    if (n < 400) 
			return string(n / 100, 'C') + int_to_roman(n % 100);
			
	    if (n < 600) 
			return string(5 - n / 100, 'C') + 'D' + int_to_roman(n % 100);
			
	    if (n < 900) 
			return string("D") + string(n / 100 - 5, 'C') + int_to_roman(n % 100);
			
	    if (n < 1100) 
			return string(10 - n / 100, 'C') + "M" + int_to_roman(n % 100);
			
	    if(n < 10000) 
			return string(n / 1000, 'M') + int_to_roman(n % 1000);
			
	    return "?";
	}
	
	int roman_to_int (string &s)
	{
		string symb = "IVXLCDM";
		int val[] = {1, 5, 10, 50, 100, 500, 1000};
		int ans = 0, back = 0;
		
		for (int i = s.size() - 1; i >= 0; --i)
		{
			int curr = val[symb.find(s[i])];
			
			if (curr < back)
				ans -= curr;
			else
				ans += curr;
				
			back = curr;
		}
		
		return ans;
	}
	
	/*	2. Cycle detection	*/
	
	//Let mu be the smallest index i and let lambda (the loop length) be the smallest 
	//positive integer such that x_mu = x_(mu + lamda)
	pii floyd_cycle_finding (int (*f)(int), int x0)
	{
		//The main phase of the algorithm, finding a repetition x_i = x_2i, hare speed 
		//is 2x tortoise
		int tortoise = f(x0), hare = f(f(x0)); //f(x0) is the element/node next to x0
		
		while (tortoise != hare)
		{
			tortoise = f(tortoise);
			hare = f(f(hare));
		}
		
		//Finds then position of mu, the hare and the tortoise move at the same speed
		int mu = 0;
		hare = tortoise;
		tortoise = x0;
		
		while (tortoise != hare)
		{
			tortoise = f(tortoise);
			hare = f(hare);
			mu += 1;
		}
		
		//Finds the length of the shortest cycle starting at x_mu, hare moves, tortoise stays
		int lambda = 1;
		hare = f(tortoise);
		
		while (tortoise != hare)
		{
			hare = f(hare);
			lambda += 1;
		}
		
		return make_pair(mu, lambda);
	}
}//end ad_hoc namespace
