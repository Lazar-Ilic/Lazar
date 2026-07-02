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
using VV=vector<V>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVS=vector<VS>;
 
using SET=set<I>;
 
using MSET=multiset<I>;
 
using MSI=map<S,I>;
 
using MII=map<I,I>;
 
using DQ=deque<I>;
 
using ST=stack<I>;
 
using Q=queue<I>;
 
using PQ=priority_queue<I>;
 
using Z=void;
 
I p=1000000007;
 
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsize __builtin_popcount
#define shuf random_shuffle
#define fir first
#define sec second
#define mp make_pair
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define eb emplace_back 
#define rtn return
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
#define BT bitset
 
Z solve(){
    I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
    D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md,nd,od,pd,qd,rd,sd,td,ud,vd,wd,xd,yd,zd;
    L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml,nl,ol,pl,ql,rl,sl,tl,ul,vl,wl,xl,yl,zl;
    S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms,ns,os,ps,qs,rs,ss,ts,us,vs,ws,xs,ys,zs;
    C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc,nc,oc,pc,qc,rc,sc,tc,uc,vc,wc,xc,yc,zc;
    V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv,nv,ov,pv,qv,rv,sv,tv,uv,vv,wv,xv,yv,zv;
    VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd,nvd,ovd,pvd,qvd,rvd,svd,tvd,uvd,vvd,wvd,xvd,yvd,zvd;
    VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv,nvv,ovv,pvv,qvv,rvv,svv,tvv,uvv,vvv,wvv,xvv,yvv,zvv;
    VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs,nvs,ovs,pvs,qvs,rvs,svs,tvs,uvs,vvs,wvs,xvs,yvs,zvs;
 
    cin>>c>>as>>bs;
    cs="";
    ds="";
    d=0;//index
    e=0;//number of 0s since last
    f=0;//number of 1s since last
    g=0;//track consistent since last point
    h=-1;//track what consistent means
    while(d<c and g==0){
        if(as[d]=='0'){e++;}
        else{f++;}
        if(e+f==1){
            if(as[d]==bs[d]){h=0;}
            else{h=1;}
        }//first of new string
        else{
            if(as[d]==bs[d] and h==1 or as[d]!=bs[d] and h==0){//not consistent
                g=1;
            }
        }
        if(e==f){
            e=0;
            f=0;
        }
        d++;
    }
    if(g==1 or e+f!=0 and h==1){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
}
 
I main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("a.txt", "r", stdin);
        //freopen("b.txt", "w", stdout);
    #endif
    I te;
    cin>>te;
    while(te--){
        solve();
    }
}