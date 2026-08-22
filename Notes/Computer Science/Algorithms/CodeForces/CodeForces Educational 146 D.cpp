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
using PQ=priority_queue<I>;
using MINPQ=priority_queue<I,V,greater<I>>;
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
#define Lsubsetsize __builtin_popcountll
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

I testcase;
I testcases;

Z az(){
	// Optimise by deleting unused variables or test-casing in loop.
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
Maybe I can ABCDE the round and ping in later ugh hard to know ugh this one and E also seems uh trivial mighty trivial to me here today with 70 minutes to go I might wanna reg' and then ping in ABC dunno if the round will crash out on the uh scoring unrated... may as well go for it and update on D solvers ugh... it does not say what if this task is uh like impossible ugh so uh for sure not sure that there exists a uh dude in any case for sure can casework on like the uh relevant uh ranges uh like uh so assuming there exists some way then like process the relevant uh Left oh no that will not uh work that uh simply I uh think. 3000ms is uh still like. Modulo uh. Still seems to me as though uh like potentially uh OKOKOK need to check up I mean there are initially like uh some dudes and we gotta umm like bash up say we wanted to bash each uh relevant uh interval like we have some gap of size uh whatever is like 1500 gap and then we had a ton of dude in the range [10000,11000] and then we are testing up for each dude not capturable in that range we need the uh closest on each end and then that is trivial in O[3000] or whatever to then bash outwards like 2 pointers I think so like O[3000^2] should still be AC basically uh especially if we just process those gaps in order based on uh how many dudes were in that uh range.
*/

	testcase++;
	in>>a>>b;
	m=0; // Maximum capturable in range which works.
	av=V(a);
	bv=V(a);
	for(c=0;c<a;c++)in>>av[c];
	for(c=0;c<a;c++)in>>bv[c];
	VPL avpl;
	for(c=0;c<a;c++)avpl.add({L(av[c])*bv[c],av[c]});
	// Ensure to not include (0,) in bashes.
	sort(all(avpl));
	/*
	y=0;
	for(auto dude:avpl){out<<dude.first<<" "<<dude.second<<" "<<y<<nl;y++;}
	out<<nl;
	*/
	// 27 28 41 42
	for(c=0;c<a;c++){
		//d=c+1;
		//while(d<a and avpl[d].first<=avpl[c].first+b)d++;
		//d--;
		//if(d-c+1>m){
			// Then we ought to test this case potentially uh.
			al=avpl[c].first; // Left bound
			//bl=avpl[d].first; // Right bound
			// So values are in uh the range or in uh like uh [bl-b,al) or uh like (bl,al+b] I guess.
			// OK and process through with like 2 pointers and an auxiliary VB I think maybe and a counter for the VB so if the counter hits the thing then we AC this sub test case or whatever and move on.
			cv=V(a,0);
			cv[c]=1;
			//for(e=c;e<=d;e++)cv[e]=1;
			n=1;
			o=1; // Authentic captures ungh.
			//n=d-c+1; // Counter of a uh 1s in avb.
			VPL bvpl,cvpl;
			// To process through uh 2 pointers I guess uh. Start and then uh do for each potential uh Left point including a nothing and uh trivial and uh check I guess ugh. 2 pointers works I guess uh.
			for(e=c-1;e>=0;e--){
				/*
				if((bl/avpl[e].second)*avpl[e].second>=al){
					cv[e]=1;
					n++;
				}
				*/
				//else{
					if(avpl[e].first<=al and avpl[e].first>=al-b)bvpl.add({avpl[e].first,e});
					else if(avpl[e].first>al and avpl[e].first<=al+b)cvpl.add({avpl[e].first,e});
					if(avpl[e].first!=al-(al%avpl[e].second) and al-(al%avpl[e].second)>=max(al-b,L(1)))bvpl.add({al-(al%avpl[e].second),e});
					if(avpl[e].first!=al+avpl[e].second-(al%avpl[e].second) and al+avpl[e].second-(al%avpl[e].second)<=al+b)cvpl.add({al+avpl[e].second-(al%avpl[e].second),e});
				//}
			}
			for(e=c+1;e<a;e++){
				/*
				if((bl/avpl[e].second)*avpl[e].second>=al){
					cv[e]=1;
					n++;
				}
				*/
				//else{
					if(avpl[e].first<=al and avpl[e].first>=al-b)bvpl.add({avpl[e].first,e});
					else if(avpl[e].first>al and avpl[e].first<=al+b)cvpl.add({avpl[e].first,e});
					if(avpl[e].first!=al-(al%avpl[e].second) and al-(al%avpl[e].second)>=max(al-b,L(1)))bvpl.add({al-(al%avpl[e].second),e});
					if(avpl[e].first!=al+avpl[e].second-(al%avpl[e].second) and al+avpl[e].second-(al%avpl[e].second)<=al+b)cvpl.add({al+avpl[e].second-(al%avpl[e].second),e});
				//}
			}
			sort(all(bvpl));
			sort(all(cvpl));
			for(auto dude:bvpl){
				if(cv[dude.second]==0)n++;
				cv[dude.second]=1;
				if(dude.first==avpl[dude.second].first)o++;
			}
			/*
			if(c==27 or c==28 or c==41 or c==42)out<<c<<" "<<o<<nl;
			if(c==28 or c==42){
				for(auto dude:bvpl){
				out<<dude.first<<" "<<avpl[dude.second].first<<nl;
				if(dude.first==avpl[dude.second].first)o++;
			}
			}
			*/
			g=-1; // Uh always uh consider uh when to set to 0 uh up front I think works in 2 pointers uh.
			//y=1;
			for(f=0;f<=sz(bvpl);f++){
				// Uh consider this uh starting uh.
				if(f>=1){
					cv[bvpl[f-1].second]--;
					if(cv[bvpl[f-1].second]==0)n--;
					if(bvpl[f-1].first==avpl[bvpl[f-1].second].first)o--;
				}
				while(g+1<sz(cvpl) and ((f<sz(bvpl) and cvpl[g+1].first<=b+bvpl[f].first) or (f==sz(bvpl) and cvpl[g+1].first<=al+b))){
					g++;
					cv[cvpl[g].second]++;
					if(cv[cvpl[g].second]==1)n++;
					if(cvpl[g].first==avpl[cvpl[g].second].first)o++;
				}
				if(n==a and o>m){
					m=o;
					//y=0;
					/*
					if(testcase==1){
						out<<o<<nl<<c<<nl<<b<<nl;
						out<<"bvpl"<<nl;
						for(auto dude:bvpl)out<<dude.first<<" "<<dude.second<<nl;
						out<<"cvpl"<<nl;
						for(auto dude:cvpl)out<<dude.first<<" "<<dude.second<<nl;
						for(auto dude:avpl)out<<dude.first<<" "<<dude.second<<nl;
						out<<nl;
					}
					*/
				}
			}
		//}
	}
	/*
	if(testcase==19 and a-m==49){
		out<<a<<" "<<b<<nl;
		for(auto dude:av)out<<dude<<" ";
		out<<nl;
		for(auto dude:bv)out<<dude<<" ";
		out<<nl;
	}
	*/
	/*
	if(testcases==937 and testcase==67){
		out<<a<<" "<<b<<nl;
		for(auto dude:av)out<<dude<<" ";
		out<<nl;
		for(auto dude:bv)out<<dude<<" ";
		out<<nl;
	}
	*/
	out<<a-m<<nl;
}

I main(){zz();I a=1;in>>a;testcases=a;while(a--){az();}}