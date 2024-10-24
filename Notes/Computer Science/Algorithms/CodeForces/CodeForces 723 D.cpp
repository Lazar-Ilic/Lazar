#include <bits/stdc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using LD=long double;
using S=string;
using U=uint64_t;
using PB=pair<B,B>;
using PC=pair<C,C>;
using PD=pair<D,D>;
using P=pair<I,I>;
using PL=pair<L,L>;
using PLD=pair<LD,LD>;
using PS=pair<S,S>;
using PIS=pair<I,S>;
using PID=pair<I,D>;
using PLI=pair<L,I>;
using TIII=tuple<I,I,I>;
using SET=set<I>;
using USET=unordered_set<I>;
using MSET=multiset<I>;
using SETSET=set<SET>;
using SETS=set<S>;
using SETL=set<L>;
using SETP=set<P>;
using SETPL=set<PL>;
using MSI=map<S,I>;
using MII=map<I,I>;
using MLI=map<L,I>;
using MLL=map<L,L>;
using MPI=map<P,I>;
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
using STP=stack<P>;
using STPL=stack<PL>;
using Q=queue<I>;
using PQ=priority_queue<I>;
using VB=vector<B>;
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
using VL=vector<L>; 
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
using VVB=vector<VB>;
using VVC=vector<VC>;
using VVD=vector<VD>;
using VVL=vector<VL>;
using VV=vector<V>;
using VVV=vector<VV>;
using VVL=vector<VL>;
using VVLD=vector<VLD>;
using VVP=vector<VP>;
using VVS=vector<VS>;
using VSET=vector<SET>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using MIV=map<I,V>;
using UMIV=unordered_map<I,V>;
using Z=void;
#define MHI map<H,I>
#define UMHI unordered_map<H,I>
#define PTL PT<L>
#define PTD PT<D>
#define VH vector<H>
#define VPTL vector<PTL>
#define VPTD vector<PTD>
#define orderofkey order_of_key
#define findbyorder find_by_order
#define STR struct
#define add push_back
#define addf push_front
#define remove pop_back
#define subsize __builtin_popcount
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
const I p=1000000007; // 998244353 1000000007
Z outv(V av){
	I a;
	out<<av[0];
	for(a=1;a<sz(av);a++){
		out<<" "<<av[a];
	}
	out<<nl;
}
Z outvv(VV avv){
	I a,b;
	for(a=0;a<sz(avv);a++){
		out<<avv[a][0];
		for(b=1;b<sz(avv[a]);b++){
            out<<" "<<avv[a][b];
        }
        out<<nl;
    }
}
//--------------------------------------------------------------------

L _mergeSort(L arr[], L temp[], L left, L right);
L merge(L arr[], L temp[], L left, L mid,
          L right);
L mergeSort(L arr[], L array_size){
    L temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
L _mergeSort(L arr[], L temp[], L left, L right){
    L mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
L merge(L arr[], L temp[], L left, L mid,L right){
    L i, j, k;
    L inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)){
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

Z az(){
    C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
    D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
    I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
    L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
    S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
    V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
    VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
    VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
    VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
    VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
    VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
    SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
    USET auset,buset,cuset,duset,euset,fuset,guset,huset;
    MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
    MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
    UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
    DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
    Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
    PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
    ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;
    
	in>>as;
	L arr[24][sz(as)];
	avs={"nota","onta","tnoa","ntoa","otna","tona","toan","otan","aton","taon","oatn","aotn","anto","nato","tano","atno","ntao","tnao","onat","noat","aont","oant","naot","anot"};
	n=0;
	o=0;
	t=0;
	a=0;
	for(d=0;d<sz(as);d++){ // Post Contest Analysis: terrible terrible terrible style of code I would probably never again use unless really really really needed or simpler and faster.... sometimes in real life an implementation like this can be faster actually depending costly the algorithmic construction code is versus explicit in place literal.
		if(as[d]=='N'){
			n++;
			arr[0][d]=0;//nota
			arr[1][d]=1;//onta
			arr[2][d]=1;//tnoa
			arr[3][d]=0;//ntoa
			arr[4][d]=2;//otna
			arr[5][d]=2;//tona
			arr[6][d]=3;//toan
			arr[7][d]=3;//otan
			arr[8][d]=3;//aton
			arr[9][d]=3;//taon
			arr[10][d]=3;//oatn
			arr[11][d]=3;//aotn
			arr[12][d]=1;//anto
			arr[13][d]=0;//nato
			arr[14][d]=2;//tano
			arr[15][d]=2;//atno
			arr[16][d]=0;//ntao
			arr[17][d]=1;//tnao
			arr[18][d]=1;//onat
			arr[19][d]=0;//noat
			arr[20][d]=2;//aont
			arr[21][d]=2;//oant
			arr[22][d]=0;//naot
			arr[23][d]=1;//anot
		}
		else if(as[d]=='O'){
			o++;
			arr[0][d]=1;//nota
			arr[1][d]=0;//onta
			arr[2][d]=2;//tnoa
			arr[3][d]=2;//ntoa
			arr[4][d]=0;//otna
			arr[5][d]=1;//tona
			arr[6][d]=1;//toan
			arr[7][d]=0;//otan
			arr[8][d]=2;//aton
			arr[9][d]=2;//taon
			arr[10][d]=0;//oatn
			arr[11][d]=1;//aotn
			arr[12][d]=3;//anto
			arr[13][d]=3;//nato
			arr[14][d]=3;//tano
			arr[15][d]=3;//atno
			arr[16][d]=3;//ntao
			arr[17][d]=3;//tnao
			arr[18][d]=0;//onat
			arr[19][d]=1;//noat
			arr[20][d]=1;//aont
			arr[21][d]=0;//oant
			arr[22][d]=2;//naot
			arr[23][d]=2;//anot
		}
		else if(as[d]=='T'){
			t++;
			arr[0][d]=2;//nota
			arr[1][d]=2;//onta
			arr[2][d]=0;//tnoa
			arr[3][d]=1;//ntoa
			arr[4][d]=1;//otna
			arr[5][d]=0;//tona
			arr[6][d]=0;//toan
			arr[7][d]=1;//otan
			arr[8][d]=1;//aton
			arr[9][d]=0;//taon
			arr[10][d]=2;//oatn
			arr[11][d]=2;//aotn
			arr[12][d]=2;//anto
			arr[13][d]=2;//nato
			arr[14][d]=0;//tano
			arr[15][d]=1;//atno
			arr[16][d]=1;//ntao
			arr[17][d]=0;//tnao
			arr[18][d]=3;//onat
			arr[19][d]=3;//noat
			arr[20][d]=3;//aont
			arr[21][d]=3;//oant
			arr[22][d]=3;//naot
			arr[23][d]=3;//anot
		}
		else {
			a++;
			arr[0][d]=3;//nota
			arr[1][d]=3;//onta
			arr[2][d]=3;//tnoa
			arr[3][d]=3;//ntoa
			arr[4][d]=3;//otna
			arr[5][d]=3;//tona
			arr[6][d]=2;//toan
			arr[7][d]=2;//otan
			arr[8][d]=0;//aton
			arr[9][d]=1;//taon
			arr[10][d]=1;//oatn
			arr[11][d]=0;//aotn
			arr[12][d]=0;//anto
			arr[13][d]=1;//nato
			arr[14][d]=1;//tano
			arr[15][d]=0;//atno
			arr[16][d]=2;//ntao
			arr[17][d]=2;//tnao
			arr[18][d]=2;//onat
			arr[19][d]=2;//noat
			arr[20][d]=0;//aont
			arr[21][d]=1;//oant
			arr[22][d]=1;//naot
			arr[23][d]=0;//anot
		}
	}
	fl=0;
	q=0;
	for(d=0;d<24;d++){
		gl=mergeSort(arr[d],sz(as));
		if(gl>fl){
			fl=gl;
			q=d;
		}
	}
	for(d=0;d<4;d++){
		if(avs[q][d]=='n'){
			for(e=0;e<n;e++){
				out<<"N";
			}
		}
		else if(avs[q][d]=='o'){
			for(e=0;e<o;e++){
				out<<"O";
			}
		}
		else if(avs[q][d]=='t'){
			for(e=0;e<t;e++){
				out<<"T";
			}
		}
		else{
			for(e=0;e<a;e++){
				out<<"A";
			}
		}
	}
	out<<nl;
}

I main(){
    ios_base::sync_with_stdio(0);in.tie(0);out.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("a.txt", "r", stdin);
    #endif
    I a=1;in>>a;
    while(a--){az();}
}