/*
Not related to mutually orthogonal Latin squares.

----------

20

0 1 2 3
2 3 0 1
3 2 1 0
1 0 3 2

1 0 3 2
3 2 1 0
2 3 0 1
0 1 2 3

2 3 0 1
0 1 2 3
1 0 3 2
3 2 1 0

3 2 1 0
1 0 3 2
0 1 2 3
2 3 0 1

----------

012345
234501
501234
123450
450123

----------

Seems that Googling and OEISing Latin Diagonal Square Cube might be useful.
*/

//%%writefile a.cpp

/*
"Our lives are not our own. From womb to tomb, we are bound to others. Past 
and present. And by each crime and every kindness, we birth our future."
- Sonmi-451, Cloud Atlas

"As I see it you need a strategy for reading, I find a computer 
indispensable... For centuries alchemists tried to make Gold from base metals. 
Today we make microchips from Silicon, which is common sand, but far better 
than Gold."
- Maximillian Zorin, A View To A Kill

"I like how math is so simple. It uses simple things to solve harder things. 
At the same time, it's so beautiful. It assumes a perfect world and it really 
lets you see the completeness of things. Some of the proofs are just really 
inspiring."
- Amy Chou XO <3

"Death solves all problems: no man, no problem."
- Анато́лий Нау́мович Рыбако́в, "Ио́сиф Виссарио́нович Ста́лин"

"VENI, VIDI, VICI"
- Julius Caesar

https://github.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
*/

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
using UI=unsigned int;
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
using USETL=unordered_set<L>;
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
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VUI=vector<UI>;
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
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using PIV=pair<I,V>;
using PDV=pair<D,V>;
using PULL=pair<ULL,ULL>;
using MULLPULL=map<ULL,PULL>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using QP=queue<P>;
using QV=queue<V>;
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
I p=1000000007; // 998244353 1000000007 1000000009 1000000000 433494437 993353399
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

	/*  */

	av={0,1,2,3};
	do{
		avv.add(av);
	}while(nextpermutation(all(av)));
	bv={0,1,2,3};
	for(V dude1:avv){
		for(V dude2:avv){
			for(V dude3:avv){
				for(V dude4:avv){
					// Evaluate if they make Latin Square and add to avvv.
					bvv=VV(0,V(0));
					bvv.add(dude1);
					bvv.add(dude2);
					bvv.add(dude3);
					bvv.add(dude4);
					auset.clear();
					auset.insert(bvv[0][0]);
					auset.insert(bvv[1][0]);
					auset.insert(bvv[2][0]);
					auset.insert(bvv[3][0]);
					if(sz(auset)==4){
					auset.clear();
					auset.insert(bvv[0][1]);
					auset.insert(bvv[1][1]);
					auset.insert(bvv[2][1]);
					auset.insert(bvv[3][1]);
					if(sz(auset)==4){
					auset.clear();
					auset.insert(bvv[0][2]);
					auset.insert(bvv[1][2]);
					auset.insert(bvv[2][2]);
					auset.insert(bvv[3][2]);
					if(sz(auset)==4){
					auset.clear();
					auset.insert(bvv[0][3]);
					auset.insert(bvv[1][3]);
					auset.insert(bvv[2][3]);
					auset.insert(bvv[3][3]);
					if(sz(auset)==4){
					if(dude1==bv)avvv.add(bvv);
					if(bvv[0][0]==1)bvvv.add(bvv);
					if(bvv[0][0]==2)cvvv.add(bvv);
					if(bvv[0][0]==3)dvvv.add(bvv);
					}
					}
					}
					}
				}
			}
		}
	}
	out<<sz(avvv)<<nl<<sz(bvvv)<<nl<<sz(cvvv)<<nl<<sz(dvvv)<<nl;
	m=0;
	al=0;
	for(VV dude1:avvv){
		for(VV dude2:bvvv){
			for(VV dude3:cvvv){
				for(VV dude4:dvvv){
					z=1;
					al++;
					if(al%10000000==0)out<<al<<nl;
					for(b=0;b<4 and z;b++){
						for(c=0;c<4 and z;c++){
							auset.clear();
							auset.insert(dude1[b][c]);
							auset.insert(dude2[b][c]);
							auset.insert(dude3[b][c]);
							auset.insert(dude4[b][c]);
							if(sz(auset)<4)z=0;
						}
					}
					if(z){
						n=0;
						// Evaluate all diagonals.
						for(b=0;b<4;b++){
							auset.clear();
							auset.insert(dude1[b][0]);
							auset.insert(dude2[b][1]);
							auset.insert(dude3[b][2]);
							auset.insert(dude4[b][3]);
							if(sz(auset)==4)n++;
							auset.clear();
							auset.insert(dude1[b][3]);
							auset.insert(dude2[b][2]);
							auset.insert(dude3[b][1]);
							auset.insert(dude4[b][0]);
							if(sz(auset)==4)n++;
						}
						for(b=0;b<4;b++){
							auset.clear();
							auset.insert(dude1[0][b]);
							auset.insert(dude2[1][b]);
							auset.insert(dude3[2][b]);
							auset.insert(dude4[3][b]);
							if(sz(auset)==4)n++;
							auset.clear();
							auset.insert(dude1[3][b]);
							auset.insert(dude2[2][b]);
							auset.insert(dude3[1][b]);
							auset.insert(dude4[0][b]);
							if(sz(auset)==4)n++;
						}
						auset.clear();
						auset.insert(dude1[0][0]);
						auset.insert(dude1[1][1]);
						auset.insert(dude1[2][2]);
						auset.insert(dude1[3][3]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude1[0][3]);
						auset.insert(dude1[1][2]);
						auset.insert(dude1[2][1]);
						auset.insert(dude1[3][0]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude2[0][0]);
						auset.insert(dude2[1][1]);
						auset.insert(dude2[2][2]);
						auset.insert(dude2[3][3]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude2[0][3]);
						auset.insert(dude2[1][2]);
						auset.insert(dude2[2][1]);
						auset.insert(dude2[3][0]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude3[0][0]);
						auset.insert(dude3[1][1]);
						auset.insert(dude3[2][2]);
						auset.insert(dude3[3][3]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude3[0][3]);
						auset.insert(dude3[1][2]);
						auset.insert(dude3[2][1]);
						auset.insert(dude3[3][0]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude4[0][0]);
						auset.insert(dude4[1][1]);
						auset.insert(dude4[2][2]);
						auset.insert(dude4[3][3]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude4[0][3]);
						auset.insert(dude4[1][2]);
						auset.insert(dude4[2][1]);
						auset.insert(dude4[3][0]);
						if(sz(auset)==4)n++;

						auset.clear();
						auset.insert(dude1[0][0]);
						auset.insert(dude2[1][1]);
						auset.insert(dude3[2][2]);
						auset.insert(dude4[3][3]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude1[3][3]);
						auset.insert(dude2[2][2]);
						auset.insert(dude3[1][1]);
						auset.insert(dude4[0][0]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude1[0][3]);
						auset.insert(dude2[1][2]);
						auset.insert(dude3[2][1]);
						auset.insert(dude4[3][0]);
						if(sz(auset)==4)n++;
						auset.clear();
						auset.insert(dude1[3][0]);
						auset.insert(dude2[2][1]);
						auset.insert(dude3[1][2]);
						auset.insert(dude4[0][3]);
						if(sz(auset)==4)n++;

						if(n>m){
							m=n;
							out<<n<<nl<<nl;
							outvv(dude1);
							out<<nl;
							outvv(dude2);
							out<<nl;
							outvv(dude3);
							out<<nl;
							outvv(dude4);
							out<<nl<<nl<<nl;
						}
					}
				}
			}
		}
	}

	av={0,1,2,3,4,5};
	do{
		// Check this setting. Through all 2^6 = 64 directions.
		for(a=0;a<(1<<6);a++){
			avv=VV(6,V(6));
			for(b=0;b<6;b++){
				if(a ba (1<<b)){
					for(c=0;c<6;c++){
						avv[b][c]=(av[b]+c)%6;
					}
				}
				else{
					for(c=0;c<6;c++){
						avv[b][c]=(av[b]-c+6)%6;
					}
				}
			}
			outvv(avv);
			// Evaluate avv diagonals.
			auset.clear();
			auset.insert(avv[0][0]);
			auset.insert(avv[1][1]);
			auset.insert(avv[2][2]);
			auset.insert(avv[3][3]);
			auset.insert(avv[4][4]);
			auset.insert(avv[5][5]);
			if(sz(auset)==6){
			outvv(avv);
			auset.clear();
			auset.insert(avv[0][5]);
			auset.insert(avv[1][4]);
			auset.insert(avv[2][3]);
			auset.insert(avv[3][2]);
			auset.insert(avv[4][1]);
			auset.insert(avv[5][0]);
			if(sz(auset)==6){
				avvv.add(avv);
			}
			}
		}
	}while(nextpermutation(all(av)));
	out<<sz(avvv)<<nl;

	/* https://users.cecs.anu.edu.au/~bdm/data/mc666.txt.gz */

	a=6;
	m=0;
	for(b=0;b<264248;b++){ // 15 = Number Of Classes
		avvv=VVV(a,VV(a,V(a)));
		for(c=0;c<a;c++){
			for(d=0;d<a;d++){
				in>>as;
				for(e=0;e<a;e++)avvv[c][d][e]=1+as[e]-'0';
			}
		}
		in>>bs>>cs;
		n=0;
		for(c=0;c<a;c++){
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[c][d][d]);
			if(sz(auset)==a)n++;
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[c][d][a-1-d]);
			if(sz(auset)==a)n++;
		}
		for(c=0;c<a;c++){
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[d][c][d]);
			if(sz(auset)==a)n++;
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[d][c][a-1-d]);
			if(sz(auset)==a)n++;
		}
		for(c=0;c<a;c++){
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[d][d][c]);
			if(sz(auset)==a)n++;
			auset.clear();
			for(d=0;d<a;d++)auset.insert(avvv[d][a-1-d][c]);
			if(sz(auset)==a)n++;
		}
		auset.clear();
		for(d=0;d<a;d++)auset.insert(avvv[d][d][d]);
		if(sz(auset)==a)n++;
		auset.clear();
		for(d=0;d<a;d++)auset.insert(avvv[d][d][a-1-d]);
		if(sz(auset)==a)n++;
		auset.clear();
		for(d=0;d<a;d++)auset.insert(avvv[d][a-1-d][d]);
		if(sz(auset)==a)n++;
		auset.clear();
		ford=0;d<a;d++)auset.insert(avvv[d][a-1-d][a-1-d]);
		if(sz(auset)==a)n++;
		if(n>m){
			m=n;
			for(VV dude:avvv){
				outvv(dude);
				out<<nl;
			}
			out<<3*a*a+n<<" / "<<3*a*a+6*a+4<<nl;
		}
	}

	av={1,2,3,4,5};
	bv={1,2,3,4,5};
	cv={1,2,3,4,5};
	dv={1,2,3,4,5};
	ev={1,2,3,4,5};
	al=0;
	do{
	do{
	do{
	do{
	do{
	al++;
	if(al%1000000==0)out<<al<<nl;
	z=1;
	for(a=0;a<5 and z;a++){
		auset.clear();
		auset.insert(av[a]);
		auset.insert(bv[a]);
		auset.insert(cv[a]);
		auset.insert(dv[a]);
		auset.insert(ev[a]);
		if(sz(auset)!=5)z=0;
	}
	auset.clear();
	auset.insert(av[0]);
	auset.insert(bv[1]);
	auset.insert(cv[2]);
	auset.insert(dv[3]);
	auset.insert(ev[4]);
	if(sz(auset)!=5)z=0;
	auset.clear();
	auset.insert(av[4]);
	auset.insert(bv[3]);
	auset.insert(cv[2]);
	auset.insert(dv[1]);
	auset.insert(ev[0]);
	if(sz(auset)!=5)z=0;
	if(z==1){
		avv=VV(5,V(5));
		avv[0]=av;
		avv[1]=bv;
		avv[2]=cv;
		avv[3]=dv;
		avv[4]=ev;
		avvv.add(avv);
	}
	}while(nextpermutation(all(av)));
	}while(nextpermutation(all(bv)));
	}while(nextpermutation(all(cv)));
	}while(nextpermutation(all(dv)));
	}while(nextpermutation(all(ev)));
	m=0;
	out<<sz(avvv)<<nl;
	for(VV dude2:avvv){
		VV dude1=avvv[0];
		z=1;
		for(a=0;a<5 and z;a++){
			for(b=0;b<5 and z;b++){
				auset.clear();
				auset.insert(dude1[a][b]);
				auset.insert(dude2[a][b]);
				if(sz(auset)!=2)z=0;
			}
		}
		if(z){
		for(VV dude3:avvv){
			z=1;
			for(a=0;a<5 and z;a++){
				for(b=0;b<5 and z;b++){
					auset.clear();
					auset.insert(dude1[a][b]);
					auset.insert(dude2[a][b]);
					auset.insert(dude3[a][b]);
					if(sz(auset)!=3)z=0;
				}
			}
			if(z){
			for(VV dude4:avvv){
				z=1;
				for(a=0;a<5 and z;a++){
					for(b=0;b<5 and z;b++){
						auset.clear();
						auset.insert(dude1[a][b]);
						auset.insert(dude2[a][b]);
						auset.insert(dude3[a][b]);
						auset.insert(dude4[a][b]);
						if(sz(auset)!=4)z=0;
					}
				}
				if(z){
				for(VV dude5:avvv){
					z=1;
					for(a=0;a<5 and z;a++){
						for(b=0;b<5 and z;b++){
							auset.clear();
							auset.insert(dude1[a][b]);
							auset.insert(dude2[a][b]);
							auset.insert(dude3[a][b]);
							auset.insert(dude4[a][b]);
							auset.insert(dude5[a][b]);
							if(sz(auset)!=5)z=0;
						}
					}
					if(z){
						n=0;
						for(a=0;a<5;a++){
							auset.clear();
							auset.insert(dude1[a][0]);
							auset.insert(dude2[a][1]);
							auset.insert(dude3[a][2]);
							auset.insert(dude4[a][3]);
							auset.insert(dude5[a][4]);
							if(sz(auset)==5)n++;
							auset.clear();
							auset.insert(dude1[a][4]);
							auset.insert(dude2[a][3]);
							auset.insert(dude3[a][2]);
							auset.insert(dude4[a][1]);
							auset.insert(dude5[a][0]);
							if(sz(auset)==5)n++;
							auset.clear();
							auset.insert(dude1[0][a]);
							auset.insert(dude2[1][a]);
							auset.insert(dude3[2][a]);
							auset.insert(dude4[3][a]);
							auset.insert(dude5[4][a]);
							if(sz(auset)==5)n++;
							auset.clear();
							auset.insert(dude1[4][a]);
							auset.insert(dude2[3][a]);
							auset.insert(dude3[2][a]);
							auset.insert(dude4[1][a]);
							auset.insert(dude5[0][a]);
							if(sz(auset)==5)n++;
						}
						auset.clear();
						auset.insert(dude1[0][0]);
						auset.insert(dude2[1][1]);
						auset.insert(dude3[2][2]);
						auset.insert(dude4[3][3]);
						auset.insert(dude5[4][4]);
						if(sz(auset)==5)n++;
						auset.clear();
						auset.insert(dude1[0][4]);
						auset.insert(dude2[1][3]);
						auset.insert(dude3[2][2]);
						auset.insert(dude4[3][1]);
						auset.insert(dude5[4][0]);
						if(sz(auset)==5)n++;
						auset.clear();
						auset.insert(dude1[4][4]);
						auset.insert(dude2[3][3]);
						auset.insert(dude3[2][2]);
						auset.insert(dude4[1][1]);
						auset.insert(dude5[0][0]);
						if(sz(auset)==5)n++;
						auset.clear();
						auset.insert(dude1[4][0]);
						auset.insert(dude2[3][1]);
						auset.insert(dude3[2][2]);
						auset.insert(dude4[1][3]);
						auset.insert(dude5[0][4]);
						if(sz(auset)==5)n++;
						if(n>m){
							outvv(dude1);
							outvv(dude2);
							outvv(dude3);
							outvv(dude4);
							outvv(dude5);
							out<<m+85<<nl;
						}
					}
				}
				}
			}
			}
		}
		}
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}