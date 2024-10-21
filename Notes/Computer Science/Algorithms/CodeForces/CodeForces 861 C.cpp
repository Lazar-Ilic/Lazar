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

Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	L a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
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
	Uh OK so the longest common prefix is quite relevant ugh I misread and misunderstood obviously and then uh from there we can consider the range of values taken on in the range of course. Digit by digit should work quite simply here ugh. Note that uh obviously uh 39520 to 39580 if we can not uh see min and max in prefix and then uh compute uh deviation off of those values I guess bounds uh. Uh OK if the next digit is uh greater then uh we need to like test uh te minimum possible uh... and if it is the next digit on the upper bound is lower than uh minimal ungh.
	4892 is upper we gotta test like 48920000000 is guaranteed in range ungh. Means uh 48919999999 is also guaranteed in range ungh but a uh 1 could be forced ungh either way. Unless ungh 48922222222 is in range I think. I mean 2 is ensured forced yadda. That is certainly via smoothing the uh minimum number greater yadda yadda yadda yadda here works I think ungh.

	Ugh this should be a super duper wooper 0 latency onsight frankly ABCE3 today should all drop down cum down in like 20 minutes flat mooudder fooking Tiger Room Fooking Looking Shook At Temple Magical Miracle Mystical Digital Gold Oracle Mathangi Tigress Room Fooking Metall Auf Metall Gymnasium In London 04:00AM some lower middle class chick was 'mirin' me 5 years ago sik brah should have been tweaking tweaking tweaking off that matcha kafa shit bro' history histoire books hottie hot hot London babes jacked shredded 'mirin' brahs. Radical revolutionary evolutionary odyssey 'mirin' that 16 year old sik brah girly girl Zhang Laura Yingyue via the 4k on YouTube fook yeah fooking paedophile Pervert shit whatever 'mirin' her blossom bosoms lmao kekkorino we need a real fucking practical MariGold miracle.

	Pretty fucking dreck early morning day core 04:00AM In The Morning round frankly just that slightest bit of lethargy tanks me I could have been a uh +130 on the round to 2050 Personal Record still a 1983 is within a solid Top 50 to Master 2100 now so both 2-Kyu and Master are 1 Round away maybe maybe maybe 2 depending.

	Task E is like aiyaa igad Yikes "The Matrix Has ATTACKED ME" - Andrew Tate

	In terms of me here ungh ungh ungh ungh dude if I was phat chilling with Laura in the flesh right now or some of those 19 year olds at MassTech brah dude sik brahs LASER Razer REZA rays of Light be like Sun boom use English ungh The Sun ungh singular UNGH yuck yunghck Camp Alpha Wolf Tiger Flow Gang is Forever sik brahs I am 1 with the people love for all and all for 1 Mathangi gang dude sik brah Tiger Room fooking looking shook at so that is lick it flick it licky flicky drip it ungh I aim at your Temple you are insane ungh mental Safe House Sane House bona fide IO House shit frankly bull shit love for Lana ungh Lana the GOAT and Aaron Benjamin Sorkin the Rank 2 in my books kekkorino West Wing shit ninjas ungh fake frauds know 0 Doctor Lawyer shit sik sikker than sik Obama was my neighbour in Kauai Neo-Kyoto shit ungh whatever Beach Better whatever matcha got a girl wetter ungh wed her ungh Japanese Flowers ungh Bae Doona shit whatever Mauna Keau Seoul SOL keep the rants private ranting like the David Foster Wallace dude you know real bona fide > 180IQ gang shit GENIUS GENIUS GENIUS GENIUS Rest In Peace hanging with the sloths whatever sik brah hanging with the cows other-centeredness I gotta Focus on the girly girls and their feelings you know sik brah that what I gotta Win Rank 1 Focus on in the sik esthetic revolutionary radical odyssey universe lames can not chill with me hot hot hot hot soon I will flexture on YouTube maybe deliver some lectures on Algorithms or discussion once I hit 1-Dan GrandMaster on training strategies and more upsolving or something thank that Errichto guy for the motivational inspirational short films from Poland ungh foreign ungh from Japan ungh Michael Kenji is the GOATTF poet ungh Murakami literally metaphorically Michaelangelo ungh ungh ungh ungh yunghck King LASER... show her my 4k beauty beaut booty boot fruity toot squatting Pumping Iron in the home Metall Auf Metall gymnasium from Proto IO 2 in Austin or Boston.
	*/

	in>>al>>bl;
	m=9;
	nnnl=al;
	for(cl=al;m>0 and cl<al+11 and cl<=bl;cl++){
		// Test number c.
		d=0; // Max
		e=9;
		fl=cl;
		while(fl!=0){
			if(fl%10>d)d=fl%10;
			if(fl%10<e)e=fl%10;
			fl/=10;
		}
		if(d-e<m){
			m=d-e;
			nnnl=cl;
		}
	}
	// How to compute uh longest prefix ungh?
	cl=1000000000000000000;
	dl=100000000000000000;
	el=0; // Longest uh prefix value.
	if(bl==cl){
		if(al==cl)out<<cl<<nl;
		else out<<cl-1<<nl;
		return;
	}
	// If the longest prefix has size 0 done boom uh 9999.
	if(I(log10(al))!=I(log10(bl))){
		while(cl>max(al,bl))cl/=10;
		out<<cl-1<<nl;
		return;
	}
	d=0;
	e=9;
	while(cl>0 and (al/cl)%10==(bl/cl)%10){
		el+=cl*((al/cl)%10);
		if((al/cl)%10>d)d=(al/cl)%10;
		if((al/cl)%10<e)e=(al/cl)%10;
		cl/=10;
	}
	cl-=1;
	cl/=9;
	if(cl<1)cl=1;
	for(f=0;f<=9;f++){
		if(el+cl*f>=al and el+cl*f<=bl){
			//out<<el+cl*f<<nl;
			//return;
			g=0; // Max
			h=9;
			fl=el+cl*f;
			while(fl!=0){
				if(fl%10>g)g=fl%10;
				if(fl%10<h)h=fl%10;
				fl/=10;
			}
			if(g-h<m){
				m=g-h;
				nnnl=el+cl*f;
			}
		}
	}
	cl*=9;
	cl+=1;
	cl/=10;
	for(f=0;f<=9;f++){
		if(el+cl*f>=al and el+cl*f<=bl){
			//out<<el+cl*f<<nl;
			//return;
			g=0; // Max
			h=9;
			fl=el+cl*f;
			while(fl!=0){
				if(fl%10>g)g=fl%10;
				if(fl%10<h)h=fl%10;
				fl/=10;
			}
			if(g-h<m){
				m=g-h;
				nnnl=el+cl*f;
			}
		}
	}
	out<<nnnl<<nl;
}

I main(){zz();I a=1;in>>a;while(a--){az();}}