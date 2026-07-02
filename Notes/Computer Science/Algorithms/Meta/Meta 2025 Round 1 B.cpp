// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <sys/time.h>
//#include <bits/extc++.h>
// Instead Of Recoding Can Change Definition Like D To long double
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using SHORT=short; // 16 bits=2 bytes | [-32768,32767]
using I8=int8_t; // 8 bits=1 byte | [-128,127]
using UI8=uint8_t; // 8 bits=1 byte | [0,255]
using UI=unsigned int;// 32 bits=4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t;// 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=signed long long;// 64 bits=8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long;// 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128;// 128 bits=16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
using S=string;
using PB=pair<B,B>;
using PC=pair<C,C>;
using PD=pair<D,D>;
using PDI=pair<D,I>;
using PLDI=pair<LD,I>;
using P=pair<I,I>;
using PIP=pair<I,P>;
using PL=pair<L,L>;
using PLD=pair<LD,LD>;
using PS=pair<S,S>;
using PSL=pair<S,L>;
using PIS=pair<I,S>;
using PSI=pair<S,I>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
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
using SETPSI=set<PSI>;
using PLSET=pair<L,SET>;
using VPLSET=vector<PLSET>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MIL=map<I,L>;
using MIMII=map<I,MII>;
using MLI=map<L,I>;
using MLL=map<L,L>;
using MPI=map<P,I>;
using MCI=map<C,I>;
using MUI=map<U,I>;
using VMII=vector<MII>;
using VMLI=vector<MLI>;
using UMSI=unordered_map<S,I>;
using UMII=unordered_map<I,I>;
using UMIL=unordered_map<I,L>;
using UMLL=unordered_map<L,L>;
using UMUI=unordered_map<U,I>;
using VUMII=vector<UMII>;
using DQ=deque<I>;
using ST=stack<I>;
using STST=stack<ST>;
using STP=stack<P>;
using STPL=stack<PL>;
using Q=queue<I>;
// Arrays [Declared Large] Are Often Sharper
using VB=vector<B>;
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
using VVVVVB=vector<VVVVB>;
using VVVVVVB=vector<VVVVVB>;
using VUSETS=vector<USETS>;
using VVUSETS=vector<VUSETS>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VUI=vector<UI>;
using VL=vector<L>;
using VULL=vector<ULL>;
using VUI128=vector<UI128>;
using VLD=vector<LD>;
using VS=vector<S>;
using VU=vector<U>;
using VPB=vector<PB>;
using VPC=vector<PC>;
using VPD=vector<PD>;
using VP=vector<P>;
using VPIP=vector<PIP>;
using VPL=vector<PL>;
using VPLD=vector<PLD>;
using VPS=vector<PS>;
using VPIS=vector<PIS>;
using VPSI=vector<PSI>;
using VPLI=vector<PLI>;
using VPDI=vector<PDI>;
using VPLDI=vector<PLDI>;
using VPID=vector<PID>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVVV=vector<VVV>;
using VVVVV=vector<VVVV>;
using VVVVVV=vector<VVVVV>;
using VVVVVVV=vector<VVVVVV>;
using VVL=vector<VL>;
using VVVL=vector<VVL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VVULL=vector<VULL>;
using VSET=vector<SET>;
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using PQ=priority_queue<I>;
using MINPQ=priority_queue<I,V,greater<I>>;
using PQL=priority_queue<L>;
using MINPQL=priority_queue<L,VL,greater<L>>;
using PQVL=priority_queue<VL>;
using MINPQVL=priority_queue<VL,VVL,greater<VL>>;
using PQP=priority_queue<P>;
using MINPQP=priority_queue<P,VP,greater<P>>;
using PQPL=priority_queue<PL>;
using MINPQPL=priority_queue<PL,VPL,greater<PL>>;
using PQPIP=priority_queue<PIP>;
using SETV=set<V>;
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QV=queue<V>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MLV=map<L,V>;
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
using MVI=map<V,I>;
using MVL=map<V,L>;
using MVV=map<V,V>;
using MVBV=map<VB,V>;
using PIV=pair<I,V>;
using PDV=pair<D,V>;
using PULL=pair<ULL,ULL>;
using VPULL=vector<PULL>;
using MULLPULL=map<ULL,PULL>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using CLD=complex<LD>;
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
#define subsetsizeL __builtin_popcountll
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a)((a).begin()),((a).end())
#define sortify(a) sort(all(a))
#define uniquify(a)(a).resize(unique(all(a))-(a).begin())
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
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);out<<fixed<<setprecision(10);
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
const I p=1000000007; // 998244353 1000000007 // 1073741824 * 2 > INT_MAX So 1234567891 Forces (long long) Conversion Or Usage Before + Modulo p
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

L inverse(L al){
	L bl=1;
	I a=p-2;
	while(a!=0){
		if(a%2==1){
			bl=bl*al%p;
		}
		al=al*al%p;
		a/=2;
	}
	return bl;
}

I testcase=0;
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
	VB avb,bvb,cvb,dvb,evb,fvb,gvb,hvb,ivb,jvb,kvb,lvb,mvb;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
	VVB avvb,bvvb,cvvb,dvvb,evvb,fvvb,gvvb,hvvb,ivvb,jvvb;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;
	MINPQ aminpq,bminpq,cminpq,dminpq,eminpq,fminpq,gminpq;
	out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:


Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/
	in>>al>>bl>>cl;
	avl=VL(0);
	bvl=VL(0);
	for(a=2;a<=10000000;a++){
		if(cl%a==0){
			b=0;
			while(cl%a==0){
				cl/=a;
				b++;
			}
			avl.add(a);
			bvl.add(b);
		}
	}
	if(cl!=1){
		avl.add(cl);
		bvl.add(1);
		cl=1;
	}
	while(sz(avl)<12){
		avl.add(1);
		bvl.add(0);
	}
	avvl=VVL(12,VL(0));
	for(a=0;a<12;a++){
		avvl[a].add(1);
		dl=1;
		for(b=1;b<=bvl[a];b++){
			dl*=avl[a];
			avvl[a].add(dl);
		}
	}
	evl=VL(100);
	evl[1]=al%p;
	for(a=2;a<100;a++)evl[a]=((al+a-1)%p*evl[a-1])%p;
	fvl=VL(100);
	fvl[0]=1;
	for(a=1;a<100;a++)fvl[a]=(a*fvl[a-1])%p;
	cvl=VL(100);
	for(a=0;a<100;a++)cvl[a]=inverse(fvl[a]);
	dvl=VL(100);
	dvl[0]=1;
	for(a=1;a<100;a++)dvl[a]=evl[a]*cvl[a]%p;
	dl=0;
	for(I a0=0;a0<=bvl[0];a0++)for(I a1=0;a1<=bvl[1];a1++)for(I a2=0;a2<=bvl[2];a2++)for(I a3=0;a3<=bvl[3];a3++)for(I a4=0;a4<=bvl[4];a4++)for(I a5=0;a5<=bvl[5];a5++)for(I a6=0;a6<=bvl[6];a6++)for(I a7=0;a7<=bvl[7];a7++)for(I a8=0;a8<=bvl[8];a8++)for(I a9=0;a9<=bvl[9];a9++)for(I a10=0;a10<=bvl[10];a10++)for(I a11=0;a11<=bvl[11];a11++){
		el=avvl[0][a0]*avvl[1][a1]*avvl[2][a2]*avvl[3][a3]*avvl[4][a4]*avvl[5][a5]*avvl[6][a6]*avvl[7][a7]*avvl[8][a8]*avvl[9][a9]*avvl[10][a10]*avvl[11][a11];
		if(el<=bl){
			fl=1;
			fl=(fl*dvl[a0]%p*dvl[bvl[0]-a0])%p;fl=(fl*dvl[a1]%p*dvl[bvl[1]-a1])%p;fl=(fl*dvl[a2]%p*dvl[bvl[2]-a2])%p;fl=(fl*dvl[a3]%p*dvl[bvl[3]-a3])%p;fl=(fl*dvl[a4]%p*dvl[bvl[4]-a4])%p;fl=(fl*dvl[a5]%p*dvl[bvl[5]-a5])%p;fl=(fl*dvl[a6]%p*dvl[bvl[6]-a6])%p;fl=(fl*dvl[a7]%p*dvl[bvl[7]-a7])%p;fl=(fl*dvl[a8]%p*dvl[bvl[8]-a8])%p;fl=(fl*dvl[a9]%p*dvl[bvl[9]-a9])%p;fl=(fl*dvl[a10]%p*dvl[bvl[10]-a10])%p;fl=(fl*dvl[a11]%p*dvl[bvl[11]-a11])%p;
			dl=(dl+fl)%p;
		}
	}
	out<<dl<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}