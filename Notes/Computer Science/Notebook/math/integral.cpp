// Description: Simple integration of a function over an interval using Simpson's rule. The error should be proportional to $h^4$, although in practice you will want to verify that the result is stable to desired precision when epsilon changes.
template<class F>
D integral(D a,D b,F f,const I n=1000){//Simon Lindholm
	D h=(b-a)/2/n,v=f(a)+f(b);
	rep(i,1,n*2)
		v+=f(a+i*h)*(i&1?4:2);
	return v*h/3;
}