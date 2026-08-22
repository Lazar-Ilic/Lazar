#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
struct S{
	int n;
	vector<int> m,a;
	S(){}S(const vector<int>&x){
		build(x);
	}
	void build(const vector<int>&x){
		a=x;
		n=(int)x.size();
		m.assign(4*n,0);
		b(1,0,n-1);
	}
	void b(int v,int l,int r){
		if(l==r)m[v]=a[l];
		else{
			int k=(l+r)>>1;
			b(v<<1,l,k);
			b(v<<1|1,k+1,r);
			m[v]=max(m[v<<1],m[v<<1|1]);
		}
	}
	int rg(int ql,int qr,int t){
		if(ql>qr or n==0)return-1;
		return rg(1,0,n-1,ql,qr,t);
	}
	int rg(int v,int l,int r,int ql,int qr,int t){
		if(ql>qr or m[v]<=t)return-1;
		if(l==r)return l;
		int k=(l+r)>>1;
		if(qr>k){
			int p=rg(v<<1|1,k+1,r,max(ql,k+1),qr,t);
			if(p!=-1)return p;
		}
		if(ql<=k)return rg(v<<1,l,k,ql,min(qr,k),t);
		return-1;
	}
};
pair<long long,long long> f(set<long long>&w,long long al){
	auto it=w.upper_bound(al);
	long long bl=*it;
	--it;
	long long cl=*it;
	return {cl,bl};
}
pair<int,int> g(const vector<long long>&x,long long al,long long bl){
	int l=upper_bound(x.begin(),x.end(),al)-x.begin();
	int r=(int)(lower_bound(x.begin(),x.end(),bl)-x.begin())-1;
	if(l>r)return{-1,-1};
	return{l,r};
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
	int testcases;
	cin>>testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
		int N,Q;
		long long L;
		cin>>N>>Q>>L;
		vector<long long> X(N+1);
		for(int i=1;i<=N;++i)cin>>X[i];
		vector<pair<long long,int>> y;
		y.reserve(N);
		for(int i=1;i<=N;++i)y.push_back({X[i],i});
		sort(y.begin(),y.end());
		vector<long long> z(N);
		vector<int> d(N),p(N+1);
		for(int i=0;i<N;++i){
			z[i]=y[i].first;
			d[i]=y[i].second;
			p[d[i]]=i;
		}
		S t(d);
		set<long long> w{1,L};
		long long answer=0;
		for(int q=0;q<Q;q++){
			int o;
			cin>>o;
			if(o==1){
				long long h;
				cin>>h;
				w.insert(h);
			}
			else{
				int r;
				long long s;
				cin>>r>>s;
				long long x=X[r];
				auto [A,B]=f(w,x);
				long long len=B-A;
				auto [lposition,rposition]=g(z,A,B);
				if(lposition==-1)continue;
				long long pr=x-A,u=0;
				if(s<len){
					long long U=2*s-pr;
					if(U>=1){
						long long c=A+min<long long>(U,len-1);
						int j=(int)(upper_bound(z.begin()+lposition,z.begin()+rposition+1,c)-z.begin())-1;
						if(j>=lposition){
							int px=t.rg(lposition,j,r);
							if(px!=-1)u=d[px];
						}
					}
				}
				else{
					long long v=s%len,W=2*v-pr;
					if(W>=1){
						long long c=A+min<long long>(W,len-1);
						int j=(int)(upper_bound(z.begin()+lposition,z.begin()+rposition+1,c)-z.begin())-1;
						if(j>=lposition){
							int px=t.rg(lposition,j,r);
							if(px!=-1)u=d[px];
						}
					}
					if(u==0){
						int px=t.rg(lposition,rposition,r);
						if(px!=-1)u=d[px];
					}
				}
				answer+=u;
			}
		}
		cout<<"Case #"<<testcase<<": "<<answer<<endl;
	}
	return 0;
}