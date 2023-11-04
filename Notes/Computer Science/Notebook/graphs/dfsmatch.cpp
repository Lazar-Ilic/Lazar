// Description: Simple bipartite matching algorithm. Graph graph should be a list of neighbors of the left partition, and $btoa$ should be a vector full of -1's of the same size as the right partition. Returns the size of the matching. right[i] will be the match for vertex i on the right side, or -1 if it's not matched.
// Time: O(E*V)
// Usage: V right(m,-1);dfsmatch(graph,right);
B find(I j,VV& graph,V& right,V& visited){//Lukas Polacek
	if(right[j]==-1)return 1;
	visited[j]=1;I di=right[j];
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
				right[j]=i;
				break;
			}
	}
	return sz(right)-(I)count(all(right),-1);
}