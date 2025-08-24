// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
 
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

// Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals
// Time: O(log N)
// Usage: Node* tr=new Node(v,0,sz(v));
const L inf=1e18;
STR SGLZ{//Simon Lindholm
	SGLZ *l=0,*r=0;
	L lo,hi,ts=inf,ta=0,value=-inf; //ta toadd ts toset
	SGLZ(L lo,L hi):lo(lo),hi(hi){} // large interval of -inf
	SGLZ(VL& v,L lo,L hi):lo(lo),hi(hi){ // [lo,hi)
		if(lo+1<hi){
			L mid=lo+(hi-lo)/2;
			l=new SGLZ(v,lo,mid);r=new SGLZ(v,mid,hi);
			value=max(l->value,r->value); // associative
		}
		else value=v[lo];
	}
	L query(L a,L b){ // [a,b)
		if(b<=lo or hi<=a)return -inf;
		if(a<=lo and hi<=b)return value;
		push();
		return max(l->query(a,b),r->query(a,b));
	}
	Z set(L a,L b,L x){ // [a,b)
		if(b<=lo or hi<=a)return;
		if(a<=lo and hi<=b)ts=value=x,ta=0;
		else{
			push(),l->set(a,b,x),r->set(a,b,x);
			value=max(l->value,r->value);
		}
	}
	Z addto(L a,L b,L x){ // [a,b)
		if(b<=lo or hi<=a)return;
		if(a<=lo and hi<=b){
			if(ts!=inf)ts+=x;
			else ta+=x;
			value+=x;
		}
		else{
			push(),l->addto(a,b,x),r->addto(a,b,x);
			value=max(l->value,r->value);
		}
	}
	Z push(){
		if(!l){
			L mid=lo+(hi-lo)/2;
			l=new SGLZ(lo,mid);r=new SGLZ(mid,hi);
		}
		if(ts!=inf)
			l->set(lo,hi,ts),r->set(lo,hi,ts),ts=inf;
		else if(ta)
			l->addto(lo,hi,ta),r->addto(lo,hi,ta),ta=0;
	}
};

Z az(){
	I a,b,c,d,e,f;
	VL avl,bvl,cvl,dvl,evl;

	/*
	*/

	in>>a;
	avl=VL(a);
	bvl=VL(a);
	for(b=0;b<a;b++)in>>avl[b];
	for(b=0;b<a;b++)in>>bvl[b];
	if(a==1){
		out<<min(avl[0],bvl[0])<<nl;
		return;
	}
	// Ugh think up a new plan here would be like ugh I mean somehow to process the contributions in a different way like ugh somehow for each dude we need to ugh consider an n^2 matrix underlying all of this and take the ugh relevant column sums somehow shwooping through in a simple O[n log n] algorithm based around like a vector or whatever ugh. Something about sorting or prefix or suffix sums maybe. Could compute the partials and the completes separately and add at the end like the 20 dude dude range sums completely to the right ugh and ugh ugh ugh boom that works AC I think.

	cvl=VL(a+3,0); // Multiplicities.
	evl=VL(a,0); // Super additions.
	dvl=VL(a+1,0);
	//dvl[1]=bvl[0]; // Prefix Sums of bvl[s] umm 0, bvl[0], bvl[0]+bvl[1], ...
	for(b=1;b<=a;b++){
		dvl[b]=dvl[b-1]+bvl[b-1];
	}
	SGLZ * asglz = new SGLZ(cvl,0,a+2);
	for(b=0;b<a;b++){
		// Process the avl[b] dude.
		asglz -> addto(b,max(0,I(lowerbound(dvl.begin(),dvl.end(),avl[b]+dvl[b])-dvl.begin())-1),1);
		if(max(0,I(lowerbound(dvl.begin(),dvl.end(),avl[b]+dvl[b])-dvl.begin()-1))<a)evl[max(0,I(lowerbound(dvl.begin(),dvl.end(),avl[b]+dvl[b])-dvl.begin()-1))]+=avl[b]-(*(lowerbound(dvl.begin(),dvl.end(),avl[b]+dvl[b])-1)-dvl[b]);
	}
	for(b=0;b<a;b++)out<<bvl[b]*(asglz -> query(b,b+1))+evl[b]<<" ";
	out<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}