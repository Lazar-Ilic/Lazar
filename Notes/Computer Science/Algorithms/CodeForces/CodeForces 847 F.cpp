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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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

 
const int MV = 200010;
const int ME = MV<<1;
const int LMV = 20;
const int inf = 1e8;
int N;
/*
int st[MV], en[ME], nxxxt[ME], dep[MV], up[MV][LMV], par[MV], dis[MV], down[MV];
bool check[MV], cut[ME];
*/
VV up;
V st, en, nxxxt, dep, par, dis, down;
VB check, cut;
 
void addedge(int s,int d,int c)
{
    nxxxt[c]=st[s];
    st[s]=c;
    en[c]=d;
}
 
void dfs(int x,int p)
{
    check[x]=down[x]=1;
    for(int i=st[x];i;i=nxxxt[i]){
        if(!check[en[i]] && !cut[i])up[en[i]][p] = up[x][p]+1, dfs(en[i],p), down[x]+=down[en[i]];
    }check[x]=0;
}
 
int find_mid(int x)
{
    int u = down[x]>>1, i;
    for(;;){
        for(i=st[x];i;i=nxxxt[i]){
            if(cut[i] || down[x]<down[en[i]])continue;
            if(down[en[i]]>u){x=en[i];break;}
        }
        if(!i)return x;
    }
}
 
void solve(int x,int pa)
{
    int r = find_mid(x);
    dep[r] = dep[pa]+1;
    par[r] = pa;
    dfs(r,dep[r]);
    for(int i=st[r];i;i=nxxxt[i]){
        if(cut[i])continue;
        cut[i] = cut[i^1] = 1;
        solve(en[i],r);
    }
}
 
void update(int x)
{
    for(int t=x;t;t=par[t])dis[t] = min(dis[t],up[x][dep[t]]);
}
 
int read(int x)
{
    int ret=inf;
    for(int t=x;t;t=par[t])ret=min(ret,dis[t]+up[x][dep[t]]);
    return ret;
}
 
void pre()
{
    dfs(1,0);
    solve(1,0);
    for(int i=1;i<=N;i++)dis[i]=inf;
    update(1);
}
 
int getInt()
{
    int t=0;
    char x=getchar();
    while(isdigit(x)){
        t=(t<<1)+(t<<3)+x-48;
        x=getchar();
    }
    return t;
}

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
The Nearest Colored Node in a Tree
Paweł Gawrychowski† Gad M. Landau‡ Shay Mozes§ Oren Weimann¶
Abstract
We start a systematic study of data structures for the nearest colored node problem on trees. Given a tree with colored nodes and weighted edges, we want to answer queries (v, c) asking for the nearest node to node v that has color c. This is a natural generalization of the well-known nearest marked ancestor problem. We give an O(n)-space O(log log n)-query solution and show that this is optimal. We also consider the dynamic case where updates can change a node's color and show that in O(n) space we can support both updates and queries in O(log n) time. We complement this by showing that O(polylog n) update time implies Ω( log n log log n) query time. Finally, we consider the case where updates can change the edges of the tree (link-cut operations). There is a known (top-tree based) solution that requires update time that is roughly linear in the number of colors. We show that this solution is probably optimal by showing that a strictly sublinear update time implies a strictly subcubic time algorithm for the classical all pairs shortest paths problem on a general graph. We also consider versions where the tree is rooted, and the query asks for the nearest ancestor/descendant of node v that has color c, and present efficient data structures for both variants in the static and the dynamic setting. Dedicated to Professor Costas S. Iliopoulos,on the occasion of his 60th birthday.

https://stackoverflow.com/questions/32937894/nearest-node-in-a-tree

https://en.wikipedia.org/wiki/Top_tree

https://codeforces.com/blog/entry/20719

https://codeforces.com/contest/342/problem/E
*/

/*
int st[MV], en[ME], nxxxt[ME], dep[MV], up[MV][LMV], par[MV], dis[MV], down[MV];
bool check[MV], cut[ME];
*/

	in>>n;
	N=n;
	up=VV(n+1,V(LMV));
	st=V(n+1);
	en=V(2*n+2);
	nxxxt=V(2*n+2);
	dep=V(n+1);
	par=V(n+1);
	dis=V(n+1);
	down=V(n+1);
	check=VB(n+1);
	cut=VB(2*n+2);
	I ansans=n;
	//out<<ansans<<nl;
	in>>c; // Swap node 1 and c internally.
	avv=VV(2*(n-1),V(2));
	for(I d=0;d<n-1;d++){
		in>>e;
		if(e==1){
			avv[2*d][0]=2;
			avv[2*d][1]=c;
			avv[2*d+1][0]=1;
			avv[2*d+1][1]=c;
		}
		else{
			avv[2*d][0]=2;
			avv[2*d][1]=e;
			avv[2*d+1][0]=1;
			avv[2*d+1][1]=e;
		}
	}
    for(i=1;i<n;i++){
        in>>x>>y;
		if(x==1)x=c;
		else if(x==c)x=1;
		if(y==1)y=c;
		else if(y==c)y=1;
        addedge(x,y,2*i);
        addedge(y,x,2*i+1);
    }
    pre();
	for(i=0;i<2*(n-1);i++)
    {
		//out<<dude[0]<<" "<dude[1]<<nl;
        int cmd=avv[i][0];
		x=avv[i][1];
		//out<<cmd<<" "<<x<<nl;
        if(cmd==1)update(x);
        else{
			ansans=min(ansans,read(x));
			out<<ansans<<" ";
		}
    }
	out<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}