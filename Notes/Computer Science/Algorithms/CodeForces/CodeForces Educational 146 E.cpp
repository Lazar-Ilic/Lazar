// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp
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
using MSI=map<S,I>;
using MII=map<I,I>;
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
#define Lsubsetsize __builtin_popcountll
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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

Z az(){
	// Optimise by deleting unused variables or test-casing in loop.
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
The underlying is a matching task of matching to valid vertices with different costs on a tree the path is the minimal path and perhaps a smoothing argumentation reveals some sort of trivial structure. Any leaf which is already good we may uh ignore I uh think otherwise there can just be like a simple flip flop I uh think once we prune off those dudes uh not sure maybe check in the test case if that is uh optimal here is merely like the uh sum of 2x each edge which does get uh flip flopped along. Uh OKOKOK so we uh flip flop but like uh for each dude we uh OKOKOK but the uh bottom dudes uh OK so each bottom uh tree dude each edge gets done 2 times I uh think is uh ensured right like each bottom takes an out and a uh in I think is ensured so it is 2x all of those edges then uh ignore is provably optimal I uh think.

12 12 20 17 15

2[12+12+20+17+15] = 152

Uh OKOKOK no no no.

2 0 2 0 2 0 ...

Instead we can like uh I think uh like...

2 1 1 1 1 0 2 1 1 1...1

Or terminate on a a 02 instance.

Min DP thus far I uh think in 3 states uh. But then uh once we change the uh underlying value in this Dynamic Program the uh optimal can uh change I think uh shift I think.

The underlying is then like basically a uh like a uh... we auxiliary up a 0 I uh think is like a uh...

2 0 2 0 2
2 0 2 1 1

Oh first dude has to be a uh 2 I think so then like... from there after that it is like a uh opt in to doing a full 02 and where we do those is add flow any time we uh can I think is uh strictly uh dominating I uh think so like greedy until the very end with 3 left or something uh... always flow frm larger in to a uh smaller right?

10 6 12 15 20 8 17 12 15 umm is like a uh... is it better here to have a uh 1 1 or a uh 0 2 I think?

2 1 1 1 0 2 0 2 1 ? uh must uh end in 2 I think uh. Oh uh no no no we always gotta do a uh 2.

2*10+1*6+1*12+1*15+0*20+2*8+0*17+2*12+2*15 = 108

Range update and uh a uh segment tree supporting a range sums I think uh. 0s can only go in the middle uh I think uh.

2*[12+6+12+10+8+12+15]

Uh OKOKOK 15 minutes in so the structure is more obviously something like uh we want to be uh taking like 2 0 2 0 2 0 2

Or like uh 2 2 0 2 0 2 2 2

Uh want to uh then uh when we do a uh update consider something but like still uh Left Right Dynamic Program must be executed to uh somehow range update or propagate through or whatever...

https://usaco.guide/gold/intro-dp?lang=cpp

https://atcoder.jp/contests/dp/tasks/dp_a

Something kind of like this uh canonical task but with uh updates.

In any case uh 2 2 2 is obviously uh never optimal and so thus we basically just do uh a uh 2 2 0 2 could become a uh 2 0 2 2 I uh OKOKOK so maybe we need to uh bust out like 2 segment trees uh range summing or range changing if we flip flooped from like a uh 2 2 0 2 0 2 0 2 0 2 0 2 0 2 0 ... 2 2 configuration to a uh 2 0 2 0 2 0 2 0 2 ... 0 2 configuration uh at each query because like we obviously can not simply update shwoop a doop a loop in that fashion but uh breaking the actual DP here at the proper indexing is like a uh trivialioso I think as long as we are tracking each 2 2 instance in the background we can then maybe even like range maximum delta query on the Deltas in the underlying up to that next 2 2 index on the other uh underlying and then do that Delta query there up to that index on the underlying and uh store the even and odd dudes in their own separate segment trees basically to do a relevant flip flop range sums on those relevant intervals should be like a simple quick Dynamic Program uh recursion to reply to these live queries even in a uh legitimate live streaming setting in uh O[log n] which is an ACcepted proposal for an algorithm and let us see if I can uh smash this out in uh 23 minutes left on the clock way too slow on my D implementation here today uh ummm ergh ugh. Uhh something sorta kinda something like uh like this I think uh after upsolving the initial configuration on uh 2 0 2 0 2 2 0 2 or whatever...
*/

	in>>a;
	av=V(a-1);
	for(b=0;b<a-1;b++)in>>av[b];
	in>>b;
	al=;
	for(c=0;c<b;c++){
		in>>d>>e;
		d--;
		f=armq.query();
		// Update sorted set of 2 2 index locations uh.
		if(){
			al+=aseg.query();
			al-=bseg.query();
		}
		else{
			al-=aseg.query();
			al+=bseg.query();
		}
		out<<al<<nl;
	}
}

I main(){zz();I a=1;while(a--){az();}}