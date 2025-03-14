VL isprime(1000001,true);
VL primes;
VL spf(1000001);
Z sieve(I a){
    isprime[0]=isprime[1]=false;
    I c;
    for(L b=2;b<=a;b++){
        if(isprime[b]){
            primes.add(b);
            spf[b]=b;
        }
        c=sz(primes);
        for(L d=0;d<c && b*primes[d]<=a && primes[d]<=spf[b];d++){
            isprime[b*primes[d]]=false;
            spf[b*primes[d]]=primes[d];
        }
    }
}
L mobius[1000001];
Z mobiuses(){
    I a;
    mobius[1]=1;
    for(a=2;a<=1000000;a++){
        if(spf[a/spf[a]]==spf[a])mobius[a]=0;
        else mobius[a]=-1*mobius[a/spf[a]];
    }
}