    ULL aull,bull;
    in>>aull;
    while(aull!=0){
        bull=2*aull+1;
        while(!isprime(bull))bull++;
        out<<bull;
        if(!isprime(aull))out<<" ("<<aull<<" is not prime)";
        out<<nl;
        in>>aull;
    }