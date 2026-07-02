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
	So we need for [a+b]/ab to clear in to like k but for example uh maybe uh maybe like a uh casework on uh the actual prime factorisation of k can uh like work here in conjunction perhaps with like a uh the uh factorisation of each potential ab case maybe value and its factorisation decompositions. So for uh like each uh prime firstly note that uh 3 7 10 6 7 does not appear in the OEIS Online Encyclopaedia Of Integer Sequences so uh like. So uh in any case the maximum thus far could be worth trying out in a uh another file um to see if there is any interesting pattern there um. So uh the formula here obviously is just like the k value resulting is just like a*b/gcd[a*b,a+b] which should be super duper wooper to like easily implement uh maybe try that for the first umm like 10000x10000 even works.
	*/

	/*
	av=V(1001);
	for(a=1;a<=10000;a++){
		for(b=a;b<=10000;b++){
			if(a*b/gcd(a*b,a+b)<=1000){av[a*b/gcd(a*b,a+b)]++;
			out<<a<<" "<<b<<" "<<a*b/gcd(a*b,a+b)<<nl;}
		}
	}
	*/

	/*
	av=V(1001);
	for(a=1;a<=40000;a++){
		for(b=a;b<=40000;b++){
			if(a*b/gcd(a*b,a+b)<=1000){
				for(c=a*b/gcd(a*b,a+b);c<=1000;c+=a*b/gcd(a*b,a+b))av[c]++;
			}
		}
	}
	//outv(av);
	m=0;
	for(a=1;a<=1000;a++){
		if(av[a]>m){
			m=av[a];
			out<<a<<" "<<m<<nl;
		}
	}
	*/

/*

login
The OEIS is supported by the many generous donors to the OEIS Foundation.
 

Logo
3 4 6 8 10 12 18 20 24 30 36
 		Hints
(Greetings from The On-Line Encyclopedia of Integer Sequences!)
Search: seq:3,4,6,8,10,12,18,20,24,30,36
Displaying 1-4 of 4 results found.	page 1
     Sort: relevance | references | number | modified | created      Format: long | short | data
A067128		Ramanujan's largely composite numbers, defined to be numbers m such that d(n) >= d(k) for k = 1 to m-1.		+30
36
1, 2, 3, 4, 6, 8, 10, 12, 18, 20, 24, 30, 36, 48, 60, 72, 84, 90, 96, 108, 120, 168, 180, 240, 336, 360, 420, 480, 504, 540, 600, 630, 660, 672, 720, 840, 1080, 1260, 1440, 1680, 2160, 2520, 3360, 3780, 3960, 4200, 4320, 4620, 4680, 5040, 7560, 9240 (list; graph; refs; listen; history; text; internal format)
OFFSET	
1,2

COMMENTS	
This sequence is a subsequence of A034287; are they identical? They match for m up to 1500000.

Identical to A034287 for the 105834 terms less than 10^150.

Every subsequence of terms, having the fixed greatest prime divisor prime(k), k=1,2,..., is finite. For a proof see A273015. The list of these subsequences begins {2,4,8}, {3,6,12,18,24,36,48,72,96,108}, ... - Vladimir Shevelev, May 13 2016

By a result of Erdős (1944), a(n+1) <= 2*a(n): see Erdős link.

LINKS	
T. D. Noe, Table of n, a(n) for n = 1..10000

P. Erdős, On Highly composite numbers, J. London Math. Soc. 19 (1944), 130--133 MR7,145d; Zentralblatt 61,79.

Jean-Louis Nicolas, Répartition des nombres largement composés, Acta Arithmetica 34 (1979), 379-390.

J.-L. Nicolas and G. Robin, Highly Composite Numbers by Srinivasa Ramanujan, The Ramanujan Journal, Vol. 1(2), pp. 119-153, Kluwer Academics Pub.

Vladimir Shevelev, On Erdős constant, arXiv:1605.08884 [math.NT], 2016.

EXAMPLE	
8 is a term as d(8) = 4 and d(k) <= 4 for k = 1,...,7.

MATHEMATICA	
For[n=1; max=0, True, n++, If[(d=DivisorSigma[0, n])>=max, Print[n]; max=d]]

NestList[Function[last,

  NestWhile[# + 1 &, last + 1,

   DivisorSigma[0, #] < DivisorSigma[0, last] &]], 1, 70] (* Steven Lu, Nov 28 2022 *)

PROG	
(PARI) is(n) = my(nd=numdiv(n)); for(k=1, n-1, if(numdiv(k) > nd, return(0))); return(1) \\ Felix Fröhlich, May 22 2016

CROSSREFS	
For n with strictly increasing number of divisors, see A002182; A272314, A273011 (infinitary analog), subsequences A273015, A273016, A273018.

Number of divisors of a(n): A273353.

KEYWORD	
easy,nonn

AUTHOR	
Amarnath Murthy, Jan 09 2002

EXTENSIONS	
Edited by Dean Hickerson, Jan 15 2002 and by T. D. Noe, Nov 07 2002

STATUS	
approved

A034287		Numbers whose product of divisors is larger than that of any smaller number.		+30
13
1, 2, 3, 4, 6, 8, 10, 12, 18, 20, 24, 30, 36, 48, 60, 72, 84, 90, 96, 108, 120, 168, 180, 240, 336, 360, 420, 480, 504, 540, 600, 630, 660, 672, 720, 840, 1080, 1260, 1440, 1680, 2160, 2520, 3360, 3780, 3960, 4200, 4320, 4620, 4680, 5040, 7560, 9240 (list; graph; refs; listen; history; text; internal format)
OFFSET	
1,2

COMMENTS	
It appears that 2 and 3 are the only terms in this sequence that are not in A034288. - T. D. Noe, Mar 10 2007

Is this the same as A067128?

a(n) = numbers m where record values occur in A007955(m); A007955(m) = product of divisors of m. a(n) = possible values of A174901(m) in increasing order, a(n) = the smallest numbers k such that A007955(k) = A174899(n). - Jaroslav Krizek, Apr 01 2010

Equals A067128 for the 105834 terms less than 10^150.

LINKS	
Amiram Eldar, Table of n, a(n) for n = 1..230 (terms below 10^10, terms 1..161 from T. D. Noe)

MATHEMATICA	
divProd[n_] := Times @@ Divisors[n]; a[1] = 1; a[n_] := a[n] = Catch[For[dp = divProd[an = a[n - 1]]; an++, True, an++, If[divProd[an] > dp, Throw[an]]]]; Table[a[n], {n, 1, 52}] (* Jean-François Alcover, Feb 01 2013 *)

PROG	
(PARI) A007955(n)=if(issquare(n, &n), n^numdiv(n^2), n^(numdiv(n)/2))

r=0; for(n=1, 1e5, t=A007955(n); if(t>r, r=t; print1(n", "))) \\ Charles R Greathouse IV, Feb 01 2013

CROSSREFS	
Cf. A007955, A007956, A034288, A034090, A034091, A067128.

KEYWORD	
easy,nonn,nice

AUTHOR	
Erich Friedman

EXTENSIONS	
More terms from David W. Wilson, Dec 19 2001

STATUS	
approved

A291899		Numbers n such that (pod(n)/tau(n)) > (pod(k)/tau(k)) for all k < n.		+30
3
1, 3, 4, 6, 8, 10, 12, 18, 20, 24, 30, 36, 48, 60, 72, 84, 90, 96, 108, 120, 168, 180, 240, 336, 360, 420, 480, 504, 540, 600, 630, 660, 672, 720, 840, 1080, 1260, 1440, 1680, 2160, 2520, 3360, 3780, 3960, 4200, 4320, 4620, 4680, 5040, 7560, 9240, 10080, 12600 (list; graph; refs; listen; history; text; internal format)
OFFSET	
1,2

COMMENTS	
pod(n) = the product of the divisors of n (A007955), tau(n) = the number of the divisors of n (A000005).

Contains all members of A002182 except 2. - Robert Israel, Nov 09 2017

Is this the same as A034288 except for 3? - Georg Fischer, Oct 09 2018

From David A. Corneth, Oct 11 2018: (Start)

Various methods exist to find terms for this sequence, possibly combinable:

- Brute force; checking every positive integer up to some bound.

- Finding terms based on the prime signature.

- Relating to that, the number of divisors.

- Finding terms based on the GCD of some earlier found terms.

- ... (?)

There seems to be a method that helps finding terms < 10^150 for the similar A034287. (End)

LINKS	
David A. Corneth, Table of n, a(n) for n = 1..200 (First 126 terms by Robert Israel)

David A. Corneth, Conjectured first 1171 terms

FORMULA	
Numbers n such that (A007955(n)/A000005(n)) > (A007955(k)/A000005(k)) for all k < n.

Numbers n such that (A291186(n)/A137927(n)) > (A291186(k)/A137927(k)) for all k < n.

EXAMPLE	
6 is a term because pod(6)/tau(6) = 36/4 = 9 > pod(k)/tau(k) for all k < 6.

MAPLE	
with(numtheory): P:=proc(q) local a, b, k, n, ok; for n from 1 to q do a:=evalf(n^(tau(n)/2)/tau(n)); ok:=1;

for k from 1 to n-1 do b:=evalf(k^(tau(k)/2)/tau(k)); if a<b or a=b then ok:=0: break; fi; od;

if ok=1 then print(n); fi; od; end: P(10^5); # Paolo P. Lava, Oct 17 2017

# Alternative:

f:= proc(n) local t; t:= numtheory:-tau(n); simplify(n^(t/2))/t end proc:

N:= 20000: # to get all terms <= N

Res:= NULL: m:= 0:

for n from 1 to N do

  v:= f(n);

  if v > m then Res:= Res, n; m:= v fi

od:

Res; # Robert Israel, Nov 09 2017

MATHEMATICA	
With[{s = Array[Times @@ Divisors@ # &, 12600]}, Select[Range@ Length@ s, Function[m, AllTrue[Range[# - 1], m > s[[#]]/DivisorSigma[0, #] &]][s[[#]]/DivisorSigma[0, #]] &]] (* Michael De Vlieger, Oct 10 2017 *)

PROG	
(Magma) a:=1; S:=[a]; for n in [2..60] do k:=0; flag:= true; while flag do k+:=1; if &*[d: d in Divisors(a)] / #[d: d in Divisors(a)] lt &*[d: d in Divisors(k)] / #[d: d in Divisors(k)] then Append(~S, k); a:=k; flag:=false; end if; end while; end for; S;

CROSSREFS	
Cf. A000005, A002182, A034287, A034288, A007955, A120736, A137927, A291186.

KEYWORD	
nonn

AUTHOR	
Jaroslav Krizek, Oct 10 2017

STATUS	
approved

A216365		Numbers n such that tau(n)*sigma(n) sets a new record.		+30
1
1, 2, 3, 4, 6, 8, 10, 12, 18, 20, 24, 30, 36, 48, 60, 72, 84, 90, 96, 108, 120, 144, 168, 180, 240, 300, 336, 360, 420, 480, 504, 540, 600, 630, 660, 720, 840, 1008, 1080, 1200, 1260, 1440, 1680, 2100, 2160, 2520, 3360, 3780, 3960, 4200, 4320, 4620, 4680, 5040 (list; graph; refs; listen; history; text; internal format)
OFFSET	
1,2

COMMENTS	
Positions of record values in A064840.

Not identical to A067128; e.g. a(22) = 144 < 168 = A067128(22).

LINKS	
Charles R Greathouse IV and Donovan Johnson, Table of n, a(n) for n = 1..400 (first 268 terms from Charles R Greathouse IV)

MATHEMATICA	
lst = {}; k = 0; Do[n = DivisorSigma[0, i]*DivisorSigma[1, i]; If[n > k, AppendTo[lst, i]; k = n], {i, 7!}]; lst

PROG	
(PARI) r=0; for(n=1, 1e9, t=numdiv(n)*sigma(n); if(t>r, r=t; print1(n", "))) \\ Charles R Greathouse IV, Sep 05 2012

CROSSREFS	
Cf. A000005, A000203, A064840.

KEYWORD	
nonn

AUTHOR	
Arkadiusz Wesolowski, Sep 05 2012

STATUS	
approved

page 1
Search completed in 0.004 seconds

Lookup | Welcome | Wiki | Register | Music | Plot 2 | Demos | Index | Browse | More | WebCam
Contribute new seq. or comment | Format | Style Sheet | Transforms | Superseeker | Recents
The OEIS Community | Maintained by The OEIS Foundation Inc.
License Agreements, Terms of Use, Privacy Policy. .
Last modified March 27 15:43 EDT 2023. Contains 361574 sequences. (Running on oeis4.)

Mang I am not really in the mood today yikes yikes yikes maybe these patterns reveal a little bit of a simpler upsolve where we merely bash out like um something on the order of an uh bashy kind of an O[n^[1/2]*log^2[n]] works sort of an algorithm only trusting that uh like the true value will be between like r and uh r-r^[1/2] or something and then bashing out those cases works or so.
*/
	

	//in>>a>>b;
}

I main(){zz();I a=1;while(a--){az();}}