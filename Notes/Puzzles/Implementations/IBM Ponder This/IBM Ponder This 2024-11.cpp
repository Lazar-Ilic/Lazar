// "We're living Ultralife"-Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <sys/time.h>
//#include <bits/extc++.h>
// Instead Of Recoding Can Change Definition Like D To long double
using B=bool; // 8 bits=1 byte | [0,1]
using C=char; // 8 bits=1 byte | [-128,127]
using D=double; // 64 bits=8 bytes | [Eh]
using LD=long double; // 96 bits=12 bytes | [Eh]
using I=int; // 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits=4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=signed long long; // 64 bits=8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits=16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
#define all(a)((a).begin()),((a).end())
#define sortify(a) sort(all(a))
#define sortifyreverse(a) sort(all(a),greater<>())
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
const I p=998244353; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------


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
	//out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:


Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/
	ev={0,0,1,2,2,11,3,26,4,47,5,54,6,107,7,146,8,191,9,242,10,299,11,191,12,134,13,146,14,146,15,151,16,767,17,423,18,151,19,854,20,558,21,764,22,491,23,503,24,464,25,146,26,146,27,431,28,944,29,666,30,146,31,146,32,350,33,146,34,311,35,599,36,511,37,1559,38,599,39,944,40,1871,41,1679,42,990,43,1375,44,1907,45,990,46,551,47,959,48,1199,49,1244,50,990,51,1206,52,854,53,764,54,567,55,2876,56,854,57,503,58,503,59,2394,60,1154,61,1127,62,1952,63,368,64,575,65,1154,66,1664,67,446,68,608,69,3911,70,446,71,2111,72,1559,73,503,74,1559,75,1439,76,1296,77,1439,78,614,79,1454,80,614,81,527,82,503,83,1454,84,671,85,755,86,614,87,1274,88,614,89,4802,90,914,91,671,92,1106,93,839,94,2000,95,2399,96,1330,97,1879,98,2000,99,1330,100,4076,101,1274,102,1719,103,719,104,3596,105,1328,106,2511,107,3671,108,3834,109,1274,110,455,111,839,112,774,113,774,114,1271,115,2294,116,455,117,4259,118,1314,119,774,120,3419,121,839,122,2279,123,5711,124,731,125,2306,126,5391,127,1314,128,506,129,506,130,506,131,506,132,731,133,1244,134,1532,135,1244,136,2474,137,944,138,944,139,2474,140,2051,141,1691,142,4364,143,1895,144,1532,145,2306,146,4556,147,1823,148,5504,149,5715,150,1550,151,671,152,4199,153,671,154,1550,155,1691,156,2519,157,1616,158,5639,159,6215,160,971,161,1879,162,971,163,2051,164,2975,165,2799,166,4679,167,2799,168,1879,169,5904,170,6326,171,2546,172,7614,173,2546,174,4304,175,1223,176,1223,177,3968,178,4860,179,2183,180,3328,181,7146,182,5591,183,2876,184,9071,185,5183,186,1055,187,4986,188,3996,189,3184,190,3968,191,6236,192,1231,193,2903,194,1231,195,1231,196,2903,197,2174,198,1231,199,9551,200,2159,201,6431,202,3968,203,4175,204,524,205,6431,206,1391,207,4619,208,4175,209,2279,210,2000,211,1895,212,7884,213,1098,214,3996,215,1098,216,3015,217,1391,218,5823,219,439,220,4175,221,6734,222,5084,223,1919,224,9575,225,3503,226,332,227,8091,228,439,229,3056,230,3015,231,4759,232,1879,233,2351,234,1879,235,2183,236,1514,237,7175,238,5148,239,7175,240,8091,241,5067,242,8126,243,1514,244,2954,245,2954,246,396,247,2639,248,3431,249,2639,250,3456,251,4319,252,5186,253,10079,254,5744,255,1511,1310,9671,257,6695,258,1431,259,1431,260,3392,261,6614,262,3119,263,6614,264,871,265,3119,266,3644,267,4031,268,4527,269,7856,270,6460,271,4031,272,6039,273,871,274,4391,275,5607,276,4716,277,5148,278,4511,279,7859,280,128,281,7292,282,4716,283,4391,284,9950,285,3434,286,4031,287,2834,288,2834,289,4931,290,5186,291,3119,292,396,293,2831,294,1439,295,5094,296,1511,297,6599,298,8459,299,10139,300,6551,301,3932,302,3434,303,5159,304,5504,305,8714,306,5094,307,7859,308,5094,309,8816,310,5414,311,1250,312,5634,313,7808,314,9116,315,8816,316,2714,317,6434,318,1250,319,4199,320,4919,321,5414,322,3644,323,4079,324,5612,325,4931,326,5414,327,2351,328,2231,329,2231,330,5414,331,1250,332,1136,333,4931,334,10044,335,5504,336,1199,337,3527,338,3434,339,4444,340,3296,341,3296,342,1199,343,4239,344,1719,345,594,346,7391,347,594,348,491,349,3311,350,491,351,551,352,5900,353,3191,354,3191,355,2903,356,7292,357,3071,358,2903,359,2231,360,4759,361,594,362,6156,363,2714,364,5024,365,7271,366,4156,367,2159,368,2714,369,5231,370,2972,371,7271,372,4688,373,9575,374,3335,375,6908,376,7871,377,5391,378,6750,379,594,380,3555,381,10339,382,13424,383,7391,384,18972,385,3555,386,5231,387,3575,388,2160,389,5276,390,1532,391,407,392,1863,393,8411,394,191,395,5927,396,10204,397,8559,398,2351,399,6074,400,6074};
	y=2;
	for(al=1;al<401;al++){if(ev[2*al+1]<=655){ // The 128 256 Rather Than 1310 Case Is Solved Here Via OEIS Online Encyclopaedia Of Integer Sequences With al=280;al<281;al++
		for(bl=1;bl<=al;bl++){
			out<<al<<" "<<bl<<nl;
			for(cl=1;cl<=al;cl++){
				for(dl=1;dl<=al;dl++){
					for(el=1;el<=al;el++){
						// -2 a^4 f^2 - 2 a^2 b^2 d^2 + 2 a^2 b^2 e^2 + 2 a^2 b^2 f^2 + 2 a^2 c^2 d^2 - 2 a^2 c^2 e^2 + 2 a^2 c^2 f^2 + 2 a^2 d^2 f^2 + 2 a^2 e^2 f^2 - 2 a^2 f^4 - 2 b^4 e^2 + 2 b^2 c^2 d^2 + 2 b^2 c^2 e^2 - 2 b^2 c^2 f^2 + 2 b^2 d^2 e^2 - 2 b^2 e^4 + 2 b^2 e^2 f^2 - 2 c^4 d^2 - 2 c^2 d^4 + 2 c^2 d^2 e^2 + 2 c^2 d^2 f^2 - 2 d^2 e^2 f^2 = 1310
						// Solve For Using Quadratic Formula And Check Near +- Of Both Roots For f
						L f1=0;
						L f2=0;
						L aaa=(-2*al*al);
						L bbb=(-2*al*al*al*al+2*al*al*bl*bl+2*al*al*cl*cl+2*al*al*dl*dl+2*al*al*el*el-2*bl*bl*cl*cl+2*bl*bl*el*el+2*cl*cl*dl*dl-2*dl*dl*el*el);
						L ccc=(-2*al*al*bl*bl*dl*dl+2*al*al*bl*bl*el*el+2*al*al*cl*cl*dl*dl-2*al*al*cl*cl*el*el-2*bl*bl*bl*bl*el*el+2*bl*bl*cl*cl*dl*dl+2*bl*bl*cl*cl*el*el+2*bl*bl*dl*dl*el*el-2*bl*bl*el*el*el*el-2*cl*cl*cl*cl*dl*dl-2*cl*cl*dl*dl*dl*dl+2*cl*cl*dl*dl*el*el-1310);
						L fff1=0;
						L fff2=0;
						if((LD)bbb*bbb-4*(LD)aaa*ccc>=0)fff1=(-bbb+sqrt((LD)bbb*bbb-4*(LD)aaa*ccc))/(2*aaa); // Long Double Works Here But Alternately Can Convert To Python Or Try __int128 Due To Memory Overflow Around Here
						if((LD)bbb*bbb-4*(LD)aaa*ccc>=0)fff2=(-bbb-sqrt((LD)bbb*bbb-4*(LD)aaa*ccc))/(2*aaa);
						if(fff1>0)f1=sqrt(fff1);
						if(fff2>0)f2=sqrt(fff2);
						for(fl=f1-y;fl<f1+y;fl++)if(-2*al*al*al*al*fl*fl-2*al*al*bl*bl*dl*dl+2*al*al*bl*bl*el*el+2*al*al*bl*bl*fl*fl+2*al*al*cl*cl*dl*dl-2*al*al*cl*cl*el*el+2*al*al*cl*cl*fl*fl+2*al*al*dl*dl*fl*fl+2*al*al*el*el*fl*fl-2*al*al*fl*fl*fl*fl-2*bl*bl*bl*bl*el*el+2*bl*bl*cl*cl*dl*dl+2*bl*bl*cl*cl*el*el-2*bl*bl*cl*cl*fl*fl+2*bl*bl*dl*dl*el*el-2*bl*bl*el*el*el*el+2*bl*bl*el*el*fl*fl-2*cl*cl*cl*cl*dl*dl-2*cl*cl*dl*dl*dl*dl+2*cl*cl*dl*dl*el*el+2*cl*cl*dl*dl*fl*fl-2*dl*dl*el*el*fl*fl==1310)out<<"["<<al<<","<<bl<<","<<cl<<","<<dl<<","<<el<<","<<fl<<"]"<<nl;
						for(fl=f2-y;fl<f2+y;fl++)if(-2*al*al*al*al*fl*fl-2*al*al*bl*bl*dl*dl+2*al*al*bl*bl*el*el+2*al*al*bl*bl*fl*fl+2*al*al*cl*cl*dl*dl-2*al*al*cl*cl*el*el+2*al*al*cl*cl*fl*fl+2*al*al*dl*dl*fl*fl+2*al*al*el*el*fl*fl-2*al*al*fl*fl*fl*fl-2*bl*bl*bl*bl*el*el+2*bl*bl*cl*cl*dl*dl+2*bl*bl*cl*cl*el*el-2*bl*bl*cl*cl*fl*fl+2*bl*bl*dl*dl*el*el-2*bl*bl*el*el*el*el+2*bl*bl*el*el*fl*fl-2*cl*cl*cl*cl*dl*dl-2*cl*cl*dl*dl*dl*dl+2*cl*cl*dl*dl*el*el+2*cl*cl*dl*dl*fl*fl-2*dl*dl*el*el*fl*fl==1310)out<<"["<<al<<","<<bl<<","<<cl<<","<<dl<<","<<el<<","<<fl<<"]"<<nl;
						for(fl=-f1-y;fl<-f1+y;fl++)if(-2*al*al*al*al*fl*fl-2*al*al*bl*bl*dl*dl+2*al*al*bl*bl*el*el+2*al*al*bl*bl*fl*fl+2*al*al*cl*cl*dl*dl-2*al*al*cl*cl*el*el+2*al*al*cl*cl*fl*fl+2*al*al*dl*dl*fl*fl+2*al*al*el*el*fl*fl-2*al*al*fl*fl*fl*fl-2*bl*bl*bl*bl*el*el+2*bl*bl*cl*cl*dl*dl+2*bl*bl*cl*cl*el*el-2*bl*bl*cl*cl*fl*fl+2*bl*bl*dl*dl*el*el-2*bl*bl*el*el*el*el+2*bl*bl*el*el*fl*fl-2*cl*cl*cl*cl*dl*dl-2*cl*cl*dl*dl*dl*dl+2*cl*cl*dl*dl*el*el+2*cl*cl*dl*dl*fl*fl-2*dl*dl*el*el*fl*fl==1310)out<<"["<<al<<","<<bl<<","<<cl<<","<<dl<<","<<el<<","<<fl<<"]"<<nl;
						for(fl=-f2-y;fl<-f2+y;fl++)if(-2*al*al*al*al*fl*fl-2*al*al*bl*bl*dl*dl+2*al*al*bl*bl*el*el+2*al*al*bl*bl*fl*fl+2*al*al*cl*cl*dl*dl-2*al*al*cl*cl*el*el+2*al*al*cl*cl*fl*fl+2*al*al*dl*dl*fl*fl+2*al*al*el*el*fl*fl-2*al*al*fl*fl*fl*fl-2*bl*bl*bl*bl*el*el+2*bl*bl*cl*cl*dl*dl+2*bl*bl*cl*cl*el*el-2*bl*bl*cl*cl*fl*fl+2*bl*bl*dl*dl*el*el-2*bl*bl*el*el*el*el+2*bl*bl*el*el*fl*fl-2*cl*cl*cl*cl*dl*dl-2*cl*cl*dl*dl*dl*dl+2*cl*cl*dl*dl*el*el+2*cl*cl*dl*dl*fl*fl-2*dl*dl*el*el*fl*fl==1310)out<<"["<<al<<","<<bl<<","<<cl<<","<<dl<<","<<el<<","<<fl<<"]"<<nl;
					}
				}
			}
		}
	}}
}

I main(){zz();I a=1;while(a--){az();}}