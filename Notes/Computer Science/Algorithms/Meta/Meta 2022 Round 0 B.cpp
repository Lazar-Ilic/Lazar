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
using QP=queue<P>;
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
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using PULL=pair<ULL,ULL>;
using MULLPULL=map<ULL,PULL>;
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
		freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 433494437 993353399
//--------------------------------------------------------------------

I casecount=0;

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

	casecount++;
	out<<"Case #"<<casecount<<": ";
	
	in>>a>>b;
	QP aqp;
	avv=VV(a,V(b));
	bvv=VV(a,V(b));
	for(c=0;c<a;c++){
		in>>as;
		for(d=0;d<b;d++){
			ac=as[d];
			if(ac=='.')bvv[c][d]=1; // Tree de facto ab initio.
			else if(ac=='^'){
				bvv[c][d]=1;
				avv[c][d]=1;
			}
			else{
				bvv[c][d]=2;
				avv[c][d]=2;
			}
		}
	}
	for(c=0;c<a;c++){
		for(d=0;d<b;d++){
			if(bvv[c][d]==1){
				e=0;
				if(c+1<a and bvv[c+1][d]==1)e++;
				if(c-1>=0 and bvv[c-1][d]==1)e++;
				if(d+1<b and bvv[c][d+1]==1)e++;
				if(d-1>=0 and bvv[c][d-1]==1)e++;
				if(e<2)aqp.push({c, d});
			}
		}
	}
	while(!aqp.empty()){
		ap=aqp.front();
		aqp.pop();
		c=ap.first;
		d=ap.second;
		bvv[c][d]=0;
		if(c+1<a and bvv[c+1][d]==1){ // Post Contest Analysis: So the CodingJesus Tomer dude says it is critical to consider ensuring how memory is running at run time or directly timing to ensure that in expected or important cases we have a cheaper easier checker up front to the Left in And statements such as this one known as short circuiting to more rapidly exit on False conditionals.
			e=0;
			if(c+2<a and bvv[c+2][d]==1)e++;
			if(d+1<b and bvv[c+1][d+1]==1)e++; // Error bug unvectorised.
			if(d-1>=0 and bvv[c+1][d-1]==1)e++;
			if(e<2)aqp.push({c+1,d});
		}
		if(c-1>=0 and bvv[c-1][d]==1){
			e=0;
			if(c-2>=0 and bvv[c-2][d]==1)e++;
			if(d+1<b and bvv[c-1][d+1]==1)e++;
			if(d-1>=0 and bvv[c-1][d-1]==1)e++;
			if(e<2)aqp.push({c-1,d});
		}
		if(d+1<b and bvv[c][d+1]==1){
			e=0;
			if(d+2<b and bvv[c][d+2]==1)e++;
			if(c+1<a and bvv[c+1][d+1]==1)e++;
			if(c-1>=0 and bvv[c-1][d+1]==1)e++;
			if(e<2)aqp.push({c,d+1});
		}
		if(d-1>=0 and bvv[c][d-1]==1){
			e=0;
			if(d-2>=0 and bvv[c][d-2]==1)e++;
			if(c+1<a and bvv[c+1][d-1]==1)e++;
			if(c-1>=0 and bvv[c-1][d-1]==1)e++;
			if(e<2)aqp.push({c,d-1});
		}
	}
	for(c=0;c<a;c++){
		for(d=0;d<b;d++){
			if(avv[c][d]==1 and bvv[c][d]==0){
				out<<"Impossible"<<nl;
				return;
			}
		}
	}
	out<<"Possible"<<nl;
	for(c=0;c<a;c++){
		for(d=0;d<b;d++){
			if(bvv[c][d]==0)out<<".";
			else if(bvv[c][d]==1)out<<"^";
			else out<<"#";
		}
		out<<nl;
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}