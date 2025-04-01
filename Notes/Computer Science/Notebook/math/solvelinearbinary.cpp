// Description: Solves zx=b over F2. If there are multiple solutions, one is returned arbitrarily. Returns rank, or -1 if no solutions. Destroys z and b
// Time: O(n^2*m)
typedef bitset<1000> BTS;
I solvelinear(vector<BTS>& z,V& b,BTS& x,I m){//Simon Lindholm
	I n=sz(z),rank=0,br;
	assert(m<=sz(x));
	V col(m);iota(all(col),0);
	rep(i,0,n){
		for(br=i;br<n;++br)if(z[br].any())break;
		if(br==n){
			rep(j,i,n)if(b[j])return -1;
			break;
		}
		I bc=(I)z[br]._Find_next(i-1);
		swap(z[i],z[br]);
		swap(b[i],b[br]);
		swap(col[i],col[bc]);
		rep(j,0,n)if(z[j][i]!=z[j][bc]){
			z[j].flip(i);z[j].flip(bc);
		}
		rep(j,i+1,n)if(z[j][i]){
			b[j]^=b[i];
			z[j]^=z[i];
		}
		rank++;
	}
	x=BTS();
	for(I i=rank;i--;){
		if(!b[i])continue;
		x[col[i]]=1;
		rep(j,0,i)b[j]^=z[j][i];
	}
	return rank; // multiple solutions if rank<m
}
