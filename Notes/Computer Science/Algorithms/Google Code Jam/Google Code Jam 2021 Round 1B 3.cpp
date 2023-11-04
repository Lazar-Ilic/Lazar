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
#define fo(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define fr(a,b,c) for((a)=(b);a>=(c);(a)--)
I p=1000000007;
//I p=998244353;

Z outv(V av){
    I a;
    out<<av[0];
    fo(a,1,sz(av)){
        out<<" "<<av[a];
    }
    out<<nl;
}

Z outvv(VV avv){
    I a,b;
    fo(a,0,sz(avv)){
        out<<avv[a][0];
        fo(b,1,sz(avv[a])){
            out<<" "<<avv[a][b];
        }
        out<<nl;
    }
}

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
    in>>al;
    y=0;
    for(d=0;d<a and y==0;d++){
        av.clear();
        for(e=0;e<b;e++){
            av.add(0);
        }
        h=-1;
        i=-1;
        j=0;
        for(e=0;e<b*c and y==0;e++){
            in>>f;
            if(f==-1){y=1;}
            if(f<8){
                if(j!=-1){
                    out<<j+1<<nl;
                    k=j;
                }
                else if(i!=-1){
                    out<<i+1<<nl;
                    k=i;
                }
                else{
                    out<<h+1<<nl;
                    k=h;
                }
            }
            else if(f==8){
                if(i!=-1){
                    out<<i+1<<nl;
                    k=i;
                }
                else if(j!=-1){
                    out<<j+1<<nl;
                    k=j;
                }
                else{
                    out<<h+1<<nl;
                    k=h;
                }
            }
            else if(f==9){
                if(h!=-1){
                    out<<h+1<<nl;
                    k=h;
                }
                else if(i!=-1){
                    out<<i+1<<nl;
                    k=i;
                }
                else{
                    out<<j+1<<nl;
                    k=j;
                }
            }
            av[k]=av[k]+1;
            if(av[k]==c){
                if(k+1<b and av[k+1]==c-1){
                    h=k+1;
                }
                else{
                    h=-1;
                }
            }
            else if(av[k]==c-1){
                if(h==-1){
                    h=k;
                }
                if(k+1<b and av[k+1]==c-2){
                    i=k+1;
                }
                else{
                    i=-1;
                }
                
            }
            else if(av[k]==c-2){
                if(i==-1){
                    i=k;
                }
                if(k+1<b){
                    j=k+1;
                }
                else{
                    j=-1;
                }
            }
        }
    }
    in>>z;
    exit(0);
}

I main(){
    ios_base::sync_with_stdio(0);
    in.tie(0);
    out.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("a.txt", "r", stdin);
        //freopen("b.txt", "w", stdout);
    #endif
    I a;
    a=1;
    //in>>a;
    I b=1;
    while(a--){
        //out<<"Case #"<<b<<": ";
        b++;
        solve();
    }
}