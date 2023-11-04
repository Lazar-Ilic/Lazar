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
	for(I a=0;a<sz(av);a++)out<<av[a]; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399

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
Of course the criterion immediately isomorphs into that of wondering which precise vertices can be the end of a directed Hamiltonian Path that is if we simply move perfectly along that path from "Losers To LASERs" e.g. from the Bottom to the Top. The poo poo deuces to the Pair Of Black Aces. The Jump to the Do Not Jump. The Jesus Is King to the Trill Music In zIOn. Anyways so we need to query at most 2n times to discover something about those potential Hamiltonian Paths. So ugh so ugh so ugh it is like immediately quite clear that we should be able to pass through for example in 1 phase of O[n] or n and discover some dude who beat more than half of the other dudes. I think that like frankly it is a very common theorem that any complete digraph contains a Hamiltonian Path. And so ugh errm is it not like that canonical classical task about like ugh if we could just end up considering for each dude like the set of dudes he beats if like one of those dudes beats someone in the set of dudes he loses to we can form maybe ugh a chain from the dudes he loses to through then through a chain in the dudes he beats up to him... or ugh maybe induction means if we can identify the candidate masters we need an additional 2 queries somehow so ugh if we knew the candidate masters from 1 dude and we are a new dude and we can beat any of those candidate masters ugh this immediately is good but ugh we might also introduce new candidate masters to the graph depending. Ugh anyone who can beat us and was a candidate master ugh I see. So if we can beat 0 of the previous candidate masters we certainly are a 0. Otherwise we are a 1 and in fact any dude that can beat us is also a 1. Ugh ugh ugh feels like this should be a totally routine and trivial task I mean uh ugh for sure it is like something super stupid simple I feel like. Looks like I would have been in for yet another Division 1 Top 500 if I had only decided to pull the trigger on this one Late Registration however I was writing up the code for D following C and had yet to drop A and B so I did not pull the trigger on that there decision. Uh OKOKOK so anyways let us crack this task here in round observing Claire Zhang there capiche badda boom on the task F imagine she could be my wifey girl friend maybe maybe maybe but I gotta crack this trivial E. Maybe it suffices to store like who can be on top and who can be on bottom at which point somehow like it will reduce into 2 very simple queries of a > 0 nature i.e. if we are beaten by any dude who could be on bottom then anyone who could be on top is still on top moving into this induction step. Oh wait if we are actually beaten by any 1 dude then we can move ugh OK so we need to know which dudes actually win 1 oh ugh OK no no no so any dude will appear at some point the previous chain so basically if we lose to even 1 dude then boom all the previous 1s stay 1s and frankly if we beat anyone of the previous 1s then we are also a 1 else not a 1. OK ugh so actually this is something sort of like this except we need to see if we form the new singleton strongly connected component or ugh OKOKOK I think actually what we do here is store the Strongly Connected Components decomposition break down and then can ugh like inductively deduce ugh but with the chain I feel like we can just toss in any dude from below at any point in time.
*/
	in>>a;
	if(a==1){
		out<<"! 1"<<nl;
		return;
	}
	av=V(a); // Can use VB instead later for better memory usage.
	as="";
	for(b=0;b<a;b++)as+='0';
	bs=as;
	bs[1]='1';
	out<<"? 1 "<<bs<<nl;
	in>>b;
	if(b==1)av[0]=1;
	else av[1]=0; // First 2 dudes are determined fixed who is on Top.
	for(b=2;b<a;b++){
		// Determine 3rd through ath inductively.
		bs=as;
		e=0;
		for(c=0;c<b;c++){
			if(av[c]==1){
				bs[c]='1';
				e++;
			}
		}
		out<<"? "<<b+1<<" "<<bs<<nl;
		in>>d;
		if(d>0){
			av[b]=1;
			// Now test ugh losers I think. Check the case we need to check that 3 is a winner who can lose to 2 e.g. means that then we would throw back in the 2 as the 2 can be kept out of any loser chain and then tossed in relevantly to beat us or whatever.
		}
		// Oh gee ugh if any loser beats us ugh. Strongly Connected Components. Ugh.
		
		/*
		bs=as;
		for(c=0;c<b;c++)bs[c]='1';
		out<<"? "<<b+1<<" "<<bs<<nl;
		in>>d;
		if(d==b){
			// Only possible winner here.
			av[b]=1;
			for(c=0;c<b;c++)av[c]=0;
		}
		else{
			bs=as;
			for(c=0;c<b;c++){
				if(av[c]==1)bs[c]='1';
			}
			out<<"? "<<b+1<<" "<<bs<<nl;
			in>>d;
			if(d>0)av[b]=1;
		}
		*/
	}
	out<<"! ";
	outv(av);
}

I main(){zz();I a=1;in>>a;while(a--){az();}}