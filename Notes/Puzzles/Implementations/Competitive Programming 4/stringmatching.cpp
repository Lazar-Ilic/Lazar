    while(getline(in,as) and getline(in,bs)){
        U ahu=U(hashstring(as));
        hashinterval ahi(bs);
        for(a=0;a<=sz(bs)-sz(as);a++){
            if(U(ahi.gethashinterval(a,a+sz(as)-1))==ahu)out<<a<<" ";
        }
        out<<nl;
    }