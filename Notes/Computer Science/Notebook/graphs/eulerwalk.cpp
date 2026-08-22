// Description: Eulerian undirected/directed path/cycle algorithm. Input should be a vector of (dest, global edge index), where for undirected graphs, forward/backward edges have the same index. Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or empty list if no cycle/path exists. To get edge indices back, add .second to s and ret.
// Time: O(E+V)
//{destination,edgenumber}
//returns list of nodes source at start and end or empty V
//to get edgenumbers back add .second to s and ret
V eulerwalk(VVP& graph,I numedges,I source=0){//Simon Lindholm
	I n=sz(graph);
	V d(n),its(n),eu(numedges),ret,s={source};
	d[source]++; // to allow Euler paths, not just cycles
	while(!s.empty()){
		I x=s.back(),y,e,&it=its[x],end=sz(graph[x]);
		if(it==end){ret.push_back(x);s.pop_back();continue;}
		tie(y,e)=graph[x][it++];
		if(!eu[e]){
			d[x]--,d[y]++;eu[e]=1;s.push_back(y);
		}}
	for (I x:d)if(x<0 or sz(ret)!=numedges+1)return {};
	return {ret.rbegin(),ret.rend()};
}