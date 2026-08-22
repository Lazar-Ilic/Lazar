//%%writefile a.cpp
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O1")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;
using B=bool;
using C=char;
using D=double;
using I=int;
using L=long long;
using ULL=unsigned long long;
using U=uint64_t;
using LD=long double;
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
using VC=vector<C>;
using VD=vector<D>;
using V=vector<I>;
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
using VSETP=vector<SETP>;
using VUSET=vector<USET>;
using VMSET=vector<MSET>;
using SETV=set<V>;
using SETSETV=set<SETV>;
using SETVSET=set<VSET>;
using SETVSETP=set<VSETP>;
using QVSET=queue<VSET>;
using QVSETP=queue<VSETP>;
using MIV=map<I,V>;
using MVI=map<V,I>;
using MSETV=map<SET,V>;
using MSETVS=map<SET,VS>;
using MSVS=map<S,VS>;
using PIV=pair<I,V>;
using UMIV=unordered_map<I,V>;
using CD=complex<D>;
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
#define nextpermutation next_permutation
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
const I p=1000000007; // 998244353 1000000007 1000000009 1000000000
//--------------------------------------------------------------------



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

	MSVS amsvs,bmsvs;
	for(a=0;a<2315;a++){
		in>>as;
		avs.add(as);
	}
	for(b=0;b<5;b++){
		for(c=b+1;c<5;c++){
			for(d=0;d<26;d++){
				for(e=0;e<26;e++){
					as=".....";
					as[b]=C('A'+d);
					as[c]=C('A'+e);
					bvs.add(as);
				}
			}
		}
	}
	for(a=0;a<sz(bvs);a++){
		as=bvs[a];
		for(b=0;b<sz(avs);b++){
			bs=avs[b];
			c=1;
			for(d=0;d<5;d++){
				if(!(as[d]=='.' or as[d]==bs[d]))c=0;
			}
			if(c){
				if(amsvs.count(as)){
					amsvs[as].add(bs);
				}
				else{
					cvs={bs};
					amsvs.insert({as,cvs});
				}
			}
		}
	}
	for(const auto& [theset,value]:amsvs){
		if(size(value)>=10){ // Can modify value.
			for(c=0;c<size(value);c++){
				// out<<value[c]<<nl;
			}
			// out<<nl;
		}
	}

	// Compute a maximal chain and then output the top say 20 maximal chains produced here to further examine using another algorithm. Could be eyeballing, manual, inspection. I read through the entire words list.

	bvs.clear();
	for(b=0;b<5;b++){
		for(c=b+1;c<5;c++){
			for(d=c+1;d<5;d++){
				for(e=0;e<26;e++){
					for(f=0;f<26;f++){
						for(g=0;g<26;g++){
							as=".....";
							as[b]=C('A'+e);
							as[c]=C('A'+f);
							as[d]=C('A'+g);
							bvs.add(as);
						}
					}
				}
			}
		}
	}
	for(a=0;a<sz(bvs);a++){
		as=bvs[a]; // Relevant pattern like ".IG.T"
		for(b=0;b<sz(avs);b++){
			bs=avs[b]; // Loop through all strings in the set.
			c=1;
			for(d=0;d<5;d++){ // If this string matches the pattern.
				if(!(as[d]=='.' or as[d]==bs[d]))c=0;
			}
			if(c){ // Add it to the map from patterns to pattern matching strings.
				if(bmsvs.count(as)){
					bmsvs[as].add(bs);
				}
				else{
					cvs={bs};
					bmsvs.insert({as,cvs});
				}
			}
		}
	}
	for(const auto& [theset,value]:bmsvs){ // Iterate through map.
		if(size(value)>=10){ // Can modify value.
			for(c=0;c<size(value);c++){
				out<<value[c]<<nl;
			} // Output all sets of size to eyeball and consider.
			out<<nl;
		}
	}
	
	// Separate script.
	// Could consider programatically producing strong evidence of optimality here in the right way.
	
	as="BODEFHLMNRSW";
	for(a=0;a<2315;a++){
		in>>bs;
		b=1;
		for(c=0;c<size(as);c++){
			for(d=0;d<size(bs);d++){
				if(as[c]==bs[d])b=0;
			}
		}
		if(b)avs.add(bs);
	}
	bvs={"WIGHT","TIGHT","SIGHT","RIGHT","NIGHT","MIGHT","LIGHT","FIGHT","EIGHT","DIGIT","BIGOT"};
	for(a=0;a<size(avs);a++){
		for(b=a+1;b<size(avs);b++){
			for(c=b+1;c<size(avs);c++){
				if(a!=b and b!=c and c!=a){
					bs=avs[a];
					cs=avs[b];
					ds=avs[c];
					// Check if a grey appears in multiple words.
					aset.clear();
					e=1;
					for(d=0;d<5;d++){
						if(bs[d]!='I' and bs[d]!='G' and bs[d]!='T'){
							aset.insert(bs[d]-'A');
						}
					}
					for(d=0;d<5;d++){
						if(cs[d]!='I' and cs[d]!='G' and cs[d]!='T'){
							if(!aset.count(cs[d]-'A'))aset.insert(cs[d]-'A');
							else e=0;
						}
					}
					for(d=0;d<5;d++){
						if(ds[d]!='I' and ds[d]!='G' and ds[d]!='T'){
							if(aset.count(ds[d]-'A'))e=0;
						}
					}
					if(e)out<<bs<<" "<<cs<<" "<<ds<<nl;
				}
			}
		}
	}
	// Output CIVIC KITTY PIZZA fails.

	// Another script to verify no 14 from .IGHT

	as="EFLMNRSW";
	for(a=0;a<2315;a++){
		in>>bs;
		b=1;
		for(c=0;c<size(as);c++){
			for(d=0;d<size(bs);d++){
				if(as[c]==bs[d])b=0;
			}
		}
		if(b)avs.add(bs);
	}
	bvs={"WIGHT","TIGHT","SIGHT","RIGHT","NIGHT","MIGHT","LIGHT","FIGHT","EIGHT"};
	out<<size(avs)<<nl;
	for(a=0;a<size(avs);a++){
		for(b=a+1;b<size(avs);b++){
			for(c=b+1;c<size(avs);c++){
				for(f=c+1;f<size(avs);f++){
				for(g=f+1;g<size(avs);g++){
				if(a!=b and b!=c and c!=a and a!=f and b!=f and c!=f and a!=g and b!=g and c!=g and f!=g){
					bs=avs[a];
					cs=avs[b];
					ds=avs[c];
					es=avs[f];
					fs=avs[g];
					// Check if a grey appears in multiple words.
					aset.clear();
					e=1;
					for(d=0;d<5;d++){
						if(bs[d]!='I' and bs[d]!='G' and bs[d]!='T'){
							aset.insert(bs[d]-'A');
						}
					}
					for(d=0;d<5 and e;d++){
						if(cs[d]!='I' and cs[d]!='G' and cs[d]!='T'){
							if(!aset.count(cs[d]-'A'))aset.insert(cs[d]-'A');
							else e=0;
						}
					}
					for(d=0;d<5 and e;d++){
						if(ds[d]!='I' and ds[d]!='G' and ds[d]!='T'){
							if(!aset.count(ds[d]-'A'))aset.insert(ds[d]-'A');
							else e=0;
						}
					}
					for(d=0;d<5 and e;d++){
						if(es[d]!='I' and es[d]!='G' and es[d]!='T'){
							if(!aset.count(es[d]-'A'))aset.insert(es[d]-'A');
							else e=0;
						}
					}
					for(d=0;d<5 and e;d++){
						if(fs[d]!='I' and fs[d]!='G' and fs[d]!='T'){
							if(aset.count(fs[d]-'A'))e=0;
						}
					}
					if(e)out<<bs<<" "<<cs<<" "<<ds<<" "<<es<<" "<<fs<<nl;
				}
			}
			}
			}
		}
	}

	// Another script hit 15.

	as="BCFGHKLMPSTWZ";
	for(a=0;a<2315;a++){
		in>>bs;
		b=1;
		for(c=0;c<size(as);c++){
			for(d=0;d<size(bs);d++){
				if(as[c]==bs[d])b=0;
			}
		}
		if(b)avs.add(bs);
	}
	for(a=0;a<size(avs);a++){
		if(avs[a]!="RARER")cvs.add(avs[a]);
	}
	avs=cvs;
	bvs={"WATER","LATER","HATER","EATER","CATER","TAMER","PAPER","RARER","BAKER","GAZER","SAFER"};
	out<<size(avs)<<nl;
	for(a=0;a<size(avs);a++){
		for(b=a+1;b<size(avs);b++){
			for(c=b+1;c<size(avs);c++){
				//for(f=c+1;f<size(avs);f++){
				for(g=f+1;g<size(avs);g++){
				if(a!=b and b!=c and c!=a and a!=g and b!=g and c!=g){
					bs=avs[a];
					cs=avs[b];
					ds=avs[c];
					//es=avs[f];
					fs=avs[g];
					// Check if a grey appears in multiple words.
					aset.clear();
					e=1;
					for(d=0;d<5;d++){
						if(bs[d]!='A' and bs[d]!='E' and bs[d]!='R'){
							aset.insert(bs[d]-'A');
						}
					}
					for(d=0;d<5 and e;d++){
						if(cs[d]!='A' and cs[d]!='E' and cs[d]!='R'){
							if(!aset.count(cs[d]-'A'))aset.insert(cs[d]-'A');
							else e=0;
						}
					}
					for(d=0;d<5 and e;d++){
						if(ds[d]!='A' and ds[d]!='E' and ds[d]!='R'){
							if(!aset.count(ds[d]-'A'))aset.insert(ds[d]-'A');
							else e=0;
						}
					}

					for(d=0;d<5 and e;d++){
						if(fs[d]!='A' and fs[d]!='E' and fs[d]!='R'){
							if(aset.count(fs[d]-'A'))e=0;
						}
					}
					h=0;
					i=0;
					for(d=0;d<5 and e;d++){
						if(bs[d]=='E')i++;
					}
					if(i>=2)h++;
					i=0;
					for(d=0;d<5 and e;d++){
						if(cs[d]=='E')i++;
					}
					if(i>=2)h++;
					i=0;
					for(d=0;d<5 and e;d++){
						if(ds[d]=='E')i++;
					}
					if(i>=2)h++;
					
					i=0;
					for(d=0;d<5 and e;d++){
						if(fs[d]=='E')i++;
					}
					if(i>=2)h++;
					if(h>=2)e=0;

					h=0;
					i=0;
					for(d=0;d<5 and e;d++){
						if(bs[d]=='R')i++;
					}
					if(i>=2)h++;
					i=0;
					for(d=0;d<5 and e;d++){
						if(cs[d]=='R')i++;
					}
					if(i>=2)h++;
					i=0;
					for(d=0;d<5 and e;d++){
						if(ds[d]=='R')i++;
					}
					if(i>=2)h++;
					
					i=0;
					for(d=0;d<5 and e;d++){
						if(fs[d]=='R')i++;
					}
					if(i>=2)h++;
					if(h>=1)e=0;

					h=0;
					if(bs[0]=='A')h++;
					if(cs[0]=='A')h++;
					if(ds[0]=='A')h++;
					if(fs[0]=='A')h++;
					if(h>=2)e=0;

					if(e)out<<bs<<" "<<cs<<" "<<ds<<" "<<fs<<nl;
				}
			}
			//}
			}
		}
	}
}

I main(){zz();I a=1;while(a--){az();}}