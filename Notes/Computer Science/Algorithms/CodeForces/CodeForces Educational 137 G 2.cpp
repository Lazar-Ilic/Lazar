// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
 
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
using VUSETS=vector<USETS>;
using VVUSETS=vector<VUSETS>;
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
using VVULL=vector<VULL>;
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
using VPULL=vector<PULL>;
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
#define equalrange equal_range
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
I p=998244353; // 998244353 1000000007 1000000009 1000000000 433494437 993353399
//--------------------------------------------------------------------

bool arr0[1];
bool arr1[1];
bool arr2[2];
bool arr3[3];
bool arr4[5];
bool arr5[8];
bool arr6[13];
bool arr7[21];
bool arr8[34];
bool arr9[55];
bool arr10[89];
bool arr11[144];
bool arr12[233];
bool arr13[377];
bool arr14[610];
bool arr15[987];
bool arr16[1597];
bool arr17[2584];
bool arr18[4181];
bool arr19[6765];
bool arr20[10946];
bool arr21[17711];
bool arr22[28657];
bool arr23[46368];
bool arr24[75025];
bool arr25[121393];
bool arr26[196418];
bool arr27[317811];
bool arr28[514229];
bool arr29[832040];

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	L a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
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

	av={1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
	VB avb,bvb,cvb;
	VVB avvb;
	avvb=VVB(sz(av),VB(0));
	arr[0]=0;
	arr[1]=1;
	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	for(a=2;a>2-1;a--)arr2[a]=arr1[a-1];
	for(a=2-1;a>=0;a--)arr2[a]=arr0[a];

	//out<<avvb[2][0]<<" "<<avvb[2][1]<<nl;
	/*
	for(auto dude:avvb){
		for(auto dude1:dude)out<<dude1<<" ";
		out<<nl;
	}
	*/
	in>>a;
	avb=VB(0);
	bv=V(1000001);
	al=1; // Sum of values thus far.
	bv[0]=1;
	c=1;
	for(b=0;b<a;b++){
		in>>as;
		for(auto charr:as){
			if(charr=='0')avb.add(0);
			else avb.add(1);
		}
		y=0;
		for(;c<=sz(avb);c++){
			// Process index c in bv.
			bl=al;
			for(d=0;d<sz(av) and av[d]<=c;d++){
				// Process the previous av[d] string.
				bvb=avvb[d];
				z=1;
				for(e=sz(bvb)-1;e>=0 and z;e--){
					if(bvb[e]!=avb[c-1+e-sz(bvb)+1])z=0;
				}
				if(z)bl=(bl-bv[c-av[d]]+p)%p;
			}
			bv[c]=bl;
			y++;
			//if(y==1 and bl!=0)out<<bl<<nl;
			//out<<bv[c]<<nl;
			al=(al+bl)%p;
		}
		out<<bv[c-1]<<nl;
	}
	//out<<bv[c]<<nl;
}

I main(){zz();I a=1;while(a--){az();}}