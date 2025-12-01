    in>>al>>bl;
    while(!(al==0 and bl==0)){
        if(exp(bl,al,al)==bl and !isprime(al))out<<"yes"<<nl;
        else out<<"no"<<nl;
        in>>al>>bl;
    }