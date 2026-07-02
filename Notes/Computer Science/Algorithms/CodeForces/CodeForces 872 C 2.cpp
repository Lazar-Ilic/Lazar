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
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits = 16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
#define Lsubsetsize __builtin_popcountll
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
	//Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;
	MINPQ aminpq,bminpq,cminpq,dminpq,eminpq,fminpq,gminpq;

/*
Does greedy not uh work here like we uh firstly uh want to uh just note that uh all that is relevant is uh the distinct values at leaves I think and uh their relevant relative multiplicity in uh subtrees and uh then uh just shift off the uh overall root so that max of those are now fixed set to 0s so if ab initio is a uh 0 max then do not shift at all else can just shift and then induct uh Tree DP or whatever from that point on I think uh top down basically... is like uh range updating that uh tree or whatever or uh do we do this uh bottoms up basically uh... somehow compute the uh minimum number of operations needed to set all dudes uh equal on some level I think uh... reason quite carefully uh uh uh here is like uh obviously uh can just uh find values later I think uh using a uh linear uh equation or whatever think that for uh each uh well the actual values do uh matter you know min cost to hit what what what for each dude is like uh represent the uh compress a tree up 1 level basically the father of some set of downstream dudes is like uh what cost for which uh majority values is like uh relevant uh... if all were distinct could be like 4 values which each cost 3 to hit and neighbour same and so on and so on... if I solve here next 10 or so minutes can chime in else not uh. So OKOKOK so need to consider the majority in each such uh dude and then uh can still just like map map I think uh need to choose a uh majority in each uh group basically else shift up by 1 more is like uh... costs an additional uh 1 or whatever uh... so merging up is pretty simple majority majority majority using a uh map and a uh set of the precise relevant uh possible uh values uh by counting those with a map at each up merge. Can uh represent uh cost and uh majorities quite simply I think at each uh relevant uh up step maybe... delete old ones so as to not waste uh memory I think. Usual uh BFS works and then process back in terms of the order and uh uh uh I think uh clear out as we go yeah yeah yeah can store uh each uh dude majority as like a uh vector and a uh cost with a uh set so store the uh majority set and cost to hit majority so cost+1 is cost to hit non majority etc. and compute cost up to the top at which point out is like uh if 0 is in majority boom else cost+1 again. OK uh so fascinating task fascinating round frankly the epic Le Epic Fail on Task A and then the uh le epic Fail on Task C so I am back in to Division 2 regular for now and maybe one day will actually accurately adjudicate my own fake solves and legitimate onsights in round I uh thought today might be a smooth AB1C but no no no au contraire and so there is that and that is there I guess Yikes Yikes Yikes icy spicy dicey stuff really need some Division 2 ABCDEs I guess Yikes Yikeserino from 1 character away ugh Master ugh ugh ugh soon Enough I hope I suppose. Maybe somehow we can uh smooth out here the uh copying cases in the ugh uh uh uh up solve so that uh the only time we have to process is uh through actual ugh joints and like then we uh could somehow amortise the analysis so that the uh but then uh...

<>
 <>
  <>
   <>

Tree structure will still uh break the code program I think.

Oh ugh ugh errrm maybe it is trivial to execute these uh merges with like a uh leaf indicator on a uh uh uh like segment tree auxiliary to a flattened tree in order vector ugh ugh ugh.

OK so post facto analysis here off of ecnerwala and uh like uh Lingyu Jiang is that in a situation like this you can make it work pop pop by uh always uh using the underlying pointers in memory essentially to utilise the DSU Disjoint Set Union style memory handling approach here to not Exceed Time Limit and execute in O[n log n] rather than uh O[n^2] and uh OKOKOK so that is what I ought to have done here maybe I will uh come back to uh see like uh so in Lingyu Jiang's code see this is why a little ICPC Icky Picky practise is OK too but we can call default uh swap uh function I think when one executes the C++ Standard Library std::swap here to the uh underlying pointers in the uh like cvv set vectors here we can do it and get the amortised analysis O[n log n] asymptotic and I should onsight that here prior to even Exceeding Time Limit frankly and just AC this straight up bona fide ought to have ACed at least like AC today ACB1 or something ugh...
*/

	in>>a;
	av=V(a);
	for(b=0;b<a;b++)in>>av[b];
	avv=VV(a,V(0));
	bvv=VV(a,V(0)); // BFS level.
	//cvv=VV(a,V(0)); // Can store as uh vector like [cost,majority values...] ugh and ensure to uh store the values uh offset by the uh not including th current node's uh value I think uh.
	VPLS cvpls;
	for(b=0;b<a-1;b++){
		in>>c>>d;
		c--;d--;
		avv[c].add(d);
		avv[d].add(c);
	}
	vector<bool> processed(avv.size(),0);
	V distances(avv.size(),0);
	V parents(avv.size(),-1);
	VV children(a,V(0));
	queue<int> aq;
	int root=0;
	I aaa=0;
	aq.push(root);
	processed[root]=1;
	bvv[0].add(0);
	while(!aq.empty()){
		aaa=aq.front();
		aq.pop();
		for(auto neighbour:avv[aaa]){
			if(!processed[neighbour]){
				aq.push(neighbour);
				processed[neighbour]=1;
				distances[neighbour]=distances[aaa]+1;
				bvv[distances[aaa]+1].add(neighbour);
				parents[neighbour]=aaa;
				children[aaa].add(neighbour);
			}
		}
	}
	for(b=a-1;b>=0;b--){
		for(auto dude:bvv[b]){
			if(sz(children[dude])==0){
				SET lolset;
				lolset.insert(dude);
				cvpls[dude]={0,lolset};
			}
			else{
				m=0;
				n=-1;
				for(auto child:children[dude])if(sz(cvpls[child].second)>m){m=sz(cvpls[child].second);n=child;}
				SET lolset;
				y=1;
				for(auto child:children[dude]){
					if(child!=n and y){
						for(auto dude2:cvpls[child]){
							if((cvpls[n].second).count(dude2) or (lolset).count(dude2))y=0;
							else lolset.insert(dude2);
						}
					}
				}
				if(y){
					swap(cvpls[n],cvpls[dude]);
					for(auto dude2:cvpls[])
					for(auto child:children[dude]){
						if(child!=n){
							for(auto dude2:cvpls[child])(cvpls[dude].second).insert(dude2 bx av[dude]);
							cvpls[dude].first+=cvpls[child].first+1;
						}
					}
				}
				else{
					al=0;
					UMII majority;
					for(auto child:children[dude]){
						al+=cvpls[child].first+1;
						for(auto dude2:cvpls[child].second)majority[dude2]++;
						SET lolset;
						cvpls[child]={0,lolset};
					}
					I maxxx=0;
					for(auto lol:majority)if(lol.second>maxxx)maxxx=lol.second;
					cvpls[dude].first=al-maxxx;
					for(auto lol:majority)if(lol.second==maxxx)().insert(lol.first bx av[dude]);
				}
			}
		}
		if(b==0){
			for(auto dude:cvpls[0].second)if(dude==0){
				out<<cvpls[0].first<<nl;
				return;
			}
			out<<cvpls[0].first+1<<nl;
			return;
		}
	}
	return;
}

I main(){zz();I a=1;while(a--){az();}}