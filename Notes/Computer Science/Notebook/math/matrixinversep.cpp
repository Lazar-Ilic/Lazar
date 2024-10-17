// Description: Invert matrix $z$ modulo a prime. Returns rank; result is stored in $z$ unless singular (rank < n). For prime powers, repeatedly set $z^{-1} = z^{-1} (2I - zz^{-1})\  (\text{mod }p^k)$ where $z^{-1}$ starts as the inverse of z mod p, and k is doubled in each step.
// Time: O(n^3)
const L mod=1000000007; // faster if const
L modpower(L a,L b){//Simon Lindholm
	L ans=1;
	for(;b;a=a*a%mod,b/=2)
		if(b&1)ans=ans*a%mod;
	return ans;
}
I matrixinverse(VVL& z){
	I n=sz(z);V col(n);
	VVL tmp(n,VL(n));
	rep(i,0,n)tmp[i][i]=1,col[i]=i;
	rep(i,0,n){
		I r=i,c=i;
		rep(j,i,n)rep(k,i,n)if(z[j][k]){
			r=j;c=k;goto found;
		}
		return i;
found:
		z[i].swap(z[r]);tmp[i].swap(tmp[r]);
		rep(j,0,n)swap(z[j][i],z[j][c]),swap(tmp[j][i],tmp[j][c]);
		swap(col[i],col[c]);
		L v=modpower(z[i][i],mod-2);
		rep(j,i+1,n){
			L f=z[j][i]*v%mod;
			z[j][i]=0;
			rep(k,i+1,n)z[j][k]=(z[j][k]-f*z[i][k])%mod;
			rep(k,0,n)tmp[j][k]=(tmp[j][k]-f*tmp[i][k])%mod;
		}
		rep(j,i+1,n)z[i][j]=z[i][j]*v%mod;
		rep(j,0,n)tmp[i][j]=tmp[i][j]*v%mod;
		z[i][i]=1;
	}
	for(I i=n-1;i>0;--i)rep(j,0,i){
		L v=z[j][i];
		rep(k,0,n)tmp[j][k]=(tmp[j][k]-v*tmp[i][k])%mod;
	}
	rep(i,0,n)rep(j,0,n)
		z[col[i]][col[j]]=tmp[i][j]%mod+(tmp[i][j]<0?mod:0);
	return n;
}