// https://github.com/Lazar-Ilic/Lazar/blob/main/Notes/Thoughts/Inanity.txt

//%%writefile a.cpp
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

	out<<"Case #"<<casecount<<": ";
	casecount++;

	// This must be super duper canonical.
	// To be sure one either wants to somehow execute this into some like graph isomorphism task. Or simply note that the obvious naive greedy thing is like we want the bottom weight to be the one which maximally propagates down the chain and then literally the most naive iterated version of this should ace AC the Test Set 1. Like um maybe this isomorphs in fact into like a variant of the scheduling task where like there is some metaphor parable between rooms and rooms being allocated in a certain way to as to minimise the number of room scheduling sessions or something in some conference like some CSES type task or something. Scheduling tasks.
	// Wait actually like for each weight type it certainly breaks down into like in the first example case like it is just a bloop bloop sequence like:
	// 1 2 3 1
	// - - - -
	//   - -
	//     -
	// Which has broken down into these 3 chains and in particular we certainly need to add on for each chain and take off for each chain and the order does oh right OK yeah yeah the order in this break down does matter. But like of all the dudes who have a leftmost chain forced add on at time step 2 say we already removed all that needed to be removed then can we not simply add on those in the correct order based upon the time step they need to be removed by oh but yeah yeah a later dude gets forced to break down there. In any case still feel like we could simply isomorph this dude into like a sequence:
	// [0,3]
	// [1,2]
	// [2,2]
	// The index added and the index after which removed.
	// Do this for each dude and then process through this whole sequence of dudes like in some CSES tasks and uh when we are forced to pop a dude early we just pop it back into like the right dude with the new starting point of now and a ++ to the overall number of dudes which is *=2 at the end or whatever.
	// So in this example like:
	// 2 3
	// 1 2 1
	// 2 1 2
	// [1,2] [2,2]
	// [1,2] [1,1]
	// [1,2] [2,2]
	// And we actually just process here all the [1,2] dudes then put on the [1,1] dude and pop it off and pop on.

	in>>a>>b;
	VVP avvp;
	avvp=VVP(a,VP(0));
	avv=VV(a+1,V(b));
	for(c=0;c<a;c++){
		for(d=0;d<b;d++){
			in>>avv[c][d];
		}
	}

	for(d=0;d<b;d++){
		for(e=0;e<avv[0][d];e++){
			ast.push(0);
		}
		for(e=1;e<a+1;e++){
			// Process the delta between avv[e][d] and avv[e-1][d]
			if(avv[e][d]>avv[e-1][d]){
				for(f=avv[e-1][d]+1;f<=avv[e][d];f++){
					ast.push(e);
				}
			}
			else if(avv[e][d]<avv[e-1][d]){
				// Something to add this pair to avvp of the earlier dude.
				for(f=avv[e][d]+1;f<=avv[e-1][d];f++){
				g=ast.top();
				ast.pop();
				avvp[g].add({g,e-1});
				}
			}
		}
	}

	for(d=0;d<a;d++){
		sort(all(avvp[d]));
	}

	// Sort should have each internally in like ascending or whatever.

	// Just like process through this in the most meaningful way.

	z=0;
	STP astp;

	for(c=sz(avvp[0])-1;c>=0;c--){
		astp.push({avvp[0][c].second,avvp[0][c].first});
		z++;
	}
	for(d=1;d<a;d++){
		// First pop off all dudes that ended at time d-1 I guess.
		while(!astp.empty() and d-1==(astp.top()).first)astp.pop();
		for(c=sz(avvp[d])-1;c>=0;c--){
			// Process through the pair element avvp[d][c]
			// Oops tautologically definitionally by construction this has left bound [d,whatever] but it is whatever for this competitive programming round a little constant factor error does not matter.
			// Every time we push we add z++
			// Now I am second questioning myself about optimality here about what if we had A and a dudes it is always greedy to simply pop off and put back on like this or this super duper suboptimal should just leave on and pop off then off at that later point in time and then pop back on... think we split this new dude in that way think we actually add a pop back for this dude later now in a simulated way and so if a new dude needs to pop through 5 later really we add 1 push here if possible. But wait it needs to pop through each one each time maybe pop them all is fine.
			// Yikes it would appear that I am being a bit of a clown tonight goofing up this scheduling logic on how to optimally break down these pairs in such a way weigh that the weightlifting is optimal but I like the esthetics of the stack task statement and the topical topic of weightlifting of course funny sport really funny it might be taken out of the Olympics and so on and so on maybe one day they bring it back like deadlifting 1 shot event and then dudes with extremely high natural levels of like endogenous human growth hormone who eat a ton from Russia, just kidding, can win more Gold Medals...
			// I do not know in this sample input case 3 actually you want to be popping off the [0,1] dude and then pushing the 2*2=4 [1,2] dudes prior to pushing back a [1,1] dude. And that makes the 10 interval breakdown dudes.
			if(!astp.empty() and avvp[d][c].second>(astp.top()).first){
				astp.push({(astp.top()).first,avvp[d][c].first});
				out<< (astp.top()).first <<" "<< avvp[d][c].first <<nl;
				z++;
				avvp[(astp.top()).first].add({(astp.top()).first,avvp[d][c].second});
				/*
				avp.clear();
				while(!astp.empty() and avvp[d][c].second>(astp.top()).first){
					avp.add(astp.top());
					astp.pop();
				}
				sort(all(avp));
				// Put the new dude on who ends but then each push back.
				astp.push({avvp[d][c].second,avvp[d][c].first});
				z++;
				for(f=0;f<sz(avp);f++){
					astp.push({avp[f].first,avvp[d][c].first});
					z++;
				}
				*/
			}
			else{
				astp.push({avvp[d][c].second,avvp[d][c].first});
				out<< avvp[d][c].second <<" "<< avvp[d][c].first <<nl;
				z++;
			}
		}
	}
	out<<2*z<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}