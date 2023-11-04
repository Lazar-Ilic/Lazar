    in>>a;
    av=sieve();
    for(b=0;b<a;b++){
        in>>c;
        if(c==4){
            out<<"4 has 1 representation(s)"<<nl<<"2+2"<<nl<<nl;
        }
        else{
            d=0;
            e=0;
            f=0;
            avp.clear();
            while(av[d]+av[e]<=c)e++;
            e--;
            while(d<=e){
                if(av[d]+av[e]==c){
                    avp.add({av[d],av[e]});
                    d++;
                    e--;
                }
                else if(av[d]+av[e]<c)d++;
                else e--;
            }
            out<<c<<" has "<<sz(avp)<<" representation(s)"<<nl;
            for(P ap:avp){
                out<<ap.first<<"+"<<ap.second<<nl;
            }
            out<<nl;
        }
    }