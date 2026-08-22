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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 433494437 993353399

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

	// This is an O[n*log[p]+t] solution with precomputed exp powers of 2 function.
	in>>a>>b>>c>>d>>e;
	if(((d==a) and (b==1 or b==a)) or ((e==a) and (c==1 or c==a))){out<<0<<nl;return;}
	f=c-b-1; // Number of spots between 2 values.
	if(d>e){g=b-1;h=a-c;}
	else{g=a-c;h=b-1;i=d;d=e;e=i;}
	al=(exp(2,a-d-1)*choose(d-e-1,f-(a-d))%p*choose(e-1,g-(d-e-1-(f-(a-d))))%p+(g>a-d and a>d)*exp(2,a-d-1)*choose(d-e-1,f)%p*choose(e-1,g-(a-d)+f-(d-e-1))%p+(g==a-d and a>d)*(exp(2,a-d-1)-1)*choose(d-e-1,f)%p*choose(e-1,g-(a-d)+f-(d-e-1))%p)%p;
	out<<al<<nl;
	//al=(exp(2,a-d-1)*choose(d-e-1,f-(a-d))%p*choose(e-1,g-(d-e-1-(f-(a-d))))%p+B(g>a-d and a>d)*exp(2,a-d-1)*choose(d-e-1,f)%p*choose(e-1,g-(a-d)+f-(d-e-1))%p+B(g==a-d and a>d)*(exp(2,a-d-1)-1)*choose(d-e-1,f)%p*choose(e-1,g-(a-d)+f-(d-e-1))%p)%p;
	/*
	if(a-d>f){
		out<<0<<nl;
		return;
	}
	*/
	/*
	al=1;
	al=al*exp(2,a-d-1)%p;
	al=al*choose(d-e-1,f-(a-d))%p;
	//out<<d-e-1<<" "<<f-(a-d)<<nl;
	al=al*choose(e-1,g-(d-e-1-(f-(a-d))))%p;
	//out<<e-1<<" "<<g-(d-e-1-(f-(a-d)))<<nl;
	//out<<al<<nl;
	// Oh I see and there can also be caseworks upon cases where in fact the maximum peak value occurs outside of the target interior range so I made a pretty critical costly time sink latency error here tanking for 15 minutes which costs me the round critically but OKOKOK we can certainly fix that type of error patch it up here with some follow on simple loop casework summation on those cases too I think. Oh Jeez Louise I did not even realise Late Registration only works for 15:00 minutes or so after the start of the round otherwise I would have pinged the server with my registration status immediately upon onsighting this here task D after A and B today.
	for(z=1;z<g;z++){ // Number of spots next to greater taken up to maximum peak.
		// Test spot for maximum value forces interior values interior and then case from there on maximal values in range etc. etc.
		if(f>d-e-1 or z>a-d)continue;
		bl=1;
		bl=bl*choose(d-e-1,f)%p;
		bl=bl*choose(a-d-1,z-1)%p;
		bl=bl*choose(e-1,g-z-(d-e-1-f)-(a-d-1-(z-1)))%p;
		al=(al+bl)%p;
	}

	I personally find "this type of shit happen every day" to be annoying when dudes like Neal Wu can ping in with shitty Dynamic Programming codes... the tasks setters should always aspire to set sharp bounds like 1000000 1000000 here:

void run_case() {
    int N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    A--; B--; X--; Y--;
    vector<vector<mod_int>> dp(N + 1, vector<mod_int>(N + 1, 0));
    dp[0][N] = 1;
 
    auto valid = [&](int index, int value) -> bool {
        return !(index == A && value != X) && !(index == B && value != Y);
    };
 
    for (int i = 0; i < N; i++)
        for (int j = N; j > i; j--) {
            if (j - i == 1 && (i == 0 || j == N))
                continue;
 
            int next = N - (j - i);
 
            if (valid(i, next))
                dp[i + 1][j] += dp[i][j];
 
            if (j - i > 1 && valid(j - 1, next))
                dp[i][j - 1] += dp[i][j];
        }
 
    mod_int total = 0;
 
    for (int i = 1; i < N; i++)
        total += dp[i][i];
 
    cout << total << '\n';

	Not sure if the Hudson River Trading Check gang is looking down upon this code right here I mean why would you choose to write such gross disgusting repulsive egregiously anti intellectual low brow trash garbage scum fake fraudulent ninja code when we can Make It Better? Priceless. Neal Wu of the Rank 1 Poo Poo Poo Poo Woo Wu Poon Tang Clan here demonstrating his lack of algorisms prowess. I am just kidding sik brah bloody hell I look so fucking weaky weak out here need to study study study more codesbases. I just been in a grumpy grouchy bad mood for a minute now brah I love the sik brahs Andrew He, Kevin Sun, Neal Wu posting up on the YouTube platform system and shieeet you love to see some competitors mang would have loved to take down the Rank 1 on every single Project Leonhard Euler Round you know mang you and I are not the same Numbers don't lie, you know I see that. LOGIC. I was just fucking angry raging Joshuaing around in public. OKOKOK never again never again never again I need to learn the lessons from history, Scott Aaronson, Kanye West, et al. and never again engage in public writing which would be deemed and classified by many in America 2022 to be the "racism" or "scientific racism" content. It does not matter just how shitty I am feeling or how bad and low my Indoor air Quality is. The Hudson River Trading firm has a strong stance against what they deem to be the "racist" sort of .txt files and perhaps the coolture culture vulture kind as well. OK so no more mentioning traditional Chinese poetry either. Brah I love all the poetries and people brah love every single sik brah human out there brah I am on my Lex Fridman shieeet All Day ninja brah so no more slurring around the "Ninja" string like the Hudson River Trading firm OKOKOK aight sik brah Keyboard Warriors!
}
 
	*/
}

I main(){zz();I a=1;in>>a;while(a--){az();}}