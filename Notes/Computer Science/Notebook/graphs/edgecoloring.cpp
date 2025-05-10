// Description: Given a simple, undirected graph with max degree D, computes a (D+1)-coloring of the edges such that no neighboring edges share a color. (D-coloring is NP-hard, but can be done for bipartite graphs by repeated matchings of max-degree nodes.)
// Time: O(N*M)
V edgecoloring(I n,VP edges){//Simon Lindholm
	V w(n+1),ret(sz(edges)),fan(n),free(n),loc;
	for(P e:edges)++w[e.first],++w[e.second];
	I u,v,nc=*max_element(all(w))+1;
	VV adj(n,V(nc,-1));
	for(P e:edges){
		tie(u,v)=e;
		fan[0]=v;
		loc.assign(nc, 0);
		I at=u,end=u,d,c=free[u],ind=0,i=0;
		while(d=free[v],!loc[d]&&(v=adj[u][d])!=-1)
			loc[d]=++ind,w[ind]=d,fan[ind]=v;
		w[loc[d]]=c;
		for(I cd=d;at!=-1;cd^=c^d,at=adj[at][cd])
			swap(adj[at][cd],adj[end=at][cd^c^d]);
		while(adj[fan[i]][d]!=-1){
			I left=fan[i],right=fan[++i],e=w[i];
			adj[u][e]=left;
			adj[left][e]=u;
			adj[right][e]=-1;
			free[right]=e;
		}
		adj[u][d]=fan[i];
		adj[fan[i]][d]=u;
		for(I y:{fan[0],u,end})
			for(I& z=free[y]=0;adj[y][z]!=-1;z++);
	}
	rep(i,0,sz(edges))
		for(tie(u,v)=edges[i];adj[u][ret[i]]!=v;)++ret[i];
	return ret;
}