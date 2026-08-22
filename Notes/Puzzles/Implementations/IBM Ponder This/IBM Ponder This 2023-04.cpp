/*
https://math.stackexchange.com/questions/1052609/minimal-number-of-moves-needed-to-solve-a-lights-out-variant
https://people.math.umass.edu/~hajir/m499c/vardy-complexity.pdf
https://stackoverflow.com/questions/27436275/how-can-i-further-optimize-this-solver-of-a-variant-of-lights-out [ACcepted]
https://cran.r-project.org/web/packages/lightsout/lightsout.pdf
https://srabbani.com/lights_out.pdf
https://www.jaapsch.net/puzzles/lomath.htm
https://mathoverflow.net/questions/119352/randomly-switching-street-lights-in-a-square-city?_gl=1*1ngjrrg*_ga*MjAzNzQ4Nzg4LjE2ODAxMDA1NTA.*_ga_S812YQPLT2*MTY4MDEwMjY0OS4yLjEuMTY4MDEwNDU5MC4wLjAuMA..
https://math.stackexchange.com/questions/282342/board-game-10-by-10-light-bulbs-minimum-switches-to-get-all-off?rq=1
*/
/*
def solve(matrix):
	n=len(matrix)
	result = [0 for i in range(n) for j in range(n)]
	for i, j in product(range(n), repeat=2):
		if matrix[i][j]:
			for k in range(n):
				result[i*n + k] ^= 1
				result[k*n + j] ^= 1
			result[i*n + j] ^= 1
	return result
result=solve([
	[1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0],
	[0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0],
	[1,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,1],
	[1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1],
	[0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1],
	[0,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,1,0,1,0,1,1,1],
	[0,0,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0],
	[0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1],
	[1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,0],
	[1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1],
	[1,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,1],
	[0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,0],
	[1,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1],
	[1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0],
	[0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1],
	[1,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0],
	[0,0,0,1,1,0,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,0,0,1],
	[0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,1,0,1],
	[0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1],
	[0,1,0,1,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1],
	[0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,0],
	[0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0],
	[1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1],
	[0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0]
])
answer=[]
for i in range(24):
	for j in range(24):
		if result[24*i+j]==1:
			answer.append((j+1,24-i))
print(answer)
result=solve([[0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,0,1,1,1],
[1,0,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1],
[1,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1],
[0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,1,1,0],
[1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0,1],
[0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0],
[1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0],
[0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1],
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1],
[0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0],
[0,0,0,1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1],
[1,0,1,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0],
[1,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,1],
[1,0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0],
[0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,1],
[0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,1,0],
[0,0,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,0,1],
[0,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,0,1],
[1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,0,0],
[0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1],
[1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1],
[0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,0,1],
[0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,0],
[0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1],
[0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,0,0],
[1,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0],
[1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0],
[1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1,1,0,1],
[0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1]])
answer=[]
for i in range(30):
	for j in range(30):
		if result[30*i+j]==1:
			answer.append((j+1,30-i))
print(answer)
*/

// "We're living Ultralife" - Josephine Vander Gucht :) <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp 
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615]
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
using MSI=map<S,I>;
using MII=map<I,I>;
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
using PQ=priority_queue<I>;
using PQP=priority_queue<P>;
using PQPL=priority_queue<PL>;
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
const I p=1000000007; // 998244353 1000000007
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
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
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
	*/

	avv=VV(30,V(30));
	bvv=VV(30,V(30));
	bvv={{0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,0,1,1,1},
{1,0,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1},
{1,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1},
{0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,1,1,0},
{1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0,1},
{0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0},
{1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0},
{0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
{0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1},
{0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0},
{0,0,0,1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1},
{1,0,1,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0},
{1,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,1},
{1,0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0},
{0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,1},
{0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,1,0},
{0,0,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,0,1},
{0,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,0,1},
{1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,0,0},
{0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1},
{1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1},
{0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,0,1},
{0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1},
{0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,0,0},
{1,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0},
{1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0},
{1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1,1,0,1},
{0,0,1,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1}};
	for(a=0;a<429;a++){
		in>>c>>b;
		cvp.add({c,b});
	}
	while(sz(bvp)<429){
		avv=bvv;
		avp=cvp;
		bvp=VP(0);
		random_shuffle(avp.begin(),avp.end());
		for(a=0;a<sz(avp) and a<1000000;a++){
			c=avp[a].first;
			b=avp[a].second;
			c--;
			b=30-b;
			if(avv[b][c]==1){
				bvp.add({c+1,30-b});
				avv[b][c]=1-avv[b][c];
				for(d=0;d<30;d++)avv[b][d]=1-avv[b][d];
				for(d=0;d<30;d++)avv[d][c]=1-avv[d][c];
			}
			else avp.add({c+1,30-b}); // Would have been much stronger to loop through with an auxiliary vector simply initialised to say all 0s or all -1s and then produce the final indexing of the viable permutation as we go marking them off with their index as we process through cyclically rather than wasting a little bit of extra memory here.
		}
	}
	outvv(avv);
	out<<"[";
	for(auto dude:bvp)out<<"("<<dude.first<<","<<dude.second<<"),";
	out<<"]"<<nl;
}

I main(){zz();I a=1;while(a--){az();}}