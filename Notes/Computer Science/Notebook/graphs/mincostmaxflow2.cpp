STR edge{
    I u,v;L capacity,cost;
    edge(I u,I v,L capacity,L cost):u(u),v(v),capacity(capacity),cost(cost){}
}; 
STR MCMF{
    I n,s,t;L flow, cost;VV graph;vector<edge> e;VL distance;V parent;
    MCMF(I nn){n=nn;graph.assign(n,V());}
    Z addedge(I u,I v,L capacity,L cost,B directed=true){
        graph[u].push_back(e.size());
        e.push_back(edge(u,v,capacity,cost));
        graph[v].push_back(e.size());
        e.push_back(edge(v,u,0,-cost));
        if(!directed)addedge(v,u,capacity,cost,true);
    }
    PL generate(I ss,I tt){
        s=ss;t=tt;
        flow=0,cost=0;
        while(SPFA()){
            flow+=sendflow(t,1L<<62);
        }
        return make_pair(flow,cost);
    }
    B SPFA(){
        parent.assign(n,-1);
        distance.assign(n,1L<<62);distance[s]=0;
        V queuetime(n,0);queuetime[s]=1;
        VB inqueue(n,0);inqueue[s]=true;
        Q q;q.push(s);
        B negativecycle=false;
        while(!q.empty() and !negativecycle){
            I u=q.front();q.pop();inqueue[u]=false;
            for(I i=0;i<graph[u].size();i++){
                I eIdx=graph[u][i];
                I v=e[eIdx].v;L w=e[eIdx].cost,capacity=e[eIdx].capacity;
                if(distance[u]+w<distance[v] and capacity>0){
                    distance[v]=distance[u]+w;
                    parent[v]=eIdx;
                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v]=true;
                        if(queuetime[v]==n+2){
                            negativecycle=true;
                            break;
                        }
                    }
                }
            }
        }
        return distance[t]!=(1L<<62);
    }
    L sendflow(I v,L curflow){
        if(parent[v]==-1)return curflow;
        I eIdx=parent[v];
        I u=e[eIdx].u;L w=e[eIdx].cost;
        L f=sendflow(u,min(curflow,e[eIdx].capacity));
        cost+=f*w;
        e[eIdx].capacity-=f;
        e[eIdx^1].capacity+=f;
        return f;
    }
};