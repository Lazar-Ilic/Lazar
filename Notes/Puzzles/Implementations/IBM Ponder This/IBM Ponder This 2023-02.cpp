/*
Interesting task. So immediately one can try brute force bashing out the usual n-Queens task and testing each case. However, my implementation did not AC in the first 10 minutes and then I realised that the actual underlying structure here if we are targeting having precisely 14 1s, 4 2s, and 1 4 dude connected component with precisely 3 edges e.g. a 4 chain in the resultant underlying embedding of the 19 free diagonals cross the 19 other free diagonals. This reduces the case count into checking potentially like up to [39 choose 19]^2 sets of diagonals and then bashing for permutation tractability. One can also attempt to literally sketch out a potential such set of free diagonals and then fill in with a permutation. Is there a simple maximum flow setting? Flow of 4 into each square and then out like 1 through each to the row column and diagonals and then enforce the precise diagonals binary strings as desired in the flow setting as well as the 1 for each row and column?

https://www.csplib.org/Problems/prob079/

CSPLib Problems prob079
079: n-Queens Completion Problem and Excluded Diagonals n-Queens Problem
Specification
 
Data files
 
Results
 
References
 
Models
 
Cite
 
Json
Edit Page
Proposed by Ian Gent

n
-Queens Completion Problem
The N-Queens Problem, [prob054], suffers from the problem that its complexity is trivial as a decision problem.
The n-Queens Completion and Blocked n-Queens problems are variants of N-Queens which have been proven to be NP-Complete as decision problems and #P-Complete as counting problems.

An instance of n-Queens Completion
An instance of n-Queens Completion from 1850
For the n
-Queens Completion Problem, as well as board size n
, one is given some number of queens placed on the board already. The problem is to provide a solution to the n
-Queens problem containing all those queens. I.e. a superset of the preplaced queens of size n
 and with no two queens on the same row, column, or diagonal. (If any two of the preplaced queens attack each other it is considered to be trivially unsolvable).

The image shows an example problem, originating in 1850 [Nauck1850a]. Can you place the other 6 queens to give a solution to the 8-Queens problem? And in how many ways is this possible? The answers are shown below.

Excluded Diagonals n
-Queens Problem
The Excluded Diagonals Problem is a closely related problem where, given an n×n
 board, only certain rows and columns are allowed and certain diagonals are excluded. For rows and columns, a subset of rows and columns are specified which are allowed. The subsets must be the same size. A sum diagonal is the set of squares where the sum of the row and column indexes of the squares is constant. A difference diagonal is the set of squares where the difference between the row and column indexes is constant.
For the Excluded Diagonals Problem, we are given n
 and a set of diagonals, each of which is either a sum diagonal or a difference diagonal. A solution is a set of queens with exactly one queen in each of the allowed rows and columns, and where where no queen is placed on one of the
excluded diagonals.

Relation between the two problems
The two problems here are so similar it is best to think of them as the same problem, as processing to flip between them is very simple.

To go from n
-Queens Completion to Excluded Diagonals is very easy: simply allow only rows and columns with no queens preplaced, and exclude any diagonals (both sum and diagonal) on which there are preplaced queens.

The other direction is more complex but still fast, following a construction in [nqueenscompletion]. It is implemented in the python files diagtoqueens.py and queens-diag-transform.py.

The two problems are closely related to Blocked n-Queens Problem, [prob080].

Random Instance Generators
Python generators are available to implement the models from the paper [nqueenscompletion]. The generator for random placement of queens for of n-Queens Completion is not recommended as it does not seem to produce hard instances. The generator for random Excluded Diagonals n-Queens instances does appear to generate hard instances.

Note that the generator for Excluded Diagonals always allows all rows and columns, so those are not outputted. It also offsets the difference diagonals by n-1 so that all numbers are non-negative. Also it generates a maximal set of diagonals which retain the property that there are at least k squares left in each row and column (e.g. k=4). The generator is designed so that, if you want fewer diagonals than that maximal number, e.g. d
, you can simply take the first d
 diagonals and get a probabilistically valid sample.

References
The n-Queens Completion problem was proposed in 1850 [Nauck1850a]

The Excluded Diagonals Problem was proposed by [nqueenscompletion]

Both problems were proved NP-Complete and #P-Complete by [nqueenscompletion]

An instance of n-Queens Completion An instance of n-Queens Completion
The Two Solutions to the n-Queens Completion from 1850
Creative Commons License This work is licensed under a Creative Commons Attribution 4.0 International License.

----------

00000000000000000000  1 0000
000000000000000000001   0000
00000000000000000000   10000
00000000000000000000 1  0000
000000000000  1 000000000000
0000000000001   000000000000
000000000000   1000000000000
000000000000 1  000000000000
0000  1 00000000000000000000
00001   00000000000000000000
0000   100000000000000000000
0000 1  00000000000000000000
000000000000000000000000  1 
0000000000000000000000001   
000000000000000000000000   1
000000000000000000000000 1  
0000000000000000  1 00000000
00000000000000001   00000000
0000000000000000   100000000
0000000000000000 1  00000000
00000000  1 0000000000000000
000000001   0000000000000000
00000000   10000000000000000
00000000 1  0000000000000000
  1 000000000000000000000000
1   000000000000000000000000
   1000000000000000000000000
 1  000000000000000000000000

----------

Centrosymmetric Solutions to Chessboard Separation Problems
R. Douglas Chatham∗ Maureen Doyle† Robert J. Jeffers‡ Walter A. Kosters§
R. Duane Skaggs¶ Jeffrey Wardk
Abstract
Chessboard separation problems are modifications to classic chessboard problems, such as the N
queens problem, in which obstacles are placed on the chessboard. The N + k queens problem requires
placements of k pawns and N + k mutually non-attacking queens on an N-by-N chessboard. Here we
examine centrosymmetric (half-turn symmetric) and doubly centrosymmetric (quarter-turn symmetric)
solutions to the N +k queens problem. We also consider solutions in which the queens and pawns exhibit
different types of symmetry.
Keywords: combinatorial algorithms, N queens problem, symmetry
AMS Subject Classification 05B20, 05C69, 68R05

----------

Hmm quite interesting that seems like an interesting starting point for example to attempt to do a bashing of the 29 x 29 case for the Bonus could work. Ugh this puzzle still feels really trivial and easy except I am sleep deprived today. Should be a super duper wooper low solve time I think for me snoozing off here like < 30 minutes not ~10 hours.

----------

Ugh in the example there were like 5 free squares on an n=8 board kind of suggests that maybe ugh an 14*1 + 4*2 + 4*1 = 26 free squares on an n=20 board is possible in fact. But I probably need to dig up some code to bash it and maybe consider which precise digonals can appear where exactly.

----------

"
For a solution S of the n-queens problem, let M(S) denote the maximum of the absolute values of the diagonal numbers of S, and let m(S) denote the minimum of those absolute values. For n≥4, let F(n) denote the minimum value of M(S), and let f(n) denote the maximum value of m(S), as S ranges over all solutions of the n-queens problem. Say that a solution S is an n-champion if M(S)=F(n) and m(S)=f(n). Approximately linear bounds are given for F(n) and f(n), along with computational results and several constructions together providing evidence that the bounds are excellent. It is shown that, in the range 4≤n≤24,n-champions exist except for n=11,16,21,22.
"

----------

https://cses.fi/problemset/task/1624/

CSES Hacking Section of course can be sorted for low latency codes.

----------

http://oeis.org/A000170

----------

Perhaps we try some sort of annealing process or like that one 2015 United States Of America Maths Olympiad Task 4 consider swapping [a,b] [c,d] with [a,d] and [c,b] and try to like do this until converging in on the desired target value of 48 and could like consider perhaps starting off with a simple example for the 20 x 20 case and then transmogrifying it as needed until hitting 48 or for near 48 values just kind of RNJesusing around in that search space until finally hitting it as a target again. Convergence rate should be could be quite rapid really just need to try like DFSing and shit from each potential 400-state position is pretty low runtime ugh each step is like consider 20 choose 2 um errrum it is like 100000 for each step could be super duper wooper AC code perhaps probably on the order of at most 10^10 operations.
*/

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391

//--------------------------------------------------------------------


I ans;
I lol;
B bbb[20][20];
B place(I x, I y){
    B yes = true;
    for(I i = 0; i < 20; i++)
        if(bbb[x][i] || bbb[i][y])
            yes = false;
    for(I i = 0; x-i >= 0 && y-i >= 0; i++)
        if(bbb[x-i][y-i])
            yes = false;
    for(I i = 0; x-i >= 0 && y+i < 20; i++)
        if(bbb[x-i][y+i])
            yes = false;
    return yes;
}
Z dfs(I i){
    if(i == 20){
        if(lol){
            ans++;
			if(ans%10000==0)out<<ans<<nl;
			// Check the possible spaces.
			VV ccc;
			ccc=VV(20,V(20));
			for(I a=0;a<20;a++){
				for(I b=0;b<20;b++){
					if(bbb[a][b]){
						for(I c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(I c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			V av;
			av=V(5);
			for(I a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(I b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]==0){
						I d=0;
						QP aqp;
						VP avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							P ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							I e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				lol=0;
				for(I a=0;a<20;a++){
					for(I b=0;b<20;b++){
						out<<bbb[a][b];
					}
					out<<nl;
				}
			}
		}
        return;
    }
    for(I j = 0; j < 20; j++){
        if(place(i, j)){
            bbb[i][j] = true;
            dfs(i+1);
            bbb[i][j] = false;
        }
    }
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
	lol=1;
	ans=0;
    dfs(0);
    //out<<ans<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OK Another Attempt

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391

//--------------------------------------------------------------------


I ans;
I lol;
B bbb[20][20], input[20][20];
B place(I x, I y){
    B yes = true;
    for(I i = 0; i < 20; i++)
        if(bbb[x][i] || bbb[i][y])
            yes = false;
    for(I i = 0; x-i >= 0 && y-i >= 0; i++)
        if(bbb[x-i][y-i])
            yes = false;
    for(I i = 0; x-i >= 0 && y+i < 20; i++)
        if(bbb[x-i][y+i])
            yes = false;
    return yes;
}
B check(){
    for(I i = 0; i < 20; i++)
        for(I j = 0; j < 20; j++)
            if(bbb[i][j] && input[i][j])
                return false;
    return true;
}
Z dfs(I i){
    if(i == 20){
        if(check() and lol){
            ans++;
			if(ans%10==0)out<<ans<<nl;
			// Check the possible spaces.
			VV ccc;
			ccc=VV(20,V(20));
			for(I a=0;a<20;a++){
				for(I b=0;b<20;b++){
					if(bbb[a][b]){
						for(I c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(I c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			V av;
			av=V(5);
			for(I a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(I b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]==0){
						I d=0;
						QP aqp;
						VP avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							P ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							I e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				lol=0;
				for(I a=0;a<20;a++){
					for(I b=0;b<20;b++){
						out<<bbb[a][b];
					}
					out<<nl;
				}
			}
		}
        return;
    }
    for(I j = 0; j < 20; j++){
        if(place(i, j)){
            bbb[i][j] = true;
            dfs(i+1);
            bbb[i][j] = false;
        }
    }
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
	lol=1;
	avs.add("-...-.-...-.-...-...");
	avs.add(".-.-.-...-.-...-...-");
	avs.add("..-.-...-.-...-...-.");
	avs.add(".-.-...-.-...-...-..");
	avs.add("-.-.-.-.-...-...-...");
	avs.add(".-...-.-...-...-...-");
	avs.add("-.-.-.-...-...-...-.");
	avs.add("...-.-.-.-...-...-..");
	avs.add("..-.-...-...-...-...");
	avs.add(".-.-.-.-.-.-...-...-");
	avs.add("-.-...-...-...-...-.");
	avs.add(".-...-.-.-.-.-...-..");
	avs.add("-...-...-...-...-...");
	avs.add(".-.-...-.-.-.-.-...-");
	avs.add("..-...-...-...-...-.");
	avs.add(".-.-.-...-.-.-.-.-..");
	avs.add("-...-...-...-...-...");
	avs.add("...-.-.-...-.-.-.-.-");
	avs.add("..-...-...-...-...-.");
	avs.add(".-...-.-.-...-.-.-.-");
	for(a=0;a<20;a++){
		for(b=0;b<20;b++){
			if(avs[a][b]=='-')input[a][b]=1;
		}
	}
    dfs(0);
    //out<<ans<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OK maybe let us try instead somehow generating upon the underlying actual raw permutation in like Python or with some other script and then generating out the 19 by 19 of unhit diagonals and seeing that underlying graph structure which those induce.

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391

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
	SETP asetp;
	asetp.insert({0,5});
	asetp.insert({1,3});
	asetp.insert({2,6});
	asetp.insert({3,0});
	asetp.insert({4,7});
	asetp.insert({5,1});
	asetp.insert({6,4});
	asetp.insert({7,2});
	avv=VV(64,V(64));
	for(a=0;a<64;a++){
		for(b=0;b<64;b++){
			c=a/8;
			d=b/8;
			e=a%8;
			f=b%8;
			if(asetp.count({c,d}) and asetp.count({e,f})){
				avv[a][b]=1;
				aset.insert(a+b);
				bset.insert(a-b);
			}
		}
	}
	out<<sz(aset)<<nl<<sz(bset)<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OKOKOK we need another approach I think for the Bonus and main task.

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391

//--------------------------------------------------------------------


I ans;
I lol;
I minnn;
B bbb[26][26];
B place(I x, I y){
    B yes = true;
    for(I i = 0; i < 26; i++)
        if(bbb[x][i] || bbb[i][y])
            yes = false;
    for(I i = 0; x-i >= 0 && y-i >= 0; i++)
        if(bbb[x-i][y-i])
            yes = false;
    for(I i = 0; x-i >= 0 && y+i < 26; i++)
        if(bbb[x-i][y+i])
            yes = false;
    return yes;
}
Z dfs(I i){
    if(i == 26){
        if(lol){
            ans++;
			if(ans%10000==0)out<<ans<<nl;
			// Check the possible spaces.
			VV ccc;
			ccc=VV(26,V(26));
			for(I a=0;a<26;a++){
				for(I b=0;b<26;b++){
					if(bbb[a][b]){
						for(I c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(I c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			I part;
			part=0;
			for(I a=0;a<26;a++){
				for(I b=0;b<26;b++){
					if(ccc[a][b]==0){
						I d=0;
						QP aqp;
						VP avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							P ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<26 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<26 and ap.second+1<26 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<26 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<26 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<26 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						part+=(d+1)/2;
					}
				}
			}
			if(part<minnn){
				minnn=part;
				out<<minnn<<nl;
				for(I a=0;a<26;a++){
					for(I b=0;b<26;b++){
						out<<bbb[a][b];
					}
					out<<nl;
				}
			}
		}
        return;
    }
    for(I j = 0; j < 26; j++){
        if(place(i, j)){
            bbb[i][j] = true;
            dfs(i+1);
            bbb[i][j] = false;
        }
    }
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
	lol=1;
	ans=0;
	minnn=500;
    dfs(0);
    //out<<ans<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OKOKOK maybe I need to look up stronger codes from other people. This brute force code for n=8 is not sharp backtracking I think here. Still not sure if I could possibly just crack this entire puzzle by hand.

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391

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
	m=300;
	aset.insert(0); // Sum Of X+Y Coordinates
	aset.insert(1);
	aset.insert(3);
	aset.insert(-1);
	aset.insert(-3);
	bset.insert(0); // Subtraction Of X-Y Coordinates
	bset.insert(-1);
	bset.insert(3);
	bset.insert(1);
	bset.insert(-3);
	av={3,4,5,6,7,8,9,10,11,12,13,14};
	// Test [12 choose 6] * 6! = 665280 cases.
	for(a=3;a<=9;a++){
		for(b=a+1;b<=10;b++){
			for(c=b+1;c<=11;c++){
				for(d=c+1;d<=12;d++){
					for(e=d+1;e<=13;e++){
						for(f=e+1;f<=14;f++){
							av=V(0);
							for(g=3;g<a;g++)av.add(g);
							for(g=a+1;g<b;g++)av.add(g);
							for(g=b+1;g<c;g++)av.add(g);
							for(g=c+1;g<d;g++)av.add(g);
							for(g=d+1;g<e;g++)av.add(g);
							for(g=e+1;g<f;g++)av.add(g);
							for(g=f+1;g<=14;g++)av.add(g);
							do{
								cset=aset; // X + Y
								dset=bset; // X - Y
								if(0==cset.count(a+av[0]) and 0==dset.count(a-av[0])){
									cset.insert(a+av[0]);
									dset.insert(a-av[0]);
								if(0==cset.count(-a-av[0]) and 0==dset.count(-a+av[0])){
									cset.insert(-a-av[0]);
									dset.insert(-a+av[0]);
								if(0==cset.count(av[0]-a) and 0==dset.count(av[0]+a)){
									cset.insert(av[0]-a);
									dset.insert(av[0]+a);
								if(0==cset.count(-av[0]+a) and 0==dset.count(-av[0]-a)){
									cset.insert(-av[0]+a);
									dset.insert(-av[0]-a);
								// OK 6ix times of that.

								if(0==cset.count(b+av[1]) and 0==dset.count(b-av[1])){
									cset.insert(b+av[1]);
									dset.insert(b-av[1]);
								if(0==cset.count(-b-av[1]) and 0==dset.count(-b+av[1])){
									cset.insert(-b-av[1]);
									dset.insert(-b+av[1]);
								if(0==cset.count(av[1]-b) and 0==dset.count(av[1]+b)){
									cset.insert(av[1]-b);
									dset.insert(av[1]+b);
								if(0==cset.count(-av[1]+b) and 0==dset.count(-av[1]-b)){
									cset.insert(-av[1]+b);
									dset.insert(-av[1]-b);
								// OK 6ix times of that.

								if(0==cset.count(c+av[2]) and 0==dset.count(c-av[2])){
									cset.insert(c+av[2]);
									dset.insert(c-av[2]);
								if(0==cset.count(-c-av[2]) and 0==dset.count(-c+av[2])){
									cset.insert(-c-av[2]);
									dset.insert(-c+av[2]);
								if(0==cset.count(av[2]-c) and 0==dset.count(av[2]+c)){
									cset.insert(av[2]-c);
									dset.insert(av[2]+c);
								if(0==cset.count(-av[2]+c) and 0==dset.count(-av[2]-c)){
									cset.insert(-av[2]+c);
									dset.insert(-av[2]-c);
								// OK 6ix times of that.

								if(0==cset.count(d+av[3]) and 0==dset.count(d-av[3])){
									cset.insert(d+av[3]);
									dset.insert(d-av[3]);
								if(0==cset.count(-d-av[3]) and 0==dset.count(-d+av[3])){
									cset.insert(-d-av[3]);
									dset.insert(-d+av[3]);
								if(0==cset.count(av[3]-d) and 0==dset.count(av[3]+d)){
									cset.insert(av[3]-d);
									dset.insert(av[3]+d);
								if(0==cset.count(-av[3]+d) and 0==dset.count(-av[3]-d)){
									cset.insert(-av[3]+d);
									dset.insert(-av[3]-d);
								// OK 6ix times of that.

								if(0==cset.count(e+av[4]) and 0==dset.count(e-av[4])){
									cset.insert(e+av[4]);
									dset.insert(e-av[4]);
								if(0==cset.count(-e-av[4]) and 0==dset.count(-e+av[4])){
									cset.insert(-e-av[4]);
									dset.insert(-e+av[4]);
								if(0==cset.count(av[4]-e) and 0==dset.count(av[4]+e)){
									cset.insert(av[4]-e);
									dset.insert(av[4]+e);
								if(0==cset.count(-av[4]+e) and 0==dset.count(-av[4]-e)){
									cset.insert(-av[4]+e);
									dset.insert(-av[4]-e);
								// OK 6ix times of that.

								if(0==cset.count(f+av[5]) and 0==dset.count(f-av[5])){
									cset.insert(f+av[5]);
									dset.insert(f-av[5]);
								if(0==cset.count(-f-av[5]) and 0==dset.count(-f+av[5])){
									cset.insert(-f-av[5]);
									dset.insert(-f+av[5]);
								if(0==cset.count(av[5]-f) and 0==dset.count(av[5]+f)){
									cset.insert(av[5]-f);
									dset.insert(av[5]+f);
								if(0==cset.count(-av[5]+f) and 0==dset.count(-av[5]-f)){
									cset.insert(-av[5]+f);
									dset.insert(-av[5]-f);
								// OK 6ix times of that.
								z=0;
								avv=VV(29,V(29));
								for(g=-14;g<=14;g++){
									for(h=-14;h<=14;h++){
										if(0==cset.count(g+h) and 0==dset.count(g-h)){
											z++;
											avv[g+14][h+14]=1;
										}
									}
								}
								if(z<m){
									m=z;
									out<<m<<nl<<a<<" "<<av[0]<<nl<<b<<" "<<av[1]<<nl<<c<<" "<<av[2]<<nl<<d<<" "<<av[3]<<nl<<e<<" "<<av[4]<<nl<<f<<" "<<av[5]<<nl<<nl;
									for(g=0;g<29;g++){
										for(h=0;h<29;h++){
											if(avv[g][h])out<<"#";
											else out<<" ";
										}
										out<<nl;
									}
									SETP asetp;
									asetp.insert({0,0});
									asetp.insert({1,2});
									asetp.insert({-2,1});
									asetp.insert({-1,-2});
									asetp.insert({2,-1});
									asetp.insert({a,av[0]});
									asetp.insert({-a,-av[0]});
									asetp.insert({av[0],-a});
									asetp.insert({-av[0],a});

									asetp.insert({b,av[1]});
									asetp.insert({-b,-av[1]});
									asetp.insert({av[1],-b});
									asetp.insert({-av[1],b});

									asetp.insert({c,av[2]});
									asetp.insert({-c,-av[2]});
									asetp.insert({av[2],-c});
									asetp.insert({-av[2],c});

									asetp.insert({d,av[3]});
									asetp.insert({-d,-av[3]});
									asetp.insert({av[3],-d});
									asetp.insert({-av[3],d});

									asetp.insert({e,av[4]});
									asetp.insert({-e,-av[4]});
									asetp.insert({av[4],-e});
									asetp.insert({-av[4],e});

									asetp.insert({f,av[5]});
									asetp.insert({-f,-av[5]});
									asetp.insert({av[5],-f});
									asetp.insert({-av[5],f});
									out<<"[";
									for(auto dude:asetp)out<<"("<<dude.first+14<<", "<<dude.second+14<<"), ";
									out<<"]"<<nl;
									out<<nl<<nl;
								}
								// OK
								}
								}
								}
								}

								// OK
								}
								}
								}
								}

								// OK
								}
								}
								}
								}

								// OK
								}
								}
								}
								}

								// OK
								}
								}
								}
								}

								// OK
								}
								}
								}
								}
							}while(nextpermutation(all(av)));
						}
					}
				}
			}
		}
	}
/*
           #     #           
          ##  #  ##          
             # #             
            # # #            
             ###             
              #              
                             
                             
                             
                             
 #                         # 
##                         ##
   #                     #   
  # #                   # #  
 # ###                 ### # 
  # #                   # #  
   #                     #   
##                         ##
 #                         # 
                             
                             
                             
                             
              #              
             ###             
            # # #            
             # #             
          ##  #  ##          
           #     #           


lazar@penguin:~$ 

[(-14, 10), (-13, 5), (-12, 7), (-11, 4), (-10, -14), (-9, 3), (-8, 6), (-7, -12), (-6, -8), (-5, -13), (-4, -11), (-3, -9), (-2, 1), (-1, -2), (0, 0), (1, 2), (2, -1), (3, 9), (4, 11), (5, 13), (6, 8), (7, 12), (8, -6), (9, -3), (10, 14), (11, -4), (12, -7), (13, -5), (14, -10), ]

[(0, 24), (1, 19), (2, 21), (3, 18), (4, 0), (5, 17), (6, 20), (7, 2), (8, 6), (9, 1), (10, 3), (11, 5), (12, 15), (13, 12), (14, 14), (15, 16), (16, 13), (17, 23), (18, 25), (19, 27), (20, 22), (21, 26), (22, 8), (23, 11), (24, 28), (25, 10), (26, 7), (27, 9), (28, 4), ]
*/
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OKOKOK so finally I Get Got ACcepted on the Bonus a couple hours into the round and now need to crack the primary main task. Yikes umm perhaps it could be done by hand perhaps not ugh yikes. Check out those other people and their codes I guess. Really not that trivial at all in fact and I am totally not even convinced the density of these types of dude hitting 48 precisely is that that that high... not sure not sure not totally sure I mean it could be on the order of 10^[-8] or better at which point simple pseudorandom sampling until simply hitting could work but we would also need to be able to pseudorandomly sample from valid 20-Queens solutions... hmm. Tank and maybe come back to constrained programs and try up new and different interesting ways to enter in the constraints.

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang :) <3

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

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
Maybe without loss of generality just select those front and back 6 for each and then ugh just try bashing out like the other ugh like 27 choose 7 in each direction somehow ugh. Ugh potentially worth considering ugh ugh ugh could RNG ugh maybe RNG is a good strategy or try umm like instead doing the 29 choose 9 with an auxiliary RNG could work out OKOKOK maybe.
*/
	in>>a;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OKOKOK here is an RNJesus

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang :) <3

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

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
Maybe without loss of generality just select those front and back 6 for each and then ugh just try bashing out like the other ugh like 27 choose 7 in each direction somehow ugh. Ugh potentially worth considering ugh ugh ugh could RNG ugh maybe RNG is a good strategy or try umm like instead doing the 29 choose 9 with an auxiliary RNG could work out OKOKOK maybe.

First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}

OKOKOK can try selecting 9 from 5 through 33 inclusive on each. Is 29 choose 9 ugh.
*/
	aset.insert(0);
	aset.insert(1);
	aset.insert(2);
	aset.insert(3);
	aset.insert(4);
	aset.insert(34);
	aset.insert(35);
	aset.insert(36);
	aset.insert(37);
	aset.insert(38);
	bset.insert(0);
	bset.insert(1);
	bset.insert(2);
	bset.insert(3);
	bset.insert(4);
	bset.insert(34);
	bset.insert(35);
	bset.insert(36);
	bset.insert(37);
	bset.insert(38);
	z=0;
	y=0;
	for(a=0;a<9;a++)av.add(1);
	for(a=0;a<20;a++)av.add(0);
	while(z<100){
		y++;
		cset=aset;
		shuf(av.begin(),av.end());
		for(a=5;a<=33;a++){
			if(av[a-5])cset.insert(a);
		}
		dset=bset;
		shuf(av.begin(),av.end());
		for(a=5;a<=33;a++){
			if(av[a-5])dset.insert(a);
		}

			VV ccc(20,V(20,1));
			for(a=0;a<20;a++){
				for(b=0;b<20;b++){
					if(cset.count(a+b) and dset.count(a-b+19)){
						ccc[a][b]=0;
					}
				}
			}
			V av;
			av=V(5);
			for(a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]==0){
						d=0;
						QP aqp;
						avp=VP(0);
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(y%10000==0)outv(av);
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				z++;
				out<<"{";
				for(auto dude:cset)out<<"{"<<dude<<",1},";
				for(auto dude:dset)out<<"{"<<dude<<",0},";
				out<<"}"<<nl;
			}
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OKOKOK here is another RNJesus:

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang :) <3

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

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
Maybe without loss of generality just select those front and back 6 for each and then ugh just try bashing out like the other ugh like 27 choose 7 in each direction somehow ugh. Ugh potentially worth considering ugh ugh ugh could RNG ugh maybe RNG is a good strategy or try umm like instead doing the 29 choose 9 with an auxiliary RNG could work out OKOKOK maybe.

First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}

OKOKOK can try selecting 9 from 5 through 33 inclusive on each. Is 29 choose 9 ugh.
*/
	aset.insert(0);
	aset.insert(1);
	aset.insert(2);
	aset.insert(3);
	aset.insert(4);
	aset.insert(5);
	aset.insert(33);
	aset.insert(34);
	aset.insert(35);
	aset.insert(36);
	aset.insert(37);
	aset.insert(38);
	bset.insert(0);
	bset.insert(1);
	bset.insert(2);
	bset.insert(3);
	bset.insert(4);
	bset.insert(5);
	bset.insert(33);
	bset.insert(34);
	bset.insert(35);
	bset.insert(36);
	bset.insert(37);
	bset.insert(38);
	z=0;
	y=0;
	for(a=0;a<7;a++)av.add(1);
	for(a=0;a<20;a++)av.add(0);
	while(z<100){
		y++;
		cset=aset;
		shuf(av.begin(),av.end());
		for(a=6;a<=32;a++){
			if(av[a-5])cset.insert(a);
		}
		dset=bset;
		shuf(av.begin(),av.end());
		for(a=6;a<=32;a++){
			if(av[a-5])dset.insert(a);
		}

			VV ccc(20,V(20,1));
			for(a=0;a<20;a++){
				for(b=0;b<20;b++){
					if(cset.count(a+b) and dset.count(a-b+19)){
						ccc[a][b]=0;
					}
				}
			}
			V av;
			av=V(5);
			for(a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]==0){
						d=0;
						QP aqp;
						avp=VP(0);
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(y%10000==0)outv(av);
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				z++;
				out<<"{";
				for(auto dude:cset)out<<"{"<<dude<<",1},";
				for(auto dude:dset)out<<"{"<<dude<<",0},";
				out<<"}"<<nl;
			}
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// OK another RNJesus

//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang :) <3

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
using MVI=map<V,I>;
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

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
Maybe without loss of generality just select those front and back 6 for each and then ugh just try bashing out like the other ugh like 27 choose 7 in each direction somehow ugh. Ugh potentially worth considering ugh ugh ugh could RNG ugh maybe RNG is a good strategy or try umm like instead doing the 29 choose 9 with an auxiliary RNG could work out OKOKOK maybe.

First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}

OKOKOK can try selecting 9 from 5 through 33 inclusive on each. Is 29 choose 9 ugh.
*/
	aset.insert(0);
	aset.insert(1);
	aset.insert(2);
	aset.insert(3);
	aset.insert(4);
	aset.insert(5);
	aset.insert(33);
	aset.insert(34);
	aset.insert(35);
	aset.insert(36);
	aset.insert(37);
	aset.insert(38);
	bset.insert(0);
	bset.insert(1);
	bset.insert(2);
	bset.insert(3);
	bset.insert(4);
	bset.insert(5);
	bset.insert(33);
	bset.insert(34);
	bset.insert(35);
	bset.insert(36);
	bset.insert(37);
	bset.insert(38);
	z=0;
	y=0;
	for(a=0;a<7;a++)av.add(1);
	for(a=0;a<20;a++)av.add(0);
	while(z<100){
		y++;
		cset=aset;
		shuf(av.begin(),av.end());
		for(a=6;a<=32;a++){
			if(av[a-5])cset.insert(a);
		}
		dset=bset;
		shuf(av.begin(),av.end());
		for(a=6;a<=32;a++){
			if(av[a-5])dset.insert(a);
		}

			VV ccc(20,V(20,1));
			for(a=0;a<20;a++){
				for(b=0;b<20;b++){
					if(cset.count(a+b) and dset.count(a-b+19)){
						ccc[a][b]=0;
					}
				}
			}
			V av;
			av=V(4);
			for(a=0;a<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;a++){
				for(b=0;b<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;b++){
					if(ccc[a][b]==0){
						d=0;
						QP aqp;
						avp=VP(0);
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							ap=aqp.front();
							avp.add(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>3)av[1]=16;
						else if(d==3){
							e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=16;
							else av[3]++;
						}
						else av[d]++;
					}
				}
			}
			if(y%10000==0)outv(av);
			if(av[1]==15 and av[2]==4 and av[3]==1){
				z++;
				out<<"{";
				for(auto dude:cset)out<<"{"<<dude<<",1},";
				for(auto dude:dset)out<<"{"<<dude<<",0},";
				out<<"}"<<nl;
			}
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}

// Then it strikes me that perhaps instead of [14,4,0,1] what could also work could be the even simpler... [15,4,1] with the actual 3 dude forming a full K3 C3 cycle on the underlying Kings' Graph so that there is precisely 3 ways to choose the needed 1 Kings from that chunk.

// OKOKOK here is a solver program:

/*
The MIT License (MIT) Copyright (c) 2015 Christopher Jefferson. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies of substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <signal.h>
#include <vector>
#ifdef PRINT_INFO
#define INFO(...) printf(__VA_ARGS__);
#define PAD(x) pad(x);
#define PRINTBITS(x) printBits(x)
#else
#define INFO(...)
#define PAD(x)
#define PRINTBITS(x)
#endif
#define PRINT_SOL
#ifdef PRINT_SOL
static int sol[100];
#endif
#include <sys/resource.h>
#include <sys/times.h>
#include <sstream>
double gettime(){
	struct rusage rusage;
	if(getrusage(RUSAGE_SELF,&rusage)!=-1)return (double)rusage.ru_utime.tv_sec+(double)rusage.ru_utime.tv_usec/1000000.0;
	std::cerr<<"Fatal error in reading time\n";
	exit(1);
}

volatile int trig = false;

void trigger_function(int){
  trig = true;
}

void setup_timelimit(int timeout){
	signal(SIGXCPU,trigger_function);
	signal(SIGALRM,trigger_function);
	rlimit lim;
	lim.rlim_cur=timeout;
	lim.rlim_max=timeout + 5;
	setrlimit(RLIMIT_CPU,&lim);
}

long long node_count=0;
static __int128_t all;
static const __int128_t one=1;
static int depth;
static int count=0;
int fillLeft[127];
int fillRight[127];
int skipDepth[127];

#ifdef PRINT_SOL
void print_sol(){
	printf("\n");
	for(int i=0;i<depth;++i){
		for(int j=0;j<depth;++j){
			if(1<<j==sol[i])std::cout<<i<<" "<<j<<"\n";
		}
	}

}
#endif

void printBits(__int128_t bits){
	for(int i=0;i<depth;++i){
		printf(bits & one ? "1":"0");
		bits=bits>>1;
	}
}

void pad(int curDepth){
	for(int i=0;i<curDepth;++i)printf(" ");
}

void print_info(){
        std::cout<<"Solutions: "<<count<<" ";
        std::cout<<"Nodes: "<<node_count<<" ";
        std::cout<<"Timeout: "<<trig<<" ";
        std::cout<<"Time: "<<gettime()<<"\n";
}

void tryFunc(__int128_t ld, __int128_t cols, __int128_t rd, int curDepth){
		node_count++;
		if(trig){
			print_info();
			std::cout<<"Timeout Reached. Exiting.\n";
			exit(0);
		}
		PAD(curDepth);
		PRINTBITS(ld);
		INFO(",");
		PRINTBITS(cols);
		INFO(",");
		PRINTBITS(rd);
		INFO(":%d ", curDepth);
	if(curDepth==depth){
		INFO("\n");
		count++;
		std::cout<<"Solution Found\n";
#ifdef PRINT_SOL
		print_sol();
#endif
		print_info();
		exit(0);
	}
	__int128_t shiftld=ld<<1;
	__int128_t shiftrd=rd>>1;
	assert((shiftld & one)==0);
	assert((shiftrd & (one<<(depth-1)))==0);
	if(fillLeft[curDepth+1]){
		INFO("*");
		shiftld |= one;
	}
	else
	INFO(" ");
	if(fillRight[curDepth+1]){
		INFO("*");
		shiftrd |= one<<(depth-1);
	}
	else INFO(" ");
	if(skipDepth[curDepth]){
		INFO(" -- skip\n");
		return tryFunc(shiftld,cols,shiftrd,curDepth+1);
	}
	PRINTBITS(shiftld);
		INFO(",");
		PRINTBITS(shiftrd);
		INFO("\n");
	{
		__int128_t poss=~(ld | cols | rd) & all;
		while(poss){
			__int128_t bit=poss & -poss;
			poss-=bit;
#ifdef PRINT_SOL
	sol[curDepth]=bit;
#endif
			PAD(curDepth);
			PRINTBITS(bit);
			INFO(" added\n");
			tryFunc((bit<<1)|shiftld,cols|bit,(bit>>1)|shiftrd,curDepth+1);
		}
	}
}

int main(int argc,char** argv)
{
	depth=20;
	all=(one<<depth)-1;
	__int128_t cols=0;
	__int128_t ld=0;
	__int128_t rd=0;
	int diagonals=19;
	/*
	The value numdiags is the number of diagonals in the list diags. For any number d up to numdiags a valid excluded diagonals instance can be created by taking the FIRST d elements of the list diagas. Other subsets should not be taken as they may not be statistically valid. Therefore the above example creates 15 valid instances from d=0 up to d=14.

	The list diags consists of pairs, where the first number represents a pair and the second number the type of diagonal. 1 represents a sum diagonal and 0 represents a difference diagonal. The boards are assumed to be indexed from 0, so the corners of a 10x10 board are (0,0) (0,9), (9,0) and (9,9).

	For sum diagonals the excluded diagonal is given by the first number in the pair.

	For difference diagonals the excluded diagonal is offset by n-1, i.e. the difference diagonal to be excluded is the first number minus n-1.

	For example in the above, the pair [4,1] excludes sum diagonal 4, i.e. squares (0,4), (1,3), (2,2), (3,1), (4,). While the pair [5,0] excludes difference diagonal 5-9=-4 (since 10-1=9). That is, it excludes the squares (0,4), (1,5), (2,6), (3,7), (4,8), (5,9).
	*/
	std::vector<std::pair<int,int>> avp={{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}; // {{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,}}
	// First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}
	for(int i=0;i<diagonals;i++){
		int diag,direction;
		diag=avp[i].first;
		direction=avp[i].second;
		if(direction){
			int rightintersect=diag;
			if(rightintersect<depth){
				__int128_t newrd=one<<rightintersect;
				if(rd & newrd){
					printf("Inconsistent Diagonal\n");
				}
				rd |= newrd;
			}
			else{
					rightintersect-=(depth-1);
					if(fillRight[rightintersect]){
						printf("Inconsistent Diagonal - Type 2\n");
					}
					fillRight[rightintersect]=1;
			}
		}
		else{
			int leftintersect=diag-depth+1;
			if(leftintersect>=0){
				__int128_t newld=one<<leftintersect;
				if(ld & newld){
					printf("Inconsistent Left Diagonal\n");
				}
				ld |= newld;
			}
			else{
					leftintersect*=-1;
					if(fillLeft[leftintersect]){
						printf("Inconsistent Left Diagonal - Type 2\n");
					}
					fillLeft[leftintersect]=1;
			}
		}
	}
	count=0;
	tryFunc(ld,cols,rd,0);
	std::cout<<"No Solution"<<"\n";
	print_info();
	exit(0);
}

// OKOKOK confirming that in fact it works on a 19 open subset ugh.

/*
The MIT License (MIT) Copyright (c) 2015 Christopher Jefferson. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies of substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <signal.h>
#include <vector>
#ifdef PRINT_INFO
#define INFO(...) printf(__VA_ARGS__);
#define PAD(x) pad(x);
#define PRINTBITS(x) printBits(x)
#else
#define INFO(...)
#define PAD(x)
#define PRINTBITS(x)
#endif
#define PRINT_SOL
#ifdef PRINT_SOL
static int sol[100];
#endif
#include <sys/resource.h>
#include <sys/times.h>
#include <sstream>
double gettime(){
	struct rusage rusage;
	if(getrusage(RUSAGE_SELF,&rusage)!=-1)return (double)rusage.ru_utime.tv_sec+(double)rusage.ru_utime.tv_usec/1000000.0;
	std::cerr<<"Fatal error in reading time\n";
	exit(1);
}

volatile int trig = false;

void trigger_function(int){
  trig = true;
}

void setup_timelimit(int timeout){
	signal(SIGXCPU,trigger_function);
	signal(SIGALRM,trigger_function);
	rlimit lim;
	lim.rlim_cur=timeout;
	lim.rlim_max=timeout + 5;
	setrlimit(RLIMIT_CPU,&lim);
}

long long node_count=0;
static __int128_t all;
static const __int128_t one=1;
static int depth;
static int count=0;
int fillLeft[127];
int fillRight[127];
int skipDepth[127];

#ifdef PRINT_SOL
void print_sol(){
	printf("\n");
	for(int i=0;i<depth;++i){
		for(int j=0;j<depth;++j){
			if(1<<j==sol[i])std::cout<<i<<" "<<j<<"\n";
		}
	}

}
#endif

void printBits(__int128_t bits){
	for(int i=0;i<depth;++i){
		printf(bits & one ? "1":"0");
		bits=bits>>1;
	}
}

void pad(int curDepth){
	for(int i=0;i<curDepth;++i)printf(" ");
}

void print_info(){
        std::cout<<"Solutions: "<<count<<" ";
        std::cout<<"Nodes: "<<node_count<<" ";
        std::cout<<"Timeout: "<<trig<<" ";
        std::cout<<"Time: "<<gettime()<<"\n";
}

void tryFunc(__int128_t ld, __int128_t cols, __int128_t rd, int curDepth){
		node_count++;
		if(trig){
			print_info();
			std::cout<<"Timeout Reached. Exiting.\n";
			exit(0);
		}
		PAD(curDepth);
		PRINTBITS(ld);
		INFO(",");
		PRINTBITS(cols);
		INFO(",");
		PRINTBITS(rd);
		INFO(":%d ", curDepth);
	if(curDepth==depth){
		INFO("\n");
		count++;
		std::cout<<"Solution Found\n";
#ifdef PRINT_SOL
		print_sol();
#endif
		print_info();
		exit(0);
	}
	__int128_t shiftld=ld<<1;
	__int128_t shiftrd=rd>>1;
	assert((shiftld & one)==0);
	assert((shiftrd & (one<<(depth-1)))==0);
	if(fillLeft[curDepth+1]){
		INFO("*");
		shiftld |= one;
	}
	else
	INFO(" ");
	if(fillRight[curDepth+1]){
		INFO("*");
		shiftrd |= one<<(depth-1);
	}
	else INFO(" ");
	if(skipDepth[curDepth]){
		INFO(" -- skip\n");
		return tryFunc(shiftld,cols,shiftrd,curDepth+1);
	}
	PRINTBITS(shiftld);
		INFO(",");
		PRINTBITS(shiftrd);
		INFO("\n");
	{
		__int128_t poss=~(ld | cols | rd) & all;
		while(poss){
			__int128_t bit=poss & -poss;
			poss-=bit;
#ifdef PRINT_SOL
	sol[curDepth]=bit;
#endif
			PAD(curDepth);
			PRINTBITS(bit);
			INFO(" added\n");
			tryFunc((bit<<1)|shiftld,cols|bit,(bit>>1)|shiftrd,curDepth+1);
		}
	}
}

int main(int argc,char** argv)
{
	depth=20;
	all=(one<<depth)-1;
	__int128_t cols=0;
	__int128_t ld=0;
	__int128_t rd=0;
	int diagonals=19;
	/*
	The value numdiags is the number of diagonals in the list diags. For any number d up to numdiags a valid excluded diagonals instance can be created by taking the FIRST d elements of the list diagas. Other subsets should not be taken as they may not be statistically valid. Therefore the above example creates 15 valid instances from d=0 up to d=14.

	The list diags consists of pairs, where the first number represents a pair and the second number the type of diagonal. 1 represents a sum diagonal and 0 represents a difference diagonal. The boards are assumed to be indexed from 0, so the corners of a 10x10 board are (0,0) (0,9), (9,0) and (9,9).

	For sum diagonals the excluded diagonal is given by the first number in the pair.

	For difference diagonals the excluded diagonal is offset by n-1, i.e. the difference diagonal to be excluded is the first number minus n-1.

	For example in the above, the pair [4,1] excludes sum diagonal 4, i.e. squares (0,4), (1,3), (2,2), (3,1), (4,). While the pair [5,0] excludes difference diagonal 5-9=-4 (since 10-1=9). That is, it excludes the squares (0,4), (1,5), (2,6), (3,7), (4,8), (5,9).
	*/
	std::vector<std::pair<int,int>> avp={{1,1},{2,1},{5,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{14,1},{15,1},{16,1},{32,1},{33,1},{34,1},{35,1},{36,1},{37,1},{38,1}}; // {{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,}}
	// First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}
	for(int i=0;i<diagonals;i++){
		int diag,direction;
		diag=avp[i].first;
		direction=avp[i].second;
		if(direction){
			int rightintersect=diag;
			if(rightintersect<depth){
				__int128_t newrd=one<<rightintersect;
				if(rd & newrd){
					printf("Inconsistent Diagonal\n");
				}
				rd |= newrd;
			}
			else{
					rightintersect-=(depth-1);
					if(fillRight[rightintersect]){
						printf("Inconsistent Diagonal - Type 2\n");
					}
					fillRight[rightintersect]=1;
			}
		}
		else{
			int leftintersect=diag-depth+1;
			if(leftintersect>=0){
				__int128_t newld=one<<leftintersect;
				if(ld & newld){
					printf("Inconsistent Left Diagonal\n");
				}
				ld |= newld;
			}
			else{
					leftintersect*=-1;
					if(fillLeft[leftintersect]){
						printf("Inconsistent Left Diagonal - Type 2\n");
					}
					fillLeft[leftintersect]=1;
			}
		}
	}
	count=0;
	tryFunc(ld,cols,rd,0);
	std::cout<<"No Solution"<<"\n";
	print_info();
	exit(0);
}

/*
Solution Found

0 0
1 2
2 4
3 1
4 3
5 12
6 14
7 11
8 17
9 19
10 16
11 8
12 15
13 18
14 7
15 9
16 6
17 13
18 5
19 10
Solutions: 1 Nodes: 74 Timeout: 0 Time: 0.003965
*/

// OKOKOK ugh fascinating little Quantitative Research here trying out interesting little test cases...

/*
The MIT License (MIT) Copyright (c) 2015 Christopher Jefferson. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies of substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <signal.h>
#include <vector>
#ifdef PRINT_INFO
#define INFO(...) printf(__VA_ARGS__);
#define PAD(x) pad(x);
#define PRINTBITS(x) printBits(x)
#else
#define INFO(...)
#define PAD(x)
#define PRINTBITS(x)
#endif
#define PRINT_SOL
#ifdef PRINT_SOL
static int sol[100];
#endif
#include <sys/resource.h>
#include <sys/times.h>
#include <sstream>
double gettime(){
	struct rusage rusage;
	if(getrusage(RUSAGE_SELF,&rusage)!=-1)return (double)rusage.ru_utime.tv_sec+(double)rusage.ru_utime.tv_usec/1000000.0;
	std::cerr<<"Fatal error in reading time\n";
	exit(1);
}

volatile int trig = false;

void trigger_function(int){
  trig = true;
}

void setup_timelimit(int timeout){
	signal(SIGXCPU,trigger_function);
	signal(SIGALRM,trigger_function);
	rlimit lim;
	lim.rlim_cur=timeout;
	lim.rlim_max=timeout + 5;
	setrlimit(RLIMIT_CPU,&lim);
}

long long node_count=0;
static __int128_t all;
static const __int128_t one=1;
static int depth;
static int count=0;
int fillLeft[127];
int fillRight[127];
int skipDepth[127];

#ifdef PRINT_SOL
void print_sol(){
	printf("\n");
	for(int i=0;i<depth;++i){
		for(int j=0;j<depth;++j){
			if(1<<j==sol[i])std::cout<<i<<" "<<j<<"\n";
		}
	}

}
#endif

void printBits(__int128_t bits){
	for(int i=0;i<depth;++i){
		printf(bits & one ? "1":"0");
		bits=bits>>1;
	}
}

void pad(int curDepth){
	for(int i=0;i<curDepth;++i)printf(" ");
}

void print_info(){
        std::cout<<"Solutions: "<<count<<" ";
        std::cout<<"Nodes: "<<node_count<<" ";
        std::cout<<"Timeout: "<<trig<<" ";
        std::cout<<"Time: "<<gettime()<<"\n";
}

void tryFunc(__int128_t ld, __int128_t cols, __int128_t rd, int curDepth){
		node_count++;
		if(trig){
			print_info();
			std::cout<<"Timeout Reached. Exiting.\n";
			exit(0);
		}
		PAD(curDepth);
		PRINTBITS(ld);
		INFO(",");
		PRINTBITS(cols);
		INFO(",");
		PRINTBITS(rd);
		INFO(":%d ", curDepth);
	if(curDepth==depth){
		INFO("\n");
		count++;
		std::cout<<"Solution Found\n";
#ifdef PRINT_SOL
		print_sol();
#endif
		print_info();
		exit(0);
	}
	__int128_t shiftld=ld<<1;
	__int128_t shiftrd=rd>>1;
	assert((shiftld & one)==0);
	assert((shiftrd & (one<<(depth-1)))==0);
	if(fillLeft[curDepth+1]){
		INFO("*");
		shiftld |= one;
	}
	else
	INFO(" ");
	if(fillRight[curDepth+1]){
		INFO("*");
		shiftrd |= one<<(depth-1);
	}
	else INFO(" ");
	if(skipDepth[curDepth]){
		INFO(" -- skip\n");
		return tryFunc(shiftld,cols,shiftrd,curDepth+1);
	}
	PRINTBITS(shiftld);
		INFO(",");
		PRINTBITS(shiftrd);
		INFO("\n");
	{
		__int128_t poss=~(ld | cols | rd) & all;
		while(poss){
			__int128_t bit=poss & -poss;
			poss-=bit;
#ifdef PRINT_SOL
	sol[curDepth]=bit;
#endif
			PAD(curDepth);
			PRINTBITS(bit);
			INFO(" added\n");
			tryFunc((bit<<1)|shiftld,cols|bit,(bit>>1)|shiftrd,curDepth+1);
		}
	}
}

int main(int argc,char** argv)
{
	depth=20;
	all=(one<<depth)-1;
	__int128_t cols=0;
	__int128_t ld=0;
	__int128_t rd=0;
	int diagonals=19;
	/*
	The value numdiags is the number of diagonals in the list diags. For any number d up to numdiags a valid excluded diagonals instance can be created by taking the FIRST d elements of the list diagas. Other subsets should not be taken as they may not be statistically valid. Therefore the above example creates 15 valid instances from d=0 up to d=14.

	The list diags consists of pairs, where the first number represents a pair and the second number the type of diagonal. 1 represents a sum diagonal and 0 represents a difference diagonal. The boards are assumed to be indexed from 0, so the corners of a 10x10 board are (0,0) (0,9), (9,0) and (9,9).

	For sum diagonals the excluded diagonal is given by the first number in the pair.

	For difference diagonals the excluded diagonal is offset by n-1, i.e. the difference diagonal to be excluded is the first number minus n-1.

	For example in the above, the pair [4,1] excludes sum diagonal 4, i.e. squares (0,4), (1,3), (2,2), (3,1), (4,). While the pair [5,0] excludes difference diagonal 5-9=-4 (since 10-1=9). That is, it excludes the squares (0,4), (1,5), (2,6), (3,7), (4,8), (5,9).
	*/
	std::vector<std::pair<int,int>> avp={{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{30,1},{31,1},{32,1},{33,1},{34,1},{35,1},{36,1},{37,1},{38,1}}; // {{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,},{,}}
	// First attempt... hmm... how to generate potential vectors which might actually have solutions if I can only test around 120 cases in 1 hour? {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{8,1},{10,1},{12,1},{16,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{29,1},{23,1},{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{8,0},{11,0},{12,0},{16,0},{38,0},{37,0},{36,0},{35,0},{34,0},{33,0},{30,0},{26,0},{22,0}}
	for(int i=0;i<diagonals;i++){
		int diag,direction;
		diag=avp[i].first;
		direction=avp[i].second;
		if(direction){
			int rightintersect=diag;
			if(rightintersect<depth){
				__int128_t newrd=one<<rightintersect;
				if(rd & newrd){
					printf("Inconsistent Diagonal\n");
				}
				rd |= newrd;
			}
			else{
					rightintersect-=(depth-1);
					if(fillRight[rightintersect]){
						printf("Inconsistent Diagonal - Type 2\n");
					}
					fillRight[rightintersect]=1;
			}
		}
		else{
			int leftintersect=diag-depth+1;
			if(leftintersect>=0){
				__int128_t newld=one<<leftintersect;
				if(ld & newld){
					printf("Inconsistent Left Diagonal\n");
				}
				ld |= newld;
			}
			else{
					leftintersect*=-1;
					if(fillLeft[leftintersect]){
						printf("Inconsistent Left Diagonal - Type 2\n");
					}
					fillLeft[leftintersect]=1;
			}
		}
	}
	count=0;
	tryFunc(ld,cols,rd,0);
	std::cout<<"No Solution"<<"\n";
	print_info();
	exit(0);
}

/*
No Solution
Solutions: 0 Nodes: 823833237 Timeout: 0 Time: 70.2613

Well well well I mean this is interesting the thing is every single square we do it is banned and we need free squares but we also want a low number of double-hit squares means we want these minimal length diagonals is like... maybe OKOKOK if there were like on the order of 39029188884 solution configurations and like 1000000000000 potential input diagonals chains if only if only if only we could bash through to find potential diagonal 38-tuplets and then bash out if it was somewhat distributed OK the P of success for each one would be around 1/100 though maybe realistically it could plausibly be in the range of 1/100000 at which point we would still have AC code if we could just plausibly generate those test input cases.

OKOKOK it kind of half begs the question like what fraction of those [39 choose 19] potential Input cases for the 19 sum diagonal do even obtain >= 1 solution. But I digress. The fact that there were 25 solvers in the first 6 days suggests to me that maybe simply bashing it out with a more performant program for long enough might really work if it was even 100 times faster than my initial attempt in the C programming language might really work.
*/

// OKOKOK an example of a half decent counter program which will not work here but nevertheless could be optimised into executing for the n = 20 case in around 20 hours I think...

#include <cstdio>
//using namespace std;
inline int calcDiag1Bit(int max,int row,int col){
	return 1<<(max-col-row);
}
inline int calcDiag2Bit(int max,int row,int col){
	return calcDiag1Bit(max,row,max-col);
}
long long solve(int max, int solutions,int *rowsUsed,int row,int col,int allCols,int diag1,int diag2){
	int rowBit,colBit,diag1bit,diag2bit;
	for(col=0;col<max;col++){
		if(allCols&(colBit=(1<<col)))continue;
		if(diag1&(diag1bit=calcDiag1Bit(max,row,col)))continue;
		if(diag2&(diag2bit=calcDiag2Bit(max,row,col)))continue;
		rowsUsed[row]=col;
		if(row>=(max-1))++solutions;
		else solutions=solve(max,solutions,rowsUsed,row+1,col,allCols|colBit, diag1|diag1bit,diag2|diag2bit);
	}
	rowsUsed[row]=-1;
	return solutions;
}
int main(){
	int	 i,rowsUsed[32];
	long long solutions;
	for(i=0;i<32;i++)rowsUsed[i]=-1;
	solutions=solve(20,0,rowsUsed,0,0,0,0,0);
	printf("%d: %d total solutions\n",i,solutions);
}

// Another half interesting related program piece of software...

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int tablewidth = 1;
int offset1 = 0;
int offset2 = 0;

struct type_of_node
{
       char number; //y
       char position; //x
       struct type_of_node *next;
       struct type_of_node *previous;
};

type_of_node * Createnode(type_of_node *temp)
{
     temp->next = new(type_of_node);
     temp->next->previous = temp;
     temp->next->next = NULL;
     return temp->next;
}

void cleanstuff(bool usedrows[], bool type1diagons[], bool type2diagons[])
{
     int i;
     for(i = 0; i < tablewidth; i++)
           usedrows[i] = false;
     for(i = 0; i < (2 * tablewidth - 1); i++)
     {
           type1diagons[i] = false;
           type2diagons[i] = false;
     }
}

char Findposition(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[])
{
     int i;
     for(i = x + 1; i <= tablewidth; i++)
     {
           if(usedrows[i - 1] == false and type1diagons[i - y + offset1] == false and type2diagons[i + y + offset2] == false)
                  return i;
     }
     return -1;
}

void delusedareas(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[])
{
     usedrows[x - 1] = false;
     type1diagons[x - y + offset1] = false;
     type2diagons[x + y + offset2] = false;
}

void markusedareas(char y, char x, bool usedrows[], bool type1diagons[], bool type2diagons[])
{
     usedrows[x - 1] = true;
     type1diagons[x - y + offset1] = true;
     type2diagons[x + y + offset2] = true;
}

void Printnodes(type_of_node *temp)
{
     printf("\n--------------------------------\n");
     printf("\tCoordinates\n\tX\tY");
     while(temp->next != NULL)
     {
                  printf("\n%d:\t%d\t%d",temp->number, temp->position, temp->number);
                  temp = temp->next;    
     }
     printf("\n%d:\t%d\t%d",temp->number, temp->position, temp->number);
     printf("\n");
}

void Solve_problem()
{
    int i;
    bool *usedrows;
    bool *type1diagons;
    bool *type2diagons;
    time_t t1,t2;
    int answer = 0;
    printf("Adjust table dimensions with a single number\n(more than 2x2 less than 40x40)\n");
    while(answer < 3 or answer > 40)
          scanf("%d", &answer);
    tablewidth = answer;  
    offset1 = tablewidth - 1;
    offset2 = -2; 
    answer = 0;
    usedrows = (bool*)malloc(tablewidth * sizeof(char));
    type1diagons = (bool*)malloc((2 * tablewidth - 1) * sizeof(char));
    type2diagons = (bool*)malloc((2 * tablewidth - 1) * sizeof(char));
    cleanstuff(usedrows, type1diagons, type2diagons);
    struct type_of_node *lista, *temp;
    lista = new(type_of_node);
    lista->number = 1;
    lista->position = 1;
    lista->previous = NULL;
    lista->next = NULL;
    markusedareas(lista->number, lista->position, usedrows, type1diagons, type2diagons);
    temp = new(type_of_node);
    temp = lista;
    bool flag = 1;
    char position;
    unsigned long int counter = 0;
    for(i = 0; i < tablewidth - 1; i++)
    {
          temp = Createnode(temp);
          temp->number = temp->previous->number + 1;
          temp->position = 0;
    }
    temp = lista->next;
    (void) time(&t1);
    while(flag)
    {
            counter++;
            position = Findposition(temp->number, temp->position, usedrows, type1diagons, type2diagons);
            if(position != -1)
            {
                       temp->position = position;
                       markusedareas(temp->number, temp->position, usedrows, type1diagons, type2diagons);
                       if(temp->number == tablewidth)
                       {
                                       flag = false;
                                       break; 
                       }
                       temp = temp->next;
            }
            else
            {
                       if(temp->number == 1)
                       {
                                       flag = false;
                                       break;
                       }
                       temp->position = 0;
                       temp = temp->previous;
                       delusedareas(temp->number, temp->position, usedrows, type1diagons, type2diagons);
            }
    }
    printf("\n--------------------------------");
    printf("\nNumber of steps:%d", counter);
    (void) time(&t2);
    printf("\nTime taken = %d seconds", (int) t2-t1);
    if(temp->number == 1)
    {
               printf("\n--------------------------------");
               printf("\nUnable to solve the problem...\n");
    }
    else
        Printnodes(lista);
}

int main()
{
    int answer = 0;
    Solve_problem();
    printf("\nDo you want to try another variation? (Y=Yes,N=No)\n");
    while(answer != 'N' and answer != 'n')
    {
          scanf("%c", &answer);
          if(answer == 'Y' or answer == 'y')
          {
                    Solve_problem();
                    printf("\nDo you want to try another variation? (Y=Yes,N=No)\n");
                    answer = 0;
          }
    }
    system("PAUSE");
    return 0;
}

// Might just try bashing again on a more performant implementation.

#include <bits/stdc++.h>
using namespace std;
int zzz;
void solveBoard(vector<vector<bool>>& board,int row,int rowmask,int ldmask,int rdmask){
    int n=board.size();
    int all_rows_filled=(1<<n)-1;
    if(rowmask==all_rows_filled){
        vector<int> v;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board.size();j++){
                if(board[i][j])v.push_back(j);
            }
        }
		
        zzz++;
		if(zzz%100000==0)cout<<zzz<<endl;		

		//OKOKOK still a relatively slow program overall.

			vector<vector<bool>> ccc(20,vector<bool>(20,true));
			for(int a=0;a<20;a++){
				for(int b=0;b<20;b++){
					if(board[a][b]){
						for(int c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=false;
						for(int c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=false;
					}
				}
			}
			vector<int> av(5);
			for(int a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(int b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]){
						int d=0;
						queue<pair<int,int>> aqp;
						vector<pair<int,int>> avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							pair<int,int> ap=aqp.front();
							avp.push_back(ap);
							ccc[ap.first][ap.second]=false;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second])aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1])aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1])aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1])aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second])aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1])aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1])aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1])aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							int e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				for(int a=0;a<20;a++){
					for(int b=0;b<20;b++){
						cout<<board[a][b];
					}
					cout<<endl;
				}
			}

        return;
    }
    int safe=all_rows_filled&(~(rowmask|ldmask|rdmask));
    while(safe){
        int p=safe&(-safe);
        int col=(int)log2(p);
        board[row][col]=true;
        solveBoard(board,row+1,rowmask|p,(ldmask|p)<<1,(rdmask|p)>>1);
        safe=safe&(safe-1);
        board[row][col]=false;
    }
    return;
}

int main(){
    int n=20;zzz=0;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    int rowmask=0,ldmask=0,rdmask=0,row=0;
    solveBoard(board,row,rowmask,ldmask,rdmask);
    return 0;
}

// Uh bool is slower than int here I think.

#include <bits/stdc++.h>
using namespace std;
int zzz;
void solveBoard(vector<vector<bool>>& board,int row,int rowmask,int ldmask,int rdmask){
    int n=board.size();
    int all_rows_filled=(1<<n)-1;
    if(rowmask==all_rows_filled){
		/*
        vector<int> v;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board.size();j++){
                if(board[i][j])v.push_back(j);
            }
        }
		*/
        zzz++;
		if(zzz%100000==0)cout<<zzz<<endl;		

		//OKOKOK still a relatively slow program overall.

			vector<vector<int>> ccc(20,vector<int>(20));
			for(int a=0;a<20;a++){
				for(int b=0;b<20;b++){
					if(board[a][b]){
						for(int c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(int c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			vector<int> av(5);
			for(int a=0;a<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;a++){
				for(int b=0;b<20 and av[1]<=14 and av[2]<=4 and av[3]<=0 and av[4]<=1;b++){
					if(ccc[a][b]==0){
						int d=0;
						queue<pair<int,int>> aqp;
						vector<pair<int,int>> avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							pair<int,int> ap=aqp.front();
							avp.push_back(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>4)av[1]=15;
						else if(d==4){
							int e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=15;
							else av[4]++;
						}
						else if(d==3)av[1]=15;
						else if(d<=2)av[d]++;
					}
				}
			}
			if(av[1]==14 and av[2]==4 and av[3]==0 and av[4]==1){
				for(int a=0;a<20;a++){
					for(int b=0;b<20;b++){
						cout<<board[a][b];
					}
					cout<<endl;
				}
			}

        return;
    }
    int safe=all_rows_filled&(~(rowmask|ldmask|rdmask));
    while(safe){
        int p=safe&(-safe);
        int col=(int)log2(p);
        board[row][col]=true;
        solveBoard(board,row+1,rowmask|p,(ldmask|p)<<1,(rdmask|p)>>1);
        safe=safe&(safe-1);
        board[row][col]=false;
    }
    return;
}

int main(){
    int n=20;zzz=0;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    int rowmask=0,ldmask=0,rdmask=0,row=0;
    solveBoard(board,row,rowmask,ldmask,rdmask);
    return 0;
}

// Ugh might just let this run up to 10000000 or 20000000 or 30000000 see what happens here is still just like ugh 1/1000th of the total overall cases I think... could maybe just try to run it until oblivion like 300000000... ugh yikes yikes yikes maybe check a different out case here could work like the other configuration.

#include <bits/stdc++.h>
using namespace std;
int zzz;
void solveBoard(vector<vector<bool>>& board,int row,int rowmask,int ldmask,int rdmask){
    int n=board.size();
    int all_rows_filled=(1<<n)-1;
    if(rowmask==all_rows_filled){
		/*
        vector<int> v;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board.size();j++){
                if(board[i][j])v.push_back(j);
            }
        }
		*/
        zzz++;
		if(zzz%100000==0)cout<<zzz<<endl;		

		//OKOKOK still a relatively slow program overall.

			vector<vector<int>> ccc(20,vector<int>(20));
			for(int a=0;a<20;a++){
				for(int b=0;b<20;b++){
					if(board[a][b]){
						for(int c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(int c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			vector<int> av(4);
			for(int a=0;a<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;a++){
				for(int b=0;b<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;b++){
					if(ccc[a][b]==0){
						int d=0;
						queue<pair<int,int>> aqp;
						vector<pair<int,int>> avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							pair<int,int> ap=aqp.front();
							avp.push_back(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>3)av[1]=16;
						else if(d==3){
							int e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=16;
							else av[3]++;
						}
						else av[d]++;
					}
				}
			}
			if(av[1]==15 and av[2]==4 and av[3]==1){
				for(int a=0;a<20;a++){
					for(int b=0;b<20;b++){
						cout<<board[a][b];
					}
					cout<<endl;
				}
			}

        return;
    }
    int safe=all_rows_filled&(~(rowmask|ldmask|rdmask));
    while(safe){
        int p=safe&(-safe);
        int col=(int)log2(p);
        board[row][col]=true;
        solveBoard(board,row+1,rowmask|p,(ldmask|p)<<1,(rdmask|p)>>1);
        safe=safe&(safe-1);
        board[row][col]=false;
    }
    return;
}

int main(){
    int n=20;zzz=0;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    int rowmask=0,ldmask=0,rdmask=0,row=0;
    solveBoard(board,row,rowmask,ldmask,rdmask);
    return 0;
}

// I dunno what I will do if this program hits like 30000000 and then fails ugh 1|1000th of the way there and like... could run it simply for 1 month at which point it still might Fail!

#include <bits/stdc++.h>
using namespace std;
int zzz;
void solveBoard(vector<vector<bool>>& board,int row,int rowmask,int ldmask,int rdmask){
    int n=board.size();
    int all_rows_filled=(1<<n)-1;
    if(rowmask==all_rows_filled){
		/*
        vector<int> v;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board.size();j++){
                if(board[i][j])v.push_back(j);
            }
        }
		*/
        zzz++;
		if(zzz%100000==0)cout<<zzz<<endl;		

		//OKOKOK still a relatively slow program overall.

			vector<vector<int>> ccc(20,vector<int>(20));
			for(int a=0;a<20;a++){
				for(int b=0;b<20;b++){
					if(board[a][b]){
						for(int c=-min(a,b);c<=min(19-a,19-b);c++)ccc[a+c][b+c]=1;
						for(int c=-min(a,19-b);c<=min(b,19-a);c++)ccc[a+c][b-c]=1;
					}
				}
			}
			vector<int> av(4);
			for(int a=0;a<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;a++){
				for(int b=0;b<20 and av[1]<=15 and av[2]<=4 and av[3]<=1;b++){
					if(ccc[a][b]==0){
						int d=0;
						queue<pair<int,int>> aqp;
						vector<pair<int,int>> avp;
						aqp.push({a,b});
						while(!aqp.empty()){
							d++;
							pair<int,int> ap=aqp.front();
							avp.push_back(ap);
							ccc[ap.first][ap.second]=1;
							aqp.pop();
							if(ap.first+1<20 and ccc[ap.first+1][ap.second]==0)aqp.push({ap.first+1,ap.second});
							if(ap.first+1<20 and ap.second+1<20 and ccc[ap.first+1][ap.second+1]==0)aqp.push({ap.first+1,ap.second+1});
							if(ap.second+1<20 and ccc[ap.first][ap.second+1]==0)aqp.push({ap.first,ap.second+1});
							if(ap.first-1>=0 and ap.second+1<20 and ccc[ap.first-1][ap.second+1]==0)aqp.push({ap.first-1,ap.second+1});
							if(ap.first-1>=0 and ccc[ap.first-1][ap.second]==0)aqp.push({ap.first-1,ap.second});
							if(ap.first-1>=0 and ap.second-1>=0 and ccc[ap.first-1][ap.second-1]==0)aqp.push({ap.first-1,ap.second-1});
							if(ap.second-1>=0 and ccc[ap.first][ap.second-1]==0)aqp.push({ap.first,ap.second-1});
							if(ap.first+1<20 and ap.second-1>=0 and ccc[ap.first+1][ap.second-1]==0)aqp.push({ap.first+1,ap.second-1});
						}
						if(d>3)av[1]=16;
						else if(d==3){
							int e=0;
							for(auto dude1:avp){
								for(auto dude2:avp){
									if(1==max(abs(dude1.first-dude2.first),abs(dude1.second-dude2.second)))e++;
								}
							}
							if(e!=3)av[1]=16;
							else av[3]++;
						}
						else av[d]++;
					}
				}
			}
			if(av[1]==15 and av[2]==4 and av[3]==1){
				for(int a=0;a<20;a++){
					for(int b=0;b<20;b++){
						cout<<board[a][b];
					}
					cout<<endl;
				}
			}

        return;
    }
    int safe=all_rows_filled&(~(rowmask|ldmask|rdmask));
    while(safe){
        int p=safe&(-safe);
        int col=(int)log2(p);
        board[row][col]=true;
        solveBoard(board,row+1,rowmask|p,(ldmask|p)<<1,(rdmask|p)>>1);
        safe=safe&(safe-1);
        board[row][col]=false;
    }
    return;
}

int main(){
    int n=20;zzz=0;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    int rowmask=0,ldmask=0,rdmask=0,row=0;
    solveBoard(board,row,rowmask,ldmask,rdmask);
    return 0;
}

// OKOKOK see what I do here might literally just quit this month's round don't think I will try pinging one of the solvers... I ought to note that in fact 25 solvers in the first 6 days would suggest that this is statistically one of the easier rounds out there and nevertheless I fail to AC it in the first 6 days hmmm... interesting dunno if there was some simple way to ad hoc it or prune the prune earlier somehow based around diagonals maybe maybe... in fact that is a good idea to try next I think somehow.