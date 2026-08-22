// https://judge.yosupo.jp/problem/gcd_convolution
// And Other Web Logs



VL gcdconvolution(VL a, VL b, L mod){
	int n = a.size();
	VL A(n);
	VL B(n);
	VL D(n);
	for (int i = 0; i < n; i++)
	{
		if(i%1000000==0)out<<i<<nl;
		for (int j = i; j < n; j += i+1)
		{
			A[i] += a[j];
			B[i] += b[j];
			A[i] %= mod;
			B[i] %= mod;
		}
		D[i] = A[i] * B[i];
		D[i] %= mod;
	}
	VL d(n);
	for (int i = n-1; i >= 0; i--)
	{
		if(i%1000000==0)out<<i<<nl;
		d[i] = D[i];
		for (int j = 2*i+1; j < n; j += i + 1)
		{
			d[i] -= d[j];
			d[i] = (d[i] + mod) % mod;
		}
	}
	return d;

}