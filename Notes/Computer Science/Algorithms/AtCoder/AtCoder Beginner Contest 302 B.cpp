// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <sys/time.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits = 16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
using PSI=pair<S,I>;
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
using VUI128=vector<UI128>;
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
using VPSI=vector<PSI>;
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
using PQ=priority_queue<I>;
using MINPQ=priority_queue<I,V,greater<I>>;
using PQL=priority_queue<L>;
using MINPQL=priority_queue<L,VL,greater<L>>;
using PQP=priority_queue<P>;
using MINPQP=priority_queue<P,VP,greater<P>>;
using PQPL=priority_queue<PL>;
using MINPQPL=priority_queue<PL,VPL,greater<PL>>;
using SETV=set<V>;
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MLV=map<L,V>;
using MVI=map<V,I>;
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
#define all(a) ((a).begin()),((a).end())
#define sortify(a) sort(all(a))
#define uniquify(a) (a).resize(unique(all(a))-(a).begin())
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
const I p=998244353; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

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

/*
Analysis:


Post Contest Analysis:
Pretty bad trashy kind of CP code here... we want to be sharper and have sharp precomputes for tasks such as this one at work... dunno frankly was considering just buffering with 4 blank spaces all around is like an additional O[a+b] addition factor of space usage to then simplify code and like... can check first if (avs[c][d]=='s') prior to then entering the if body and then going through checking uh straight up bona fide 8 nested if if if if calls... or I think the way compile time might handle optimal is 1 checker up front in a separate if and then logically 8 uh if( and and and ) statements is OK here good runtime and performance and legibility.

Test + Additional Input:

*/

	in>>a>>b;
	avs=VS(a);
	for(c=0;c<a;c++)in>>avs[c];
	for(c=0;c<a;c++){
		for(d=0;d<b;d++){ // Can be pruned in to starting with uh esses... and maybe even uh further somehow with a sharp directional Breadth First Searching strategy and a coordinatewise set inclusion strategy approach really depending upon expected Inupts and optimised shortcircuiting techniques here.
			if(d+4<b and avs[c][d]=='s' and avs[c][d+1]=='n' and avs[c][d+2]=='u' and avs[c][d+3]=='k' and avs[c][d+4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c<<" "<<1+d+1<<nl<<1+c<<" "<<1+d+2<<nl<<1+c<<" "<<1+d+3<<nl<<1+c<<" "<<1+d+4<<nl;
				return;
			}
			if(c+4<a and d+4<b and avs[c][d]=='s' and avs[c+1][d+1]=='n' and avs[c+2][d+2]=='u' and avs[c+3][d+3]=='k' and avs[c+4][d+4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c+1<<" "<<1+d+1<<nl<<1+c+2<<" "<<1+d+2<<nl<<1+c+3<<" "<<1+d+3<<nl<<1+c+4<<" "<<1+d+4<<nl;
				return;
			}
			if(c+4<a and avs[c][d]=='s' and avs[c+1][d]=='n' and avs[c+2][d]=='u' and avs[c+3][d]=='k' and avs[c+4][d]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c+1<<" "<<1+d<<nl<<1+c+2<<" "<<1+d<<nl<<1+c+3<<" "<<1+d<<nl<<1+c+4<<" "<<1+d<<nl;
				return;
			}
			if(d-4>=0 and avs[c][d]=='s' and avs[c][d-1]=='n' and avs[c][d-2]=='u' and avs[c][d-3]=='k' and avs[c][d-4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c<<" "<<1+d-1<<nl<<1+c<<" "<<1+d-2<<nl<<1+c<<" "<<1+d-3<<nl<<1+c<<" "<<1+d-4<<nl;
				return;
			}
			if(c-4>=0 and avs[c][d]=='s' and avs[c-1][d]=='n' and avs[c-2][d]=='u' and avs[c-3][d]=='k' and avs[c-4][d]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c-1<<" "<<1+d<<nl<<1+c-2<<" "<<1+d<<nl<<1+c-3<<" "<<1+d<<nl<<1+c-4<<" "<<1+d<<nl;
				return;
			}
			if(c-4>=0 and d+4<b and avs[c][d]=='s' and avs[c-1][d+1]=='n' and avs[c-2][d+2]=='u' and avs[c-3][d+3]=='k' and avs[c-4][d+4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c-1<<" "<<1+d+1<<nl<<1+c-2<<" "<<1+d+2<<nl<<1+c-3<<" "<<1+d+3<<nl<<1+c-4<<" "<<1+d+4<<nl;
				return;
			}
			if(c-4>=0 and d-4>=0 and avs[c][d]=='s' and avs[c-1][d-1]=='n' and avs[c-2][d-2]=='u' and avs[c-3][d-3]=='k' and avs[c-4][d-4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c-1<<" "<<1+d-1<<nl<<1+c-2<<" "<<1+d-2<<nl<<1+c-3<<" "<<1+d-3<<nl<<1+c-4<<" "<<1+d-4<<nl;
				return;
			}
			if(c+4<a and d-4>=0 and avs[c][d]=='s' and avs[c+1][d-1]=='n' and avs[c+2][d-2]=='u' and avs[c+3][d-3]=='k' and avs[c+4][d-4]=='e'){
				out<<1+c<<" "<<1+d<<nl<<1+c+1<<" "<<1+d-1<<nl<<1+c+2<<" "<<1+d-2<<nl<<1+c+3<<" "<<1+d-3<<nl<<1+c+4<<" "<<1+d-4<<nl;
				return;
			}
		}
	}
}

I main(){zz();I a=1;while(a--){az();}}