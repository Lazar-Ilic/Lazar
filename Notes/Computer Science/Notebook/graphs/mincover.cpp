// Description: Finds a minimum vertex cover in a bipartite graph. The size is the same as the size of a maximum matching, and the complement is a maximum independent set.
// Status: stress-tested
B find(I j,VV& graph,V& right,V& visited){//Johan Sannemo,Simon Lindholm
	if (right[j] == -1) return 1;
	visited[j] = 1; I di = right[j];
	for(I e:graph[di])
		if(!visited[e] and find(e,graph,right,visited)){
			right[e]=di;
			return 1;
		}
	return 0;
}
I dfsmatch(VV& graph,V& right){ // to and V(m,-1) per usual
	V visited;
	rep(i,0,sz(graph)){
		visited.assign(sz(right),0);
		for(I j:graph[i])
			if(find(j,graph,right,visited)){
				right[j] = i;
				break;
			}
	}
	return sz(right)-(I)count(all(right),-1);
}
V mincover(VV& graph,I n,I m){
	V match(m,-1);
	I res=dfsmatch(graph,match);
	VB lfound(n,true),seen(m);
	for(I it:match)if(it!=-1)lfound[it]=false;
	V q,cover;
	rep(i,0,n)if(lfound[i])q.push_back(i);
	while(!q.empty()){
		I i=q.back();q.pop_back();
		lfound[i]=1;
		for(I e:graph[i])if(!seen[e] and match[e]!=-1){
			seen[e]=true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n)if(!lfound[i])cover.push_back(i);
	rep(i,0,m)if(seen[i])cover.push_back(n+i);
	assert(sz(cover)==res);
	return cover;
}