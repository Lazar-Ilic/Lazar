VB sievesegmented(L lll,L rrr){ // Competitive-Programming Algorithms
	L lim=sqrt(rrr);
	VB mark(lim+1,false);
	VL primes;
	for(L i=2;i<=lim;++i){
		if(!mark[i]){
			primes.emplace_back(i);
			for (L j=i*i;j<=lim;j+=i)mark[j]=true;
		}
	}
	VB isPrime(rrr-lll+1,true);
	for(L i:primes)for(L j=max(i*i,(lll+i-1)/i*i);j<=rrr;j+=i)isPrime[j-lll]=false;
	if(lll==1)isPrime[0]=false;
	return isPrime;
}