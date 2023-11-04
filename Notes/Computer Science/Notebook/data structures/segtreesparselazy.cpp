STR node{//Andi Qu
	I sum, lazy, tl, tr, l, r;
	node() : sum(0), lazy(0), l(-1), r(-1) {}
};
const I maxn = 123456;
node segtree[64*maxn];
I cnt = 2;
Z push(I node){
	if (segtree[node].lazy) {
		segtree[node].sum = segtree[node].tr - segtree[node].tl + 1;
		I mid = (segtree[node].tl + segtree[node].tr) / 2;
		if (segtree[node].l == -1) {
			segtree[node].l = cnt++;
			segtree[segtree[node].l].tl = segtree[node].tl;
			segtree[segtree[node].l].tr = mid;
		}
		if (segtree[node].r == -1) {
			segtree[node].r = cnt++;
			segtree[segtree[node].r].tl = mid + 1;
			segtree[segtree[node].r].tr = segtree[node].tr;
		}
		segtree[segtree[node].l].lazy = segtree[segtree[node].r].lazy = 1;
		segtree[node].lazy = 0;
	}
}
Z update(I node, I l, I r) {
	push(node);
	if (l == segtree[node].tl && r == segtree[node].tr) {
		segtree[node].lazy = 1;
		push(node);
	} else {
		I mid = (segtree[node].tl + segtree[node].tr) / 2;
		if (segtree[node].l == -1) {
			segtree[node].l = cnt++;
			segtree[segtree[node].l].tl = segtree[node].tl;
			segtree[segtree[node].l].tr = mid;
		}
		if (segtree[node].r == -1) {
			segtree[node].r = cnt++;
			segtree[segtree[node].r].tl = mid + 1;
			segtree[segtree[node].r].tr = segtree[node].tr;
		}

		if (l > mid) update(segtree[node].r, l, r);
		else if (r <= mid) update(segtree[node].l, l, r);
		else {
			update(segtree[node].l, l, mid);
			update(segtree[node].r, mid + 1, r);
		}

		push(segtree[node].l);
		push(segtree[node].r);
		segtree[node].sum = segtree[segtree[node].l].sum + segtree[segtree[node].r].sum;
	}
}
I query(I node, I l, I r){
	push(node);
	if (l == segtree[node].tl && r == segtree[node].tr) return segtree[node].sum;
	else {
		I mid = (segtree[node].tl + segtree[node].tr) / 2;
		if (segtree[node].l == -1) {
			segtree[node].l = cnt++;
			segtree[segtree[node].l].tl = segtree[node].tl;
			segtree[segtree[node].l].tr = mid;
		}
		if (segtree[node].r == -1) {
			segtree[node].r = cnt++;
			segtree[segtree[node].r].tl = mid + 1;
			segtree[segtree[node].r].tr = segtree[node].tr;
		}

		if (l > mid) return query(segtree[node].r, l, r);
		else if (r <= mid) return query(segtree[node].l, l, r);
		else return query(segtree[node].l, l, mid) + query(segtree[node].r, mid + 1, r);
	}
}

Z az(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	I m;
	cin >> m;

	segtree[1].sum = 0; segtree[1].lazy = 0;
	segtree[1].tl = 1; segtree[1].tr = 1e9;

	I c = 0;
	FOR(_, 0, m) {
		I d, x, y;
		cin >> d >> x >> y;
		if (d == 1) {
			c = query(1, x + c, y + c);
			cout << c << '\n';
		} else update(1, x + c, y + c);
	}
	return 0;
}