STR graph{
  I n;
  VV adj, rdj; //adjacency list and reverse
  graph(I n):n(n),adj(n),rdj(n){}
  Z addedge(I src, I dst) { //source destination
    adj[src].add(dst);
    rdj[dst].add(src);
  }
  VV sccs(){ // kosaraju
    V ord, visited(n);
    VV scc;
    function<void(I, VV&, V&)> dfs
    = [&](I u, VV &adj, V &out) {
      visited[u] = true;
      for (I v : adj[u])
        if (!visited[v]) dfs(v, adj, out);
      out.add(u);
    };
    for (I u = 0; u < n; ++u)
      if (!visited[u]) dfs(u, adj, ord);
    fill(all(visited), false);
    for (I i = n - 1; i >= 0; --i)
      if (!visited[ord[i]])
        scc.add({}), dfs(ord[i], rdj, scc.back());
    return scc;
  }
};

//--------------------------------------------------------------------

Z az(){
	I n, m;
	scanf("%d %d", &n, &m); //number of vertices and edges
	graph g(n); //graph of n vertices
	for (I k = 0; k < m; ++k){
    	I i, j;
    	scanf("%d %d", &i, &j); //read in edge
    	g.addedge(i - 1, j - 1); //add edge
  	}
	VV scc = g.sccs(); //sccs
	V outdeg(scc.size()); //outdeg for each scc
	V id(n); //identity of scc for each vertex
  	for (I i = 0; i < scc.size(); ++i)
    	for (I u : scc[i]) id[u] = i; //identity of vertex
  	for (I u = 0; u < n; ++u)
    	for (I v : g.adj[u])
      		if (id[u] != id[v]) ++outdeg[id[u]]; //count outdegree
}