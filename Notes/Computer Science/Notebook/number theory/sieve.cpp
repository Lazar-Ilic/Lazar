// Description: Prime sieve for generating all primes up to a certain limit. isprime[i] is true iff i is a prime.
// Time: lim=100000000 ~0.8s. Runs 30% faster if only odd indices are stored
const I MAX_PR=5000000;
bitset<MAX_PR> isprime;
V sieve(I lim){//Håkan Terelius
	isprime.set();isprime[0]=isprime[1]=0;
	for(I i=4;i<lim;i+=2)isprime[i]=0;
	for(I i=3;i*i<lim;i+=2)if(isprime[i])
		for(I j=i*i;j<lim;j+=i*2)isprime[j]=0;
	V pr;
	rep(i,2,lim)if(isprime[i])pr.push_back(i);
	return pr;
}