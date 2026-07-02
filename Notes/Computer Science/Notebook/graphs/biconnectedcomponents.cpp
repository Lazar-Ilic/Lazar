// Description: Finds all biconnected components in an undirected graph, and runs a callback for the edges in each. In a biconnected component there are at least two distinct paths between any two nodes. Note that a node can be in several components. An edge which is not in a component is a bridge, i.e., not part of any cycle.
// Usage:
//  int eid=0;ed.resize(N);
//  for each edge (a,b){
//    ed[a].emplace_back(b,eid);
//    ed[b].emplace_back(a,eid++);}
//  bicomps([\&](const vi\& edgelist) {...});
// Time: O(E + V)
// Status: tested during MIPT ICPC Workshop 2017
V num, abcc;
VVP edges;
I time;
template<class F>
I dfs(I at,I parent,F& f){//Simon Lindholm
	I me=num[at]=++time,e,y,top=me;
	for (auto pa:edges[at])if(pa.second!=parent){
		tie(y,e)=pa;
		if(num[y]){
			top=min(top,num[y]);
			if(num[y]<me)
				abcc.push_back(e);
		}
		else{
			I si=sz(abcc);
			I up=dfs(y,e,f);
			top=min(top,up);
			if(up==me){
				abcc.push_back(e);
				f(V(abcc.begin()+si,abcc.end()));
				abcc.resize(si);
			}
			else if(up<me)abcc.push_back(e);
			else{ /* e is a bridge */ }
		}
	}
	return top;
}
template<class F>
Z bicomps(F f){
	num.assign(sz(edges),0);
	rep(i,0,sz(edges))if(!num[i])dfs(i,-1,f);
}