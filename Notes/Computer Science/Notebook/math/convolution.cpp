// May fail on memory for n ~ 10^8 or 10^9.
// Time: O[N * log[N]] with N = A + B [~1000ms for N = 2^22 ~ 4000000]
Z fft(vector<CD>& a){//Ludo Pulles,chilli,Simon Lindholm
	I n=sz(a),l=31-__builtin_clz(n);
	static vector<CLD> r(2,1);
	static vector<CD> rt(2, 1);  // 10% faster if double
	for(static I k=2;k<n;k*=2){
		r.resize(n);rt.resize(n);
		auto x=polar(1.0L,acos(-1.0L)/k);
		rep(i,k,2*k)rt[i]=r[i]=i&1?r[i/2]*x:r[i/2];
	}
	V rev(n);
	rep(i,0,n)rev[i]=(rev[i/2]|(i&1)<<l)/2;
	rep(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(I k=1;k<n;k*=2)
		for(I i=0;i<n;i+=2*k)rep(j,0,k){
			// CD z=rt[j+k]*a[i+j+k]; // include this line 25% faster
			auto x=(D *)&rt[j+k],y=(D *)&a[i+j+k];// exclude this line
			CD z(x[0]*y[0]-x[1]*y[1],x[0]*y[1]+x[1]*y[0]);// exclude this line
			a[i+j+k]=a[i+j]-z;
			a[i+j]+=z;
		}
}
VD convolution(const VD& a,const VD& b){
	if(a.empty() or b.empty())return {};
	VD res(sz(a)+sz(b)-1);
	I l=32-__builtin_clz(sz(res)),n=1<<l;
	vector<CD> in(n),out(n);
	copy(all(a),begin(in));
	rep(i,0,sz(b))in[i].imag(b[i]);
	fft(in);
	for(CD& x:in)x*=x;
	rep(i,0,n)out[i]=in[-i&(n-1)]-conj(in[i]);
	fft(out);
	rep(i,0,sz(res))res[i]=imag(out[i])/(4*n);
	return res;
}