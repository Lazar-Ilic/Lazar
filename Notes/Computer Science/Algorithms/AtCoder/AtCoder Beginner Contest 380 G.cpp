#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
 
const int SZ = 500;
 
struct Query {
    int l, r, idx;
    bool operator < (const Query &other) const {
        if (l / SZ == other.l / SZ) {
            if (r == other.r)
                return idx < other.idx;
            return l / SZ % 2 ? r > other.r : r < other.r;
        }
        return l < other.l;
    }
};

const int ppp=998244353;
long long inverse(long long al){
    long long bl=1;
    int a=ppp-2;
    while(a!=0){
        if(a%2==1){
            bl=bl*al%ppp;
        }
        al=al*al%ppp;
        a/=2;
    }
    return bl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, lol;
    cin >> n >> m;
    vector<int> a(n + 1), sorted;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sorted.push_back(a[i]);
    }
	lol=m;
	m=n-m+2;
    vector<Query> queries(m);
	queries[0].l=1;
	queries[0].r=n;
	queries[0].idx=0;
    for (int i=1; i<m; i++) {
        //cin >> queries[i].l >> queries[i].r;
		queries[i].l=i;
		queries[i].r=i+lol-1;
        queries[i].idx = i;
    }
 
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int o = (int) sorted.size();
    for (int i=1; i<=n; i++)
        a[i] = int(lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin());
 
    vector<vector<tuple<int, int, int, int, int>>> iv(n + 1);
    sort(queries.begin(), queries.end());
    int moLeft = 1, moRight = 0;
    for (int i=0; i<m; i++) {
        Query &q = queries[i];
        if (moRight < q.r) {
            iv[moLeft - 1].emplace_back(moRight + 1, q.r, i, -1, 1);
            moRight = q.r;
        }
        if (q.l < moLeft) {
            iv[moRight].emplace_back(q.l, moLeft - 1, i, 1, 0);
            moLeft = q.l;
        }
        if (q.r < moRight) {
            iv[moLeft - 1].emplace_back(q.r + 1, moRight, i, 1, 1);
            moRight = q.r;
        }
        if (moLeft < q.l) {
            iv[moRight].emplace_back(moLeft, q.l - 1, i, -1, 0);
            moLeft = q.l;
        }
    }
 
    vector<int> lcnt(o), llazy(SZ), rcnt(o), rlazy(SZ);
 
    auto add = [&] (int x) -> void {
        int b = x / SZ;
        for (int i=SZ-1; i>b; i--)
            llazy[i]++;
        for (int i=min((b+1)*SZ, o)-1; i>x; i--)
            lcnt[i]++;
        for (int i=0; i<b; i++)
            rlazy[i]++;
        for (int i=b*SZ; i<x; i++)
            rcnt[i]++;
    };
 
    auto query = [&] (int x, int s) -> int {
        return s ? rcnt[x] + rlazy[x / SZ] : lcnt[x] + llazy[x / SZ];
    };
 
    vector<long long> ans(m), ansPrev(n + 1), ansNext(n + 1);
    for (int i=1; i<=n; i++) {
        ansPrev[i] = ansPrev[i-1] + query(a[i], 1);
        add(a[i]);
        ansNext[i] = ansNext[i-1] + query(a[i], 0);
        for (auto [l, r, j, c, s] : iv[i]) {
            long long tot = 0;
            for (int p=l; p<=r; p++)
                tot += query(a[p], s);
            ans[j] += tot * c;
        }
    }
 
    vector<long long> ret(m);
    long long curAns = 0;
    for (int i=0; i<m; i++) {
        curAns += ans[i];
        ret[queries[i].idx] = curAns + ansPrev[queries[i].r] + ansNext[queries[i].l - 1];
    }

	long long answer=ret[0]%ppp;
	answer=(answer+lol*(lol-1)/2%ppp*inverse(2)%ppp)%ppp;
	long long offset=0;
    for (int i=1; i<m; i++)offset=(offset+ret[i])%ppp;
        //cout << ret[i] << "\n";
	if(m==1)answer=(answer-offset)%ppp;
    else answer=(answer-offset*inverse(m-1)%ppp)%ppp;
	answer=(answer+ppp)%ppp;
	cout<<answer<<"\n";
    return 0;
}