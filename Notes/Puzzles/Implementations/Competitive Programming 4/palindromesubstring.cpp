    SETS asets;
    while(getline(in,as)){
        array<V,2> ax=maxpalindromes(as);
        asets.clear();
        for(a=1;a<=sz(as)-1;a++){
            b=ax[0][a];
            while(!asets.count(as.substr(a-b,2*b)) and b>0){
                asets.insert(as.substr(a-b,2*b));
                b--;
            }
        }
        for(a=1;a<=sz(as)-2;a++){
            b=ax[1][a];
            while(!asets.count(as.substr(a-b,2*b+1)) and b>0){
                asets.insert(as.substr(a-b,2*b+1));
                b--;
            }
        }
        for(S str:asets){
            out<<str<<nl;
        }
        out<<nl;
    }