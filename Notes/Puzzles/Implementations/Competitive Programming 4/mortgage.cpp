    in>>al>>bl>>cl>>ad;
    while(!(al==0 and bl==0 and cl==0 and ad==D(0))){
        cl*=12;
        ad/=D(12.0);
        ad+=100.0;
        ad/=D(100.0);
        if(D(al)*(ad-1.0)>D(bl) or (ad==D(1) and cl*bl<al) or D(al)/D(bl)*(ad-1.0)>D(1.0)-(pow(ad,-cl)))out<<"NO"<<nl;
        else out<<"YES"<<nl;
        in>>al>>bl>>cl>>ad;
    }