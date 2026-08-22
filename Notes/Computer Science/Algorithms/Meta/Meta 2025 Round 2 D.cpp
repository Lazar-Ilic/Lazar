// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <sys/time.h>
//#include <bits/extc++.h>
// Instead Of Recoding Can Change Definition Like D To long double
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using SHORT=short; // 16 bits=2 bytes | [-32768,32767]
using I8=int8_t; // 8 bits=1 byte | [-128,127]
using UI8=uint8_t; // 8 bits=1 byte | [0,255]
using UI=unsigned int;// 32 bits=4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t;// 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=signed long long;// 64 bits=8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long;// 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128;// 128 bits=16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
using VMLI=vector<MLI>;
using UMSI=unordered_map<S,I>;
using UMII=unordered_map<I,I>;
using UMIL=unordered_map<I,L>;
using UMLL=unordered_map<L,L>;
using UMUI=unordered_map<U,I>;
using VUMII=vector<UMII>;
using DQ=deque<I>;
using ST=stack<I>;
using STST=stack<ST>;
using STP=stack<P>;
using STPL=stack<PL>;
using Q=queue<I>;
// Arrays [Declared Large] Are Often Sharper
using VB=vector<B>;
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
using VVVVVB=vector<VVVVB>;
using VVVVVVB=vector<VVVVVB>;
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
using VVVVV=vector<VVVV>;
using VVVVVV=vector<VVVVV>;
using VVVVVVV=vector<VVVVVV>;
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
using PQVL=priority_queue<VL>;
using MINPQVL=priority_queue<VL,VVL,greater<VL>>;
using PQP=priority_queue<P>;
using MINPQP=priority_queue<P,VP,greater<P>>;
using PQPL=priority_queue<PL>;
using MINPQPL=priority_queue<PL,VPL,greater<PL>>;
using PQPIP=priority_queue<PIP>;
using SETV=set<V>;
using SETULL=set<ULL>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QV=queue<V>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MLV=map<L,V>;
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
using MVI=map<V,I>;
using MVL=map<V,L>;
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
#define all(a)((a).begin()),((a).end())
#define sortify(a) sort(all(a))
#define uniquify(a)(a).resize(unique(all(a))-(a).begin())
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
		freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
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
const I p=998244353; // 998244353 1000000007 // 1073741824 * 2 > INT_MAX So 1234567891 Forces (long long) Conversion Or Usage Before + Modulo p
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

V lololol;

L fff(S as){
	L res = 0;
	L mul = 1;
	for(I a = sz(as) - 1; a >= 0; a--){
		res += mul * (as[a] - '0') % p;
		mul = mul * 10 % p;
	}
	return res % p;
}

L ggg(S as,I a){
	if(sz(as)>=a){
		return lololol[25-a];
		S bs = "";
		for(I b = 0; b < a - 1; b++) bs += "9";
		as = bs;
	}
	if(sz(as) == 1){
		L resres = 0;
		for(I b = 1; b <= (I)(as[0] - '0'); b++) if(b % a != 0) resres++;
		return resres;
	}
	//out<<as<<nl;
	L res = 0;
	VV lol((1<<a),V(a,0));
	for(I b = 1; b <= 9; b++){
		if((b % a) != 0){
			lol [(1 << (b % a))][b % a] += 1;
			res += 1;
		}
	}
	VV ease(a+1,V(0));
	for(I b=0;b<(1<<a);b++)ease[subsetsize(b)].add(b);
	for(I b=2;b<sz(as);b++){
		//out<<b<<nl;
		// Each Iteration We Go Through And Add Less Than And Then If b>=2 Can Add In New Less Than Generated From Prefix Of as On First b-1 Digits Also Ensure At End To Add For as Itself
		for(auto dude:ease[b-1]){
			for(I c=1;c<a;c++){
				if(lol[dude][c]){
				for(I d=1;d<=9;d++){
					if(((dude ba (1 << ((c + d) % a))) == 0) and (c + d) % a != 0){
						lol[dude + (1 << ((c + d) % a))][(c + d) % a] = (lol[dude + (1 << ((c + d) % a))][(c + d) % a] + lol[dude][c]) % p;
						res = (res + lol[dude][c]) % p;
					}
				}
			}}
		}
	}
	lol=VV((1<<a),V(a,0));
	for(I b = 1; b < (I)(as[0] - '0'); b++){
		if((b % a) != 0){
			lol [(1 << (b % a))][b % a] += 1;
			//res += 1;
		}
	}
	//out<<"res1"<<" "<<res<<nl;
	for(I b=2;b<=sz(as);b++){
		//out<<b<<nl;
		// Each Iteration We Go Through And Add Less Than And Then If b>=2 Can Add In New Less Than Generated From Prefix Of as On First b-1 Digits Also Ensure At End To Add For as Itself
		for(auto dude:ease[b-1]){
			for(I c=1;c<a;c++){
				if(lol[dude][c]){
				for(I d=1;d<=9;d++){
					if(((dude ba (1 << ((c + d) % a))) == 0) and (c + d) % a != 0){
						lol[dude + (1 << ((c + d) % a))][(c + d) % a] = (lol[dude + (1 << ((c + d) % a))][(c + d) % a] + lol[dude][c]) % p;
						if(b == sz(as)) res = (res + lol[dude][c]) % p;
					}
				}
			}}
		}
		I pref=0;
		I blah=0;
		I strongblah=1;
		for(I c=0;c<b-1;c++){
			if(as[c] == '0') strongblah = 0;
			pref = (pref + (I)(as[c]-'0')) % a;
			if((pref == 0) or (blah ba (1 << pref)) != 0) strongblah = 0;
			blah += (1 << pref);
		}
		if(strongblah){
			for(I c=1;c<(I)(as[b-1]-'0');c++){
				if((pref + c)%a != 0 and (blah ba (1<<((pref+c)%a))) == 0){
					lol[blah + (1<<((pref+c)%a))][(pref + c)%a]++;
					if(b==sz(as)) res++;
				}
			}
		}
		//out<<"res2"<<" "<<res<<nl;
	}
		I strongstrong = 1;
		for(I c=0;c<sz(as);c++){
			for(I d=c;d<sz(as);d++){
				I lolol = 0;
				for(I e=c;e<=d;e++){
					lolol += (I)(as[e] - '0');
				}
				if(lolol % a == 0) strongstrong = 0;
			}
		}
	res += strongstrong;
	//out<<nl<<nl;
	return res;
}

I testcase=0;
Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
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
	//out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:
Aiya way way way too slow in contest eek I am way out of practise at this stuff and debugging and n0 cheating and so on and so on so you know I ought to meet in the middle here or something... run uh the way it works out here is that like we are running in to a very mediocre like O(25) times blowup right around the transition points in the middle so uh actually casing out big cases in terms of like we could instead of O(25 * 2^25) or whatever in the end it could be like uh... cut a lot of it out and have a final step be like O(25 choose 12) with lookups and mults for the subcase values on left and right hand sides of the string in 1-dimension or whatever... pretty angry at myself and sad today was an epic failure TT

Test+Additional Input:


[Worst-Case Runtime] Analysis:

*/

	lololol={979496524,672540615,983997887,214933306,842164561,453621152,92437344,106737793,109772426,723522759,134513257,276407095,67195782,16387527,4012710,986409,109600,32335,9348,2481,632,119,24,5};
	in>>x;
	//out<<x<<nl;
	avs=VS(x);
	bvs=VS(x);
	av=V(x);
	bv=V(x);
	for(z=0;z<x;z++)in>>avs[z]>>bvs[z]>>av[z];
	//in>>as>>bs>>a;
	omp_set_num_threads(8);
	#pragma omp parallel for num_threads(8)
	for(y=0;y<x;y++){
		S as=avs[y];
		S bs=bvs[y];
		I a=av[y];
		if(sz(as)>=a){
			//out<<((fff(bs)-fff(as)+1)%p+p)%p<<nl;
			bv[y]=((fff(bs)-fff(as)+1)%p+p)%p;
		}
		else{
			I strongstrong = 1;
			for(I c=0;c<sz(as);c++){
				for(I d=c;d<sz(as);d++){
					I lolol = 0;
					for(I e=c;e<=d;e++){
						lolol += (I)(as[e] - '0');
					}
					if(lolol % a == 0) strongstrong = 0;
				}
			}
			//out<<((fff(bs)-fff(as)+1-(ggg(bs,a)-ggg(as,a)+strongstrong))%p+p)%p<<nl;
			bv[y]=((fff(bs)-fff(as)+1-(ggg(bs,a)-ggg(as,a)+strongstrong))%p+p)%p;
			//out<<fff(bs)<<" "<<fff(as)<<" "<<ggg(bs,a)<<" "<<ggg(as,a)<<" "<<strongstrong<<nl;
			if(testcase==2){
				//out<<ggg("129",a)<<" "<<ggg("130",a)<<" "<<ggg("131",a)<<" "<<ggg("132",a)<<" "<<ggg("133",a)<<" "<<ggg("134",a)<<" "<<ggg("135",a)<<" "<<nl;
				//cs="9999999999999999999999999999999999999999999999999999999999";
				//for(z=25;z>=2;z--)out<<ggg(cs,z)<<nl;
			}
		}
	}
	for(y=0;y<x;y++){
		out<<"Case #"<<y+1<<": "<<bv[y]<<nl;
	}
}

I main(){zz();I a=1;while(a--){az();}}