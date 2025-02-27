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
const I p=998244353; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251 1000000000039 1000000000000000003

//--------------------------------------------------------------------

static I crand;
template<I M,class Y>
STR A{//Simon Lindholm
	I x;Y b;A(I x=0):x(x),b(x){}
	A(I x,Y b):x(x),b(b){}
	A operator+(A o){I y=x+o.x;return{y-(y>=M)*M,b+o.b};}
	A operator-(A o){I y=x-o.x; return{y+(y<0)*M,b-o.b};}
	A operator*(A o) {return{(I)(1LL*x*o.x%M),b*o.b};}
	explicit operator U(){return x^(U) b<<21;}
};
typedef A<1000000007,A<1000000009,unsigned>> H;
STR hashinterval{
	vector<H> ha,pw;
	hashinterval(S& str):ha(sz(str)+1),pw(ha){
		pw[0]=1;
		rep(i,0,sz(str))
			ha[i+1]=ha[i]*crand+str[i],
			pw[i+1]=pw[i]*crand;
	}
	H gethashinterval(I a,I b){ // [a,b]
		return ha[b+1]-ha[a]*pw[b+1-a];
	}
};
vector<H> gethashes(S& str,I length){
	if(sz(str)<length)return{};
	H h=0,pw=1;
	rep(i,0,length)
		h=h*crand+str[i],pw=pw*crand;
	vector<H> ret={h};
	rep(i,length,sz(str)){
		ret.push_back(h=h*crand+str[i]-pw*str[i-length]);
	}
	return ret;
}
H hashstring(S& as){H h{};for(C c:as)h=h*crand+c;return h;}

//--------------------------------------------------------------------

Z az(){
	VH avh=gethashes(as,sz(bs));
	H bh=hashstring(bs);
	for(a=0;a<sz(avh);a++){
		if(U(avh[a])==U(bh)){
			out<<a<<nl;
		}
	}
	hashinterval ahi(as);
	H ch=ahi.gethashinterval(1,3);
}

#include <sys/time.h>
I main(){
	timeval tp;gettimeofday(&tp,0);crand=(I)tp.tv_usec;assert((U)(H(1)*2+1-3)==0);
}

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
	Umm so by like the Pigeonhole Principle uh errrm I mean to be sure we only do need to check primes up to the maximum multiplicity of a letter maybe maybe if only we knew how to uh like bash I mean we can certainly hit the maximum multiplicity ugh I mean like maybe much easier instead of running through that to simply hash from like each substring to the precise locations where that substring occurs... then loop through and for each unique substring compute the maximal actual dude from that substring from Left To Right works I think AC.
	*/

	in>>as;
	MLV amlv;
	I ppp=307;

	// Oh I misread the task again Yikes OKOKOK oh OK so we do need to Dynamic Program I think but I think O[n^2*[maxprime~37]*] ugh ugh ugh OKOKOK not really that trivial per se but like certainly once we bash out lower cases it would seem to me that like fundamentally if we can oh I dunno count out the frequency multiplicity vector and then sort out cases like 4, 5, 7, 11, etc. etc. is like even for a dude like 11 say we would need every single dude to appear >= 11 times to hit like 22 at which point we have some subset of like uh errrm like the substring induced by precisely those say 5 6 7 relevant characters to see if we get 22 33 44 55 66 77 or whatever and it is at that point that like we might even be able to bash out 7^7 potential substrings or whatever in a simple Dynamic Program from there based around straight up Pigeonhole Princpled based casework after that point in time or whatever.

	av=V(26);
	for(auto dude:as)av[dude-'a']++;
	m=0;
	for(auto dude:av)if(dude>m)m=dude;
	bv={2,3,5,7,11,13,17,19,23,29,31,37};
	// So m has already been attained is like...
	for(a=0;a<sz(bv);a++){
		b=bv[a];
		// Ugh this is not AC I think what if we had like ugh some dude appears 40 times and some other dude 21 and it is a fundamental 2*21=42 maximum out but instead we have like ugh ugh ugh... OKOKOK maybe correct and patch that.
		avp=VP(0);
		for(c=0;c<26;c++)if(b*av[c]>m)avp.add(b,av[c]);
		// Then ugh I guess like process through this dude somehow but it could still involve like ugh say 4 so 5 so like 6 so like 24 dudes who each appeared like 3 times... the AAAABCDBCDBCDDEFDEFDEF...WXYWXYWXY case where we can not bash out all umm 2^24 if we not crack and ACcepted there is too high I think. 
	}
}

I main(){zz();I a=1;while(a--){az();}}