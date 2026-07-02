    in>>as;
    hashinterval ahi(as);
    in>>a;
    for(b=0;b<a;b++){
        in>>c>>d;
        out<<U(ahi.gethashinterval(c,d-1))<<nl;
    }