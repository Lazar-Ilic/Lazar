// Description: Recovers any $n$-order linear recurrence relation from the first $2n$ terms of the recurrence. Useful for guessing linear recurrences after brute-forcing the first terms. Should work on any field, but numerical stability for floats is not guaranteed. Output will have size <=n
// Usage: recurrence({0, 1, 1, 3, 5, 11}) // {1, 2}
// Time: O(N^2)
const L mod=1000000007; // faster if const
L modpower(L a,L b){//Lucian Bicsi
	L ans=1;
	for(;b;a=a*a%mod,b/=2)
		if(b&1)ans=ans*a%mod;
	return ans;
}
VL recurrence(VL s){
	int n=sz(s),z=0,m=0;
	VL y(n),v(n),w;
	y[0]=v[0]=1;
	L b=1;
	rep(i,0,n){++m;
		L d=s[i]%mod;
		rep(j,1,z+1)d=(d+y[j]*s[i-j])%mod;
		if(!d)continue;
		w=y; L coef=d*modpower(b,mod-2)%mod;
		rep(j,m,n) y[j]=(y[j]-coef*v[j-m])%mod;
		if(2*z>i)continue;
		z=i+1-z;v=w;b=d;m=0;
	}
	y.resize(z+1);y.erase(y.begin());
	for(L& x:y)x=(mod-x)%mod;
	return y;
}