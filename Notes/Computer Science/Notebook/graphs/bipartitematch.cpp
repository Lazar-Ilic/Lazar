//Description: Fast bipartite matching algorithm. Graph graph should be a list of neighbors of the left partition, and right should be a vector full of -1's of the same size as the right partition. Returns the size of the matching. right[i] will be the match for vertex $i$ on the right side, or -1 if it's not matched.
// Usage: V right(m,-1);bipartitematch(g,right);
// Time: O(E * V^(1/2))
B dfs(I a,I left,VV& graph,V& right,V& aaa,V& bbb){//Chen Xing
	if(aaa[a]!=left)return 0;
	aaa[a]=-1;
	for(I b :graph[a])if(bbb[b]==left+1){
		bbb[b]=0;
		if(right[b]==-1||dfs(right[b],left+1,graph,right,aaa,bbb))
			return right[b]=a,1;
	}
	return 0;
}
I bipartitematch(VV& graph,V& right){ // list of neighbors, V(m,-1) matches
	I res=0;
	V aaa(graph.size()),bbb(right.size()),cur,next;
	for(;;){
		fill(all(aaa),0);
		fill(all(bbb),0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (I a :right)if(a!=-1)aaa[a]=-1;
		rep(a,0,sz(graph))if(aaa[a]==0)cur.push_back(a);
		/// Find all layers using bfs.
		for (I lay=1;;lay++){
			B islast=0;
			next.clear();
			for(I a:cur)for(I b:graph[a]){
				if(right[b]==-1){
					bbb[b]=lay;
					islast=1;
				}
				else if(right[b]!=a && !bbb[b]){
					bbb[b]=lay;
					next.push_back(right[b]);
				}
			}
			if(islast)break;
			if(next.empty())return res;
			for(I a:next)aaa[a]=lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(graph))
			res+=dfs(a,0,graph,right,aaa,bbb);
	}
}