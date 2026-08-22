//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using U=uint64_t;
using LD=long double;
using S=string;
using PB=pair<B,B>;
using PC=pair<C,C>;
using PD=pair<D,D>;
using P=pair<I,I>;
using PL=pair<L,L>;
using PLD=pair<LD,LD>;
using PS=pair<S,S>;
using PSL=pair<S,L>;
using PIS=pair<I,S>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using MSETP=multiset<P>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETULL=set<ULL>;
using SETP=set<P>;
using SETSETP=set<SETP>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MLI=map<L,I>;
using MLL=map<L,L>;
using MPI=map<P,I>;
using MCI=map<C,I>;
using MUI=map<U,I>;
using VMII=vector<MII>;
using UMSI=unordered_map<S,I>;
using UMII=unordered_map<I,I>;
using UMIL=unordered_map<I,L>;
using UMLL=unordered_map<L,L>;
using UMUI=unordered_map<U,I>;
using UMPI=unordered_map<P,I>;
using VUMII=vector<UMII>;
using DQ=deque<I>;
using ST=stack<I>;
using STST=stack<ST>;
using STP=stack<P>;
using STPL=stack<PL>;
using Q=queue<I>;
using PQ=priority_queue<I>;
using PQP=priority_queue<P>;
using PQPL=priority_queue<PL>;
using VB=vector<B>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VL=vector<L>;
using VULL=vector<ULL>;
using VLD=vector<LD>;
using VS=vector<S>;
using VU=vector<U>;
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
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VSET=vector<SET>;
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using Z=void;
#define PTL PT<L>
#define PTD PT<D>
#define VH vector<H>
#define VPTL vector<PTL>
#define VPTD vector<PTD>
#define orderofkey order_of_key
#define findbyorder find_by_order
#define lowerbound lower_bound
#define upperbound upper_bound
#define nextpermutation next_permutation
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsetsize __builtin_popcount
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a) ((a).begin()),((a).end())
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define BT bitset
#define ba &
#define bo |
#define bx ^
#define bf ~
#define in cin
#define out cout
#define nl endl
Z zz(){
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);
	#endif
}
Z outv(V av){
	if(sz(av)==0)return;
	for(I a=0;a<sz(av);a++)out<<av[a]<<" ";
	out<<nl;
}
Z outvv(VV avv){
	if(sz(avv)==0)return;
	for(I a=0;a<sz(avv);a++)outv(avv[a]);
}
Z outset(SET aset){
	if(aset.empty())return;
	for(auto aa:aset)out<<aa<<" ";
	out<<nl;
}
const I p=1000000007; // 998244353 1000000007 1000000000
//--------------------------------------------------------------------

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
	V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
	P ap,bp,cp,dp,ep,fp,gp,hp,ip,jp,kp,lp,mp;
	VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
	VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
	VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
	VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;

/*
There exist O[4^[n^2]] possible states/configurations of pins so we must do better. Code generating row by row, in a total runtime ~O[n^2 * 4^n], to produce the maximum of this metric supposing all layers below are made up of the 5th pin type, genuine random as in the depicted Galton Board example. In the sense that we use the sum of induced double/floating binomial distributions downstream. There may exist a smoothing intuition that this will produce the global optimum/maximum though my time/energy to write such an argumentation out is not worth it.

A verification:

114.801
L<><<><<<><<<<RL<<<R><R<<L>>LLR<RRLL

This graphic depicts precisely how many balls will reach each pin in the constructed deterministic Galton Board:

        150
         L
       75 75
        <  >
      75  0 75
       <  <  >
     75  0  0 75
      <  <  <  >
    75  0  0  0 75
     <  <  <  <  R
   75  0  0  0 37 38
    L  <  <  <  R  >
  38 37  0  0 18 19 38
   <  R  <  <  L  >  >
 38 18 19  0  9  9 19 38
  L  L  R  <  R  R  L  L
19 28 18 10  4  9 15 28 19

[9/150*4]^1*[9/150*9]^2*[9/150*10]^3*[9/150*15]^4*[9/150*18]^5*[9/150*28]^6*[9/150*28]^7*[9/150*19]^8*[9/150*19]^9

Diving and taking the logarithm:

Maximise log(a)+2*log(b)+3*log(c)+4*log(d)+5*log(f)+6*log(g)+7*log(h)+8*log(j)+9*log(k) for a+b+c+d+f+g+h+j+k=150 and a>0,b>0,c>0,d>0,f>0,g>0,h>0,j>0,k>0 by Lagrange Multipliers one obtains 1/a=2/b=3/c=4/d=5/f=6/g=7/h=8/j=9/k and the continuous maximum final distribution vector of:

[90/3,70/3,50/3,30/3,10/3,20/3,40/3,60/3,80/3] =
[30.0,23.3,16.7,10.0, 3.3, 6.7,13.3,20.0,26.7] compared to output:
[19.0,28.0,18.0,10.0, 4.0, 9.0,15.0,28.0,19.0]

136.172
L<><<><<<>L<<<><><<<R<<><<<>L<<R<L<><R<L<<L<L
*/

	ad=10;
	z=10;
	bd=150;
	av=V(((z*(z-1))/2),4);
	cv={3,7,1,6,9,5,2,8,0,4};
	for(a=1;a<=z-1;a++){
		cd=0;
		for(b=0;b<(1<<(2*a));b++){
			bv=av;
			c=b;
			for(d=1;d<=a;d++){
				bv[((a*(a+1))/2)-d]=c%4;
				c/=4;
			}
			dd=1.0;
			avd=VD(z);
			avd[0]=bd;
			for(c=1;c<=z-1;c++){
				bvd=VD(z);
				for(d=0;d<=c;d++){
					if(d-1>=0 and bv[(((c-1)*c)/2)+d-1]==0 and avd[d-1]>0)bvd[d]+=0;
					if(d-1>=0 and bv[(((c-1)*c)/2)+d-1]==1 and avd[d-1]>0)bvd[d]+=avd[d-1];
					if(d-1>=0 and bv[(((c-1)*c)/2)+d-1]==2 and avd[d-1]>0)bvd[d]+=double(int(avd[d-1])/2);
					if(d-1>=0 and bv[(((c-1)*c)/2)+d-1]==3 and avd[d-1]>0)bvd[d]+=double(avd[d-1]-int(avd[d-1])/2);
					if(d-1>=0 and bv[(((c-1)*c)/2)+d-1]==4 and avd[d-1]>0)bvd[d]+=avd[d-1]/2;
					if(d<c and bv[(((c-1)*c)/2)+d]==0 and avd[d]>0)bvd[d]+=avd[d];
					if(d<c and bv[(((c-1)*c)/2)+d]==1 and avd[d]>0)bvd[d]+=0;
					if(d<c and bv[(((c-1)*c)/2)+d]==2 and avd[d]>0)bvd[d]+=double(avd[d]-int(avd[d])/2);
					if(d<c and bv[(((c-1)*c)/2)+d]==3 and avd[d]>0)bvd[d]+=double(int(avd[d])/2);
					if(d<c and bv[(((c-1)*c)/2)+d]==4 and avd[d]>0)bvd[d]+=avd[d]/2;
				}
				avd=bvd;
			}
			for(c=1;c<=z;c++){
				dd*=pow(ad*avd[cv[c-1]]/bd,double(c));
			}
			if(dd>cd){
				cd=dd;
				av=bv;
			}
		}
	}
	out<<cd<<nl;
	for(a=0;a<sz(av);a++){
		if(av[a]==0)out<<"<";
		else if(av[a]==1)out<<">";
		else if(av[a]==2)out<<"L";
		else out<<"R";
	}
	out<<nl;
}

I main(){zz();I a=1;while(a--){az();}}