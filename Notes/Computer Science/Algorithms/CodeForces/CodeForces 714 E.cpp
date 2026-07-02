#include <bits/stdc++.h>  
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using LD=long double;
using S=string;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using SETSET=set<SET>;
using MSI=map<S,I>;
using MII=map<I,I>;
using DQ=deque<I>;
using ST=stack<I>;
using Q=queue<I>;
using PQ=priority_queue<I>;
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
#define ba &
#define bo |
#define bx ^
#define bf ~
#define in cin
#define out cout
#define nl endl
I p=1000000007;
 
L inverse(I a){
    L b=1;
    L f=a;
    S c="111011100110101100101000000101";
    I d=sz(c);
    for(I e=d-1;e>=0;e--){
        if(c[e]=='1'){
            b=(b*f)%p;
        }
        f=(f*f)%p;
    }
    return (b+p)%p;
}
 
Z solve(){
    C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
    D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
    I a,b,c,d,e,f,g,h,i,j,k,l,m,n,q,r,s,t,u,v,w,x,y,z;
    L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
    S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
    V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
    VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
    VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
    VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
    //B C D I L S P V VP VV SET USET MSET MII DQ Q PQ ST
 
    in>>a;
    al=0;
    for(b=0;b<a;b++){
        in>>c;
        av.add(c);
        al+=c;
    }
    sort(av.begin(),av.end());
    if(al%a!=0){out<<0<<nl;}
    else{
        al/=a;
        g=al;
        d=0;//track avg
        e=0;//track less
        f=0;//track greater
        z=-1;//previous element track mult in bv
        for(b=0;b<a;b++){
            if(g==av[b]){d++;}
            else if(av[b]<g){e++;}
            else{f++;}
            if(av[b]==z){
                bv[sz(bv)-1]++;
            }
            else{
                bv.add(1);
                z=av[b];
            }
        }
        hl=1;
        if(d>0){
            for(b=a;b>(a-d);b--){
                hl=(hl*b)%p;
            }
        }
        if(e==1 or f==1){
            for(b=a-d;b>=1;b--){
                hl=(hl*b)%p;
            }
        }
        else if(e>1 and f>1){
            hl=(hl*2)%p;
            for(b=1;b<=e;b++){
                hl=(hl*b)%p;
            }
            for(b=1;b<=f;b++){
                hl=(hl*b)%p;
            }
        }
        for(b=0;b<sz(bv);b++){
            for(c=1;c<=bv[b];c++){
                hl=(hl*inverse(c))%p;
            }
        }
        out<<hl<<nl;
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
    a=1;
    //in>>a;
    I b=1;
    while(a--){
        //out<<"Case #"<<b<<": ";
        b++;
        solve();
    }
}