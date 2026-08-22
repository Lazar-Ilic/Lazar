// Description: Finds a minimum spanning tree/arborescence of a directed graph, given a root node. If no MST exists, returns -1
// Time: O(E log V)
STR dsudelete{//chilli,Takanori MAEHARA,Benq,Simon Lindholm
	V e;
	VP st;
	dsudelete(I n):e(n,-1){}
	I size(I x){return -e[find(x)];}
	I find(I x){return e[x]<0 ? x:find(e[x]);}
	I time(){return sz(st);}
	Z rollback(I t){
		for(I i=time();i-->t;)
			e[st[i].first]=st[i].second;
		st.resize(t);
	}
	B join(I a,I b){
		a=find(a),b=find(b);
		if(a==b)return false;
		if(e[a]>e[b])swap(a,b);
		st.push_back({a,e[a]});
		st.push_back({b,e[b]});
		e[a]+=e[b];e[b]=a;
		return true;
	}
};
STR edge{I a,b;L w;};
STR node{ /// lazy skew heap node
	edge key;
	node *l,*r;
	L delta;
	Z prop(){
		key.w+=delta;
		if(l)l->delta+=delta;
		if(r)r->delta+=delta;
		delta=0;
	}
	edge top(){prop();return key;}
};
node *merge(node *a,node *b){
	if(!a||!b)return a ?: b;
	a->prop(),b->prop();
	if(a->key.w>b->key.w)swap(a,b);
	swap(a->l,(a->r=merge(b,a->r)));
	return a;
}
Z pop(node*& a){a->prop();a=merge(a->l,a->r);}
pair<L,V> dmst(I n,I r,vector<edge>& g){
	dsudelete uf(n);
	vector<node*> heap(n);
	for(edge e:g)heap[e.b]=merge(heap[e.b],new node{e});
	L res=0;
	V seen(n,-1),path(n),par(n);
	seen[r]=r;
	vector<edge> qqq(n),in(n,{-1,-1}),comp;
	deque<tuple<I,I,vector<edge>>> cycs;
	rep(s,0,n){
		I u = s, qi = 0, w;
		while (seen[u] < 0) {
			if (!heap[u]) return {-1,{}};
			edge e = heap[u]->top();
			heap[u]->delta -= e.w, pop(heap[u]);
			qqq[qi] = e, path[qi++] = u, seen[u] = s;
			res += e.w, u = uf.find(e.a);
			if (seen[u] == s) { /// found cycle, contract
				node* cyc = 0;
				I end=qi,time=uf.time();
				do cyc=merge(cyc,heap[w=path[--qi]]);
				while(uf.join(u,w));
				u=uf.find(u),heap[u]=cyc,seen[u]=-1;
				cycs.push_front({u,time,{&qqq[qi],&qqq[end]}});
			}
		}
		rep(i,0,qi) in[uf.find(qqq[i].b)]=qqq[i];
	}

	for (auto& [u,t,comp] : cycs) { // restore sol (optional)
		uf.rollback(t);
		edge inedge=in[u];
		for(auto& e :comp)in[uf.find(e.b)]=e;
		in[uf.find(inedge.b)]=inedge;
	}
	rep(i,0,n)par[i]=in[i].a;
	return {res,par};
}