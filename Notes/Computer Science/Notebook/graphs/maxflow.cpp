STR edge{
  I a,b;
  L capacity,flow;
  edge(){}
  edge(I a,I b,L capacity):a(a),b(b),capacity(capacity),flow(0){}
};
STR maxflow{
  I num;
  vector<edge> edges;
  VV g;
  V d,pt;
  maxflow(I num):num(num),edges(0),g(num),d(num),pt(num){}
  Z addedge(I u,I v,L capacity){
	if(u!=v){
	  edges.emplace_back(u,v,capacity);
	  g[u].emplace_back(edges.size()-1);
	  edges.emplace_back(v,u,0);
	  g[v].emplace_back(edges.size()-1);
	}
  }
  B bfs(I source,I to){
	Q q({source});
	fill(d.begin(),d.end(),num+1);
	d[source]=0;
	while(!q.empty()){
	  I u=q.front();q.pop();
	  if(u==to)break;
	  for(I k:g[u]){
		edge &e=edges[k];
		if(e.flow<e.capacity and d[e.b]>d[e.a]+1){
		  d[e.b]=d[e.a]+1;
		  q.emplace(e.b);
		}
	  }
	}
	return d[to]!=num+1;
  }
  L dfs(I u,I to,L flow=-1){
	if(u==to or flow==0)return flow;
	for(I &i=pt[u];i<g[u].size();++i){
	  edge &e=edges[g[u][i]];
	  edge &oe=edges[g[u][i]^1];
	  if(d[e.b]==d[e.a]+1){
		L amt=e.capacity-e.flow;
		if(flow!=-1 and amt>flow)amt=flow;
		if(L pushed=dfs(e.b,to,amt)){
		  e.flow+=pushed;
		  oe.flow-=pushed;
		  return pushed;
		}
	  }
	}
	return 0;
  }
  L generate(I source,I to){
	L total=0;
	while(bfs(source,to)){
	  fill(pt.begin(),pt.end(),0);
	  while(L flow=dfs(source,to))total+=flow;
	}
	return total;
  }
};

//----------

Z az(){
	in>>a>>b;
	maxflow amax(a);
	for(c=0;c<b;c++){
		in>>d>>e>>f;
		amax.addedge(d,e,f);
	}
	out<<amax.generate(0,a-1)<<nl;
	for(edge aedge:amax.edges){
		if(aedge.flow>0)out<<aedge.a<<" "<<aedge.b<<nl;
	}
}