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
using I=int; // 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
#define sortifyreverse(a) sort(all(a),greater<>())
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
	//out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:


Test+Additional Input:


[Worst-Case Runtime] Analysis:
OKOKOK time to write up a formalish analysis of the situation in round. So one cool insight here I am not sure I have seen before in Competitive Programming is the following. It is quite trivial to identify a root and Breadth First Search to give order to the tree structure. Then from there we can compute degrees quite easily. And then go through in level order identifying which ultimate parents for each subtree of all degree 3 vertices exist. At which point we can like Breadth First Search out from each of those to identify for each dude in its subtree that its ultimate parent on the tree was that subtree's root. So then checking if 2 dudes with degree 2 and an edge together have a path consisting of all degree 3s between them is as simple as computing their LCA and checking those subpaths have all degree 3 edges between them. But in fact this is even easier as this would logically imply that both dudes have the same ultimate deg3 ancestor parent and the reverse implication is also true. Also we may simply sum [deg2 neighbours of subtree choose 2] over each subtree because 2 pairs can not have 2 trees touching them as that would imply a cycle in the original graph which was a tree contradiction.
*/
	in>>a;
	VV graph(a,V(0));
	for(b=0;b<a-1;b++){
		in>>c>>d;c--;d--;
		avp.add({c,d});
		graph[c].add(d);
		graph[d].add(c);
	}
	vector<bool> processed(a,0);
	V distances(a,0);
	V parents(a,0);
	VV children(a,V(0));
	VV levels(a,V(0));
	levels[0].add(0);
	int root=0,aaa=0;
	aq.push(root);
	processed[root]=1;
	while(!aq.empty()){
		aaa=aq.front();
		aq.pop();
		for(auto neighbour:graph[aaa]){
			if(!processed[neighbour]){
				aq.push(neighbour);
				processed[neighbour]=1;
				children[aaa].add(neighbour);
				parents[neighbour]=aaa;
				distances[neighbour]=distances[aaa]+1;
				levels[distances[aaa]+1].add(neighbour);
			}
		}
	}
	V isneighbour(a,0);
	V ancestor(a,-1); // Works Here In Relevant Exclusion Case
	V neighbours(0);
	L neighbourcount=0;
	al=0;
	if(sz(children[0])==3){
				I rooter=0;
				aq.push(rooter);
				//ancestor[rooter]=rooter;
				while(!aq.empty()){
					c=aq.front();
					aq.pop();
					for(auto neighbour:children[c]){
						//ancestor[neighbour]=rooter;
						if(sz(children[neighbour])==2)aq.push(neighbour);
						else if(sz(children[neighbour])==1){
							if(!isneighbour[neighbour]){
								ancestor[neighbour]=rooter;
								isneighbour[neighbour]=1;
								neighbours.add(neighbour);
								neighbourcount++;
							}
						}
					}
				}
				al+=neighbourcount*(neighbourcount-1)/2;
				neighbourcount=0;
				//outv(isneighbour);
				for(auto neighbour:neighbours)isneighbour[neighbour]=0;
				neighbours=V(0);
	}
	for(b=1;b<a;b++){
		for(auto rooter:levels[b]){
			if(sz(children[rooter])==2 and ((parents[rooter]==0 and sz(children[0])!=3) or (parents[rooter]!=0 and sz(children[parents[rooter]])!=2))){
				// New rooter Of Subtree
				aq.push(rooter);
				//ancestor[rooter]=rooter;
				if((parents[rooter]==0 and sz(children[0])==2) or (parents[rooter]!=0 and sz(children[parents[rooter]])==1)){
					ancestor[parents[rooter]]=rooter;
					isneighbour[parents[rooter]]=1;
					neighbours.add(parents[rooter]);
					neighbourcount++;
				}
				while(!aq.empty()){
					c=aq.front();
					aq.pop();
					for(auto neighbour:children[c]){
						//ancestor[neighbour]=rooter;
						if(sz(children[neighbour])==2)aq.push(neighbour);
						else if(sz(children[neighbour])==1){
							if(!isneighbour[neighbour]){
								ancestor[neighbour]=rooter;
								isneighbour[neighbour]=1;
								neighbours.add(neighbour);
								neighbourcount++;
							}
						}
					}
				}
				al+=neighbourcount*(neighbourcount-1)/2;
				neighbourcount=0;
				//outv(isneighbour);
				for(auto neighbour:neighbours)isneighbour[neighbour]=0;
				neighbours=V(0);
			}
		}
	}
	for(auto dude:avp)if(((dude.first==0 and sz(children[dude.first])==2) or (dude.first!=0 and sz(children[dude.first])==1)) and ((dude.second==0 and sz(children[dude.second])==2) or (dude.second!=0 and sz(children[dude.second])==1)) and ancestor[dude.first]==ancestor[dude.second] and ancestor[dude.first]!=-1)al--;
	out<<al<<nl;
}

I main(){zz();I a=1;while(a--){az();}}