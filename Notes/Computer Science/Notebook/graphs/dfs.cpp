VV graph;
VB processed;

Z dfs(I a){
	processed[a]=1;
	for(I b:graph[a]){
		if(!processed[b]){
			dfs(b);
		}
	}
}

	in>>a;

	graph=VV(a+1,V(0));
	processed=VB(a+1,false);

//----------

VV graph;
VB processed;
//V subtreesize;
//V dfslevel;
//V dfsorder;
//V dfsinoutorder;
Z dfs(I a){
	processed[a]=1;
	//dfsorder.add(a);
	//dfsinoutorder.add(a);
	I c=1;
	for(I b:graph[a]){
		if(!processed[b]){
			//dfslevel[b]=1+dfslevel[a];
			dfs(b);
			c+=subtreesize[b];
		}
	}
	subtreesize[a]=c;
	//dfsinoutorder.add(a);
}

	in>>a;

	graph=VV(a+1,V(0));
	processed=VB(a+1,false);
	//subtreesize=V(a+1,0);
	//dfslevel=V(a+1,0);
	//V dfsoutorder=dfsorder;reverse(all(dfsoutorder)); // Can loop through in reverse.

//----------

vector<bool> processed(graph.size(),0);
stack<int> ast;
int root=0,a=0;
ast.push(root);
while(!ast.empty()){
	a=ast.top();
	ast.pop();
	processed[a]=1;
	for(auto neighbour:graph[a]){
		if(!processed[neighbour]){
			ast.push(neighbour);
		}
	}
}