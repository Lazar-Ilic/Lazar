// "We're living Ultralife" - Josephine Vander Gucht <3
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
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
const I p=998244353;// 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Could try going bottoms up and top down e.g. by seeing if we can obtain a score actually rather than bashing through all of the possible squares in sequence.

Test+Additional Input:

[Worst-Case Runtime] Analysis:

*/

	I minn=INT_MAX;
	I maxx=0;
	evv=VV(5,V(0));
	fvv=VV(5,V(0));
	for(z=0;z<=45;z++){
		out<<z<<nl;
		avv=VV(0,V(0));
		bvv=VV(0,V(0));
		cvv=VV(0,V(0));
		for(a=1;a<=9;a++)for(b=0;b<=9;b++)for(c=0;c<=9;c++)for(d=0;d<=9;d++)for(e=0;e<=9;e++)if(isprime(10000*a+1000*b+100*c+10*d+e) and a+b+c+d+e==z)avv.add({a,b,c,d,e});
		SETV asetv;
		for(auto dude:avv)asetv.insert(dude);
		//out<<sz(asetv)<<nl;
		for(a=1;a<=9;a++)for(b=1;b<=9;b++)for(c=1;c<=9;c++)for(d=1;d<=9;d++)for(e=1;e<=9;e++)if(isprime(10000*a+1000*b+100*c+10*d+e) and a+b+c+d+e==z)bvv.add({a,b,c,d,e});
		for(a=1;a<=9;a+=2)for(b=1;b<=9;b+=2)for(c=1;c<=9;c+=2)for(d=1;d<=9;d+=2)for(e=1;e<=9;e+=2)if(isprime(10000*a+1000*b+100*c+10*d+e) and a+b+c+d+e==z)cvv.add({a,b,c,d,e});
		//out<<sz(bvl)<<" "<<sz(cvl)<<nl;
		MPVV mpvv1,mpvv2,mpvv3,mpvv4,mpvv5;
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)mpvv1[{a,b}]=VV(0,V(0));
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)mpvv2[{a,b}]=VV(0,V(0));
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)mpvv3[{a,b}]=VV(0,V(0));
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)mpvv4[{a,b}]=VV(0,V(0));
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)mpvv5[{a,b}]=VV(0,V(0));
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)for(auto dude:bvv)if(dude[0]==a and dude[4]==b)mpvv1[{a,b}].add(dude);
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)for(auto dude:avv)if(dude[1]==a and dude[3]==b)mpvv2[{a,b}].add(dude);
		for(a=0;a<=9;a++)for(auto dude:avv)if(dude[2]==a)mpvv3[{a,a}].add(dude);
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)for(auto dude:avv)if(dude[3]==a and dude[1]==b)mpvv4[{a,b}].add(dude);
		for(a=0;a<=9;a++)for(b=0;b<=9;b++)for(auto dude:cvv)if(dude[4]==a and dude[0]==b)mpvv5[{a,b}].add(dude);
		//out<<sz(mpvv1)<<nl;
		out<<"Case Count: "<<sz(avv)*sz(avv)<<nl;
		y=0;
		for(V diag1:avv){
			for(V diag2:avv){
				y++;
				if(y%10000==0)out<<y<<nl;
				if(diag1[2]==diag2[2]){
					for(V row1:mpvv1[{diag1[0],diag2[0]}]){
						for(V row2:mpvv2[{diag1[1],diag2[1]}]){
							for(V row3:mpvv3[{diag1[2],diag2[2]}]){
								for(V row4:mpvv4[{diag1[3],diag2[3]}]){
									for(V row5:mpvv5[{diag1[4],diag2[4]}]){
										if(asetv.count({row1[0],row2[0],row3[0],row4[0],row5[0]}) and asetv.count({row1[1],row2[1],row3[1],row4[1],row5[1]}) and asetv.count({row1[2],row2[2],row3[2],row4[2],row5[2]}) and asetv.count({row1[3],row2[3],row3[3],row4[3],row5[3]}) and asetv.count({row1[4],row2[4],row3[4],row4[4],row5[4]})){
											// Evaluate Cost Of Valid Square
											SETV bsetv;
											bsetv.insert(diag1);
											bsetv.insert(diag2);
											bsetv.insert(row1);
											bsetv.insert(row2);
											bsetv.insert(row3);
											bsetv.insert(row4);
											bsetv.insert(row5);
											bsetv.insert(V{row1[0],row2[0],row3[0],row4[0],row5[0]});
											bsetv.insert(V{row1[1],row2[1],row3[1],row4[1],row5[1]});
											bsetv.insert(V{row1[2],row2[2],row3[2],row4[2],row5[2]});
											bsetv.insert(V{row1[3],row2[3],row3[3],row4[3],row5[3]});
											bsetv.insert(V{row1[4],row2[4],row3[4],row4[4],row5[4]});
											dv=V(10);
											for(V lol:bsetv)for(I val:lol)dv[val]++;
											I cost=0;
											for(auto mult:dv)cost+=mult*(mult-1)/2;
											if(cost<minn or cost==61){
												minn=cost;
												evv[0]=row1;
												evv[1]=row2;
												evv[2]=row3;
												evv[3]=row4;
												evv[4]=row5;
												out<<"minn "<<minn<<nl;
												outv(evv[0]);
												outv(evv[1]);
												outv(evv[2]);
												outv(evv[3]);
												outv(evv[4]);
											}
											if(cost>maxx or cost==488){
												maxx=cost;
												fvv[0]=row1;
												fvv[1]=row2;
												fvv[2]=row3;
												fvv[3]=row4;
												fvv[4]=row5;
												out<<"maxx "<<maxx<<nl;
												outv(fvv[0]);
												outv(fvv[1]);
												outv(fvv[2]);
												outv(fvv[3]);
												outv(fvv[4]);
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
	out<<minn<<nl;
	for(auto dude:evv)outv(dude);
	out<<maxx<<nl;
	for(auto dude:fvv)outv(dude);
}

I main(){zz();I a=1;while(a--){az();}}

/*
IBM Ponder This 2025-02 Lazar Ilic
Lazar Ilic
To ponder@il.ibm.com
Sun, Feb 2 at 11:27 AM

A=23
Minimum Score=61

2 8 4 6 3
8 9 0 5 1
4 0 7 3 9
6 5 3 2 7
3 1 9 7 3

A=17
Maximum Score=488

1 7 3 3 3
4 1 8 1 3
3 3 3 1 7
2 3 2 9 1
7 3 1 3 3

Lazar Ilic
To  ponder@il.ibm.com
 · 
Tue, Feb 4 at 11:19 AM
Message Body
I re ran my code for the N=5 case testing for all of the minima and maxima and found 1 more minimum instance at:

Sum=23
Score=61
2 8 6 4 3 
8 9 0 5 1 
6 0 7 3 7 
4 5 3 2 9 
3 1 7 9 3 

Just wanted this noted for our written records.

0
Case Count: 0
1
Case Count: 0
2
Case Count: 0
3
Case Count: 0
4
Case Count: 16
5
Case Count: 144
6
Case Count: 0
7
Case Count: 784
8
Case Count: 2025
9
Case Count: 0
10
Case Count: 9025
11
Case Count: 20449
minn 434
1 1 3 5 1 
3 3 2 0 3 
3 0 3 2 3 
1 4 0 3 3 
3 3 3 1 1 
maxx 434
1 1 3 5 1 
3 3 2 0 3 
3 0 3 2 3 
1 4 0 3 3 
3 3 3 1 1 
minn 159
1 1 3 5 1 
1 4 0 3 3 
3 0 3 2 3 
5 3 2 0 1 
1 3 3 1 3 
maxx 442
2 1 5 2 1 
5 0 4 1 1 
1 2 1 6 1 
2 7 0 1 1 
1 1 1 1 7 
10000
minn 103
5 1 1 3 1 
1 0 4 3 3 
1 4 3 0 3 
3 3 0 2 3 
1 3 3 3 1 
20000
12
Case Count: 0
13
Case Count: 55696
10000
20000
30000
40000
50000
14
Case Count: 73984
10000
20000
30000
40000
50000
60000
70000
15
Case Count: 0
16
Case Count: 168921
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
17
Case Count: 229441
minn 91
1 2 7 4 3 
2 1 8 5 1 
7 8 1 0 1 
4 5 0 5 3 
3 1 1 3 9 
minn 89
1 4 7 2 3 
4 1 6 5 1 
7 6 1 0 3 
2 5 0 7 3 
3 1 3 3 7 
maxx 488
1 7 3 3 3 
4 1 8 1 3 
3 3 3 1 7 
2 3 2 9 1 
7 3 1 3 3 
10000
20000
30000
40000
minn 73
2 4 6 2 3 
4 0 7 5 1 
6 7 1 0 3 
2 5 0 7 3 
3 1 3 3 7 
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
18
Case Count: 0
19
Case Count: 396900
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
20
Case Count: 440896
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
400000
410000
420000
430000
440000
21
Case Count: 0
22
Case Count: 550564
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
400000
410000
420000
430000
440000
450000
460000
470000
480000
490000
500000
510000
520000
530000
540000
550000
23
Case Count: 573049
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
minn 63
2 8 4 6 3 
8 7 2 5 1 
4 2 7 1 9 
6 5 1 4 7 
3 1 9 7 3 
130000
minn 61
2 8 4 6 3 
8 9 0 5 1 
4 0 7 3 9 
6 5 3 2 7 
3 1 9 7 3 
minn 61
2 8 6 4 3 
8 9 0 5 1 
6 0 7 3 7 
4 5 3 2 9 
3 1 7 9 3 
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
400000
410000
420000
430000
440000
450000
460000
470000
480000
490000
500000
510000
520000
530000
540000
550000
560000
570000
24
Case Count: 0
25
Case Count: 549081
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
400000
410000
420000
430000
440000
450000
460000
470000
480000
490000
500000
510000
520000
530000
540000
26
Case Count: 498436
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
340000
350000
360000
370000
380000
390000
400000
410000
420000
430000
440000
450000
460000
470000
480000
490000
27
Case Count: 0
28
Case Count: 336400
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
280000
290000
300000
310000
320000
330000
29
Case Count: 278784
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
150000
160000
170000
180000
190000
200000
210000
220000
230000
240000
250000
260000
270000
30
Case Count: 0
31
Case Count: 143641
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
120000
130000
140000
32
Case Count: 116281
10000
20000
30000
40000
50000
60000
70000
80000
90000
100000
110000
33
Case Count: 0
34
Case Count: 42025
10000
20000
30000
40000
35
Case Count: 27556
10000
20000
36
Case Count: 0
37
Case Count: 7056
38
Case Count: 3844
39
Case Count: 0
40
Case Count: 1156
41
Case Count: 169
42
Case Count: 0
43
Case Count: 16
44
Case Count: 4
45
Case Count: 0
61
2 8 6 4 3 
8 9 0 5 1 
6 0 7 3 7 
4 5 3 2 9 
3 1 7 9 3 
488
1 7 3 3 3 
4 1 8 1 3 
3 3 3 1 7 
2 3 2 9 1 
7 3 1 3 3 

maxx 1040
1 1 1 2 6 3 
2 4 1 4 2 1 
4 3 4 1 1 1 
1 1 1 3 1 7 
3 4 4 1 1 1 
3 1 3 3 3 1 

OK so here from printing those numerics it is pretty interesting uh... the most constrained by far is actually the right column and bottom row so... we want to constrain as fast as possible and uh reduce the number of cases dramatically there... can drop then the diag2 actually which satisfies and then uh... say case on the diag1 again and sharpen it up all around...
*/

// "We're living Ultralife" - Josephine Vander Gucht <3
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
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
const I p=998244353;// 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Could try going bottoms up and top down e.g. by seeing if we can obtain a score actually rather than bashing through all of the possible squares in sequence.

Test+Additional Input:

[Worst-Case Runtime] Analysis:

*/

	I minn=INT_MAX;
	I maxx=0;
	evv=VV(6,V(0));
	fvv=VV(6,V(0));
	for(z=27;z<=54;z++){
		out<<z<<nl;
		// avv=VV(0,V(0));
		// bvv=VV(0,V(0));
		// cvv=VV(0,V(0));
		// Perhaps Wiser To Store Each Type In A Vector Associated Also With Its First Digit
		// To Loop Through Cases On The Upper Left Corner Digit
		// Try Every Possible Top Row And Left Column And Diagonal
		avvv=VVV(10,VV(0,V(0)));
		bvvv=VVV(10,VV(0,V(0)));
		cvvv=VVV(10,VV(0,V(0)));
		for(a=1;a<=9;a++)for(b=0;b<=9;b++)for(c=0;c<=9;c++)for(d=0;d<=9;d++)for(e=0;e<=9;e++)for(f=0;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)avvv[a].add({a,b,c,d,e,f});
		SETV asetv;
		for(auto dude:avv)asetv.insert(dude);
		//out<<sz(asetv)<<nl;
		for(a=1;a<=9;a++)for(b=1;b<=9;b++)for(c=1;c<=9;c++)for(d=1;d<=9;d++)for(e=1;e<=9;e++)for(f=1;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)bvvv[a].add({a,b,c,d,e,f});
		for(a=1;a<=9;a+=2)for(b=1;b<=9;b+=2)for(c=1;c<=9;c+=2)for(d=1;d<=9;d+=2)for(e=1;e<=9;e+=2)for(f=1;f<=9;f+=2)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)cvvv[a].add({a,b,c,d,e,f});
		// Probably Faster Here To Generate All The Sets We Need In Like A VVVV Structure
		// Using The Relevant Digits Now Uh...
		// Want To Condition On The Other Diagonal I Think It Has 2 Set In Stone Now
		// And Then Deduce The Other Valid Dudes Through Their Own Things
		// And Then Try The Checker On Columns Or Whatever For Primality
		VVVV avvvvrightdiag=VVVV(10,VVV(10,VV(0,V(0))));
		for(VV lol1:avvv)for(V dude:lol1)avvvvrightdiag[dude[0]][dude[5]].add(dude);
		// Now Like Row 1 2 3 4 Have 4 Forced Elements
		// And Row 5 Has 2 Forced Elements And Must Be Bottom To Pass
		VVVVVV avvvvvvrow1=VVVVVV(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		VVVVVV avvvvvvrow2=VVVVVV(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		VVVVVV avvvvvvrow3=VVVVVV(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		VVVVVV avvvvvvrow4=VVVVVV(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		VVVV cvvvvrow5=VVVV(10,VVV(10,VV(0,V(0))));
		for(VV lol1:avvv)for(V dude:lol1)avvvvvvrow1[dude[0]][dude[1]][dude[4]][dude[5]].add(dude);
		for(VV lol1:avvv)for(V dude:lol1)avvvvvvrow2[dude[0]][dude[2]][dude[3]][dude[5]].add(dude);
		for(VV lol1:avvv)for(V dude:lol1)avvvvvvrow3[dude[0]][dude[2]][dude[3]][dude[5]].add(dude);
		for(VV lol1:avvv)for(V dude:lol1)avvvvvvrow4[dude[0]][dude[1]][dude[4]][dude[5]].add(dude);
		for(VV lol1:cvvv)for(V dude:lol1)cvvvvrow5[dude[0]][dude[5]].add(dude);
		for(I firstdigit=1;firstdigit<=9;firstdigit++){
			out<<sz(bvvv[firstdigit])*sz(bvvv[firstdigit])*sz(avvv[firstdigit])<<nl;
			for(V row0:bvvv[firstdigit]){
				for(V col0:bvvv[firstdigit]){
					for(V diag1:avvv[firstdigit]){
						for(V diag2:avvvvrightdiag[row0[5]][col0[5]]){
						for(V col5:cvvvvrow5[row0[5]][diag1[5]]){
							for(V row1:avvvvvvrow1[col0[1]][diag1[1]][diag2[1]][col5[1]]){
								for(V row2:avvvvvvrow2[col0[2]][diag1[2]][diag2[2]][col5[2]]){
									for(V row3:avvvvvvrow3[col0[3]][diag2[3]][diag1[3]][col5[3]]){
										for(V row4:avvvvvvrow4[col0[4]][diag2[4]][diag1[4]][col5[4]]){
											for(V row5:cvvvvrow5[col0[5]][diag1[5]]){
												if(asetv.count({row0[1],row1[1],row2[1],row3[1],row4[1],row5[1]}) and asetv.count({row0[2],row1[2],row2[2],row3[2],row4[2],row5[2]}) and asetv.count({row0[3],row1[3],row2[3],row3[3],row4[3],row5[3]}) and asetv.count({row0[4],row1[4],row2[4],row3[4],row4[4],row5[4]})){
												// OK Copy Paste Checker
												SETV bsetv;
												bsetv.insert(diag1);
												bsetv.insert(diag2);
												bsetv.insert(row0);
												bsetv.insert(row1);
												bsetv.insert(row2);
												bsetv.insert(row3);
												bsetv.insert(row4);
												bsetv.insert(row5);
												bsetv.insert(col0);
												bsetv.insert(col5);
												bsetv.insert(V{row0[1],row1[1],row2[1],row3[1],row4[1],row5[1]});
												bsetv.insert(V{row0[2],row1[2],row2[2],row3[2],row4[2],row5[2]});
												bsetv.insert(V{row0[3],row1[3],row2[3],row3[3],row4[3],row5[3]});
												bsetv.insert(V{row0[4],row1[4],row2[4],row3[4],row4[4],row5[4]});
												dv=V(10);
												for(V lol:bsetv)for(I val:lol)dv[val]++;
												I cost=0;
												for(auto mult:dv)cost+=mult*(mult-1)/2;
												if(cost<=minn){
													minn=cost;
													evv[0]=row0;
													evv[1]=row1;
													evv[2]=row2;
													evv[3]=row3;
													evv[4]=row4;
													evv[5]=row5;
													out<<"minn "<<minn<<nl;
													outv(evv[0]);
													outv(evv[1]);
													outv(evv[2]);
													outv(evv[3]);
													outv(evv[4]);
													outv(evv[5]);
												}
												if(cost>=maxx){
													maxx=cost;
													fvv[0]=row0;
													fvv[1]=row1;
													fvv[2]=row2;
													fvv[3]=row3;
													fvv[4]=row4;
													fvv[5]=row5;
													out<<"maxx "<<maxx<<nl;
													outv(fvv[0]);
													outv(fvv[1]);
													outv(fvv[2]);
													outv(fvv[3]);
													outv(fvv[4]);
													outv(fvv[5]);
												}
												}
											}
										}
									}
								}
							}
						}}
					}
				}
			}
		}
	}
	out<<minn<<nl;
	for(auto dude:evv)outv(dude);
	out<<maxx<<nl;
	for(auto dude:fvv)outv(dude);
}

I main(){zz();I a=1;while(a--){az();}}

/*
Another try:
*/

// "We're living Ultralife" - Josephine Vander Gucht <3
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
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
const I p=998244353;// 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Could try going bottoms up and top down e.g. by seeing if we can obtain a score actually rather than bashing through all of the possible squares in sequence.

Test+Additional Input:

[Worst-Case Runtime] Analysis:
The optimal strategy might be to drop the bottom row then the right column then the right diagonal then the seceond from bottom row then the second from right column then the third from bottom row then the third from right column then case on the top left digit and uh from there can probably case through the final 2 dudes somewhat sharply so as to avoid the checker...
*/

	I minn=INT_MAX;
	I maxx=0;
	evv=VV(6,V(0));
	fvv=VV(6,V(0));
	for(z=0;z<=54;z++){
		out<<z<<nl;
		avv=VV(0,V(0));
		bvv=VV(0,V(0));
		cvv=VV(0,V(0));
		for(a=1;a<=9;a++)for(b=0;b<=9;b++)for(c=0;c<=9;c++)for(d=0;d<=9;d++)for(e=0;e<=9;e++)for(f=0;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)avv.add({a,b,c,d,e,f});
		VVVVVVB avvvvvvb(10,VVVVVB(10,VVVVB(10,VVVB(10,VVB(10,VB(10,0))))));
		for(auto dude:avv)avvvvvvb[dude[0]][dude[1]][dude[2]][dude[3]][dude[4]][dude[5]]=1;
		for(a=1;a<=9;a++)for(b=1;b<=9;b++)for(c=1;c<=9;c++)for(d=1;d<=9;d++)for(e=1;e<=9;e++)for(f=1;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)bvv.add({a,b,c,d,e,f});
		for(a=1;a<=9;a+=2)for(b=1;b<=9;b+=2)for(c=1;c<=9;c+=2)for(d=1;d<=9;d+=2)for(e=1;e<=9;e+=2)for(f=1;f<=9;f+=2)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)cvv.add({a,b,c,d,e,f});
		VV row5v(0,V(0));
		for(V dude:cvv)row5v.add(dude);
		VVV col5v(10,VV(0,V(0)));
		for(V dude:cvv)col5v[dude[5]].add(dude);
		VVVV diag1v(10,VVV(10,VV(0,V(0))));
		for(V dude:avv)diag1v[dude[0]][dude[5]].add(dude);
		VVVV row4v(10,VVV(10,VV(0,V(0))));
		for(V dude:avv)row4v[dude[1]][dude[5]].add(dude);
		VVVVV col4v(10,VVVV(10,VVV(10,VV(0,V(0)))));
		for(V dude:avv)col4v[dude[1]][dude[4]][dude[5]].add(dude);
		VVVVV row3v(10,VVVV(10,VVV(10,VV(0,V(0)))));
		for(V dude:avv)row3v[dude[2]][dude[4]][dude[5]].add(dude);
		VVVVVV col3v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:avv)col3v[dude[2]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV row0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:bvv)row0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV col0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:bvv)col0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV diag0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:avv)diag0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		for(V row5:row5v){
			for(V col5:col5v[row5[5]]){
				for(V diag1:diag1v[col5[0]][row5[0]]){
					for(V row4:row4v[diag1[4]][col5[4]]){
						for(V col4:col4v[diag1[1]][row4[4]][row5[4]]){
							for(V row3:row3v[diag1[3]][col4[3]][col5[3]]){
								for(V col3:col3v[diag1[2]][row3[3]][row4[3]][row5[3]]){
									for(I aaa=1;aaa<=9;aaa++){
										for(V row0:row0v[aaa][col3[0]][col4[0]][col5[0]]){
											for(V col0:col0v[aaa][row3[0]][row4[0]][row5[0]]){
												for(V diag0:diag0v[aaa][row3[3]][row4[4]][row5[5]]){
													for(I aaa12=0;aaa12<=9;aaa12++){
														if(avvvvvvb[col0[1]][diag0[1]][aaa12][col3[1]][col4[1]][col5[1]] and avvvvvvb[row0[2]][aaa12][diag0[2]][row3[2]][row4[2]][row5[2]]){
															V row1={col0[1],diag0[1],aaa12,col3[1],col4[1],col5[1]};
															V col2={row0[2],aaa12,diag0[2],row3[2],row4[2],row5[2]};
															for(I aaa21=0;aaa21<=9;aaa21++){
																if(avvvvvvb[col0[2]][aaa21][diag0[2]][col3[2]][col4[2]][col5[2]] and avvvvvvb[row0[1]][diag0[1]][aaa21][row3[1]][row4[1]][row5[1]]){
																	V row2={col0[2],aaa21,diag0[2],col3[2],col4[2],col5[2]};
																	V col1={row0[1],diag0[1],aaa21,row3[1],row4[1],row5[1]};
																	// Check
												SETV bsetv;
												bsetv.insert(row0);
												bsetv.insert(row1);
												bsetv.insert(row2);
												bsetv.insert(row3);
												bsetv.insert(row4);
												bsetv.insert(row5);
												bsetv.insert(col0);
												bsetv.insert(col1);
												bsetv.insert(col2);
												bsetv.insert(col3);
												bsetv.insert(col4);
												bsetv.insert(col5);
												bsetv.insert(diag0);
												bsetv.insert(diag1);
												dv=V(10);
												for(V lol:bsetv)for(I val:lol)dv[val]++;
												I cost=0;
												for(auto mult:dv)cost+=mult*(mult-1)/2;
												if(cost<=minn){
													minn=cost;
													evv[0]=row0;
													evv[1]=row1;
													evv[2]=row2;
													evv[3]=row3;
													evv[4]=row4;
													evv[5]=row5;
													out<<"minn "<<minn<<nl;
													outv(evv[0]);
													outv(evv[1]);
													outv(evv[2]);
													outv(evv[3]);
													outv(evv[4]);
													outv(evv[5]);
												}
												if(cost>=maxx){
													maxx=cost;
													fvv[0]=row0;
													fvv[1]=row1;
													fvv[2]=row2;
													fvv[3]=row3;
													fvv[4]=row4;
													fvv[5]=row5;
													out<<"maxx "<<maxx<<nl;
													outv(fvv[0]);
													outv(fvv[1]);
													outv(fvv[2]);
													outv(fvv[3]);
													outv(fvv[4]);
													outv(fvv[5]);
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
		}
	}
	out<<minn<<nl;
	for(auto dude:evv)outv(dude);
	out<<maxx<<nl;
	for(auto dude:fvv)outv(dude);
}

I main(){zz();I a=1;while(a--){az();}}

/*
Perhaps there is a wiser way to filter by inserting a digit choice somewhere to divide out cases faster. If this one has too many inner loops halting at 0 points repeatedly it means we are not quite pruning nearly optimally enough from like an information theoretic standpoint. Say there was a problem where there are like 10^12 cases and uh 10^6 solutions of vectors of size 6 or whatever... if we can easily look up if some vector is a solution the optimal strategy is to simply search through 10^6 possible solutions and check rather than searching through 10^7 cases where a vast majority of our checkers will come back negative.
*/

/*
Next try up is try bottom row then right column then condition on top left digit value maybe to try the uh top row and left column...

5570 3714 436

OKOKOK so could try uh... bottom row followed by right column followed by case on top left is like uh... 500*100*10*100*100*100*... at which point we are pretty highly filtered...
*/

/*
Eh... might give up on this one eh or Google around a bit more maybe. Think about how to approach it more from the actual target score values or something.
*/

// "We're living Ultralife" - Josephine Vander Gucht <3
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
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MPD=map<P,D>;
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
const I p=998244353;// 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Could try going bottoms up and top down e.g. by seeing if we can obtain a score actually rather than bashing through all of the possible squares in sequence.

Test+Additional Input:

[Worst-Case Runtime] Analysis:
The optimal strategy might be to drop the bottom row then the right column then the right diagonal then the seceond from bottom row then the second from right column then the third from bottom row then the third from right column then case on the top left digit and uh from there can probably case through the final 2 dudes somewhat sharply so as to avoid the checker...
*/

	I minn=INT_MAX;
	I maxx=0;
	evv=VV(6,V(0));
	fvv=VV(6,V(0));
	for(z=28;z<=54;z++){
		out<<z<<nl;
		avv=VV(0,V(0));
		bvv=VV(0,V(0));
		cvv=VV(0,V(0));
		for(a=1;a<=9;a++)for(b=0;b<=9;b++)for(c=0;c<=9;c++)for(d=0;d<=9;d++)for(e=0;e<=9;e++)for(f=0;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)avv.add({a,b,c,d,e,f});
		VVVVVVB avvvvvvb(10,VVVVVB(10,VVVVB(10,VVVB(10,VVB(10,VB(10,0))))));
		for(auto dude:avv)avvvvvvb[dude[0]][dude[1]][dude[2]][dude[3]][dude[4]][dude[5]]=1;
		for(a=1;a<=9;a++)for(b=1;b<=9;b++)for(c=1;c<=9;c++)for(d=1;d<=9;d++)for(e=1;e<=9;e++)for(f=1;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)bvv.add({a,b,c,d,e,f});
		for(a=1;a<=9;a+=2)for(b=1;b<=9;b+=2)for(c=1;c<=9;c+=2)for(d=1;d<=9;d+=2)for(e=1;e<=9;e+=2)for(f=1;f<=9;f+=2)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)cvv.add({a,b,c,d,e,f});
		VV row5v(0,V(0));
		for(V dude:cvv)row5v.add(dude);
		VVV col5v(10,VV(0,V(0)));
		for(V dude:cvv)col5v[dude[5]].add(dude);
		VVVV diag1v(10,VVV(10,VV(0,V(0))));
		for(V dude:avv)diag1v[dude[0]][dude[5]].add(dude);
		VVVV row4v(10,VVV(10,VV(0,V(0))));
		for(V dude:avv)row4v[dude[1]][dude[5]].add(dude);
		VVVVV col4v(10,VVVV(10,VVV(10,VV(0,V(0)))));
		for(V dude:avv)col4v[dude[1]][dude[4]][dude[5]].add(dude);
		VVVVV row3v(10,VVVV(10,VVV(10,VV(0,V(0)))));
		for(V dude:avv)row3v[dude[2]][dude[4]][dude[5]].add(dude);
		VVVVVV col3v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:avv)col3v[dude[2]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV row0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:bvv)row0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV col0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:bvv)col0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		VVVVVV diag0v (10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		for(V dude:avv)diag0v[dude[0]][dude[3]][dude[4]][dude[5]].add(dude);
		w=0;
		out<<sz(row5v)<<nl;
		for(V row5:row5v){w++;out<<w<<nl;
			for(V col5:col5v[row5[5]]){
				for(V diag1:diag1v[col5[0]][row5[0]]){
					for(V row4:row4v[diag1[4]][col5[4]]){
						for(V col4:col4v[diag1[1]][row4[4]][row5[4]]){
							for(V row3:row3v[diag1[3]][col4[3]][col5[3]]){
								for(V col3:col3v[diag1[2]][row3[3]][row4[3]][row5[3]]){
									for(I aaa=1;aaa<=9;aaa++){
										if(sz(row0v[aaa][col3[0]][col4[0]][col5[0]]) and sz(col0v[aaa][row3[0]][row4[0]][row5[0]]) and sz(diag0v[aaa][row3[3]][row4[4]][row5[5]])){
										for(V row0:row0v[aaa][col3[0]][col4[0]][col5[0]]){
											for(V col0:col0v[aaa][row3[0]][row4[0]][row5[0]]){
												for(V diag0:diag0v[aaa][row3[3]][row4[4]][row5[5]]){
													for(I aaa12=0;aaa12<=9;aaa12++){
														if(avvvvvvb[col0[1]][diag0[1]][aaa12][col3[1]][col4[1]][col5[1]] and avvvvvvb[row0[2]][aaa12][diag0[2]][row3[2]][row4[2]][row5[2]]){
															V row1={col0[1],diag0[1],aaa12,col3[1],col4[1],col5[1]};
															V col2={row0[2],aaa12,diag0[2],row3[2],row4[2],row5[2]};
															for(I aaa21=0;aaa21<=9;aaa21++){
																if(avvvvvvb[col0[2]][aaa21][diag0[2]][col3[2]][col4[2]][col5[2]] and avvvvvvb[row0[1]][diag0[1]][aaa21][row3[1]][row4[1]][row5[1]]){
																	V row2={col0[2],aaa21,diag0[2],col3[2],col4[2],col5[2]};
																	V col1={row0[1],diag0[1],aaa21,row3[1],row4[1],row5[1]};
																	// Check
												SETV bsetv;
												bsetv.insert(row0);
												bsetv.insert(row1);
												bsetv.insert(row2);
												bsetv.insert(row3);
												bsetv.insert(row4);
												bsetv.insert(row5);
												bsetv.insert(col0);
												bsetv.insert(col1);
												bsetv.insert(col2);
												bsetv.insert(col3);
												bsetv.insert(col4);
												bsetv.insert(col5);
												bsetv.insert(diag0);
												bsetv.insert(diag1);
												dv=V(10);
												for(V lol:bsetv)for(I val:lol)dv[val]++;
												I cost=0;
												for(auto mult:dv)cost+=mult*(mult-1)/2;
												if(cost<=minn){
													minn=cost;
													evv[0]=row0;
													evv[1]=row1;
													evv[2]=row2;
													evv[3]=row3;
													evv[4]=row4;
													evv[5]=row5;
													out<<"minn "<<minn<<nl;
													outv(evv[0]);
													outv(evv[1]);
													outv(evv[2]);
													outv(evv[3]);
													outv(evv[4]);
													outv(evv[5]);
												}
												if(cost>=maxx){
													maxx=cost;
													fvv[0]=row0;
													fvv[1]=row1;
													fvv[2]=row2;
													fvv[3]=row3;
													fvv[4]=row4;
													fvv[5]=row5;
													out<<"maxx "<<maxx<<nl;
													outv(fvv[0]);
													outv(fvv[1]);
													outv(fvv[2]);
													outv(fvv[3]);
													outv(fvv[4]);
													outv(fvv[5]);
												}
																}
															}
														}
													}
												}
											}
										}
									}}
								}
							}
						}
					}
				}
			}
		}
	}
	out<<minn<<nl;
	for(auto dude:evv)outv(dude);
	out<<maxx<<nl;
	for(auto dude:fvv)outv(dude);
}

I main(){zz();I a=1;while(a--){az();}}

/*
Perhaps there is a wiser way to filter by inserting a digit choice somewhere to divide out cases faster. If this one has too many inner loops halting at 0 points repeatedly it means we are not quite pruning nearly optimally enough from like an information theoretic standpoint. Say there was a problem where there are like 10^12 cases and uh 10^6 solutions of vectors of size 6 or whatever... if we can easily look up if some vector is a solution the optimal strategy is to simply search through 10^6 possible solutions and check rather than searching through 10^7 cases where a vast majority of our checkers will come back negative.
*/

/*
Next try up is try bottom row then right column then condition on top left digit value maybe to try the uh top row and left column...

5570 3714 436

OKOKOK so could try uh... bottom row followed by right column followed by case on top left is like uh... 500*100*10*100*100*100*... at which point we are pretty highly filtered...
*/

// "We're living Ultralife" - Josephine Vander Gucht <3
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
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
const I p=998244353;// 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Could try going bottoms up and top down e.g. by seeing if we can obtain a score actually rather than bashing through all of the possible squares in sequence. Would be interesting to see if we could find a solution with say like 18 of a particular digit or even like say 15 or something and then restrict to only searching dudes who have say 16 or 14 or whatever follows as a bound not too tight not too loose here to still ensure the logical verification without trying too hard.

Test+Additional Input:

[Worst-Case Runtime] Analysis:

*/

	I minn=INT_MAX;
	evv=VV(6,V(0));
	for(z=0;z<=54;z++){
		out<<z<<nl;
		avv=VV(0,V(0));
		bvv=VV(0,V(0));
		cvv=VV(0,V(0));
		for(a=1;a<=9;a++)for(b=0;b<=9;b++)for(c=0;c<=9;c++)for(d=0;d<=9;d++)for(e=0;e<=9;e++)for(f=0;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)avv.add({a,b,c,d,e,f});
		VVVVVVB avvvvvvb(10,VVVVVB(10,VVVVB(10,VVVB(10,VVB(10,VB(10,0))))));
		for(auto dude:avv)avvvvvvb[dude[0]][dude[1]][dude[2]][dude[3]][dude[4]][dude[5]]=1;
		for(a=1;a<=9;a++)for(b=1;b<=9;b++)for(c=1;c<=9;c++)for(d=1;d<=9;d++)for(e=1;e<=9;e++)for(f=1;f<=9;f++)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)bvv.add({a,b,c,d,e,f});
		for(a=1;a<=9;a+=2)for(b=1;b<=9;b+=2)for(c=1;c<=9;c+=2)for(d=1;d<=9;d+=2)for(e=1;e<=9;e+=2)for(f=1;f<=9;f+=2)if(isprime(100000*a+10000*b+1000*c+100*d+10*e+f) and a+b+c+d+e+f==z)cvv.add({a,b,c,d,e,f});
		VVV avvv(10,VV(0,V(0)));
		VVVV avvvv(10,VVV(10,VV(0,V(0))));
		VVVVV avvvvv(10,VVVV(10,VVV(10,VV(0,V(0)))));
		VVVVVV avvvvvv(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0))))));
		VVVVVVV avvvvvvv(10,VVVVVV(10,VVVVV(10,VVVV(10,VVV(10,VV(0,V(0)))))));
		for(V dude:avv)avvv[dude[0]].add(dude);
		for(V dude:avv)avvvv[dude[0]][dude[1]].add(dude);
		for(V dude:avv)avvvvv[dude[0]][dude[1]][dude[2]].add(dude);
		for(V dude:avv)avvvvvv[dude[0]][dude[1]][dude[2]][dude[3]].add(dude);
		for(V dude:avv)avvvvvvv[dude[0]][dude[1]][dude[2]][dude[3]][dude[4]].add(dude);
		for(V diag0:avv){
			//outv(diag0);
			for(V row0:avvv[diag0[0]]){
				for(V row1:avvvv[row0[1]][diag0[1]]){
					for(V row2:avvvvv[row0[2]][row1[2]][diag0[2]]){
						for(i=0;i<=9;i++){
						if(avvvvvvb[i][row1[4]][row2[3]][row2[3]][row1[4]][row0[5]] and avvvvvvb[row0[0]][row0[1]][row0[2]][row0[3]][row0[4]][i]){
							V diag1={i,row1[4],row2[3],row2[3],row1[4],row0[5]};
							V row6={row0[0],row0[1],row0[2],row0[3],row0[4],i};
							for(V row3:avvvvvv[row0[3]][row1[3]][row2[3]][diag0[3]]){
								for(V row4:avvvvvvv[row0[4]][row1[4]][row2[4]][row3[4]][diag0[4]]){
									if(avvvvvvb[row0[5]][row1[5]][row2[5]][row3[5]][row4[5]][diag0[5]] and avvvvvvb[i][row1[5]][row2[5]][row3[5]][row4[5]][diag0[5]]){
												V row5={row0[5],row1[5],row2[5],row3[5],row4[5],diag0[5]};
												V col6={i,row1[5],row2[5],row3[5],row4[5],row5[5]};
												SETV bsetv;
												bsetv.insert(diag0);
												bsetv.insert(diag1);
												bsetv.insert(row0);
												bsetv.insert(row1);
												bsetv.insert(row2);
												bsetv.insert(row3);
												bsetv.insert(row4);
												bsetv.insert(row5);
												bsetv.insert(row6);
												bsetv.insert(col6);
												dv=V(10);
												for(V lol:bsetv)for(I val:lol)dv[val]++;
												I cost=0;
												for(auto mult:dv)cost+=mult*(mult-1)/2;
												if(cost<=minn){
													minn=cost;
													evv[0]=row0;
													evv[1]=row1;
													evv[2]=row2;
													evv[3]=row3;
													evv[4]=row4;
													evv[5]=row5;
													out<<"minn "<<minn<<nl;
													outv(evv[0]);
													outv(evv[1]);
													outv(evv[2]);
													outv(evv[3]);
													outv(evv[4]);
													outv(evv[5]);
												}
									}
								}
							}
						}}
					}
				}
			}
		}
	}
	out<<minn<<nl;
	for(auto dude:evv)outv(dude);
}

I main(){zz();I a=1;while(a--){az();}}

/*
Eh might never crack this one whatever I have more important research to pursue right now. Sum changes and so on and so on ugh egh would imagine under 100 is possible.
*/