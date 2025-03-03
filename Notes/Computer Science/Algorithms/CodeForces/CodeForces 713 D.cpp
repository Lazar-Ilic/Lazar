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
    I secmax,max,isecmax,imax;
    L sum;
    secmax=0;
    max=0;
    isecmax=0;
    imax=0;
    sum=0;
    for(b=0;b<a+2;b++){
        in>>c;
        av.add(c);
        sum+=c;
        if(c>=max){
            secmax=max;
            max=c;
            isecmax=imax;
            imax=b;
        }
        else if(c>secmax){
            secmax=c;
            isecmax=b;
        }
    }
    c=0;
    for(b=0;b<a+2 and c==0;b++){
        if((sum-av[b]==2*max and b!=imax) or (sum-av[b]==2*secmax and b!=isecmax)){
            c=1;
            if(sum-av[b]==2*max and b!=imax){
                for(d=0;d<a+2;d++){
                    if(d!=imax and d!=b){
                        bv.add(av[d]);
                    }
                }
            }
            else{
                for(d=0;d<a+2;d++){
                    if(d!=isecmax and d!=b){
                        bv.add(av[d]);
                    }
                }
            }
            out<<bv[0];
            for(d=1;d<a;d++){
                out<<" "<<bv[d];
            }
            out<<nl;
        }
    }
    if(c==0){out<<-1<<nl;}
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
