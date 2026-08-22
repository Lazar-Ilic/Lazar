// Description: Find a global minimum cut in an undirected graph, as represented by an adjacency matrix.
// Time: O(V^3)
PIV globalmincut(VV graph){//Simon Lindholm
	PIV best={INT_MAX,{}};
	I n=sz(graph);
	VV co(n);
	rep(i,0,n) co[i]={i};
	rep(z,1,n){
		vi w=graph[0];
		size_t s=0,t=0;
		rep(it,0,n-z){ // O(V^2) -> O(E log V) with prio. queue
			w[t]=INT_MIN;
			s=t,t=max_element(all(w))-w.begin();
			rep(i,0,n) w[i]+=graph[t][i];
		}
		best=min(best,{w[t]-graph[t][t],co[t]});
		co[s].insert(co[s].end(),all(co[t]));
		rep(i,0,n) graph[s][i]+=graph[t][i];
		rep(i,0,n) graph[i][s]=graph[s][i];
		graph[0][t]=INT_MIN;
	}
	return best;
}