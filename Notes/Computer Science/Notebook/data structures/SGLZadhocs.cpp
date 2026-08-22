#include<bits/stdc++.h>
using namespace std;

// #define int ll
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define per(i, a, b) for(int i=a; i>=b; i--)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define f first
#define s second
#define nl '\n'
#define V vector
typedef long long ll;
typedef V<int> vi;
typedef pair<int, int> pii;
#define nl '\n'
#define m1(x) template<class T, class... U> void x(T&& a, U&&... b) 
#define m2(x) (int[]){(x forward<U>(b),0)...}
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }
m1(pr) { cout << forward<T>(a);  m2(cout << " " <<); cout << "\n"; } 
m1(re) { cin >> forward<T>(a); m2(cin >>); }

template<typename A, typename B> ostream& operator<< (ostream &cout, pair<A,B> const &p)
{return cout << "(" << p.F << ", " << p.S << ")";}
template<typename A> ostream& operator<< (ostream &cout, vector<A> const&v)
{cout << "["; rep(i,0,sz(v)-1){ if (i) cout << ", "; cout << v[i];} return cout << "]";}

const int mod=1e9+7;
const int N=1e6+5;
int T;
pii ans[4*N][2];
int lazy[4*N];

void build(vi &v, int x, int lx, int rx){
  if(rx-lx==1){
    ans[x][0]={v[lx], -lx};
    ans[x][1]={mod-v[lx], -lx};
    return;
  }
  int m=(lx+rx)/2;
  build(v, 2*x+1, lx, m);
  build(v, 2*x+2, m, rx);
  rep(j,0,1) ans[x][j]=max(ans[2*x+1][j], ans[2*x+2][j]);
}

void push(int x, int lx, int rx){
  if(!lazy[x] || rx-lx==1) return;
  for(int y:{2*x+1, 2*x+2}){
    swap(ans[y][0], ans[y][1]);
    lazy[y]^=1;
  }
  lazy[x]=0;
}

void upd(int l, int r, int x, int lx, int rx){
  push(x, lx, rx);
  if(lx>=r || rx<=l) return; 
  if(lx>=l && rx<=r){
    swap(ans[x][0], ans[x][1]);
    lazy[x]^=1;
    return;
  }
  int m=(lx+rx)/2;
  upd(l, r, 2*x+1, lx, m);
  upd(l, r, 2*x+2, m, rx);
  rep(j,0,1) ans[x][j]=max(ans[2*x+1][j], ans[2*x+2][j]);
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);

    freopen("input_D.txt", "r", stdin);
    freopen("output_D.txt", "w", stdout);
    re(T);
    rep(tc,1,T){
        int n; re(n);
        vi a(n);
        ll sum=0;
        for(int &x:a) re(x);
          rep(i,0,4*n-1) lazy[i]=0;
        int q; re(q);
        build(a, 0, 0, n);
        // pr(ans[0]);
        while(q--){
          int l,r; re(l,r);
          upd(l-1, r, 0, 0, n);
          sum-=ans[0][0].s-1;
          // sum%=mod;
        }
        cout << "Case #" << tc << ": " << sum << nl;
    }
}

// OKOKOK

#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

const ll SZ = 131072*8;

array<int, 4> sum[SZ*2];
int lazy[SZ*2];

array<int, 4> combineUpd(array<int, 4> A, int B) {
    if (B&1) {
        return {MOD-A[1], MOD-A[0], A[3], A[2]};
    }
    return A;
}

array<int, 4> combine(array<int, 4> A, array<int, 4> B) {
    pi opA = {A[0], A[2]}, opB = {B[0], B[2]};
    array<int, 4> ans;
    if (opA < opB) {
        ans[0] = A[0];
        ans[2] = A[2];
    } else {
        ans[0] = B[0];
        ans[2] = B[2];
    }
    opA = {-A[1], A[3]}, opB = {-B[1], B[3]};
    if (opA < opB) {
        ans[1] = A[1];
        ans[3] = A[3];
    } else {
        ans[1] = B[1];
        ans[3] = B[3];
    }
    return ans;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] += lazy[index], lazy[2*index+1] += lazy[index];
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

array<int, 4> query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return {MOD, 0, -1, -1};
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}
void solve() {
    int N; cin >> N;
    F0R(i, 2*SZ) lazy[i] = 0;
    FOR(i, SZ, 2*SZ) {
        sum[i] = {MOD, 0, -1, -1};
    }
    F0R(i, N) {
        int X; cin >> X;
        sum[i+SZ] = {X, X, i, i};
    }
    F0Rd(i, SZ) {
        pull(i);
    }
    ll res = 0;
    int Q; cin >> Q;
    while(Q--) {
        int L, R; cin >> L >> R; L--; R--;
        update(L, R, 1);
        array<int, 4> ans = query(0, N-1);
        //dbg(ans);
        res += ans[3] + 1;
    }
    cout << res << nl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    FOR(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }

	return 0;
}

// OKOKOK

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll P = (1 << 20);
const ll MAXP = 2 * P + 100;
const ll M = 1e9 + 7;

ll N;
ll A[MAXP];
ll mhi[MAXP], mlo[MAXP];
ll hloc[MAXP], lloc[MAXP];
ll sflip[MAXP];

void build (ll nn)
{
    if (mhi[2*nn] >= mhi[2*nn+1])
    {
        mhi[nn] = mhi[2*nn];
        hloc[nn] = hloc[2*nn];
    }
    else
    {
        mhi[nn] = mhi[2*nn+1];
        hloc[nn] = hloc[2*nn+1];
    }

    if (mlo[2*nn] <= mlo[2*nn+1])
    {
        mlo[nn] = mlo[2*nn];
        lloc[nn] = lloc[2*nn];
    }
    else
    {
        mlo[nn] = mlo[2*nn+1];
        lloc[nn] = lloc[2*nn+1];
    }
}

void flip (ll nn)
{
    mhi[nn] = M - mhi[nn];
    mlo[nn] = M - mlo[nn];
    swap (mhi[nn], mlo[nn]);
    swap (hloc[nn], lloc[nn]);

    if (nn < P)
    {
        sflip[2*nn] = 1 - sflip[2*nn];
        sflip[2*nn+1] = 1 - sflip[2*nn+1];
    }
}

void prop (ll nn)
{
    if (sflip[nn])
    {
        flip (nn);
        sflip[nn] = 0;
    }
}

void apply (ll cloc, ll rlo, ll rhi, ll lo, ll hi)
{
    if (rhi < lo || hi < rlo) return;
    prop (cloc);
    if (lo <= rlo && rhi <= hi)
    {
        flip (cloc);
        //cout << cloc << " " << rlo << " " << rhi << " " << hloc[cloc] << " " << hloc[2*cloc] << " " << hloc[2*cloc+1] << "\n";
        //cout << mhi[cloc] << " " << mhi[2*cloc] << " " << mhi[2*cloc+1] << "\n";
        return;
    }

    ll rmid = (rlo + rhi) / 2;
    apply (2 * cloc, rlo, rmid, lo, hi);
    prop (2 * cloc);
    apply (2 * cloc + 1, rmid + 1, rhi, lo, hi);
    prop (2 * cloc + 1);
    build (cloc);
    //cout << cloc << " " << rlo << " " << rhi << " " << hloc[cloc] << " " << hloc[2*cloc] << " " << hloc[2*cloc+1] << "\n";
    //cout << mhi[cloc] << " " << mhi[2*cloc] << " " << mhi[2*cloc+1] << "\n";
}

void gogo()
{
    for (ll i = 0; i < MAXP; i++)
    {
        A[i] = mhi[i] = mlo[i] = 0;
        hloc[i] = lloc[i] = 0;
        sflip[i] = 0;
    }

    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        mhi[i+P] = mlo[i+P] = A[i];
        hloc[i+P] = lloc[i+P] = i;
    }
    for (ll i = P + N; i < 2 * P; i++)
    {
        mhi[i] = 0;
        mlo[i] = M;
        hloc[i] = lloc[i] = -1;
    }

    for (ll i = P - 1; i >= 1; i--)
    {
        build (i);
    }

    ll ans = 0;
    ll Q; cin >> Q;
    for (ll i = 0; i < Q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        apply (1, 0, P - 1, l, r);

        ll res = hloc[1] + 1;
        //cout << res << "\n";
        ans += res;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    ll T; cin >> T;
    for (ll t = 0; t < T; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        gogo();
    }
}

// OKOKOK

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MOD = int(1e9) + 7;

struct segment_change {
    bool flip;

    segment_change(bool _flip = false) : flip(_flip) {}

    bool has_change() const {
        return flip;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(flip ^ other.flip);
    }
};

struct segment {
    array<int, 2> minimum[2], maximum[2];

    segment(int x = -1, int index = -1) {
        minimum[0] = minimum[1] = {MOD, index};
        maximum[0] = maximum[1] = {-MOD, index};

        if (x >= 0) {
            if (x <= MOD / 2)
                minimum[0] = maximum[0] = {x, index};
            else
                minimum[1] = maximum[1] = {MOD - x, index};
        }
    }

    void apply(int, const segment_change &change) {
        if (change.flip) {
            swap(minimum[0], minimum[1]);
            swap(maximum[0], maximum[1]);
        }
    }

    void join(const segment &other) {
        for (int i = 0; i < 2; i++) {
            minimum[i] = min(minimum[i], other.minimum[i]);
            maximum[i] = max(maximum[i], other.maximum[i]);
        }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }

    int query() const {
        if (minimum[1][1] >= 0)
            return minimum[1][1];

        return maximum[0][1];
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);

        if (position < tree_n)
            changes[position] = changes[position].combine(change);
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position] = segment_change();
        }
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        assert(0 <= a && a <= b && b <= tree_n);

        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        segment answer;

        process_range(a, b, false, [&](int position, int) -> void {
            answer.join(tree[position]);
        });

        return answer;
    }

    segment query_full() const {
        return tree[1];
    }

    segment query_single(int index) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        return tree[position];
    }

    void update(int a, int b, const segment_change &change) {
        process_range(a, b, true, [&](int position, int length) -> void {
            apply_and_combine(position, length, change);
        });
    }

    void update_single(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        tree[position] = seg;

        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    // Finds the end of the last subarray starting at `first` satisfying `should_join` via binary search in O(log n).
    template<typename T_bool>
    int find_last_subarray(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        // Check the degenerate case.
        if (!should_join(current, current))
            return first - 1;

        return y_combinator([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};


void run_case(int test_case) {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(A[i], i);

    seg_tree tree(N);
    tree.build(initial);
    int Q;
    cin >> Q;
    int64_t ans = 0;

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
        tree.update(L, R, true);
        ans += tree.query_full().query() + 1;
    }

    cout << "Case #" << test_case << ": " << ans << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}

// OKOKOK

/**
 *    author:  tourist
 *    created: 07.10.2023 13:20:59       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    Mint mx = 0;
    Mint mn = 0;
    int mxpos = -1;
    int mnpos = -1;
    bool flip = false;

    void apply(int l, int r, Mint v) {
      mx = mn = v;
      mxpos = mnpos = l;
    }

    void apply(int l, int r, bool v) {
      if (v) {
        swap(mx, mn);
        mx = -mx;
        mn = -mn;
        swap(mxpos, mnpos);
        flip = !flip;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mx = max(a.mx, b.mx);
    res.mn = min(a.mn, b.mn);
    res.mxpos = (res.mx == a.mx ? a.mxpos : b.mxpos);
    res.mnpos = (res.mn == a.mn ? a.mnpos : b.mnpos);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].flip) {
      tree[x + 1].apply(l, y, tree[x].flip);
      tree[z].apply(y + 1, r, tree[x].flip);
      tree[x].flip = false;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<Mint> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    segtree st(a);
    int q;
    cin >> q;
    long long ans = 0;
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      st.modify(l, r, true);
      ans += st.get(0, n - 1).mxpos + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
