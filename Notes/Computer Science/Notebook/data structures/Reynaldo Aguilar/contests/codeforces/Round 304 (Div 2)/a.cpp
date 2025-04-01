// the glory is for GOD

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

typedef long long ll;

ll k, n, w;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> k >> n >> w;

    ll total = w * (w + 1) / 2 * k;
    cout << max(total - n, 0ll) << endl;
    return 0;
}