// Description: Invert matrix $A$. Returns rank; result is stored in $A$ unless singular (rank < n). Can easily be extended to prime moduli; for prime powers, repeatedly set $A^{-1} = A^{-1} (2I - AA^{-1})\  (\text{mod }p^k)$ where $A^{-1}$ starts as the inverse of A mod p, and k is doubled in each step.
// Time: O(n^3)
I matrixinverse(VVD& z){//Max Bennedich
	I n=sz(z);V col(n);
	VVD tmp(n,VD(n));
	rep(i,0,n)tmp[i][i]=1,col[i]=i;
	rep(i,0,n){
		I r=i,c=i;
		rep(j,i,n)rep(k,i,n)
			if(fabs(z[j][k])>fabs(z[r][c]))r=j,c=k;
		if(fabs(z[r][c])<1e-12)return i;
		z[i].swap(z[r]);tmp[i].swap(tmp[r]);
		rep(j,0,n)
			swap(z[j][i],z[j][c]),swap(tmp[j][i],tmp[j][c]);
		swap(col[i],col[c]);
		D v=z[i][i];
		rep(j,i+1,n){
			D f=z[j][i]/v;
			z[j][i]=0;
			rep(k,i+1,n)z[j][k]-=f*z[i][k];
			rep(k,0,n)tmp[j][k]-=f*tmp[i][k];
		}
		rep(j,i+1,n)z[i][j]/=v;
		rep(j,0,n)tmp[i][j]/=v;
		z[i][i]=1;
	}
	// forget z at this point, just eliminate tmp backward
	for(I i=n-1;i>0;--i)rep(j,0,i){
		D v=z[j][i];
		rep(k,0,n)tmp[j][k]-=v*tmp[i][k];
	}
	rep(i,0,n)rep(j,0,n)z[col[i]][col[j]]=tmp[i][j];
	return n;
}