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

    for(b=0;b<a;b++)
    {
      cout<<"Case #"<<(b+1)<<": ";
      cin>>c;
      d=0;
      av.clear();
      for(e=0;e<c;e++)
      {
        cin>>f;
        av.add(f);
      }
      bv=av;
      for(e=1;e<c;e++)
      {
        g=int(find(av.begin(),av.end(),e)-av.begin());
        d+=1+g-(e-1);
        for(h=(e-1);h<=g;h++)
        {
          bv[h]=av[g+e-1-h];
        }
        av=bv;
      }
      cout<<d<<endl;
    }
}

