//%%writefile a.cpp
 
/*

"
LASER, Gold Medalists are my role models.
"
- Wasalu Muhammad Jaco, Drogas [Losers To] Light 光 LASERs

"
Exploring other fields like maths and physics.
"
- Claire Zhang :) <3

https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

*/
 
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

//--------------------------------------------------------------------

struct SCC{//Benjamin Qi
	I size;
    VV adj, radj;
	V todo, components, componentof;
    VB visited;
	Z build(I a){
        size=a;
        adj=VV(size,V(0));
        radj=VV(size,V(0));
        componentof=V(size,-1);
        visited=VB(size);
	}
	Z addedge(I a,I b){
        adj[a].add(b);
        radj[b].add(a);
    }
	Z dfs(I a){
		visited[a]=1;
        for(auto ay:adj[a]){
            if(!visited[ay])dfs(ay);
        }
        todo.add(a);
    }
	Z dfs2(I a,I b){
		componentof[a]=b;
        for(auto ay:radj[a]){
            if(componentof[ay]==-1)dfs2(ay,b);
        }
	}
	Z generate(I a){
        I b;
        for(b=0;b<=a;b++){
            if(!visited[b])dfs(b);
        }
        reverse(all(todo));
        for(auto ay:todo){
            if(componentof[ay]==-1){
                dfs2(ay,ay);
                components.add(ay);
            }
        }
	}
};

// Description: Topological sorting. Given is an oriented graph. Output is an ordering of vertices, such that there are edges only from left to right. If there are cycles, the returned list will have size smaller than $n$ -- nodes reachable from cycles will not be returned.
// Time: O(E+V)
V topsort(const VV& graph){
	V indegree(sz(graph)),ret;
	for(auto& li:graph)for(I x:li)indegree[x]++;
	Q q; // use priority_queue for lexicographically largest answer
	rep(i,0,sz(graph)) if (indegree[i] == 0) q.push(i);
	while(!q.empty()){
		I i=q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for(I x:graph[i])
			if(--indegree[x]==0)q.push(x);
	}
	return ret;
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
Classical canonical puzzle obviously ugh I guess for each rose we are supposed to compute if it is free on energy or else its minimum energy cost and then simply sort on energies and add up energies until we overflow or hit the end I guess ugh.

OKOKOK so I made an error last night which is terribly cringey in round my brain organ memory was flawed re the Quanta Magazine Puzzles task on this precise topic but in round one can certainly run a literal functional derivative test to check it the unimodal maximum or whatever takes on a value that is > 0 representing a viable escape on the underlying theta angle function of escape velocity or you can run a trinary search for the unimodal maximum approximation on that underlying with a break in the loop once a value of > 0 is attained or you can manually hand examine this structure and program in that derivative computation for an O[1] query to the unimodal maximum on the underlying structure here or whatever to actually formally ping out the unimodal maximum as needed here, carefully reading the task statement quite clearly, technically, and precisely.

https://www.quantamagazine.org/can-math-help-you-escape-a-hungry-bear-20210629/
*/

	in>>a>>b;
	LD pipi=3.141592653589793238462643383279502884L;
	for(c=0;c<a;c++){
		in>>ad>>bd;
		if(bd>=pipi and bd<pipi+1.0)av.add(3);
		else if(bd<pipi)av.add(0);
	}
	sort(all(av));
	z=0;
	for(c=0;c<sz(av) and z+av[c]<=b;c++)z+=av[c];
	out<<min(a,c+1)<<nl;

	// UGH

	in>>a>>b;
	z=0;
	y=1;
	b/=3;
	LD ald,bld;
	LD pipi=3.141592653589793238462643383279502884L;
	LD eeee=2.718281828459045235360287471352662497L;
	for(c=0;c<a;c++){
		in>>ald>>bld;
		//out<<ald<<" "<<bld<<" "<<(ald-eeee)*bld<<" "<<ald*pipi<<" "<<b<<nl;
		if(bld>=pipi and (ald-eeee)*bld<ald*pipi and b>0){
			b--;
			z++;
		}
		else if(bld<pipi)z++;
		else if(y>0){
			y=0;
			z++;
		}
	}
	out<<z<<nl;
}

I main(){zz();I a=1;while(a--){az();}}