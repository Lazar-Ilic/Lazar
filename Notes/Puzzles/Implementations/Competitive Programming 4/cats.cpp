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