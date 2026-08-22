// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

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
using L=signed long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits = 16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);out<<fixed<<setprecision(10);
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
const L p=1000000000039; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

V lolol={1000003,1000033,1000037,1000039,1000081,1000099,1000117,1000121,1000133,1000151,1000159,1000171,1000183,1000187,1000193,1000199,1000211,1000213,1000231,1000249,1000253,1000273,1000289,1000291,1000303,1000313,1000333,1000357,1000367,1000381,1000393,1000397,1000403,1000409,1000423,1000427,1000429,1000453,1000457,1000507,1000537,1000541,1000547,1000577,1000579,1000589,1000609,1000619,1000621,1000639,1000651,1000667,1000669,1000679,1000691,1000697,1000721,1000723,1000763,1000777,1000793,1000829,1000847,1000849,1000859,1000861,1000889,1000907,1000919,1000921,1000931,1000969,1000973,1000981,1000999,1001003,1001017,1001023,1001027,1001041,1001069,1001081,1001087,1001089,1001093,1001107,1001123,1001153,1001159,1001173,1001177,1001191,1001197,1001219,1001237,1001267,1001279,1001291,1001303,1001311,1001321,1001323,1001327,1001347,1001353,1001369,1001381,1001387,1001389,1001401,1001411,1001431,1001447,1001459,1001467,1001491,1001501,1001527,1001531,1001549,1001551,1001563,1001569,1001587,1001593,1001621,1001629,1001639,1001659,1001669,1001683,1001687,1001713,1001723,1001743,1001783,1001797,1001801,1001807,1001809,1001821,1001831,1001839,1001911,1001933,1001941,1001947,1001953,1001977,1001981,1001983,1001989,1002017,1002049,1002061,1002073,1002077,1002083,1002091,1002101,1002109,1002121,1002143,1002149,1002151,1002173,1002191,1002227,1002241,1002247,1002257,1002259,1002263,1002289,1002299,1002341,1002343,1002347,1002349,1002359,1002361,1002377,1002403,1002427,1002433,1002451,1002457,1002467,1002481,1002487,1002493,1002503,1002511,1002517,1002523,1002527,1002553,1002569,1002577,1002583,1002619,1002623,1002647,1002653,1002679,1002709,1002713,1002719,1002721,1002739,1002751,1002767,1002769,1002773,1002787,1002797,1002809,1002817,1002821,1002851,1002853,1002857,1002863,1002871,1002887,1002893,1002899,1002913,1002917,1002929,1002931,1002973,1002979,1003001,1003003,1003019,1003039,1003049,1003087,1003091,1003097,1003103,1003109,1003111,1003133,1003141,1003193,1003199,1003201,1003241,1003259,1003273,1003279,1003291,1003307,1003337,1003349,1003351,1003361,1003363,1003367,1003369,1003381,1003397,1003411,1003417,1003433,1003463,1003469,1003507,1003517,1003543,1003549,1003589,1003601,1003609,1003619,1003621,1003627,1003631,1003679,1003693,1003711,1003729,1003733,1003741,1003747,1003753,1003757,1003763,1003771,1003787,1003817,1003819,1003841,1003879,1003889,1003897,1003907,1003909,1003913,1003931,1003943,1003957,1003963,1004027,1004033,1004053,1004057,1004063,1004077,1004089,1004117,1004119,1004137,1004141,1004161,1004167,1004209,1004221,1004233,1004273,1004279,1004287,1004293,1004303,1004317,1004323,1004363,1004371,1004401,1004429,1004441,1004449,1004453,1004461,1004477,1004483,1004501,1004527,1004537,1004551,1004561,1004567,1004599,1004651,1004657,1004659,1004669,1004671,1004677,1004687,1004723,1004737,1004743,1004747,1004749,1004761,1004779,1004797,1004873,1004903,1004911,1004917,1004963,1004977,1004981,1004987,1005007,1005013,1005019,1005029,1005041,1005049,1005071,1005073,1005079,1005101,1005107,1005131,1005133,1005143,1005161,1005187,1005203,1005209,1005217,1005223,1005229,1005239,1005241,1005269,1005287,1005293,1005313,1005317,1005331,1005349,1005359,1005371,1005373,1005391,1005409,1005413,1005427,1005437,1005439,1005457,1005467,1005481,1005493,1005503,1005527,1005541,1005551,1005553,1005581,1005593,1005617,1005619,1005637,1005643,1005647,1005661,1005677,1005679,1005701,1005709,1005751,1005761,1005821,1005827,1005833,1005883,1005911,1005913,1005931,1005937,1005959,1005971,1005989,1006003,1006007,1006021,1006037,1006063,1006087,1006091,1006123,1006133,1006147,1006151,1006153,1006163,1006169,1006171,1006177,1006189,1006193,1006217,1006219,1006231,1006237,1006241,1006249,1006253,1006267,1006279,1006301,1006303,1006307,1006309,1006331,1006333,1006337,1006339,1006351,1006361,1006367,1006391,1006393,1006433,1006441,1006463,1006469,1006471,1006493,1006507,1006513,1006531,1006543,1006547,1006559,1006583,1006589,1006609,1006613,1006633,1006637,1006651,1006711,1006721,1006739,1006751,1006769,1006781,1006783,1006799,1006847,1006853,1006861,1006877,1006879,1006883,1006891,1006897,1006933,1006937,1006949,1006969,1006979,1006987,1006991,1007021,1007023,1007047,1007059,1007081,1007089,1007099,1007117,1007119,1007129,1007137,1007161,1007173,1007179,1007203,1007231,1007243,1007249,1007297,1007299,1007309,1007317,1007339,1007353,1007359,1007381,1007387,1007401,1007417,1007429,1007441,1007459,1007467,1007483,1007497,1007519,1007527,1007549,1007557,1007597,1007599,1007609,1007647,1007651,1007681,1007683,1007693,1007701,1007711,1007719,1007723,1007729,1007731,1007749,1007753,1007759,1007767,1007771,1007789,1007801,1007807,1007813,1007819,1007827,1007857,1007861,1007873,1007887,1007891,1007921,1007933,1007939,1007957,1007959,1007971,1007977,1008001,1008013,1008017,1008031,1008037,1008041,1008043,1008101,1008131,1008157,1008181,1008187,1008193,1008199,1008209,1008223,1008229,1008233,1008239,1008247,1008257,1008263,1008317,1008323,1008331,1008347,1008353,1008373,1008379,1008401,1008407,1008409,1008419,1008421,1008433,1008437,1008451,1008467,1008493,1008499,1008503};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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


Test + Additional Input:


Analysis:

*/

	in>>a;
	VMLI avmii;
	avmii=VMLI(1000001);
	avs=VS(a);
	c=0;
	z=rng()%640;
	for(b=0;b<a;b++){
		in>>as;
		avs[b]=as;
		c+=sz(as);
		bl=1;
		cl=lolol[z]; // Semiarbitrary prime.
		dl=0;
		for(d=0;d<sz(as);d++){
			dl=(dl+bl*(as[d]-'a'+1))%p;
			avmii[d][dl]++;
			bl=(bl*cl)%p;
		}
	}
	al=L(a)*2*c;
	for(auto dude:avs){
		bl=1;
		cl=lolol[z];
		dl=0;
		for(d=sz(dude)-1;d>=0;d--){
			dl=(dl+bl*(dude[d]-'a'+1))%p;
			if(avmii[sz(dude)-1-d].count(dl))al-=2*avmii[sz(dude)-1-d][dl];
			bl=(bl*cl)%p;
		}
	}
	out<<al<<nl;
}

I main(){zz();I a=1;while(a--){az();}}