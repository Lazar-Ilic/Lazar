    in>>as;
    suffixarray asfx(as);
    av=asfx.sfxarray;
    bv=asfx.lcp;
    RMQ armq(bv);
    cv=V(sz(as));
    for(b=1;b<=sz(as);b++){
        cv[av[b]]=b;
    }
    in>>a;
    for(b=0;b<a;b++){
        in>>c>>d;
        out<<armq.query(min(cv[c],cv[d])+1,max(cv[c],cv[d])+1)<<nl;
    }