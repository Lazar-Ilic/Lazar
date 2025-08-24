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
 
    vector<vector<int>> avv;
    cin>>a;
    for(b=0;b<a;b++)
    {
      cin>>c;
      avv.clear();
      av.clear();
      bv.clear();
      av.add(1);
      bv.add(1);
      for(d=0;d<c;d++)
      {
        cin>>e;
        av.add(e);
      }
      for(d=0;d<c;d++)
      {
        cin>>e;
        bv.add(e);
      }
      for(d=0;d<=c;d++)
      {
        cv.clear();
        cv.add(av[d]);
        cv.add(bv[d]);
        avv.add(cv);
      }
      sort(avv.begin(),avv.end());
      int cost=0;
      for(d=0;d<c;d++)
      {
        if((avv[d][0]-avv[d+1][0])==(avv[d][1]-avv[d+1][1]) && (avv[d][0]+avv[d][1])%2==0)
        {
          cost+=(avv[d+1][0]-avv[d][0]);
        }
        else
        {
          if((avv[d][0]+avv[d][1])%2==0)
          {
            avv[d][0]+=1;
          }
          h=avv[d][0]-avv[d][1];
          i=avv[d+1][0]-avv[d+1][1];
          if((i-h)%2==0)
          {
            cost+=((i-h)/2);
          }
          else
          {
            cost+=(1+(i-h)/2);
          }
        }
      }
      cout<<cost<<endl;
    }
}