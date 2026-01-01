// Description: Computes sums a[i,j] for all i<I,j<J, and increases single elements a[i,j]. Requires that the elements to be updated are known in advance (call fakeupdate() before build())
// Time: O(log^2 N) (Use persistent segment trees for O(log N))
STR BIT{//Simon Lindholm
	VV ys; vector<FT> ft;
	BIT(I limx):ys(limx){}
	Z fakeupdate(I x,I y){
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	Z build(){
		for(V& v:ys)sort(all(v)),ft.emplace_back(sz(v));
	}
	I ind(I x,I y){
		return (I)(lower_bound(all(ys[x]),y)-ys[x].begin());}
	Z update(I x,I y,L dif){
		for (;x<sz(ys);x|=x+1)
			ft[x].update(ind(x,y),dif);
	}
	L query(I x,I y){
		L sum=0;
		for(;x;x&=x-1)
			sum+=ft[x-1].query(ind(x-1,y));
		return sum;
	}
};
//call all fakeupdates before build()
//sum of rectangle from origin to [a,b] exclusive
//use persistent segment trees for log n