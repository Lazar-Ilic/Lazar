struct SCC{//Benjamin Qi
	I size;
    VV adj, radj;
	V todo, components, componentof;
    VB visited;
	Z build(I a){
        size=a;
        adj=VV(size,V(0));
        radj=VV(size,V(0));
        componentof=V(size,-1);
        visited=VB(size);
	}
	Z addedge(I a,I b){
        adj[a].add(b);
        radj[b].add(a);
    }
	Z dfs(I a){
		visited[a]=1;
        for(auto ay:adj[a]){
            if(!visited[ay])dfs(ay);
        }
        todo.add(a);
    }
	Z dfs2(I a,I b){
		componentof[a]=b;
        for(auto ay:radj[a]){
            if(componentof[ay]==-1)dfs2(ay,b);
        }
	}
	Z generate(I a){
        I b;
        for(b=0;b<=a;b++){
            if(!visited[b])dfs(b);
        }
        reverse(all(todo));
        for(auto ay:todo){
            if(componentof[ay]==-1){
                dfs2(ay,ay);
                components.add(ay);
            }
        }
	}
};

//--------------------------------------------------------------------

Z az(){
    SCC assc;
	assc.build(5);
	assc.addedge(1,2);
	assc.addedge(0,1);
	assc.addedge(2,1);
	assc.generate(4);
	out<<sz(assc.components)<<nl;
	out<<assc.componentof[0]<<nl;//1
	out<<assc.componentof[1]<<nl;//1
	out<<assc.componentof[2]<<nl;//1
	out<<assc.componentof[3]<<nl;//3
	out<<assc.componentof[4]<<nl;//4
	//components are given by representative element

	//----------

	in>>a>>b;
	SCC assc;
	assc.build(a);
	for(c=0;c<b;c++){
		in>>d>>e;
		assc.addedge(d-1,e-1);
		assc.addedge(e-1,d-1);
	}
	assc.generate(a-1);
	out<<sz(assc.components)<<nl;
	/*
	out<<assc.componentof[0]<<nl;//1
	out<<assc.componentof[1]<<nl;//1
	out<<assc.componentof[2]<<nl;//1
	out<<assc.componentof[3]<<nl;//3
	out<<assc.componentof[4]<<nl;//4
	*/
}