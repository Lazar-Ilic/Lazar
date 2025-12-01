/*
PARI|GP Paris Pari De Pascal Pascal's Arithmetic Great Programmable Mid-Latency C Calculator Code:

answer=0
al=0
f(a,b)=
{
    answer=max(answer,a);
	al+=1;
	if(al%1000000==0,print(al," ",answer));
    if(b<=4,f(10*a+0,b+1));
    if(isprime(10*a+1),f(10*a+1,b));
    if(b<=4 && !isprime(10*a+1),f(10*a+1,b+1));
    if(b<=4,f(10*a+2,b+1));
    if(isprime(10*a+3),f(10*a+3,b));
    if(b<=4 && !isprime(10*a+3),f(10*a+3,b+1));
    if(b<=4,f(10*a+4,b+1));
    if(b<=4,f(10*a+5,b+1));
    if(b<=4,f(10*a+6,b+1));
    if(isprime(10*a+7),f(10*a+7,b));
    if(b<=4 && !isprime(10*a+7),f(10*a+7,b+1));
    if(b<=4,f(10*a+8,b+1));
    if(isprime(10*a+9),f(10*a+9,b));
    if(b<=4 && !isprime(10*a+9),f(10*a+9,b+1));
}
f(1,1)
f(2,0)
f(3,0)
f(4,1)
f(5,0)
f(6,1)
f(7,0)
f(8,1)
f(9,1)
print(answer)
numbernonprimes=0
g(a)=
{
	numbernonprimes+=!isprime(a);
	a=(a-(a%10))/10;
	if(a>0,g(a));
}
g(answer)
print(numbernonprimes)
quit()

----------

3733799911799539139382193991

5

----------

Oh OK for the bonus one can execute a memoryless Depth First Search program with O[1] memory usage rather than O[n] which can blow up memory. In particular there exists a very natural ordering here which is like the natural lexicographic ordering of all such strings with <= 5 nonprimes and so I think thus one can actually execute the Depth First Search with an auxiliary variable tracking maximum thus far and an auxiliary variable memorising the direction we are moving like expanding or contracting the string currently uh backtracking I mean prior to re expanding along the Depth First Search graph essentially but basically rather than storing explicit next to search paths we can leave them out of memory and find them implicitly along the way thus executing this task with like O[1] auxiliary memory to a Depth First Search. Uh OKOKOK sounds good to me. In particular there also exists a natural implementation strategy here which merely involves memorising the maximum thus far as well as the previous checked uh such string in order so just memorise 1 more string and deduce uh next valid strings to check and keep on checking until finally hitting and moving to again in order. The precise asymptotics would still depend somewhat nontrivially on the underlying graph an set structure of semivalid integers as well as the runtime on the native C isprime function in PARI|GP and if we have average runtime O[polylogn] rejections in the randomised primality testing algorithm as well as some other implementational specifics I might come back to manipulating at a later date or not.

Alex Fleischer dos not have codes up here for this particular puzzle task:

https://github.com/AlexFleischerParis/ponderthis

----------


*/

// %%writefile a.cpp 
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

// Description: Deterministic Miller-Rabin primality test. Guaranteed to work for numbers up to 7*10^18; for larger numbers, use Python and extend A randomly.
// Time: 7 times the complexity of a^b(mod mod)
ULL modmultiply(ULL a,ULL b,ULL mod){//chilli,c1729,Simon Lindholm
	L ret=a*b-mod*ULL(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
ULL modpower(ULL a,ULL b,ULL mod){
	ULL ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(ULL n){
	if(n<2 or n%6%4!=1)return(n|1)==3;
	ULL aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(ULL a:aaa){   // ^ count trailing zeroes
		ULL ppp=modpower(a%n,d,n),i=s;
		while (ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
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
	*/

	VPL avpl;
	a=0;
	L answer=0;
	avpl={{1,1},{2,0},{3,0},{4,1},{5,0},{6,1},{7,0},{8,1},{9,1}};
	while(a<sz(avpl)){
		if(sz(avpl)%1000000==0)out<<sz(avpl)<<nl;
		answer=max(answer,avpl[a].first);
		for(b=0;b<=9;b++){
			if(isprime(10*avpl[a].first+b))avpl.add({10*avpl[a].first+b,avpl[a].second});
			else if(avpl[a].second+1<=5)avpl.add({10*avpl[a].first+b,avpl[a].second+1});
		}
		a++;
	}
	out<<answer<<nl;
/*

import random
def power(x,y,p):
	res=1
	x=x%p
	while(y>0):
		if(y&1):
			res=(res*x)%p
		y=y>>1
		x=(x*x)%p
	return res
def primetest(d,n):
	a=2+random.randint(1,n-4)
	x=power(a,d,n)
	if(x==1 or x==n-1):
		return True
	while(d!=n-1):
		x=(x*x)%n
		d*=2
		if(x==1):
			return False
		if(x==n-1):
			return True
	return False
def isprime(n,k):
	if(n<=1 or n==4):
		return False
	if(n<=3):
		return True
	d=n-1
	while(d%2==0):
		d//=2
	for i in range(k):
		if(primetest(d,n)==False):
			return False
	return True

k=20

# Simple Breadth First Search Should Suffice Umm

a=0
answer=0
av=[[1,1],[2,0],[3,0],[4,1],[5,0],[6,1],[7,0],[8,1],[9,1]]
while a < len(av):
	answer=max(answer,av[a][0])
	print(answer)
	for b in range(0,10):
		if isprime(10*av[a][0]+b,k):
			av.append([10*av[a][0]+b,av[a][1]])
		elif av[a][1]+1<=5:
			av.append([10*av[a][0]+b,av[a][1]+1])
	a+=1
print(answer)

----------

answer=0
al=0
f(a,b)=
{
    answer=max(answer,a);
	al+=1;
	if(al%1000000==0,print(al," ",answer));
    if(b<=4,f(10*a+0,b+1));
    if(isprime(10*a+1),f(10*a+1,b));
    if(b<=4 && !isprime(10*a+1),f(10*a+1,b+1));
    if(b<=4,f(10*a+2,b+1));
    if(isprime(10*a+3),f(10*a+3,b));
    if(b<=4 && !isprime(10*a+3),f(10*a+3,b+1));
    if(b<=4,f(10*a+4,b+1));
    if(b<=4,f(10*a+5,b+1));
    if(b<=4,f(10*a+6,b+1));
    if(isprime(10*a+7),f(10*a+7,b));
    if(b<=4 && !isprime(10*a+7),f(10*a+7,b+1));
    if(b<=4,f(10*a+8,b+1));
    if(isprime(10*a+9),f(10*a+9,b));
    if(b<=4 && !isprime(10*a+9),f(10*a+9,b+1));
}
f(1,1)
f(2,0)
f(3,0)
f(4,1)
f(5,0)
f(6,1)
f(7,0)
f(8,1)
f(9,1)
print(answer)
numbernonprimes=0
g(a)=
{
	numbernonprimes+=!isprime(a);
	a=(a-(a%10))/10;
	if(a>0,g(a));
}
g(answer)
print(numbernonprimes)
quit()

----------

3733799911799539139382193991
5

----------

Good that I intuitively realised pretty early on in the round that in fact 10^18 is a major key underbound and that Python is too slow so native PARI|GP isprime() function should have come in handy here for the win ab initio could have been an easy simple bash round ugh...

3733799911799539139382193991

----------

numbernonprimes=0
f(a)=
{
	numbernonprimes+=!isprime(a);
	a=(a-(a%10))/10;
	if(a>0,f(a));
}
f(3733799911799539139382193991)
print(numbernonprimes)
quit()

----------

5

----------

print(!isprime(3)+!isprime(37)+!isprime(373)+!isprime(3733)+!isprime(37337)+!isprime(373379)+!isprime(3733799)+!isprime(37337999)+!isprime(373379991)+!isprime(3733799911)+!isprime(37337999117)+!isprime(373379991179)+!isprime(3733799911799)+!isprime(37337999117995)+!isprime(373379991179953)+!isprime(3733799911799539)+!isprime(37337999117995391)+!isprime(373379991179953913)+!isprime(3733799911799539139)+!isprime(37337999117995391393)+!isprime(373379991179953913938)+!isprime(3733799911799539139382)+!isprime(37337999117995391393821+!isprime(373379991179953913938219)+!isprime(3733799911799539139382193)+!isprime(37337999117995391393821939)+!isprime(37337999117995391393821939)+!isprime(37337999117995391393821939)+!isprime(373379991179953913938219391))
quit()

----------

default(parisize,120000000)
av=vector(200)
av[1]=10
for(i=2,200,av[i]=av[i-1]*10);
answer=0
al=0
print(1)
f(a,b,c)=
{
    answer=max(answer,a);
	al+=1;
	if(al%100000==0,print(al," ",answer));
    if(isprime(av[c]*1+a),f(av[c]*1+a,b,c+1));
    if(b<=4 && !isprime(av[c]*1+a),f(av[c]*1+a,b+1,c+1));
	if(isprime(av[c]*2+a),f(av[c]*2+a,b,c+1));
    if(b<=4 && !isprime(av[c]*2+a),f(av[c]*2+a,b+1,c+1));
	if(isprime(av[c]*3+a),f(av[c]*3+a,b,c+1));
    if(b<=4 && !isprime(av[c]*3+a),f(av[c]*3+a,b+1,c+1));
	if(isprime(av[c]*4+a),f(av[c]*4+a,b,c+1));
    if(b<=4 && !isprime(av[c]*4+a),f(av[c]*4+a,b+1,c+1));
	if(isprime(av[c]*5+a),f(av[c]*5+a,b,c+1));
    if(b<=4 && !isprime(av[c]*5+a),f(av[c]*5+a,b+1,c+1));
	if(isprime(av[c]*6+a),f(av[c]*6+a,b,c+1));
    if(b<=4 && !isprime(av[c]*6+a),f(av[c]*6+a,b+1,c+1));
	if(isprime(av[c]*7+a),f(av[c]*7+a,b,c+1));
    if(b<=4 && !isprime(av[c]*7+a),f(av[c]*7+a,b+1,c+1));
	if(isprime(av[c]*8+a),f(av[c]*8+a,b,c+1));
    if(b<=4 && !isprime(av[c]*8+a),f(av[c]*8+a,b+1,c+1));
	if(isprime(av[c]*9+a),f(av[c]*9+a,b,c+1));
    if(b<=4 && !isprime(av[c]*9+a),f(av[c]*9+a,b+1,c+1));
}
f(1,1,1)
f(2,0,1)
f(3,0,1)
f(4,1,1)
f(5,0,1)
f(6,1,1)
f(7,0,1)
f(8,1,1)
f(9,1,1)
print(answer)
quit()

----------

numbernonprimes=0
g(a)=
{
	numbernonprimes+=!isprime(a);
	a=(a-(a%10))/10;
	if(a>0,f(a));
}
g(answer)
print(numbernonprimes)
quit()

----------

\p250
default(parisize,120000000)
av1=vector(200)
av2=vector(200)
av3=vector(200)
av4=vector(200)
av5=vector(200)
av6=vector(200)
av7=vector(200)
av8=vector(200)
av9=vector(200)
av1[1]=10
for(i=2,200,av1[i]=av1[i-1]*10);
for(i=1,200,av2[i]=av1[i]*2);
for(i=1,200,av3[i]=av1[i]*3);
for(i=1,200,av4[i]=av1[i]*4);
for(i=1,200,av5[i]=av1[i]*5);
for(i=1,200,av6[i]=av1[i]*6);
for(i=1,200,av7[i]=av1[i]*7);
for(i=1,200,av8[i]=av1[i]*8);
for(i=1,200,av9[i]=av1[i]*9);
answer=0
al=0
print(1)
f(a,b,c)=
{
    answer=max(answer,a);
	al+=1;
	if(al%100000==0,print(al," ",answer));
    if(isprime(av1[c]+a),f(av1[c]+a,b,c+1));
    if(b<=4 && !isprime(av1[c]+a),f(av1[c]+a,b+1,c+1));
	if(isprime(av2[c]+a),f(av2[c]+a,b,c+1));
    if(b<=4 && !isprime(av2[c]+a),f(av2[c]+a,b+1,c+1));
	if(isprime(av3[c]+a),f(av3[c]+a,b,c+1));
    if(b<=4 && !isprime(av3[c]+a),f(av3[c]+a,b+1,c+1));
	if(isprime(av4[c]+a),f(av4[c]+a,b,c+1));
    if(b<=4 && !isprime(av4[c]+a),f(av4[c]+a,b+1,c+1));
	if(isprime(av5[c]+a),f(av5[c]+a,b,c+1));
    if(b<=4 && !isprime(av5[c]+a),f(av5[c]+a,b+1,c+1));
	if(isprime(av6[c]+a),f(av6[c]+a,b,c+1));
    if(b<=4 && !isprime(av6[c]+a),f(av6[c]+a,b+1,c+1));
	if(isprime(av7[c]+a),f(av7[c]+a,b,c+1));
    if(b<=4 && !isprime(av7[c]+a),f(av7[c]+a,b+1,c+1));
	if(isprime(av8[c]+a),f(av8[c]+a,b,c+1));
    if(b<=4 && !isprime(av8[c]+a),f(av8[c]+a,b+1,c+1));
	if(isprime(av9[c]+a),f(av9[c]+a,b,c+1));
    if(b<=4 && !isprime(av9[c]+a),f(av9[c]+a,b+1,c+1));
}
f(1,1,1)
f(2,0,1)
f(3,0,1)
f(4,1,1)
f(5,0,1)
f(6,1,1)
f(7,0,1)
f(8,1,1)
f(9,1,1)
print(answer)
quit()

----------

Error while connecting with the serverrealprecision = 250 significant digits
***   Warning: new stack size = 120000000 (114.441 Mbytes).
1
100000 916836642873973237576322111
200000 8774697332996421374912422111
300000 8774697332996421374912422111
400000 8774697332996421374912422111
500000 8774697332996421374912422111
600000 994365348498619817779233392111
700000 4236973339221379263136353392111
800000 4236973339221379263136353392111
900000 4236973339221379263136353392111
1000000 4236973339221379263136353392111
1100000 4236973339221379263136353392111
1200000 4236973339221379263136353392111
1300000 4236973339221379263136353392111
1400000 3379272468426763324486836136844111
1500000 3379272468426763324486836136844111

----------

Hmm could be running into stack issues stack overflow errors here or something with a suboptimal Breadth First Search too could run into major key major bag alert major errors with more than 10^9 integers up ahead of us to evaluate... hmmm hmmm hmmm fascinating interesting intriguing little Bonus task to be sure. Might just move on with my life here.

----------

Lazar Ilic IBM Research Ponder This 2023-03
Yahoo
/
Sent



Lazar Ilic <lazar_ilic@yahoo.com>
To:
ponder@il.ibm.com

Wed, Mar 1 at 5:35 AM

3733799911799539139382193991


----------

https://www.ams.org/journals/mcom/1977-31-137/S0025-5718-1977-0427213-2/

https://proofwiki.org/wiki/Definition:Right-Truncatable_Prime/Mistake

https://www.wolframalpha.com/input?i=number+of+primes+less+than+10%5E12

https://research.ibm.com/haifa/ponderthis/challenges/March2023.html

https://en.wikipedia.org/wiki/Truncatable_prime

https://primes.utm.edu/glossary/page.php?sort=RightTruncatablePrime

https://www.primepuzzles.net/puzzles/puzz_131.htm

----------

Uh dunno if I could prune out somehow based upon the number of even digits umm we definitely do need at most 5 even digits is like still a lot of wiggling room and I think this here Depth First Search really might execute in time for a Top 10 performance here...

----------

OKOKOK

Hopefully this C++ code will pop pop off faster... Faster Faster Faster dunno how many millie it will go through and whether or not there might exist some huge huge huge massive chains ugh of like longer digits requiring ugh PARI|GP here to straight up bash...
*/
}

I main(){zz();I a=1;while(a--){az();}}