// Description: Given a list of edges representing an undirected flow graph, returns edges of the Gomory-Hu tree. The max flow between any pair of vertices is given by minimum edge weight along the Gomory-Hu tree path.
// Time: O(V) Flow Computations
STR pushrelabel{//chilli,Takanori MAEHARA
	STR edge{I dest, back;L f, c;};
	vector<vector<edge>> g;VL ec;vector<edge*> cur;VV hs;V H;
	pushrelabel(I n):g(n),ec(n),cur(n),hs(2*n),H(n){}
	Z addedge(I s,I t,L cap,L rcap=0){
		if(s==t)return;
		g[s].push_back({t,sz(g[t]),0,cap});
		g[t].push_back({s,sz(g[s])-1,0,rcap});
	}
	Z addflow(edge& e,L f){
		edge &back=g[e.dest][e.back];
		if(!ec[e.dest] and f)hs[H[e.dest]].push_back(e.dest);
		e.f+=f;e.c-=f;ec[e.dest]+=f;
		back.f-=f;back.c+=f;ec[back.dest]-=f;
	}
	L generate(I s,I t){
		I v=sz(g);H[s]=v;ec[t]=1;
		V co(2*v);co[0]=v-1;
		rep(i,0,v)cur[i]=g[i].data();
		for(edge& e:g[s])addflow(e,e.c);
		for(I hi=0;;){
			while(hs[hi].empty())if(!hi--)return -ec[s];
			I u=hs[hi].back(); hs[hi].pop_back();
			while(ec[u]>0){  // discharge u
				if(cur[u]==g[u].data()+sz(g[u])){
					H[u]=1e9;
					for(edge& e:g[u])if(e.c and H[u]>H[e.dest]+1)
						H[u]=H[e.dest]+1,cur[u]=&e;
					if(++co[H[u]],!--co[hi] and hi<v)
						rep(i,0,v)if(hi<H[i] and H[i]<v)
							--co[H[i]],H[i]=v+1;
					hi=H[u];
				}
				else if(cur[u]->c && H[u] == H[cur[u]->dest]+1){
					addflow(*cur[u],min(ec[u],cur[u]->c));
				}
				else ++cur[u];
			}
		}
	}
	B leftofcut(I a){return H[a]>=sz(g);}
};
vector<array<L,3>> mincuts(int N,vector<array<L,3>> edges){
	vector<array<L,3>> tree;
	V parent(N);
	rep(i,1,N){
		pushrelabel apr(N); // Dinic also works
		for(array<L,3> t:edges)apr.addedge(t[0],t[1],t[2],t[2]);
		tree.push_back({i,parent[i],apr.calc(i,parent[i])});
		rep(j,i+1,N)
			if(parent[j]==parent[i] and apr.leftofcut(j))parent[j]=i;
	}
	return tree;
}