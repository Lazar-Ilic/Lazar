    VULL avull;
    ULL aull;
    in>>aull;
    while(aull!=4){
        b=1;
        avull=factor(aull);
        while(sz(avull)!=1){
            b++;
            aull=0;
            for(ULL bull:avull){
                aull+=bull;
            }
            avull=factor(aull);
        }
        out<<aull<<" "<<b<<nl;
        in>>aull;
    }