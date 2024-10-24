// Description: Finds two integers x and y, such that ax+by=gcd(a,b). If you just need gcd, use the built in gcd instead. If a and b are coprime, then x is the inverse of a(mod b)
L euclid(L a,L b,L &x,L &y){
	if(!b)return x=1,y=0,a;
	L d=euclid(b,a%b,y,x);
	return y-=a/b*x,d;
}