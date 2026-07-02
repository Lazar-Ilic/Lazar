// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

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
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=signed long long; // 32 bits = 4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=signed long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits = 16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using OSET=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
	out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:
Upon further review I think this solution is impossible or tricky to repair. In particular in this sort of scheme with offset oset there is still an issue in adversarial input. Say we have some dudes and keep on going past it. There is an issue with how to select the right values at insertion. And essentially the distance between 2 points can be exponentially decayed forced or whatever at which point this is not sharp. OK upon even further review there might be a way to sort of repair this sort of strategy... using 2 osets or maybe even 2 arrays uh with the proper kind of spacing techniques utilised so that whenever 2 dudes get too close together and we need to expand some delta we can go through in O[n] and produce a massive or big delta again and somehow monitour kind of smartly perhaps drop down runtime I can see a very possible way to drop runtime more in to maybe like an O[n^2/log[n]] type of runtime here maybe. Unclear. Would need to work out some details and think again about adversarial inputs. OKOKOK so I think there actually is a way to repair this solution sort of kind of new approach. The new approach has something like an ordered set of like pair<int,pair<int,int>> which represents like {leftmost index of chunk, {size of chunk, colour of chunk}}. OKOKOK not quite that but that sort of idea moves towards the right direction here which could be more like using a segment tree. OKOKOK no no no. So we would need more rigour and proof of any sort of expected O[n^2/log[n]] type asymptotic here with randomness to assist in dealing with adversaries like in particular ugh one might think we could maybe use ints or bitsets somehow and try to think about side by side compares which enable deeper with more memory but even repeatedly blowing up the gaps will not work well so a strategy where we basically spread the dudes out and then insert until a conflict at which point we re spread out in O[n] is doomed to fail basically that would also be uh O[n^2] with pretty mediocre constant factor to boot so... not sure.

https://codeforces.com/blog/entry/12285

Test + Additional Input:


[Worst-Case Runtime] Analysis:
Can try to simulate and store the relevant details in pairs of [location, index] and then have an auxiliary ordered set maybe of which prefix indices have been shifted downwards so that way querying it for order of and lower bound might work and then shifting along with it at the insertion index. OKOKOK and maybe an ordered set actually of the locations too with respect to the shift works. At the end we could actually binary search for the answer there then. OK actually maybe it is possible to simply do this with 1 ordered set and the given functions operations of that data structure. Ugh it has been a while since I practised Competitive Programming so I ought to prior to Round 2 and Round 3 to be sure. Oh never mind that was actually an OK idea here. And then I tank over an hour in to reading up on gcc g++ g++-12 and how to set up an Apple Macintosh machine for this purpose.
*/
	//out<<nl;
	in>>a>>b;
	OSET<P> aoset;
	LD ald;
	aoset.insert({20000000,0});
	OSET<pair<I,LD>> boset;
	boset.insert({20000000,0});
	for(c=0;c<a;c++){
		in>>d;
		if(((*aoset.findbyorder(0)).first)-(sz(boset)-1)>d)aoset.insert({d+sz(boset)-1,0});
		else{
			l=0;
			r=sz(aoset)-2;
			while(r>l){
				m=(l+r+1)/2;
				if(((*aoset.findbyorder(m)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(m))))-(m+1)>=d)r=m-1;
				else l=m;
			}
			y=d+l+1+(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound({*aoset.findbyorder(l+1)})));
			if((*boset.lowerbound({(*aoset.findbyorder(l))})).first==(*aoset.findbyorder(l)).first){
				x=1;
				while(x){
					al=rng()%10000000;
					bl=rng()%10000000;
					ald=LD(al)/10000000+LD(bl)/100000000000000;
					if((*boset.lowerbound({(*aoset.findbyorder(l)).first,(*aoset.findbyorder(l)).second+ald})).second!=(*aoset.findbyorder(l)).second+ald)x=0;
				}
				boset.insert({(*aoset.findbyorder(l)).first,(*aoset.findbyorder(l)).second+ald});
			}
			else boset.insert(*aoset.findbyorder(l));
			if((*aoset.lowerbound({y,0})).first!=y)aoset.insert({y,0});
			else{
				l=0;
				r=INT_MAX;
				while(l<r){
					m=(l+r+1)/2;
					if((*aoset.lowerbound({y,m})).first!=y)r=m-1;
					else l=m;
				}
				aoset.insert({y,l+1});
			}
		}
		//if(testcase<=11)for(z=0;z<=sz(aoset)-2;z++)out<<z<<" "<<((*aoset.findbyorder(z)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(z))))<<nl;
	}
	l=0;
	r=sz(aoset)-2;
	L distance;
	while(r-l>1){
		m=(l+r+1)/2;
		if(((*aoset.findbyorder(m)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(m))))>=b)r=m;
		else l=m;
	}
	if(((*aoset.findbyorder(r)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(r))))-b<=b-(((*aoset.findbyorder(l)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(l)))))){
		m=r;
		distance=((*aoset.findbyorder(r)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(r))))-b;
	}
	else{
		m=l;
		distance=b-(((*aoset.findbyorder(l)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(l)))));
	}
	l=0;
	r=sz(aoset)-2;
	if(((*aoset.findbyorder(l)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(l))))>=b){
		m=l;
		distance=(((*aoset.findbyorder(l)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(l)))))-b;
	}
	if(((*aoset.findbyorder(r)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(r))))<b){
		m=r;
		distance=b-(((*aoset.findbyorder(r)).first)-(boset.orderofkey({20000000,0})-boset.orderofkey(*boset.lowerbound(*aoset.findbyorder(r)))));
	}
	out<<a-m<<" "<<distance<<nl;
}

int main(){zz();I a=1;in>>a;while(a--){az();}}