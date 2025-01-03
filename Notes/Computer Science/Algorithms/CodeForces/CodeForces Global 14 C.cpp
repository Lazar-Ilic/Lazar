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
using SETV=set<V>;
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

///////////////////////////////////////////////////////////////////

L factorials[1000000];
I factorialsmax;
L factorial(L al){
    L bl;
    factorials[0]=1;
    if(al<=factorialsmax){
        return factorials[al];
    }
    else{
        for(bl=factorialsmax+1;bl<=al;bl++){
            factorials[bl]=factorials[bl-1]*bl%p;
        }
        factorialsmax=al;
        return factorials[al];
    }
}
L inverse(L al){
    L bl=1;
    I a=p-2;
    while(a!=0){
        if(a%2==1){
            bl=bl*al%p;
        }
        al=al*al%p;
        a/=2;
    }
    return bl;
}
L choose(L al,L bl){
    return factorial(al)*inverse(factorial(bl))%p*inverse(factorial(al-bl))%p;
}
L exp(L al,L bl){
    L cl=1;
    while(bl>0){
        if(bl%2==1){
            cl=cl*al%p;
        }
        al=al*al%p;
        bl/=2;
    }
    return cl;
}
L chose[1000][1000];
Z precomputechose(I a){
    I b,c;
    chose[0][0]=1;
    for(b=1;b<=a;b++){
        chose[b][0]=1;
        for(c=1;c<=b;c++){
            chose[b][c]=(chose[b-1][c-1]+chose[b-1][c])%p;
        }
    }
}
L achose[10000];
Z precomputeachose(L al){
    L bl,cl;
    achose[0]=1;
    achose[al]=1;
    for(bl=1;bl<=(al/2);bl++){
        cl=achose[bl-1]*(al+1-bl)*inverse(bl)%p;
        achose[bl]=cl;
        achose[al-bl]=cl;
    }
}
L inverses[1000000];
Z precomputeinverses(L al){
    I a;
    inverses[1]=1;
    for(a=2;a<al;a++){
        inverses[a]=al-(al/a)*inverses[al%a]%al;
    }
}
//L factorial(L al)
//L inverse(L al)
//L choose(L al,L bl)
//L exp(L la,L bl)  
//Z precomputechose(I a)
//Z precomputeachose(L al)
//Z precomputeinverses(L al)

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
    
    in>>a>>b>>c;
    for(d=0;d<a;d++){
        in>>e;
        avv.add({e,d});
        av.add(0);
    }
    sort(avv.begin(),avv.end());
    SETV aset;
    for(d=1;d<=b;d++){
        aset.insert({avv[a-d][0],d});
        av[avv[a-d][1]]=d;
    }
    for(d=a-b-1;d>=0;d--){
        aset.insert({(*aset.begin())[0]+avv[d][0],(*aset.begin())[1]});
        av[avv[d][1]]=(*aset.begin())[1];
        aset.erase(aset.begin());
    }
 
    if((*aset.begin())[0]+c>=(*aset.rbegin())[0]){
        out<<"YES"<<nl;
        outv(av);
    }
    else{out<<"NO"<<nl;}
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