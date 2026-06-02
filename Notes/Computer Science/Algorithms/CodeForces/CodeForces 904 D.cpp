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
using PDI=pair<D,I>;
using PLDI=pair<LD,I>;
using P=pair<I,I>;
using PIP=pair<I,P>;
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
using VPIP=vector<PIP>;
using VPL=vector<PL>; 
using VPLD=vector<PLD>;
using VPS=vector<PS>;
using VPIS=vector<PIS>;
using VPSI=vector<PSI>;
using VPLI=vector<PLI>;
using VPDI=vector<PDI>;
using VPLDI=vector<PLDI>;
using VPID=vector<PID>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVVV=vector<VVV>;
using VVL=vector<VL>;
using VVVL=vector<VVL>;
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
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);out<<fixed<<setprecision(10);
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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

VB isprime(1000001,true);
VL primes;
VL spf(1000001);
VL order(1000001);
Z sieve(L al){
    isprime[0]=isprime[1]=false;
    I c;
    for(L b=2;b<=al;b++){
        if(isprime[b]){
            primes.add(b);
            spf[b]=b;
        }
        c=sz(primes);
        for(L d=0;d<c && b*primes[d]<=al && primes[d]<=spf[b];d++){
            isprime[b*primes[d]]=false;
            spf[b*primes[d]]=primes[d];
        }
    }
	for(L b=2;b<=al;b++){
		if(isprime[b]){
			order[b]=1;
		}
		else if((b/spf[b])%spf[b]!=0){
			order[b]=1;
		}
		else{
			order[b]=1+order[b/spf[b]];
		}
	}
}
 
V primefactorsof(I a){
	V av;
	while(a!=1){
		if(sz(av)==0 or spf[a]!=av[sz(av)-1])av.add(spf[a]);
		a/=spf[a];
	}
	return av;
}
 
VP primefactorisationof(I a){
	VP avp;
	while(a!=1){
		if(sz(avp)==0 or spf[a]!=avp[sz(avp)-1].first)avp.add({spf[a],1});
		else if(spf[a]==avp[sz(avp)-1].first)avp[sz(avp)-1].second++;
		a/=spf[a];
	}
	return avp;
}

V factorsof(I n){
	VP avp=primefactorisationof(n);
	V av,bv;
	VV avv;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avp)<15)avp.add({1,0});
	for(a0=0;a0<15;a0++){
		bv=V(0);
		I c=1;
		for(a1=0;a1<=avp[a0].second;a1++){
			bv.add(c);
			c*=avp[a0].first;
		}
		avv.add(bv);
	}
	for(a0=0;a0<=avp[0].second;a0++){
	for(a1=0;a1<=avp[1].second;a1++){
	for(a2=0;a2<=avp[2].second;a2++){
	for(a3=0;a3<=avp[3].second;a3++){
	for(a4=0;a4<=avp[4].second;a4++){
	for(a5=0;a5<=avp[5].second;a5++){
	for(a6=0;a6<=avp[6].second;a6++){
	for(a7=0;a7<=avp[7].second;a7++){
	for(a8=0;a8<=avp[8].second;a8++){
	for(a9=0;a9<=avp[9].second;a9++){
	for(a10=0;a10<=avp[10].second;a10++){
	for(a11=0;a11<=avp[11].second;a11++){
	for(a12=0;a12<=avp[12].second;a12++){
	for(a13=0;a13<=avp[13].second;a13++){
	for(a14=0;a14<=avp[14].second;a14++){
		av.add(avv[0][a0]*avv[1][a1]*avv[2][a2]*avv[3][a3]*avv[4][a4]*avv[5][a5]*avv[6][a6]*avv[7][a7]*avv[8][a8]*avv[9][a9]*avv[10][a10]*avv[11][a11]*avv[12][a12]*avv[13][a13]*avv[14][a14]);
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
	}
	}
	}
	}
	}
	sort(all(av));
	return av;
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
Imagine moving from Left to Right here if we use say 3 for example as a dude which appears and cancel out any pair of dudes which were divisible by 3 then we should also block those off from future consideration at which point we swoop through in a simple enough vector of booleans appproach here I would think frankly and long long the valid answer. Aha I see so yet another simple logical error from me here and I realise it is Not That Simple. Perhaps there is something else here with sieves or polylogarithmic algorithms or some such thing. Harmonic series if OK means we can move from Right to Left here and knock out any dude who has already been captured I think up top uh actually uh like... n log^2[n] is even good enough here maybe somehow to process from Right to Left like uh... sieve and then uh... add each dude in to each of its divisors and then uh... process from Right to Left and uh... or somehow from Left to Right and when we process this 2 dude somehow include the 6 dude in an off counter ugh... for 6 or whatever... so that way uh pairs of already processed like uh... pairs of already processed 6 dudes get killed I think Left to Right works in conjunction with sieve up front frankly here...
*/

	in>>a;
	al=L(a)*(a-1)/2;
	av=V(a+1);
	avl=VL(a+1);
	avb=VB(a+1);
	for(b=0;b<a;b++){
		in>>c;
		av[c]++;
		avb[c]=1;
	}
	sieve(1000000);
	for(b=1;b<=a;b++){
		if(avb[b]){
			for(c=b;c<=a;c+=b)avb[c]=0;
			bl=0;
			for(c=b;c<=a;c+=b){
				bl+=av[c];
				al+=avl[c]*(avl[c]-1)/2; // Not the Number Theoretically correct quantity here to recorrect ugh think this round should have been a trivial upfront onsight for me to figure out how to account for each of these dudes once in like O[n * log[n]] ugh better luck later today on the next round of the day maybe.
				for(auto dude:factorsof(c))avl[dude]+=av[c];
			}
			al-=bl*(bl-1)/2;
			//out<<b<<" "<<bl<<" "<<al<<nl;
		}
	}
	out<<al<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}