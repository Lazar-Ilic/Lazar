// Description: Calculates determinant using modular arithmetics. Modulos can also be removed to get a pure-Ieger version.
// Time: O(N^3)
const L mod=12345;
L determinant(VVL& a){
	I n=sz(a);L ans=1;
	rep(i,0,n){
		rep(j,i+1,n){
			while(a[j][i]!=0){ // gcd step
				L t=a[i][i]/a[j][i];
				if(t) rep(k,i,n)
					a[i][k]=(a[i][k]-a[j][k]*t)%mod;
				swap(a[i],a[j]);
				ans*=-1;
			}
		}
		ans=ans*a[i][i]%mod;
		if(!ans)return 0;
	}
	return (ans+mod)%mod;
}