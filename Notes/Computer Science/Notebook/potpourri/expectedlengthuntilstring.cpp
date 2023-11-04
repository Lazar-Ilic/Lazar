// https://codeforces.com/problemset/gymProblem/102832/G
// https://zhuanlan.zhihu.com/p/279287505

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005,M=26;
const ll MOD=1e9+7;
char S[N];
int n,m,x,y;
ll w[N],sw[N],p[N];
ll pm(ll x,ll b){ll res=1;while(b){if(b&1)res=res*x%MOD;b>>=1;x=x*x%MOD;}return res;}
ll getlr(int l,int r){return (sw[r]-sw[l-1]+MOD)%MOD;}
struct sam{
	int fa[N],sz[N],len[N],lst,gt,ch[N][M],pos[N];
	void init(){gt=lst=1;}
	void init2(){
		for(int p=1;p<=gt;p++){
			for(int i=0;i<M;i++)if(ch[p][i])ch[p][i]=0;
		}
		lst=gt=1;
	}
	void ins(int c,int id){
		int f=lst,p=++gt;lst=p;
		len[p]=len[f]+1;sz[p]=1;pos[p]=id;
		while(f&&!ch[f][c])ch[f][c]=p,f=fa[f];
		if(!f){fa[p]=1;return ;}
		int x=ch[f][c],y=++gt;
		if(len[x]==len[f]+1){gt--;fa[p]=x;return ;}
		len[y]=len[f]+1;pos[y]=pos[x];fa[y]=fa[x];fa[x]=fa[p]=y;
		for(int i=0;i<M;i++)ch[y][i]=ch[x][i];
		while(f&&ch[f][c]==x)ch[f][c]=y,f=fa[f];
	}
	int A[N],c[N];
	void rsort(){
		for(int i=1;i<=gt;i++){c[i]=0;}
		for(int i=1;i<=gt;i++)++c[len[i]];
		for(int i=1;i<=gt;i++)c[i]+=c[i-1];
		for(int i=gt;i>=1;i--){A[c[len[i]]--]=i;}
		for(int i=gt;i>=1;i--){
			int u=A[i];
			sz[fa[u]]+=sz[u];
		}
	}
	ll f2(){
		rsort();
		ll ans=0;
		for(int u=2;u<=gt;u++){
			ll na=1ll*sz[u]*(sz[u]+1)/2%MOD*w[pos[u]]%MOD;
			int a=len[fa[u]]+1,b=len[u],r=pos[u]-a,l=pos[u]-b;
			if(r>=0){ans=(ans+na*sw[r]%MOD)%MOD;}
			if(l-1>=0){ans=(ans-na*sw[l-1]%MOD+MOD)%MOD;}
		}
		return ans;
	}
}g,t;
void f1(){
	scanf("%s",S+1);
	n=strlen(S+1);
	ll na=0;
	for(int i=0;i<M;i++){scanf("%lld",&p[i]);na+=p[i];}
	for(int i=0;i<M;i++){p[i]=na*pm(p[i],MOD-2)%MOD;}
	w[0]=1;sw[0]=1;
	for(int i=1;i<=n;i++){
		w[i]=w[i-1]*p[S[i]-'a']%MOD;
		sw[i]=(sw[i-1]+pm(w[i],MOD-2))%MOD;
	}
	g.init();
	for(int i=1;i<=n;i++){g.ins(S[i]-'a',i);}
	printf("%lld",g.f2());
}
int main(){
	f1();
	return 0;
}	
// -----------------------------------
// 【题解】2020CCPC长春 G.Monkey's Keyboard
// https://blog.51cto.com/u_15127542/4132606

// https://acm.timus.ru/problem.aspx?space=1&num=1677

// https://codeforces.com/blog/entry/98808

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v < MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend std::istream& operator >> (std::istream& in, mi& a) {
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
	friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
	friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
	friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
	friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
	friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
	mi operator - () const { return mi(-val); }
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator /= (const mi& m) { return (*this) *= inv(m); }
	friend mi operator + (mi a, const mi& b) { return a += b; }
	friend mi operator - (mi a, const mi& b) { return a -= b; }
	friend mi operator * (mi a, const mi& b) { return a *= b; }
	friend mi operator / (mi a, const mi& b) { return a /= b; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	string S;
	cin >> S;

	int n = S.size();

	vector<int> LPS(n), LIPS(n), LPSH(n), LPST(n);

	//initialize base cases
	LIPS[0] = 0;
	LPS[0] = 0;
	if(S[0] == 'H'){
		LPSH[0] = 0;
		LPST[0] = -1;
	} else {	// S[0] == 'T'
		LPSH[0] = -1;
		LPST[0] = 0;
	}

	for(int i=1; i<n; i++){

		// set LPS[i] and LIPS[i]
		if(S[i] == 'H'){
			LPS[i] = LPSH[i-1] + 1;
			LIPS[i] = LPST[i-1] + 1;
		} else {	// S[i] == 'T'
			LPS[i] = LPST[i-1] + 1;
			LIPS[i] = LPSH[i-1] + 1;
		}

		// set LPSH[i] and LPST[i]
		if(S[LPS[i]] == 'H'){
			LPSH[i] = LPS[i];
			LPST[i] = (LPS[i] > 0 ? LPST[LPS[i]-1] : -1);
		} else {	// S[LPS[i]] == 'T'
			LPST[i] = LPS[i];
			LPSH[i] = (LPS[i] > 0 ? LPSH[LPS[i]-1] : -1);
		}
	}

	vector<mi> val(n);  // the (n+1)th column of the matrix
	vector<mi> pref(n);	// prefix sums of val
	pref[0] = 2;
	val[0] = 2;

	for(int i=1; i<n; i++){
		val[i] = 2 + pref[i-1] - (LIPS[i]-1 >= 0 ? pref[LIPS[i]-1] : 0);
		pref[i] = pref[i-1] + val[i];
	}

	cout << pref[n-1] << "\n";
}