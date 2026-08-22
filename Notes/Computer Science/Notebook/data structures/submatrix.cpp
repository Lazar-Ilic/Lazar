// Description: Calculate submatrix sums quickly, given upper-left and lower-right corners (half-open).
// Usage:
// submatrix<I> m(matrix);
// m.sum(0,0,2,2); // top left 4 elements
// Time: O(N^2 + Q)
template<class T>
STR submatrix{//Johan Sannemo
	vector<vector<T>> a;
	submatrix(vector<vector<T>>& v){
		I row=sz(v),column=sz(v[0]);
		a.assign(row+1, vector<T>(column+1));
		rep(r,0,row) rep(c,0,column)
			a[r+1][c+1]=v[r][c]+a[r][c+1]+a[r+1][c]-a[r][c];
	}
	T sum(I u,I l,I d,I r){
		return a[d][r]-a[d][l]-a[u][r]+a[u][l];
	}
};