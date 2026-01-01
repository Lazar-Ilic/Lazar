    in>>a;
    num=a;
    graph.clear();
    graph=VVD(a,VD(a));
    VVD avvd;
    avvd=VVD(a,VD(2));
    for(b=0;b<a;b++){
        in>>avvd[b][0]>>avvd[b][1];
    }
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            graph[b][c]=sqrt((avvd[b][0]-avvd[c][0])*(avvd[b][0]-avvd[c][0])+(avvd[b][1]-avvd[c][1])*(avvd[b][1]-avvd[c][1]));
        }
    }
    ad=MST();
    out<<ad<<nl;