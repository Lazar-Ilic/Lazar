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
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using UI=unsigned int;
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
using USETL=unordered_set<L>;
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
I p=1000000007; // 998244353 1000000007 1000000009 1000000000 433494437 993353399
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

	/* Note that the sets must encode pairs with sums or difference |y-x|
	Can multiplicity bash again only test out dudes who appear a bunch. */
	
	in>>a;
	UMLL aumll,bumll,cumll,dumll,eumll;
	avl=VL(a);
	bvl=VL(a);
	for(b=0;b<a;b++){
		in>>avl[b];
		if(bumll.count(avl[b])==0)bumll.insert({avl[b],1});
		else bumll[avl[b]]++;
		// Post Contest Analysis note is the right here one can actually effectively 1 linerise this and simply use the uh else statement's body here rather than an if else control flow.
	}
	for(b=0;b<a;b++){
		in>>bvl[b];
		if(cumll.count(bvl[b])==0)cumll.insert({bvl[b],1});
		else cumll[bvl[b]]++;
	}
	sort(all(avl));
	sort(all(bvl));
	for(L dude1:avl){
		for(L dude2:bvl){
			if(aumll.count(abs(dude2-dude1))==0)aumll.insert({abs(dude2-dude1),1});
			else aumll[abs(dude2-dude1)]++;
			if(aumll.count(dude2+dude1)==0)aumll.insert({dude2+dude1,1});
			else aumll[dude2+dude1]++;
		}
	}
	if(avl==bvl){
		out<<"YES"<<nl;
		for(L dude:bvl)out<<dude<<" ";
		out<<nl<<0<<" "<<0<<nl;
		return;
	}
	for(auto const& xxx:aumll){
		if(xxx.second>=a){
			z=1;
			al=xxx.first;
			// Test if this works. Greater forces pairs out yeah yeah.
			// So process through from the back ends of avl and bvl.
			// Pretend that uh Left is at 0 and Right is at al I guess.
			// Then shift at the end everything Rightward I guess works.
			dumll=bumll;
			eumll=cumll;
			cvl=VL(0);
			e=sz(avl)-1;
			f=sz(bvl)-1;
			while((e>=0 or f>=0) and z and (avl[e]>al or bvl[f]>al)){
				if((e>=0 and f>=0) and avl[e]>bvl[f]){
					if(dumll.count(avl[e])>0 and dumll[avl[e]]>0 and eumll.count(avl[e]-al)>0 and eumll[avl[e]-al]>0){
						cvl.add(avl[e]);
						dumll[avl[e]]--;
						eumll[avl[e]-al]--;
					}
					else z=0;
					if(avl[e]-al==bvl[f])f--;
					e--;
				}
				else{
					if(dumll.count(bvl[f]-al)>0 and dumll[bvl[f]-al]>0 and eumll.count(bvl[f])>0 and eumll[bvl[f]]>0){
						cvl.add(al-bvl[f]);
						dumll[bvl[f]-al]--;
						eumll[bvl[f]]--;
					}
					else z=0;
					if(avl[e]==bvl[f]-al)e--;
					f--;
				}
			}
			for(auto const& yyy:dumll){ // Can optimise further.
				if(yyy.second>0){
					// Remove all pairs boom multiplicity.
					if(eumll.count(al-yyy.first)>0 and yyy.second==eumll[al-yyy.first]){
						for(f=0;f<yyy.second;f++)cvl.add(yyy.first);
					}
					else z=0;
				}
			}
			if(z){
				// Done and print and return.
				out<<"YES"<<nl;
				sort(all(cvl));
				dl=0; // Add to all.
				if(cvl[0]<0)dl=-cvl[0];
				for(L dude:cvl)out<<dude+dl<<" ";
				out<<nl;
				out<<dl<<" "<<dl+al<<nl;
				return;
			}
		}
	}
	out<<"NO"<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}