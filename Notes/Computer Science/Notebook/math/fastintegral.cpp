// Description: Fast integration using an adaptive Simpson's rule.
// Usage:
//	double sphereVolume = integral(-1, 1, [](double x) {
//	return integral(-1, 1, [\&](double y) {
//	return integral(-1, 1, [\&](double z) {
//	return x*x + y*y + z*z < 1; });});});
#define bz(a,b) (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6
template <class F>
D rec(F& f,D a,D b,D eps,D s){//Simon Lindholm
	D c=(a+b)/2;
	D s1=bz(a,c),s2=bz(c,b),t=s1+s2;
	if(abs(t-s)<=15*eps or b-a<1e-10)
		return t+(t-s)/15;
	return rec(f,a,c,eps/2,s1)+rec(f,c,b,eps/2,s2);
}
template<class F>
D integral(D a,D b,F f,D eps=1e-8){
	return rec(f,a,b,eps,bz(a,b));
}