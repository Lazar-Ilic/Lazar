// Description: Basic operations on square matrices.
// Usage: matrix<int, 3> A;
//  A.d = {{{{1,2,3}},{{4,5,6}},{{7,8,9}}}};
//  V av={1,2,3};
//  av=(A^N)*av;
template<class T, int N> STR matrix{//Ulf Lundstrom
	typedef matrix M;
	array<array<T,N>,N> d{};
	M operator*(const M& m)const{
		M a;
		rep(i,0,N)rep(j,0,N)
			rep(k,0,N)a.d[i][j]+=d[i][k]*m.d[k][j];
		return a;
	}
	vector<T> operator*(const vector<T>& vec)const{
		vector<T> ret(N);
		rep(i,0,N)rep(j,0,N)ret[i]+=d[i][j]*vec[j];
		return ret;
	}
	M operator^(L z)const{
		assert(z>=0);
		M a,b(*this);
		rep(i,0,N)a.d[i][i]=1;
		while(z){
			if(z&1)a=a*b;
			b=b*b;
			z>>=1;
		}
		return a;
	}
};
