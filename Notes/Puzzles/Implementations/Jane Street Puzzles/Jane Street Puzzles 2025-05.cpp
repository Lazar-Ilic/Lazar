// "We're living Ultralife" - Josephine Vander Gucht <3
// https://GitHub.com/Lazar-Ilic/Lazar/blob/main/Notes/Ideas/Productivity.txt
//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <sys/time.h>
//#include <bits/extc++.h>
// Instead Of Recoding Can Change Definition Like D To long double
using B=bool;// 8 bits=1 byte | [0,1]
using C=char;// 8 bits=1 byte | [-128,127]
using D=double;// 64 bits=8 bytes | [Eh]
using LD=long double;// 96 bits=12 bytes | [Eh]
using I=int;// 32 bits=4 bytes | [-2147483648,2147483647] ~ [-2*10^9,2*10^9]
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
using MLVV=map<L,VV>;
using MPV=map<P,V>;
using MPVV=map<P,VV>;
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
	ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);out<<fixed<<setprecision(20);
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);//freopen("b.txt","w",stdout);
	#endif
}
Z outv(V av){
	if(sz(av)==0)return;
	for(I a=0;a<sz(av);a++){
		if(av[a]!=10)out<<av[a]<<" ";
		else out<<"x ";
	}
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
const I p=1000000007;// 998244353 1000000007 // 1073741824 * 2 > INT_MAX So 1234567891 Forces (long long) Conversion Or Usage Before + Modulo p
// L 1000000000039 1000000000000037 1000000000000000003
//--------------------------------------------------------------------

void generate(int remaining, std::vector<int>& current, int last,
	std::vector<std::vector<int>>& result) {
if (remaining == 0) {
result.push_back(current);
return;
}

for (int i = 1; i <= remaining; ++i) {
if ((i == 1 && last == 1) || (i > 1 && last > 1)) continue; // disallow adjacent 1s or adjacent >1s
current.push_back(i);
generate(remaining - i, current, i, result);
current.pop_back();
}
}

VV rowtovv(V av){
	// Can Return Empty VV If Multiplicity Has Been Detected Inside Row I Guess
	V bv(0);
	VV avv;
	for(I a=0;a<11;a++){
		if(av[a]<10)bv.add(av[a]);
		else if(av[a]==10 and sz(bv)>0){
			avv.add(bv);
			bv=V(0);
		}
	}
	if(sz(bv))avv.add(bv);
	sortify(avv);
	for(I a=1;a<sz(avv);a++)if(avv[a]==avv[a-1])return {};
	return avv;
}

B vvchecker(VV avv){
	sortify(avv);
	for(I a=1;a<sz(avv);a++)if(avv[a]==avv[a-1])return 0;
	return 1;
}

struct Edge {
    int to, rev, cap;
};

class MaxFlow {
public:
    MaxFlow(int N) {
        graph.resize(N);
        level.resize(N);
        iter.resize(N);
    }

    void addEdge(int from, int to, int cap) {
        graph[from].push_back({to, (int)graph[to].size(), cap});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0});
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INT_MAX)) > 0)
                flow += f;
        }
        return flow;
    }

public:
    vector<vector<Edge>> graph;
    vector<int> level, iter;

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (size_t i = 0; i < graph[v].size(); ++i) {
                Edge& e = graph[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int upTo) {
        if (v == t) return upTo;
        for (int& i = iter[v]; i < (int)graph[v].size(); ++i) {
            Edge& e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(upTo, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

bool isPossibleFlowBased(vector<vector<int>> initial, vector<vector<int>> target, vector<vector<bool>> canSend) {
    int m = initial.size();
    int n = initial[0].size();
    int numCells = m * n;
    int source = numCells, sink = numCells + 1;
    MaxFlow mf(numCells + 2);

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    auto cellId = [&](int i, int j) { return i * n + j; };
    int totalSend = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int id = cellId(i, j);
            int delta = target[i][j] - initial[i][j];

            if (canSend[i][j] && initial[i][j] > 0) {
                mf.addEdge(source, id, initial[i][j]);
                totalSend += initial[i][j];
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        int nid = cellId(ni, nj);
                        mf.addEdge(id, nid, INT_MAX);
                    }
                }
            }

            if (delta > 0) {
                mf.addEdge(id, sink, delta);
            }
        }
    }

    int flow = mf.maxFlow(source, sink);
    if (flow != totalSend)
        return false;

    // 🎯 Inline flow visualization
    vector<vector<string>> display(m, vector<string>(n, "   \n   \n   "));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!canSend[i][j]) continue;
            int id = cellId(i, j);

            string cell[3] = {"   ", "   ", "   "};

            for (Edge e : mf.graph[id]) {
                if (e.to >= numCells || e.cap == 0) continue;

                int ni = e.to / n;
                int nj = e.to % n;
                int sent = mf.graph[e.to][e.rev].cap;
                if (sent == 0) continue;

                char ch = (sent < 10 ? '0' + sent : '*');
                if (ni == i - 1 && nj == j)      cell[0][1] = ch;
                else if (ni == i + 1 && nj == j) cell[2][1] = ch;
                else if (ni == i && nj == j - 1) cell[1][0] = ch;
                else if (ni == i && nj == j + 1) cell[1][2] = ch;
            }

            display[i][j] = cell[0] + '\n' + cell[1] + '\n' + cell[2];
        }
    }

    // 🖨️ Print 3x3 blocks
    for (int row = 0; row < m; ++row) {
        for (int line = 0; line < 3; ++line) {
            for (int col = 0; col < n; ++col) {
                cout << display[row][col].substr(line * 4, 3) << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return true;
}

I testcase=0;
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
	//out<<"Case #"<<++testcase<<": ";
/*
Post Contest Analysis:
Fun round. I am sure there are many ways my code could be improved. Make rowss a vector of vectors so we loop through like for(V rowss[0]:rows[0][r0]) and then could maybe write up a different checker function highly optimised in a separate function. Though that enables less custom control over logical circuiting to reduce cases as rapidly as possible. Another way to really be sophisticated in sharper settings is to like say we know some stuff here but write an algorithm to use minimum cost maximum flow to actually look for little patterns like I did manually little logical patterns which imply there exists no solution to a minimum cost maximum flow. Then try and generate more of those little 1 line checkers to reduce prune cases without running an excessive number of mcmcs. But do this in an automated fashion to keep track of our sharpest logical checkers thus far.

Test+Additional Input:

[Worst-Case Runtime] Analysis:

*/

	int target = 11;
	std::vector<std::vector<int>> compositions;
	std::vector<int> current;
	generate(target, current, -1, compositions); // -1 means no previous number
	/*
	// Print the results (optional)
	for (const auto& comp : compositions) {
		for (size_t i = 0; i < comp.size(); ++i) {
			if (i > 0) std::cout << " ";
			std::cout << comp[i];
		}
		std::cout << '\n';
	}

	std::cout << "Total compositions: " << compositions.size() << '\n';
	*/
	B checker; // Eh Alright To Use I Guess But Locally In Loop Is Sharper Probably
	V lowers;
	lowers={2,4,3,4,1,3,6,7,1}; // Eyeball Guess. Can Change Later. Observe Output Through Row 5 Or Whatever
	// Filter Using Lowers As Fast As Possible
	/*
	25341 Was Obviously Worth Trying As Well As 24341
	25641 Solid Number Of Solutions
	25741 FAILED
	24341 Solid I Guess... Still Seems Like Maybe Some Logical Error With Respect To This Diagonal Of Xs And The Implication There
	Tried:
	213X5
	21315 FAILED
	21345 FAILED
	21365 FAILED
	21375 FAILED
	21385 FAILED
	214X5
	21415 FAILED
	21435 FAILED
	21465 FAILED
	21475 
	21485 
	216X5
	21615 FAILED
	21635
	21645
	217X5
	218X5
	Maybe Try These Rigourously Later Maybe Nah
	*/
	VV positions(11,V(11,0));
	positions[0] ={0,0,0,0,0,0,0,0,0,0,0};
	positions[1] ={0,1,0,0,0,0,0,0,0,0,0};
	positions[2] ={1,1,2,2,2,2,3,3,3,0,3};
	positions[3] ={1,2,2,1,2,4,3,3,3,3,3};
	positions[4] ={1,2,2,1,2,4,4,3,3,4,3};
	positions[5] ={1,1,1,1,1,4,4,4,4,4,3};
	positions[6] ={1,5,6,6,1,1,4,4,6,4,4};
	positions[7] ={1,5,6,6,6,6,6,6,6,7,7};
	positions[8] ={5,5,5,5,6,5,6,7,7,7,7};
	positions[9] ={5,5,5,5,5,5,5,5,5,5,5};
	positions[10]={5,5,8,8,8,8,8,8,5,5,5};
	VV before(9,V(11,0));
	VV targett(9,V(11,0));
	for(a=0;a<9;a++)for(b=0;b<11;b++)before[a][b]=lowers[positions[a][b]];
	before[8][2]-=2;before[8][8]-=2;
	// We Want To Be Pruning Here In Loop I Think Is Sharper On Runtime With Respect To lowers
	VVP avvp(sz(compositions),VP(0));
	for(a=0;a<sz(compositions);a++){
		V shape=compositions[a];
		b=0;
		for(c=0;c<sz(shape);c++){
			avvp[a].add({b,b+shape[c]});
			b+=shape[c]; // Each Pair Stores The [) Bounds For That Chunk In That shape
		}
	}
	avvb=VVB(sz(compositions),VB(sz(compositions),0)); // Can Go Through And Mark Compatible Compositions With Eachother
	bvv=VV(sz(compositions),V(0)); // List Of Compatible With Subindices
	dvv=VV(sz(compositions),V(0)); // Composition To Binary Where 1 Represents Black Here
	for(a=0;a<sz(compositions);a++){
		for(b=a;b<sz(compositions);b++){
			av=V(0);
			bv=V(0);
			for(I dude:compositions[a]){
				if(dude==1)av.add(1);
				else{
					for(c=0;c<dude;c++)av.add(0);
				}
			}
			for(I dude:compositions[b]){
				if(dude==1)bv.add(1);
				else{
					for(c=0;c<dude;c++)bv.add(0);
				}
			}
			if(sz(av)!=11 or sz(bv)!=11)out<<"ERROR"<<nl;
			dvv[a]=av;
			I valid=1;
			for(c=0;valid and c<11;c++)if(av[c] and bv[c])valid=0;
			if(valid){
				avvb[a][b]=1;
				avvb[b][a]=1;
				bvv[a].add(b);
				bvv[b].add(a);
			}
		}
	}
	VVVV rows(11,VVV(sz(compositions),VV(0,V(0)))); // For Storing Potential Rows Underneath lowers
	VVV lols(12,VV(0,V(0)));
	lols=VVV(12,VV(0,V(0)));
	for(bl=1;bl*bl<(long long)100000000000;bl++){
		av=V(0);
		cl=bl*bl;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=0; // Position
	for(a=0;a<sz(compositions);a++){
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}
	//for(a=0;a<5;a++)outvv(rows[y][a]);
	// Later Will Need To Think About How To Check Back Elements In Covered Rows To Verify Incorrectness Could Check The Sum Of Deltas Next To Black Is At Least As Large As It Needs To Be And Also The Delta For Any White Is Less Than It Can Be

	lols=VVV(12,VV(0,V(0)));
	cvv={{4,5},{5,4},{5,1,4},{4,1,5},{1,4,5},{1,5,4},{5,2,2},{2,5,2},{2,2,5},{1,5,2,2},{1,2,5,2},{1,2,2,5},{5,1,2,2},{2,1,5,2},{2,1,2,5}};
	for(V cv:cvv)lols[sz(cv)].add(cv);
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=1; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][3]==0 and dvv[a][4]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[3]==lowers[0] and av[4]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	lols=VVV(12,VV(0,V(0)));
	for(bl=13;bl<100000000;bl+=13){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=2; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][4]==0 and dvv[a][9]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[4]==lowers[2] and av[9]==lowers[0])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	lols=VVV(12,VV(0,V(0)));
	for(bl=32;bl<100000000;bl+=32){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=3; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][8]==0 and dvv[a][9]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[8]==lowers[3] and av[9]==lowers[3])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	lols=VVV(12,VV(0,V(0)));
	for(bl=10;bl<100000000;bl++){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0 or bl%(cl%10)!=0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=4; // Position
	for(a=0;a<sz(compositions);a++){if(1){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}
	al=0;
	for(a=0;a<sz(compositions);a++)al+=sz(rows[y][a]);
	out<<al<<nl;

	lols=VVV(12,VV(0,V(0)));
	for(b=2;b<=11;b++){
		for(c=0;c<b;c++){
			for(d=c+1;d<b;d++){
				av=V(b,1);
				av[c]=5;
				av[d]=5;
				lols[b].add(av);
			}
		}
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=5; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][5]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[5]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	lols=VVV(12,VV(0,V(0)));
	for(bl=10;bl<100000000;bl++){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0 or bl%(cl%10)!=0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=6; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][1]==0 and dvv[a][2]==0 and dvv[a][5]==0 and dvv[a][6]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[1]==lowers[5] and av[2]==lowers[6] and av[5]==lowers[1] and av[6]==lowers[4])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}
	al=0;
	for(a=0;a<sz(compositions);a++)al+=sz(rows[y][a]);
	out<<"al now "<<al<<nl;

	lols=VVV(12,VV(0,V(0)));
	for(b=1;b<=9;b+=2){
		av={b,b};
		lols[2].add(av);
	}
	for(b=1;b<=9;b+=2){
		for(c=1;c<=9;c++){
			av={b,c,b};
			lols[3].add(av);
			av={b,c,c,b};
			lols[4].add(av);
		}
	}
	for(b=1;b<=9;b+=2){
		for(c=1;c<=9;c++){
			for(d=1;d<=9;d++){
				av={b,c,d,c,b};
				lols[5].add(av);
				av={b,c,d,d,c,b};
				lols[6].add(av);
			}
		}
	}
	for(b=1;b<=9;b+=2){
		for(c=1;c<=9;c++){
			for(d=1;d<=9;d++){
				for(e=1;e<=9;e++){
					av={b,c,d,e,d,c,b};
					lols[7].add(av);
					av={b,c,d,e,e,d,c,b};
					lols[8].add(av);
				}
			}
		}
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=7; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][1]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[1]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	lols=VVV(12,VV(0,V(0)));
	al=1;
	bl=1;
	while(bl<(long long)100000000000){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0){ // Can Remove Later If Needed
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
		cl=al+bl;
		al=bl;
		bl=cl;
	}
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=8; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][4]==0 and dvv[a][5]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[4]==lowers[6] and av[5]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}
	al=0;
	for(a=0;a<sz(compositions);a++)al+=sz(rows[y][a]);
	out<<"Fibonacci rows "<<al<<nl;
	for(a=0;a<sz(compositions);a++)outvv(rows[y][a]);

	evv={{5,5,9,9},{5,9,5,9},{5,9,9,5},{9,5,5,9},{9,5,9,5},{9,9,5,5},{1,5,5,9,9},{1,5,9,5,9},{1,5,9,9,5},{1,9,5,5,9},{1,9,5,9,5},{1,9,9,5,5},{3,3,5,5,9},{3,3,5,9,5},{3,3,9,5,5},{3,5,3,5,9},{3,5,3,9,5},{3,5,5,3,9},{3,5,5,9,3},{3,5,9,3,5},{3,5,9,5,3},{3,9,3,5,5},{3,9,5,3,5},{3,9,5,5,3},{5,1,5,9,9},{5,1,9,5,9},{5,1,9,9,5},{5,3,3,5,9},{5,3,3,9,5},{5,3,5,3,9},{5,3,5,9,3},{5,3,9,3,5},{5,3,9,5,3},{5,5,1,9,9},{5,5,3,3,9},{5,5,3,9,3},{5,5,9,1,9},{5,5,9,3,3},{5,5,9,9,1},{5,9,1,5,9},{5,9,1,9,5},{5,9,3,3,5},{5,9,3,5,3},{5,9,5,1,9},{5,9,5,3,3},{5,9,5,9,1},{5,9,9,1,5},{5,9,9,5,1},{9,1,5,5,9},{9,1,5,9,5},{9,1,9,5,5},{9,3,3,5,5},{9,3,5,3,5},{9,3,5,5,3},{9,5,1,5,9},{9,5,1,9,5},{9,5,3,3,5},{9,5,3,5,3},{9,5,5,1,9},{9,5,5,3,3},{9,5,5,9,1},{9,5,9,1,5},{9,5,9,5,1},{9,9,1,5,5},{9,9,5,1,5},{9,9,5,5,1},{1,1,5,5,9,9},{1,1,5,9,5,9},{1,1,5,9,9,5},{1,1,9,5,5,9},{1,1,9,5,9,5},{1,1,9,9,5,5},{1,3,3,5,5,9},{1,3,3,5,9,5},{1,3,3,9,5,5},{1,3,5,3,5,9},{1,3,5,3,9,5},{1,3,5,5,3,9},{1,3,5,5,9,3},{1,3,5,9,3,5},{1,3,5,9,5,3},{1,3,9,3,5,5},{1,3,9,5,3,5},{1,3,9,5,5,3},{1,5,1,5,9,9},{1,5,1,9,5,9},{1,5,1,9,9,5},{1,5,3,3,5,9},{1,5,3,3,9,5},{1,5,3,5,3,9},{1,5,3,5,9,3},{1,5,3,9,3,5},{1,5,3,9,5,3},{1,5,5,1,9,9},{1,5,5,3,3,9},{1,5,5,3,9,3},{1,5,5,9,1,9},{1,5,5,9,3,3},{1,5,5,9,9,1},{1,5,9,1,5,9},{1,5,9,1,9,5},{1,5,9,3,3,5},{1,5,9,3,5,3},{1,5,9,5,1,9},{1,5,9,5,3,3},{1,5,9,5,9,1},{1,5,9,9,1,5},{1,5,9,9,5,1},{1,9,1,5,5,9},{1,9,1,5,9,5},{1,9,1,9,5,5},{1,9,3,3,5,5},{1,9,3,5,3,5},{1,9,3,5,5,3},{1,9,5,1,5,9},{1,9,5,1,9,5},{1,9,5,3,3,5},{1,9,5,3,5,3},{1,9,5,5,1,9},{1,9,5,5,3,3},{1,9,5,5,9,1},{1,9,5,9,1,5},{1,9,5,9,5,1},{1,9,9,1,5,5},{1,9,9,5,1,5},{1,9,9,5,5,1},{3,1,3,5,5,9},{3,1,3,5,9,5},{3,1,3,9,5,5},{3,1,5,3,5,9},{3,1,5,3,9,5},{3,1,5,5,3,9},{3,1,5,5,9,3},{3,1,5,9,3,5},{3,1,5,9,5,3},{3,1,9,3,5,5},{3,1,9,5,3,5},{3,1,9,5,5,3},{3,3,1,5,5,9},{3,3,1,5,9,5},{3,3,1,9,5,5},{3,3,3,3,5,5},{3,3,3,5,3,5},{3,3,3,5,5,3},{3,3,5,1,5,9},{3,3,5,1,9,5},{3,3,5,3,3,5},{3,3,5,3,5,3},{3,3,5,5,1,9},{3,3,5,5,3,3},{3,3,5,5,9,1},{3,3,5,9,1,5},{3,3,5,9,5,1},{3,3,9,1,5,5},{3,3,9,5,1,5},{3,3,9,5,5,1},{3,5,1,3,5,9},{3,5,1,3,9,5},{3,5,1,5,3,9},{3,5,1,5,9,3},{3,5,1,9,3,5},{3,5,1,9,5,3},{3,5,3,1,5,9},{3,5,3,1,9,5},{3,5,3,3,3,5},{3,5,3,3,5,3},{3,5,3,5,1,9},{3,5,3,5,3,3},{3,5,3,5,9,1},{3,5,3,9,1,5},{3,5,3,9,5,1},{3,5,5,1,3,9},{3,5,5,1,9,3},{3,5,5,3,1,9},{3,5,5,3,3,3},{3,5,5,3,9,1},{3,5,5,9,1,3},{3,5,5,9,3,1},{3,5,9,1,3,5},{3,5,9,1,5,3},{3,5,9,3,1,5},{3,5,9,3,5,1},{3,5,9,5,1,3},{3,5,9,5,3,1},{3,9,1,3,5,5},{3,9,1,5,3,5},{3,9,1,5,5,3},{3,9,3,1,5,5},{3,9,3,5,1,5},{3,9,3,5,5,1},{3,9,5,1,3,5},{3,9,5,1,5,3},{3,9,5,3,1,5},{3,9,5,3,5,1},{3,9,5,5,1,3},{3,9,5,5,3,1},{5,1,1,5,9,9},{5,1,1,9,5,9},{5,1,1,9,9,5},{5,1,3,3,5,9},{5,1,3,3,9,5},{5,1,3,5,3,9},{5,1,3,5,9,3},{5,1,3,9,3,5},{5,1,3,9,5,3},{5,1,5,1,9,9},{5,1,5,3,3,9},{5,1,5,3,9,3},{5,1,5,9,1,9},{5,1,5,9,3,3},{5,1,5,9,9,1},{5,1,9,1,5,9},{5,1,9,1,9,5},{5,1,9,3,3,5},{5,1,9,3,5,3},{5,1,9,5,1,9},{5,1,9,5,3,3},{5,1,9,5,9,1},{5,1,9,9,1,5},{5,1,9,9,5,1},{5,3,1,3,5,9},{5,3,1,3,9,5},{5,3,1,5,3,9},{5,3,1,5,9,3},{5,3,1,9,3,5},{5,3,1,9,5,3},{5,3,3,1,5,9},{5,3,3,1,9,5},{5,3,3,3,3,5},{5,3,3,3,5,3},{5,3,3,5,1,9},{5,3,3,5,3,3},{5,3,3,5,9,1},{5,3,3,9,1,5},{5,3,3,9,5,1},{5,3,5,1,3,9},{5,3,5,1,9,3},{5,3,5,3,1,9},{5,3,5,3,3,3},{5,3,5,3,9,1},{5,3,5,9,1,3},{5,3,5,9,3,1},{5,3,9,1,3,5},{5,3,9,1,5,3},{5,3,9,3,1,5},{5,3,9,3,5,1},{5,3,9,5,1,3},{5,3,9,5,3,1},{5,5,1,1,9,9},{5,5,1,3,3,9},{5,5,1,3,9,3},{5,5,1,9,1,9},{5,5,1,9,3,3},{5,5,1,9,9,1},{5,5,3,1,3,9},{5,5,3,1,9,3},{5,5,3,3,1,9},{5,5,3,3,3,3},{5,5,3,3,9,1},{5,5,3,9,1,3},{5,5,3,9,3,1},{5,5,9,1,1,9},{5,5,9,1,3,3},{5,5,9,1,9,1},{5,5,9,3,1,3},{5,5,9,3,3,1},{5,5,9,9,1,1},{5,9,1,1,5,9},{5,9,1,1,9,5},{5,9,1,3,3,5},{5,9,1,3,5,3},{5,9,1,5,1,9},{5,9,1,5,3,3},{5,9,1,5,9,1},{5,9,1,9,1,5},{5,9,1,9,5,1},{5,9,3,1,3,5},{5,9,3,1,5,3},{5,9,3,3,1,5},{5,9,3,3,5,1},{5,9,3,5,1,3},{5,9,3,5,3,1},{5,9,5,1,1,9},{5,9,5,1,3,3},{5,9,5,1,9,1},{5,9,5,3,1,3},{5,9,5,3,3,1},{5,9,5,9,1,1},{5,9,9,1,1,5},{5,9,9,1,5,1},{5,9,9,5,1,1},{9,1,1,5,5,9},{9,1,1,5,9,5},{9,1,1,9,5,5},{9,1,3,3,5,5},{9,1,3,5,3,5},{9,1,3,5,5,3},{9,1,5,1,5,9},{9,1,5,1,9,5},{9,1,5,3,3,5},{9,1,5,3,5,3},{9,1,5,5,1,9},{9,1,5,5,3,3},{9,1,5,5,9,1},{9,1,5,9,1,5},{9,1,5,9,5,1},{9,1,9,1,5,5},{9,1,9,5,1,5},{9,1,9,5,5,1},{9,3,1,3,5,5},{9,3,1,5,3,5},{9,3,1,5,5,3},{9,3,3,1,5,5},{9,3,3,5,1,5},{9,3,3,5,5,1},{9,3,5,1,3,5},{9,3,5,1,5,3},{9,3,5,3,1,5},{9,3,5,3,5,1},{9,3,5,5,1,3},{9,3,5,5,3,1},{9,5,1,1,5,9},{9,5,1,1,9,5},{9,5,1,3,3,5},{9,5,1,3,5,3},{9,5,1,5,1,9},{9,5,1,5,3,3},{9,5,1,5,9,1},{9,5,1,9,1,5},{9,5,1,9,5,1},{9,5,3,1,3,5},{9,5,3,1,5,3},{9,5,3,3,1,5},{9,5,3,3,5,1},{9,5,3,5,1,3},{9,5,3,5,3,1},{9,5,5,1,1,9},{9,5,5,1,3,3},{9,5,5,1,9,1},{9,5,5,3,1,3},{9,5,5,3,3,1},{9,5,5,9,1,1},{9,5,9,1,1,5},{9,5,9,1,5,1},{9,5,9,5,1,1},{9,9,1,1,5,5},{9,9,1,5,1,5},{9,9,1,5,5,1},{9,9,5,1,1,5},{9,9,5,1,5,1},{9,9,5,5,1,1}};

	lols=VVV(12,VV(0,V(0)));
	for(V dude:evv)lols[sz(dude)].add(dude);
	lols[1]=VV(0,V(0));
	lols[1].add({10}); // Maybe Try 10 Here For Potentially Easier Calls Later
	y=9; // Position
	for(a=0;a<sz(compositions);a++){if(dvv[a][4]==0){ // Also Wise To Add A Final Checker Maybe Is Adequare For The == Condition Implied And Shit Like
		V shape=compositions[a];
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					av=V(0);
					for(I dude:part0)av.add(dude);
					if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
				}
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
									}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){
											av=V(0);
											for(I dude:part0)av.add(dude);
											for(I dude:part1)av.add(dude);
											for(I dude:part2)av.add(dude);
											for(I dude:part3)av.add(dude);
											for(I dude:part4)av.add(dude);
											if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
										}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){
												av=V(0);
												for(I dude:part0)av.add(dude);
												for(I dude:part1)av.add(dude);
												for(I dude:part2)av.add(dude);
												for(I dude:part3)av.add(dude);
												for(I dude:part4)av.add(dude);
												for(I dude:part5)av.add(dude);
												if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
											}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				checker=1;
				for(b=avvp[a][0].first;checker and b<avvp[a][0].second;b++)if(part0[b-avvp[a][0].first]<lowers[positions[y][b]])checker=0;
				if(checker){
					for(V part1:lols[shape[1]]){
						checker=1;
						for(b=avvp[a][1].first;checker and b<avvp[a][1].second;b++)if(part1[b-avvp[a][1].first]<lowers[positions[y][b]])checker=0;
						if(checker){
							for(V part2:lols[shape[2]]){
								checker=1;
								for(b=avvp[a][2].first;checker and b<avvp[a][2].second;b++)if(part2[b-avvp[a][2].first]<lowers[positions[y][b]])checker=0;
								if(checker){for(V part3:lols[shape[3]]){
									checker=1;
									for(b=avvp[a][3].first;checker and b<avvp[a][3].second;b++)if(part3[b-avvp[a][3].first]<lowers[positions[y][b]])checker=0;
									if(checker){for(V part4:lols[shape[4]]){
										checker=1;
										for(b=avvp[a][4].first;checker and b<avvp[a][4].second;b++)if(part4[b-avvp[a][4].first]<lowers[positions[y][b]])checker=0;
										if(checker){for(V part5:lols[shape[5]]){
											checker=1;
											for(b=avvp[a][5].first;checker and b<avvp[a][5].second;b++)if(part5[b-avvp[a][5].first]<lowers[positions[y][b]])checker=0;
											if(checker){for(V part6:lols[shape[6]]){
												checker=1;
												for(b=avvp[a][6].first;checker and b<avvp[a][6].second;b++)if(part6[b-avvp[a][6].first]<lowers[positions[y][b]])checker=0;
												if(checker){
													av=V(0);
													for(I dude:part0)av.add(dude);
													for(I dude:part1)av.add(dude);
													for(I dude:part2)av.add(dude);
													for(I dude:part3)av.add(dude);
													for(I dude:part4)av.add(dude);
													for(I dude:part5)av.add(dude);
													for(I dude:part6)av.add(dude);
													if(av[4]==lowers[5])if(sz(rowtovv(av)))rows[y][a].add(av);
												}
											}}
										}}
									}}
								}}
							}
						}
					}
				}
			}
		}
	}}

	y=-1;
	w=0;
	// Start Drafting The Final Loop Structure With Checkers Maybe On Both Black Deltas And White Deltas In Reverse As Well As Forced == Try Forced White == First Maybe When Verifying And Moving Forward
	out<<"Start"<<nl;
	x=0;
	for(I r0=0;r0<sz(compositions);r0++){
		for(V row0:rows[0][r0]){
			for(I r1:bvv[r0]){
				for(V row1:rows[1][r1]){
					// Check For Compatibility Already Could Maybe Index To Be Slightly Faster Here By Precomputing The Black And White Values For Each Of r0 r1 ... Not Sure It Really Matters
					checker=1;
					for(a=1;checker and a<10;a++){
						if(row0[a]==10){
							// Black Square Checker
							// Can Check Sum Of Deltas Is >= Force
							if((row0[a-1]-lowers[positions[0][a-1]])+(row0[a+1]-lowers[positions[0][a+1]])+(row1[a]-lowers[positions[1][a]])<lowers[positions[0][a]])checker=0;
						}
						else{
							// White Square Checker
							// Can Check Delta Is <= Force
							I force=0;
							if(row0[a-1]==10)force+=lowers[positions[0][a-1]];
							if(row0[a+1]==10)force+=lowers[positions[0][a+1]];
							if(row1[a]==10)force+=lowers[positions[1][a]];
							if(row0[a]-lowers[positions[0][a]]>force)checker=0;
						}
					}
					if(checker and row0[0]==10){
						// Black Square Checker
						// Can Check Sum Of Deltas Is >= Force
						if((row0[1]-lowers[positions[0][1]])+(row1[0]-lowers[positions[1][0]])<lowers[positions[0][0]])checker=0;
					}
					else if(checker){
						// White Square Checker
						// Can Check Delta Is <= Force
						I force=0;
						if(row0[1]==10)force+=lowers[positions[0][1]];
						if(row1[0]==10)force+=lowers[positions[1][0]];
						if(row0[0]-lowers[positions[0][0]]>force)checker=0;
					}
					if(checker and row0[10]==10){
						// Black Square Checker
						// Can Check Sum Of Deltas Is >= Force
						if((row0[10-1]-lowers[positions[0][10-1]])+(row1[10]-lowers[positions[1][10]])<lowers[positions[0][10]])checker=0;
					}
					else if(checker){
						// White Square Checker
						// Can Check Delta Is <= Force
						I force=0;
						if(row0[10-1]==10)force+=lowers[positions[0][10-1]];
						if(row1[10]==10)force+=lowers[positions[1][10]];
						if(row0[10]-lowers[positions[0][10]]>force)checker=0;
					}
					if(checker){
						VV lolol;VV lolo;
						lolo=rowtovv(row0);
						for(V lololo:lolo)lolol.add(lololo);
						lolo=rowtovv(row1);
						for(V lololo:lolo)lolol.add(lololo);
						if(!vvchecker(lolol))checker=0;
					}
					if(checker){
						// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
						I sumofdeltas=0;
						I sumofblacks=0;
						for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
						if(sumofdeltas<sumofblacks)checker=0;
						for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
						for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
						if(sumofdeltas>sumofblacks)checker=0;
					}
					if(checker){
						//out<<nl;outv(row0);outv(row1);out<<nl;
						for(I r2:bvv[r1]){
							for(V row2:rows[2][r2]){
								checker=1;
								for(a=1;checker and a<10;a++){
									if(row1[a]==10){
										// Black Square Checker
										// Can Check Sum Of Deltas Is >= Force
										if((row1[a-1]-lowers[positions[1][a-1]])+(row1[a+1]-lowers[positions[1][a+1]])+(row2[a]-lowers[positions[2][a]])+(row0[a]-lowers[positions[0][a]])<lowers[positions[1][a]])checker=0;
									}
									else{
										// White Square Checker
										// Can Check Delta Is <= Force
										I force=0;
										if(row1[a-1]==10)force+=lowers[positions[1][a-1]];
										if(row1[a+1]==10)force+=lowers[positions[1][a+1]];
										if(row2[a]==10)force+=lowers[positions[2][a]];
										if(row0[a]==10)force+=lowers[positions[0][a]];
										if(row1[a]-lowers[positions[1][a]]>force)checker=0;
									}
								}
								if(row1[0]==10){
									// Black Square Checker
									// Can Check Sum Of Deltas Is >= Force
									if((row1[1]-lowers[positions[1][1]])+(row2[0]-lowers[positions[2][0]])+(row0[0]-lowers[positions[0][0]])<lowers[positions[1][0]])checker=0;
								}
								else{
									// White Square Checker
									// Can Check Delta Is <= Force
									I force=0;
									if(row1[1]==10)force+=lowers[positions[1][1]];
									if(row2[0]==10)force+=lowers[positions[2][0]];
									if(row0[0]==10)force+=lowers[positions[0][0]];
									if(row1[0]-lowers[positions[1][0]]>force)checker=0;
								}
								if(row1[10]==10){
									// Black Square Checker
									// Can Check Sum Of Deltas Is >= Force
									if((row1[10-1]-lowers[positions[1][10-1]])+(row2[10]-lowers[positions[2][10]])+(row0[10]-lowers[positions[0][10]])<lowers[positions[1][10]])checker=0;
								}
								else{
									// White Square Checker
									// Can Check Delta Is <= Force
									I force=0;
									if(row1[10-1]==10)force+=lowers[positions[1][10-1]];
									if(row2[10]==10)force+=lowers[positions[2][10]];
									if(row0[10]==10)force+=lowers[positions[0][10]];
									if(row1[10]-lowers[positions[1][10]]>force)checker=0;
								}
								VV lolol;VV lolo;
								lolo=rowtovv(row0);
								for(V lololo:lolo)lolol.add(lololo);
								lolo=rowtovv(row1);
								for(V lololo:lolo)lolol.add(lololo);
								lolo=rowtovv(row2);
								for(V lololo:lolo)lolol.add(lololo);
								if(!vvchecker(lolol))checker=0;
								if(checker){
									// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
									I sumofdeltas=0;
									I sumofblacks=0;
									for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
									for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
									for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
									if(sumofdeltas<sumofblacks)checker=0;
									for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
									for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
									if(sumofdeltas>sumofblacks)checker=0;
								}
								if(checker and row0[7]==10 and row1[6]==10 and row0[6]==5 and row1[7]==5 and row0[5]!=10 and row1[8]!=10 and row2[7]!=10)checker=0;
								if(checker and row0[0]==10 and row0[1]+row1[0]>=7 and row0[2]!=10 and row1[1]!=10 and row2[0]!=10)checker=0;
								if(checker and row0[0]==10 and row2[0]==10 and lowers[positions[0][0]]+lowers[positions[2][0]]<(row0[1]-lowers[positions[0][1]])+(row1[0]-lowers[positions[1][0]])+(row2[1]-lowers[positions[2][1]]))checker=0;
								if(checker and row1[2]==10 and row0[3]!=10 and (row0[2]-lowers[positions[0][2]])+(row1[1]-lowers[positions[1][1]])>lowers[positions[1][2]])checker=0;
								if(checker){
									//out<<nl;outv(row0);outv(row1);outv(row2);out<<nl;x++;
									for(I r3:bvv[r2]){
										for(V row3:rows[3][r3]){
											checker=1;
											for(a=1;checker and a<10;a++){
												if(row2[a]==10){
													// Black Square Checker
													// Can Check Sum Of Deltas Is >= Force
													if((row2[a-1]-lowers[positions[2][a-1]])+(row2[a+1]-lowers[positions[2][a+1]])+(row3[a]-lowers[positions[3][a]])+(row1[a]-lowers[positions[1][a]])<lowers[positions[2][a]])checker=0;
												}
												else{
													// White Square Checker
													// Can Check Delta Is <= Force
													I force=0;
													if(row2[a-1]==10)force+=lowers[positions[2][a-1]];
													if(row2[a+1]==10)force+=lowers[positions[2][a+1]];
													if(row3[a]==10)force+=lowers[positions[3][a]];
													if(row1[a]==10)force+=lowers[positions[1][a]];
													if(row2[a]-lowers[positions[2][a]]>force)checker=0;
												}
											}
											if(checker and row2[0]==10){
												// Black Square Checker
												// Can Check Sum Of Deltas Is >= Force
												if((row2[1]-lowers[positions[2][1]])+(row3[0]-lowers[positions[3][0]])+(row1[0]-lowers[positions[1][0]])<lowers[positions[2][0]])checker=0;
											}
											else if(checker){
												// White Square Checker
												// Can Check Delta Is <= Force
												I force=0;
												if(row2[1]==10)force+=lowers[positions[2][1]];
												if(row3[0]==10)force+=lowers[positions[3][0]];
												if(row1[0]==10)force+=lowers[positions[1][0]];
												if(row2[0]-lowers[positions[2][0]]>force)checker=0;
											}
											if(checker and row2[10]==10){
												// Black Square Checker
												// Can Check Sum Of Deltas Is >= Force
												if((row2[10-1]-lowers[positions[2][10-1]])+(row3[10]-lowers[positions[3][10]])+(row1[10]-lowers[positions[1][10]])<lowers[positions[2][10]])checker=0;
											}
											else if(checker){
												// White Square Checker
												// Can Check Delta Is <= Force
												I force=0;
												if(row2[10-1]==10)force+=lowers[positions[2][10-1]];
												if(row3[10]==10)force+=lowers[positions[3][10]];
												if(row1[10]==10)force+=lowers[positions[1][10]];
												if(row2[10]-lowers[positions[2][10]]>force)checker=0;
											}
											if(checker){
												VV lolol;VV lolo;
												lolo=rowtovv(row0);
												for(V lololo:lolo)lolol.add(lololo);
												lolo=rowtovv(row1);
												for(V lololo:lolo)lolol.add(lololo);
												lolo=rowtovv(row2);
												for(V lololo:lolo)lolol.add(lololo);
												lolo=rowtovv(row3);
												for(V lololo:lolo)lolol.add(lololo);
												if(!vvchecker(lolol))checker=0;
											}
											if(checker){
												// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
												I sumofdeltas=0;
												I sumofblacks=0;
												for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
												for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
												for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
												for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
												for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
												if(sumofdeltas<sumofblacks)checker=0;
												for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
												for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
												if(sumofdeltas>sumofblacks)checker=0;
											}
											if(checker and row2[8]==10 and row0[8]!=10 and row1[7]!=10 and row2[6]!=10 and row3[7]!=10 and (row1[8]-lowers[positions[1][8]])+(row2[7]-lowers[positions[2][7]])>lowers[positions[2][8]])checker=0;
											if(checker and row1[10]==10 and row3[10]!=10 and (row0[10]-lowers[positions[0][10]])+(row2[10]-lowers[positions[2][10]])>lowers[positions[1][10]])checker=0;
											if(row1[2]==10 and row0[3]!=10 and row3[2]!=10 and row2[3]!=10 and (row0[2]-lowers[positions[0][2]])+(row2[2]-lowers[positions[2][2]])>lowers[positions[1][2]])checker=0;
											if(row0[7]==10 and row1[6]==10 and row2[5]==10 and row3[6]!=10 and (row0[8]-lowers[positions[0][8]])+(row0[6]-lowers[positions[0][6]])+(row1[5]-lowers[positions[1][5]])+(row2[6]-lowers[positions[2][6]])>lowers[positions[0][7]]+lowers[positions[1][6]]+lowers[positions[2][5]])checker=0;
											if(checker){
												//out<<nl;outv(row0);outv(row1);outv(row2);outv(row3);out<<nl;x++;
												x++;//if(x%1==0)out<<x<<" "<<r0<<nl;
												
												for(I r4:bvv[r3]){
													for(V row4:rows[4][r4]){
														// OK
														checker=1;
														for(a=1;checker and a<10;a++){
															if(row3[a]==10){
																// Black Square Checker
																// Can Check Sum Of Deltas Is >= Force
																if((row3[a-1]-lowers[positions[3][a-1]])+(row3[a+1]-lowers[positions[3][a+1]])+(row4[a]-lowers[positions[4][a]])+(row2[a]-lowers[positions[2][a]])<lowers[positions[3][a]])checker=0;
															}
															else{
																// White Square Checker
																// Can Check Delta Is <= Force
																I force=0;
																if(row3[a-1]==10)force+=lowers[positions[3][a-1]];
																if(row3[a+1]==10)force+=lowers[positions[3][a+1]];
																if(row4[a]==10)force+=lowers[positions[4][a]];
																if(row2[a]==10)force+=lowers[positions[2][a]];
																if(row3[a]-lowers[positions[3][a]]>force)checker=0;
															}
														}
														if(checker and row3[0]==10){
															// Black Square Checker
															// Can Check Sum Of Deltas Is >= Force
															if((row3[1]-lowers[positions[3][1]])+(row4[0]-lowers[positions[4][0]])+(row2[0]-lowers[positions[2][0]])<lowers[positions[3][0]])checker=0;
														}
														else if(checker){
															// White Square Checker
															// Can Check Delta Is <= Force
															I force=0;
															if(row3[1]==10)force+=lowers[positions[3][1]];
															if(row4[0]==10)force+=lowers[positions[4][0]];
															if(row2[0]==10)force+=lowers[positions[2][0]];
															if(row3[0]-lowers[positions[3][0]]>force)checker=0;
														}
														if(checker and row3[10]==10){
															// Black Square Checker
															// Can Check Sum Of Deltas Is >= Force
															if((row3[10-1]-lowers[positions[3][10-1]])+(row4[10]-lowers[positions[4][10]])+(row2[10]-lowers[positions[2][10]])<lowers[positions[3][10]])checker=0;
														}
														else if(checker){
															// White Square Checker
															// Can Check Delta Is <= Force
															I force=0;
															if(row3[10-1]==10)force+=lowers[positions[3][10-1]];
															if(row4[10]==10)force+=lowers[positions[4][10]];
															if(row2[10]==10)force+=lowers[positions[2][10]];
															if(row3[10]-lowers[positions[3][10]]>force)checker=0;
														}
														if(checker){
															VV lolol;VV lolo;
															lolo=rowtovv(row0);
															for(V lololo:lolo)lolol.add(lololo);
															lolo=rowtovv(row1);
															for(V lololo:lolo)lolol.add(lololo);
															lolo=rowtovv(row2);
															for(V lololo:lolo)lolol.add(lololo);
															lolo=rowtovv(row3);
															for(V lololo:lolo)lolol.add(lololo);
															lolo=rowtovv(row4);
															for(V lololo:lolo)lolol.add(lololo);
															if(!vvchecker(lolol))checker=0;
														}
														if(checker){
															// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
															I sumofdeltas=0;
															I sumofblacks=0;
															for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
															for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
															for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];

															for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
															for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
															for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
															for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
															if(sumofdeltas<sumofblacks)checker=0;
															
															for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
															for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
															if(sumofdeltas>sumofblacks)checker=0;
														}
														if(checker){
															if(y!=x){
																y=x;
																out<<nl<<x<<nl;outv(row0);outv(row1);outv(row2);outv(row3);out<<nl;
															}
															for(I r5:bvv[r4]){
																for(V row5:rows[5][r5]){
																	// MOSTRECENT
																	checker=1;
																	for(a=1;checker and a<10;a++){
																		if(row4[a]==10){
																			// Black Square Checker
																			// Can Check Sum Of Deltas Is >= Force
																			if((row4[a-1]-lowers[positions[4][a-1]])+(row4[a+1]-lowers[positions[4][a+1]])+(row5[a]-lowers[positions[5][a]])+(row3[a]-lowers[positions[3][a]])<lowers[positions[4][a]])checker=0;
																		}
																		else{
																			// White Square Checker
																			// Can Check Delta Is <= Force
																			I force=0;
																			if(row4[a-1]==10)force+=lowers[positions[4][a-1]];
																			if(row4[a+1]==10)force+=lowers[positions[4][a+1]];
																			if(row5[a]==10)force+=lowers[positions[5][a]];
																			if(row3[a]==10)force+=lowers[positions[3][a]];
																			if(row4[a]-lowers[positions[4][a]]>force)checker=0;
																		}
																	}
																	if(checker and row4[0]==10){
																		// Black Square Checker
																		// Can Check Sum Of Deltas Is >= Force
																		if((row4[1]-lowers[positions[4][1]])+(row5[0]-lowers[positions[5][0]])+(row3[0]-lowers[positions[3][0]])<lowers[positions[4][0]])checker=0;
																	}
																	else if(checker){
																		// White Square Checker
																		// Can Check Delta Is <= Force
																		I force=0;
																		if(row4[1]==10)force+=lowers[positions[4][1]];
																		if(row5[0]==10)force+=lowers[positions[5][0]];
																		if(row3[0]==10)force+=lowers[positions[3][0]];
																		if(row4[0]-lowers[positions[4][0]]>force)checker=0;
																	}
																	if(checker and row4[10]==10){
																		// Black Square Checker
																		// Can Check Sum Of Deltas Is >= Force
																		if((row4[10-1]-lowers[positions[4][10-1]])+(row5[10]-lowers[positions[5][10]])+(row3[10]-lowers[positions[3][10]])<lowers[positions[4][10]])checker=0;
																	}
																	else if(checker){
																		// White Square Checker
																		// Can Check Delta Is <= Force
																		I force=0;
																		if(row4[10-1]==10)force+=lowers[positions[4][10-1]];
																		if(row5[10]==10)force+=lowers[positions[5][10]];
																		if(row3[10]==10)force+=lowers[positions[3][10]];
																		if(row4[10]-lowers[positions[4][10]]>force)checker=0;
																	}
																	if(checker){
																		VV lolol;VV lolo;
																		lolo=rowtovv(row0);
																		for(V lololo:lolo)lolol.add(lololo);
																		lolo=rowtovv(row1);
																		for(V lololo:lolo)lolol.add(lololo);
																		lolo=rowtovv(row2);
																		for(V lololo:lolo)lolol.add(lololo);
																		lolo=rowtovv(row3);
																		for(V lololo:lolo)lolol.add(lololo);
																		lolo=rowtovv(row4);
																		for(V lololo:lolo)lolol.add(lololo);
																		lolo=rowtovv(row5);
																		for(V lololo:lolo)lolol.add(lololo);
																		if(!vvchecker(lolol))checker=0;
																	}
																	if(checker){
																		// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
																		I sumofdeltas=0;
																		I sumofblacks=0;
																		for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																		for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																		for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																		for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];

																		for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																		for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																		for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																		for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																		for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																		if(sumofdeltas<sumofblacks)checker=0;
																		
																		for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
																		for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
																		if(sumofdeltas>sumofblacks)checker=0;
																	}
																	if(checker){
																		//w++;if(w%100==0)out<<"w "<<w<<nl;
																		for(I r6:bvv[r5]){
																			for(V row6:rows[6][r6]){
																				// BLAHBLAHBLAH
																				checker=1;
																				for(a=1;checker and a<10;a++){
																					if(row5[a]==10){
																						// Black Square Checker
																						// Can Check Sum Of Deltas Is >= Force
																						if((row5[a-1]-lowers[positions[5][a-1]])+(row5[a+1]-lowers[positions[5][a+1]])+(row6[a]-lowers[positions[6][a]])+(row4[a]-lowers[positions[4][a]])<lowers[positions[5][a]])checker=0;
																					}
																					else{
																						// White Square Checker
																						// Can Check Delta Is <= Force
																						I force=0;
																						if(row5[a-1]==10)force+=lowers[positions[5][a-1]];
																						if(row5[a+1]==10)force+=lowers[positions[5][a+1]];
																						if(row6[a]==10)force+=lowers[positions[6][a]];
																						if(row4[a]==10)force+=lowers[positions[4][a]];
																						if(row5[a]-lowers[positions[5][a]]>force)checker=0;
																					}
																				}
																				if(checker and row5[0]==10){
																					// Black Square Checker
																					// Can Check Sum Of Deltas Is >= Force
																					if((row5[1]-lowers[positions[5][1]])+(row6[0]-lowers[positions[6][0]])+(row4[0]-lowers[positions[4][0]])<lowers[positions[5][0]])checker=0;
																				}
																				else if(checker){
																					// White Square Checker
																					// Can Check Delta Is <= Force
																					I force=0;
																					if(row5[1]==10)force+=lowers[positions[5][1]];
																					if(row6[0]==10)force+=lowers[positions[6][0]];
																					if(row4[0]==10)force+=lowers[positions[4][0]];
																					if(row5[0]-lowers[positions[5][0]]>force)checker=0;
																				}
																				if(checker and row5[10]==10){
																					// Black Square Checker
																					// Can Check Sum Of Deltas Is >= Force
																					if((row5[10-1]-lowers[positions[5][10-1]])+(row6[10]-lowers[positions[6][10]])+(row4[10]-lowers[positions[4][10]])<lowers[positions[5][10]])checker=0;
																				}
																				else if(checker){
																					// White Square Checker
																					// Can Check Delta Is <= Force
																					I force=0;
																					if(row5[10-1]==10)force+=lowers[positions[5][10-1]];
																					if(row6[10]==10)force+=lowers[positions[6][10]];
																					if(row4[10]==10)force+=lowers[positions[4][10]];
																					if(row5[10]-lowers[positions[5][10]]>force)checker=0;
																				}
																				if(checker){
																					VV lolol;VV lolo;
																					lolo=rowtovv(row0);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row1);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row2);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row3);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row4);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row5);
																					for(V lololo:lolo)lolol.add(lololo);
																					lolo=rowtovv(row6);
																					for(V lololo:lolo)lolol.add(lololo);
																					if(!vvchecker(lolol))checker=0;
																				}
																				if(checker){
																					// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
																					I sumofdeltas=0;
																					I sumofblacks=0;
																					for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																					for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																					for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																					for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
																					for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
			
																					for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																					for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																					for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																					for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																					for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																					for(a=0;a<11;a++)if(row5[a]!=10)sumofdeltas+=row5[a]-lowers[positions[5][a]];
																					if(sumofdeltas<sumofblacks)checker=0;
																					
																					for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
																					for(a=0;a<11;a++)if(row6[a]==10)sumofblacks+=lowers[positions[6][a]];
																					if(sumofdeltas>sumofblacks)checker=0;
																				}
																				if(checker){
																					//w++;if(w%100==0)out<<w<<nl;
																					//outv(row0);outv(row1);outv(row2);outv(row3);outv(row4);outv(row5);outv(row6);out<<nl;
																					for(I r7:bvv[r6]){
																						for(V row7:rows[7][r7]){
																							// BLAHBLAH
																							checker=1;
																							for(a=1;checker and a<10;a++){
																								if(row6[a]==10){
																									// Black Square Checker
																									// Can Check Sum Of Deltas Is >= Force
																									if((row6[a-1]-lowers[positions[6][a-1]])+(row6[a+1]-lowers[positions[6][a+1]])+(row7[a]-lowers[positions[7][a]])+(row5[a]-lowers[positions[5][a]])<lowers[positions[6][a]])checker=0;
																								}
																								else{
																									// White Square Checker
																									// Can Check Delta Is <= Force
																									I force=0;
																									if(row6[a-1]==10)force+=lowers[positions[6][a-1]];
																									if(row6[a+1]==10)force+=lowers[positions[6][a+1]];
																									if(row7[a]==10)force+=lowers[positions[7][a]];
																									if(row5[a]==10)force+=lowers[positions[5][a]];
																									if(row6[a]-lowers[positions[6][a]]>force)checker=0;
																								}
																							}
																							if(checker and row6[0]==10){
																								// Black Square Checker
																								// Can Check Sum Of Deltas Is >= Force
																								if((row6[1]-lowers[positions[6][1]])+(row7[0]-lowers[positions[7][0]])+(row5[0]-lowers[positions[5][0]])<lowers[positions[6][0]])checker=0;
																							}
																							else if(checker){
																								// White Square Checker
																								// Can Check Delta Is <= Force
																								I force=0;
																								if(row6[1]==10)force+=lowers[positions[6][1]];
																								if(row7[0]==10)force+=lowers[positions[7][0]];
																								if(row5[0]==10)force+=lowers[positions[5][0]];
																								if(row6[0]-lowers[positions[6][0]]>force)checker=0;
																							}
																							if(checker and row6[10]==10){
																								// Black Square Checker
																								// Can Check Sum Of Deltas Is >= Force
																								if((row6[10-1]-lowers[positions[6][10-1]])+(row7[10]-lowers[positions[7][10]])+(row5[10]-lowers[positions[5][10]])<lowers[positions[6][10]])checker=0;
																							}
																							else if(checker){
																								// White Square Checker
																								// Can Check Delta Is <= Force
																								I force=0;
																								if(row6[10-1]==10)force+=lowers[positions[6][10-1]];
																								if(row7[10]==10)force+=lowers[positions[7][10]];
																								if(row5[10]==10)force+=lowers[positions[5][10]];
																								if(row6[10]-lowers[positions[6][10]]>force)checker=0;
																							}
																							if(checker){
																								VV lolol;VV lolo;
																								lolo=rowtovv(row0);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row1);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row2);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row3);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row4);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row5);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row6);
																								for(V lololo:lolo)lolol.add(lololo);
																								lolo=rowtovv(row7);
																								for(V lololo:lolo)lolol.add(lololo);
																								if(!vvchecker(lolol))checker=0;
																							}
																							if(checker){
																								// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
																								I sumofdeltas=0;
																								I sumofblacks=0;
																								for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																								for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																								for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																								for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
																								for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
																								for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
						
																								for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																								for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																								for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																								for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																								for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																								for(a=0;a<11;a++)if(row5[a]!=10)sumofdeltas+=row5[a]-lowers[positions[5][a]];
																								for(a=0;a<11;a++)if(row6[a]!=10)sumofdeltas+=row6[a]-lowers[positions[6][a]];
																								if(sumofdeltas<sumofblacks)checker=0;
																								
																								for(a=0;a<11;a++)if(row6[a]==10)sumofblacks+=lowers[positions[6][a]];
																								for(a=0;a<11;a++)if(row7[a]==10)sumofblacks+=lowers[positions[7][a]];
																								if(sumofdeltas>sumofblacks)checker=0;
																							}
																							if(row7[8]!=9)checker=0; // Test If This Intuition Brings The Answer
																							if(checker){
																								for(I r8:bvv[r7]){
																									for(V row8:rows[8][r8]){
																										// BBBBLLLLAAAAHHHH
																										checker=1;
																										for(a=1;checker and a<10;a++){
																											if(row7[a]==10){
																												// Black Square Checker
																												// Can Check Sum Of Deltas Is >= Force
																												if((row7[a-1]-lowers[positions[7][a-1]])+(row7[a+1]-lowers[positions[7][a+1]])+(row8[a]-lowers[positions[8][a]])+(row6[a]-lowers[positions[6][a]])<lowers[positions[7][a]])checker=0;
																											}
																											else{
																												// White Square Checker
																												// Can Check Delta Is <= Force
																												I force=0;
																												if(row7[a-1]==10)force+=lowers[positions[7][a-1]];
																												if(row7[a+1]==10)force+=lowers[positions[7][a+1]];
																												if(row8[a]==10)force+=lowers[positions[8][a]];
																												if(row6[a]==10)force+=lowers[positions[6][a]];
																												if(row7[a]-lowers[positions[7][a]]>force)checker=0;
																											}
																										}
																										if(checker and row7[0]==10){
																											// Black Square Checker
																											// Can Check Sum Of Deltas Is >= Force
																											if((row7[1]-lowers[positions[7][1]])+(row8[0]-lowers[positions[8][0]])+(row6[0]-lowers[positions[6][0]])<lowers[positions[7][0]])checker=0;
																										}
																										else if(checker){
																											// White Square Checker
																											// Can Check Delta Is <= Force
																											I force=0;
																											if(row7[1]==10)force+=lowers[positions[7][1]];
																											if(row8[0]==10)force+=lowers[positions[8][0]];
																											if(row6[0]==10)force+=lowers[positions[6][0]];
																											if(row7[0]-lowers[positions[7][0]]>force)checker=0;
																										}
																										if(checker and row7[10]==10){
																											// Black Square Checker
																											// Can Check Sum Of Deltas Is >= Force
																											if((row7[10-1]-lowers[positions[7][10-1]])+(row8[10]-lowers[positions[8][10]])+(row6[10]-lowers[positions[6][10]])<lowers[positions[7][10]])checker=0;
																										}
																										else if(checker){
																											// White Square Checker
																											// Can Check Delta Is <= Force
																											I force=0;
																											if(row7[10-1]==10)force+=lowers[positions[7][10-1]];
																											if(row8[10]==10)force+=lowers[positions[8][10]];
																											if(row6[10]==10)force+=lowers[positions[6][10]];
																											if(row7[10]-lowers[positions[7][10]]>force)checker=0;
																										}
																										if(checker){
																											VV lolol;VV lolo;
																											lolo=rowtovv(row0);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row1);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row2);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row3);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row4);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row5);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row6);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row7);
																											for(V lololo:lolo)lolol.add(lololo);
																											lolo=rowtovv(row8);
																											for(V lololo:lolo)lolol.add(lololo);
																											if(!vvchecker(lolol))checker=0;
																										}
																										if(checker){
																											// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
																											I sumofdeltas=0;
																											I sumofblacks=0;
																											for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																											for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																											for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																											for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
																											for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
																											for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
																											for(a=0;a<11;a++)if(row6[a]==10)sumofblacks+=lowers[positions[6][a]];
									
																											for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																											for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																											for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																											for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																											for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																											for(a=0;a<11;a++)if(row5[a]!=10)sumofdeltas+=row5[a]-lowers[positions[5][a]];
																											for(a=0;a<11;a++)if(row6[a]!=10)sumofdeltas+=row6[a]-lowers[positions[6][a]];
																											for(a=0;a<11;a++)if(row7[a]!=10)sumofdeltas+=row7[a]-lowers[positions[7][a]];
																											if(sumofdeltas<sumofblacks)checker=0;
																											
																											for(a=0;a<11;a++)if(row7[a]==10)sumofblacks+=lowers[positions[7][a]];
																											for(a=0;a<11;a++)if(row8[a]==10)sumofblacks+=lowers[positions[8][a]];
																											if(sumofdeltas>sumofblacks)checker=0;
																										}
																										if(checker){
																											// Final Round Maybe
																											//out<<nl;outv(row0);outv(row1);outv(row2);outv(row3);outv(row4);outv(row5);outv(row6);outv(row7);outv(row8);out<<nl;
																											//w++;if(w%100==0)out<<w<<nl;
																											I sumofdeltas=0;
																											I sumofblacks=0;
																											for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																											for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																											for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																											for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
																											for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
																											for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
																											for(a=0;a<11;a++)if(row6[a]==10)sumofblacks+=lowers[positions[6][a]];
																											for(a=0;a<11;a++)if(row7[a]==10)sumofblacks+=lowers[positions[7][a]];
																											for(a=0;a<11;a++)if(row8[a]==10)sumofblacks+=lowers[positions[8][a]];
									
																											for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																											for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																											for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																											for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																											for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																											for(a=0;a<11;a++)if(row5[a]!=10)sumofdeltas+=row5[a]-lowers[positions[5][a]];
																											for(a=0;a<11;a++)if(row6[a]!=10)sumofdeltas+=row6[a]-lowers[positions[6][a]];
																											for(a=0;a<11;a++)if(row7[a]!=10)sumofdeltas+=row7[a]-lowers[positions[7][a]];
																											for(a=0;a<11;a++)if(row8[a]!=10)sumofdeltas+=row8[a]-lowers[positions[8][a]];
																											if(sumofdeltas==sumofblacks-4){
																												out<<w<<nl;w++;
																												//outv(row0);outv(row1);outv(row2);outv(row3);outv(row4);outv(row5);outv(row6);outv(row7);outv(row8);out<<nl;
																												//w++;if(w%100==0)out<<w<<nl;
																												targett[0]=row0;
																												targett[1]=row1;
																												targett[2]=row2;
																												targett[3]=row3;
																												targett[4]=row4;
																												targett[5]=row5;
																												targett[6]=row6;
																												targett[7]=row7;
																												targett[8]=row8;
																												VVB cansend(9,VB(11,0));
																												for(e=0;e<9;e++){
																													for(f=0;f<11;f++){
																														if(targett[e][f]==10){
																															targett[e][f]=0;
																															cansend[e][f]=1;
																														}
																													}
																												}
																												if(isPossibleFlowBased(before,targett,cansend)){
																													out<<nl;outv(row0);outv(row1);outv(row2);outv(row3);outv(row4);outv(row5);outv(row6);outv(row7);outv(row8);out<<nl;
																												}
																											}
																											/*
																											for(I r9:bvv[r8]){
																												for(V row9:rows[9][r9]){
																													// BBBBLLLLAAAAHHHH
																													checker=1;
																													for(a=1;checker and a<10;a++){
																														if(row8[a]==10){
																															// Black Square Checker
																															// Can Check Sum Of Deltas Is >= Force
																															if((row8[a-1]-lowers[positions[8][a-1]])+(row8[a+1]-lowers[positions[8][a+1]])+(row9[a]-lowers[positions[9][a]])+(row7[a]-lowers[positions[7][a]])<lowers[positions[8][a]])checker=0;
																														}
																														else{
																															// White Square Checker
																															// Can Check Delta Is <= Force
																															I force=0;
																															if(row8[a-1]==10)force+=lowers[positions[8][a-1]];
																															if(row8[a+1]==10)force+=lowers[positions[8][a+1]];
																															if(row9[a]==10)force+=lowers[positions[9][a]];
																															if(row7[a]==10)force+=lowers[positions[7][a]];
																															if(row8[a]-lowers[positions[8][a]]>force)checker=0;
																														}
																													}
																													if(checker and row8[0]==10){
																														// Black Square Checker
																														// Can Check Sum Of Deltas Is >= Force
																														if((row8[1]-lowers[positions[8][1]])+(row9[0]-lowers[positions[9][0]])+(row7[0]-lowers[positions[7][0]])<lowers[positions[8][0]])checker=0;
																													}
																													else if(checker){
																														// White Square Checker
																														// Can Check Delta Is <= Force
																														I force=0;
																														if(row8[1]==10)force+=lowers[positions[8][1]];
																														if(row9[0]==10)force+=lowers[positions[9][0]];
																														if(row7[0]==10)force+=lowers[positions[7][0]];
																														if(row8[0]-lowers[positions[8][0]]>force)checker=0;
																													}
																													if(checker and row8[10]==10){
																														// Black Square Checker
																														// Can Check Sum Of Deltas Is >= Force
																														if((row8[10-1]-lowers[positions[8][10-1]])+(row9[10]-lowers[positions[9][10]])+(row7[10]-lowers[positions[7][10]])<lowers[positions[8][10]])checker=0;
																													}
																													else if(checker){
																														// White Square Checker
																														// Can Check Delta Is <= Force
																														I force=0;
																														if(row8[10-1]==10)force+=lowers[positions[8][10-1]];
																														if(row9[10]==10)force+=lowers[positions[9][10]];
																														if(row7[10]==10)force+=lowers[positions[7][10]];
																														if(row8[10]-lowers[positions[8][10]]>force)checker=0;
																													}
																													if(checker){
																														VV lolol;VV lolo;
																														lolo=rowtovv(row0);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row1);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row2);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row3);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row4);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row5);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row6);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row7);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row8);
																														for(V lololo:lolo)lolol.add(lololo);
																														lolo=rowtovv(row9);
																														for(V lololo:lolo)lolol.add(lololo);
																														if(!vvchecker(lolol))checker=0;
																													}
																													if(checker){
																														// Now Add In A Check That Sum Of Deltas In First 1 Rows Is <= Sum Of Blacks In First 2 Rows And >= Sum Of Blacks In First 0 Rows ...
																														I sumofdeltas=0;
																														I sumofblacks=0;
																														for(a=0;a<11;a++)if(row0[a]==10)sumofblacks+=lowers[positions[0][a]];
																														for(a=0;a<11;a++)if(row1[a]==10)sumofblacks+=lowers[positions[1][a]];
																														for(a=0;a<11;a++)if(row2[a]==10)sumofblacks+=lowers[positions[2][a]];
																														for(a=0;a<11;a++)if(row3[a]==10)sumofblacks+=lowers[positions[3][a]];
																														for(a=0;a<11;a++)if(row4[a]==10)sumofblacks+=lowers[positions[4][a]];
																														for(a=0;a<11;a++)if(row5[a]==10)sumofblacks+=lowers[positions[5][a]];
																														for(a=0;a<11;a++)if(row6[a]==10)sumofblacks+=lowers[positions[6][a]];
																														for(a=0;a<11;a++)if(row7[a]==10)sumofblacks+=lowers[positions[7][a]];
												
																														for(a=0;a<11;a++)if(row0[a]!=10)sumofdeltas+=row0[a]-lowers[positions[0][a]];
																														for(a=0;a<11;a++)if(row1[a]!=10)sumofdeltas+=row1[a]-lowers[positions[1][a]];
																														for(a=0;a<11;a++)if(row2[a]!=10)sumofdeltas+=row2[a]-lowers[positions[2][a]];
																														for(a=0;a<11;a++)if(row3[a]!=10)sumofdeltas+=row3[a]-lowers[positions[3][a]];
																														for(a=0;a<11;a++)if(row4[a]!=10)sumofdeltas+=row4[a]-lowers[positions[4][a]];
																														for(a=0;a<11;a++)if(row5[a]!=10)sumofdeltas+=row5[a]-lowers[positions[5][a]];
																														for(a=0;a<11;a++)if(row6[a]!=10)sumofdeltas+=row6[a]-lowers[positions[6][a]];
																														for(a=0;a<11;a++)if(row7[a]!=10)sumofdeltas+=row7[a]-lowers[positions[7][a]];
																														for(a=0;a<11;a++)if(row8[a]!=10)sumofdeltas+=row8[a]-lowers[positions[7][a]];
																														if(sumofdeltas<sumofblacks)checker=0;
																														
																														for(a=0;a<11;a++)if(row8[a]==10)sumofblacks+=lowers[positions[8][a]];
																														for(a=0;a<11;a++)if(row9[a]==10)sumofblacks+=lowers[positions[9][a]];
																														if(sumofdeltas>sumofblacks)checker=0;
																													}
																													if(checker){
																														w++;if(w%100==0)out<<w<<nl;
																													}
																												}}
																												*/
																										}
																									}}
																							}
																						}}
																				}
																			}}
																	}
														}
													}
												}}}
												
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
	out<<x<<nl;
	/*
	lols=VVV(12,VV(0,V(0)));
	al=1;
	bl=1;
	while(bl<(long long)100000000000){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0 or cl==55){ // Can Remove Later If Needed
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
		cl=al+bl;
		al=bl;
		bl=cl;
	}
	lols[1]=VV(0,V(0));
	lols[1].add({0});
	VV row2s;
	for(V shape:compositions){
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row2s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row2s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row2s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row2s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row2s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row2s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									for(V part6:lols[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row2s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//outvv(row2s);
	lols=VVV(12,VV(0,V(0)));
	lols[1].add({0});
	I maximum=100000000; // SSRS_
	V spf(maximum+1,-1);
	V primes;
	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}
	spf=V(0); // Save Memory
	for(auto dude:primes){
		av=V(0);
		cl=dude;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)lols[sz(av)].add(av);
	}
	lols[1]=VV(0,V(0));
	lols[1].add({0});
	VV row0s;
	for(V shape:compositions){if(sz(shape)==4){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row0s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row0s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row0s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row0s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row0s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row0s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									for(V part6:lols[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row0s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}}
	lols=VVV(12,VV(0,V(0)));
	lols[1].add({0});
	avv={{3,3,3,3,5,5},{3,3,3,5,3,5},{3,3,3,5,5,3},{3,3,5,3,3,5},{3,3,5,3,5,3},{3,3,5,5,3,3},{3,3,5,5,9},{3,3,5,9,5},{3,3,9,5,5},{3,5,3,3,3,5},{3,5,3,3,5,3},{3,5,3,5,3,3},{3,5,3,5,9},{3,5,3,9,5},{3,5,5,3,3,3},{3,5,5,3,9},{3,5,5,9,3},{3,5,9,3,5},{3,5,9,5,3},{3,9,3,5,5},{3,9,5,3,5},{3,9,5,5,3},{5,3,3,3,3,5},{5,3,3,3,5,3},{5,3,3,5,3,3},{5,3,3,5,9},{5,3,3,9,5},{5,3,5,3,3,3},{5,3,5,3,9},{5,3,5,9,3},{5,3,9,3,5},{5,3,9,5,3},{5,5,3,3,3,3},{5,5,3,3,9},{5,5,3,9,3},{5,5,9,3,3},{5,5,9,9},{5,9,3,3,5},{5,9,3,5,3},{5,9,5,3,3},{5,9,5,9},{5,9,9,5},{9,3,3,5,5},{9,3,5,3,5},{9,3,5,5,3},{9,5,3,3,5},{9,5,3,5,3},{9,5,5,3,3},{9,5,5,9},{9,5,9,5},{9,9,5,5}};
	for(V dude:avv)lols[sz(dude)].add(dude);
	lols[1]=VV(0,V(0));
	lols[1].add({0});
	VV row1s;
	for(V shape:compositions){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:lols[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row1s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row1s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row1s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row1s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row1s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row1s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:lols[shape[0]]){
				for(V part1:lols[shape[1]]){
					for(V part2:lols[shape[2]]){
						for(V part3:lols[shape[3]]){
							for(V part4:lols[shape[4]]){
								for(V part5:lols[shape[5]]){
									for(V part6:lols[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row1s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	out<<sz(row2s)<<nl;
	out<<sz(row1s)<<nl;
	out<<sz(row0s)<<nl;
	avv=VV(0,V(0));
	for(V row2:row2s)if(row2[0]!=1 and row2[0]!=2 and row2[1]!=1 and row2[1]!=2 and row2[2]!=1 and row2[2]!=2 and row2[3]!=1 and row2[3]!=2 and row2[4]!=0 and row2[4]!=1 and row2[5]!=0 and row2[7]!=1 and row2[8]!=1 and row2[9]!=1 and row2[10]!=1 and row2[7]!=2 and row2[8]!=2 and row2[9]!=2 and row2[10]!=2 and row2[7]!=3 and row2[8]!=3 and row2[9]!=3 and row2[10]!=3)avv.add(row2);
	row2s=avv;avv=VV(0,V(0));
	avv=VV(0,V(0));
	for(V row1:row1s)if(row1[4]!=0)avv.add(row1);
	row1s=avv;avv=VV(0,V(0));
	avv=VV(0,V(0));
	for(V row0:row0s)if(row0[0]!=1 and row0[0]!=2 and row0[1]!=1 and row0[1]!=2 and row0[8]!=1 and row0[8]!=2 and row0[9]!=1 and row0[9]!=2 and row0[10]!=1 and row0[10]!=2)avv.add(row0);
	row0s=avv;avv=VV(0,V(0));
	out<<sz(row2s)<<nl;
	out<<sz(row1s)<<nl;
	out<<sz(row0s)<<nl;
	y=0;
	for(V row2:row2s){
		out<<y<<nl;y++;z=0;
		for(V row1:row1s){
			if(z%10==0)out<<z<<nl;z++;
			if(row2[5]==row1[4] and (row2[0]>=row2[5] or row2[0]==0) and (row2[1]>=row2[5] or row2[1]==0) and (row2[2]>=row2[5] or row2[2]==0) and (row2[3]>=row2[5] or row2[3]==0)){
				I isvalid=1;
				for(a=0;isvalid and a<11;a++)if(row1[a]==0 and row2[a]==0)isvalid=0;
				if(isvalid){
				//out<<nl;outv(row2);outv(row1);out<<nl;
				for(V row0:row0s){
					if((row0[0]>=row2[5] or row0[0]==0) and (row0[1]>=row2[5] or row0[1]==0) and (row0[8]>=row2[5] or row0[8]==0) and (row0[9]>=row2[5] or row0[9]==0) and (row0[10]>=row2[5] or row0[10]==0)){
						I isvalid=1;
						for(a=0;isvalid and a<11;a++)if(row0[a]==0 and row1[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if(row1[a]==0 and row2[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row0[a-1]!=0) and (a==10 or row0[a+1]!=0) and (row1[a]!=0) and (1) and (row0[a]!=row2[5]) and (a<2 or a>7))isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row1[a-1]!=0) and (a==10 or row1[a+1]!=0) and (row2[a]!=0) and (row0[a]!=0) and (row1[a]!=row2[5]))isvalid=0;
						if(isvalid){
							out<<nl;
							outv(row0);
							outv(row1);
							outv(row2);
							out<<nl;
						}
					}
				}}
			}
		}
	}
	*/
}

I main(){zz();I a=1;while(a--){az();}}

/*
This was my output prior to pinging ChatGPT for a uh Dinic's implementation to see observe what would happen uh...

4188677 or 4189235

342225+324+54+225+252+5343+65+26+736+32+544+555+22+816+55+551+155+3674412+24+737+99+999+34+46368+89+53593+59533+47+877+433

342225+324+54+225+252+5343+65+26+736+32+544+555+55+551+155+3674412+737+99+999+34+46368+89+53593+59533+47+887+433=4188373

342225+324+54+225+252+5343+65+26+736+32+544+555+224+36+55+551+155+3674412+44+737+99+999+34+46368+89+53593+59533+47+877+433=

4188373+(22+816+24)=4189235
4188373+(224+36+44)=4188677

x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

  1                         1 1             
 1                                          

         2               2               2  
                                            
                                            

 2                   3           3          
  1                             1           
 1                                          

             1           2               2  
            3           1 1                 
                                         2  

 2                                          
  2             1 1           4             
                 1                          

         2               1                  
        1 1                             4   
                                            

 1                               4          
                                1 1         
 3                                          

             1                           3  
            1 3         3 3             2   
             1                           2  

                                 3          
        1                       1 1         


x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

1231305
al now 1297
Fibonacci rows 2
3 4 x 4 6 3 6 8 x 8 9 
5 5 x 4 6 3 6 8 x 8 9 
Start

1
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 

0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18

4
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 

19
20
21
22

5
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 6 8 x 5 4 4 x 


6
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


10
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 4 4 8 x 5 4 4 x 


13
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 7 3 6 x 5 4 4 x 


15
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


25
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 

23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38

x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93

x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155

26
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 

156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189

27
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 9 6 x 5 4 4 x 


37
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 


40
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 


42
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


51
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


55
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 

190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206

58
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 

207
208
209
210
211
212
213
214

59
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 6 8 x 5 4 4 x 


60
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


64
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 4 4 8 x 5 4 4 x 


67
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 7 3 6 x 5 4 4 x 


69
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


79
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 

215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305

80
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 

306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325

81
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 9 6 x 5 4 4 x 


91
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 


94
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 


96
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


105
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 

108


Last login: Sat May  3 11:17:55 on ttys001
(base) lazar@Mac ~ % a
(base) lazar@Mac ~ % s
1231305
al now 1297
Fibonacci rows 2
3 4 x 4 6 3 6 8 x 8 9 
5 5 x 4 6 3 6 8 x 8 9 
Start

1
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 

0
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

1
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

2
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

3
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

4
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

5
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

6
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

7
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

8
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

9
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

10
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

11
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

12
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

13
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

14
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

15
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

16
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

17
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

18
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


4
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 

19
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

20
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

21
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

22
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


5
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 6 8 x 5 4 4 x 


6
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


10
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 4 4 8 x 5 4 4 x 


13
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 7 3 6 x 5 4 4 x 


15
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


25
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 

23
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

24
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

25
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 5 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

26
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

27
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

28
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

29
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

30
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

31
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

32
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 6 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

33
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

34
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

35
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

36
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

37
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

38
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

39
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

40
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

41
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

42
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 6 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

43
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

44
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

45
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

46
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

47
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

48
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

49
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

50
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 5 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

51
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

52
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

53
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 4 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

54
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 3 3 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

55
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

56
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

57
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

58
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

59
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

60
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

61
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

62
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

63
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

64
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

65
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

66
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

67
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

68
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

69
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

70
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

71
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 3 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

72
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 5 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

73
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 5 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

74
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

75
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 1 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

76
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

77
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

78
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

79
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

80
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

81
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

82
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

83
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

84
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

85
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

86
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

87
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

88
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

89
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

90
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

91
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

92
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

93
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

94
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

95
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

96
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

97
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

98
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

99
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

100
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

101
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

102
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

103
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

104
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

105
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

106
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

107
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

108
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

109
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

110
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

111
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

112
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

113
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

114
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

115
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

116
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 3 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

117
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

118
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 1 6 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

119
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

120
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

121
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

122
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 3 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

123
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 3 3 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

124
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

125
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

126
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

127
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

128
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

129
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

130
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

131
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

132
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

133
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

134
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

135
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

136
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

137
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

138
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

139
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

140
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

141
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 4 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

142
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 3 3 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

143
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 4 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

144
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

145
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

146
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

147
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

148
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

149
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

150
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

151
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

152
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

153
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

154
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

155
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


26
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 

156
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

157
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

158
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

159
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

160
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

161
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

162
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

163
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

164
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

165
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

166
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

167
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

168
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

169
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

170
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

171
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

172
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

173
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

174
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

175
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

176
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

177
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

178
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

179
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

180
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

181
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

182
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

183
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

184
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

185
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

186
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

187
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

188
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

189
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


27
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 9 6 x 5 4 4 x 


37
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 


40
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 


42
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


51
x 3 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


55
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 

190
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

191
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

192
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

193
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

194
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

195
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

196
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

197
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

198
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

199
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

200
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

201
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

202
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

203
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

204
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

205
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

206
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


58
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 

207
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

208
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

209
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

210
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

211
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

212
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

213
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

214
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


59
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 7 6 8 x 5 4 4 x 


60
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


64
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 4 4 8 x 5 4 4 x 


67
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 7 3 6 x 5 4 4 x 


69
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 4 4 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 


79
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 

215
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

216
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

217
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

218
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

219
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

220
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 5 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

221
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

222
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

223
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

224
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

225
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

226
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

227
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

228
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 5 1 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

229
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

230
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

231
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

232
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

233
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

234
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

235
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

236
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

237
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

238
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

239
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

240
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 2 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

241
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 7 7 7 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

242
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

243
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

244
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

245
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

246
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

247
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

248
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

249
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 7 7 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

250
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 8 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

251
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

252
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

253
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 3 5 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

254
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 3 5 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

255
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

256
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

257
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

258
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 4 4 x 4 8 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

259
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 5 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

260
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

261
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

262
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 6 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

263
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 6 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

264
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

265
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

266
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

267
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

268
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

269
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

270
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

271
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 6 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

272
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 6 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

273
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

274
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

275
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

276
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

277
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

278
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

279
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 1 5 x 4 8 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

280
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

281
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

282
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

283
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 8 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

284
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

285
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 3 5 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

286
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

287
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 4 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

288
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

289
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

290
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

291
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

292
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 2 4 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

293
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

294
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 3 3 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

295
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

296
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 3 6 6 x 4 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

297
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

298
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 2 4 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

299
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

300
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 3 3 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

301
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

302
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 5 5 5 x 4 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

303
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

304
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
x 6 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

305
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 3 2 x 5 4 4 x 
4 3 6 8 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


80
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 

306
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

307
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

308
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

309
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

310
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 3 6 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

311
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 8 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

312
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 1 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 6 6 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

313
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 x 8 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

314
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

315
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

316
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

317
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

318
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 1 5 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

319
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 x 3 6 
5 5 x 5 5 1 x 1 5 5 x 
x 3 6 7 4 4 1 2 x 2 4 
7 3 7 x 9 6 9 x 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

320
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

321
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 6 x 3 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

322
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

323
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 3 6 6 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

324
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 1 2 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 

325
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 6 4 x 5 4 4 x 
x 5 5 5 x 2 1 4 4 1 6 
5 5 x 5 5 1 1 1 1 1 x 
x 3 6 7 4 4 1 2 x 4 4 
7 3 7 x 9 9 x 9 9 9 x 
3 4 x 4 6 3 6 8 x 8 9 


81
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 3 4 3 x 6 5 x 2 6 
7 3 6 x 9 6 x 5 4 4 x 


91
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 4 4 8 x 5 4 4 x 


94
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 7 3 6 x 5 4 4 x 


96
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
6 4 x 8 3 2 x 5 4 4 x 


105
x 4 4 2 2 2 5 x 3 2 4 
5 4 x 2 2 5 x 2 5 2 x 
x 5 7 3 3 x 6 5 x 2 6 
9 6 x 8 3 2 x 5 4 4 x 

108
(base) lazar@Mac ~ % 

*/

/*
	int target = 11;
	std::vector<std::vector<int>> compositions;
	std::vector<int> current;
	generate(target, current, -1, compositions); // -1 means no previous number
	/*
	// Print the results (optional)
	for (const auto& comp : compositions) {
		for (size_t i = 0; i < comp.size(); ++i) {
			if (i > 0) std::cout << " ";
			std::cout << comp[i];
		}
		std::cout << '\n';
	}

	std::cout << "Total compositions: " << compositions.size() << '\n';
	
	VVV fibonaccis(12,VV(0,V(0)));
	al=1;
	bl=1;
	while(bl<(long long)100000000000){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)fibonaccis[sz(av)].add(av);
		cl=al+bl;
		al=bl;
		bl=cl;
	}
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row2s;
	for(V shape:compositions){
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row2s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row2s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row2s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row2s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row2s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row2s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row2s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//outvv(row2s);
	fibonaccis=VVV(12,VV(0,V(0)));
	fibonaccis[1].add({0});
	I maximum=100000000; // SSRS_
	V spf(maximum+1,-1);
	V primes;
	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}
	spf=V(0); // Save Memory
	for(auto dude:primes){
		av=V(0);
		cl=dude;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)fibonaccis[sz(av)].add(av);
	}
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row0s;
	for(V shape:compositions){if(sz(shape)>=4){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row0s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row0s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row0s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row0s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row0s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row0s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row0s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}}
	fibonaccis=VVV(12,VV(0,V(0)));
	fibonaccis[1].add({0});
	avv={{3,3,3,3,5,5},{3,3,3,5,3,5},{3,3,3,5,5,3},{3,3,5,3,3,5},{3,3,5,3,5,3},{3,3,5,5,3,3},{3,3,5,5,9},{3,3,5,9,5},{3,3,9,5,5},{3,5,3,3,3,5},{3,5,3,3,5,3},{3,5,3,5,3,3},{3,5,3,5,9},{3,5,3,9,5},{3,5,5,3,3,3},{3,5,5,3,9},{3,5,5,9,3},{3,5,9,3,5},{3,5,9,5,3},{3,9,3,5,5},{3,9,5,3,5},{3,9,5,5,3},{5,3,3,3,3,5},{5,3,3,3,5,3},{5,3,3,5,3,3},{5,3,3,5,9},{5,3,3,9,5},{5,3,5,3,3,3},{5,3,5,3,9},{5,3,5,9,3},{5,3,9,3,5},{5,3,9,5,3},{5,5,3,3,3,3},{5,5,3,3,9},{5,5,3,9,3},{5,5,9,3,3},{5,5,9,9},{5,9,3,3,5},{5,9,3,5,3},{5,9,5,3,3},{5,9,5,9},{5,9,9,5},{9,3,3,5,5},{9,3,5,3,5},{9,3,5,5,3},{9,5,3,3,5},{9,5,3,5,3},{9,5,5,3,3},{9,5,5,9},{9,5,9,5},{9,9,5,5}};
	for(V dude:avv)fibonaccis[sz(dude)].add(dude);
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row1s;
	for(V shape:compositions){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row1s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row1s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row1s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row1s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row1s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row1s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row1s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	out<<sz(row2s)<<nl;
	out<<sz(row1s)<<nl;
	out<<sz(row0s)<<nl;
	y=0;
	for(V row2:row2s){
		out<<y<<nl;y++;z=0;
		row2={0,3,4,0,2,3,3,0,8,9,0};
		for(V row1:row1s){
			//out<<z<<nl;z++;
			if(row2[4]!=0 and row2[5]!=0 and row2[5]==row1[4] and row2[1]>=row2[5] and row2[2]>=row2[5]){
				out<<nl;
				outv(row1);
				outv(row2);
				out<<nl;
				/*
				for(V row0:row0s){
					if(row0[0]>=row2[5] and row0[1]>=row2[5] and row0[8]>=row2[5] and row0[9]>=row2[5] and row0[10]>=row2[5]){
						I isvalid=1;
						for(a=0;isvalid and a<11;a++)if(row0[a]==0 and row1[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if(row1[a]==0 and row2[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row0[a-1]!=0) and (a==10 or row0[a+1]!=0) and (row1[a]!=0) and (1) and (row0[a]!=row2[5]) and (a<2 or a>7))isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row1[a-1]!=0) and (a==10 or row1[a+1]!=0) and (row2[a]!=0) and (row0[a]!=0) and (row1[a]!=row2[5]))isvalid=0;
						if(isvalid){
							out<<nl;
							outv(row0);
							outv(row1);
							outv(row2);
							out<<nl;
						}
					}
				}
				*/
/*			}
		}
	}
*/

/*
	int target = 11;
	std::vector<std::vector<int>> compositions;
	std::vector<int> current;
	generate(target, current, -1, compositions); // -1 means no previous number
	/*
	// Print the results (optional)
	for (const auto& comp : compositions) {
		for (size_t i = 0; i < comp.size(); ++i) {
			if (i > 0) std::cout << " ";
			std::cout << comp[i];
		}
		std::cout << '\n';
	}

	std::cout << "Total compositions: " << compositions.size() << '\n';
	
	VVV fibonaccis(12,VV(0,V(0)));
	al=1;
	bl=1;
	while(bl<(long long)100000000000){
		av=V(0);
		cl=bl;
		while(cl>0){
			if(cl%10==0 or cl==55){ // Can Remove Later If Needed
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)fibonaccis[sz(av)].add(av);
		cl=al+bl;
		al=bl;
		bl=cl;
	}
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row2s;
	for(V shape:compositions){
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row2s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row2s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row2s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row2s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row2s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row2s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row2s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//outvv(row2s);
	fibonaccis=VVV(12,VV(0,V(0)));
	fibonaccis[1].add({0});
	I maximum=100000000; // SSRS_
	V spf(maximum+1,-1);
	V primes;
	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}
	spf=V(0); // Save Memory
	for(auto dude:primes){
		av=V(0);
		cl=dude;
		while(cl>0){
			if(cl%10==0){
				cl=0;
				av=V(0);
			}
			else{
				av.insert(av.begin(),cl%10);
				cl/=10;
			}
		}
		if(sz(av)>0)fibonaccis[sz(av)].add(av);
	}
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row0s;
	for(V shape:compositions){if(sz(shape)>=5){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row0s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row0s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row0s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row0s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row0s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row0s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row0s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}}
	fibonaccis=VVV(12,VV(0,V(0)));
	fibonaccis[1].add({0});
	avv={{3,3,3,3,5,5},{3,3,3,5,3,5},{3,3,3,5,5,3},{3,3,5,3,3,5},{3,3,5,3,5,3},{3,3,5,5,3,3},{3,3,5,5,9},{3,3,5,9,5},{3,3,9,5,5},{3,5,3,3,3,5},{3,5,3,3,5,3},{3,5,3,5,3,3},{3,5,3,5,9},{3,5,3,9,5},{3,5,5,3,3,3},{3,5,5,3,9},{3,5,5,9,3},{3,5,9,3,5},{3,5,9,5,3},{3,9,3,5,5},{3,9,5,3,5},{3,9,5,5,3},{5,3,3,3,3,5},{5,3,3,3,5,3},{5,3,3,5,3,3},{5,3,3,5,9},{5,3,3,9,5},{5,3,5,3,3,3},{5,3,5,3,9},{5,3,5,9,3},{5,3,9,3,5},{5,3,9,5,3},{5,5,3,3,3,3},{5,5,3,3,9},{5,5,3,9,3},{5,5,9,3,3},{5,5,9,9},{5,9,3,3,5},{5,9,3,5,3},{5,9,5,3,3},{5,9,5,9},{5,9,9,5},{9,3,3,5,5},{9,3,5,3,5},{9,3,5,5,3},{9,5,3,3,5},{9,5,3,5,3},{9,5,5,3,3},{9,5,5,9},{9,5,9,5},{9,9,5,5}};
	for(V dude:avv)fibonaccis[sz(dude)].add(dude);
	fibonaccis[1]=VV(0,V(0));
	fibonaccis[1].add({0});
	VV row1s;
	for(V shape:compositions){
		outv(shape);
		if(sz(shape)==1){
			for(V part0:fibonaccis[shape[0]]){
				av=V(0);
				for(I dude:part0)av.add(dude);
				row1s.add(av);
			}
		}
		else if(sz(shape)==2){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					av=V(0);
					for(I dude:part0)av.add(dude);
					for(I dude:part1)av.add(dude);
					row1s.add(av);
				}
			}
		}
		else if(sz(shape)==3){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						av=V(0);
						for(I dude:part0)av.add(dude);
						for(I dude:part1)av.add(dude);
						for(I dude:part2)av.add(dude);
						row1s.add(av);
					}
				}
			}
		}
		else if(sz(shape)==4){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							av=V(0);
							for(I dude:part0)av.add(dude);
							for(I dude:part1)av.add(dude);
							for(I dude:part2)av.add(dude);
							for(I dude:part3)av.add(dude);
							row1s.add(av);
						}
					}
				}
			}
		}
		else if(sz(shape)==5){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								av=V(0);
								for(I dude:part0)av.add(dude);
								for(I dude:part1)av.add(dude);
								for(I dude:part2)av.add(dude);
								for(I dude:part3)av.add(dude);
								for(I dude:part4)av.add(dude);
								row1s.add(av);
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==6){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									av=V(0);
									for(I dude:part0)av.add(dude);
									for(I dude:part1)av.add(dude);
									for(I dude:part2)av.add(dude);
									for(I dude:part3)av.add(dude);
									for(I dude:part4)av.add(dude);
									for(I dude:part5)av.add(dude);
									row1s.add(av);
								}
							}
						}
					}
				}
			}
		}
		else if(sz(shape)==7){
			for(V part0:fibonaccis[shape[0]]){
				for(V part1:fibonaccis[shape[1]]){
					for(V part2:fibonaccis[shape[2]]){
						for(V part3:fibonaccis[shape[3]]){
							for(V part4:fibonaccis[shape[4]]){
								for(V part5:fibonaccis[shape[5]]){
									for(V part6:fibonaccis[shape[6]]){
										av=V(0);
										for(I dude:part0)av.add(dude);
										for(I dude:part1)av.add(dude);
										for(I dude:part2)av.add(dude);
										for(I dude:part3)av.add(dude);
										for(I dude:part4)av.add(dude);
										for(I dude:part5)av.add(dude);
										for(I dude:part6)av.add(dude);
										row1s.add(av);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	out<<sz(row2s)<<nl;
	out<<sz(row1s)<<nl;
	out<<sz(row0s)<<nl;
	avv=VV(0,V(0));
	for(V row2:row2s)if(row2[0]!=1 and row2[0]!=2 and row2[1]!=1 and row2[1]!=2 and row2[2]!=1 and row2[2]!=2 and row2[3]!=1 and row2[3]!=2 and row2[4]!=0 and row2[4]!=1 and row2[5]!=0 and row2[7]!=1 and row2[8]!=1 and row2[9]!=1 and row2[10]!=1 and row2[7]!=2 and row2[8]!=2 and row2[9]!=2 and row2[10]!=2 and row2[7]!=3 and row2[8]!=3 and row2[9]!=3 and row2[10]!=3)avv.add(row2);
	row2s=avv;avv=VV(0,V(0));
	avv=VV(0,V(0));
	for(V row1:row1s)if(row1[4]!=0)avv.add(row1);
	row1s=avv;avv=VV(0,V(0));
	avv=VV(0,V(0));
	for(V row0:row0s)if(row0[0]!=1 and row0[0]!=2 and row0[1]!=1 and row0[1]!=2 and row0[8]!=1 and row0[8]!=2 and row0[9]!=1 and row0[9]!=2 and row0[10]!=1 and row0[10]!=2)avv.add(row0);
	row0s=avv;avv=VV(0,V(0));
	out<<sz(row2s)<<nl;
	out<<sz(row1s)<<nl;
	out<<sz(row0s)<<nl;
	y=0;
	for(V row2:row2s){
		out<<y<<nl;y++;z=0;
		for(V row1:row1s){
			if(z%10==0)out<<z<<nl;z++;
			if(row2[5]==row1[4] and (row2[0]>=row2[5] or row2[0]==0) and (row2[1]>=row2[5] or row2[1]==0) and (row2[2]>=row2[5] or row2[2]==0) and (row2[3]>=row2[5] or row2[3]==0)){
				I isvalid=1;
				for(a=0;isvalid and a<11;a++)if(row1[a]==0 and row2[a]==0)isvalid=0;
				if(isvalid){
				//out<<nl;outv(row2);outv(row1);out<<nl;
				for(V row0:row0s){
					if((row0[0]>=row2[5] or row0[0]==0) and (row0[1]>=row2[5] or row0[1]==0) and (row0[8]>=row2[5] or row0[8]==0) and (row0[9]>=row2[5] or row0[9]==0) and (row0[10]>=row2[5] or row0[10]==0)){
						I isvalid=1;
						for(a=0;isvalid and a<11;a++)if(row0[a]==0 and row1[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if(row1[a]==0 and row2[a]==0)isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row0[a-1]!=0) and (a==10 or row0[a+1]!=0) and (row1[a]!=0) and (1) and (row0[a]!=row2[5]) and (a<2 or a>7))isvalid=0;
						for(a=0;isvalid and a<11;a++)if((a==0 or row1[a-1]!=0) and (a==10 or row1[a+1]!=0) and (row2[a]!=0) and (row0[a]!=0) and (row1[a]!=row2[5]))isvalid=0;
						if(isvalid){
							out<<nl;
							outv(row0);
							outv(row1);
							outv(row2);
							out<<nl;
						}
					}
				}}
			}
		}
	}
*/