// Description: Prime sieve for generating all primes smaller than limit.
// Time: limit=1e9 ~1.5s
const I limit=1e6;
bitset<limit> isprime;
V sieve(){//Jakob Kogler,chilli,pajenegod
	const I z=(I)round(sqrt(limit)),r=limit/2;
	V pr={2},sieve(z+1);pr.reserve(I(limit/log(limit)*1.1));
	VP cp;
	for(I i=3;i<=z;i+=2)if(!sieve[i]){
		cp.push_back({i,i*i/2});
		for(I j=i*i;j<=z;j+=2*i)sieve[j]=1;
	}
	for(I l=1;l<=r;l+=z){
		array<B,z> b{};
		for(auto &[p,idx]:cp)
			for(I i=idx;i<z+l;idx=(i+=p))b[i-l]=1;
		rep(i,0,min(z,r-l))
			if(!b[i])pr.push_back((l+i)*2+1);
	}
	for(I i:pr)isprime[i]=1;
	return pr;
}