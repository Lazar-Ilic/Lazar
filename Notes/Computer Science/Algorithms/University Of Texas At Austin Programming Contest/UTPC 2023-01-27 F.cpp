//%%writefile a.cpp
 
/*

"
LASER [レーザ]
Gold Medalists are my role models
"
- Wasalu Muhammad Jaco, [Losers To] LASERs, Drogas 光 Light

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615]
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
using USETP=unordered_set<P>;
using USETL=unordered_set<L>;
using USETS=unordered_set<S>;
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
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
using VUSETS=vector<USETS>;
using VVUSETS=vector<VUSETS>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VUI=vector<UI>;
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
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VVULL=vector<VULL>;
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
using PDV=pair<D,V>;
using PULL=pair<ULL,ULL>;
using VPULL=vector<PULL>;
using MULLPULL=map<ULL,PULL>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using QP=queue<P>;
using QV=queue<V>;
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
#define equalrange equal_range
#define nextpermutation next_permutation
#define prevpermutation prev_permutation
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399

//--------------------------------------------------------------------

// Description: Pollard-rho randomized factorization algorithm. Returns prime factors of a number, in arbitrary order (e.g. 2299 -> {11, 19, 11}).
// Time: $O(n^(1/4))$, less for numbers with small factors
ULL modmultiply(ULL a,ULL b,ULL mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*ULL(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
ULL modpower(ULL a,ULL b,ULL mod){
	ULL ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(ULL n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	ULL aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(ULL a:aaa){
		ULL ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
ULL pollard(ULL n){
	auto f=[n](ULL x){return modmultiply(x,x,n)+1;};
	ULL x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VULL factor(ULL n){
	if(n==1)return{};
	if(isprime(n))return{n};
	ULL x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPULL primefactorisationof(ULL n){
	VULL avull=factor(n);
	VPULL avpull;
	for(ULL aull:avull){
		if(sz(avpull)==0 or aull!=avpull[sz(avpull)-1].first){
			avpull.add({aull,1});
		}
		else{
			avpull[sz(avpull)-1].second++;
		}
	}
	return avpull;
}

VULL factorsof(ULL n){
	VPULL avpull=primefactorisationof(n);
	VULL avull,bvull;
	VVULL avvull;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avpull)<15)avpull.add({1,0});
	for(a0=0;a0<15;a0++){
		bvull=VULL(0);
		ULL cull=1;
		for(a1=0;a1<=avpull[a0].second;a1++){
			bvull.add(cull);
			cull*=avpull[a0].first;
		}
		avvull.add(bvull);
	}
	for(a0=0;a0<=avpull[0].second;a0++){
	for(a1=0;a1<=avpull[1].second;a1++){
	for(a2=0;a2<=avpull[2].second;a2++){
	for(a3=0;a3<=avpull[3].second;a3++){
	for(a4=0;a4<=avpull[4].second;a4++){
	for(a5=0;a5<=avpull[5].second;a5++){
	for(a6=0;a6<=avpull[6].second;a6++){
	for(a7=0;a7<=avpull[7].second;a7++){
	for(a8=0;a8<=avpull[8].second;a8++){
	for(a9=0;a9<=avpull[9].second;a9++){
	for(a10=0;a10<=avpull[10].second;a10++){
	for(a11=0;a11<=avpull[11].second;a11++){
	for(a12=0;a12<=avpull[12].second;a12++){
	for(a13=0;a13<=avpull[13].second;a13++){
	for(a14=0;a14<=avpull[14].second;a14++){
		avull.add(avvull[0][a0]*avvull[1][a1]*avvull[2][a2]*avvull[3][a3]*avvull[4][a4]*avvull[5][a5]*avvull[6][a6]*avvull[7][a7]*avvull[8][a8]*avvull[9][a9]*avvull[10][a10]*avvull[11][a11]*avvull[12][a12]*avvull[13][a13]*avvull[14][a14]);
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	sort(all(avull));
	return avull;
}

VULL factorsofset(VULL avull){ // Can be improved with GCD analysis.
	VULL bvull=factorsof(avull[0]);
	for(I a=1;a<sz(avull);a++){
		VULL cvull=factorsof(avull[a]);
		SETULL asetull;
		for(auto dude1:bvull){
			for(auto dude2:cvull){
				asetull.insert(dude1*dude2);
			}
		}
		cvull=VULL(0);
		for(auto dude1:asetull)cvull.add(dude1);
		bvull=cvull;
	}
	return bvull;
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

	in>>al>>bl;
	cl=gcd(al,bl);
	ULL aull=cl;
	VPULL avpull=primefactorisationof(aull);
	for(auto dude:avpull)out<<dude.first<<" "<<dude.second<<nl;
	out<<0<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}