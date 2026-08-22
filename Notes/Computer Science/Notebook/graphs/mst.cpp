// Time : O(V^2)
I num;
VV graph; // adjacency matrix of graph
//V spantree[1000000];
const I inf=1000000001; // weight inf means there is no edge
STR edge{I w=inf,to=-1;};
L MST(){
    L totalweight=0;
    VB selected(num,false);
    vector<edge> mmm(num);
    mmm[0].w=0;
    for(I i=0;i<num;++i){
        I v=-1;
        for(I j=0;j<num;++j){
            if(!selected[j] and (v==-1 or mmm[j].w<mmm[v].w))v=j;
        }
        if(mmm[v].w==inf)return -1;
		selected[v]=true;
        totalweight+=mmm[v].w;
        if(mmm[v].to!=-1){
			//spantree[v].add(mmm[v].to);
			//spantree[mmm[v].to].add(v);
			//if(v==target)output=;
		}
        for(I to=0;to<num;++to){
            if(graph[v][to]<mmm[to].w)mmm[to]={graph[v][to],v};
        }
    }
    return totalweight;
}

//----------

	in>>a>>b;
	p=b;
	avl=VL(a);
	num=a;
	graph=VV(a,V(a,inf));
	for(c=0;c<a;c++)in>>avl[c];
	for(c=0;c<a-1;c++){
		for(d=c+1;d<a;d++){
			graph[c][d]=-((exp(avl[c],avl[d])+exp(avl[d],avl[c]))%b);
			graph[d][c]=-((exp(avl[c],avl[d])+exp(avl[d],avl[c]))%b);
		}
	}
	al=MST();
	out<<-al<<nl;

//--------------------------------------------------------------------

// Time: O(E log V)
//V spantree[100000];
const I inf=1000000001;
STR edge{
    I w=inf,to=-1;
    B operator<(edge const& other)const{
        return make_pair(w,to)<make_pair(other.w,other.to);
    }
};
I num;
vector<vector<edge>> graph;
L MST(){
    L totalweight=0;
    vector<edge> mmm(num);
    mmm[0].w=0;
    set<edge> q;
    q.insert({0,0});
    VB selected(num,false);
    for(I i=0;i<num;++i){
        if(q.empty())return -1;
		I v=q.begin()->to;
        selected[v]=true;
        totalweight+=q.begin()->w;
        q.erase(q.begin());
        if(mmm[v].to!=-1){
			//spantree[v].add(mmm[v].to);
			//spantree[mmm[v].to].add(v);
			//if(v==target)output=;
		}
        for(edge e:graph[v]){
            if(!selected[e.to] and e.w<mmm[e.to].w){
                q.erase({mmm[e.to].w,e.to});
                mmm[e.to]={e.w,v};
                q.insert({e.w,e.to});
            }
        }
    }
    return totalweight;
}

//--------------------------------------------------------------------

Z az(){
	in>>a>>b;
	num=b;
	graph.clear();
	graph=vector<vector<edge>>(b);
	for(c=0;c<b*(b-1)/2;c++){
		in>>d>>e>>f;
		edge aedge;
		aedge.w=f;
		aedge.to=e;
		graph[d].add(aedge);
		aedge.to=d;
		graph[e].add(aedge);
	}
	al=MST();
	if(a>=al+b)out<<"yes"<<nl;
	else out<<"no"<<nl;
}

//--------------------------------------------------------------------

// Time: O(E log V)
V parent,rank;
Z makeset(I v){
    parent[v]=v;
    rank[v]=0;
}
I findset(I v){
    if(v==parent[v])return v;
    return parent[v]=findset(parent[v]);
}
Z unionsets(I a,I b){
    a=findset(a);
    b=findset(b);
    if(a!=b){
        if(rank[a]<rank[b])swap(a, b);
        parent[b]=a;
        if(rank[a]==rank[b])rank[a]++;
    }
}
STR edge{
    I u,v,weight;
    B operator<(edge const& other){
        return weight<other.weight;
    }
};
I num;
vector<edge> edges;
L cost=0;
vector<edge> result;
parent.resize(num);
rank.resize(num);
for(I i=0;i<num;i++)makeset(i);
sort(edges.begin(),edges.end());
for(edge e:edges){
    if(findset(e.u)!=findset(e.v)){
        cost+=e.weight;
        result.push_back(e);
        unionsets(e.u,e.v);
    }
}

//--------------------------------------------------------------------

// Time: O(V^2) for doubles
I num;
VVD graph; // adjacency matrix of graph
//V spantree[100000];
const I inf=1000000000; // weight inf means there is no edge
STR edge{
	D w=inf;
	I to=-1;
};
D MST(){
    D totalweight=0;
    VB selected(num,false);
    vector<edge> mmm(num);
    mmm[0].w=0;
    for(I i=0;i<num;++i){
        I v=-1;
        for(I j=0;j<num;++j){
            if(!selected[j] and (v==-1 or mmm[j].w<mmm[v].w))v=j;
        }
		if(mmm[v].w==inf)return -1;
		selected[v]=true;
        totalweight+=mmm[v].w;
        if(mmm[v].to!=-1){
			//spantree[v].add(mmm[v].to);
			//spantree[mmm[v].to].add(v);
			//if(v==target)output=;
		}
        for(I to=0;to<num;++to){
            if(graph[v][to]<mmm[to].w)mmm[to]={graph[v][to],v};
        }
    }
    return totalweight;
}