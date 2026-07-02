#include <chrono>
const I inf = 2e9;
mt19937 rng(1);
auto dist = uniform_int_distribution<I>(0,inf);
inline I mrand(){
	return dist(rng);
}
STR node{
	I val,prio;
	I mv,sz=1;
	node *l=0,*r=0;
	B reverse=false;
	node(I val):val(val),mv(val),prio(mrand()){}
	Z push(){
		if(reverse){
			swap(l,r);
			if(l)l->reverse=!l->reverse;
			if(r)r->reverse=!r->reverse;
			reverse=false;
		}
	}
	Z pull(){
		mv=min({val,(l?l->mv:inf),(r?r->mv:inf)});
		sz=1+(l?l->sz:0)+(r?r->sz:0);
	}
};
typedef node* pnode;
Z merge(pnode &t,pnode l,pnode r){
	if(!l or !r){t=(l?l:r);return;}
	if(l->prio>r->prio){l->push();t=l;merge(t->r,l->r,r);}
	else{r->push();t=r;merge(t->l,l,r->l);}
	t->pull();
}
Z splitsize(pnode t,pnode &l,pnode &r,I v){
	if(!t){l=r=t;return;}
	t->push();
	I sz=1+(t->l?t->l->sz:0);
	if(sz<=v){l=t;splitsize(t->r,l->r,r,v-sz);l->pull();}
	else{r=t;splitsize(t->l,l,r->l,v);r->pull();}
}
I min(pnode &t,I a,I b){
	if(!t or t->sz<a or !b)return inf;
	if(!a and t->sz<=b)return t->mv;
	t->push();
	I sz=1+(t->l?t->l->sz:0);
	if(sz<a){return min(t->r,a-sz,b-sz);}
	if(sz>b){return min(t->l,a,b);}
	return min({min(t->l,a,b),t->val,min(t->r,0,b-sz)});
}
I find(pnode &t,I x){
	if(!t)return 0;
	t->push();
	if(t->val==x)return (t->l?t->l->sz:0)+1;
	if(t->r and t->r->mv<=x)return (t->l?t->l->sz:0)+1+find(t->r,x);
	return find(t->l,x);
}

//--------------------------------------------------------------------

Z az(){
	in>>n;
	pnode treap=0;
	for(i=0;i<n;i++){
		in>>num;
		merge(treap,treap,new node(num));
	}
	VP ans;
	ans.reserve(n);
	for(i=1;i<=n;i++){
		if(min(treap,i,i)==i)continue;
		I end=find(treap,i);
		pnode l,m,r;
		splitsize(treap,l,r,end);
		splitsize(l,l,m,i-1);
		m->reverse=!m->reverse;
		merge(treap,l,m);
		merge(treap,treap,r);
		ans.push_back({i,end});
	}
	out<<sz(ans)<<nl;
	for(P ap:ans){
		out<<ap.first<<" "<<ap.second<<nl;
	}
}