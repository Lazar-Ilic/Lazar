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
using VVVV=vector<VVV>;
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


Test + Additional Input:


Analysis:

*/

	//in>>a;
	// Can vectorise the 5 away. And reduce compute time on t. Ensure maximum 1 add by only snagging cheeses on the move in. For later transition function we will need to edit thise one somehow ugh. Perhaps some variant on a minimum cost maximum flow instance uh with nodes and uh time stamps maximum flow uh time stamped uh. Should work I think maximise flow out of each node to be 1. I ought to have onsighted that solution ab initio but this is simpler for the first case.
	k=30;
	n=100;
	al=1103515245;
	cl=12345;
	ml=(1L<<31);
	VVVV avvvv(k+2,VVV(k+2,VV(k+2,V(n+1,0))));
	for(e=0;e<n/2 and avvvv[1][1][1][1]==0;e++)if(((al*(1*1*1+e)+cl)%ml)%n==1)avvvv[1][1][1][1]++;
	for(a=2;a<=n;a++){
		for(b=1;b<=k;b++){
			for(c=1;c<=k;c++){
				for(d=1;d<=k;d++){
					if(b+c+d<=a+2){
						f=max(avvvv[b-1][c][d][a-1],max(avvvv[b][c-1][d][a-1],avvvv[b][c][d-1][a-1])); // Edit later for other transition.
						if(f>=avvvv[b][c][d][a-1]){
							avvvv[b][c][d][a]=f;
							for(e=0;e<n/2 and avvvv[b][c][d][a]==f;e++)if(((al*(b*c*d+e)+cl)%ml)%n==a)avvvv[b][c][d][a]++;
						}
						else avvvv[b][c][d][a]=avvvv[b][c][d][a-1];
					}
				}
			}
		}
	}
	m=0;
	e=0;
	f=0;
	g=0;
	for(b=1;b<=k;b++)for(c=1;c<=k;c++)for(d=1;d<=k;d++)if(avvvv[b][c][d][n]>m){
		m=avvvv[b][c][d][n];
		e=b;
		f=c;
		g=d;
	}
	//out<<m<<nl;
	as="";
	for(a=n;a>=2;a--){
		// Transitioning from e,f,g back to 1,1,1...
		out<<a<<" "<<e<<" "<<f<<" "<<g<<" "<<avvvv[e][f][g][a]<<nl;
		y=0;
		for(h=0;h<n/2 and y==0;h++)if(((al*(e*f*g+h)+cl)%ml)%n==a)y=1;
		if(avvvv[e][f][g][a]==avvvv[e][f][g][a-1])as+="W";
		else if(e>=2 and ((y and avvvv[e][f][g][a]==avvvv[e-1][f][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e-1][f][g][a-1])){
			as+="R";
			e--;
		}
		else if(f>=2 and ((y and avvvv[e][f][g][a]==avvvv[e][f-1][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f-1][g][a-1])){
			as+="U";
			f--;
		}
		else if(g>=2 and ((y and avvvv[e][f][g][a]==avvvv[e][f][g-1][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f][g-1][a-1])){
			as+="F";
			g--;
		}
	}
	reverse(all(as));
	out<<as<<nl;

	k=50;
	n=200;
	al=1103515245;
	cl=12345;
	ml=(1L<<31);
	avvvv=VVVV(k+2,VVV(k+2,VV(k+2,V(n+1,0))));
	for(e=0;e<n/2 and avvvv[1][1][1][1]==0;e++)if(((al*(1*1*1+e)+cl)%ml)%n==1)avvvv[1][1][1][1]++;
	for(a=2;a<=n;a++){
		for(b=1;b<=k;b++){
			for(c=1;c<=k;c++){
				for(d=1;d<=k;d++){
					if(b+c+d<=a+2){
						f=max(max(avvvv[b-1][c][d][a-1],max(avvvv[b][c-1][d][a-1],avvvv[b][c][d-1][a-1])),max(avvvv[b+1][c][d][a-1],max(avvvv[b][c+1][d][a-1],avvvv[b][c][d+1][a-1])));
						if(f>=avvvv[b][c][d][a-1]){
							avvvv[b][c][d][a]=f;
							for(e=0;e<n/2 and avvvv[b][c][d][a]==f;e++)if(((al*(b*c*d+e)+cl)%ml)%n==a)avvvv[b][c][d][a]++;
						}
						else{
							avvvv[b][c][d][a]=avvvv[b][c][d][a-1];
							for(e=0;e<n/2 and avvvv[b][c][d][a]==avvvv[b][c][d][a-1];e++)if(((al*(b*c*d+e)+cl)%ml)%n==a)avvvv[b][c][d][a]++;
						}
					}
				}
			}
		}
	}
	m=0;
	e=0;
	f=0;
	g=0;
	for(b=1;b<=k;b++)for(c=1;c<=k;c++)for(d=1;d<=k;d++)if(avvvv[b][c][d][n]>m){
		m=avvvv[b][c][d][n];
		e=b;
		f=c;
		g=d;
	}
	//out<<m<<nl;
	as="";
	for(a=n;a>=2;a--){
		// Transitioning from e,f,g back to 1,1,1...
		out<<a<<" "<<e<<" "<<f<<" "<<g<<" "<<avvvv[e][f][g][a]<<nl;
		y=0;
		for(h=0;h<n/2 and y==0;h++)if(((al*(e*f*g+h)+cl)%ml)%n==a)y=1;
		if(avvvv[e][f][g][a]==avvvv[e][f][g][a-1] or (y and avvvv[e][f][g][a]==avvvv[e][f][g][a-1]+1))as+="W";
		else if(e>=2 and ((y and avvvv[e][f][g][a]==avvvv[e-1][f][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e-1][f][g][a-1])){
			as+="R";
			e--;
		}
		else if(f>=2 and ((y and avvvv[e][f][g][a]==avvvv[e][f-1][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f-1][g][a-1])){
			as+="U";
			f--;
		}
		else if(g>=2 and ((y and avvvv[e][f][g][a]==avvvv[e][f][g-1][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f][g-1][a-1])){
			as+="F";
			g--;
		}
		else if(e<=k-1 and ((y and avvvv[e][f][g][a]==avvvv[e+1][f][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e+1][f][g][a-1])){
			as+="L";
			e++;
		}
		else if(f<=k-1 and ((y and avvvv[e][f][g][a]==avvvv[e][f+1][g][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f+1][g][a-1])){
			as+="D";
			f++;
		}
		else if(g<=k-1 and ((y and avvvv[e][f][g][a]==avvvv[e][f][g+1][a-1]+1) or avvvv[e][f][g][a]==avvvv[e][f][g+1][a-1])){
			as+="B";
			g++;
		}
	}
	reverse(all(as));
	out<<as<<nl;
}

I main(){zz();I a=1;while(a--){az();}}