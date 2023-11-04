// Description: A short self-balancing tree. It acts as a sequential container with log-time splits/joins, and is easy to augment with additional data.
// Time: O(log N)
STR node{
	node *l=0,*r=0;
	I val,y,c=1;
	node(I val):val(val),y(rand()){}
	Z recalc();
};
I cnt(node* n){return n ? n->c:0;}
Z node::recalc(){c=cnt(l)+cnt(r)+1;}
template<class F> Z each(node* n,F f){
	if(n){each(n->l,f);f(n->val);each(n->r,f);}
}
pair<node*,node*> split(node* n,I k){
	if(!n)return{};
	if(cnt(n->l)>=k){ // "n->val>=k" for lower_bound(k)
		auto pa=split(n->l,k);
		n->l=pa.second;
		n->recalc();
		return{pa.first,n};
	}
	else{
		auto pa=split(n->r,k-cnt(n->l)-1); // and just "k"
		n->r=pa.first;
		n->recalc();
		return {n,pa.second};
	}
}
node* merge(node* l,node* r){
	if(!l)return r;
	if(!r)return l;
	if(l->y>r->y){
		l->r=merge(l->r,r);
		l->recalc();
		return l;
	}
	else{
		r->l=merge(l,r->l);
		r->recalc();
		return r;
	}
}
node* ins(node* t,node* n,I pos){
	auto pa=split(t,pos);
	return merge(merge(pa.first,n),pa.second);
}
// Example application: move the range [l,r) to index k
Z move(node*& t,I l,I r,I k){
	node *a,*b,*c;
	tie(a,b)=split(t,l);tie(b,c)=split(b,r-l);
	if(k<=l)t=merge(ins(a,b,k),c);
	else t=merge(a,ins(c,b,k-r));
}