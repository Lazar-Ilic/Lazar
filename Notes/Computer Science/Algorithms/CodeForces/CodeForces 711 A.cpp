#include <bits/stdc++.h>
using namespace std;
#define add push_back
#define remove pop_back
#define subsize __builtin_popcount
#define shuf random_shuffle
 
int main()
{
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
double ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md,nd,od,pd,qd,rd,sd,td,ud,vd,wd,xd,yd,zd;
long long al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml,nl,ol,pl,ql,rl,sl,tl,ul,vl,wl,xl,yl,zl;
string as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms,ns,os,ps,qs,rs,ss,ts,us,vs,ws,xs,ys,zs;
char ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc,nc,oc,pc,qc,rc,sc,tc,uc,vc,wc,xc,yc,zc;
vector<int> av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv,nv,ov,pv,qv,rv,sv,tv,uv,vv,wv,xv,yv,zv;
vector<double> avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd,nvd,ovd,pvd,qvd,rvd,svd,tvd,uvd,vvd,wvd,xvd,yvd,zvd;
vector<vector<int>> avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv,nvv,ovv,pvv,qvv,rvv,svv,tvv,uvv,vvv,wvv,xvv,yvv,zvv;
 
//freopen("a.txt", "r", stdin);
 
cin>>a;
for(int b=0;b<a;b++){
  cin>>al;
  c=0;
  while(c==0){
    bl=0;
    cl=al;
    while(cl!=0){
      bl+=cl%10;
      cl/=10;
    }
    if(gcd(al,bl)>1){
      cout<<al<<endl;
      c=1;
    }
    else{
      al++;
    }
  }
}
}