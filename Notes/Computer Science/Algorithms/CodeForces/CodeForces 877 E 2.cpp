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
const I p=1000000007; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

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
B inversefactorialsaux[2000001];
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

// If needed can replace factorialsmax with L and also set a const L limitt=10000000000; depending upon the machine and execution and also switch it up from memory allocation like this to a pair of VLs declared later in loop in main or az(){} to be memory allocated there clearing 64GB of RAM or 128GB RAM.

// Faster version is convolutionsuisenlarge.cpp
Z fft(vector<CD>& a){//chilli
	I n=sz(a),l=31-__builtin_clz(n);
	static vector<complex<LD>> r(2,1);
	static vector<CD> rt(2,1);  // 10% faster if D
	for(static I k=2;k<n;k*=2){
		r.resize(n);rt.resize(n);
		auto x=polar(1.0L,acos(-1.0L)/k);
		rep(i,k,2*k)rt[i]=r[i]=i&1?r[i/2]*x:r[i/2];
	}
	V rev(n);
	rep(i,0,n)rev[i]=(rev[i/2]|(i&1)<<l)/2;
	rep(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(I k=1;k<n;k*=2)
		for(I i=0;i<n;i+=2*k)rep(j,0,k){
			// CD z=rt[j+k]*a[i+j+k]; // include this line 25% faster
			auto x=(D *)&rt[j+k],y=(D *)&a[i+j+k]; // exclude this line
			CD z(x[0]*y[0]-x[1]*y[1],x[0]*y[1]+x[1]*y[0]); // exclude this line
			a[i+j+k]=a[i+j]-z;
			a[i+j]+=z;
		}
}
VL convolutionp(const VL &a,const VL &b){
	if(a.empty() or b.empty())return {};
	VL res(sz(a)+sz(b)-1);
	I y=32-__builtin_clz(sz(res)),n=1<<y,cut=I(sqrt(p));
	vector<CD> c(n),d(n),os(n),ol(n);
	rep(i,0,sz(a))c[i]=CD((I)a[i]/cut,(I)a[i]%cut);
	rep(i,0,sz(b))d[i]=CD((I)b[i]/cut,(I)b[i]%cut);
	fft(c),fft(d);
	rep(i,0,n){
		I j=-i&(n-1);
		ol[j]=(c[i]+conj(c[j]))*d[i]/(2.0*n);
		os[j]=(c[i]-conj(c[j]))*d[i]/(2.0*n)/1i;
	}
	fft(ol),fft(os);
	rep(i,0,sz(res)){
		L av=L(real(ol[i])+.5),cv=L(imag(os[i])+.5);
		L bv=L(imag(ol[i])+.5)+L(real(os[i])+.5);
		res[i]=((av%p*cut+bv)%p*cut+cv)%p;
	}
	return res;
}
// May fail on memory for n ~ 10^8 10^9.
// Google Colab claims 4.8GB for a pair of VL at n ~ 10^7 producing a resultant cvl of n ~ 2 * 10^7 implies 48GB may be enough and that was on 70s run time so ~ 450 at 10^8 might take ~ 140 hours depending uh on a number of other factors but could theoretically clear in a background-executed massive $50 Google Colab. Except that Google Colab Pro+ still has a 24 hour execution run time cap and thus securing a 64GB or 96GB Apple Macintosh Book Professional Machine would still be in my direct Economic interest. As it so happens, that approach will not actually work here as the actual effective maximum size of n here is ~ 10^7 I think according to chilli's writing in the upstream KACTL documentation for this particular C|C++ convolution modulo p implementation and the Python Scientific Python SciPy or a uh PARI|GP implementation might work out better depending. Potentially one could more simply extend this one with some kind of a Karatsuba-style trickery...
// https://scicomp.stackexchange.com/questions/23867/c-libraries-for-fast-fourier-transform-in-high-

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
Interesting interesting interesting half interesting really here maybe 5 minutes in to the round after WolframAlpha pings me back with the closed form expression starting off with k^n - ... it should have triggered my OnSight OnSight OnSight OnSight in the morning zoning OnSight there...

OKOKOK so one could theoretically practically go ahead and compose an iterated squaring approach with O[n * log[n] * log [A]] complexity and Fast Fourier Modulo p Transformations with an auxiliary long long variable representing the number of valid sequences that have already transitioned out in the Markov Chain or alternately one can simply do the complementary counting approach here and only keep dudes who have yet to transition out and then add those up at the end...

Test + Additional Input:


Analysis:
Eins, zwei, drei, vier, fünf, sechs, sieben, acht, neun, aus!
Alle warten auf das Licht
Fürchtet euch, fürchtet euch nicht
Die Sonne scheint mir aus den Augen
Sie wird heut Nacht nicht untergeh'n
Und die Welt zählt laut bis zehn
(Eins) Hier kommt die Sonne
(Zwei) Hier kommt die Sonne
(Drei) Sie ist der hellste Stern von allen
(Vier) Hier kommt die Sonne
Die Sonne scheint mir aus den Händen
Kann verbrennen, kann euch blenden
Wenn sie aus den Fäusten bricht
Legt sich heiß auf das Gesicht
Sie wird heut Nacht nicht untergeh'n
Und die Welt zählt laut bis zehn
(Eins) Hier kommt die Sonne
(Zwei) Hier kommt die Sonne
(Drei) Sie ist der hellste Stern von allen
(Vier) Hier kommt die Sonne
(Fünf) Hier kommt die Sonne
(Sechs) Hier kommt die Sonne
(Sieben) Sie ist der hellste Stern von allen
(Acht, neun) Hier kommt die Sonne
Die Sonne scheint mir aus den Händen
Kann verbrennen, kann dich blenden
Wenn sie aus den Fäusten bricht
Legt sich heiß auf dein Gesicht
Legt sich schmerzend auf die Brust
Das Gleichgewicht wird zum Verlust
Lässt dich hart zu Boden geh'n
Und die Welt zählt laut bis zehn
(Eins) Hier kommt die Sonne
(Zwei) Hier kommt die Sonne
(Drei) Sie ist der hellste Stern von allen
(Vier) Und wird nie vom Himmel fallen
(Fünf) Hier kommt die Sonne
(Sechs) Hier kommt die Sonne
(Sieben) Sie ist der hellste Stern von allen
(Acht, neun) Hier kommt die Sonne

Seems as though once we have picked the uh 1st indices for each of the uh n dudes in the m array we then have n-m uh well based upon the final index actually casework there uh... sum sum sum uh but like sum from n to m of uh casework on that final index for the multiplier uh...

https://www.wolframalpha.com/input?i=sum+from+n%3Da+to+b+of+%28%28n-1%29+choose+%28a-1%29%29*c%5E%28n-a%29*%28c%2B1%29%5E%28b-n%29

https://mathworld.wolfram.com/HypergeometricFunction.html

OKOKOK

[4 choose 4]*[x]^0*[x+1]^10+[5 choose 4]*[x]^1*[x+1]^9+...

Is it easier to somehow casework upon the uh uh uh final indices uh for each dude like the maximal appearance uh...?

From the Right to the Left we need no more of final dude and then uh... no more of 2nd final dude between uh okokok it is the same thing uh...

https://www.wolframalpha.com/input?i=sum+from+n%3Da+to+b+of+%28%28n-1%29+choose+%28a-1%29%29*%28c-1%29%5E%28n-a%29*%28c%29%5E%28b-n%29

Umm OKOKOK

Like uh Markov Chain exponentiation somehow uh just uh 0 through uh a state and uh the transition is just like c-1 ways to loop back and 1 in and uh once in the final state just uh c...

Uh uh uh some kind of a uh simple Markov Chain uh there is like of course just uh c-1s on the diagonal and a final c and then uh 1s in the diagonal 1 above uh...

https://www.wolframalpha.com/input?i=%7B%7B2%2C1%2C0%2C0%7D%2C%7B0%2C2%2C1%2C0%7D%2C%7B0%2C0%2C2%2C1%7D%2C%7B0%2C0%2C0%2C3%7D%7D%5E4

https://www.wolframalpha.com/input?i=%7B%7B1%2C1%7D%2C%7B0%2C2%7D%7D%5E10

https://www.wolframalpha.com/input?i=%7B%7B17%2C1%2C0%2C0%2C0%2C0%2C0%7D%2C%7B0%2C17%2C1%2C0%2C0%2C0%2C0%7D%2C%7B0%2C0%2C17%2C1%2C0%2C0%2C0%7D%2C%7B0%2C0%2C0%2C17%2C1%2C0%2C0%7D%2C%7B0%2C0%2C0%2C0%2C17%2C1%2C0%7D%2C%7B0%2C0%2C0%2C0%2C0%2C17%2C1%7D%2C%7B0%2C0%2C0%2C0%2C0%2C0%2C18%7D%7D%5E6

Umm OKOKOK so instead like what about uh... somehow uh... FFTing this one uh...

[[c-1]+x]^dude

And then like these are fast O[n log n] ops in the uh exponential uh... where uh any of the final dudes uh... need to get smooshed in in transition uh... think I am too too too slow here again right now at like 31 minutes in to the round with 2 left on Late Registration I uh tank and tank out here tank tank tank in the tank is optimal game theoretically optimal decision here to be sure feels good to make the right good decision good strong decision is not Late Register here ungh.
*/

	in>>a>>b>>c;
	for(d=0;d<a;d++)in>>z;
	d=b;
	// Exponentiating [c-1+x]^[b] to first a terms which have not completed...
	avl=VL(a,0);
	avl[0]=1;
	bvl=VL(a,0);
	bvl[0]=c-1;
	if(a>1)bvl[1]=1;
	while(b>0){
		if(b%2==1){
			avl=convolutionp(avl,bvl);
			if(sz(avl)>a)avl.resize(a);
		}
		bvl=convolutionp(bvl,bvl);
		if(sz(bvl)>a)bvl.resize(a);
		b/=2;
	}
	al=0;
	for(auto dude:avl)al+=dude;
	al%=p;
	out<<((exp(c,d)-al)%p+p)%p<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}