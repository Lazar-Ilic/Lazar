// the glory is for GOD

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

const int MAXN = 3005;

int n, a[MAXN], ans;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    for (int i = 1; i < n; ++i)
    {
        for (; a[i] <= a[i - 1]; ++a[i])
            ++ans;
    }

    cout << ans << endl;
    
    return 0;
}