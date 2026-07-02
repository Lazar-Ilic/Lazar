VV graph;
VB processed;
V bfsparent;
V bfslevel;
V bfslevel2;
VV bfslevels;

Z bfs(I a){
	Q aq;
	I b;
	aq.push(a);
	processed[a]=1;
	while(!aq.empty()){
		b=aq.front();
		aq.pop();
		for(I c:graph[b]){
			if(!processed[c]){
				aq.push(c);
				processed[c]=1;
				bfsparent[c]=b;
				bfslevel[c]=1+bfslevel[b];
			}
		}
	}
}

	in>>a;

	graph=VV(a+1,V(0));
	processed=VB(a+1,false);
	bfsparent=V(a+1);
	bfslevel=V(a+1);
	bfslevel2=V(a+1);
	bfslevels=VV(a+1,V(0));

//----------

vector<bool> processed(a,0);
V distances(a,0);
V parents(a,0);
VV children(a,V(0));
VV levels(a,V(0));
levels[0].add(0);
int root=0,aaa=0;
aq.push(root);
processed[root]=1;
while(!aq.empty()){
	aaa=aq.front();
	aq.pop();
	for(auto neighbour:graph[aaa]){
		if(!processed[neighbour]){
			aq.push(neighbour);
			processed[neighbour]=1;
			children[aaa].add(neighbour);
			parents[neighbour]=aaa;
			distances[neighbour]=distances[aaa]+1;
			levels[distances[aaa]+1].add(neighbour);
		}
	}
}

// This code is fairly useful and should usually get ACcepted for Bottoms Up Tree Dynamic Programming tasks in Competitive Programming but may be quite suboptimal from a memory perspective at the very least in a workplace setting.

//----------

vector<bool> processed(graph.size(),0);
V distances(graph.size(),0);
queue<int> aq;
int root=0,a=0;
aq.push(root);
processed[root]=1;
while(!aq.empty()){
	a=aq.front();
	aq.pop();
	for(auto neighbour:graph[a]){
		if(!processed[neighbour]){
			aq.push(neighbour);
			processed[neighbour]=1;
			distances[neighbour]=distances[a]+1;
		}
	}
}

//----------

	VVP graph;
	graph=VVP(c,VP(0));
	for(d=0;d<c-1;d++){
		in>>e>>f>>g;
		e--;f--;
		graph[e].add({f,g});
		graph[f].add({e,g});
	}
	av=V(c);
	auset.insert(0);
	VB processed(c,0);
	processed[a]=1;
	QV aqv;
	for(auto appp:graph[a]){
		if(appp.first!=b)aqv.push({a,appp.first,appp.second});
		else if(appp.first==b and appp.second==0){
			out<<"YES"<<nl;
			return;
		}
	}
	while(!aqv.empty()){
		bv=aqv.front();
		processed[bv[1]]=1;
		aqv.pop();
		av[bv[1]]=(av[bv[0]] bx bv[2]);
		auset.insert(av[bv[1]]);
		for(auto neighbour:graph[bv[1]]){
			if(!processed[neighbour.first] and neighbour.first!=b){
				aqv.push({bv[1],neighbour.first,neighbour.second});
			}
			else if(!processed[neighbour.first] and neighbour.first==b){
				if((av[bv[1]] bx neighbour.second)==0){
					out<<"YES"<<nl;
					return;
				}
			}
		}
	}
	cv=V(c);
	processed=VB(c,0);
	processed[b]=1;
	for(auto appp:graph[b]){
		aqv.push({b,appp.first,appp.second});
	}
	while(!aqv.empty()){
		bv=aqv.front();
		processed[bv[1]]=1;
		aqv.pop();
		cv[bv[1]]=(cv[bv[0]] bx bv[2]);
		if(auset.count(cv[bv[1]])){
			out<<"YES"<<nl;
			return;
		}
		for(auto neighbour:graph[bv[1]]){
			if(!processed[neighbour.first]){
				aqv.push({bv[1],neighbour.first,neighbour.second});
			}
		}
	}