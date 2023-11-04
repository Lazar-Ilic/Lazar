#include <bits/stdc++.h>
using namespace std;
#define add push_back
#define remove pop_back
#define sssize __builtin_popcount

int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    double ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md,nd,od,pd,qd,rd,sd,td,ud,vd,wd,xd,yd,zd;
    long long al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml,nl,ol,pl,ql,rl,sl,tl,ul,vl,wl,xl,yl,zl;
    string as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms,ns,os,ps,qs,rs,ss,ts,us,vs,ws,xs,ys,zs;
    char ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc,nc,oc,pc,qc,rc,sc,tc,uc,vc,wc,xc,yc,zc;
    vector<int> av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv,nv,ov,pv,qv,rv,sv,tv,uv,vv,wv,xv,yv,zv;
    vector<vector<int>> avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv,nvv,ovv,pvv,qvv,rvv,svv,tvv,uvv,vvv,wvv,xvv,yvv,zvv;

    //freopen("a.txt", "r", stdin); 

    cin>>a;
    int steps=0;
    int steps2=0;
    int sumthusfar=0;
    for(b=0;b<a;b++)
    {
      cout<<"Case #"<<(b+1)<<":";
      cin>>c>>d;
      steps=0;
      steps2=0;
      if(d<(c-1) || d>=c*(c+1)/2)
      {
        cout<<" IMPOSSIBLE"<<endl;
      }
      else
      {
        av.clear();
        for(e=0;e<c;e++)
        {
          av.add(0);
        }
        sumthusfar=0;
        while(sumthusfar+(c-steps)+(c-steps-2)<=d && steps<c)
        {
          sumthusfar+=c-steps;
          steps++;
          if(steps%2==1)
          {
            av[c-1-steps/2]=steps;
          }
          else
          {
            av[steps/2-1]=steps;
          }
        }
        steps2=steps+1;
        if(sumthusfar<d)
        {
          if(steps%2==0)
          {
            g=d-sumthusfar-(c-steps-2)+steps/2-1;
            h=steps/2;
            for(e=g;e>=h;e--)
            {
              av[e]=steps2;
              steps2++;
            }
            g=d-sumthusfar-(c-steps-2)+steps/2;
            h=c-steps/2;
            for(e=g;e<h;e++)
            {
              av[e]=steps2;
              steps2++;
            }
          }
          else
          {
            g=c-steps/2-1-(d-sumthusfar-(c-steps-2));
            h=c-steps/2-1;
            for(e=g;e<h;e++)
            {
              av[e]=steps2;
              steps2++;
            }
            g=c-steps/2-1-(d-sumthusfar-(c-steps-2))-1;
            h=steps/2;
            for(e=g;e>=h;e--)
            {
              av[e]=steps2;
              steps2++;
            }
          }
      }
      for(e=0;e<c;e++)
        {
          cout<<" "<<av[e];
        }
        cout<<endl;
    }
}
}
