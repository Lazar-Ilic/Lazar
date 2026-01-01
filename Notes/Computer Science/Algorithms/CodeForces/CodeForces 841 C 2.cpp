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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399

//--------------------------------------------------------------------

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
const long long bsz = 316;
long long res = 0;
  
// Query structure
struct Query {
    long long l, r, q_idx, block_idx;
  
    Query() {}
    Query(long long _l, long long _r, long long _q_idx)
    {
        l = _l, r = _r, q_idx = _q_idx, block_idx = _l / bsz;
    }
  
    // We use operator overloading
    // to sort the queries
    bool operator<(const Query& y) const
    {
        if (block_idx != y.block_idx)
            return block_idx < y.block_idx;
        return r < y.r;
    }
};
  
Query queries[2000005];
unordered_map<long long, long long> cnt;
long long n, q, k;
long long xorr[2000005];
long long answer;
  
// Function to add elements while traversing
void add(long long u)
{
    long long y = xorr[u] ^ k;
  
    // We find the number of prefixes with value y
    // that are contributing to the answer,
    // add them to the answer
    res = res + cnt[y];
  
    // If we are performing add operation, and suppose
    // we are at index u then count of xorr[u]
    // will increase by 1 as we are adding
    // the answer to the list
    cnt[xorr[u]]++;
}
  
// Function to delete elements while traversing
void del(long long u)
{
    // If we are performing delete operation and suppose
    // we are at index u then count of xorr[u]
    // will decrease by 1 as we are removing
    // the answer from the list
    cnt[xorr[u]]--;
    long long y = xorr[u] ^ k;
  
    // We find the number of prefixes with value y
    // that was initially contributing to the answer
    // now we do not need them, hence subtract it from answer
    res = res - cnt[y];
}
  
// Here we are performing Mo's algorithm
// if you have no idea of it then go through here:
// https:// www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
void Mo()
{
    // first we sort the queries with block index, and ties are broken by less r value .
    sort(queries + 1, queries + q + 1);
    vector<long long> ans(q + 1);
    long long l = 1, r = 0;
    res = 0;
    cnt[0] = 1;
  
    // Iterate each query and check whether
    // we have to move the left and right pointer
    // to left or right
    for (long long i = 1; i <= q; ++i) {
  
        // If current right pointer r is less than
        // the rightmost index of the present query,
        // increment r
        while (r < queries[i].r) {
            ++r;
  
            // While incrementing we are adding new numbers
            // to our list. Hence, we modify our answer
            // for each r using add() function
            add(r);
        }
  
        // If current left pointer is greater than the
        // left most index of the present query, decrement l
        while (l > queries[i].l) {
            l--;
  
            // While decrementing l, we are again adding
            // new numbers to our list, hence we modify
            // our answer using add() function
            add(l - 1);
        }
  
        // Similarly, if current left pointer is less than
        // the left most index of the present query, increment l
        while (l < queries[i].l) {
  
            // While incrementing we are deleting elements
            // as we are moving right, hence we modify our answer
            // using del() function
            del(l - 1);
            ++l;
        }
  
        // If current right pointer is greater than the rightmost
        // index of the present query, decrement it
        while (r > queries[i].r) {
  
            // While decrementing, modify the answer
            del(r);
            --r;
        }
        ans[queries[i].q_idx] = res;
    }
    for (long long i = 1; i <= q; ++i) {
        //cout << ans[i] << endl;
		answer-=ans[i];
		//out<<ans[i]<<nl;
    }
}

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j;//,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
	V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
	P ap,bp,cp,dp,ep,fp,gp,hp,ip,jp,kp,lp,mp;
	VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
	//VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
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

	in>>a;
	//av=V(a);
	answer=L(a)*L(a+1)/2;
	//out<<answer<<nl;

	k = 0;
    vector<long long> v;
	v=VL(a+1);
	v[0]=0;
	for(b=0;b<a;b++)in>>v[b+1];
  
    // 1-based indexing
    n = v.size() + 1;
  
    xorr[1] = v[1];
    for (long long i = 2; i <= n; ++i)
        xorr[i] = xorr[i - 1] ^ v[i];
  
    // Queries
	for(b=0;b*b<=2*a;b++)queries[b+1]=Query(1,a,b*b);
	q=b;
	/*
    queries[1] = Query(1, 6, 1);
    queries[2] = Query(2, 4, 2);
    queries[3] = Query(2, 6, 3);
	*/
  
    Mo();
	out<<answer<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}