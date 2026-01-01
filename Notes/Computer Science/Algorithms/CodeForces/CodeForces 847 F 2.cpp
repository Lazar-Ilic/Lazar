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

const int N=200005;
struct cd
{
    int lv,rv,ll,rr;
} a[N];
struct ab
{
    int f,t;
} t[N];
int h,hh[N],head[N],id[N],f[N],son[N],szzz[N],d[N],tot,ss[N],root[N],dis[N];
void make(int x,int y)
{
    t[++h].f=hh[x];
    t[h].t=y;
    hh[x]=h;
}
void dfs1(int x)
{
    szzz[x]=1;
    d[x]=d[f[x]]+1;
    for(int i=hh[x];i;i=t[i].f)
    {
        int j=t[i].t;
        if(j==f[x]) continue;
        f[j]=x;
        dfs1(j);
        szzz[x]+=szzz[j];
        if(szzz[son[x]]<szzz[j]) son[x]=j;
    }
}
void dfs2(int x,int y)
{
    head[x]=y;
    ss[y]++;
    id[x]=ss[y];
    if(!son[x]) return;
    dfs2(son[x],y);
    for(int i=hh[x];i;i=t[i].f)
    {
        int j=t[i].t;
        if(j==f[x]||j==son[x]) continue;
        dfs2(j,j);
    }
}
void pushup(int x)
{
    int l=a[x].ll,r=a[x].rr;
    a[x].lv=min(a[l].lv,a[r].lv);
    a[x].rv=min(a[l].rv,a[r].rv);
}
void build(int l,int r,int x)
{
    a[x].lv=1e9;
    a[x].rv=1e9;
    if(l==r) return;
    a[x].ll=++tot;
    a[x].rr=++tot;
    int mid=(l+r)>>1;
    build(l,mid,a[x].ll);
    build(mid+1,r,a[x].rr);
}
void add(int y,int z,int l,int r,int x,int sss)
{
    if(l==r)
    {
        a[x].lv=y+z-1;
        a[x].rv=sss-y+z;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=y) add(y,z,l,mid,a[x].ll,sss);
    else add(y,z,mid+1,r,a[x].rr,sss);
    pushup(x);
}
int que(int L,int R,int k,int l,int r,int x)
{
    int ans=1e9;
    if(L<=l&&R>=r)
    {
        if(k) return a[x].rv;
        return a[x].lv;
    }
    int mid=(l+r)>>1;
    if(L<=mid) ans=min(ans,que(L,R,k,l,mid,a[x].ll));
    if(R>mid) ans=min(ans,que(L,R,k,mid+1,r,a[x].rr));
    return ans;
}

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	//D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	//I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
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
	int n,ansans;
    scanf("%d%d",&n);
	ansans=n;
	I c,e;
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
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
		if(x==1)x=c;
		else if(x==c)x=1;
		if(y==1)y=c;
		else if(y==c)y=1;
        make(x,y);
        make(y,x);
    }
    dfs1(1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
        if(ss[i]!=1&&head[i]==i)
        {
            root[i]=++tot;
            build(1,ss[i],root[i]);
        }
    }
    add(1,0,1,ss[1],root[1],ss[1]);
    dis[1]=0;
    for(auto dude:avv)
    {
        int k,x;
        //scanf("%d%d",&k,&x);
		k=dude[0];
		x=dude[1];
        if(k==1)
        {
            for(int i=x;i;)
            {
                int tt=head[i];
                if(dis[i]>d[x]-d[i])
                {
                    dis[i]=d[x]-d[i];
                    if(ss[tt]>1) add(id[i],dis[i],1,ss[tt],root[tt],ss[tt]);
                }
                else break;
                i=f[tt];
            }
        }
        else
        {
            int ans=1e9;
            for(int i=x;i;)
            {
                int tt=head[i];
                if(ss[tt]==1) ans=min(ans,dis[i]+d[x]-d[i]);
                else
                {
                    ans=min(ans,que(1,id[i],1,1,ss[tt],root[tt])+id[i]-ss[tt]+d[x]-d[i]);
                    ans=min(ans,que(id[i],ss[tt],0,1,ss[tt],root[tt])+1-id[i]+d[x]-d[i]);
                }
                i=f[tt];
            }
			ansans=min(ansans,ans);
            //printf("%d\n",ans);
			out<<ansans<<" ";
        }
    }
	out<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}