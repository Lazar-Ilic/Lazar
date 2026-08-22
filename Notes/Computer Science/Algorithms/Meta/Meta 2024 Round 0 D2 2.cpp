// "We're living Ultralife"-Josephine Vander Gucht <3
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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

namespace treap{ // WARNING: NOT VERIFIED
	/*	QUERY TYPES:
	1. ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example,performing "ADD 2 4 1" on {1,2,3,4,5} results in {1,3,4,5,5}
	2. REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example,performing "REVERSE 2 4" on {1,2,3,4,5} results in {1,4,3,2,5}
	3. REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example,performing "REVOLVE 2 4 2" on {1,2,3,4,5} results in {1,3,4,2,5}
	4. INSERT x P: insert P after Ax. For example,performing "INSERT 2 4" on {1,2,3,4,5} results in {1,2,4,3,4,5}
	5. DELETE x: delete Ax. For example,performing "DELETE 2" on {1,2,3,4,5} results in {1,3,4,5}
	6. MIN x y: what is the minimum number in sub-sequence {Ax ... Ay}. For example,the correct answer to "MIN 2 4" on {1,2,3,4,5} is 2
	7. SUM x y: what is the sum of all numbers in sub-sequence {Ax...Ay}. For example,the answer to "SUM 3 5" on {1,2,3,4,5} is 12*/
	typedef int node;
	const int MAXN=300001,MAXS=2000000,NIL=0,oo=1000000000; // Can change to non const if needed with vectors for contrived tasks with ~100000 cases with sum of ns ~4000000 e.g.
	node lch[MAXS],rch[MAXS],root;
	int val[MAXS],//val[i]=value of array at corresponding index to node i
		cnt[MAXS],//cnt[i]=gets the number of nodes in the subtree rooted at node i
		rev[MAXS],//rev[i]=says if the node i is reversed
		acc[MAXS],//acc[i]=accumulated value for sum in all the subtree rooted at node i
		sum[MAXS],//sum[i]=gets the sum of values of all nodes in the subtree rooted at node i
		mim[MAXS],//mim[i]=gets the minimum value of all nodes in the subreee rooted at node i
		arr[MAXN],//arr[i]=value of initial array at index i
		sz;

	int random(){return rng();}

	void init(){sz=1;}

	void clear(){
		root=0;
		memset(lch,0,MAXS*sizeof(lch[0]));
		memset(rch,0,MAXS*sizeof(rch[0]));
		memset(val,0,MAXS*sizeof(val[0]));
		memset(cnt,0,MAXS*sizeof(cnt[0]));
		memset(rev,0,MAXS*sizeof(rev[0]));
		memset(acc,0,MAXS*sizeof(acc[0]));
		memset(sum,0,MAXS*sizeof(sum[0]));
		memset(mim,0,MAXS*sizeof(mim[0]));
		memset(arr,0,MAXN*sizeof(arr[0]));
	}

	int getCount(node t){return t!=NIL ? cnt[t]:0;}

	int getSum(node t){return t!=NIL ? sum[t]:0;}

	int getMin(node t){return t!= NIL ? mim[t]:oo;}

	void push(node t){
		if(t!=NIL){
			if(rev[t]){ // Reverse Query
				rev[t]=false;
				if(lch[t]!=NIL)rev[lch[t]] ^= 1;
				if(rch[t]!=NIL)rev[rch[t]] ^= 1;
				swap(lch[t],rch[t]);
			}
			if(acc[t]){ // Interval Sum Query
				val[t]+=acc[t];
				if(lch[t]!=NIL)acc[lch[t]]+=acc[t];
				if(rch[t]!=NIL)acc[rch[t]]+=acc[t];
				acc[t]=0;
			}
		}
	}

	void update(node t){
		if(t!=NIL){
			cnt[t]=getCount(lch[t])+getCount(rch[t])+1;
			sum[t]=getSum(lch[t])+getSum(rch[t])+val[t];
			int mc=min(getMin(lch[t]),getMin(rch[t]));
			mim[t]=min(mc,val[t]);
		}
	}

	node newNode(int v,node l,node r){
		assert(sz<MAXS);
		val[sz]=v;
		mim[sz]=v;
		lch[sz]=l;
		rch[sz]=r;
		update(sz);
		return sz++;
	}

	//WARNING: Call root=build(0,n-1)
	node build(int b,int e){
		if(b>e)return NIL;
		int m=(b+e)>>1;
		return newNode(arr[m],build(b,m-1),build(m+1,e));
	}

	void split(node t,node &l,node &r,int cnt){
		if(t==NIL)l=r=NIL;
		else{
			push(t);
			int tmp=getCount(lch[t]);
			if(tmp>=cnt){
				split(lch[t],l,lch[t],cnt);
				r=t;
			}
			else{
				split(rch[t],rch[t],r,cnt-tmp-1);
				l=t;
			}
			update(t);
		}
	}

	node merge(node l,node r){
		if(l==NIL||r==NIL)return l==NIL ? r:l;
		push(l);
		push(r);
		if(random()%(cnt[l]+cnt[r])<cnt[l]){
			rch[l]=merge(rch[l],r);
			update(l);
			return l;
		}
		lch[r]=merge(l,lch[r]);
		update(r);
		return r;
	}

	void insert(int idx,int val){
		if(idx>getCount(root))return;
		node n1,n2;
		split(root,n1,n2,idx);
		root=merge(n1,newNode(val,NIL,NIL));
		root=merge(root,n2);
	}

	void erase(int idx){
		if(getCount(root)<=idx)return;
		node n1,n2,n3;
		split(root,n1,n2,idx);
		split(n2,n2,n3,1);
		root=merge(n1,n3);
	}

	void reverse(int l,int r){
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		rev[n2]^=1;
		root=merge(n1,n2);
		root=merge(root,n3);
	}

	//Rotate arr[l...r] k times to the right(WARNING: TO THE RIGHT!!!)
	void rotate(int l,int r,int k){
		if(l>r)return;
		node n1,n2,n3,n4;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		k%=getCount(n2);
		split(n2,n2,n4,getCount(n2)-k);
		root=merge(n1,n4);
		root=merge(root,n2);
		root=merge(root,n3);
	}

	int sumquery(int l,int r){// WARNING: Check overflow in sum
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		int ans=getSum(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}

	void sumquery(int l,int r,int v){
		if(r<0)return;
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		acc[n2]+=v;
		root=merge(n1,n2);
		root=merge(root,n3);
	}

	int min_query(int l,int r){
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		int ans=getMin(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}
};

I testcase=0;

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,w,x,y,z;
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

/*
Post Contest Analysis:
I should probably find a new one here which enables a struct call so multiple treaps can be run at the same time with custom memory allocation to each treap expected size in the form of a vector.

Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/
	out<<"Case #"<<++testcase<<": ";
	in>>a>>b;
	treap::arr[0]=2000000;
	treap::init();
	treap::root=treap::build(0,0);
	for(c=0;c<a;c++){
		in>>d;
		l=0;
		r=c;
		while(l<r){
			m=(l+r)/2;
			if(treap::sumquery(m,m)-m-1>=d)r=m;
			else l=m+1;
		}
		treap::sumquery(0,l-1,-1);
		treap::insert(l,d+l);
		//out<<nl;
		//for(d=0;d<=c;d++)out<<treap::sumquery(d,d)<<nl;
	}
	l=0;
	r=a-1;
	if(treap::sumquery(r,r)<=b)l=r;
	else if(treap::sumquery(l,l)>=b)r=l;
	while(r-l>1){
		m=(l+r)/2;
		if(treap::sumquery(m,m)<b)l=m;
		else r=m;
	}
	if(abs(treap::sumquery(r,r)-b)<=abs(treap::sumquery(l,l)-b))out<<a-r<<" "<<abs(treap::sumquery(r,r)-b)<<nl;
	else out<<a-l<<" "<<abs(treap::sumquery(l,l)-b)<<nl;
	treap::clear();
}

int main(){zz();I a=1;in>>a;while(a--){az();}}