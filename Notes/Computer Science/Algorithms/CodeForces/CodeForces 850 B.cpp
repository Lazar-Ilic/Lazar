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
using B=bool; // 8 bits = 1 byte | [0,1]
using C=char; // 8 bits = 1 byte | [-128,127]
using D=double; // 64 bits = 8 bytes | [Eh]
using LD=long double; // 96 bits = 12 bytes | [Eh]
using I=int; // 32 bits = 4 bytes | [-2147483648,2147483647]
using UI=unsigned int; // 32 bits = 4 bytes | [0,4294967295]
using U=uint64_t; // 64 bits = 8 bytes | [0,18446744073709551615]
using L=long long; // 64 bits = 8 bytes | [-9223372036854775808,9223372036854775807]
using ULL=unsigned long long; // 64 bits = 8 bytes | [0,18446744073709551615]
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
using VPSI=vector<PSI>;
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
#define prevpermutation prev_permutation
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399 409120391 1005075251

//--------------------------------------------------------------------

int minSwaps(V arr,I n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
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
Maybe do all the simple 2 swaps and then we are left with like some 3-cycles I would guess...

Umm OK so it is like isomorphic with sort each dudes hand and then have dude1 rank1 dude2 rank1 ... dude1 rank2 dude2 rank2... dude1 rank3... then we need to swap around in this dude so that the overall array is like WWWWIIIINNNN and then that is just like literally sorting that literal array in minimum number of swaps.

INWINWINW
 NWI WIN
  W  WIN
  W   I

This cycle detection algorithm presented here is mediocre obviously in the more general case if we had like WWWI on an underlying set of WING we would want to store this index twice maybe in a W +1 Surplus vector of indices and also this index once in each N -1 Lack and G -1 Lack vector of indices and then later shwoop through those vectors of indices with Surpli and Lack to deduce underlying cycles structures or bust out a more generic cycles detection implementation a la some other more performant submissions to this task that generalise well and easily beyond the n = 3 case.
*/

	in>>a;
	av=V(3*a,0);
	avs=VS(0);
	for(b=0;b<a;b++){
		in>>as;
		sort(all(as)); // i n w
		/*
		av[b]=1*(as[0]=='n')+2*(as[0]=='w');
		av[b+a]=1*(as[1]=='n')+2*(as[1]=='w');
		av[b+2*a]=1*(as[2]=='n')+2*(as[2]=='w');
		*/
		if(as=="iii"){
			av[b]=0;
			av[b+a]=0;
			av[b+2*a]=0;
		}
		else if(as=="nnn"){
			av[b]=1;
			av[b+a]=1;
			av[b+2*a]=1;
		}
		else if(as=="www"){
			av[b]=2;
			av[b+a]=2;
			av[b+2*a]=2;
		}
		else if(as=="iin"){
			av[b]=0;
			av[b+a]=1;
			av[b+2*a]=0;
		}
		else if(as=="inn"){
			av[b]=0;
			av[b+a]=1;
			av[b+2*a]=1;
		}
		else if(as=="iiw"){
			av[b]=0;
			av[b+a]=0;
			av[b+2*a]=2;
		}
		else if(as=="iww"){
			av[b]=0;
			av[b+a]=2;
			av[b+2*a]=2;
		}
		else if(as=="nnw"){
			av[b]=1;
			av[b+a]=1;
			av[b+2*a]=2;
		}
		else if(as=="nww"){
			av[b]=2;
			av[b+a]=1;
			av[b+2*a]=2;
		}
		else{
			av[b]=0;
			av[b+a]=1;
			av[b+2*a]=2;
		}
	}
	//outv(av);
	//out<<minSwaps(av,3*a)<<nl;
	avv=VV(6,V(0)); // Indices where a 1 is in a 0 spot 2 in 0 0 in 1 2 in 1 0 in 2 1 in 2...
	for(b=0;b<a;b++){
		if(av[b]==1)avv[0].add(b);
		else if(av[b]==2)avv[1].add(b);
	}
	for(b=a;b<2*a;b++){
		if(av[b]==0)avv[2].add(b);
		else if(av[b]==2)avv[3].add(b);
	}
	for(b=2*a;b<3*a;b++){
		if(av[b]==0)avv[4].add(b);
		else if(av[b]==1)avv[5].add(b);
	}
	bv=V(6);
	cv=V(6,0);
	bv[0]=sz(avv[0]);
	bv[1]=sz(avv[1]);
	bv[2]=sz(avv[2]);
	bv[3]=sz(avv[3]);
	bv[4]=sz(avv[4]);
	bv[5]=sz(avv[5]);
	z=0;
	while(cv[0]<bv[0] and cv[2]<bv[2]){
		z++;
		avs.add(to_string((avv[0][cv[0]])%a+1)+" n "+to_string((avv[2][cv[2]])%a+1)+" i");
		cv[0]++;
		cv[2]++;
	}
	while(cv[1]<bv[1] and cv[4]<bv[4]){
		z++;
		avs.add(to_string((avv[1][cv[1]])%a+1)+" w "+to_string((avv[4][cv[4]])%a+1)+" i");
		cv[1]++;
		cv[4]++;
	}
	while(cv[3]<bv[3] and cv[5]<bv[5]){
		z++;
		avs.add(to_string((avv[3][cv[3]])%a+1)+" w "+to_string((avv[5][cv[5]])%a+1)+" n");
		cv[3]++;
		cv[5]++;
	}
	while(cv[0]<bv[0] and cv[3]<bv[3] and cv[4]<bv[4]){
		z+=2;
		avs.add(to_string((avv[0][cv[0]])%a+1)+" n "+to_string((avv[3][cv[3]])%a+1)+" w");
		avs.add(to_string((avv[0][cv[0]])%a+1)+" w "+to_string((avv[4][cv[4]])%a+1)+" i");
		cv[0]++;
		cv[3]++;
		cv[4]++;
	}
	while(cv[1]<bv[1] and cv[2]<bv[2] and cv[5]<bv[5]){
		z+=2;
		avs.add(to_string((avv[1][cv[1]])%a+1)+" w "+to_string((avv[2][cv[2]])%a+1)+" i");
		avs.add(to_string((avv[2][cv[2]])%a+1)+" w "+to_string((avv[5][cv[5]])%a+1)+" n");
		cv[1]++;
		cv[2]++;
		cv[5]++;
	}
	out<<z<<nl;
	for(auto dude:avs){
		out<<dude<<nl;
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}