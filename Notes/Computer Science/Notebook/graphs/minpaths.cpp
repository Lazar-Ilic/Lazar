VP graph[2000];// adjacency list of {neighbour, edge weight}
L distances[2000];
I numvertices;
Z minpaths(I source){
	for(I a=0;a<numvertices;++a){
		distances[a] = LLONG_MAX;
	}
	priority_queue<PLI,vector<PLI>,greater<PLI>> aq;
	distances[source]=0;
	aq.push({0,source});
	while(sz(aq)){
		L adistance;
		I node;
		tie(adistance,node)=aq.top();
		aq.pop();
		if(adistance!=distances[node])continue;
		for (P ap:graph[node]){
			if(adistance+ap.second<distances[ap.first]){
				aq.push({distances[ap.first] = adistance+ap.second, ap.first});
			}
		}
	}
}
//VP graph[] {neighbor, edge weight}, L distances[], I numvertices, Z minpaths(I source)