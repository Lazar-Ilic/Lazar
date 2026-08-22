namespace treap{ // rlaguilar Reynaldo Aguilar WARNING: NOT VERIFIED
	/*	QUERY TYPES:
	1. ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example,performing "ADD 2 4 1" on {1,2,3,4,5} results in {1,3,4,5,5}
	2. REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example,performing "REVERSE 2 4" on {1,2,3,4,5} results in {1,4,3,2,5}
	3. REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example,performing "REVOLVE 2 4 2" on {1,2,3,4,5} results in {1,3,4,2,5}
	4. INSERT x P: insert P after Ax. For example,performing "INSERT 2 4" on {1,2,3,4,5} results in {1,2,4,3,4,5}
	5. DELETE x: delete Ax. For example,performing "DELETE 2" on {1,2,3,4,5} results in {1,3,4,5}
	6. MIN x y: what is the minimum number in sub-sequence {Ax ... Ay}. For example,the correct answer to "MIN 2 4" on {1,2,3,4,5} is 2
	7. SUM x y: what is the sum of all numbers in sub-sequence {Ax...Ay}. For example,the answer to "SUM 3 5" on {1,2,3,4,5} is 12*/
	typedef int node;
	const int MAXN=300001,MAXS=2000000,NIL=0,oo=1000000000; // Can change to non const if needed with vectors for contrived tasks with ~100000 cases with sum of ns ~4000000 e.g.
	node lch[MAXS],rch[MAXS],root;
	int val[MAXS],//val[i]=value of array at corresponding index to node i
		cnt[MAXS],//cnt[i]=gets the number of nodes in the subtree rooted at node i
		rev[MAXS],//rev[i]=says if the node i is reversed
		acc[MAXS],//acc[i]=accumulated value for sum in all the subtree rooted at node i
		sum[MAXS],//sum[i]=gets the sum of values of all nodes in the subtree rooted at node i
		mim[MAXS],//mim[i]=gets the minimum value of all nodes in the subreee rooted at node i
		arr[MAXN],//arr[i]=value of initial array at index i
		sz;

	int random(){return rng();}

	void init(){sz=1;}

	void clear(){
		root=0;
		memset(lch,0,MAXS*sizeof(lch[0]));
		memset(rch,0,MAXS*sizeof(rch[0]));
		memset(val,0,MAXS*sizeof(val[0]));
		memset(cnt,0,MAXS*sizeof(cnt[0]));
		memset(rev,0,MAXS*sizeof(rev[0]));
		memset(acc,0,MAXS*sizeof(acc[0]));
		memset(sum,0,MAXS*sizeof(sum[0]));
		memset(mim,0,MAXS*sizeof(mim[0]));
		memset(arr,0,MAXN*sizeof(arr[0]));
	}

	int getCount(node t){return t!=NIL ? cnt[t]:0;}

	int getSum(node t){return t!=NIL ? sum[t]:0;}

	int getMin(node t){return t!= NIL ? mim[t]:oo;}

	void push(node t){
		if(t!=NIL){
			if(rev[t]){ // Reverse Query
				rev[t]=false;
				if(lch[t]!=NIL)rev[lch[t]] ^= 1;
				if(rch[t]!=NIL)rev[rch[t]] ^= 1;
				swap(lch[t],rch[t]);
			}
			if(acc[t]){ // Interval Sum Query
				val[t]+=acc[t];
				if(lch[t]!=NIL)acc[lch[t]]+=acc[t];
				if(rch[t]!=NIL)acc[rch[t]]+=acc[t];
				acc[t]=0;
			}
		}
	}

	void update(node t){
		if(t!=NIL){
			cnt[t]=getCount(lch[t])+getCount(rch[t])+1;
			sum[t]=getSum(lch[t])+getSum(rch[t])+val[t];
			int mc=min(getMin(lch[t]),getMin(rch[t]));
			mim[t]=min(mc,val[t]);
		}
	}

	node newNode(int v,node l,node r){
		assert(sz<MAXS);
		val[sz]=v;
		mim[sz]=v;
		lch[sz]=l;
		rch[sz]=r;
		update(sz);
		return sz++;
	}

	//WARNING: Call root=build(0,n-1)
	node build(int b,int e){
		if(b>e)return NIL;
		int m=(b+e)>>1;
		return newNode(arr[m],build(b,m-1),build(m+1,e));
	}

	void split(node t,node &l,node &r,int cnt){
		if(t==NIL)l=r=NIL;
		else{
			push(t);
			int tmp=getCount(lch[t]);
			if(tmp>=cnt){
				split(lch[t],l,lch[t],cnt);
				r=t;
			}
			else{
				split(rch[t],rch[t],r,cnt-tmp-1);
				l=t;
			}
			update(t);
		}
	}

	node merge(node l,node r){
		if(l==NIL||r==NIL)return l==NIL ? r:l;
		push(l);
		push(r);
		if(random()%(cnt[l]+cnt[r])<cnt[l]){
			rch[l]=merge(rch[l],r);
			update(l);
			return l;
		}
		lch[r]=merge(l,lch[r]);
		update(r);
		return r;
	}

	void insert(int idx,int val){
		if(idx>getCount(root))return;
		node n1,n2;
		split(root,n1,n2,idx);
		root=merge(n1,newNode(val,NIL,NIL));
		root=merge(root,n2);
	}

	void erase(int idx){
		if(getCount(root)<=idx)return;
		node n1,n2,n3;
		split(root,n1,n2,idx);
		split(n2,n2,n3,1);
		root=merge(n1,n3);
	}

	void reverse(int l,int r){
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		rev[n2]^=1;
		root=merge(n1,n2);
		root=merge(root,n3);
	}

	//Rotate arr[l...r] k times to the right(WARNING: TO THE RIGHT!!!)
	void rotate(int l,int r,int k){
		if(l>r)return;
		node n1,n2,n3,n4;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		k%=getCount(n2);
		split(n2,n2,n4,getCount(n2)-k);
		root=merge(n1,n4);
		root=merge(root,n2);
		root=merge(root,n3);
	}

	int sumquery(int l,int r){// WARNING: Check overflow in sum
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		int ans=getSum(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}

	void sumquery(int l,int r,int v){
		if(r<0)return;
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		acc[n2]+=v;
		root=merge(n1,n2);
		root=merge(root,n3);
	}

	int min_query(int l,int r){
		node n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		int ans=getMin(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}
};

I testcase=0;

Z az(){
	out<<"Case #"<<++testcase<<": ";
	in>>a>>b;
	treap::arr[0]=2000000;
	treap::init();
	treap::root=treap::build(0,0);
	for(c=0;c<a;c++){
		in>>d;
		l=0;
		r=c;
		while(l<r){
			m=(l+r)/2;
			if(treap::sumquery(m,m)-m-1>=d)r=m;
			else l=m+1;
		}
		treap::sumquery(0,l-1,-1);
		treap::insert(l,d+l);
		//out<<nl;
		//for(d=0;d<=c;d++)out<<treap::sumquery(d,d)<<nl;
	}
	l=0;
	r=a-1;
	if(treap::sumquery(r,r)<=b)l=r;
	else if(treap::sumquery(l,l)>=b)r=l;
	while(r-l>1){
		m=(l+r)/2;
		if(treap::sumquery(m,m)<b)l=m;
		else r=m;
	}
	if(abs(treap::sumquery(r,r)-b)<=abs(treap::sumquery(l,l)-b))out<<a-r<<" "<<abs(treap::sumquery(r,r)-b)<<nl;
	else out<<a-l<<" "<<abs(treap::sumquery(l,l)-b)<<nl;
	treap::clear();
}