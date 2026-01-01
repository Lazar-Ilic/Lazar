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
	for(I a=0;a<sz(av);a++)out<<av[a]<<" "; // Change back later.
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000 1234567891 433494437 993353399

//--------------------------------------------------------------------

/*
 
int minSwaps(vector<int> nums,int n){
	int len = n;
	map<int,int> map;
	for(int i=0;i<len;i++)map[nums[i]]=i;
	sort(all(nums));
	bool visited[len]={0};
	// Initialize result
	int ans=0;
	for(int i=0;i<len;i++){
		if(visited[i] || map[nums[i]]==i)continue;
		int j=i,cycle_size=0;
		while(!visited[j]){
			visited[j]=true;
			j = map[nums[j]];
			cycle_size++;
		}
		if(cycle_size>0){
			ans+=(cycle_size-1);
		}
	}
	return ans;
}
 
// Driver code
int main(){
	// Driver program to test the above function
	int a[] = { 1, 5, 4, 3, 2 };
	int n = 5;
	cout << minSwaps(a, n);
	return 0;
}

----------

void dfs(vector &lt; int &gt; vec[], vector &lt; bool &gt; &amp; vis, int node, int &amp; compSize) {
  vis[node] = true;
  compSize += 1;
  for (auto x: vec[node]) {
    if (!vis[x]) {
      dfs(vec, vis, x, compSize);
    }
  }
}
int minimumSwaps(vector &lt; int &gt; &amp; a, int n) {
  vector &lt; int &gt; vec[n + 1];
  vector &lt; pair &lt; int, int &gt;&gt; aux;
  for (int i = 0; i &lt; n; i++) {
    pair &lt; int, int &gt; p = {
      a[i],
      i + 1
    };
    aux.push_back(p);
  }
  sort(aux.begin(), aux.end());
  for (auto x: aux) {
    cout &lt;&lt; x.first &lt;&lt; " " &lt;&lt; x.second &lt;&lt; endl;
  }
  vector &lt; bool &gt; vis(n + 1, false);
  for (int i = 0; i &lt; n; i++) {
    vec[aux[i].second].push_back(i + 1);
  }
  int ans = 0;
for (int i = 1; i &lt;= n; i++) {
    if (!vis[i]) {
      int compSize = 0;
      dfs(vec, vis, i, compSize);
      ans += (compSize - 1);
    }
  }
  return ans;
}

----------

public int findMinSwapsToSort(int[] ar) {
    int n = ar.length;
    Map<Integer, Integer> m = new HashMap<>();
    for (int i = 0; i < n; i++) {
        m.put(ar[i], i);
    }
    Arrays.sort(ar);
    for (int i = 0; i < n; i++) {
        ar[i] = m.get(ar[i]);
    }
    m = null;
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        int val = ar[i];
        if (val < 0) continue;
        while (val != i) {
            int new_val = ar[val];
            ar[val] = -1;
            val = new_val;
            swaps++;
        }
        ar[i] = -1;
    }
    return swaps;
}

*/

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
Mmm 1 inversion is just like ugh increasing until a single point swap and then increasing again I think like ugh...

132456 works...

Ugh so like maybe we can count the number of dudes ugh pairs ugh... fucking values and where they might need to be flip flopped to depending on casework and range updating... based on final bull shit. n has to be in n position or n+-1 position depending. So all but 2 guys end up the wrong place yadda yadda yadda yadda... ugh for sure if we can solve the minimum swaps needed to sort then of course that number is at most 1 more than this number I think ugh if already sorted out 1 so then check for that or already done otherwise I think that like ugh... it can be ugh our value can actually be ugh 1 more or equal to or 1 less I think ugh... maybe we can process those 2 cases and then go from like prefix to suffix ugh just sorting in naively does that work? And then compute minimum over those prefix suffix taking the 2 gap? Ugh or can we not simply do naive ugh I don't think that simple naive works here think we need to go prefix and suffix and compute check. Maybe we can undo those swaps somehow to go from Left Right counting. That one is canonical to be sure ugh... I think that ugh like when we do this casework we can very simply count up front ugh the process like if either of those 2 dudes were in their Right place and the natural simple sorting process as we go through in increasing order ugh.

So anyways after consulting the canonical codes above and contemplating the nature of this task it becomes rapidly much more clear that we need to consider like cases if and only if we are casing on the cycle break down flip flop I think to solve for that final +-1 or 0 mod modification index but that ought to be rather trivial in the cyclic decomposition scheme.
*/

}

I main(){zz();I a=1;in>>a;while(a--){az();}}