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
const I p=998244353; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399

//--------------------------------------------------------------------

L factorials[2000001];
I factorialsmax;
L factorial(L al){
    L bl;
    factorials[0]=1;
    if(al<=factorialsmax){
        return factorials[al];
    }
    else{
        for(bl=factorialsmax+1;bl<=al;bl++){
            factorials[bl]=factorials[bl-1]*bl%p;
        }
        factorialsmax=al;
        return factorials[al];
    }
}
L inverse(L al){
    L bl=1;
    I a=p-2;
    while(a!=0){
        if(a%2==1){
            bl=bl*al%p;
        }
        al=al*al%p;
        a/=2;
    }
    return bl;
}
L inversefactorials[2000001];
I inversefactorialsaux[2000001];
L inversefactorial(L al){
    if(inversefactorialsaux[al]==0){
        inversefactorialsaux[al]=1;
        inversefactorials[al]=inverse(factorial(al));
    }
    return inversefactorials[al];
}
L choose(L al,L bl){
	if(bl>al or bl<0 or al<0)return 0;
    return factorial(al)*inversefactorial(bl)%p*inversefactorial(al-bl)%p;
}
L multinomial(L al,VL avl){
    I a;
    al=factorial(al);
    for(a=0;a<sz(avl);a++){
        al=(al*inversefactorial(avl[a]))%p;
    }
    return al;
}
L exp(L al,L bl){
    L cl=1;
    while(bl>0){
        if(bl%2==1){
            cl=cl*al%p;
        }
        al=al*al%p;
        bl/=2;
    }
    return cl;
}
L exppp(L al,L bl,L cl){ // (Base,Exponent,Modulus)
    L dl=1;
    while(bl>0){
        if(bl%2==1){
            dl=dl*al%cl;
        }
        al=al*al%cl;
        bl/=2;
    }
    return dl;
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
Consider how many ways to label a full binary tree or whatever OKOKOK think the indexing is fixed or whateer e.g. i points into 2i and 2i+1 down the tree like

1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
etc. etc.

UGH could be easier OKOKOK reduces to arbitrary dude on like Ath level and non dependent dude on Bth level I think... but probably some number theoretic computation based around the permutation of the exponent too after realising some fairly deep structure here about the Probabilities. Think dunno the ugh number of ways to order once we pick like dependent upstream and downstream sets of those 2 dudes is like fixed due to a relative ordering so it suffices to choose how many ways we can pick ugh like this Uth value is < Vth value an then sum up some binomial computation on the number of upstream and downstream dudes quite simply I think. It is just like well ugh computing over all the dudes might be kind of tricky ugh I mean summing over from a to b of a to b of 2^5000 is way too much... but then sum over ways to choose whatever whatever inequality of course. Of course there are [A-1] upstream and [B-1] upstream dudes for each is maybe simple and then ugh compute the downstream depending on the actual explicit values is still like for a sum of a casework is still like a brutal massive binomial sum but hockey stick identity might work quite frankly ugh. And need ugh so it is lowkey like there is a chain leading into the expansion which is lowkey maybe like ummm selecting ugh simply case into the like [A+B+2^[]-1+2^[-1]] dudes i.e. [A-1+B-1+2^[n-A-1]+2^[n-B-1]] dudes and then selecting from there... ugh think it is actually more like [A+B+2^[n-A-1]+2^[n-B-1]] dudes we select those 2 chains from etc. etc. perhaps say we have chosen now and it does not matter actually the A value the B value and the chains but from there ugh it is still like the casework on the number of permutations inducing that ugh which is like to say ugh the actual evaluation still here has to do with what what but like ugh multiply by the other selection too I think. So still it reduces I think into a WLOG about breaking down a partition into like ugh still the multiplicity on the downstreams do not matter from there so it is still like something about ugh they don't matter they are always the same it reduces still into this selection of the partition. Sum from A=A to the top of like ugh selecting the upstream oh it must be like sum from A=A to A+B or whatever if A is going to be < the B value due to induced upstream. Oh well all the dudes from 1 to the AA value are upstream and inclusive so there ugh maybe it is a like simple summation from 1+A to 1+A+B or whatever on the way to select the upstream chain and then force the rest and then select the rest which is like still a simple binary searchy thingy I think with low bottom counts that can be manually executed. And then sum from 1+A+1 to 1+A+B+1 or whatever the less you know in denominator. Ugh write this summation out and evaluate if it is a hockeystick instance I guess... not onsighting the bijection here today unfortunately but I think that it might be right there in sight. Each of these cases certainly leaves some like product of the ways to select the downstream chain to the B value from the remainder and then fixes all dudes in that interim into the downstream chain from a but then we are still left with some other term so it is like sum of [dude choose whatever]*[2^[]-dude choose 2^[blah]-whatever] which is still wait wait wait basically this is still like simply picking the downstream dudes I think. Ugh think it ugh suffices after picking a to simply pick the downstream dudes which is a huge cluster fuck of basically like a [2^[blah]-d choose 2^[blah]-2] and then the remainder chain for B is also fixed ugh. Well taking this all modulo p obviously immediately provides some like ugh ugh ugh modulo p computation should be pretty trivial here in O[p] for each instance is too high still. Still just like even considering Lucas's Theorem here is non trivial. Except even that still will not work because actually we need to be preserving the count of the number of powers of p in the numerator and denominator with respect to the final actual division of the representation of the true underlying fraction that is to say this is still nontrivial. Oh wait from there it is then as easy as simply seeing that this is in fact like equivalent with choosing ugh I think ugh this summation itself is like a summation of ugh maybe there is still a simple bijection here somehow where we like shift any additional ugh no that will not work. Probability distribution of order statistic in sampling without replacement e.g. variation on German Tank Problem task with Ath order statistic from set of size A+2^blah-2 out of A+B+2^blah-2+2^blah-2. Perhaps the Python programming language could actually help me with this here task and DP dunno just how to use arbitrary precision but I think maybe in O[n^2] time is trivial... frankly dunno if any of the first 5000 powers of 2 are actually within 5002 of a multiple of p... seems likely to not be the case actually... I think we can just naturally process this unfolding the first A+B letters and doing it in an DP doing the count until we halt e.g. or simply doing yeah yeah the first A+B and adding up along the rows and columns there. In any case yeah yeah yeah think we can simply compute the probability for each step and note that like probabilities sum in the ring I think so ugh keep it simple.
*/
	in>>a>>b>>c;
	al=0; // Numerator
	bl=0; // Denominator
	for(d=1+a;d<=1+a+b-1;d++){
		al=(al+choose(d-2,a-1)*choose())%p;
		bl=(bl+)%p;
	}
	for(d=1+b;d<=1+a+b-1;d++){
		bl=(bl+)%p;
	}
	out<<al*inverse(bl)%p<<nl;
}

I main(){zz();I a=1;while(a--){az();}}