// Description: Does not allocate storage for nodes with no data
const I size = 1<<17;
template<class T> STR node {//Benjamin Qi
	T val = 0; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	Z upd(I ind, T v, I left = 0, I right = size-1) { // add v
		if (left == ind && right == ind) { val += v; return; }
		I mid = (left+right)/2;
		if (ind <= mid) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,left,mid);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,mid+1,right);
		}
		val = 0;
		for(I i=0;i<2;i++){
			if(c[i]){
				val+=c[i]->val;
			}
		}
	}
	T query(I lo, I hi, I left = 0, I right = size-1) { // query sum of segment
		if (hi < left || right < lo) return 0;
		if (lo <= left && right <= hi) return val;
		I mid = (left+right)/2; T res = 0;
		if (c[0]) res += c[0]->query(lo,hi,left,mid);
		if (c[1]) res += c[1]->query(lo,hi,mid+1,right);
		return res;
	}
	Z update(I ind, node* c0, node* c1, I left = 0, I right = size-1) { // for 2D segtree
		if (left != right) {
			I mid = (left+right)/2;
			if (ind <= mid) {
				if (!c[0]) c[0] = new node();
				c[0]->update(ind,c0?c0->c[0]:NULL,c1?c1->c[0]:NULL,left,mid);
			} else {
				if (!c[1]) c[1] = new node();
				c[1]->update(ind,c0?c0->c[1]:NULL,c1?c1->c[1]:NULL,mid+1,right);
			}
		} 
		val = (c0?c0->val:0)+(c1?c1->val:0);
	}
};