// Faster version is convolutionsuisenlarge.cpp
Z fft(vector<CD>& a){//chilli
	I n=sz(a),l=31-__builtin_clz(n);
	static vector<complex<LD>> r(2,1);
	static vector<CD> rt(2,1);  // 10% faster if D
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
			auto x=(D *)&rt[j+k],y=(D *)&a[i+j+k]; // exclude this line
			CD z(x[0]*y[0]-x[1]*y[1],x[0]*y[1]+x[1]*y[0]); // exclude this line
			a[i+j+k]=a[i+j]-z;
			a[i+j]+=z;
		}
}
VL convolutionp(const VL &a,const VL &b){
	if(a.empty() or b.empty())return {};
	VL res(sz(a)+sz(b)-1);
	I y=32-__builtin_clz(sz(res)),n=1<<y,cut=I(sqrt(p));
	vector<CD> c(n),d(n),os(n),ol(n);
	rep(i,0,sz(a))c[i]=CD((I)a[i]/cut,(I)a[i]%cut);
	rep(i,0,sz(b))d[i]=CD((I)b[i]/cut,(I)b[i]%cut);
	fft(c),fft(d);
	rep(i,0,n){
		I j=-i&(n-1);
		ol[j]=(c[i]+conj(c[j]))*d[i]/(2.0*n);
		os[j]=(c[i]-conj(c[j]))*d[i]/(2.0*n)/1i;
	}
	fft(ol),fft(os);
	rep(i,0,sz(res)){
		L av=L(real(ol[i])+.5),cv=L(imag(os[i])+.5);
		L bv=L(imag(ol[i])+.5)+L(real(os[i])+.5);
		res[i]=((av%p*cut+bv)%p*cut+cv)%p;
	}
	return res;
}
// May fail on memory for n ~ 10^8 10^9.
// Google Colab claims 4.8GB for a pair of VL at n ~ 10^7 producing a resultant cvl of n ~ 2 * 10^7 implies 48GB may be enough and that was on 70s run time so ~ 450 at 10^8 might take ~ 140 hours depending uh on a number of other factors but could theoretically clear in a background-executed massive $50 Google Colab. Except that Google Colab Pro+ still has a 24 hour execution run time cap and thus securing a 64GB or 96GB Apple Macintosh Book Professional Machine would still be in my direct Economic interest. As it so happens, that approach will not actually work here as the actual effective maximum size of n here is ~ 10^7 I think according to chilli's writing in the upstream KACTL documentation for this particular C|C++ convolution modulo p implementation and the Python Scientific Python SciPy or a uh PARI|GP implementation might work out better depending. Potentially one could more simply extend this one with some kind of a Karatsuba-style trickery...
// https://scicomp.stackexchange.com/questions/23867/c-libraries-for-fast-fourier-transform-in-high-