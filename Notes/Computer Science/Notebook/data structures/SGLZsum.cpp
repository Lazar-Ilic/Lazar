const L inf = 1e18;
STR SGLZ{//Simon Lindholm
	SGLZ *l = 0, *r = 0;
	L lo, hi, toset = inf, toadd = 0, value = -inf;
	SGLZ(L lo,L hi):lo(lo),hi(hi){} // large interval of -inf
	SGLZ(VL& v, L lo, L hi) : lo(lo), hi(hi){ // [lo,hi)
		if (lo + 1 < hi) {
			L mid = lo + (hi - lo)/2;
			l = new SGLZ(v, lo, mid); r = new SGLZ(v, mid, hi);
            //------------------------------------------------
			//value = max(l->value, r->value); // associative
            value = l->value + r->value;
		}
		else value = v[lo]; // initializing to vector value
	}
	L query(L left, L right){ // [left,right)
		if (right <= lo || hi <= left) return -inf;
		if (left <= lo && hi <= right) return value;
		push();
		return max(l->query( left, right), r->query( left, right));
	}
	Z set(L left, L right, L x){ // [left,right)
		if (right <= lo || hi <= left) return;
		if (left <= lo && hi <= right) toset = value = x, toadd = 0;
		else {
			push(), l->set( left, right, x), r->set( left, right, x);
			value = max(l->value, r->value);
		}
	}
	Z addto(L left, L right, L x){ // [left,right)
		if (right <= lo || hi <= left) return;
		if (left <= lo && hi <= right) {
			if (toset != inf) toset += x;
			else toadd += x;
			value += x;
		}
		else {
			push(), l->addto( left, right, x), r->addto( left, right, x);
			value = max(l->value, r->value);
		}
	}
	Z push(){
		if (!l) {
			L mid = lo + (hi - lo)/2;
			l = new SGLZ(lo, mid); r = new SGLZ(mid, hi);
		}
		if (toset != inf)
			l->set(lo,hi,toset), r->set(lo,hi,toset), toset = inf;
		else if (toadd)
			l->addto(lo,hi,toadd), r->addto(lo,hi,toadd), toadd = 0;
	}
};