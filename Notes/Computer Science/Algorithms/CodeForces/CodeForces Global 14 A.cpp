#include <bits/stdc++.h>  
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using LD=long double;
using S=string;
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
using SETL=set<L>;
using SETP=set<P>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MPI=map<P,I>;
using VMII=vector<MII>;
using UMSI=unordered_map<S,I>;
using UMII=unordered_map<I,I>;
using VUMII=vector<UMII>;
using DQ=deque<I>;
using ST=stack<I>;
using STP=stack<P>;
using Q=queue<I>;
using PQ=priority_queue<I>;
using VB=vector<B>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VL=vector<L>; 
using VLD=vector<LD>;
using VS=vector<S>;
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
using Z=void;
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsize __builtin_popcount
#define shuf random_shuffle
#define sz(x) int((x).size())
#define BT bitset
#define ba &
#define bo |
#define bx ^
#define bf ~
#define in cin
#define out cout
#define nl endl
I p=1000000007;
//I p=998244353;

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

/////////////////////////////////////////////////////////////////////////////


Z solve(){
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
    //B C D I L S P V VP VV SET USET MII UMII DQ Q PQ ST
    
    in>>a>>b;
    if(a==1){
        in>>c;
        if(c==b){out<<"NO"<<nl;}
        else{
            out<<"YES"<<nl;
            out<<c<<nl;
        }
    }
    else{
        e=0;
        for(c=0;c<a;c++){
            in>>d;
            av.add(d);
            e+=d;
        }
        if(e==b){out<<"NO"<<nl;}
        else{
            out<<"YES"<<nl;
            //produce av ordering
            sort(av.begin(),av.end());
            e=0;
            for(c=0;c<a;c++){
                //something with e put top once cleared
                e+=av[c];
                if(e==b){
                    //prefix sum hit it i think just swap 2
                    f=av[c];
                    av[c]=av[a-1];
                    av[a-1]=f;
                }
            }
            outv(av);
        }
    }
}

I main(){
    ios_base::sync_with_stdio(0);
    in.tie(0);
    out.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("a.txt", "r", stdin);
        //freopen("b.txt", "w", stdout);
    #endif
    I a;
    //a=1;
    in>>a;
    I b=1;
    while(a--){
        //out<<"Case #"<<b<<": ";
        b++;
        solve();
    }
}