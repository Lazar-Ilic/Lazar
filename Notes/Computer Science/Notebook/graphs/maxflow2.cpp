// Time: O(EV log max|cap|)
// O(E * min(E^(1/2),V^(2/3))) if max|cap|=1
// O(E * V^(1/2)) for bipartite matching
STR maxflow{//chilli
	STR edge{
		I to,rev;L c,oc;
		L flow(){return max(oc-c,0L);} // if you need flows
	};
	V lvl,ptr,q;
	vector<vector<edge>> adj;
	maxflow(I n):lvl(n),ptr(n),q(n),adj(n){}
	Z addedge(I a,I b,L c,L rcap=0){
		adj[a].push_back({b,sz(adj[b]),c,c});
		adj[b].push_back({a,sz(adj[a])-1,rcap,rcap});
	}
	L dfs(I v,I t,L f){
		if(v==t or !f)return f;
		for(I& i=ptr[v];i<sz(adj[v]);i++){
			edge& e=adj[v][i];
			if(lvl[e.to]==lvl[v]+1)
				if(L z=dfs(e.to,t,min(f,e.c))){
					e.c-=z,adj[e.to][e.rev].c+=z;
					return z;
				}
		}
		return 0;
	}
	L calculate(I source,I tosink){
		L flow=0;q[0]=source;
		rep(lll,0,31)do{ // 'I lll=30' maybe faster for random data
			lvl=ptr=V(sz(q));
			I qi=0,qe=lvl[source]=1;
			while(qi<qe and !lvl[tosink]){
				I v=q[qi++];
				for(edge e:adj[v])
					if(!lvl[e.to] and e.c>>(30-lll))
						q[qe++]=e.to,lvl[e.to]=lvl[v]+1;
			}
			while(L z=dfs(source,tosink,LLONG_MAX))flow+=z;
		}while(lvl[tosink]);
		return flow;
	}
	B leftofcut(I a){return lvl[a]!=0;}
};