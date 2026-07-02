    av=V(12);
    in>>z;
    for(a=0;a<12;a++){
        in>>av[a];
    }
    RMQ armq(av);
    c=0;
    for(a=1;a<12;a++){
        for(b=a+1;b<12;b++){
            d=armq.query(a,b);
            if(d>av[a-1] and d>av[b])c++;
        }
    }
    out<<z<<" "<<c<<nl;