// Description: Chinese Remainder Theorem. crt(a,m,b,n) computes x such that x=a(mod m), x=b(mod n). If |a|<m and |b|<n, x will obey 0<=x<lcm(m,n). Assumes mn<2^62
// Time: O(log n)
L euclid(L a,L b,L &x,L &y){//Simon Lindholm
	if(!b)return x=1,y=0,a;
	L d=euclid(b,a%b,y,x);
	return y-=a/b*x,d;
}
L crt(L a,L m,L b,L n){
	if(n>m)swap(a,b),swap(m,n);
	L x,y,g=euclid(m,n,x,y);
	assert((a-b)%g==0); // else no solution
	x=(b-a)%n*x%n/g*m+a;
	return x<0?x+m*n/g:x;
}