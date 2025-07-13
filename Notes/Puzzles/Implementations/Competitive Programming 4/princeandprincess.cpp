    casenumber++;
    out<<"Case "<<casenumber<<": ";
    in>>a>>b>>c;
    av=V(a*a+1);
    for(d=1;d<=b+1;d++){
        in>>e;
        av[e]=d;
    }
    for(d=1;d<=c+1;d++){
        in>>e;
        if(av[e]!=0)bv.add(av[e]);
    }
    out<<sz(lis(bv))<<nl;