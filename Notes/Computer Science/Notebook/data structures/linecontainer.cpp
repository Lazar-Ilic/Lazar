// Description: Container where you can add lines of the form kx+m, and query maximum values at points x. Useful for dynamic programming (``convex hull trick'').
// Time: O(log N)
STR line{//Simon Lindholm
	mutable L k,m,n;
	B operator<(const line& o)const{return k<o.k;}
	B operator<(L x)const{return n<x;}
};
STR linecontainer:multiset<line,less<>>{
	// for doubles, use inf=1/.0,div(a,b)=a/b
	static const L inf=LLONG_MAX;
	L div(L a,L b){ // floored division
		return a/b-((a^b)<0 and a%b);}
	B intersect(iterator x,iterator y){
		if(y==end())return x->n=inf,0;
		if(x->k==y->k)x->n=x->m>y->m?inf:-inf;
		else x->n=div(y->m-x->m,x->k-y->k);
		return x->n>=y->n;
	}
	Z add(L slope,L yintersect){
		auto z=insert({slope,yintersect,0}),y=z++,x=y;
		while(intersect(y,z))z=erase(z);
		if(x!=begin() and intersect(--x,y))intersect(x,y=erase(y));
		while((y=x)!=begin() and (--x)->n>=y->n)
			intersect(x,erase(y));
	}
	L query(L x){//maximum
		assert(!empty());
		auto l=*lower_bound(x);
		return l.k*x+l.m;
	}
};