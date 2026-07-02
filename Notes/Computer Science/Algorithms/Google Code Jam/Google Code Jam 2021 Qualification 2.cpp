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
    int pre;
    int prep;
    int seq;
    int prev;
    int neg;
    int sum;
    int forcedcj;
    int forcedjc;
    int optsums;
    int cost;
    for(b=0;b<a;b++)
    {
      cout<<"Case #"<<(b+1)<<": ";
      cin>>c>>d;
      cin>>as;
      e=as.size();
      prep=0;
      seq=0;
      prev=0;
      f=0;
      forcedcj=0;
      forcedjc=0;
      optsums=0;
      sum=c+d;
      cost=0;
      while(prep==0)
      {
        if(as[f]=='?')
        {
          seq++;
          f++;
        }
        else
        {
          prep=1;
          if(as[f]=='C')
          {
            prev=0;
          }
          else
          {
            prev=1;
          }
          if(seq!=0)
          {
            if(seq==1)
            {
              if(prev==0)
              {
                cost+=min(0,d);
              }
              else
              {
                cost+=min(0,c);
              }
            }
            else
            {
            if(prev==0)
            {
              cost+=min(0,min(d,min(c*int((seq-1)/2)+d*int((seq)/2),c*int((seq)/2)+d*int((seq+1)/2))));
            }
            else
            {
              cost+=min(0,min(c,min(d*int((seq-1)/2)+c*int((seq)/2),d*int((seq)/2)+c*int((seq+1)/2))));
            }
            }
          }
        }
      }
      seq=0;
      while(f<(e-1))
      {
        f++;
        if(as[f]=='?')
        {
          seq++;
        }
        else if(as[f]=='C')
        {
          if(seq==0)
          {
            if(prev==1)
            {
              forcedjc++;
              prev=0;
            }
          }
          else
          {
            if(prev==0)
            {
              optsums+=(seq+1)/2;
            }
            else
            {
              forcedjc++;
              optsums+=seq/2;
            }
            seq=0;
            prev=0;
          }
        }
        else
        {
          if(seq==0)
          {
            if(prev==0)
            {
              forcedcj++;
              prev=1;
            }
          }
          else
          {
            if(prev==1)
            {
              optsums+=(seq+1)/2;
            }
            else
            {
              forcedcj++;
              optsums+=seq/2;
            }
            seq=0;
            prev=1;
          }
        }
      }
      if(seq!=0)
      {
        if(seq==1)
        {
          if(prev==0)
          {
            cost+=min(0,c);
          }
          else
          {
            cost+=min(0,d);
          }
        }
        else
        {
        if(prev==0)
        {
          cost+=min(0,min(c,min(c*int((seq-1)/2)+d*int((seq)/2),c*int((seq)/2)+d*int((seq+1)/2))));
        }
        else
        {
          cost+=min(0,min(d,min(d*int((seq-1)/2)+c*int((seq)/2),d*int((seq)/2)+c*int((seq+1)/2))));
        }
        }
      }
      cost+=forcedcj*c+forcedjc*d;
      if(sum<0)
      {
        cost+=optsums*sum;
      }
      cout<<cost<<endl;
    }
}

