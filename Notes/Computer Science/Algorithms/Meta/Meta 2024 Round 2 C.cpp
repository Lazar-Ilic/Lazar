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
using I=long long; // 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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

template <typename T> class BIT2D { // USACO Guide
  private:
	const int n, m;
	vector<vector<T>> bit;

  public:
	BIT2D(int n, int m) : n(n), m(m), bit(n + 1, vector<T>(m + 1)) {}

	/** adds val to the point (r, c) */
	void add(int r, int c, T val) {
		r++, c++;
		for (; r <= n; r += r & -r) {
			for (int i = c; i <= m; i += i & -i) { bit[r][i] += val; }
		}
	}

	/** @returns sum of points with row in [0, r] and column in [0, c] */
	T rect_sum(int r, int c) {
		r++, c++;
		T sum = 0;
		for (; r > 0; r -= r & -r) {
			for (int i = c; i > 0; i -= i & -i) { sum += bit[r][i]; }
		}
		return sum;
	}

	/** @returns sum of points with row in [r1, r2] and column in [c1, c2] */
	T rect_sum(int r1, int c1, int r2, int c2) {
		return rect_sum(r2, c2) - rect_sum(r2, c1 - 1) - rect_sum(r1 - 1, c2) +
		       rect_sum(r1 - 1, c1 - 1);
	}
};

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
"
My Clarifications

Bunny Hopscotch

Lazar Ilic
Would you all please note to Human Resources that I made an incredibly minor typo and missed a "-1" in defining r in my code otherwise would probably be ACcepted?
about a minute ago

Meta Hacker Cup
Hi Lazar Ilic,

We'll note it on your file.

Best,
The Meta Hacker Cup Team
"

So in any case it is interesting post contest to think through that classic case again ugh in round looks like I missed it but the way one would go about doing that for say >= 3200 burrows for 1 rabbit dude is like you actually just go through computing the prefix sums for each row in the same precise M*N grid after insertion and then again do the column sums down each column is like a more precise kind of a uh 3*M*N operations to essentially produce those sums of all dudes up and to the left of a coordinate. And then from there the canonical way to get a subgrid sum is to take the lower right corner's sum plus the upper left corner ----'s sum minus the lower left corner --'s sum minus the upper right --'s corner sum or whatever so 4 lookups to then generate the subgrid sum. So that is like a uh grand total of 3*M*N+4*Burrowsish algorithm rather than doing the other way is like uh 300*Burrowish maybe some other constant factors so like 3*800*800=300*Burrow would give 6400 or something ugh... so anyways anyways this is fast enough in round evidently.

OKOKOK further update here 2024-12-13 is that I could have should have would have tried edge cases by default might want to practise that habit more... so could have actually run 800x800 with all entries the same as well as 800x800 with all entries distinct and also probably done random and 0 1 cases as well maybe thought of worst cases.

Test+Additional Input:


[Worst-Case Runtime] Analysis:
Interesting task... immediately ideas come to brain like... maybe we can binary search for the threshold value for K which then reduces the task potentially in to some kind of O[log[800]*R*C] task where the critical usual key would be to count the number of dudes to the left of some columns right of whatever columns up down rows as well as the number of dudes to the up left down left up right down right of each point in The Matrix... is a precompute but we have to deal with a way to handle the different owners condition. Which might need a slick data structure or something. Alternately we could maybe just choose like a threshold here something like ugh... if there are less than like say 3200 of some owner we can do it manually or then we could split off in to some other dude and shnizz like... think that is aight frankly so we do it. And no wasting time here recreating full dudes multiple times so save time on that ugh... implementational details coming to brain here ugh... tick tock on the clock but the party do not stop no... yeah hungh yeah what yeah ugh ungh yeah now is my time yeah yeah what now is my time that be Maaly Raw yo look Love Always Shines yup yeah and what yungh Now Is My Time look Love Always Shines... Every Rhyme yungh yup and what yup Now Is My Time look Shoot A Rocket Up Now Time To Score The Touchdown... swerving in that Smart 42...
*/
    in>>a>>b>>c;
	avv=VV(a,V(b));
	BIT2D<L> bit(a,b);
	VVP avvp(a*b,VP(0));
	for(d=0;d<a;d++)for(e=0;e<b;e++){
		in>>avv[d][e];
		avvp[avv[d][e]-1].add({d,e});
	}
	l=1;
	r=max(a-1,b-1);
	// Find The Smallest Value Which Captures >=c Dudes In Range And Note -1 Each Time For Isolation Point
	while(l<r){
		m=(l+r)/2;
		L lol=0;
		for(d=0;d<a;d++)for(e=0;e<b;e++)bit.add(d,e,1);
		for(d=0;d<a;d++)for(e=0;e<b;e++)lol+=bit.rect_sum(max((long long)0,d-m),max((long long)0,e-m),min(a-1,d+m),min(b-1,e+m))-1;
		for(d=0;d<a;d++)for(e=0;e<b;e++)bit.add(d,e,-1);
		for(d=0;d<sz(avvp);d++)if(sz(avvp[d])>0){
			for(auto dude:avvp[d])bit.add(dude.first,dude.second,1);
			for(auto dude:avvp[d])lol-=bit.rect_sum(max((long long)0,dude.first-m),max((long long)0,dude.second-m),min(a-1,dude.first+m),min(b-1,dude.second+m))-1;
			for(auto dude:avvp[d])bit.add(dude.first,dude.second,-1);
		}
		if(lol<c)l=m+1;
		else r=m;
	}
	out<<l<<nl;
}

int main(){zz();I a=1;in>>a;while(a--){az();}}

/*
Case #1: 59
Case #2: 3
Case #3: 799
Case #4: 95
Case #5: 80
Case #6: 487
Case #7: 362
Case #8: 799
Case #9: 2
Case #10: 223
Case #11: 1
Case #12: 13
Case #13: 8
Case #14: 628
Case #15: 315
Case #16: 1
Case #17: 532
Case #18: 3
Case #19: 64
Case #20: 30
Case #21: 137
Case #22: 420
Case #23: 794
Case #24: 1
Case #25: 2
Case #26: 3
Case #27: 322
Case #28: 688
Case #29: 3
Case #30: 1
Case #31: 167
Case #32: 779
Case #33: 26
Case #34: 2
Case #35: 535
Case #36: 4
Case #37: 248
Case #38: 43
Case #39: 24
Case #40: 12
Case #41: 787
Case #42: 799
Case #43: 405
Case #44: 1
Case #45: 39
Case #46: 551
Case #47: 44
Case #48: 188
Case #49: 1
Case #50: 383

Case #1: 2
Case #2: 3
Case #3: 1
Case #4: 2
Case #5: 4
Case #6: 13
Case #7: 8
Case #8: 24
Case #9: 137
Case #10: 188
Case #11: 26
Case #12: 799
Case #13: 3
Case #14: 80
Case #15: 787
Case #16: 779
Case #17: 551
Case #18: 3
Case #19: 628
Case #20: 1
Case #21: 794
Case #22: 688
Case #23: 30
Case #24: 322
Case #25: 1
Case #26: 487
Case #27: 532
Case #28: 44
Case #29: 2
Case #30: 1
Case #31: 799
Case #32: 1
Case #33: 799
Case #34: 223
Case #35: 405
Case #36: 383
Case #37: 3
Case #38: 362
Case #39: 59
Case #40: 535
Case #41: 1
Case #42: 420
Case #43: 315
Case #44: 12
Case #45: 39
Case #46: 91
Case #47: 95
Case #48: 43
Case #49: 190
Case #50: 102
Case #51: 167
Case #52: 192
Case #53: 308
Case #54: 87
Case #55: 248
Case #56: 64
Case #57: 456
Case #58: 13
Case #59: 168
Case #60: 227
*/