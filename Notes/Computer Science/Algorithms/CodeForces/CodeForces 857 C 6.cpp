// Kevin Sun ksun48

#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos], dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(res, s[pos-1]);
		return res;
	}
};

void solve(){
	int N;
	cin >> N;
	vector<vector<int> > albums(N);
	vector<int> cc;
	for(int i = 0; i < N; i++){
		int K;
		cin >> K;
		albums[i].resize(K);
		for(int& x : albums[i]) cin >> x;
		albums[i].push_back(*max_element(albums[i].begin(), albums[i].end()));
		cc.insert(cc.end(), albums[i].begin(), albums[i].end());
	}
	sort(albums.begin(), albums.end(), [&](vector<int>& a, vector<int>& b) { return a.back() < b.back();} );
	sort(cc.begin(), cc.end());

	FT ft(cc.size() + 2);
	int tbest = 0;
	for(vector<int> v : albums){
		for(int& x : v) x = lower_bound(cc.begin(), cc.end(), x) - cc.begin() + 1;
		int pmax = 0;
		int best = 0;
		for(int x : v){
			if(x <= pmax) continue;
			pmax = x;
			best = max(best, (int)ft.query(pmax));
			best += 1;
		}
		ft.update(pmax, best);
		tbest = max(tbest, best);
	}
	cout << tbest << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}