// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <sys/time.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits = 16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
using PSI=pair<S,I>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using USETP=unordered_set<P>;
using USETL=unordered_set<L>;
using USETS=unordered_set<S>;
using MSET=multiset<I>;
using MSETP=multiset<P>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETULL=set<ULL>;
using SETP=set<P>;
using SETSETP=set<SETP>;
using SETPL=set<PL>;
using SETPSI=set<PSI>;
using PLSET=pair<L,SET>;
using VPLSET=vector<PLSET>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MIL=map<I,L>;
using MIMII=map<I,MII>;
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
using VB=vector<B>;
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
using VUSETS=vector<USETS>;
using VVUSETS=vector<VUSETS>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VUI=vector<UI>;
using VL=vector<L>;
using VULL=vector<ULL>;
using VUI128=vector<UI128>;
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
using VPSI=vector<PSI>;
using VPID=vector<PID>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVVV=vector<VVV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VVULL=vector<VULL>;
using VSET=vector<SET>;
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using PQ=priority_queue<I>;
using MINPQ=priority_queue<I,V,greater<I>>;
using PQL=priority_queue<L>;
using MINPQL=priority_queue<L,VL,greater<L>>;
using PQP=priority_queue<P>;
using MINPQP=priority_queue<P,VP,greater<P>>;
using PQPL=priority_queue<PL>;
using MINPQPL=priority_queue<PL,VPL,greater<PL>>;
using SETV=set<V>;
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MLV=map<L,V>;
using MVI=map<V,I>;
using MVV=map<V,V>;
using MVBV=map<VB,V>;
using PIV=pair<I,V>;
using PDV=pair<D,V>;
using PULL=pair<ULL,ULL>;
using VPULL=vector<PULL>;
using MULLPULL=map<ULL,PULL>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
using CLD=complex<LD>;
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
#define equalrange equal_range
#define nextpermutation next_permutation
#define prevpermutation prev_permutation
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsetsize __builtin_popcount
#define subsetsizeL __builtin_popcountll
#define shuf random_shuffle
#define sz(a) int((a).size())
#define all(a) ((a).begin()),((a).end())
#define sortify(a) sort(all(a))
#define uniquify(a) (a).resize(unique(all(a))-(a).begin())
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
const I p=998244353; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

L casecount;
I avvchecker(VV avv){
	casecount++;
	if(casecount%10000000==0)out<<casecount<<nl;
	// Simple little checker function here rather than writing it in loop and copying and pasting that code segment ~7 times which could blow up to ~20 times in a larger case implementation here. As this is just a partial checker all we can do is ensure the GCD and 2x2 conditions are not yet broken... later we can check for connectedness and compute the desired answer solution areas product value. Probably this should trim down enough that I can just eyeball if the GCD conditions and connectedness are Truly satisfied.
	V bv={5,1,6,1,8,1,22,7,8};
	V cv={55,1,6,1,24,3,6,7,2};
	for(I a=0;a<8;a++)for(I b=0;b<8;b++)if(avv[a][b]>0 and avv[a+1][b]>0 and avv[a][b+1]>0 and avv[a+1][b+1]>0)return 0;
	for(I a=0;a<9;a++){
		// Check row on GCD condition with pointer to last 0 value is uh preceding the current integer string value.
		I z=-1;
		I lolgcd=0;
		for(I b=0;b<9;b++){
			if(avv[a][b]<=0 and b-z==1)z=b;
			else if(avv[a][b]<=0){
				// Actually check this actual value here.
				if((z==-1 or avv[a][z]==-1) and avv[a][b]==-1){
					I y=0;
					I x=1;
					for(I c=b-1;c>z;c--){
						y+=x*avv[a][c];
						x*=10;
					}
					if(y%cv[a]!=0)return 0;
					if(lolgcd==0)lolgcd=y;
					else lolgcd=gcd(lolgcd,y);
				}
				z=b;
			}
		}
		// And check the back too.
		if(9-z>1 and z>-1 and avv[a][z]==-1){
			I y=0;
			I x=1;
			for(I c=9-1;c>z;c--){
				y+=x*avv[a][c];
				x*=10;
			}
			if(y%cv[a]!=0)return 0;
			if(lolgcd==0)lolgcd=y;
			else lolgcd=gcd(lolgcd,y);
		}
		z=1;
		for(I b=0;b<9 and z;b++)if(avv[a][b]!=-1)z=0;
		if(z)return 0; // All -1s
		z=1;
		for(I b=0;b<9 and z;b++)if(avv[a][b]==0)z=0;
		if(z and lolgcd!=cv[a])return 0;
	}
	for(I a=0;a<9;a++){
		// Check column on GCD condition with pointer to last 0 value is uh preceding the current integer string value.
		I z=-1;
		I lolgcd=0;
		for(I b=0;b<9;b++){
			if(avv[b][a]<=0 and b-z==1)z=b;
			else if(avv[b][a]<=0){
				// Actually check this actual value here.
				if((z==-1 or avv[z][a]==-1) and avv[b][a]==-1){
					I y=0;
					I x=1;
					for(I c=b-1;c>z;c--){
						y+=x*avv[c][a];
						x*=10;
					}
					if(y%bv[a]!=0)return 0;
					if(lolgcd==0)lolgcd=y;
					else lolgcd=gcd(lolgcd,y);
				}
				z=b;
			}
		}
		// And check the back too.
		if(9-z>1 and z>-1 and avv[z][a]==-1){
			I y=0;
			I x=1;
			for(I c=9-1;c>z;c--){
				y+=x*avv[c][a];
				x*=10;
			}
			if(y%bv[a]!=0)return 0;
			if(lolgcd==0)lolgcd=y;
			else lolgcd=gcd(lolgcd,y);
		}
		z=1;
		for(I b=0;b<9 and z;b++)if(avv[b][a]!=-1)z=0;
		if(z)return 0; // All -1s
		z=1;
		for(I b=0;b<9 and z;b++)if(avv[b][a]==0)z=0;
		if(z and lolgcd!=bv[a])return 0;
	}
	return 1;
}

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
	VB avb,bvb,cvb,dvb,evb,fvb,gvb,hvb,ivb,jvb,kvb,lvb,mvb;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
	VVB avvb,bvvb,cvvb,dvvb,evvb,fvvb,gvvb,hvvb,ivvb,jvvb;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;
	MINPQ aminpq,bminpq,cminpq,dminpq,eminpq,fminpq,gminpq;

/*
Post Contest Analysis:


Test + Additional Input:


Analysis:

*/

	//in>>a;
	/*
	av={3,4,6,9};
	do{
		// Test this permutation
		z=1; // Still potentially valid.
		for(a=0;a<4 and z;a++){
			for(b=0;b<4 and z;b++){
				for(c=0;c<4 and z;c++){
					for(d=0;d<4 and z;d++){
						for(e=0;e<4 and z;e++){
							for(f=0;f<4 and z;f++){
								for(g=0;g<4 and z;g++){
									for(h=0;h<4 and z;h++){
										// Can just cycle through uh potential uh permutations up here I guess uh... potentially even this is AC code just uh assuming most will uh uh uh OKOKOK that is a no go I think uh... might need to return to those uh things.
									}
								}
							}
						}
					}
				}
			}
		}
	}while(nextpermutation(all(av)));
	*/

	casecount=0;
	av={1,2,3,4,5,6,7,8,9}; // Can customise based around centaur hypotheses.
	bv={5,1,6,1,8,1,22,7,8};
	cv={55,1,6,1,24,3,6,7,2};
	I a1,a2,a3,a4,a5,a6,a7,a8,a9,b1,b2,b3,b4,b5,b6,b7,b8,b9,c1,c2,c3,c4,c5,c6,c7,c8,c9,d1,d2,d3,d4,d5,d6,d7,d8,d9;
	do{
		// Test this permutation of values on the Ls. Represent the underlying Ls potentially via uh a simple sort of a 4 variables representing the row and column numbers in min max order... and also can use 0 as the auxiliary null is simple and fast enough here. So the permutation will have the final value representing the uh whatever but can check first that the permutation is even theoretically uh OKOKOK... and can also try out our own preferred permutations and hypotheses up front faster if needed or desired in other cases like say an n=20 or n=16 case more general setting. Need to undo the previous modifications every time we loop back in the for loops ugh. And also ugh track could use uh separate variables or uh like modify uh... might be easier syntactically to use uh separate variables uh... can check all of the conditions as we go maybe maybe maybe uh even in a separate function potentially or simply write it in as a for loop here.
		avv=VV(9,V(9,0));
		z=1;
		// First check that this permutation is potentially valid. Needs the first 2 to be 1 and 2 and then size matters from there... OK for bashing my own custom permutations might try here like uh 5 8 7 and then uh closely uh examine what can go down like 5 8 7 9 6 4 3 2 1 and swip swap around as needed. Or kill off these final conditions as we deduce they are in actually factually Wrong I mean potentially could bash up to 720 of these uh cases if needed over days but like... one would hope the 5 8 7 deduction at least was sharp... could actually be uh 5 9 8 7... uh...
		if(!(av[0]==1 and av[1]==2 and av[8]==5 and av[7]==8 and av[6]==7))z=0;
		for(e=2;e<9 and z;e++)if(av[e]>2*e+1)z=0;
		if(z){
		V dv1(3,-1);
		V ev1(5,-1);
		V fv1(7,-1);
		V gv1(9,-1);
		V hv1(11,-1);
		V iv1(13,-1);
		V jv1(15,-1);
		V kv1(17,-1);
		for(e=3-1;e>=3-av[1];e--)dv1[e]=av[1];
		for(e=5-1;e>=5-av[2];e--)ev1[e]=av[2];
		for(e=7-1;e>=7-av[3];e--)fv1[e]=av[3];
		for(e=9-1;e>=9-av[4];e--)gv1[e]=av[4];
		for(e=11-1;e>=11-av[5];e--)hv1[e]=av[5];
		for(e=13-1;e>=13-av[6];e--)iv1[e]=av[6];
		for(e=15-1;e>=15-av[7];e--)jv1[e]=av[7];
		for(e=17-1;e>=17-av[8];e--)kv1[e]=av[8];
		a1=0;
		b1=8;
		c1=0;
		d1=8;
		for(e=0;e<1;e++){
			for(y=c1;y<=d1;y++){avv[a1][y]=0;avv[b1][y]=0;}
			for(y=a1+1;y<=b1-1;y++){avv[y][c1]=0;avv[y][d1]=0;}
			kv=kv1;
			al=0;
			if(avvchecker(avv)){do{
				// Set the relevant values in avv.
				if(e==0){
					for(y=c1;y<=d1;y++)avv[a1][y]=kv[y-c1];
					for(y=a1+1;y<=b1;y++)avv[y][c1]=kv[17-1-(y-(a1+1))];
					a2=a1+1;
					b2=b1;
					c2=c1+1;
					d2=d1;
				}
				else if(e==1){
					for(y=c1;y<=d1;y++)avv[a1][y]=kv[y-c1];
					for(y=a1+1;y<=b1;y++)avv[y][d1]=kv[17-1-(y-(a1+1))];
					a2=a1+1;
					b2=b1;
					c2=c1;
					d2=d1-1;
				}
				else if(e==2){
					for(y=c1;y<=d1;y++)avv[b1][y]=kv[y-c1];
					for(y=a1;y<=b1-1;y++)avv[y][c1]=kv[17-1-(y-(a1))];
					a2=a1;
					b2=b1-1;
					c2=c1+1;
					d2=d1;
				}
				else if(e==3){
					for(y=c1;y<=d1;y++)avv[b1][y]=kv[y-c1];
					for(y=a1;y<=b1-1;y++)avv[y][d1]=kv[17-1-(y-(a1))];
					a2=a1;
					b2=b1-1;
					c2=c1;
					d2=d1-1;
				}
				for(f=3;f<4;f++){
					for(y=c2;y<=d2;y++){avv[a2][y]=0;avv[b2][y]=0;}
					for(y=a2+1;y<=b2-1;y++){avv[y][c2]=0;avv[y][d2]=0;}
					jv=jv1;
				al++;
				if(al%100==0)out<<al<<nl;
				if(avvchecker(avv)){do{
				// And similarly inductively ought to work here and AC in time.
				// Set the relevant values in avv.
				if(f==0){
					for(y=c2;y<=d2;y++)avv[a2][y]=jv[y-c2];
					for(y=a2+1;y<=b2;y++)avv[y][c2]=jv[15-1-(y-(a2+1))];
					a3=a2+1;
					b3=b2;
					c3=c2+1;
					d3=d2;
				}
				else if(f==1){
					for(y=c2;y<=d2;y++)avv[a2][y]=jv[y-c2];
					for(y=a2+1;y<=b2;y++)avv[y][d2]=jv[15-1-(y-(a2+1))];
					a3=a2+1;
					b3=b2;
					c3=c2;
					d3=d2-1;
				}
				else if(f==2){
					for(y=c2;y<=d2;y++)avv[b2][y]=jv[y-c2];
					for(y=a2;y<=b2-1;y++)avv[y][c2]=jv[15-1-(y-(a2))];
					a3=a2;
					b3=b2-1;
					c3=c2+1;
					d3=d2;
				}
				else if(f==3){
					for(y=c2;y<=d2;y++)avv[b2][y]=jv[y-c2];
					for(y=a2;y<=b2-1;y++)avv[y][d2]=jv[15-1-(y-(a2))];
					a3=a2;
					b3=b2-1;
					c3=c2;
					d3=d2-1;
				}
				for(g=3;g<4;g++){
					for(y=c3;y<=d3;y++){avv[a3][y]=0;avv[b3][y]=0;}
					for(y=a3+1;y<=b3-1;y++){avv[y][c3]=0;avv[y][d3]=0;}
					iv=iv1;
				if(avvchecker(avv)){do{
				if(g==0){
					for(y=c3;y<=d3;y++)avv[a3][y]=iv[y-c3];
					for(y=a3+1;y<=b3;y++)avv[y][c3]=iv[13-1-(y-(a3+1))];
					a4=a3+1;
					b4=b3;
					c4=c3+1;
					d4=d3;
				}
				else if(g==1){
					for(y=c3;y<=d3;y++)avv[a3][y]=iv[y-c3];
					for(y=a3+1;y<=b3;y++)avv[y][d3]=iv[13-1-(y-(a3+1))];
					a4=a3+1;
					b4=b3;
					c4=c3;
					d4=d3-1;
				}
				else if(g==2){
					for(y=c3;y<=d3;y++)avv[b3][y]=iv[y-c3];
					for(y=a3;y<=b3-1;y++)avv[y][c3]=iv[13-1-(y-(a3))];
					a4=a3;
					b4=b3-1;
					c4=c3+1;
					d4=d3;
				}
				else if(g==3){
					for(y=c3;y<=d3;y++)avv[b3][y]=iv[y-c3];
					for(y=a3;y<=b3-1;y++)avv[y][d3]=iv[13-1-(y-(a3))];
					a4=a3;
					b4=b3-1;
					c4=c3;
					d4=d3-1;
				}
				for(h=0;h<4;h++){
					for(y=c4;y<=d4;y++){avv[a4][y]=0;avv[b4][y]=0;}
					for(y=a4+1;y<=b4-1;y++){avv[y][c4]=0;avv[y][d4]=0;}
					hv=hv1;
				if(avvchecker(avv)){do{
				if(h==0){
					for(y=c4;y<=d4;y++)avv[a4][y]=hv[y-c4];
					for(y=a4+1;y<=b4;y++)avv[y][c4]=hv[11-1-(y-(a4+1))];
					a5=a4+1;
					b5=b4;
					c5=c4+1;
					d5=d4;
				}
				else if(h==1){
					for(y=c4;y<=d4;y++)avv[a4][y]=hv[y-c4];
					for(y=a4+1;y<=b4;y++)avv[y][d4]=hv[11-1-(y-(a4+1))];
					a5=a4+1;
					b5=b4;
					c5=c4;
					d5=d4-1;
				}
				else if(h==2){
					for(y=c4;y<=d4;y++)avv[b4][y]=hv[y-c4];
					for(y=a4;y<=b4-1;y++)avv[y][c4]=hv[11-1-(y-(a4))];
					a5=a4;
					b5=b4-1;
					c5=c4+1;
					d5=d4;
				}
				else if(h==3){
					for(y=c4;y<=d4;y++)avv[b4][y]=hv[y-c4];
					for(y=a4;y<=b4-1;y++)avv[y][d4]=hv[11-1-(y-(a4))];
					a5=a4;
					b5=b4-1;
					c5=c4;
					d5=d4-1;
				}
				for(i=0;i<4;i++){
					for(y=c5;y<=d5;y++){avv[a5][y]=0;avv[b5][y]=0;}
					for(y=a5+1;y<=b5-1;y++){avv[y][c5]=0;avv[y][d5]=0;}
					gv=gv1;
				if(avvchecker(avv)){do{
				if(i==0){
					for(y=c5;y<=d5;y++)avv[a5][y]=gv[y-c5];
					for(y=a5+1;y<=b5;y++)avv[y][c5]=gv[9-1-(y-(a5+1))];
					a6=a5+1;
					b6=b5;
					c6=c5+1;
					d6=d5;
				}
				else if(i==1){
					for(y=c5;y<=d5;y++)avv[a5][y]=gv[y-c5];
					for(y=a5+1;y<=b5;y++)avv[y][d5]=gv[9-1-(y-(a5+1))];
					a6=a5+1;
					b6=b5;
					c6=c5;
					d6=d5-1;
				}
				else if(i==2){
					for(y=c5;y<=d5;y++)avv[b5][y]=gv[y-c5];
					for(y=a5;y<=b5-1;y++)avv[y][c5]=gv[9-1-(y-(a5))];
					a6=a5;
					b6=b5-1;
					c6=c5+1;
					d6=d5;
				}
				else if(i==3){
					for(y=c5;y<=d5;y++)avv[b5][y]=gv[y-c5];
					for(y=a5;y<=b5-1;y++)avv[y][d5]=gv[9-1-(y-(a5))];
					a6=a5;
					b6=b5-1;
					c6=c5;
					d6=d5-1;
				}
				for(j=0;j<4;j++){
					for(y=c6;y<=d6;y++){avv[a6][y]=0;avv[b6][y]=0;}
					for(y=a6+1;y<=b6-1;y++){avv[y][c6]=0;avv[y][d6]=0;}
					fv=fv1;
				if(avvchecker(avv)){do{
				if(j==0){
					for(y=c6;y<=d6;y++)avv[a6][y]=fv[y-c6];
					for(y=a6+1;y<=b6;y++)avv[y][c6]=fv[7-1-(y-(a6+1))];
					a7=a6+1;
					b7=b6;
					c7=c6+1;
					d7=d6;
				}
				else if(j==1){
					for(y=c6;y<=d6;y++)avv[a6][y]=fv[y-c6];
					for(y=a6+1;y<=b6;y++)avv[y][d6]=fv[7-1-(y-(a6+1))];
					a7=a6+1;
					b7=b6;
					c7=c6;
					d7=d6-1;
				}
				else if(j==2){
					for(y=c6;y<=d6;y++)avv[b6][y]=fv[y-c6];
					for(y=a6;y<=b6-1;y++)avv[y][c6]=fv[7-1-(y-(a6))];
					a7=a6;
					b7=b6-1;
					c7=c6+1;
					d7=d6;
				}
				else if(j==3){
					for(y=c6;y<=d6;y++)avv[b6][y]=fv[y-c6];
					for(y=a6;y<=b6-1;y++)avv[y][d6]=fv[7-1-(y-(a6))];
					a7=a6;
					b7=b6-1;
					c7=c6;
					d7=d6-1;
				}
				for(k=0;k<4;k++){
					for(y=c7;y<=d7;y++){avv[a7][y]=0;avv[b7][y]=0;}
					for(y=a7+1;y<=b7-1;y++){avv[y][c7]=0;avv[y][d7]=0;}
					ev=ev1;
				if(avvchecker(avv)){do{
				if(k==0){
					for(y=c7;y<=d7;y++)avv[a7][y]=ev[y-c7];
					for(y=a7+1;y<=b7;y++)avv[y][c7]=ev[5-1-(y-(a7+1))];
					a8=a7+1;
					b8=b7;
					c8=c7+1;
					d8=d7;
				}
				else if(k==1){
					for(y=c7;y<=d7;y++)avv[a7][y]=ev[y-c7];
					for(y=a7+1;y<=b7;y++)avv[y][d7]=ev[5-1-(y-(a7+1))];
					a8=a7+1;
					b8=b7;
					c8=c7;
					d8=d7-1;
				}
				else if(k==2){
					for(y=c7;y<=d7;y++)avv[b7][y]=ev[y-c7];
					for(y=a7;y<=b7-1;y++)avv[y][c7]=ev[5-1-(y-(a7))];
					a8=a7;
					b8=b7-1;
					c8=c7+1;
					d8=d7;
				}
				else if(k==3){
					for(y=c7;y<=d7;y++)avv[b7][y]=ev[y-c7];
					for(y=a7;y<=b7-1;y++)avv[y][d7]=ev[5-1-(y-(a7))];
					a8=a7;
					b8=b7-1;
					c8=c7;
					d8=d7-1;
				}
				for(l=0;l<4;l++){
					for(y=c8;y<=d8;y++){avv[a8][y]=0;avv[b8][y]=0;}
					for(y=a8+1;y<=b8-1;y++){avv[y][c8]=0;avv[y][d8]=0;}
					dv=dv1;
				if(avvchecker(avv)){do{
				if(l==0){
					for(y=c8;y<=d8;y++)avv[a8][y]=dv[y-c8];
					for(y=a8+1;y<=b8;y++)avv[y][c8]=dv[3-1-(y-(a8+1))];
					a9=a8+1;
					b9=b8;
					c9=c8+1;
					d9=d8;
				}
				else if(l==1){
					for(y=c8;y<=d8;y++)avv[a8][y]=dv[y-c8];
					for(y=a8+1;y<=b8;y++)avv[y][d8]=dv[3-1-(y-(a8+1))];
					a9=a8+1;
					b9=b8;
					c9=c8;
					d9=d8-1;
				}
				else if(l==2){
					for(y=c8;y<=d8;y++)avv[b8][y]=dv[y-c8];
					for(y=a8;y<=b8-1;y++)avv[y][c8]=dv[3-1-(y-(a8))];
					a9=a8;
					b9=b8-1;
					c9=c8+1;
					d9=d8;
				}
				else if(l==3){
					for(y=c8;y<=d8;y++)avv[b8][y]=dv[y-c8];
					for(y=a8;y<=b8-1;y++)avv[y][d8]=dv[3-1-(y-(a8))];
					a9=a8;
					b9=b8-1;
					c9=c8;
					d9=d8-1;
				}
				avv[a9][c9]=1;
				if(avvchecker(avv))outvv(avv);
				avv[a9][c9]=0;
			}while(nextpermutation(all(dv)));}
			for(y=c8;y<=d8;y++){avv[a8][y]=0;avv[b8][y]=0;}
			for(y=a8+1;y<=b8-1;y++){avv[y][c8]=0;avv[y][d8]=0;}
			}
			}while(nextpermutation(all(ev)));}
			for(y=c7;y<=d7;y++){avv[a7][y]=0;avv[b7][y]=0;}
			for(y=a7+1;y<=b7-1;y++){avv[y][c7]=0;avv[y][d7]=0;}
			}
			}while(nextpermutation(all(fv)));}
			for(y=c6;y<=d6;y++){avv[a6][y]=0;avv[b6][y]=0;}
			for(y=a6+1;y<=b6-1;y++){avv[y][c6]=0;avv[y][d6]=0;}
			}
			}while(nextpermutation(all(gv)));}
			for(y=c5;y<=d5;y++){avv[a5][y]=0;avv[b5][y]=0;}
			for(y=a5+1;y<=b5-1;y++){avv[y][c5]=0;avv[y][d5]=0;}
			}
			}while(nextpermutation(all(hv)));}
			for(y=c4;y<=d4;y++){avv[a4][y]=0;avv[b4][y]=0;}
			for(y=a4+1;y<=b4-1;y++){avv[y][c4]=0;avv[y][d4]=0;}
			}
			}while(nextpermutation(all(iv)));}
			for(y=c3;y<=d3;y++){avv[a3][y]=0;avv[b3][y]=0;}
			for(y=a3+1;y<=b3-1;y++){avv[y][c3]=0;avv[y][d3]=0;}
			}
			}while(nextpermutation(all(jv)));}
			for(y=c2;y<=d2;y++){avv[a2][y]=0;avv[b2][y]=0;}
			for(y=a2+1;y<=b2-1;y++){avv[y][c2]=0;avv[y][d2]=0;}
			}
			}while(nextpermutation(all(kv)));}
			// Can also potentially uh uh uh right here reset the values from the previous L by uh simply going through one more time in the current L state and uh replacing them with 0s here in loop. Or do that part up top at the beginning of the for loop uh ensure that the outer ring of the current square is set to all 0s...
		for(y=c1;y<=d1;y++){avv[a1][y]=0;avv[b1][y]=0;}
		for(y=a1+1;y<=b1-1;y++){avv[y][c1]=0;avv[y][d1]=0;}
		}
	}
	}while(nextpermutation(all(av)));
}

I main(){zz();I a=1;while(a--){az();}}


/*
- - - - - 5 5 - - 
5 - 9 9 9 - 9 - 8 
5 9 6 - - - 4 7 8 
- 9 - 4 0 0 0 - 8 
- 9 6 4 0 0 0 7 8 
- 9 - 4 0 0 0 7 - 
- 9 6 6 6 - 6 7 8 
- - - 7 - 7 7 - - 
5 8 - - - - 8 - 8 

Somewhat interesting output as the first case to break in to the 3s...

- - - - - 5 5 - - 
5 - 9 9 9 - 9 - 8 
- 9 6 - 4 4 4 7 8 
5 9 - 4 3 - - 7 - 
- 9 6 - 3 1 2 - - 
- 9 - - 3 - 2 7 - 
- 9 6 6 6 6 - 7 8 
- - - 7 - 7 - 7 - 
5 8 - 8 8 8 - - 8 

- - - - - 5 5 - - 
5 9 - 9 9 - 9 - 8 
- 9 6 - 4 4 4 7 8 
5 9 - 4 3 - - 7 - 
- 9 6 - 3 1 2 - - 
- 9 - - 3 - 2 7 - 
- 9 6 6 6 6 - 7 8 
- - - 7 - 7 - 7 - 
5 8 - 8 8 8 - - 8 

- - - - - 5 5 - - 
5 9 9 9 9 - 9 - 8 
- - 6 - 4 4 4 7 8 
5 9 - 4 3 - - 7 - 
- 9 6 - 3 1 2 - - 
- 9 - - 3 - 2 7 - 
- 9 6 6 6 6 - 7 8 
- - - 7 - 7 - 7 - 
5 8 - 8 8 8 - - 8 

- - - - - 5 5 - - 
5 9 9 9 9 - 9 7 8 
- - 6 - 4 4 4 - - 
5 9 - 4 3 - - 7 8 
- 9 6 - 3 1 2 - - 
- 9 - - 3 - 2 7 - 
- 9 6 6 6 6 - 7 8 
- - - 7 - 7 - 7 - 
5 8 - 8 8 8 - - 8 

And then uh these pop out too...

Could just try playing around with these uh here a little bit... to force connected uh...

5 5 - - - 5 5 - - 
- 9 9 9 9 - 9 - 8 
- - 6 - 4 4 4 7 8 
- 9 - 4 3 - - - 8
- 9 6 - 3 1 2 - - 
- 9 - - 3 - 2 7 - 
- 9 6 6 6 6 - 7 8 
- 7 - 7 - 7 - 7 - 
5 8 - 8 8 8 - - - 
*/