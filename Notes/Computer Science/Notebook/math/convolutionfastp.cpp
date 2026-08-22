// Number Theoretic Transformation. N must be a power of 2. Useful for convolution modulo specific nice primes of the form [2^a * b+1], where the convolution result has size at most 2^a. For arbitrary modulo take this over multiple distinct nice primes and execute an upstream downstream merge modulus call with the Chinese Remainder Theorem or see FFTMod.
// Inputs must be in [0, mod).
// Time: O[N * log [N]]
const L mod=(119<<23)+1,root=62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
L modpower(L a,L b){
	L ans=1;
	for(;b;a=a*a%mod,b/=2)
		if(b&1)ans=ans*a%mod;
	return ans;
}
Z ntt(VL &a){//chilli
	I n=sz(a),f=31-__builtin_clz(n);
	static VL rt(2,1);
	for(static I k=2,s=2;k<n;k*=2,s++){
		rt.resize(n);
		L z[]={1,modpow(root,mod>>s)};
		rep(i,k,2*k)rt[i]=rt[i/2]*z[i&1]%mod;
	}
	V rev(n);
	rep(i,0,n)rev[i]=(rev[i/2]|(i&1)<<f)/2;
	rep(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(I k=1;k<n;k*=2)
		for(I i=0;i<n;i+=2*k)rep(j,0,k){
			L z=rt[j+k]*a[i+j+k]%mod,&ai=a[i+j];
			a[i+j+k]=ai-z+(z>ai?mod:0);
			ai+=(ai+z>=mod?z-mod:z);
		}
}
VL convolution(const VL &a,const VL &b){
	if(a.empty() or b.empty())return {};
	I s=sz(a)+sz(b)-1,e=32-__builtin_clz(s),n=1<<e;
	I inv=modpow(n,mod-2);
	VL c(a),d(b),out(n);
	c.resize(n),d.resize(n);
	ntt(c),ntt(d);
	rep(i,0,n)out[-i&(n-1)]=(L)c[i]*d[i]%mod*inv%mod;
	ntt(out);
	return {out.begin(),out.begin()+s};
}
