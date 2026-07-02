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

vector<string> solves;
vector<pair<double,int>> zvdi;
cin>>a;
cin>>z;
int max;
double maxed;
yd=exp(3);
zd=exp(6);
for(b=0;b<a;b++)
{
  cout<<"Case #"<<(b+1)<<": ";
  max=0;
  solves.clear();
  av.clear();
  bv.clear();
  cv.clear();
  avd.clear();
  bvd.clear();
  cvd.clear();
  dvd.clear();
  evd.clear();
  zvdi.clear();
  for(c=0;c<100;c++)
  {
    as="";
    cin>>as;
    solves.add(as);
  }
  for(c=0;c<10000;c++)
  {
    e=0;
    for(d=0;d<100;d++)
    {
      e+=int(solves[d][c]);
    }
    av.add(e-4800);
  }
  for(c=0;c<100;c++)
  {
    e=0;
    for(d=0;d<10000;d++)
    {
      e+=int(solves[c][d]);
    }
    bv.add(e-480000);
  }
  for(c=0;c<100;c++)
  {
    bvd.add(double(bv[c])/10000);
  }
  for(c=0;c<10000;c++)
  {
    avd.add(double(av[c])/100);
    zvdi.add({avd[c],c});
  }
  for(c=0;c<100;c++)
  {
    evd.add(log(yd*(exp(6*bvd[c])-1)/(zd-exp(6*bvd[c]))));
  }
  for(c=0;c<10000;c++)
  {
    dvd.add(-log(yd*(exp(6*avd[c])-1)/(zd-exp(6*avd[c]))));
  }
  sort(zvdi.begin(),zvdi.end());
  for(c=0;c<100;c++)
  {
    e=0;
    for(d=0;d<100;d++)
    {
      if(solves[c][zvdi[d].second]==49)
      {
        e++;
      }
    }
    if(e>40)
    {
      cv.add(c);
    }
  }
  f=cv.size();
  h=0;
  id=0;
  for(g=0;g<f;g++)
  {
    j=cv[g];
    bvd[j]=(1-2*(1-bvd[j]));
    nd=log(yd*(exp(6*bvd[j])-1)/(zd-exp(6*bvd[j])));
    kd=0;
    ld=0;
    md=0;
    od=0;
    pd=0;
    qd=0;
    for(k=0;k<10000;k++)
    {
        kd+=1/(1+exp(dvd[zvdi[k].second]-evd[j]));
        od+=(1+1/(1+exp(dvd[zvdi[k].second]-nd)))/2;
        ld+=solves[j][zvdi[k].second]-48;
        if(k<500)
        {
          pd+=abs(od-ld);
          qd+=abs(kd-ld);
        }
        //md+=(49-solves[j][zvdi[k].second])*1/(1-1/(1+exp(dvd[zvdi[k].second]-evd[j])));
        //md+=(solves[j][zvdi[k].second]-48)*1/(1/(1+exp(dvd[zvdi[k].second]-evd[j])));
    }
    md=qd/pd;
    //cout<<md<<endl;
    if(md>id)
    {
      id=md;
      h=j+1;
    }
  }
  cout<<h<<endl;
  }
}