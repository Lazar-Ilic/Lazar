    in>>a;
    av=V(a);
    bv=V(a);
    cv=V(a);
    for(b=0;b<a;b++){
        in>>av[b];
        bv[av[b]-1]=b;
    }
    for(b=0;b<a;b++){
        in>>c;
        cv[b]=bv[c-1];
    }
    out<<2<<" "<<1+sz(lis(cv))<<nl;