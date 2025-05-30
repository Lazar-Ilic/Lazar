// "We're living Ultralife" - Josephine Vander Gucht <3
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251 L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

// Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
// Time: O(log N)
STR SG{//Lucian Bicsi
	//0 1 inf -inf etc. for function coherence
	//static constexpr L unit = 0;
	//static constexpr L unit = 1;
	//static constexpr L unit = 1000000000000000001;
	static constexpr L unit = -1000000000000000001;
	L f(L a, L b){ // any associative function
		//return (a+b)%p;//unit 0
		//return a+b;//unit 0
		//return min(a,b);//unit 1000000000000000001
		return max(a,b);//unit -1000000000000000001
		//return (a bx b);//unit 0
		//return gcd(a,b);//unit 0
		//return lcm(a,b);//unit 0
	}
	VL s;L n;
	SG(L n=0,L def=unit):s(2*n,def),n(n){}
	Z update(L position,L value){
		for (s[position+=n]=value;position/=2;)
			s[position]=f(s[position*2],s[position*2+1]);
	}
	L query(L a,L b){ // query [a,b]
		b++;
		L left=unit,right=unit;
		for(a+=n,b+=n;a<b;a/=2,b/=2){
			if(a%2)left=f(left,s[a++]);
			if(b%2)right=f(s[--b],right);
		}
		return f(left,right);
	}
};

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
	https://codeforces.com/problemset/problem/598/E

	https://codeforces.com/blog/entry/14849


	So obviously the ugh k/a product term is like fixed and it does suffice to compute the uh maximum of the minimum of that value is I think it transforms in logarithm space into like a pretty trivial task relating to the ugh we need to induce yadda yadda blah blah so ugh I think the k <= 10^7 condition is super important here. Like somehow we can uh simply order the potential bumps up that is to say that we can ugh compute the optimal path moving from [b1,b2,...,bn]=[1,1,...,1] all the way up to ugh like [b1,b2,...,bn]=[a1,a2,...,an] and we need to compute that optimally maximal path along the way with each step being a ++ in 1 of the n-dimensional direction steps such that we are always at the maximum ugh which is like ugh a path of length like at most sum of ugh those dudes and then each step is a simple dimension check computation I think ugh O[100*100*blah sum] should be like pretty trivial I think. That is to say that we somehow need to store the ugh optimal frontier I think upon the curve like the best bang for buck or nearly optimal approximation algorithm here on that implicit n-dimensional curve of clearing that product ugh. It is like a convex hull search inside the discrete simplex I think. Ugh ugh ugh I mean transforming this into log space obviously is like we need the ugh sum of the relevant logs to be something and ugh in the Dynamic Program obviously the cost is like the ratio of the minimum cut in that dimension over the whole dimension length span ugh. Is like WLOG actually just the cost on that dude is like if we split into ugh it is like log(b1) value and the knapsack and need to clear the value on the implicit cost of like a factor multiplicatively uh additively of like ugh -log[floor[ai/bi]] I think ugh. So like still is it guaranteed to be ugh going up simply simply simply path searching ugh? I think we can like ugh sort on the dimensions actually and then maybe greedily snag value for some time ugh. I am not sure if I can ugh just simply snag value like loop through and snag value and leave out basically a simple subset selection task at the very end like find the minimal subset cost which clears something. Ugh I think note that like ugh optimally we can consider ilke the maximum bi cost value which induces the same uh floor[ai/bi] value in the transition. Still just seems like a relatively trivial ugh knapsack task frankly on the multiplicative nature of things. Perhaps in the transition it is like moving bi along can change that value by at most 1 each time at which point this is like a Dynamic Program ugh.

	Oh gee now it seems to me like ugh maybe the best way to do this task is to simply Dynamic Program bash ugh the adjacent dudes have ratio at most like ugh 2/1 or whatever is like bash up to the maximum is like O[n*2*k] dynamic program I think ugh until clearing it on each dude minimum cost to hit each dude maybe maybe after like a sieve to generate the prime factorisation of each dude up to like k should work. Ugh perhaps like an even more simple algorithm here would be like a like a ugh like a somehow we sort on size and like a generate a range minimum query segment tree or whatever.

	I have a feeling that this task is actually really trivial once we like set up the relevant values in ugh like O[n * k] time or whatever I think that like it reduces into a potential ugh like simple n-dimensional unimodal maximum query actually or like a unimodal minimum based around whatever whatever whatever and the actual leading in ugh n-1 values just initiate the search over the convex hull of those dudes and then like compute the cost function in loop as needed. That is to say that here we want to compute the unimodal maximum and like can intiate in the convex hull of I dunno even like set [b1,b2,...,bn-1] to be like [1,1,...,1] all the way up to ugh [a1,a2,...,an-1] and then induce ugh bn=ceil[k/product] actually. And then compute ugh. So I think that it like in this discrete setting suffices to compute like ugh store the ugh Bottom Left and Top Right corners metaphorically and then compute for each uh corner is obviously already breaking ugh because there are like 2^99 corners here potentially.
	*/

	in>>a>>b;
	av=V(a);
	for(c=0;c<a;c++)in>>av[c];
}

I main(){zz();I a=1;in>>a;while(a--){az();}}