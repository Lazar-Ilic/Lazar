// Description: Solves $aaa * x = b$. If there are multiple solutions, an arbitrary one is returned. Returns rank, or -1 if no solutions. Data in $aaa$ and $b$ is lost.
// Time: O(n^2*m)
const D eps = 1e-12;
I solvelinear(VVD& aaa, VD& b, VD& x) {//Per Austrin,Simon Lindholm
	I n = sz(aaa), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(aaa[0]) == m);
	V col(m); iota(all(col), 0);
	rep(i,0,n) {
		D v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(aaa[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(aaa[i], aaa[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(aaa[j][i], aaa[j][bc]);
		bv = 1/aaa[i][i];
		rep(j,i+1,n) {
			D fac = aaa[j][i] * bv;
			b[j] -= fac * b[i];
			rep(k,i+1,m) aaa[j][k] -= fac*aaa[i][k];
		}
		rank++;
	}
	x.assign(m, 0);
	for (I i = rank; i--;) {
		b[i] /= aaa[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] -= aaa[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}