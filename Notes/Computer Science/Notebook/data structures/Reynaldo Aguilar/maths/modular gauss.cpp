// The glory if for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef unsigned long long ll;

const int MAXN = 105, HI = 63;
int n;
ll x[MAXN][MAXN], res, tx[MAXN], f[MAXN], a[MAXN], ans[MAXN], val;

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];
		
	for (int i = HI; i >= 0; --i)
	{
		//Building the restriction for the i-th bit.
		for (int j = 0; j < n; ++j)
			tx[j] = 1 & (a[j] >> i);
			
		tx[n] = 1;
				
		//Adding the new restriction tx
		
		for (int j = 0; j < res; ++j)
		{
			if (tx[f[j]])
			{
				for (int k = f[j]; k <= n; ++k)
					tx[k] ^= x[j][k];
			}
		}		
		
		for (f[res] = 0; f[res] < n && !tx[f[res]]; ++f[res]);
		
		if (f[res] < n) //The new restriction is compatible con the previous restrictions.
			memcpy(x[res++], tx, sizeof tx);			
	}
	
	for (int i = res - 1; i >= 0; --i)
	{
		int aux = x[i][n];
		
		for (int j = f[i]; j < n; ++j)
			aux ^= x[i][j] * ans[j];
			
		if (aux != 0)
		{
			ans[f[i]] = 1;
			val ^= a[f[i]];
		}
	}
	
	cout << val << endl;
	return 0;
}
