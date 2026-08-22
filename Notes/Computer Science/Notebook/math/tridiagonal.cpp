// Description: x=tridiagonal(d,p,q,b) solves the equation system
// b0	 d0 p0 0  0  0   x0
// b1	 q0 d1 p1 0  0   x1
// b2    0  q1 d2 p2 0   x2
// b3	=. . . . . . . * x3
// .                    .
// .                    .
// .                    .
// bn-1                .xn-1
// This is useful for solving problems on the type
// ai=bi a{i-1} + ci a{i+1} + di for 1<=i<=n
// where a0, a{n+1}, bi, ci and di are known. a can then be obtained from {ai}=tridiagonal({1,-1,-1,...,-1,1},{0,c1,c2,...,cn}, {b1,b2,...,bn,0}, {a0,d1,d2,...,dn,a{n+1}}) Fails if the solution is not unique.If |di|>|pi|+|q{i-1}| for all i, or |di|>|p{i-1}|+|qi|, or the matrix is positive definite, the algorithm is numerically stable and neither \texttt{tr} nor the check for \texttt{diag[i] == 0} is needed.
// Time: O(N)
VD tridiagonal(VD diag, const VD& super,const VD& sub,VD b){
	I n=sz(b);V tr(n);//Ulf Lundstrom,Simon Lindholm
	rep(i,0,n-1){
		if(abs(diag[i])<1e-9*abs(super[i])){ // diag[i]==0
			b[i+1]-=b[i]*diag[i+1]/super[i];
			if(i+2<n)b[i+2]-=b[i]*sub[i+1]/super[i];
			diag[i+1]=sub[i];tr[++i]=1;
		}
		else{
			diag[i+1]-=super[i]*sub[i]/diag[i];
			b[i+1]-=b[i]*sub[i]/diag[i];
		}
	}
	for(I i=n;i--;){
		if(tr[i]){
			swap(b[i],b[i-1]);
			diag[i-1]=diag[i];
			b[i]/=super[i-1];
		}
		else{
			b[i]/=diag[i];
			if(i)b[i-1]-=b[i]*super[i-1];
		}
	}
	return b;
}