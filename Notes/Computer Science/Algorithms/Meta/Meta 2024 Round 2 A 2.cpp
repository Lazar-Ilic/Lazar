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
Here is a suboptimal code which would generate the code:

	for(a=3;a<=17;a+=2){
		out<<"for(I a0=1;a0<10;a0++)";
		for(b=1;b<a/2;b++)out<<"for(I a"<<b<<"=a"<<b-1<<";a"<<b<<"<10;a"<<b<<"++)";
		out<<"for(I a"<<a/2<<"=a"<<a/2-1<<"+1;a"<<a/2<<"<10;a"<<a/2<<"++)";
		out<<"for(I a"<<a/2+1<<"=a"<<a/2<<"-1;a"<<a/2+1<<">0;a"<<a/2+1<<"--)";
		for(b=a/2+2;b<a;b++)out<<"for(I a"<<b<<"=a"<<b-1<<";a"<<b<<">0;a"<<b<<"--)";
		out<<"avl.add(";
		for(b=0;b<a;b++)out<<"cvl["<<b<<"]*a"<<b<<"+";
		out<<"0);"<<nl;
	}

Generates:

for(I a0=1;a0<10;a0++)for(I a1=a0+1;a1<10;a1++)for(I a2=a1-1;a2>0;a2--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1+1;a2<10;a2++)for(I a3=a2-1;a3>0;a3--)for(I a4=a3;a4>0;a4--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2+1;a3<10;a3++)for(I a4=a3-1;a4>0;a4--)for(I a5=a4;a5>0;a5--)for(I a6=a5;a6>0;a6--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2;a3<10;a3++)for(I a4=a3+1;a4<10;a4++)for(I a5=a4-1;a5>0;a5--)for(I a6=a5;a6>0;a6--)for(I a7=a6;a7>0;a7--)for(I a8=a7;a8>0;a8--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+cvl[7]*a7+cvl[8]*a8+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2;a3<10;a3++)for(I a4=a3;a4<10;a4++)for(I a5=a4+1;a5<10;a5++)for(I a6=a5-1;a6>0;a6--)for(I a7=a6;a7>0;a7--)for(I a8=a7;a8>0;a8--)for(I a9=a8;a9>0;a9--)for(I a10=a9;a10>0;a10--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+cvl[7]*a7+cvl[8]*a8+cvl[9]*a9+cvl[10]*a10+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2;a3<10;a3++)for(I a4=a3;a4<10;a4++)for(I a5=a4;a5<10;a5++)for(I a6=a5+1;a6<10;a6++)for(I a7=a6-1;a7>0;a7--)for(I a8=a7;a8>0;a8--)for(I a9=a8;a9>0;a9--)for(I a10=a9;a10>0;a10--)for(I a11=a10;a11>0;a11--)for(I a12=a11;a12>0;a12--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+cvl[7]*a7+cvl[8]*a8+cvl[9]*a9+cvl[10]*a10+cvl[11]*a11+cvl[12]*a12+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2;a3<10;a3++)for(I a4=a3;a4<10;a4++)for(I a5=a4;a5<10;a5++)for(I a6=a5;a6<10;a6++)for(I a7=a6+1;a7<10;a7++)for(I a8=a7-1;a8>0;a8--)for(I a9=a8;a9>0;a9--)for(I a10=a9;a10>0;a10--)for(I a11=a10;a11>0;a11--)for(I a12=a11;a12>0;a12--)for(I a13=a12;a13>0;a13--)for(I a14=a13;a14>0;a14--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+cvl[7]*a7+cvl[8]*a8+cvl[9]*a9+cvl[10]*a10+cvl[11]*a11+cvl[12]*a12+cvl[13]*a13+cvl[14]*a14+0);
for(I a0=1;a0<10;a0++)for(I a1=a0;a1<10;a1++)for(I a2=a1;a2<10;a2++)for(I a3=a2;a3<10;a3++)for(I a4=a3;a4<10;a4++)for(I a5=a4;a5<10;a5++)for(I a6=a5;a6<10;a6++)for(I a7=a6;a7<10;a7++)for(I a8=a7+1;a8<10;a8++)for(I a9=a8-1;a9>0;a9--)for(I a10=a9;a10>0;a10--)for(I a11=a10;a11>0;a11--)for(I a12=a11;a12>0;a12--)for(I a13=a12;a13>0;a13--)for(I a14=a13;a14>0;a14--)for(I a15=a14;a15>0;a15--)for(I a16=a15;a16>0;a16--)avl.add(cvl[0]*a0+cvl[1]*a1+cvl[2]*a2+cvl[3]*a3+cvl[4]*a4+cvl[5]*a5+cvl[6]*a6+cvl[7]*a7+cvl[8]*a8+cvl[9]*a9+cvl[10]*a10+cvl[11]*a11+cvl[12]*a12+cvl[13]*a13+cvl[14]*a14+cvl[15]*a15+cvl[16]*a16+0);

Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/
    in>>a;
	avvl=VVL(a,VL(3));
	for(b=0;b<a;b++)in>>avvl[b][0]>>avvl[b][1]>>avvl[b][2];
	for(b=0;b<a;b++)aset.insert(int(avvl[b][2]));
	bvl=VL(0); // Distinct Dudes Moduli In Order
	for(auto dude:aset){
		amii.insert({dude,sz(bvl)});
		bvl.add(dude);
	}
	bvvl=VVL(sz(bvl),VL(0));
	// Generate All Mountains In avl And Insert In To bvvl
	avl=VL(0);
	cvl=VL(17);
	cvl[0]=1;
	for(b=1;b<17;b++)cvl[b]=10*cvl[b-1];
	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d;e<10;e++)for(f=e;f<10;f++)for(g=f;g<10;g++)for(h=g;h<10;h++)for(i=h;i<10;i++)for(j=i+1;j<10;j++)for(k=j-1;k>0;k--)for(l=k;l>0;l--)for(m=l;m>0;m--)for(n=m;n>0;n--)for(o=n;o>0;o--)for(q=o;q>0;q--)for(r=q;r>0;r--)for(s=r;s>0;s--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h+cvl[7]*i+cvl[8]*j+cvl[9]*k+cvl[10]*l+cvl[11]*m+cvl[12]*n+cvl[13]*o+cvl[14]*q+cvl[15]*r+cvl[16]*s);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d;e<10;e++)for(f=e;f<10;f++)for(g=f;g<10;g++)for(h=g;h<10;h++)for(i=h+1;i<10;i++)for(j=i-1;j>0;j--)for(k=j;k>0;k--)for(l=k;l>0;l--)for(m=l;m>0;m--)for(n=m;n>0;n--)for(o=n;o>0;o--)for(q=o;q>0;q--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h+cvl[7]*i+cvl[8]*j+cvl[9]*k+cvl[10]*l+cvl[11]*m+cvl[12]*n+cvl[13]*o+cvl[14]*q);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d;e<10;e++)for(f=e;f<10;f++)for(g=f;g<10;g++)for(h=g+1;h<10;h++)for(i=h-1;i>0;i--)for(j=i;j>0;j--)for(k=j;k>0;k--)for(l=k;l>0;l--)for(m=l;m>0;m--)for(n=m;n>0;n--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h+cvl[7]*i+cvl[8]*j+cvl[9]*k+cvl[10]*l+cvl[11]*m+cvl[12]*n);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d;e<10;e++)for(f=e;f<10;f++)for(g=f+1;g<10;g++)for(h=g-1;h>0;h--)for(i=h;i>0;i--)for(j=i;j>0;j--)for(k=j;k>0;k--)for(l=k;l>0;l--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h+cvl[7]*i+cvl[8]*j+cvl[9]*k+cvl[10]*l);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d;e<10;e++)for(f=e+1;f<10;f++)for(g=f-1;g>0;g--)for(h=g;h>0;h--)for(i=h;i>0;i--)for(j=i;j>0;j--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h+cvl[7]*i+cvl[8]*j);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c;d<10;d++)for(e=d+1;e<10;e++)for(f=e-1;f>0;f--)for(g=f;g>0;g--)for(h=g;h>0;h--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f+cvl[5]*g+cvl[6]*h);

	for(b=1;b<10;b++)for(c=b;c<10;c++)for(d=c+1;d<10;d++)for(e=d-1;e>0;e--)for(f=e;f>0;f--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d+cvl[3]*e+cvl[4]*f);

	for(b=1;b<10;b++)for(c=b+1;c<10;c++)for(d=c-1;d>0;d--)avl.add(cvl[0]*b+cvl[1]*c+cvl[2]*d);

	for(b=1;b<10;b++)avl.add(cvl[0]*b);

	sortify(avl);
	//out<<sz(avl)<<nl; // For Timing
	for(auto dude:avl){
		for(b=0;b<sz(bvl);b++)if(dude%bvl[b]==0)bvvl[b].add(dude);
	}
	y=0;
	for(auto lolol:avvl){
		out<<"Case #"<<++y<<": ";
		out<<upperbound(all(bvvl[amii[lolol[2]]]),lolol[1])-lowerbound(all(bvvl[amii[lolol[2]]]),lolol[0])<<nl;
	}
}

I main(){zz();I a=1;while(a--){az();}}