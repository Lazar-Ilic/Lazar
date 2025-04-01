// Description: Solves a general linear maximization problem: maximize $c^T x$ subject to $zx \le b$, $x \ge 0$. Returns -inf if there is no solution, inf if there are arbitrarily good solutions, or the maximum value of $c^T x$ otherwise. The input vector is set to an optimal $x$ (or in the unbounded case, an arbitrary solution fulfilling the constraints). Numerical stability is not guaranteed. For better performance, define variables such that $x = 0$ is viable.
// Usage:
// VVD z = {{1,-1}, {-1,1}, {-1,-2}};
// VD b = {1,1,-4}, c = {-1,-1}, x;
// T val = LPSolver(z, b, c).solve(x);
// Time: O(NM * \#pivots), where a pivot may be e.g. an edge relaxation. O(2^n) in the general case.
const D eps=1e-8,inf=1/.0;
#define ltj(X) if(s==-1 or make_pair(X[j],v[j])<make_pair(X[s],v[s])) s=j
STR LPSolver{//Stanford
	I m,n;V v,y;VVD w;
	LPSolver(const VVD& z,const VD& b,const VD& c):
		m(sz(b)), n(sz(c)), v(n+1), y(m), w(m+2, VD(n+2)) {
			rep(i,0,m) rep(j,0,n) w[i][j] = z[i][j];
			rep(i,0,m) { y[i] = n+i; w[i][n] = -1; w[i][n+1] = b[i];}
			rep(j,0,n) { v[j] = j; w[m][j] = -c[j]; }
			v[n] = -1; w[m+1][n] = 1;
		}
	Z pivot(I r, I s) {
		D *a = w[r].data(), inv = 1 / a[s];
		rep(i,0,m+2) if (i != r && abs(w[i][s]) > eps) {
			D *b = w[i].data(), inv2 = b[s] * inv;
			rep(j,0,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		rep(j,0,n+2) if (j != s) w[r][j] *= inv;
		rep(i,0,m+2) if (i != r) w[i][s] *= -inv;
		w[r][s] = inv;
		swap(y[r], v[s]);
	}
	B simplex(I phase) {
		I x = m + phase - 1;
		for (;;) {
			I s = -1;
			rep(j,0,n+1) if (v[j] != -phase) ltj(w[x]);
			if (w[x][s] >= -eps) return true;
			I r = -1;
			rep(i,0,m){
				if(w[i][s]<=eps)continue;
				if(r==-1 or make_pair(w[i][n+1]/w[i][s],y[i])<make_pair(w[r][n+1]/w[r][s],y[r]))r=i;
			}
			if(r==-1)return false;
			pivot(r,s);
		}
	}
	D solve(VD &x){
		I r=0;
		rep(i,1,m)if(w[i][n+1]<w[r][n+1])r=i;
		if(w[r][n+1]<-eps){
			pivot(r,n);
			if(!simplex(2) or w[m+1][n+1]<-eps)return -inf;
			rep(i,0,m)if(y[i]==-1){
				I s=0;
				rep(j,1,n+1)ltj(w[i]);
				pivot(i,s);
			}
		}
		B ok=simplex(1);x=VD(n);
		rep(i,0,m)if(y[i]<n)x[y[i]]=w[i][n+1];
		return ok?w[m][n+1]:inf;
	}
};