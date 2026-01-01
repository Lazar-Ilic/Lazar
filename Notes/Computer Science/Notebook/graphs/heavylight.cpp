// Description: Decomposes a tree into vertex disjoint heavy paths and light edges such that the path from any leaf to the root contains at most log(n) light edges. Code does additive modifications and max queries, but can support commutative segtree modifications/queries on paths and subtrees. Takes as input the full adjacency list. VALS\EDGES being true means that values are stored in the edges, as opposed to the nodes. All values initialized to the segtree default. Root must be 0.
// Time: O((log N)^2)
const L inf=1e18;
STR SGLZ{//Simon Lindholm
	SGLZ *l=0,*r=0;
	L lo,hi,ts=inf,ta=0,value=-inf; //ta toadd ts toset
	SGLZ(L lo,L hi):lo(lo),hi(hi){} // large interval of -inf
	SGLZ(VL& v,L lo,L hi):lo(lo),hi(hi){ // [lo,hi)
		if(lo+1<hi){
			L mid=lo+(hi-lo)/2;
			l=new SGLZ(v,lo,mid);r=new SGLZ(v,mid,hi);
			value=max(l->value,r->value); // associative
		}
		else value=v[lo];
	}
	L query(L a,L b){ // [a,b)
		if(b<=lo or hi<=a)return -inf;
		if(a<=lo and hi<=b)return value;
		push();
		return max(l->query(a,b),r->query(a,b));
	}
	Z set(L a,L b,L x){ // [a,b)
		if(b<=lo or hi<=a)return;
		if(a<=lo and hi<=b)ts=value=x,ta=0;
		else{
			push(),l->set(a,b,x),r->set(a,b,x);
			value=max(l->value,r->value);
		}
	}
	Z addto(L a,L b,L x){ // [a,b)
		if(b<=lo or hi<=a)return;
		if(a<=lo and hi<=b){
			if(ts!=inf)ts+=x;
			else ta+=x;
			value+=x;
		}
		else{
			push(),l->addto(a,b,x),r->addto(a,b,x);
			value=max(l->value,r->value);
		}
	}
	Z push(){
		if(!l){
			L mid=lo+(hi-lo)/2;
			l=new SGLZ(lo,mid);r=new SGLZ(mid,hi);
		}
		if(ts!=inf)
			l->set(lo,hi,ts),r->set(lo,hi,ts),ts=inf;
		else if(ta)
			l->addto(lo,hi,ta),r->addto(lo,hi,ta),ta=0;
	}
};
template <B edgevals> STR heavylight{
	I N,tim=0;//Benjamin Qi,Oleksandr Kulkov,chilli
	VV adj;
	V parent,siz,depth,rt,pos;
	SGLZ *tree;
	heavylight(VV adjj):N(sz(adjj)),adj(adjj),parent(N,-1),siz(N,1),depth(N),rt(N),pos(N),tree(new SGLZ(0,N)){dfssz(0);dfshld(0);}
	Z dfssz(I v){
		if (parent[v]!=-1)adj[v].erase(find(all(adj[v]),parent[v]));
		for (I& u :adj[v]){
			parent[u]=v,depth[u]=depth[v]+1;
			dfssz(u);
			siz[v]+=siz[u];
			if (siz[u]>siz[adj[v][0]])swap(u,adj[v][0]);
		}
	}
	Z dfshld(I v){
		pos[v]=tim++;
		for (I u:adj[v]){
			rt[u]=(u==adj[v][0]?rt[v]:u);
			dfshld(u);
		}
	}
	template <class B> Z process(I u,I v,B op){
		for (;rt[u]!=rt[v];v=parent[rt[v]]){
			if(depth[rt[u]]>depth[rt[v]])swap(u,v);
			op(pos[rt[v]],pos[v]+1);
		}
		if(depth[u]>depth[v])swap(u,v);
		op(pos[u]+edgevals,pos[v]+1);
	}
	Z modifypath(I u,I v,I val){
		process(u,v,[&](I l,I r){tree->addto(l,r,val);});
	}
	I querypath(I u,I v){ // modify depending on problem
		I res=-1e9;
		process(u,v,[&](I l,I r){
				res=max(res,tree->query(l,r));
		});
		return res;
	}
	I querysubtree(I v){ // modifysubtree is similar
		return tree->query(pos[v]+edgevals,pos[v]+siz[v]);
	}
};