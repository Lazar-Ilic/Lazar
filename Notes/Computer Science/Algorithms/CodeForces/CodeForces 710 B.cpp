#include <bits/stdc++.h>
using namespace std;
#define add push_back
#define remove pop_back
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    double ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md,nd,od,pd,qd,rd,sd,td,ud,vd,wd,xd,yd,zd;
    long long al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml,nl,ol,pl,ql,rl,sl,tl,ul,vl,wl,xl,yl,zl;
    string as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms,ns,os,ps,qs,rs,ss,ts,us,vs,ws,xs,ys,zs;
    char ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc,nc,oc,pc,qc,rc,sc,tc,uc,vc,wc,xc,yc,zc;
    vector<int> av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv,nv,ov,pv,qv,rv,sv,tv,uv,vv,wv,xv,yv,zv;
    
    //freopen("a.txt", "r", stdin); 
 
    cin>>a;
    for(b=0;b<a;b++)
    {
      cin>>c>>d;
      cin>>as;
      f=0;
      g=-d;
      h=-1;
      for(e=0;e<c;e++)
      {
        if(as.at(e)=='*')
        {
          if(f==0)
          {
            f++;
            g=e;
            h=e;
          }
          else if((e-g)>d)
          {
            f++;
            g=h;
          }
          h=e;
        }
      }
      if(g!=h)
      {
        f++;
      }
      cout<<f<<endl;
    }
}