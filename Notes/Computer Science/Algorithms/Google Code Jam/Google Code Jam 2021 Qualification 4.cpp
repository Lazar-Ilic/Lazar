#include <bits/stdc++.h>
using namespace std;
#define add push_back
#define remove pop_back
#define sssize __builtin_popcount
#define shuff random_shuffle

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
    
cin>>a>>b>>c;
for(d=1;d<=b;d++)
{
  av.add(d);
}
shuff(av.begin(),av.end());
for(d=0;d<a;d++)
{
  bv.clear();
  cout<<av[0]<<" "<<av[1]<<" "<<av[2]<<endl;
  cin>>e;
  if(e==av[0])
  {
    bv.add(av[1]);
    bv.add(av[0]);
    bv.add(av[2]);
  }
  else if(e==av[1])
  {
    bv.add(av[0]);
    bv.add(av[1]);
    bv.add(av[2]);
  }
  else
  {
    bv.add(av[0]);
    bv.add(av[2]);
    bv.add(av[1]);
  }
  for(f=3;f<b;f++)
  {
    g=av[f];
    h=f/3;
    i=(2*f)/3;
    j=0;
    k=f;
    while((k-j)>2)
    {
      cout<<bv[h]<<" "<<g<<" "<<bv[i]<<endl;
      cin>>e;
      if(e==bv[h])
      {
        k=h;
      }
      else if(e==g)
      {
        j=h+1;
        k=i;
      }
      else
      {
        j=i+1;
      }
      h=j+(k-j)/3;
      i=j+(2*(k-j))/3;
    }
    if(j==k)
    {
      l=j;
    }
    else if(j+1==k)
    {
      if(k!=f)
      {
        cout<<bv[j]<<" "<<g<<" "<<bv[j+1]<<endl;
        cin>>e;
        if(e==bv[j])
        {
          l=j;
        }
        else
        {
          l=j+1;
        }
      }
      else
      {
        cout<<bv[j-1]<<" "<<g<<" "<<bv[j]<<endl;
        cin>>e;
        if(e==bv[j])
        {
          l=j+1;
        }
        else
        {
          l=j;
        }
      }
    }
    else
    {
      cout<<bv[j]<<" "<<g<<" "<<bv[j+1]<<endl;
      cin>>e;
      if(e==bv[j])
      {
        l=j;
      }
      else if(e==g)
      {
        l=j+1;
      }
      else
      {
        l=j+2;
      }
    }
    bv.insert(bv.begin()+l,g);
  }
  cout<<bv[0];
  for(f=1;f<b;f++)
  {
    cout<<" "<<bv[f];
  }
  cout<<endl;
  cin>>z;
}
}