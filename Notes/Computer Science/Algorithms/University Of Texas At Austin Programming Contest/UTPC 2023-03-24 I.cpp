#include <bits/stdc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using LD=long double;
using S=string;
using U=uint64_t;
using PB=pair<B,B>;
using PC=pair<C,C>;
using PD=pair<D,D>;
using P=pair<I,I>;
using PL=pair<L,L>;
using PLD=pair<LD,LD>;
using PS=pair<S,S>;
using PIS=pair<I,S>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETP=set<P>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MLI=map<L,I>;
using MLL=map<L,L>;
using MPI=map<P,I>;
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
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using MIV=map<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using Z=void;
#define MHI map<H,I>
#define UMHI unordered_map<H,I>
#define PTL PT<L>
#define PTD PT<D>
#define VH vector<H>
#define VPTL vector<PTL>
#define VPTD vector<PTD>
#define orderofkey order_of_key
#define findbyorder find_by_order
#define lowerbound lower_bound
#define upperbound upper_bound
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsize __builtin_popcount
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
const I p=1000000007; // 998244353 1000000007
Z outv(V av){
	I a;
	out<<av[0];
	for(a=1;a<sz(av);a++){
		out<<" "<<av[a];
	}
	out<<nl;
}
Z outvv(VV avv){
	I a,b;
	for(a=0;a<sz(avv);a++){
		out<<avv[a][0];
		for(b=1;b<sz(avv[a]);b++){
			out<<" "<<avv[a][b];
		}
		out<<nl;
	}
}
//--------------------------------------------------------------------
 
STR edge{
    I u,v;L capacity,cost;
    edge(I u,I v,L capacity,L cost): u(u),v(v),capacity(capacity),cost(cost){}
}; 
STR MCMF{
    I n, s, t;
    L flow, cost;
    VV graph;
    vector<edge> e;
    VL distance;
    V parent;
    MCMF(I nn){
        n=nn;
        graph.assign(n, V ());
    }
    Z addedge(I u,I v,L capacity,L cost,B directed = true){
        graph[u].push_back(e.size());
        e.push_back(edge(u, v, capacity, cost));
        graph[v].push_back(e.size());
        e.push_back(edge(v, u, 0, -cost));
        if(!directed)addedge(v, u, capacity, cost, true);
    }
    PL generate(I _s, I _t){
        s = _s; t = _t;
        flow = 0, cost = 0;
        while(SPFA()){
            flow += sendFlow(t, 1LL<<62);
        }
        return make_pair(flow, cost);
    }
    B SPFA(){
        parent.assign(n, -1);
        distance.assign(n, 1LL<<62);        distance[s] = 0;
        V queuetime(n, 0);    queuetime[s] = 1;
        VB inqueue(n, 0);     inqueue[s] = true;
        Q q;                   q.push(s);
        B negativecycle = false;
        while(!q.empty() && !negativecycle){
            I u = q.front(); q.pop(); inqueue[u] = false;
            for(I i = 0; i < graph[u].size(); i++){
                I eIdx = graph[u][i];
                I v = e[eIdx].v; L w = e[eIdx].cost, capacity = e[eIdx].capacity;
                if(distance[u] + w < distance[v] && capacity > 0){
                    distance[v] = distance[u] + w;
                    parent[v] = eIdx;
                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;
                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        }
        return distance[t] != (1LL<<62);
    }
    L sendFlow(I v, L curFlow){
        if(parent[v] == -1)
            return curFlow;
        I eIdx = parent[v];
        I u = e[eIdx].u; L w = e[eIdx].cost;
        L f = sendFlow(u, min(curFlow, e[eIdx].capacity));
        cost += f*w;
        e[eIdx].capacity -= f;
        e[eIdx^1].capacity += f;
        return f;
    }
};
 
Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
	V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
	VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
	VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
	VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
	VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
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
	Obviously this is trivially canonical isomorphism with an extremely well-studied isomorphism in the Minimum Cost Maximum Flow literature known as Suurballe's Algorithm...

	https://en.wikipedia.org/wiki/Suurballe%27s_algorithm

	https://lists.boost.org/boost-bugs/2017/09/48841.php

	https://github.com/bekaus/lemon-1.2.1/blob/master/lemon/suurballe.h
	*/
	
	in>>a>>b;
	c=2;
	MCMF amax(a+1);
	amax.addedge(0,1,c,0);
	for(d=0;d<b;d++){
		in>>e>>f>>h;
		g=1;
		amax.addedge(e,f,g,h);
	}
	PL apl=amax.generate(0,a);
	if(apl.first!=c){
		out<<-1<<nl;
		return;
	}
	else out<<apl.second<<nl;
}
 
I main(){
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	I a=1;//in>>a;
	while(a--){az();}
}