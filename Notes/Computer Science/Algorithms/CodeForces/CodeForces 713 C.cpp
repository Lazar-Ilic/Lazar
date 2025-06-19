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
 
    in>>a>>b;
    in>>as;
    c=0;//counter for 0s
    d=0;//counter for 1s
    e=0;//change to 1 if invalid
    for(f=0;f<a+b;f++){
        if((as[f]=='1' and as[a+b-1-f]=='0') or (as[f]=='0' and as[a+b-1-f]=='1')){
            e=1;
        }
        if((as[f]=='?' and as[a+b-1-f]!='?') or (as[f]!='?' and as[a+b-1-f]=='?')){
            if(as[f]=='?'){as[f]=as[a+b-1-f];}
            else{as[a+b-1-f]=as[f];}
        }
        if(as[f]=='0'){c++;}
        if(as[f]=='1'){d++;}
    }
    if(e==1){
        out<<-1<<nl;
    }
    else if(c>a or d>b or (a%2==1 and b%2==1) or ((a-c)%2==1 and (b-d)%2==1)){
        out<<-1<<nl;
    }
    else{
        for(f=0;f<a+b;f++){
            if(as[f]=='?'){
                if(c+2<=a){
                    as[f]='0';
                    as[a+b-1-f]='0';
                    c+=2;
                }
                else if(d+2<=b){
                    as[f]='1';
                    as[a+b-1-f]='1';
                    d+=2;
                }
            }
        }
        if(as[(a+b)/2]=='?'){
            if(c<a){as[(a+b)/2]='0';}
            else{as[(a+b)/2]='1';}
        }
        out<<as<<nl;
    }
}