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
Post Contest Analysis:
So in any case this is yet another like 5|5 in a row instance where I fakesolve fakeonsight a Division 1 Task DEF without Truly proving optimality or considering a variety of edge and worst case input cases and ACe a jokey easy-to-ace test Input case #1 and then go in for the round in a brutally chronically sleep deprived state in a brutally measurably loud shitty fucking mediocre fucking Nampus fucking apartment and then tank out rating Rest In Peace to my ratingerino today here fucking brutal fucking fuck fuck fuck when will I get 2-Kyu Master ugh ungh maybe better luck from Proto IO 2 rented house soon soon soon fuck this fucking apartment.

Test + Additional Input:


Analysis:
OKOKOK so you want for uh a bunch of the paths to have at least 1 0 and 1 if possible but especially want uh 1 0 in each uh path uh... the other way to count it up is to note that uh the uh the only paths with MEX uh 0 are those of 11 subtrees uh connected components of edges of 1s uh... and those with MEX uh 1 are those of the uh 0 connected uh components uh... means immediately like 1 OKOKOK idea here is to uh simply consider the uh uh uh the uh like uh a simple Breadth First Search with uh alternating Black White scheme ensuring to have uh more 0s than 1s immediately leads to like at most n/2 dudes being 1 and n/2 dudes being 0 and the rest being 2 is already quite strong uh good... asymptotically that is vast vast vast majority of uh oh I see uh uh uh the vertices get coloured OKOKOK so still we can uh do it similarly uh uh uh uh I think the uh 10 case is uh interesting there are like [10 choose 2] + 10 = 55 dudes is like a uh maximum of uh 110 and -14 means that uh like uh... oh each uh single dude is like a uh -2 or uh -1 off of the uh maximum umm... -4 of the 2 and uh -6 of the uh 1 variety uh... any root works uh... OKOKOK try it out uh... should work uh trivially uh by the usual uh BFS...

OKOKOK drop to Task A maybe soon uh uh uh 450 points uh uh uh but what is a bad case worst case input here uh uh uh uh like a star... that dude will uh be good I think uh... dunno dunno dunno how uh... would think that uh a leaf uh... uh uh uh leaf uh... leaf being uh 1 uh... how is this not provably uh uh uh optimal ugh I always Late Register in without Truly onsighting uh Proof Of Correctness ugh! Ugh! Ugh! Perhaps there is some like uh... we always want uh Leafs in fact to be uh uh uh ... like 0s but then uh... going up is like what if we have a uh conflict upwards is like uh... set a ton of leafs to be 0s and then uh conflict upwards is like uh... something about maximal chains of uh 0s in the tree... and overall 0s and uh 1s...

.\\\\\\\\\
|
.
\\\\\\\\\

So uh 2 uh stars here uh connected by like uh I see that will render out uh like uh... I see we want uh the top 2 dudes to be uh 1s and uh all the leafs to be 0s obviously here like uh... so maybe uh... need to reason more carefully here about like degrees and internal paths maybe a Heavy Light Decomposition somehow here considering like uh exclusively the uh uh uh consider uh instead of that formula here taking off more like uh... OKOKOK new max is like uh related totally to number of 0s now so uh consider that only the uh uh uh number of 0s and how low that can go here would be like 3 0s induced off of that uh chain there. So the precise 0 subgraph sub induction assuming that no 2 neihgbours are both 1s uh... so 1 implies that uh parent is a uh 0 clearly uh... now go try bottoms up I think uh... and then see what what what happens uh... set all yes but then the root is also topical and uh relevant unless we degree fix here somehow monovariant uh ugh. OKOKOK uh maybe just try random roots might uh fail too ugh ugh ugh ugh uh... take some high degree node set it to uh 1 and all its neighbours to 0 and then search from there uh... maybe by parity it suffices to try it out on uh 2 adjacent nodes qua roots uh... only try 2 potential cases is a constant factor of 2 in to 2 Breadth First Searches to try.

Maybe we can somehow like cleverly try setting all dudes to uh 0 first and then bottoms up to ensure uh that uh uh uh like some dudes get set to uh 1 optimally uh uh uh considering the lengths of the chains of uh 0s like... we shatter these dudes have a ton of 2 chains of 0s and uh any time we have some path basically uh actually some uh induced like star path basically star or uh path we then want to uh set the middle dude of the uh star somehow to uh 1 basically...
*/

	in>>a;
	avv=VV(a,V(0));
	for(b=0;b<a-1;b++){
		in>>c>>d;
		c--;d--;
		avv[c].add(d);
		avv[d].add(c);
	}

vector<bool> processed(a,0);
V distances(a,0);
V parents(a,0);
VV children(a,V(0));
VV levels(a,V(0));
levels[0].add(0);
int root=0,aaa=0;
aq.push(root);
processed[root]=1;
while(!aq.empty()){
	aaa=aq.front();
	aq.pop();
	for(auto neighbour:avv[aaa]){
		if(!processed[neighbour]){
			aq.push(neighbour);
			processed[neighbour]=1;
			children[aaa].add(neighbour);
			parents[neighbour]=aaa;
			distances[neighbour]=distances[aaa]+1;
			levels[distances[aaa]+1].add(neighbour);
		}
	}
}

	I oddlevels=0;
	I evenlevels=0;
	for(b=0;b<a;b+=2)evenlevels+=sz(levels[b]);
	for(b=1;b<a;b+=2)oddlevels+=sz(levels[b]);
	out<<L(2)*(L(a)*(a-1)/2+a)-a-min(oddlevels,evenlevels)<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}