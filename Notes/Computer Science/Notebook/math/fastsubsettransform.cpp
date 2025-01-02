// Description: Transform to a basis with fast convolutions of the form c[z] = sum{z=x O y} a[x]*b[y], where O is one of AND, OR, XOR. The size of a must be a power of two.
// Time: O(N log N)
Z fastsubset(V& a,B inv){//Lucian Bicsi
	for (I n = sz(a), step = 1; step < n; step *= 2) {
		for (I i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			I &u = a[j], &v = a[j + step]; tie(u, v) =
				inv ? P(v - u, u) : P(v, u + v); // AND
				// inv ? P(v, u - v) : P(u + v, u); // OR /// include-line
				// P(u + v, u - v);                   // XOR /// include-line
		}
	}
	// if (inv) for (I& x : a) x /= sz(a); // XOR only /// include-line
}
V conv(V a, V b) {
	fastsubset(a, 0); fastsubset(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	fastsubset(a, 1); return a;
}