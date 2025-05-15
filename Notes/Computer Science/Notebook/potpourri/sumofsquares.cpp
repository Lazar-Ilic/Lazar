ULL modmultiply(ULL a,ULL b,ULL mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*ULL(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
ULL modpower(ULL a,ULL b,ULL mod){
	ULL ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(ULL n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	ULL aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(ULL a:aaa){
		ULL ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
ULL pollard(ULL n){
	auto f=[n](ULL x){return modmultiply(x,x,n)+1;};
	ULL x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VULL factor(ULL n){
	if(n==1)return{};
	if(isprime(n))return{n};
	ULL x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	return l;
}
ULL sumofsquares(ULL aull){
	if(aull==0)return 1;
	VULL avull=factor(aull);
	map<ULL,I> freq;
	ULL bull=4;
	for(ULL cull:avull)freq[cull]++;
	for(auto aa:freq){
		if(aa.first%4==1)bull=bull*(1+aa.second);
		else if(aa.first%4==3 and aa.second%2==1)return 0;
	}
	//return bull;
	ULL dull=0;
	if(aull==sqrt(aull)*sqrt(aull) or (aull%2==0 and (aull/2)==sqrt(aull/2)*sqrt(aull/2))){
		bull-=4;
		dull++;
	}
	dull+=bull/8;
	return dull;
}