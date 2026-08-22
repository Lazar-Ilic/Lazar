STR polynomial{//David Rydh,Per Austrin
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