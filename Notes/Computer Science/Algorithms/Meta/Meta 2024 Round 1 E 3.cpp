// "We're living Ultralife"-Josephine Vander Gucht <3
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <sys/time.h>
//#include <bits/extc++.h>
using B=bool; // 8 bits=1 byte | [0,1]
using C=char; // 8 bits=1 byte | [-128,127]
using D=double; // 64 bits=8 bytes | [Eh]
using LD=long double; // 96 bits=12 bytes | [Eh]
using I=int; // 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
using UI=unsigned int; // 32 bits=4 bytes | [0,4294967295] ~ [0,4*10^9]
using U=uint64_t; // 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using L=signed long long; // 64 bits=8 bytes | [-9223372036854775808,9223372036854775807] ~ [-10^19,10^19]
using ULL=unsigned long long; // 64 bits=8 bytes | [0,18446744073709551615] ~ [0,2*10^19]
using UI128=__int128; // 128 bits=16 bytes | [0,340282366920938463463374607431768211455] ~ [0,3*10^38]
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
const I p=998244353; // 998244353 1000000007
// L 1000000000039 1000000000000037 1000000000000000003

//--------------------------------------------------------------------

I testcase=0;
Z az(){
	//out<<"Case #"<<++testcase<<": ";

/*
Post Contest Analysis:
Made an error here in round thinking I should manually copy and paste around a 4 threaded approach across 4 cores on Macintosh with 4 terminal windows open and then merge my output.txt files together. Probably a bad idea and a violation of Meta terms but nevertheless interesting to try and drop that 4x factor on runtime. OKOKOK now I got that cracked in here so that is good.

Even further analysis is that this version 3 executes in around 127s on my Macintosh Book Air 2023 machine is just OK... perhaps depending on memory handling bumping out that ~15*2^15 chunk in to the overall precompute would be a sharp move here really depending on memory latencies across 4 threads and how localised that memory chunk gets in the calls underlying.

Test+Additional Input:


[Worst-Case Runtime] Analysis:
So all that is relevant for each subset is actually how the ?s line up in the maximum prefix so basically we can actually consider just taking the bitwise 
*/
	I q,r,s;
	V ev,fv,gv;
	in>>q;
	ev=V(q); // Answers
	fv=V(q); // Lengths Of
	gv=V(q); // Thread Used
	VVS avvs(q,VS(0)); // Vectors Of Strings
	for(r=0;r<q;r++){
		in>>fv[r];
		avvs[r]=VS(fv[r]);
		for(s=0;s<fv[r];s++)in>>avvs[r][s];
	}
	#pragma omp parallel for num_threads(4)
	for(r=0;r<q;r++){
		C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
		D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
		I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,t,u,v,w,x,y,z;
		L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
		S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
		V av,bv,cv,dv,hv,iv,jv,kv,lv,mv;
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
		gv[r]=omp_get_thread_num();
		a=fv[r];
		avs=avvs[r];
		//for(b=0;b<a;b++)in>>avs[b];
		avv=VV(a,V(a,0));
		for(b=0;b<a;b++){
			for(c=b+1;c<a;c++){
				x=1;
				for(d=0;d<min(sz(avs[b]),sz(avs[c]))and x;){
					if(avs[b][d]==avs[c][d] or avs[b][d]=='?' or avs[c][d]=='?')d++;
					else x=0;
				}
				avv[b][c]=d;
				avv[c][b]=d;
			}
		}
		for(b=0;b<a;b++)avv[b][b]=sz(avs[b]);
		al=0;
		avl=VL(101); // Powers of 26
		avl[0]=1;
		for(b=1;b<=100;b++)avl[b]=(26*avl[b-1])%p;
		dvl=VL(1<<15); // Precomputing For Blocks Of Size 15
		for(b=0;b<(1<<15);b++){
			c=0;
			for(d=0;d<15;d++){
				if(b ba (1<<d))c++;
				dvl[b]+=avl[c];
			}
			dvl[b]%=p;
		}
		evvl=VVL(14,VL(0)); // And For Remainder Blocks
		for(b=0;b<14;b++){
			evvl[b]=VL(1<<(b+1));
			for(c=0;c<(1<<(b+1));c++){
				d=0;
				for(e=0;e<b+1;e++){
					if(c ba (1<<e))d++;
					evvl[b][c]+=avl[d];
				}
				evvl[b][c]%=p;
			}
		}
		bvl=VL(a,0); // First 60 Bits Of ?
		cvl=VL(a,0); // Next 40 Bits Of ?
		for(b=0;b<a;b++){
			for(c=0;c<60 and c<sz(avs[b]);c++)if(avs[b][c]=='?')bvl[b]+=((L)1<<c);
			for(c=60;c<100 and c<sz(avs[b]);c++)if(avs[b][c]=='?')cvl[b]+=((L)1<<(c-60));
		}
		dv=V((1<<a),0);
		for(b=1;b<(1<<a);b++){
			bl=0;
			if(subsetsize(b)==1){
				for(c=0;c<a;c++)if(b ba (1<<c))m=avv[c][c];
			}
			else{
				c=0;
				while(!(b ba (1<<c)))c++;
				d=c+1;
				while(!(b ba (1<<d)))d++;
				m=avv[c][d];
				m=min(m,dv[b bx (1<<c)]);
				m=min(m,dv[b bx (1<<d)]);
			}
			dv[b]=m;
			if(m>60)cl=((L)1<<60)-1;
			else cl=((L)1<<m)-1;
			if(m>60)dl=((L)1<<(m-60))-1;
			else dl=0;
			for(c=0;c<a;c++){
				if(b ba (1<<c)){
					cl=(cl ba bvl[c]);
					dl=(dl ba cvl[c]);
				}
			}
			e=0;
			bl+=avl[e];
			for(f=0;f<m;f+=15){
				if(f+15>m){
					if(f<60)bl+=avl[e]*evvl[m-f-1][((((1<<15)-1)*((L)1<<f)) ba cl)/((L)1<<f)]%p;
					else bl+=avl[e]*evvl[m-f-1][((((1<<15)-1)*((L)1<<(f-60))) ba dl)/((L)1<<(f-60))]%p;
				}
				else{
					if(f<60){
						bl+=avl[e]*dvl[((((1<<15)-1)*((L)1<<f)) ba cl)/((L)1<<f)]%p;
						e+=subsetsizeL((((1<<15)-1)*((L)1<<f)) ba cl);
					}
					else{
						bl+=avl[e]*dvl[((((1<<15)-1)*((L)1<<(f-60))) ba dl)/((L)1<<(f-60))]%p;
						e+=subsetsizeL((((1<<15)-1)*((L)1<<(f-60))) ba dl);
					}
				}
			}
			if(subsetsize(b)%2==1)al+=bl%p;
			else al-=bl%p;
		}
		al=al%p;
		al+=p;
		al=al%p;
		//out<<al<<nl;
		ev[r]=al;
	}
	for(r=0;r<q;r++)out<<"Case #"<<r+1<<": "<<ev[r]<<endl;//" "<<gv[r]<<endl;
}

I main(){zz();I a=1;while(a--){az();}}

/*
Case #1: 8
Case #2: 54
Case #3: 703
Case #4: 79
Case #5: 392316013
Case #6: 629393408
Case #7: 12356631
Case #8: 333978835
Case #9: 559559045
Case #10: 360496048
Case #11: 515456933
Case #12: 850646951
Case #13: 721819701
Case #14: 148809737
Case #15: 564090199
Case #16: 166004829
Case #17: 868505184
Case #18: 607372318
Case #19: 368596750
Case #20: 580004047
Case #21: 985787637
Case #22: 958378586
Case #23: 582904197
Case #24: 113698003
Case #25: 746615724
Case #26: 81705531
Case #27: 885941873
Case #28: 403526859
Case #29: 679514418
Case #30: 265847293
Case #31: 784312052
Case #32: 590398147
Case #33: 522433821
Case #34: 606213570
Case #35: 868341676
Case #36: 131508862
Case #37: 482694668
Case #38: 489618439
Case #39: 180026427
Case #40: 232548601
Case #41: 638492541
Case #42: 721727046
Case #43: 343017821
Case #44: 884111229
Case #45: 170453385
Case #46: 47410749
Case #47: 807373984
Case #48: 472972570
Case #49: 296669200
Case #50: 926427272
Case #51: 796981956
Case #52: 40726084
Case #53: 612455717
Case #54: 880539615
Case #55: 635158858
Case #56: 552281495
Case #57: 70061599
Case #58: 442753590
Case #59: 556731536
Case #60: 486499723
Case #61: 136624108
Case #62: 445837090
Case #63: 587575830
Case #64: 592096251
Case #65: 169750441
Case #66: 241124439
Case #67: 382211207
Case #68: 659576165
Case #69: 970638083
Case #70: 184731895
Case #71: 964130248
Case #72: 903602867
Case #73: 687960566
Case #74: 960068821
Case #75: 619883327
Case #76: 292618914
Case #77: 906938848
Case #78: 688713973
Case #79: 39998712
Case #80: 754197379
Case #81: 275133340
Case #82: 186353806
Case #83: 899738796
Case #84: 441248264
Case #85: 632086514
Case #86: 542193083
Case #87: 261444729
Case #88: 727192061
Case #89: 722285916
Case #90: 225099844
Case #91: 536451454
Case #92: 193258537
Case #93: 647380340
Case #94: 33023369
Case #95: 265855059
Case #96: 395710102
Case #97: 219784901
Case #98: 271578431
Case #99: 464328452
Case #100: 916185499
Case #101: 670326
Case #102: 640640014
Case #103: 93349543
Case #104: 862812238
Case #105: 281536946
Case #106: 702810485
Case #107: 259138663
Case #108: 702715572
Case #109: 584125470
Case #110: 606799038
Case #111: 327490945
Case #112: 67483023
Case #113: 277788407
Case #114: 305504371
Case #115: 444414035
Case #116: 59488476
Case #117: 543018984
Case #118: 327306769
Case #119: 202638506
Case #120: 566349205
Case #121: 914714858
Case #122: 772637922
Case #123: 736188939
Case #124: 492363658
Case #125: 384127439
Case #126: 307443765
Case #127: 599884426
Case #128: 50990880
Case #129: 907326279
Case #130: 914629767

Case #1: 8 0
Case #2: 54 0
Case #3: 703 0
Case #4: 79 0
Case #5: 392316013 0
Case #6: 629393408 0
Case #7: 12356631 0
Case #8: 333978835 0
Case #9: 559559045 0
Case #10: 360496048 0
Case #11: 515456933 0
Case #12: 850646951 0
Case #13: 721819701 0
Case #14: 148809737 0
Case #15: 564090199 0
Case #16: 166004829 0
Case #17: 868505184 0
Case #18: 607372318 0
Case #19: 368596750 0
Case #20: 580004047 0
Case #21: 985787637 0
Case #22: 958378586 0
Case #23: 582904197 0
Case #24: 113698003 0
Case #25: 746615724 0
Case #26: 81705531 0
Case #27: 885941873 0
Case #28: 403526859 0
Case #29: 679514418 0
Case #30: 265847293 0
Case #31: 784312052 0
Case #32: 590398147 0
Case #33: 522433821 0
Case #34: 606213570 1
Case #35: 868341676 1
Case #36: 131508862 1
Case #37: 482694668 1
Case #38: 489618439 1
Case #39: 180026427 1
Case #40: 232548601 1
Case #41: 638492541 1
Case #42: 721727046 1
Case #43: 343017821 1
Case #44: 884111229 1
Case #45: 170453385 1
Case #46: 47410749 1
Case #47: 807373984 1
Case #48: 472972570 1
Case #49: 296669200 1
Case #50: 926427272 1
Case #51: 796981956 1
Case #52: 40726084 1
Case #53: 612455717 1
Case #54: 880539615 1
Case #55: 635158858 1
Case #56: 552281495 1
Case #57: 70061599 1
Case #58: 442753590 1
Case #59: 556731536 1
Case #60: 486499723 1
Case #61: 136624108 1
Case #62: 445837090 1
Case #63: 587575830 1
Case #64: 592096251 1
Case #65: 169750441 1
Case #66: 241124439 1
Case #67: 382211207 2
Case #68: 659576165 2
Case #69: 970638083 2
Case #70: 184731895 2
Case #71: 964130248 2
Case #72: 903602867 2
Case #73: 687960566 2
Case #74: 960068821 2
Case #75: 619883327 2
Case #76: 292618914 2
Case #77: 906938848 2
Case #78: 688713973 2
Case #79: 39998712 2
Case #80: 754197379 2
Case #81: 275133340 2
Case #82: 186353806 2
Case #83: 899738796 2
Case #84: 441248264 2
Case #85: 632086514 2
Case #86: 542193083 2
Case #87: 261444729 2
Case #88: 727192061 2
Case #89: 722285916 2
Case #90: 225099844 2
Case #91: 536451454 2
Case #92: 193258537 2
Case #93: 647380340 2
Case #94: 33023369 2
Case #95: 265855059 2
Case #96: 395710102 2
Case #97: 219784901 2
Case #98: 271578431 2
Case #99: 464328452 3
Case #100: 916185499 3
Case #101: 670326 3
Case #102: 640640014 3
Case #103: 93349543 3
Case #104: 862812238 3
Case #105: 281536946 3
Case #106: 702810485 3
Case #107: 259138663 3
Case #108: 702715572 3
Case #109: 584125470 3
Case #110: 606799038 3
Case #111: 327490945 3
Case #112: 67483023 3
Case #113: 277788407 3
Case #114: 305504371 3
Case #115: 444414035 3
Case #116: 59488476 3
Case #117: 543018984 3
Case #118: 327306769 3
Case #119: 202638506 3
Case #120: 566349205 3
Case #121: 914714858 3
Case #122: 772637922 3
Case #123: 736188939 3
Case #124: 492363658 3
Case #125: 384127439 3
Case #126: 307443765 3
Case #127: 599884426 3
Case #128: 50990880 3
Case #129: 907326279 3
Case #130: 914629767 3


Case #1: 392316013
Case #2: 327306769
Case #3: 70061599
Case #4: 193258537
Case #5: 333978835
Case #6: 489618439
Case #7: 727192061
Case #8: 580004047
Case #9: 914714858
Case #10: 721819701
Case #11: 862812238
Case #12: 265847293
Case #13: 647380340
Case #14: 607372318
Case #15: 784312052
Case #16: 556731536
Case #17: 926427272
Case #18: 81705531
Case #19: 868341676
Case #20: 702715572
Case #21: 54
Case #22: 632086514
Case #23: 629393408
Case #24: 916185499
Case #25: 1
Case #26: 582904197
Case #27: 970638083
Case #28: 441248264
Case #29: 885941873
Case #30: 8
Case #31: 472972570
Case #32: 368596750
Case #33: 131508862
Case #34: 395710102
Case #35: 360496048
Case #36: 964130248
Case #37: 907326279
Case #38: 515456933
Case #39: 67483023
Case #40: 12356631
Case #41: 958378586
Case #42: 259138663
Case #43: 40726084
Case #44: 559559045
Case #45: 985787637
Case #46: 638492541
Case #47: 186353806
Case #48: 327490945
Case #49: 445837090
Case #50: 543018984
Case #51: 619883327
Case #52: 482694668
Case #53: 606213570
Case #54: 796981956
Case #55: 79
Case #56: 679514418
Case #57: 271578431
Case #58: 960068821
Case #59: 564090199
Case #60: 590398147
Case #61: 612455717
Case #62: 184731895
Case #63: 659576165
Case #64: 868505184
Case #65: 635158858
Case #66: 180026427
Case #67: 850646951
Case #68: 772637922
Case #69: 148809737
Case #70: 687960566
Case #71: 702810485
Case #72: 552281495
Case #73: 736188939
Case #74: 170453385
Case #75: 522433821
Case #76: 384127439
Case #77: 275133340
Case #78: 722285916
Case #79: 566349205
Case #80: 93349543
Case #81: 225099844
Case #82: 587575830
Case #83: 721727046
Case #84: 113698003
Case #85: 542193083
Case #86: 640640014
Case #87: 241124439
Case #88: 261444729
Case #89: 166004829
Case #90: 265855059
Case #91: 305504371
Case #92: 403526859
Case #93: 746615724
Case #94: 703
Case #95: 807373984
Case #96: 296669200
Case #97: 464328452
Case #98: 486499723
Case #99: 59488476
Case #100: 33023369
Case #101: 292618914
Case #102: 903602867
Case #103: 906938848
Case #104: 584125470
Case #105: 343017821
*/