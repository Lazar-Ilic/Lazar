// Description: Deterministic Miller-Rabin primality test. Guaranteed to work for numbers up to 7*10^18; for larger numbers, use Python and extend A pseudorandomly.
// Time: 7 times the complexity of a^b [modulo mod]
L modmultiply(L a,L b,L mod){//chilli,c1729,Simon Lindholm
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return(n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){ // ^ count trailing zeroes
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}