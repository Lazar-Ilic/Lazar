// Description: Tonelli-Shanks algorithm for modular square roots. Finds x s.t. x^2=a(mod p) (-x gives the other solution).
// Time: O(log^2 p) worst case, O(log p) for most p
const L mod=1000000007; // faster if const
L modpower(L a,L b){//Simon Lindholm
	L ans=1;
	for(;b;a=a*a%mod,b/=2)
		if(b&1)ans=ans*a%mod;
	return ans;
}
L sqrt(L a,L z){ // mod z
	a%=z;if(a<0)a+=z;
	if(a==0)return 0;
	assert(modpow(a,(z-1)/2,z)==1); // else no solution
	if(z%4==3)return modpow(a,(z+1)/4,z);
	// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if z % 8 == 5
	L s=z-1,n=2;
	I r=0,m;
	while(s%2==0)
		++r,s/=2;
	/// find a non-square mod z
	while(modpow(n,(z-1)/2,z)!=z-1)++n;
	L x=modpow(a,(s+1)/2,z);
	L b=modpow(a,s,z),g=modpow(n,s,z);
	for(;;r=m){
		L t=b;
		for(m=0;m<r and t!=1;++m)
			t=t*t%z;
		if(m==0)return x;
		L gs=modpow(g,1LL<<(r-m-1),z);
		g=gs*gs%z;
		x=x*gs%z;
		b=b*g%z;
	}
}