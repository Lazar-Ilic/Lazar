    in>>a>>b;
    while(!(a==0 and b==0)){
        num=a;
        graph.clear();
        output.clear();
        graph=vector<vector<edge>>(a);
        for(c=0;c<b;c++){
            in>>d>>e>>f;
            edge aedge;
            aedge.w=f;
            aedge.to=e;
            graph[d].add(aedge);
            aedge.to=d;
            graph[e].add(aedge);
        }
        al=MST();
        if(al==-1337)out<<"Impossible"<<nl;
        else{
            out<<al<<nl;
            sort(all(output));
            for(P ap:output){
                out<<ap.first<<" "<<ap.second<<nl;
            }
        }
        in>>a>>b;
    }