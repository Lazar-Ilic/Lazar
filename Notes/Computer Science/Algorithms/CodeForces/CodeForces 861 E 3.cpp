// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt

//%%writefile a.cpp 
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
L alll;
I blll,clll;
Z zz(){
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);
	#endif
	in>>alll>>blll>>clll;
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
const I p=clll; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

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

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml,nnnl;
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
	*/

	al=alll;
	b=blll;
	out<<p<<nl;
	//in>>al>>b>>c;
	//p=c;
	if(b==1){
		out<<1<<nl;
		return;
	}
	il=0;
	jl=0;
	// Casework through umm unlucky based upon the remainder of umm like umm say it was equivalent to umm like 2a=i for i in 0 to k-1 or whatever and then case out the dudes excluded there.
	dl=0; // Number of unlucky.
	for(d=0;d<b;d++){
		// Add number of unlucky with uh sum of d modulo b and uh not hitting any of the requisite dudes.
		avl=VL(b,1);
		bvl=VL(1,1); // Dude to uh take any time the uh modulo 2 is umm odd I think.
		z=0;
		for(e=0;e<b;e++){
			if((2*e)%b==d){
				avl[e]=0; // Excluded.
				z++;
			}
		}
		// Exponentiate uh avl and uh take it modulo bl I guess umm.
		cl=al; // Uh exponent.
		while(cl>0){
			// If odd uh multiply and mod out.
			if(cl%2==1){
			cvl=convolutionp(avl,bvl);
			for(f=b;f<=2*b-2 and f<sz(cvl);f++)cvl[f-b]=(cvl[f-b]+cvl[f])%p;
			cvl.resize(b);
			bvl=cvl;
			}
			dvl=avl;
			cvl=convolutionp(avl,dvl);
			for(f=b;f<=2*b-2 and f<sz(cvl);f++)cvl[f-b]=(cvl[f-b]+cvl[f])%p;
			cvl.resize(b);
			avl=cvl;
			cl/=2;
		}
		if(z>0)dl+=bvl[d];
		else if(z==0 and il>0)dl+=jl;
		else{
			jl=bvl[0];
			il=1;
			dl+=jl;
		}
	}
	out<<(exp(b,al)-(dl%p)+p)%p<<nl;
}

I main(){zz();I a=1;while(a--){az();}}