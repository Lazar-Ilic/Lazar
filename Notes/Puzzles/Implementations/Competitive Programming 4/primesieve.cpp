    in>>a>>b;
    av=sieve();
    c=0;
    while(av[c]<=a)c++;
    out<<c<<nl;
    for(c=0;c<b;c++){
        in>>d;
        out<<isprime[d]<<nl;
    }