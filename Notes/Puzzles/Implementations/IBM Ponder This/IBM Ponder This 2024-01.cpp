// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

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
//const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
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


[Worst-Case Runtime] Analysis:

*/

	// Could try a modification of permutationspruned.cpp for faster runtime. avb rather than long and != statements also could be a speedup here.
	z=0;
	avv=VV(0,V(0));
	for(a=1;a<=16;a++){
		for(b=1;b<=16;b++){
			if(b!=a){
				for(c=1;c<=16;c++){
					if(c!=b and c!=a){
						d=a+b-c-5;
						if(d>=1 and d<=16 and d!=c and d!=b and d!=a){
							for(e=1;e<=16;e++){
								if(e!=d and e!=c and e!=b and e!=a){
									for(f=1;f<=16;f++){
										if(f!=e and f!=d and f!=c and f!=b and f!=a){
											for(g=1;g<=16;g++){
												if(g!=f and g!=e and g!=d and g!=c and g!=b and g!=a){
													h=e+f+g-10;
													if(h>=1 and h<=16 and h!=g and h!=f and h!=e and h!=d and h!=c and h!=b and h!=a){
														for(i=1;i<=16;i++){
															if(i!=h and i!=g and i!=f and i!=e and i!=d and i!=c and i!=b and i!=a){
																for(j=1;j<=16;j++){
																	if(j!=i and j!=h and j!=g and j!=f and j!=e and j!=d and j!=c and j!=b and j!=a){
																		for(k=1;k<=16;k++){
																			if(k!=j and k!=i and k!=h and k!=g and k!=f and k!=e and k!=d and k!=c and k!=b and k!=a){
																				l=9-i+j-k;
																				m=a+e+i-17;
																				n=b+f-j-8;
																				o=11-c+g+k;
																				p=48-d-h-l;
																				if(m-n+o-p==0 and l>=1 and l<=16 and m>=1 and m<=16 and n>=1 and n<=16 and o>=1 and o<=16 and p>=1 and p<=16 and l!=k and l!=j and l!=i and l!=h and l!=g and l!=f and l!=e and l!=d and l!=c and l!=b and l!=a and m!=l and m!=k and m!=j and m!=i and m!=h and m!=g and m!=f and m!=e and m!=d and m!=c and m!=b and m!=a and n!=m and n!=l and n!=k and n!=j and n!=i and n!=h and n!=g and n!=f and n!=e and n!=d and n!=c and n!=b and n!=a and o!=n and o!=m and o!=l and o!=k and o!=j and o!=i and o!=h and o!=g and o!=f and o!=e and o!=d and o!=c and o!=b and o!=a and p!=o and p!=n and p!=m and p!=l and p!=k and p!=j and p!=i and p!=h and p!=g and p!=f and p!=e and p!=d and p!=c and p!=b and p!=a){
																					z++;
																					out<<a<<" "<<b<<" "<<c<<" "<<d<<nl<<e<<" "<<f<<" "<<g<<" "<<h<<nl<<i<<" "<<j<<" "<<k<<" "<<l<<nl<<m<<" "<<n<<" "<<o<<" "<<p<<nl<<nl;
																					avv.add({a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p});
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
			}
		}
	}
	out<<z<<nl; // 84 [2, 14, 4, 7, 12, 8, 5, 15, 9, 11, 1, 10, 6, 3, 13, 16]
	y=(1<<0)+(1<<3)+(1<<4)+(1<<7)+(1<<8)+(1<<10)+(1<<12)+(1<<13)+(1<<15)+(1<<20)+(1<<21)+(1<<22)+(1<<23);
	for(a=0;a<sz(avv);a++){
		for(b=a+1;b<sz(avv);b++){
			x=1;
			for(c=0;c<16 and x;c++)if(avv[a][c]==avv[b][c])x=0;
			if(x){
				for(c=0;c<(1<<24);c++){
					if(subsetsize(c bx y)>=12){
						w=1;
						for(d=0;d<4 and w;d++)if(avv[a][4*d]-avv[a][4*d+1]+2*((c ba (1<<(3*d)))!=0)*avv[a][4*d+1]-avv[a][4*d+2]+2*((c ba (1<<(3*d+1)))!=0)*avv[a][4*d+2]-avv[a][4*d+3]+2*((c ba (1<<(3*d+2)))!=0)*avv[a][4*d+3]!=avv[b][4*d]-avv[b][4*d+1]+2*((c ba (1<<(3*d)))!=0)*avv[b][4*d+1]-avv[b][4*d+2]+2*((c ba (1<<(3*d+1)))!=0)*avv[b][4*d+2]-avv[b][4*d+3]+2*((c ba (1<<(3*d+2)))!=0)*avv[b][4*d+3])w=0;
						for(d=0;d<4 and w;d++)if(avv[a][d]-avv[a][4+d]+2*((c ba (1<<(12+3*d)))!=0)*avv[a][4+d]-avv[a][8+d]+2*((c ba (1<<(12+3*d+1)))!=0)*avv[a][8+d]-avv[a][12+d]+2*((c ba (1<<(12+3*d+2)))!=0)*avv[a][12+d]!=avv[b][d]-avv[b][4+d]+2*((c ba (1<<(12+3*d)))!=0)*avv[b][4+d]-avv[b][8+d]+2*((c ba (1<<(12+3*d+1)))!=0)*avv[b][8+d]-avv[b][12+d]+2*((c ba (1<<(12+3*d+2)))!=0)*avv[b][12+d])w=0;
						if(w){
							outv(avv[a]);
							outv(avv[b]);
							out<<c<<nl;
						}
					}
				}
			}
		}
	}
	/*
8 13 5 11 10 14 1 15 3 12 2 16 4 7 9 6 
12 8 9 6 14 10 2 16 4 7 1 11 13 3 5 15 
16659180
13 12 6 14 5 9 4 8 1 10 7 11 2 3 16 15 
14 8 2 15 4 16 1 11 5 9 3 10 6 7 13 12 
4511962
15 10 8 12 13 7 1 11 3 5 2 9 14 4 6 16 
16 12 9 14 10 6 2 8 4 7 1 11 13 3 5 15 
15348420
15 10 8 12 13 7 1 11 3 5 2 9 14 4 6 16 
16 12 9 14 10 6 2 8 4 7 1 11 13 3 5 15 
15349956
15 10 8 12 13 7 1 11 3 5 2 9 14 4 6 16 
16 12 9 14 10 6 2 8 4 7 1 11 13 3 5 15 
16659140
15 10 8 12 13 7 1 11 3 5 2 9 14 4 6 16 
16 12 9 14 10 6 2 8 4 7 1 11 13 3 5 15 
16660676
8 13 5 11 10 14 1 15 3 12 2 16 4 7 9 6 
12 8 9 6 14 10 2 16 4 7 1 11 13 3 5 15 
16659180
001101110100110001111111
001 101 110 100
110 001 111 111
08 13 05 11 10 14 01 15 03 12 02 16 04 07 09 06
12 08 09 06 14 10 02 16 04 07 01 11 13 03 05 15

08-13-05+11 = 1
+  -  +  +
10+14-01+15 = 38
+  -  +  +
03+12+02-16 = 1
-  +  +  +
04+07-09-06 = -4
17 -6 17 48
...

12-08-09+06 = 1
+  -  +  +
14+10-02+16 = 38
+  -  +  +
04+07+01-11 = 1
-  +  +  +
13+03-05-15 = -4
17 -6 17 48

[8, 13, 5, 11, 10, 14, 1, 15, 3, 12, 2, 16, 4, 7, 9, 6]
[12, 8, 9, 6, 14, 10, 2, 16, 4, 7, 1, 11, 13, 3, 5, 15]
[-,-,+,+,-,+,+,+,-,+,+,-,+,+,+,+,-,-,+,+,+,+,-,-]
	*/
}

I main(){zz();I a=1;while(a--){az();}}