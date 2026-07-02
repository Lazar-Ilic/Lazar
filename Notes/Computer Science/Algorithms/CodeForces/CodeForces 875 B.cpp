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

I maximum=400001; // SSRS_
V spf(maximum+1,-1);
V primes;

VL factor(L n){
	VL avl;
	while(n>1){
		avl.add(spf[n]);
		n/=spf[n];
	}
	sortify(avl);
	return avl;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){ // Could plausibly be improved quite non trivially by considering sharper underlying execution and memory handling and also potentially even better handling if desiring the factorsof multiple different numbers at the same time.
	VPL avpl=primefactorisationof(n);
	VL avl,bvl;
	VVL avvl;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avpl)<15)avpl.add({1,0});
	for(a0=0;a0<15;a0++){
		bvl=VL(0);
		L cl=1;
		for(a1=0;a1<=avpl[a0].second;a1++){
			bvl.add(cl);
			cl*=avpl[a0].first;
		}
		avvl.add(bvl);
	}
	for(a0=0;a0<=avpl[0].second;a0++){
	for(a1=0;a1<=avpl[1].second;a1++){
	for(a2=0;a2<=avpl[2].second;a2++){
	for(a3=0;a3<=avpl[3].second;a3++){
	for(a4=0;a4<=avpl[4].second;a4++){
	for(a5=0;a5<=avpl[5].second;a5++){
	for(a6=0;a6<=avpl[6].second;a6++){
	for(a7=0;a7<=avpl[7].second;a7++){
	for(a8=0;a8<=avpl[8].second;a8++){
	for(a9=0;a9<=avpl[9].second;a9++){
	for(a10=0;a10<=avpl[10].second;a10++){
	for(a11=0;a11<=avpl[11].second;a11++){
	for(a12=0;a12<=avpl[12].second;a12++){
	for(a13=0;a13<=avpl[13].second;a13++){
	for(a14=0;a14<=avpl[14].second;a14++){
		avl.add(avvl[0][a0]*avvl[1][a1]*avvl[2][a2]*avvl[3][a3]*avvl[4][a4]*avvl[5][a5]*avvl[6][a6]*avvl[7][a7]*avvl[8][a8]*avvl[9][a9]*avvl[10][a10]*avvl[11][a11]*avvl[12][a12]*avvl[13][a13]*avvl[14][a14]);
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
	sort(all(avl));
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
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
Umm no logarithm transform trivially kills it but like sorting might uh... uh uh uh... sorting and then uh OKOKOK it must be that uh there is something simple here perhaps upper bounding the potential solutions to like uh 1 per dude or something... 2 per dude or uh something something yadda yadda yadda examine low n count cases uh... e^[log ai + log aj] is like uh... bi + bj or whatever uh... oh OKOKOK so the bs are uh upper bounded quite low really is interesting uh uh uh it means the products are also quite low really 10^10 order... oh wait 10^5 oh OKOKOK now I see that OKOKOK uh from the conditions written out quite crystal clearly technically and precisely here in uh \le pure mathematical notation which is actually half legible. For a uh fixed value of uh ai is like uh 1*aj=1+bj means that uh... 2*bj=2+bj 3*bj=3+bj yadda yadda yadda... OKOKOK never mind is like uh... strict < uh ungh... no no no not that simple uh... points and lines uh... the actual lines uh... ai*x=bi+y is like uh... the line y=aix-bi is like uh... a bunch of uh lines basically and the question is uh how many uh of these uh points uh... maybe there is uh some like segment tree uh approach uh somehow uh... dunno no no no dunno can not check uh how many dudes are precisely equal to some uh value. Oh uh seems to me like a uh canonical somehow uh uh uh canonical like each line uh in the uh relevant uh range obviously the only range we are concerned with really is inside of uh the uh actual uh relevant topical uh square I guess is uh uh uh... like we have these n lines in an n by n square and uh uh uh... n points and can do a simple checker checker with the minus off for i==j cases... OKOKOK usual segment intersections counting algorithms will fail here ugh ugh ugh and the background noise here is measuring in at 10dB louder than a UTAustin dormitory ugh... no way to uh naive simulate uh passing through from Left to Right interval sorting ugh. Unbelieable noise pollution here on a Sun Day morning brunch at the fucking bar I guess fucking louder than loud and I can not think. Well uh uh uh for sure uh try small cases uh when a value is low else uh we need for it to be the case that uh uh uh the other dude b value frankly is like uh summations have to be uh uh uh 0 modulo 0 modulo is like tricky uh... maybe there is some way to uh break in to relevant uh threshold somehow uh uh uh like a uh sqrt[n] approach somehow. Maybe uh different uh approach here like somehow bashing the first uh uh uh values less than 10 and then uh uh uh... oh OKOKOK for each uh dude like uh... for each uh point uh uh uh... for each uh x value uh uh uh we can certainly uh line up the uh relevant uh points and their multiplicities and then uh... actually uh uh uh uh for each potential uh sum value is like... how many ways can it be uh OKOKOK if we do like a sieve and then factor each one fast is like then uh uh uh... somehow uh uh uh for each uh Right dude in this uh uh uh factoring uh uh uh still like uh aj >= sqrt [sum] is like boom I think uh... prolly ACcepted I think uh... for each uh dude in the uh bracket on the right is still like uh... each dude can be the major in quite a few uh maybe... at most uh around uh 1000 per is like OKOKOK I think uh uh uh ... OKOKOK
*/

	//maximum=400001;
	//spf=V(maximum+1,-1);
	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}
	bvvl=VVL(400001,VL(0));
	in>>y;
	for(;y>0;y--){
	in>>a;
	av=V(a);
	bv=V(a);
	avv=VV(200000+1,V(0)); // Indices with this uh aj value uh...
	for(c=0;c<a;c++){
		in>>av[c];
		avv[av[c]].add(c);
	}
	for(c=0;c<a;c++){
		in>>bv[c];
	}
	MPI ampi;
	al=0;
	for(c=0;c<a;c++)ampi[{av[c],bv[c]}]++; // Number of pairs with this valuation pair uh.
	for(c=2;c<=400000;c++){
		// Find all factorisations of c in to the uh product and loop through dudes which actually had the relevant uh max searching for uh dudes uh...
		if(sz(bvvl[c])==0){avl=factorsof(L(c));bvvl[c]=avl;}
		else avl=bvvl[c];
		for(d=sz(avl)/2+(sz(avl)%2==1);d<sz(avl) and avl[d]<=200000;d++){
			// Factorised in to uh avl[d] * uh ... c/avl[d] works uh...
			for(auto indic:avv[avl[d]]){
				al+=ampi[{c/avl[d],c-bv[indic]}];
			}
			//al+=bl;
			//if(bl>0)out<<c<<" "<<bl<<nl;
			//if(!(sz(avl)%2==1 and d==sz(avl)/2))al+=bl;
			//else al+=bl/2;
			//out<<bl<<nl;
		}
		if(sz(avl)%2==1){
			bl=0;
			for(auto indic:avv[avl[sz(avl)/2]]){
				if(bv[indic]==c-bv[indic])bl+=ampi[{c/avl[sz(avl)/2],c-bv[indic]}]-1;
				else bl+=ampi[{c/avl[sz(avl)/2],c-bv[indic]}];
			}
			al+=bl/2;
		}
	}
	//for(c=0;c<a;c++)if(L(av[c])*av[c]==bv[c]+bv[c])al--;
	out<<al<<nl;
	}
}

I main(){zz();I a=1;while(a--){az();}}