// Description: Calculates all-pairs shortest path in a directed graph that might have negative edge weights. Input is an distance matrix m, where m[i][j]=inf if i and j are not adjacent. As output, m[i][j] is set to the shortest distance between i and j, inf if no path, or -inf if the path goes through a negative-weight cycle.
// Time: O(N^3)
const L inf=1L<<62;
Z minpathsall(VVL& m){//Simon Lindholm
	int n = sz(m);
	rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}
//VVL avvl=VVL(a,VL(a,inf));