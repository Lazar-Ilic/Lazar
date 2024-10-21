// Description: Calculates determinant of a matrix. Destroys the matrix.
// Time: O(N^3)
D determinant(VVD& a){//Simon Lindholm
	I n=sz(a);D res=1;
	rep(i,0,n){
		I b=i;
		rep(j,i+1,n)if(fabs(a[j][i])>fabs(a[b][i]))b=j;
		if(i!=b)swap(a[i],a[b]),res*=-1;
		res*=a[i][i];
		if(res==0)return 0;
		rep(j,i+1,n){
			D v=a[j][i]/a[i][i];
			if(v!=0)rep(k,i+1,n)a[j][k]-=v*a[i][k];
		}
	}
	return res;
}