// Description: Finds the argument minimizing the function f in the interval [a,b] assuming f is unimodal on the interval, i.e. has only one local minimum. The maximum error in the result is epsilon. Works equally well for maximization with a small change in the code. See TernarySearch.h in the Various chapter for a discrete version.
// Usage:
//	D func(D x) { return 4+x+.3*x*x; }
//	D xmin = gss(-1000,1000,func);
// Time: O(\log((b-a) / \epsilon))
// It is important for r to be precise, otherwise we don't necessarily maintain the inequality a<x1<x2<b
D unimodalminimum(D a,D b,D (*f)(D)){//Ulf Lundstrom
	D r=(sqrt(5)-1)/2,eps=1e-7;
	D x1=b-r*(b-a),x2=a+r*(b-a);
	D f1=f(x1),f2=f(x2);
	while(b-a>eps) //change to > to find maximum
		if(f1<f2){b=x2;x2=x1;f2=f1;x1=b-r*(b-a);f1=f(x1);}
		else{a=x1;x1=x2;f1=f2;x2=a+r*(b-a);f2=f(x2);}
	return a;
}