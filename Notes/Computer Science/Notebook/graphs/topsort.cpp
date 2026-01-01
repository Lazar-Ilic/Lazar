// Description: Topological sorting. Given is an oriented graph. Output is an ordering of vertices, such that there are edges only from left to right. If there are cycles, the returned list will have size smaller than n: nodes reachable from cycles will not be returned. Unique and complete if and only if maximal path has length V - 1. This uniqueness check is as easy as checking that in each decision tree branching step essentially the decision is precisely unique and forced.
// Time: O[E + V]
B uniquesolution;
V topsort(const VV& graph){
	uniquesolution=1;
	V indegree(sz(graph)),ret;
	for(auto& li:graph)for(I x:li)indegree[x]++;
	Q q; // use priority_queue for lexicographically largest answer
	rep(i,0,sz(graph)) if (indegree[i] == 0) q.push(i);
	while(!q.empty()){
		if(sz(q)!=1)uniquesolution=0;
		I i=q.front(); // top() for priority_queue
		ret.push_back(i);
		q.pop();
		for(I x:graph[i])if(--indegree[x]==0)q.push(x);
	}
	return ret;
}