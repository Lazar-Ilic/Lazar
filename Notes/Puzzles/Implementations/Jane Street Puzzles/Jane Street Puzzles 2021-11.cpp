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

//Code 6467972 casework on the multiplicands and remainder to produce plausible multiplicands remainder tuples in phase 1 and then consider pairs amongst those until producing a consistent pair in phase 2.

	for(a=1;a<=2;a++){
		for(b=0;b<=9;b++){
			for(c=1;c<=4;c++){
				for(d=1;d<=3;d++){
					for(e=0;e<=9;e++){
						for(f=1;f<=4;f++){
							for(g=1;g<=4;g++){
								for(h=1;h<=3;h++){
	av=V(41);
	av[0]=4*a;
	av[1]=b;
	av[2]=2*c;
	av[3]=3*d;
	av[4]=e;
	av[5]=2*f;
	av[6]=2*g;
	av[39]=3*h;
	av[40]=7;
	i=100*av[0]+10*av[1]+av[2];
	j=1000*av[3]+100*av[4]+10*av[5]+av[6];
	r=10*av[39]+av[40];
	k=i*j+r;
	l=av[0]*j;
	m=k/10-10*l;
	n=av[1]*j;
	o=10*m+(k/1)%10-10*n;
	q=av[2]*j;
	if(
	o-q==r and 
	((k/100000)%10)>0 and ((k/100000)%10)%7==0 and 
	((k/10)%10)>0 and ((k/10)%10)%2==0 and 
	((k/1)%10)>0 and ((k/1)%10)%3==0 and 
	((l/1)%10)>0 and ((l/1)%10)%2==0 and 
	((m/1)%10)>0 and ((m/1)%10)%2==0 and 
	((n/10000)%10)==0 and 
	((n/1000)%10)>0 and ((n/1000)%10)%9==0 and 
	((n/10)%10)>0 and ((n/10)%10)%3==0 and 
	((n/1)%10)>0 and ((n/1)%10)%8==0 and 
	((o/1000)%10)>0 and ((o/1000)%10)%3==0 and 
	((o/10)%10)>0 and ((o/10)%10)%2==0 and 
	((o/1)%10)>0 and ((o/1)%10)%3==0 and 
	((q/1000)%10)>0 and ((q/1000)%10)%3==0 and 
	((q/100)%10)>0 and ((q/100)%10)%2==0 and 
	((q/10)%10)>0 and ((q/10)%10)%7==0 and 
	((q/1)%10)>0 and ((q/1)%10)%2==0
	){
		av[7]=(k/1000000)%10;
		av[8]=(k/100000)%10;
		av[9]=(k/10000)%10;
		av[10]=(k/1000)%10;
		av[11]=(k/100)%10;
		av[12]=(k/10)%10;
		av[13]=(k/1)%10;
		
		av[14]=(l/10000)%10;
		av[15]=(l/1000)%10;
		av[16]=(l/100)%10;
		av[17]=(l/10)%10;
		av[18]=(l/1)%10;
		
		av[19]=(m/10000)%10;
		av[20]=(m/1000)%10;
		av[21]=(m/100)%10;
		av[22]=(m/10)%10;
		av[23]=(m/1)%10;
		
		av[24]=(n/10000)%10;
		av[25]=(n/1000)%10;
		av[26]=(n/100)%10;
		av[27]=(n/10)%10;
		av[28]=(n/1)%10;
		
		av[29]=(o/10000)%10;
		av[30]=(o/1000)%10;
		av[31]=(o/100)%10;
		av[32]=(o/10)%10;
		av[33]=(o/1)%10;
		
		av[34]=(q/10000)%10;
		av[35]=(q/1000)%10;
		av[36]=(q/100)%10;
		av[37]=(q/10)%10;
		av[38]=(q/1)%10;
		
		avv.add(av);
	}
								}
							}
						}
					}
				}
			}
		}
	}
	out<<sz(avv)<<nl;
	for(a=0;a<sz(avv);a++){
		for(b=a+1;b<sz(avv);b++){
			if(
			(gcd(avv[a][0],avv[b][0])==4) and 
			(gcd(avv[a][2],avv[b][2])==2) and 
			(gcd(avv[a][3],avv[b][3])==3) and 
			(gcd(avv[a][5],avv[b][5])==2) and 
			(gcd(avv[a][6],avv[b][6])==2) and 
			(gcd(avv[a][12],avv[b][12])==2) and 
			(gcd(avv[a][13],avv[b][13])==3) and 
			(gcd(avv[a][18],avv[b][18])==2) and 
			(gcd(avv[a][23],avv[b][23])==2) and 
			(gcd(avv[a][27],avv[b][27])==3) and 
			(gcd(avv[a][30],avv[b][30])==3) and 
			(gcd(avv[a][32],avv[b][32])==2) and 
			(gcd(avv[a][33],avv[b][33])==3) and 
			(gcd(avv[a][35],avv[b][35])==3) and 
			(gcd(avv[a][36],avv[b][36])==2) and 
			(gcd(avv[a][38],avv[b][38])==2) and 
			(gcd(avv[a][39],avv[b][39])==3) and 
			!(avv[a][1]>0 and avv[b][1]>0 and gcd(avv[a][1],avv[b][1])>1) and 
			!(avv[a][4]>0 and avv[b][4]>0 and gcd(avv[a][4],avv[b][4])>1) and 
			!(avv[a][7]>0 and avv[b][7]>0 and gcd(avv[a][7],avv[b][7])>1) and 
			!(avv[a][9]>0 and avv[b][9]>0 and gcd(avv[a][9],avv[b][9])>1) and 
			!(avv[a][10]>0 and avv[b][10]>0 and gcd(avv[a][10],avv[b][10])>1) and 
			!(avv[a][11]>0 and avv[b][11]>0 and gcd(avv[a][11],avv[b][11])>1) and 
			!(avv[a][14]>0 and avv[b][14]>0 and gcd(avv[a][14],avv[b][14])>1) and 
			!(avv[a][15]>0 and avv[b][15]>0 and gcd(avv[a][15],avv[b][15])>1) and 
			!(avv[a][16]>0 and avv[b][16]>0 and gcd(avv[a][16],avv[b][16])>1) and 
			!(avv[a][17]>0 and avv[b][17]>0 and gcd(avv[a][17],avv[b][17])>1) and 
			!(avv[a][19]>0 and avv[b][19]>0 and gcd(avv[a][19],avv[b][19])>1) and 
			!(avv[a][20]>0 and avv[b][20]>0 and gcd(avv[a][20],avv[b][20])>1) and 
			!(avv[a][21]>0 and avv[b][21]>0 and gcd(avv[a][21],avv[b][21])>1) and 
			!(avv[a][22]>0 and avv[b][22]>0 and gcd(avv[a][22],avv[b][22])>1) and 
			!(avv[a][26]>0 and avv[b][26]>0 and gcd(avv[a][26],avv[b][26])>1) and 
			!(avv[a][29]>0 and avv[b][29]>0 and gcd(avv[a][29],avv[b][29])>1) and 
			!(avv[a][31]>0 and avv[b][31]>0 and gcd(avv[a][31],avv[b][31])>1) and 
			!(avv[a][34]>0 and avv[b][34]>0 and gcd(avv[a][34],avv[b][34])>1)){
				//outv(avv[a]);
				//outv(avv[b]);
				out<<1000000*(avv[a][7]+avv[b][7])+100000*(avv[a][8]+avv[b][8])+10000*(avv[a][9]+avv[b][9])+1000*(avv[a][10]+avv[b][10])+100*(avv[a][11]+avv[b][11])+10*(avv[a][12]+avv[b][12])+(avv[a][13]+avv[b][13])<<nl;
				return;
			}
		}
	}
}

I main(){zz();I a=1;while(a--){az();}}