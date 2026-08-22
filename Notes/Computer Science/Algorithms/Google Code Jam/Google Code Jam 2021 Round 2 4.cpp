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
#define lcm(a,b) __detail::__lcm((a),(b))
#define gcd(a,b) __detail::__gcd((a),(b))
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsize __builtin_popcount
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a) ((a).begin()), ((a).end())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define BT bitset
#define ba &
#define bo |
#define bx ^
#define bf ~
#define in cin
#define out cout
#define nl endl
I p=1000000007; // 998244353 1000000007
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

B findmatch(I i, const VV &w, V &mr, V &mc, V &seen) {
  for (I j=0;j<sz(w[i]);j++){
    if (w[i][j] and !seen[j]){
      seen[j] = true;
      if (mc[j]<0 or findmatch(mc[j],w,mr,mc,seen)){
        mr[i]=j;
        mc[j]=i;
        return true;
      }
    }
  }
  return false;
}
I bipartitematching(const VV &w, V &mr, V &mc) {
  mr= V(sz(w),-1);
  mc= V(sz(w[0]),-1);
  I ct = 0;
  for(I i=0;i<sz(w);i++){
    V seen(w[0].size());
    if(findmatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
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
    
    in>>a>>b>>c>>d;
    for(e=0;e<a;e++){
        in>>as;
        avs.add(as);
    }
    for(e=0;e<a;e++){
        in>>as;
        bvs.add(as);
    }
    f=0;
    for(g=0;g<a;g++){
        for(h=0;h<b;h++){
            if(avs[g][h]!=bvs[g][h]){
                f++;
            }
        }
    }
    for(g=0;g<a*b;g++){
        av.add(0);
    }
    for(g=0;g<a*b;g++){
        avv.add(av);
    }
    for(g=0;g<a;g++){
        for(h=0;h<b-1;h++){
            if(avs[g][h]!=avs[g][h+1] and avs[g][h]!=bvs[g][h] and bvs[g][h]!=bvs[g][h+1]){
                avv[g*b+h][g*b+h+1]=1;
                avv[g*b+h+1][g*b+h]=1;
            }
        }
    }
    for(g=0;g<a-1;g++){
        for(h=0;h<b;h++){
            if(avs[g][h]!=avs[g+1][h] and avs[g][h]!=bvs[g][h] and bvs[g][h]!=bvs[g+1][h]){
                avv[g*b+h][g*b+h+b]=1;
                avv[g*b+h+b][g*b+h]=1;
            }
        }
    }
    out<<f-bipartitematching(avv,bv,cv)/2<<nl;
} 

I main(){
    ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("a.txt", "r", stdin);
    #endif
    I a=1;I b=1;in>>a;
    while(a--){out<<"Case #"<<b<<": ";b++;solve();}
}