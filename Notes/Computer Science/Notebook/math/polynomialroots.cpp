// Description: Finds the real roots to a polynomial.
// Usage: polyRoots({{2,-3,1}},-1e9,1e9) // solve x^2-3x+2 = 0
// Time: O(n^2 \log(1/\epsilon))
STR polynomial{//Per Austrin
	VD a;
	D operator()(D x)const{
		D val=0;
		for(I i=sz(a);i--;)(val*=x)+=a[i];
		return val;
	}
	Z differentiate(){
		rep(i,1,sz(a))a[i-1]=i*a[i];
		a.pop_back();
	}
	Z divideoutroot(D x0){
		D b=a.back(),c;a.back()=0;
		for(I i=sz(a)-1;i--;)c=a[i],a[i]=a[i+1]*x0+b,b=c;
		a.pop_back();
	}
};
VD polynomialroots(polynomial z,D xmin,D xmax){
	if(sz(z.a)==2){return{-z.a[0]/z.a[1]};}
	VD ret;
	polynomial der=z;
	der.differentiate();
	auto dr = polynomialroots(der,xmin,xmax);
	dr.push_back(xmin-1);
	dr.push_back(xmax+1);
	sort(all(dr));
	rep(i,0,sz(dr)-1) {
		D l=dr[i],h=dr[i+1];
		B sign=z(l)>0;
		if(sign^(z(h)>0)){
			rep(it,0,60){ // while (h - l > 1e-8)
				D m=(l+h)/2,f=z(m);
				if((f<=0)^sign)l=m;
				else h=m;
			}
			ret.push_back((l+h)/2);
		}
	}
	return ret;
}