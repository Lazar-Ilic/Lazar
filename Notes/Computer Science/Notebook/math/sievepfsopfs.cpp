VL isprime(1000001,true);
VL primes;
VL spf(1000001);
VSET pfs(1000001);
VSET opfs(1000001);
Z sieve(I a){
    isprime[0]=isprime[1]=false;
    I c;
    for(L b=2;b<a;b++){
        if(isprime[b]){
            primes.add(b);
            spf[b]=b;
        }
        c=sz(primes);
        for(L d=0;d<c && b*primes[d]<a && primes[d]<=spf[b];d++){
            isprime[b*primes[d]]=false;
            spf[b*primes[d]]=primes[d];
        }
    }
    for(L b=2;b<a;b++){
        if(isprime[b]){
            pfs[b].insert(b);
            opfs[b].insert(b);
        }
        else{
            SET aset=pfs[b/spf[b]];
            aset.insert(spf[b]);
            pfs[b]=aset;
            SET bset=opfs[b/spf[b]];
            if(bset.count(spf[b])==1){bset.erase(bset.find(spf[b]));}
            else{bset.insert(spf[b]);}
            opfs[b]=bset;
        }
    }
}