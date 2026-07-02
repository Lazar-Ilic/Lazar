// Description: segtree on values instead of indices. Returns k-th largest number in 0-indexed interval [lo,hi). size=2^p and all values in a must lie in [0,size)
// Memory: O(N log N)
// Time: O(log N) query
template<I size> STR OINTERVAL{ 
	V c[size],d[size];
	Z build(V a,I i=1,I l=0,I r=size-1){
		if(l==r)return;
		c[i]=d[i]={0};
		V A[2];I m=(l+r)/2;
		each(t,a){
			A[t>m].add(t);
			c[i].add(sz(A[0])),d[i].add(sz(A[1]));
		}
		build(A[0],2*i,l,m),build(A[1],2*i+1,m+1,r);
	}
	I query(I lo,I hi,I k,I i=1,I l=0,I r=size-1){ 
		if(l==r)return l;
		I m=(l+r)/2,t=c[i][hi]-c[i][lo];
		if(t>=k)return query(c[i][lo],c[i][hi],k,2*i,l,m);
		return query(d[i][lo],d[i][hi],k-t,2*i+1,m+1,r);
	}
};