// Description: Given f and n, finds the smallest fraction p/q in [0,1] such that f(p/q) is true, and p,q<=n. You may want to throw an exception from f if it finds an exact solution, in which case n can be removed.
// Usage: fractionalbs([](Frac f){return f.p>=3*f.q;},10); // {1,3}
// Time: O(log n)
STR fraction{L p,q;};
template<class F>
fraction fractionalbs(F f,L n){//Lucian Bicsi,Simon Lindholm
	B dir=1,a=1,b=1;
	fraction lo{0,1},hi{1,1}; // Set hi to 1/0 to search (0, n]
	if(f(lo))return lo;
	assert(f(hi));
	while(a or b){
		L adv=0,step=1; // move hi if dir, else lo
		for(I si=0;step;(step*=2)>>=si){
			adv+=step;
			fraction mid{lo.p*adv+hi.p,lo.q*adv+hi.q};
			if(abs(mid.p)>n or mid.q>n or dir==!f(mid)){
				adv-=step;si=2;
			}
		}
		hi.p+=lo.p*adv;
		hi.q+=lo.q*adv;
		dir=!dir;
		swap(lo,hi);
		a=b;b=!!adv;
	}
	return dir?hi:lo;
}