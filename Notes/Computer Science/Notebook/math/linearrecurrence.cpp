// Description: Generates the $k$'th term of an n-order linear recurrence z[i]=sum z[i-j-1]tr[j], given z[0 \ldots \ge n-1]$ and $tr[0 \ldots n-1]$. Faster than matrix multiplication. Useful together with recurrence.
// Usage: linearrecurrence({0, 1}, {1, 1}, k) // kth Fibonacci number
// Time: O(n^2 log k)
const L mod=5; /** exclude-line */
L linearrecurrence(VL z,VL tr,L k){//Lucian Bicsi
	I n=sz(tr);
	auto combine=[&](VL a,VL b){
		VL res(n*2+1);
		rep(i,0,n+1)rep(j,0,n+1)
			res[i+j]=(res[i+j]+a[i]*b[j])%mod;
		for(I i=2*n;i>n;--i)rep(j,0,n)
			res[i-1-j]=(res[i-1-j]+res[i]*tr[j])%mod;
		res.resize(n+1);
		return res;
	};
	VL pol(n+1),e(pol);
	pol[0]=e[1]=1;
	for(++k;k;k/=2){
		if(k%2)pol=combine(pol,e);
		e=combine(e,e);
	}
	L res=0;
	rep(i,0,n)res=(res+pol[i+1]*z[i])%mod;
	return res;
}
