// the glory is for GOD

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

const int MAXN = 5000005;

typedef long long ll;

int t;
ll sieve[MAXN], sum[MAXN], a, b, cnt[MAXN];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    for (int i = 2; i * 1ll * i < MAXN; ++i)
    {
        if (sieve[i])
            continue;
        else 
        {
            for (int j = i * i; j < MAXN; j += i)
                sieve[j] = i;
        }
    }

    for (int i = 2; i < MAXN; ++i)
    {
        if (sieve[i])
            cnt[i] = 1 + cnt[i / sieve[i]];
        else
            cnt[i] = 1;

        sum[i] = sum[i - 1] + cnt[i];
    }

    for (cin >> t; t--; )
    {
        cin >> a >> b;
        ll ans = sum[a] - sum[b];

        cout << ans << "\n";
    }
    return 0;
}