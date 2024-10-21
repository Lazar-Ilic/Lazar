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
const I p=998244353; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251 L 1000000000039 1000000000000037 1000000000000000003

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
D - Sum of Sum of Digits
Hint 1
By considering each possible value for the ones digit of 
x, you can develop a DP solution that computes the answer for a sequence 
A from the answer for sequences 
A 

  with smaller values.
Hint 2
The sequences to consider in the DP are just the ones obtained by adding to 
⌊A 
i

 /10 
k
 ⌋ the carry from the lower digit. How many possible patterns of carries from the lower digits are there?
Hint 3
The problem can be solved by computing 
dp[k][n] defined as follows in order: 
dp[k][n] is the answer to the problem for a sequence obtained by adding 
1 to 
⌊A 
i

 /10 
k
 ⌋ of the 
n elements with the greatest 
A 
i

 mod10 
k
 .
Editorial → https://atcoder.jp/contests/arc153/editorial/5525

https://atcoder.jp/contests/arc153/editorial/5525

D - Sum of Sum of Digits Editorial by evima
Hints → https://atcoder.jp/contests/arc153/editorial/5524

For a sequence 
A of non-negative integers, let 
F(A) denote the minimum possible value of 
∑ 
i=1
N

 f(A 
i

 +x).

Additionally, let 
K be the maximum number of digits in 
A 
i

 .

[1] Computing 
F(A) recursively
For 
0≤r≤9, let 
F 
r

 (A) denote the minimum of the above value for 
x such that 
x≡r(mod10). We have 
F(A)=min 
r

 F 
r

 (A).

For instance, when 
r=1, if we let 
x=10x 

 +1, from 
f(123+x)=f(12+x 

 )+4, 
f(45+x)=f(4+x 

 )+6 and so on, we have:

F 
1

 ((123,45,678,90))=20+F((12,4,67,9)).

Similarly, when 
r=5, we have:

F 
5

 ((123,45,678,90))=16+F((12,5,68,9)).

In this way, when 
max(A)≥2, one can compute 
F(A) using 
F(A 

 ) for a sequence 
A 

  with smaller values. When 
max(A)=1, we clearly have 
F(A)=sum(A), so this method can compute 
F(A).

[2] Evaluating the number of states
For how many sequences 
A 

  do we have to compute 
F(A 

 ) when computing 
F(A 

 ) recursively by the above method?

It can be seen that the recursive calls at depth 
k only take the sequences 
A 

  that can be written as 
A 
i


 =⌊ 
10 
k
 
A 
i

 +c

 ⌋ for some 
0≤c<10 
k
 .

Thus, if 
i 
1

 ,i 
2

 ,…,i 
N

  are the result of sorting 
i=1,2,…,N in ascending order of 
A 
i

 mod10 
k
 , the recursive calls only take 
A 

  in the following form:

A 
i


 = 
⎩
⎪
⎪
⎪
⎨
⎪
⎪
⎪
⎧

  
⌊ 
10 
k
 
A 
i

 

 ⌋
⌊ 
10 
k
 
A 
i

 

 ⌋+1

  
(i=i 
1

 ,…,i 
n

 )
(i=i 
n+1

 ,…,i 
N

 )

 

Let 
A(k,n) denote the sequence 
A 

  determined in this way. One can see that there are at most 
K(N+1) such sequences.

[3] Summary
Therefore, the problem can be solved by dynamic programming where 
dp[k][n], defined by 
dp[k][n]=F(A(k,n)) (
0≤k<K,0≤n≤N), are computed in descending order of 
k. The bottleneck is the sorting of 
A 
i

 mod10 
k
  for each 
k, and the total complexity is 
O(NKlogN). Or, in the manner of radix sort, one can use the result of sorting 
A 
i

 mod10 
k-1
  in the sorting of 
A 
i

 mod10 
k
  to make the complexity 
O(NK).

Note that the complexity would increase if you performed a computation taking 
Ω(N) time for all sequences 
A(k,n), such as examining all terms. To perform the recursive computation stated in [1], you only need the frequency distribution of the ones digits of 
A(k,n), so the computation can be done faster by looking at the differences of 
A(k,n+1) and 
A(k,n), or using some cumulative sums.

OKOKOK

So 100 solvers 30 minutes in means it must be very trivial like maybe for each uh dude we can do this in like O[15 * n] or something so somehow go digit by digit and uh compute the frequencies of like uh well things can carry over multiple times if we end in like 999 and boom up but like need to track some information about frequencies merely on the last digit and then somehow recurse in by counting frequencies and cutting off the last digit maybe maybe maybe not. Go read up DEF try and crack 1 of those tasks maybe here early on for the Top 200.

OKOKOK maybe it is trivial to actually count up like the uh number of uh umm hmm let us see here umm is it trivial to count up the number of like dudes who umm say induce pairs of dudes who will induce a 4 in the umm 4th place? That is to say count the number of pairs of dudes who will produce a suffix of sum of like the form XXXXXXXXXXXXXXXXX4XXX umm...

Maybe we could like take a bunch of I dunno range counting uh segment trees or something frankly umm or we could like store a simple umm vector of the moduli that is to say a vector of the mod 10 remainders and a vector of the mod 100 remainders etc. etc. and then loop through for each dude like umm consider the precise ranges needed to produce the right digits is done I think.

Pretty disgusting round today frankly I think I should be pinging down uh ABC there pretty nearly instantaneously like all 3 of those in sub under < 30 minutes to be sure to be sure to be sure snagging a like Top 150 not a Top 450 ugh latency is everything in latency critical sensitive settings and situations such as these ugh. This code can obviously be vectorised in loop and optimised much further it was just in round I kind of spasmed out there on the lengthy debug and with more practice I will get better and stop overflowing long longs maybe soon I just start handling all integers as long longs instead so as to not Focus upon it or just pay more attention in these critical AtCoder Regular Contests shooting for Top 100.

Way way way too lethargic here today on the ABC to be sure to be sure to be sure you love to see a slow ABCD but you love even more to see a fast ABCD and the difference between a slow and fast ABC is massive it is literally the difference between 2400 and 2000 that is to say if you are around a ~1600 a 2x difference a +2x in the uprating multiplier on the session and so seriously critical to get in there and bridge that gap between a 三段 and a 初段 and so on and so on soon hopefully maybe next round onsight ABC or ABD or ABE or ABCD and snag 2級 on to my Resume.pdf and Resume.txt files.

In terms of me broadcasting publicly information upon this I obviously hate the CodeForces structure and intend to quit the moment I hit GrandMaster and ping that down but I want to beat the Big Brothers and Yang Patil Liu in particular in the Future onsight shit like this today ABCD in sub-30:00 flat. Frankly CodeForces is such a deeply problematic aggravating agitating platform system and I love AtCoder so it is AtCoder gang Until The Death hunting down that 三段 eventually maybe RedBelt.
	*/

	in>>a;
	avvl=VVL(16,VL(0));
	bl=10;
	for(b=0;b<a;b++){
		in>>al;
		bl=10;
		for(c=0;c<=15;c++){avvl[c].add(al%bl);bl*=10;}
		/*
		avvl[0].add(al%10); // All information we need to compute 0th digit.
		avvl[1].add(al%100);
		avvl[2].add(al%1000);
		avvl[3].add(al%10000);
		avvl[4].add(al%100000);
		avvl[5].add(al%1000000);
		avvl[6].add(al%10000000);
		avvl[7].add(al%100000000);
		avvl[8].add(al%1000000000);
		avvl[9].add(al%10000000000);
		avvl[10].add(al%10000000000);
		avvl[11].add(al%100000000000);
		avvl[12].add(al%1000000000000);
		avvl[13].add(al%10000000000000);
		avvl[14].add(al%100000000000000);
		avvl[15].add(al%1000000000000000);
		*/
	}
	for(b=0;b<=15;b++)sort(all(avvl[b]));
	al=0; // Answer
	bl=1;
	for(b=0;b<=15;b++){
		//out<<al<<" "<<bl<<" "<<(avvl[b][c]<1*bl)<<" "<<avvl[b][c]<<" "<<nl;
		// Process through the vector b I suppose the bth digit.
		// bl is the actual modulus here I think.
		for(c=0;c<sz(avvl[b]) and avvl[b][c]<1*bl;c++){
			// Between 00 and 09 inclusive e.g.
			al+=0*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),1*bl-avvl[b][c])-avvl[b].begin());
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),2*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),1*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),2*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<2*bl;c++){
			// Between 10 and 19 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),2*bl-avvl[b][c])-avvl[b].begin());
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),2*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<3*bl;c++){
			// Between 20 and 29 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c])-avvl[b].begin());
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),3*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<4*bl;c++){
			// Between 30 and 39 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c])-avvl[b].begin());
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),4*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<5*bl;c++){
			// Between 40 and 49 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c])-avvl[b].begin());
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),5*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<6*bl;c++){
			// Between 50 and 59 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c]));
			al+=5*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c])-avvl[b].begin());
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),6*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<7*bl;c++){
			// Between 60 and 69 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c]));
			al+=6*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c])-avvl[b].begin());
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),7*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<8*bl;c++){
			// Between 70 and 79 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c]));
			al+=7*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c])-avvl[b].begin());
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),8*bl-avvl[b][c]));
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<9*bl;c++){
			// Between 80 and 89 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),18*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c]));
			al+=8*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),18*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c])-avvl[b].begin());
			al+=9*(lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),9*bl-avvl[b][c]));
		}
		//out<<al<<nl;
		for(;c<sz(avvl[b]) and avvl[b][c]<10*bl;c++){
			// Between 90 and 99 inclusive e.g.
			al+=0*(lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c]));
			al+=1*(lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),11*bl-avvl[b][c]));
			al+=2*(lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),12*bl-avvl[b][c]));
			al+=3*(lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),13*bl-avvl[b][c]));
			al+=4*(lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),14*bl-avvl[b][c]));
			al+=5*(lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),15*bl-avvl[b][c]));
			al+=6*(lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),16*bl-avvl[b][c]));
			al+=7*(lowerbound(avvl[b].begin(),avvl[b].end(),18*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),17*bl-avvl[b][c]));
			al+=8*(lowerbound(avvl[b].begin(),avvl[b].end(),19*bl-avvl[b][c])-lowerbound(avvl[b].begin(),avvl[b].end(),18*bl-avvl[b][c]));
			al+=9*(avvl[b].end()-lowerbound(avvl[b].begin(),avvl[b].end(),19*bl-avvl[b][c])+lowerbound(avvl[b].begin(),avvl[b].end(),10*bl-avvl[b][c])-avvl[b].begin());
		}
		//out<<al<<nl<<nl;
		bl*=10;
	}
	out<<al<<nl;
}

I main(){zz();I a=1;while(a--){az();}}