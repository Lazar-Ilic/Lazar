//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using U=uint64_t;
using LD=long double;
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
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETP=set<P>;
using SETSETP=set<SETP>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
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
using PQ=priority_queue<I>;
using PQP=priority_queue<P>;
using PQPL=priority_queue<PL>;
using VB=vector<B>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
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
using VPID=vector<PID>;
using VVB=vector<VB>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VSET=vector<SET>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using SETSETV=set<SETV>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
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
#define nextpermutation next_permutation
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsetsize __builtin_popcount
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a) ((a).begin()),((a).end())
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
const I p=1000000007; // 998244353 1000000007 1000000000
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
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;

/*
https://research.ibm.com/haifa/ponderthis/challenges/September2021.html

A story: the September 2021 IBM Research Ponder This of puzzle composer and editor Dr. Gadi Aleksandrowicz. The task was to manipulate a string and produce another string under some constraints such that the "distance" between the 2 strings was under a threshold. Immediately I thought of some canonical results in strings manipulation and in the direction of generalised Hamming distance notions. However, I was not able to alter any of these extant ideas in a meaningful way.

It struck me a couple weeks later that I had missed a true underlying structure. This led to multiple insights, which came one after the other. Firstly, that one might be able to restrict to patterns of the form 0ABC and consider the task as a minimisation of sums of distances in Z3 under the taxicab metric. Secondly, that one can ignore certain input of 1s (fixed cost) to improve performance by significantly reducing the size of this region in Z3 from a 9x9x9 lattice cube to an 8x8x8 lattice cube. Thirdly, that one can, via trial and error, ignore input in order to induce a highly clustered (under this notion/metric of clusteredness) point set in Z3 upon which to execute a 15 dimensional gradient descent to compute the centers of the clusters and produce the target performance rather rapidly. This incurs a low constant term in a first phase to improve performance in a second phase. It was for me one of those tasks which I did not "on sight". Rather, I pondered in the background and had epiphanies! This simpler case, executing this dimensional reduction, imposing a more constraining condition on the used strings, transforms this into an easier task.
*/

	as="31415926535897932384626433832795288497693993755829749445923786462862899862834825342767982488653282366479384469555822372535948284874528427938525559644622948954933896";
	hs="314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
	for(a=0;a<sz(as);a++){
		if(as[a]=='2'){
			av.add(a);
		}
	}
	z=1;
	for(a=0;a<sz(av) and z;a++){
		for(b=a+1;b<sz(av) and z;b++){
			for(c=b+1;c<sz(av) and z;c++){
				bs=as;
				bs.erase(bs.begin()+av[c]);
				bs.erase(bs.begin()+av[b]);
				bs.erase(bs.begin()+av[a]);
				y=0;
				while(y<100000 and z){
					if(y%1000==0){
						m=500;
						w=1;
						while(w){
							cs="";
							w=0;
							for(d=0;d<15;d++){
								cs+=C('0'+rand()%10);
							}
							for(d=0;d<5;d++){
								if(cs[3*d]==cs[3*d+1] or cs[3*d]==cs[3*d+2] or cs[3*d+1]==cs[3*d+2])w=1;
							}
						}
					}
					ds="";
					n=500;
					for(d=0;d<15;d++){
						es=cs;
						if(es[d]!='9' and 1!=es[3*(d/3)+0]-es[d] and 1!=es[3*(d/3)+1]-es[d] and 1!=es[3*(d/3)+2]-es[d]){
							es[d]=C(1+es[d]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					for(d=0;d<15;d++){
						es=cs;
						if(es[d]!='9' and es[d]!='8' and 2!=es[3*(d/3)+0]-es[d] and 2!=es[3*(d/3)+1]-es[d] and 2!=es[3*(d/3)+2]-es[d]){
							es[d]=C(2+es[d]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					for(d=0;d<15;d++){
						es=cs;
						if(es[d]!='0' and -1!=es[3*(d/3)+0]-es[d] and -1!=es[3*(d/3)+1]-es[d] and -1!=es[3*(d/3)+2]-es[d]){
							es[d]=C(0-1+es[d]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					for(d=0;d<15;d++){
						es=cs;
						if(es[d]!='0' and es[d]!='1' and -2!=es[3*(d/3)+0]-es[d] and -2!=es[3*(d/3)+1]-es[d] and -2!=es[3*(d/3)+2]-es[d]){
							es[d]=C(0-2+es[d]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					for(d=0;d<15;d++){
						es=cs;
						if(d%3!=2){
							swap(es[d],es[d+1]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					for(d=0;d<15;d++){
						es=cs;
						if(d%3==0){
							swap(es[d],es[d+2]);
							o=26;
							for(e=0;e<sz(bs);e+=3){
								q=500;
								for(f=0;f<5;f++){
									if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
										q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									}
								}
								o+=q;
							}
							if(o<n){
								n=o;
								ds=es;
							}
						}
					}
					y++;
					if(n<=175){
						z=0;
						y=100000;
						fs="";
						es=ds;
						o=26;
						for(e=0;e<sz(bs);e+=3){
							q=500;
							for(f=0;f<5;f++){				
								if(abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2])<q){
									q=abs(bs[e]-es[3*f])+abs(bs[e+1]-es[3*f+1])+abs(bs[e+2]-es[3*f+2]);
									gs="";
									gs+=es[3*f];
									gs+=es[3*f+1];
									gs+=es[3*f+2];
								}
							}
							fs+=gs;
							o+=q;
						}
						for(e=sz(bs)-3;e>=0;e-=3){
							bs.insert(bs.begin()+e,'-');
							fs.insert(fs.begin()+e,'0');
						}
						f=0;
						for(e=0;e<sz(hs);e++){
							if(bs[f]=='-'){
								f++;
								e--;
							}
							else if(hs[e]==bs[f]){
								f++;
							}
							else{
								bs.insert(bs.begin()+f,hs[e]);
								fs.insert(fs.begin()+f,'-');
								f++;
							}
						}
						out<<"[";
						for(e=0;e<5;e++){
							out<<"\"0"<<ds[3*e]<<ds[3*e+1]<<ds[3*e+2]<<"\"";
							if(e<4)out<<",";
						}
						out<<"]"<<nl;
						out<<bs<<nl;
						out<<fs<<nl;
					}
					if(n>=m){
						y=y+1000-y%1000;
					}
					m=n;
					cs=ds;
				}
			}
		}
	}
}

I main(){zz();I a=1;while(a--){az();}}