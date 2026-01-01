Z fft(vector<CLD>& a){//chilli
	I n=sz(a),l=31-__builtin_clz(n);
	static vector<CLD> r(2,1);
	static vector<CLD> rt(2,1);  // 10% faster if D
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
			auto x=(LD *)&rt[j+k],y=(LD *)&a[i+j+k]; // exclude this line
			CLD z(x[0]*y[0]-x[1]*y[1],x[0]*y[1]+x[1]*y[0]); // exclude this line
			a[i+j+k]=a[i+j]-z;
			a[i+j]+=z;
		}
}
VL convolutionp(const VL &a,const VL &b){
	if(a.empty() or b.empty())return {};
	VL res(sz(a)+sz(b)-1);
	I y=32-__builtin_clz(sz(res)),n=1<<y,cut=I(sqrt(p));
	vector<CLD> c(n),d(n),os(n),ol(n);
	rep(i,0,sz(a))c[i]=CLD((I)a[i]/cut,(I)a[i]%cut);
	rep(i,0,sz(b))d[i]=CLD((I)b[i]/cut,(I)b[i]%cut);
	fft(c),fft(d);
	rep(i,0,n){
		I j=-i&(n-1);
		ol[j]=(c[i]+conj(c[j]))*d[i]/((LD)2.0*n);
		os[j]=(c[i]-conj(c[j]))*d[i]/((LD)2.0*n)/(CLD(0,1));
	}
	fft(ol),fft(os);
	rep(i,0,sz(res)){
		L av=L(real(ol[i])+.5),cv=L(imag(os[i])+.5);
		L bv=L(imag(ol[i])+.5)+L(real(os[i])+.5);
		res[i]=((av%p*cut+bv)%p*cut+cv)%p;
	}
	return res;
}

/*
Seems there might uh be doomed to be uh RAM issues not clear not clear not clear and uh 10^8 versus 10^7 with what is going on here in a native convolutionp call on p = 1234567891 is costing around uh 90s of runtime could be like 900s per is like 15 minutes per is 4|hour maybe maybe maybe could be like uh 400 hours is like uh 8 days OK this could be a multi week multi month implementation ungh. Not even correct ungh 24 25 precision Wrong. OKOKOK and still tossing a bunch of Output junk up front yet executing so we see we see we see if it will halt at 90s or 100s on this 10^7 Input and Output something uh interesting seems as though it tossed 687334238 is Wrong here using CD should be ungh 687241000 interesting. OKOKOK so replace that uh 1i notation with a uh CLD(0,1) call seems to clear that up is a uh good I guess see see see what happens here I think. Would be on 256GB RAM could take 45 minutes per is like still in the 500 1000 hours run time ballpark of 40 days or so talking < 70 days 10 weeks runtime is half-reasonable here.
*/

	avl=VL(10000000,1000000000);
	bvl=VL(10000000,1000000000);
	cvl=convolutionp(avl,bvl);
	out<<cvl[9999999]<<nl; // 687241000 using 8GB for 152s and n~10^7