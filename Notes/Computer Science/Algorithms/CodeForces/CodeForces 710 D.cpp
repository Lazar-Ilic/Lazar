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
      cin>>c;
      av.clear();
      for(d=0;d<c;d++)
      {
        cin>>e;
        av.add(e);
      }
      av.add(1000000001);
      sort(av.begin(),av.end());
      e=1;
      f=av[0];
      g=0;
      for(d=1;d<=c;d++)
      {
        if(av[d]==f)
        {
          e++;
        }
        else
        {
          f=av[d];
          if(e>g)
          {
            g=e;
          }
          e=1;
        }
      }
      if(g<=c/2)
      {
        if(c%2==0)
        {
          cout<<0<<endl;
        }
        else
        {
          cout<<1<<endl;
        }
      }
      else
      {
        cout<<(2*g-c)<<endl;
      }
    }
}