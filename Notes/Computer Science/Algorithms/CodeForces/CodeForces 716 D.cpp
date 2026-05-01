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
 
Z mos(V av,VP avp){
    I a,b,c,d,l,r,m;
    VP bvp;
    bvp=avp;
    a=sz(av);
    b=int(pow(a,0.5));
    VVP avvp(a/b+1);
    sort(bvp.begin(),bvp.end());
    for(c=0;c<sz(bvp);c++){
        avvp[bvp[c].first/b].add({bvp[c].second,bvp[c].first});
    }
    for(c=0;c<a/b+1;c++){
        sort(avvp[c].begin(),avvp[c].end());
    }
    bvp.clear();
    for(c=0;c<a/b+1;c++){
        if(sz(avvp[c])>0){
            for(d=0;d<sz(avvp[c]);d++){
                bvp.add({avvp[c][d].second,avvp[c][d].first});
            }
        }
    }
    MPI output;
    l=-1;
    r=-1;
    m=0;
    V freq(a,0);
    V freqmult(2*a+1,0);
    freqmult[a+0]=a+1;
    for(c=0;c<sz(bvp);c++){
        if(l<bvp[c].first-1){
            while(l<bvp[c].first-1){
                l++;
                freqmult[a+freq[av[l]]]--;
                freqmult[a+freq[av[l]]-1]++;
                if(m==freq[av[l]] and freqmult[a+freq[av[l]]]==0){m--;}
                freq[av[l]]--;
            }
        }
        else if(l>bvp[c].first-1){
            while(l>bvp[c].first-1){
                freqmult[a+freq[av[l]]]--;
                freqmult[a+freq[av[l]]+1]++;
                if(m==freq[av[l]]){m++;}
                freq[av[l]]++;
                l--;
            }
        }
        if(r<bvp[c].second){
            while(r<bvp[c].second){
                r++;
                freqmult[a+freq[av[r]]]--;
                freqmult[a+freq[av[r]]+1]++;
                if(m==freq[av[r]]){m++;}
                freq[av[r]]++;
            }
        }
        else if(r>bvp[c].second){
            while(r>bvp[c].second){
                freqmult[a+freq[av[r]]]--;
                freqmult[a+freq[av[r]]-1]++;
                if(m==freq[av[r]] and freqmult[a+freq[av[r]]]==0){m--;}
                freq[av[r]]--;
                r--;
            }
        }
        if(2*m-(r-l)>1){output.insert({bvp[c],2*m-(r-l)});}
        else{output.insert({bvp[c],1});};
    }
    for(c=0;c<sz(avp);c++){
        out<<output[avp[c]]<<nl;
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
    //B C D I L S P V VP VV SET USET MSET MII UMII DQ Q PQ ST
 
    in>>a>>b;
    av.add(0);
    for(c=0;c<a;c++){
        in>>d;
        av.add(d);
    }
    for(c=0;c<b;c++){
        in>>d>>e;
        avp.add({d,e});
    }
    mos(av,avp);
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