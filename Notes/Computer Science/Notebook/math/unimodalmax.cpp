// Description: Poor man's optimization for unimodal functions.
template<class F> pair<D,array<D,2>> unimodalmax(array<D,2> start,F f){//Simon Lindholm
	pair<D,array<D,2>>cur(f(start),start);
	for(D jmp=1e9;jmp>1e-20;jmp/=2){
		rep(j,0,100)rep(dx,-1,2)rep(dy,-1,2){
			array<D,2> z=cur.second;
			z[0]+=dx*jmp;
			z[1]+=dy*jmp;
			cur=min(cur,make_pair(f(z),z));
		}
	}
	return cur;
}

//----------

D alll,blll;

double f(double aaaa){
	return D(0)-aaaa*blll-alll/sqrt(aaaa+1);
}

double ternarysearch(double l,double r){
    double eps=1; // Choose carefully.
	double f1,f2,m1,m2;
    while(r-l>eps){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
		//out<<m1<<" "<<m2<<nl;
        f1=f(m1);
        f2=f(m2);
        if(f1<f2)l=m1;
        else r=m2;
    }
	//out<<f1<<" "<<f2<<nl;
	//out<<f(D(I(l)))<<" "<<f(D(I(l+1)))<<nl;
	if(f(D(L(l)))>f(D(L(l+1)))){
		out<<setprecision(30)<<D(0)-f(D(L(l)))<<nl;
		return 0.0-f(D(L(l)));
	}
	else{
		out<<setprecision(30)<<D(0)-f(D(L(l+1)))<<nl;
		return 0.0-f(D(L(l+1)));
	}
    //return 0.0-dmax(f(D(I(l))),f(D(I(l+1))));
}