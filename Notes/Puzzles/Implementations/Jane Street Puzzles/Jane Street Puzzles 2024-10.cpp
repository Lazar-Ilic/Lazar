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
const I p=1000000007; // 998244353 1000000007
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
Think one ought to simply go from the target back to the source but also there ought to be a strong pre pruning step where one discerns uh basically ignoring the position which possible sequences of values even can generate the target value again that part could be done from target to source and then we ignore dudes along the way which are not valid by using a hash set or whatever.

Test+Additional Input:


[Worst-Case Runtime] Analysis:
Could also consider instead of looping through from 0 to 1<<36 here instead doing that ~36 times and checking that subsetsizeL(BLAH)==j in an if statement inside the loop and also maybe if we did not want to use swap memory here could basically erase out all the irrelevant subsets in lol already covered like once we wrap up generating size 3 in to say lol2 we can say lol=lol2 each iteration of that loop and then max out on like a uh [36 choose 18]<<2^36 there on memory. But we do want to print out the solutions and here this might be fast enough to eventually generate the true optimum here for the Jane Street Puzzles task and provably so minimise that sum of A+B+C. We can almost certainly find a way to uniquify the relevant vector once in a while... at a nearly optimal frequency... and also filter out all irrelevant scores immediately by first precomputing all possible relevant scores in a DP Dynamic Programme.
*/
	av={0,0,0,1,1,2,0,0,0,1,1,2,0,0,1,1,2,2,0,0,1,1,2,2,0,1,1,2,2,2,0,1,1,2,2,2};
	avv=VV(36,V(36,0)); // O[1] lookup if we needed or wanted it.
	bvv=VV(36,V(0)); // Neighbours
	for(a=0;a<6;a++){
		for(b=0;b<6;b++){
			for(c=0;c<6;c++){
				for(d=0;d<6;d++){
					if((abs(a-c)==1 and abs(b-d)==2) or (abs(a-c)==2 and abs(b-d)==1)){
						avv[6*a+b][6*c+d]=1;
						avv[6*c+d][6*a+b]=1;
						bvv[6*a+b].add(6*c+d);
						bvv[6*c+d].add(6*a+b);
					}
				}
			}
		}
	}
	for(n=6;n<=50;n++){
	for(a=1;a<=50;a++){
		for(b=1;b<=50;b++){
			for(c=1;c<=50;c++){
				if(a!=b and b!=c and c!=a and 2024%c==0 and a+b+c==n){ // Unique forced.
					out<<a<<" "<<b<<" "<<c<<nl;
					x=1; // Unsolved A1 to F6
					y=1; // Unsolved A6 to F1
					bv={a,b,c};
					unordered_map<L,VP> lol; // Can optimise using the L mixed with location int quite easily by adding that location int multiplied by (1<<36) and adding... then the search ought to waste quite a lot less time and also we should actually make that SETP in to a simple vector of vectors for O[1] lookup there.
					lol.insert({1,{{0,a}}});
					for(m=2;m<=36;m++){
					for(al=2;al<((long long)1<<36) and x;al++){
						if(al%1000000000==0)out<<m<<" "<<al<<nl;
						if(subsetsizeL(al)==m){
						// Check from this subset backwards and ensure knight move condition and scoring to <=2024.
						for(d=0;d<36;d++){
							if((al ba ((long long)1<<d)) and lol.count(al bx ((long long)1<<d))){
								for(auto dude:lol[al bx ((long long)1<<d)]){
									if(avv[d][dude.first] and ((av[d]==av[dude.first] and dude.second+bv[av[d]]<=2024) or (av[d]!=av[dude.first] and dude.second*bv[av[d]]<=2024))){
										if(lol.count(al)){
											if(av[d]==av[dude.first]){
												lol[al].push_back({d,dude.second+bv[av[d]]});
												w=dude.second+bv[av[d]];
											}
											else{
												lol[al].push_back({d,dude.second*bv[av[d]]});
												w=dude.second*bv[av[d]];
											}
										}
										else{
											if(av[d]==av[dude.first]){
												lol.insert({al,{{d,dude.second+bv[av[d]]}}});
												w=dude.second+bv[av[d]];
											}
											else{
												lol.insert({al,{{d,dude.second*bv[av[d]]}}});
												w=dude.second*bv[av[d]];
											}
										}
										if(d==35 and w==2024){
											x=0;
											bl=al;
											dl=35;
											el=2024;
											while(bl!=1){
												out<<char(dl%6+'a')<<1+dl/6<<" "<<dl<<" "<<el<<nl;
												bl=(bl bx ((long long)1<<dl));
												v=1;
												for(auto neighbour:bvv[dl]){
													if(v and (bl ba ((long long)1<<neighbour)) and lol.count(bl bx ((long long)1<<neighbour))){
														for(auto dudedude:lol[bl]){
															if(v and av[dl]==av[neighbour] and dudedude.first==neighbour and dudedude.second==el-bv[av[dl]]){
																v=0;
																el=el-bv[av[dl]];
																dl=neighbour;
															}
															else if(v and av[dl]!=av[neighbour] and dudedude.first==neighbour and dudedude.second*bv[av[dl]]==el){
																v=0;
																el=el/bv[av[dl]];
																dl=neighbour;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}}
					}}
					if(x==0){
						lol.clear();
						lol.insert({1<<30,{{30,a}}});
						for(m=2;m<=36;m++){
						for(al=0;al<((long long)1<<36) and y;al++){
							// Check from this subset backwards and ensure knight move condition and scoring to <=2024.
							if(al%1000000000==0)out<<m<<" "<<al<<nl;
							if(subsetsizeL(al)==m){
							for(d=0;d<36;d++){
								if((al ba ((long long)1<<d)) and lol.count(al bx ((long long)1<<d))){
									for(auto dude:lol[al bx ((long long)1<<d)]){
										if(avv[d][dude.first] and ((av[d]==av[dude.first] and dude.second+bv[av[d]]<=2024) or (av[d]!=av[dude.first] and dude.second*bv[av[d]]<=2024))){
											if(lol.count(al)){
												if(av[d]==av[dude.first]){
													lol[al].push_back({d,dude.second+bv[av[d]]});
													w=dude.second+bv[av[d]];
												}
												else{
													lol[al].push_back({d,dude.second*bv[av[d]]});
													w=dude.second*bv[av[d]];
												}
											}
											else{
												if(av[d]==av[dude.first]){
													lol.insert({al,{{d,dude.second+bv[av[d]]}}});
													w=dude.second+bv[av[d]];
												}
												else{
													lol.insert({al,{{d,dude.second*bv[av[d]]}}});
													w=dude.second*bv[av[d]];
												}
											}
											if(d==5 and w==2024){
												y=0;
												cl=al;
												dl=5;
												el=2024;
												while(cl!=(1<<30)){
													out<<char(dl%6+'a')<<1+dl/6<<" "<<dl<<" "<<el<<nl;
													cl=(cl bx ((long long)1<<dl));
													v=1;
													for(auto neighbour:bvv[dl]){
														if(v and (cl ba ((long long)1<<neighbour)) and lol.count(cl bx ((long long)1<<neighbour))){
															for(auto dudedude:lol[cl]){
																if(v and av[dl]==av[neighbour] and dudedude.first==neighbour and dudedude.second==el-bv[av[dl]]){
																	v=0;
																	el=el-bv[av[dl]];
																	dl=neighbour;
																}
																else if(v and av[dl]!=av[neighbour] and dudedude.first==neighbour and dudedude.second*bv[av[dl]]==el){
																	v=0;
																	el=el/bv[av[dl]];
																	dl=neighbour;
																}
															}
														}
													}
												}
												return;
											}
										}
									}
								}
							}}
						}
					}}
				}
			}
		}
	}}
}

I main(){zz();I a=1;while(a--){az();}}

/*

%%writefile a.cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<long long,vector<pair<int,int>>> lol;
    cout<<lol.max_size()<<endl;
}

----------

230584300921369395

----------

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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------



I testcase=0;
Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,w,x,y,z;
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


	av={0,0,0,1,1,2,0,0,0,1,1,2,0,0,1,1,2,2,0,0,1,1,2,2,0,1,1,2,2,2,0,1,1,2,2,2};
	avv=VV(36,V(36,0)); // O[1] lookup if we needed or wanted it.
	bvv=VV(36,V(0)); // Neighbours
	for(a=0;a<6;a++){
		for(b=0;b<6;b++){
			for(c=0;c<6;c++){
				for(d=0;d<6;d++){
					if((abs(a-c)==1 and abs(b-d)==2) or (abs(a-c)==2 and abs(b-d)==1)){
						avv[6*a+b][6*c+d]=1;
						avv[6*c+d][6*a+b]=1;
						bvv[6*a+b].add(6*c+d);
						bvv[6*c+d].add(6*a+b);
					}
				}
			}
		}
	}
	for(a=1;a<=3;a++){
		for(b=1;b<=3;b++){
			for(c=1;c<=3;c++){
				if(a!=b and b!=c and c!=a){ // Unique forced. Can forces !(a<=3 and b<=3 and c<=3) later and keep bumping up as desired or even code in an a+b+c<= constraint similarly to finish with relative rapidity in relation to the Jane Street Puzzles latency clearance.
					out<<a<<" "<<b<<" "<<c<<nl;
					x=1; // Unsolved A1 to F6
					y=1; // Unsolved A6 to F1
					bv={a,b,c};
					unordered_map<L,V> lol; // Can optimise using the L mixed with location int quite easily by adding that location int multiplied by (1<<36) and adding... then the search ought to waste quite a lot less time and also we should actually make that SETP in to a simple vector of vectors for O[1] lookup there.
					//aset.clear();
					//aset.insert(a);
					lol.insert({1,{a}});
					for(al=2;al<((long long)1<<36) and x;al++){
						if(al%1000000==0)out<<al<<nl;
						// Check from this subset backwards and scoring to <=2024.
						for(d=0;d<36;d++){
							if((al ba ((long long)1<<d))){
								for(auto neighbour:bvv[d]){
									if(lol.count((al bx ((long long)1<<d))+neighbour*((long long)1<<36))){
										for(auto score:lol[(al bx ((long long)1<<d))+neighbour*((long long)1<<36)]){
											if(av[neighbour]==av[d])w=score+bv[av[d]];
											else w=score*bv[av[d]];
											if(w<=2024 and lol.count(al+d*((long long)1<<36)))lol[al+d*((long long)1<<36)].add(w);
											else if(w<=2024){
												//aset.clear();
												//aset.insert(w);
												lol.insert({al+d*((long long)1<<36),{w}});
											}
											if(d==35 and w==2024){
												x=0;
												bl=al+d*((long long)1<<36);
												el=2024;
												while(bl!=1){
													out<<bl/((long long)1<<36)<<" "<<el<<nl;
													e=1;
													for(auto neighbourr:bvv[bl/((long long)1<<36)]){
														if(e and av[bl/((long long)1<<36)]==av[neighbourr] and lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end()!=find(lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].begin(),lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end(),el-bv[av[bl/((long long)1<<36)]])){
															e=0;
															el=el-bv[av[bl/((long long)1<<36)]];
															bl=((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36);
														}
														else if(e and av[bl/((long long)1<<36)]!=av[neighbourr] and lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end()!=find(lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].begin(),lol[((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end(),el/bv[av[bl/((long long)1<<36)]])){
															e=0;
															el=el/bv[av[bl/((long long)1<<36)]];
															bl=((bl-(bl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(bl/((long long)1<<36))))+neighbourr*((long long)1<<36);
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
					if(x==0){
						lol.clear();
						//aset.clear();
						//aset.insert(a);
						lol.insert({30*((long long)1<<36)+(1<<30),{a}});
						for(al=0;al<((long long)1<<36) and y;al++){
							if(al%100000000==0)out<<al<<nl;
							// Check from this subset backwards and scoring to <=2024.
							for(d=0;d<36;d++){
								if((al ba ((long long)1<<d))){
									for(auto neighbour:bvv[d]){
										if(lol.count((al bx ((long long)1<<d))+neighbour*((long long)1<<36))){
											for(auto score:lol[(al bx ((long long)1<<d))+neighbour*((long long)1<<36)]){
												if(av[neighbour]==av[d])w=score+bv[av[d]];
												else w=score*bv[av[d]];
												if(w<=2024 and lol.count(al+d*((long long)1<<36)))lol[al+d*((long long)1<<36)].add(w);
												else if(w<=2024){
													//aset.clear();
													//aset.insert(w);
													lol.insert({al+d*((long long)1<<36),{w}});
												}
												if(d==5 and w==2024){
													y=0;
													cl=al+d*((long long)1<<36);
													fl=2024;
													while(cl!=1){
														out<<cl/((long long)1<<36)<<" "<<fl<<nl;
														e=1;
														for(auto neighbourr:bvv[cl/((long long)1<<36)]){
															if(e and av[cl/((long long)1<<36)]==av[neighbourr] and lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end()!=find(lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].begin(),lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end(),fl-bv[av[cl/((long long)1<<36)]])){
																e=0;
																fl=fl-bv[av[cl/((long long)1<<36)]];
																cl=((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36);
															}
															else if(e and av[cl/((long long)1<<36)]!=av[neighbourr] and lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end()!=find(lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].begin(),lol[((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36)].end(),fl/bv[av[cl/((long long)1<<36)]])){
																e=0;
																fl=fl/bv[av[cl/((long long)1<<36)]];
																cl=((cl-(cl/((long long)1<<36))*((long long)1<<36)) bx ((long long)1<<(cl/((long long)1<<36))))+neighbourr*((long long)1<<36);
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
						if(y==0){
							out<<a<<" "<<b<<" "<<c<<" "<<bl<<" "<<cl<<nl;
						}
					}
				}
			}
		}
	}
}

I main(){zz();I a=1;while(a--){az();}}
*/