// Description: Returns the smallest x>0 s.t. a^x=b(mod m), or -1 if no such x exists. modlog(a,1,m) can be used to calculate the order of a
// Time: O(m^(1/2))
L modlog(L a,L b,L m){//Bjorn Martinsson
	L n=(L)sqrt(m)+1,e=1,f=1,j=1;
	UMLL A;
	while(j<=n and (e=f=e*a%m)!=b%m)
		A[e*b%m]=j++;
	if(e==b%m)return j;
	if(__gcd(m,e)==__gcd(m,b)) 
		rep(i,2,n+2)if(A.count(e=e*f%m))
			return n*i-A[e];
	return -1;
}