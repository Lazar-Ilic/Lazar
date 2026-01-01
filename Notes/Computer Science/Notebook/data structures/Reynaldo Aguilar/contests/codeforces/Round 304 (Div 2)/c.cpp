// the glory is for GOD

#include <bits/stdc++.h>

#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;

using namespace std;

const int MAXN = 2e6;

int n, k1, k2, v, ok[MAXN], arr[MAXN], sz, msk1, msk2;
set<pair<queue<int>, queue<int> > > st;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> n;
    queue<int> q1, q2;

    cin >> k1;

    for (int i = 0; i < k1; ++i)
    {
        cin >> arr[sz++];
        q1.push(i);
    }

    cin >> k2;

    for (int i = 0; i < k2; ++i)
    {
        cin >> arr[sz];
        q2.push(sz++);
    }

    for (int i = 1; ; ++i) 
    {
        int v1 = q1.front(); q1.pop();
        int v2 = q2.front(); q2.pop();

        if (arr[v1] > arr[v2])
        {
            q1.push(v2);
            q1.push(v1);
        }
        else 
        {
            q2.push(v1);
            q2.push(v2);
        }

        if (q1.empty())
        {
            cout << i << " " << 2 << endl;
            return 0;
        }
        else if (q2.empty())
        {
            cout << i << " " << 1 << endl;
            return 0;
        }

        pair<queue<int>, queue<int> > p = make_pair(q1, q2);

        if (st.find(p) != st.end())
        {
            cout << -1 << endl;
            return 0;
        }      

        st.insert(p);
    }
    return 0;
}