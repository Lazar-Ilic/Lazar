    in>>a>>b;
    c=0;
    d=0;
    ad=0;
    f=0;
    for(g=1;g<=a;g++){
        in>>h>>i;
        ad+=sqrt((h-c)*(h-c)+(i-d)*(i-d));
        c=h;
        d=i;
        if(ad<=b and isprime(g))f=g;
    }
    out<<f<<nl;