    in>>a>>b>>c;
    MLI amli;
    VV graph(a);
    g=0;
    for(d=0;d<b;d++){
        in>>al>>bl;
        if(!amli.count(al)){
            amli.insert({al,g});
            g++;
        }
        if(!amli.count(bl)){
            amli.insert({bl,g});
            g++;
        }
        graph[amli[al]].add(amli[bl]);
    }
    av=topsort(graph);
    bv=V(a);
    for(d=0;d<a;d++){
        bv[av[d]]=d;
    }
    for(d=0;d<a;d++){
        in>>al;
        if(amli.count(al))cv.add(bv[amli[al]]);
    }
    out<<2*(a-sz(lis(cv)))<<nl;