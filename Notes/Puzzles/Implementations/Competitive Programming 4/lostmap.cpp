    in>>a;
    num=a;
    graph.clear();
    graph=VV(a,V(a));
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            in>>graph[b][c];
        }
    }
    MST();
    for(P ap:output){
        out<<ap.first+1<<" "<<ap.second+1<<nl;
    }