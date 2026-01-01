//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using U=uint64_t;
using LD=long double;
using S=string;
using PB=pair<B,B>;
using PC=pair<C,C>;
using PD=pair<D,D>;
using P=pair<I,I>;
using PL=pair<L,L>;
using PLD=pair<LD,LD>;
using PS=pair<S,S>;
using PSL=pair<S,L>;
using PIS=pair<I,S>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using MSETP=multiset<P>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETULL=set<ULL>;
using SETP=set<P>;
using SETSETP=set<SETP>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MLI=map<L,I>;
using MLL=map<L,L>;
using MPI=map<P,I>;
using MCI=map<C,I>;
using MUI=map<U,I>;
using VMII=vector<MII>;
using UMSI=unordered_map<S,I>;
using UMII=unordered_map<I,I>;
using UMIL=unordered_map<I,L>;
using UMLL=unordered_map<L,L>;
using UMUI=unordered_map<U,I>;
using UMPI=unordered_map<P,I>;
using VUMII=vector<UMII>;
using DQ=deque<I>;
using ST=stack<I>;
using STST=stack<ST>;
using STP=stack<P>;
using STPL=stack<PL>;
using Q=queue<I>;
using PQ=priority_queue<I>;
using PQP=priority_queue<P>;
using PQPL=priority_queue<PL>;
using VB=vector<B>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VL=vector<L>;
using VULL=vector<ULL>;
using VLD=vector<LD>;
using VS=vector<S>;
using VU=vector<U>;
using VPB=vector<PB>;
using VPC=vector<PC>; 
using VPD=vector<PD>;
using VP=vector<P>;
using VPL=vector<PL>; 
using VPLD=vector<PLD>;
using VPS=vector<PS>;
using VPIS=vector<PIS>;
using VPID=vector<PID>;
using VVB=vector<VB>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VSET=vector<SET>;
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using Z=void;
#define PTL PT<L>
#define PTD PT<D>
#define VH vector<H>
#define VPTL vector<PTL>
#define VPTD vector<PTD>
#define orderofkey order_of_key
#define findbyorder find_by_order
#define lowerbound lower_bound
#define upperbound upper_bound
#define nextpermutation next_permutation
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsetsize __builtin_popcount
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a) ((a).begin()),((a).end())
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define BT bitset
#define ba &
#define bo |
#define bx ^
#define bf ~
#define in cin
#define out cout
#define nl endl
Z zz(){
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);
	#endif
}
Z outv(V av){
	if(sz(av)==0)return;
	for(I a=0;a<sz(av);a++)out<<av[a]<<" ";
	out<<nl;
}
Z outvv(VV avv){
	if(sz(avv)==0)return;
	for(I a=0;a<sz(avv);a++)outv(avv[a]);
}
Z outset(SET aset){
	if(aset.empty())return;
	for(auto aa:aset)out<<aa<<" ";
	out<<nl;
}
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000
//--------------------------------------------------------------------

V graph[1000001];
I processed[1000001];
I bfsparent[1000001];
I bfslevel[1000001];

Z bfs(I a){
	Q aq;
	I b;
	aq.push(a);
	processed[a]=1;
    while(!aq.empty()){
		b=aq.front();
		aq.pop();
		for(I c:graph[b]){
			if(!processed[c]){
				aq.push(c);
				processed[c]=1;
				bfsparent[c]=b;
				bfslevel[c]=1+bfslevel[b];
			}
		}
	}
}

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
	V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
	P ap,bp,cp,dp,ep,fp,gp,hp,ip,jp,kp,lp,mp;
	VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
	VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
	VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
	VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;

	in>>a>>b>>c;
	avv=VV(a,V(b));
	for(d=0;d<a;d++){ // Mediocre grid graph input.
		in>>as;
		for(e=0;e<b;e++){
			if(as[e]=='.')avv[d][e]=0;
			else if(as[e]=='#')avv[d][e]=1;
			else if(as[e]=='S'){
				avv[d][e]=2;
				w=d;x=e;
			}
			else{
				avv[d][e]=3;
				y=d;z=e;
			}
		}
	}
	VVP avvp;
	avvp=VVP(a*b+1,VP(0)); // We process in order how much energy left.
	for(d=0;d<c;d++){ // So maximal energy guard expands.
		in>>e>>f>>g; // Maximum number of compute on point is 4.
		e--;f--; // Convenient.
		avvp[g].add({e,f});
	}
	for(d=a*b;d>=0;d--){
		bvp.clear();
		for(e=0;e<sz(avvp[d]);e++){ // Simple mutual breadth first search.
			avp.add(avvp[d][e]);
		}
		for(e=0;e<sz(avp);e++){ // Expand from guards to walls.
			f=avp[e].first;
			g=avp[e].second;
			avv[f][g]=1;
			if(f+1<a and avv[f+1][g]!=1)bvp.add({f+1,g});
			if(f-1>=0 and avv[f-1][g]!=1)bvp.add({f-1,g});
			if(g+1<b and avv[f][g+1]!=1)bvp.add({f,g+1});
			if(g-1>=0 and avv[f][g-1]!=1)bvp.add({f,g-1});
		}
		avp=bvp;
	}
	if(avv[w][x]==1 or avv[y][z]==1){ // Blocked ab initio.
		out<<"IMPOSSIBLE"<<nl;return;
	}
	for(d=0;d<a;d++){ // Add to real graph for breadth first search.
		for(e=0;e<b;e++){
			if(avv[d][e]!=1){
				if(d+1<a and avv[d+1][e]!=1)graph[(d+1)*b+e].add(d*b+e);
				if(d-1>=0 and avv[d-1][e]!=1)graph[(d-1)*b+e].add(d*b+e);
				if(e+1<b and avv[d][e+1]!=1)graph[d*b+e+1].add(d*b+e);
				if(e-1>=0 and avv[d][e-1]!=1)graph[d*b+e-1].add(d*b+e);
			}
		}
	}
	bfs(w*b+x); // Breadth first search from Victor to out.
	if(bfslevel[y*b+z]!=0)out<<bfslevel[y*b+z]<<nl;
	else out<<"IMPOSSIBLE"<<nl; // Can be blocked by walls.
}

I main(){zz();I a=1;while(a--){az();}}