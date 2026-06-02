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
	out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:


Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/
    avs=VS(6);
	for(a=0;a<6;a++)in>>avs[5-a];
	l=0;
	y=0; // Can C Win?
	z=0; // Can F Win?
	av={6,6,6,6,6,6,6};
	queue<V> aqv;
	SETV asetv;
	aqv.push(av);
	asetv.insert(av);
	while(!aqv.empty()){
		av=aqv.front();
		aqv.pop();
		w=0; // Did C Win?
		x=0; // Did F Win?
		for(h=0;h<7;h++)if(av[h]>=4){
			for(i=0;i<av[h]-3;i++){
				if(avs[i][h]==avs[i+1][h] and avs[i+1][h]==avs[i+2][h] and avs[i+2][h]==avs[i+3][h]){
					if(avs[i][h]=='C')w=1;
					else x=1;
				}
			}
		}
		for(h=0;h<4;h++)for(i=0;i<6;i++)if(av[h]>=i+1 and av[h+1]>=i+1 and av[h+2]>=i+1 and av[h+3]>=i+1 and avs[i][h]==avs[i][h+1] and avs[i][h+1]==avs[i][h+2] and avs[i][h+2]==avs[i][h+3]){
			if(avs[i][h]=='C')w=1;
			else x=1;
		}
		for(h=0;h<4;h++)for(i=0;i<3;i++)if(av[h]>=i+1 and av[h+1]>=i+2 and av[h+2]>=i+3 and av[h+3]>=i+4 and avs[i][h]==avs[i+1][h+1] and avs[i+1][h+1]==avs[i+2][h+2] and avs[i+2][h+2]==avs[i+3][h+3]){
			if(avs[i][h]=='C')w=1;
			else x=1;
		}
		for(h=3;h<7;h++)for(i=0;i<3;i++)if(av[h]>=i+1 and av[h-1]>=i+2 and av[h-2]>=i+3 and av[h-3]>=i+4 and avs[i][h]==avs[i+1][h-1] and avs[i+1][h-1]==avs[i+2][h-2] and avs[i+2][h-2]==avs[i+3][h-3]){
			if(avs[i][h]=='C')w=1;
			else x=1;
		}
		if(w==1 and x==0)y=1;
		else if(w==0 and x==1)z=1;
		else if(w==1 and x==1)l=1;
		s=0;
		for(auto dude:av)s+=dude;
		s%=2;
		for(h=0;h<7;h++)if((!s and av[h]>0 and avs[av[h]-1][h]=='F') or (s and av[h]>0 and avs[av[h]-1][h]=='C')){
			bv=av;
			bv[h]--;
			if(!asetv.count(bv)){
				asetv.insert(bv);
				aqv.push(bv);
			}
		}
	}
	if(y==1 and z==0)out<<"C"<<nl;
	else if(y==0 and z==1)out<<"F"<<nl;
	else if(l or (y==1 and z==1))out<<"?"<<nl;
	else out<<0<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

/*
Case #1: C
Case #2: ?
Case #3: F
Case #4: 0
Case #5: C
Case #6: F
Case #7: 0
Case #8: ?

1

C  FFFF
C  FCCF
C  FCFC
F  CCFF
F  CFCC
C  CFFC

Oh so we have to start at the final state and go in reverse ungh ugh ugh ugh yikes cringey...

Case #1: C
Case #2: ?
Case #3: F
Case #4: 0
Case #5: C
Case #6: F
Case #7: 0
Case #8: ?
Case #9: ?
Case #10: F
Case #11: ?
Case #12: F
Case #13: C
Case #14: C
Case #15: F
Case #16: F
Case #17: ?
Case #18: ?
Case #19: ?
Case #20: ?
Case #21: ?
Case #22: ?
Case #23: F
Case #24: C
Case #25: ?
Case #26: ?
Case #27: ?
Case #28: ?
Case #29: ?
Case #30: ?
Case #31: ?
Case #32: ?
Case #33: ?
Case #34: ?
Case #35: ?
Case #36: ?
Case #37: ?
Case #38: ?
Case #39: ?
Case #40: ?
Case #41: ?
Case #42: ?
Case #43: ?
Case #44: ?
Case #45: ?
Case #46: ?
Case #47: ?
Case #48: ?
Case #49: ?
Case #50: ?
Case #51: ?
Case #52: ?
Case #53: ?
Case #54: ?
Case #55: ?
Case #56: F
Case #57: C
Case #58: ?
Case #59: ?
Case #60: ?
Case #61: ?
Case #62: ?
Case #63: ?
Case #64: ?
Case #65: ?
Case #66: ?
Case #67: 0
Case #68: ?
Case #69: C
Case #70: C
Case #71: ?
Case #72: ?
Case #73: ?
Case #74: F
Case #75: ?
Case #76: C
Case #77: ?
Case #78: C
Case #79: ?
Case #80: C
Case #81: ?
Case #82: ?
Case #83: ?
Case #84: ?
Case #85: ?
Case #86: ?
Case #87: C
Case #88: C
Case #89: ?
Case #90: ?
Case #91: C
Case #92: ?
Case #93: ?
Case #94: C
Case #95: ?
Case #96: ?
Case #97: ?
Case #98: ?
Case #99: C
Case #100: ?
Case #101: ?
Case #102: ?
Case #103: ?
Case #104: ?
Case #105: ?
Case #106: ?
Case #107: ?
Case #108: ?
Case #109: ?
Case #110: F
Case #111: ?
Case #112: ?
Case #113: ?
Case #114: ?
Case #115: ?

Ugh and then it hits me the next morning as I am re reading solutions that one could flip the failed test cases vertically I think and so indeed for proof and logical soundness one indeed ought to go in both directions in the BFS to produce all the states which actually are part of a valid start to finish sequence and then check them. And also it is easier to immediately check the whole boaard for 0 status and then remove the l condition entirely. Well anyways seems like extremely weak test cases writing and shameful from Meta Hacker Cup essentially if this backwards algorithm did work in round because they should have forced ensured the logically valid tight thing I have since added in to my Algorithms notes here in general. Seems like because each state is obtained with 1 additional piece one can never move from the 0 winners state in to the both winners state and thus the l boolean is not necessary either.
*/