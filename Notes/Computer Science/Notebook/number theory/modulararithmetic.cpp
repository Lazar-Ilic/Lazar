// Description: Operators for modular arithmetic. You need to set {\tt mod} to some number first and then you can use the structure.
L euclid(L a,L b,L &x,L &y){//Lukas Polacek
	if(!b)return x=1,y=0,a;
	L d=euclid(b,a%b,y,x);
	return y-=a/b*x,d;
}
const L mod=17; // change to something else
STR modulus{
	L x;
	modulus(L xx):x(xx){}
	modulus operator+(modulus b) { return modulus((x + b.x) % mod); }
	modulus operator-(modulus b) { return modulus((x - b.x + mod) % mod); }
	modulus operator*(modulus b) { return modulus((x * b.x) % mod); }
	modulus operator/(modulus b) { return *this * invert(b); }
	modulus invert(modulus a) {
		L x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return modulus((x + mod) % mod);
	}
	modulus operator^(L e) {
		if (!e) return modulus(1);
		modulus r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};