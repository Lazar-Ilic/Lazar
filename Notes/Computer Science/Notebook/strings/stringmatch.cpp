// Description: pi[x] computes the length of the longest prefix of s that ends at x, other than s[0...x] itself [abacaba -> 0010123]. Can be used to find all occurrences of a string.

// Time: O(n)

V build(const S& as){//Johan Sannemo
	V z(sz(as));
	rep(i,1,sz(as)){
		I g=z[i-1];
		while(g and as[i]!=as[g])g=z[g-1];
		z[i]=g+(as[i]==as[g]);
	}
	return z;
}
V match(const S& as,const S& pattern){
	V z=build(pattern+'\0'+as),res;
	rep(i,sz(z)-sz(as),sz(z))
		if(z[i]==sz(pattern))res.push_back(i-2*sz(pattern));
	return res;
}

//--------------------------------------------------------------------

Z build(S& as,V& pi){
	pi=V(sz(as));
	I k=-2;
	for(I i=0;i<sz(as);i++){
		while(k>=-1 and as[k+1]!=as[i])
			k=(k==-1)?-2:pi[k];
		pi[i]=++k;
	}
}
V stringmatch(S& t,S& q){ // find indices where q occurs in t
	V pi,av;
	build(q,pi);
	I k=-1;
	for(I i=0;i<sz(t);i++){
		while(k>=-1 and q[k+1]!=t[i])
			k=(k==-1)?-2:pi[k];
		k++;
		if(k==sz(q)-1){ //match found
			av.add(i-k);
			k=(k==-1)?-2:pi[k];
		}
	}
	return av; //can return pi for max prefix ending at indices -1
}

//--------------------------------------------------------------------

Z az(){
	S as="AABAACAADAABAABA";
	bs="AABA";
	av=stringmatch(as,bs); //matches at 0, 9, 12
}