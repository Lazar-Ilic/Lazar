// Description: Calculate a*b(mod mod) a^b(mod mod) for 0<=a,b<=mod<=7.2*10^18
// Time: O(1) for modmultiply, O(log b) for modpower
ULL modmultiply(ULL a,ULL b,ULL mod){
	//chilli,Ramchandra Apte,Noam527,Simon Lindholm
	L ret=a*b-mod*ULL(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
ULL modpower(ULL a,ULL b,ULL mod){
	ULL ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}