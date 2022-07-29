//%%writefile a.cpp

// https://github.com/Lazar-Ilic/Lazar/blob/main/Notes/Thoughts/Inanity.txt

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using U=uint64_t;
using LD=long double;
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
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
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
using VVB=vector<VB>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VSET=vector<SET>;
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
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
#define nextpermutation next_permutation
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
		//freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 433494437
//--------------------------------------------------------------------

I casecount=1;

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

	// I think it is wise to examine a multitude of kind of degenerate edge case graph structures and ensure that any proposed algorithm will nail all of those first and I think if one does that then one has a good shot to actually nail the task. Given that this is a task 5 of course the most naive of randomised algorithms will probably fail and so there is likely some threshold and mixed phase transitioned strategy type of approach which will work and succeed here. There could be an estimator based approach which does casework on say an underlying chotomy of graphs structures captured in some statistics.

	// Of course it is at this point in time that I begin to care to the degree of doing a little bit of literature trawling on sampling in graphs and networks to produce such estimators of various unbiased desiderata. Population graph, sampled graph. Randomised algorithms. Simple algorithms. From Rochester one obtains some Notes on the Horvitz-Thompson estimator.

	// These documents certainly contain many many many ideas and one of them is to simply do this and only count the edges which appear from both ends and then somehow do that but it might be tricky to compose an algorithm trying to capture information about the underlying P that an edge exists via that sort of a route walking around the graph a little bit clusters in very dense regions so...

	// Some mixture here somehow get some information about the average degree and then some further information about some set of edges just how the pairs of the degrees on their ends look statistically.

	// The actual N=100000 case seems worth considering it seems like the least informational case and my read on the task statement is that even disconnected subgraph regions are enabled so if there were some say 1 little K_a and a bunch of lonely singleton dudes it would be like degenerately uh there would be [a choose 2] edges and we pick in with probability [a/100000] so in this case actually there is a hmm somehow it is like I think if there exists like a K_50 or maybe like a K_100 or something like that then we actually goof up here we can easily misestimate here or mismodel the size of that particular dude so maybe we do need to somehow do a decomposition of our queries into sets to go query around a little bit or do a first phase capturing some information about high degree vertices and then explore a little bit more around those high degree vertices. In particular we want to nail estimates for very extremal graphs such as that one and the metric should be easier to hit the less extremal it is somehow so we really need to ensure to nail cases such as that one.

	// Certainly Estimating And Sampling Graphs With Multidimensional... B Ribeiro
	// Sampling Directed Graphs With Random Walks... B Ribeiro
	// Estimating Graph Parameters With Random Walks... A Ben-Hamou
	// A Survey And Taxonomy Of Graph Sampling... P Hu
	// Sampling From Large Graphs... J Leskovec
	// Coarse Grained Topology Estimation Via Graph Sampling... M Kurant
	// Graph Sampling
	// Estimating The Number Of s-t Paths In A Graph... B Roberts
	// Random Walks On Graphs: A Survey... L Lovasz
	// Well it would seem that Peter Winkler appears multiple times in this Lovasz survey paper and as reference 19 now this is terribly interesting because I have yet to read his academic bibliography in any context and so I must do that to be sure.

	// Adding "number of edges" to the query seems to improve results.

	// Comparison Of Random Walk Based Techniques For Estimating Network Averages

	// On Estimating The Average Degree - Dasgupta, Kumar, Sarlos

	// Provable And Practical Approximations For The Degree Distribution Using Sublinear Graph Samples

	// Goldreich Ron Should Work

	// I think this also appears in MIT Sublinear Time Algorithms 6.889 Lecture Notes

	// Snowball Sampling A Large Graph

	// Approximating Average Parameters Of Graphs

	// It really would seem to me that an actual implementation of this Double Count Big Small Edges algorithm ought to work here but I am not sure I actually have the time nor energy right now to do it and it is a real shame because I wanted the AC ace perfect PERFECT EZPZ here.

	// Well you do not always get what you want in life and you get lemons and limes and so on and so on and also the Google firm will provide the AC code as will the other users in public but I think this sublinear algorithms session right here was quite fruitful, productive, and educational. And it leaves me with much more further reading and general overview and exposition of this scene and territory!

	//out<<"Case #"<<casecount<<": "<<nl;
	casecount++;

	in>>a>>b;
	in>>d>>e;
	al=0;
	al+=e;
	for(c=1;c<=a;c++){
		if(c!=d)av.add(c);
	}
	random_shuffle(all(av));
	if(a-1<b){
		b=a-1;
		for(c=0;c<b;c++){
			// Process through all of the exchanges.
			// At room d which has e passages.
			// Can output T 5 for Teleport to Room 5
			// Can output W for Walk through random passage.
			out<<"T "<<av[c]<<nl;
			in>>d>>e;
			al+=e;
		}
		out<<"E "<<L(al*a/(b+1)/2)<<nl;
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}