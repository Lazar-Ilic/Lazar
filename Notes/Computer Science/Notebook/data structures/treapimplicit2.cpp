namespace treap{
	const I MAXN=2e5+5,MAXS=1e6,NIL=0,oo=1e9+5;
	I lch[MAXS],rch[MAXS],root,val[MAXS],cnt[MAXS],rev[MAXS],acc[MAXS],sum[MAXS],mim[MAXS],arr[MAXN],szz;
	I random(){return(rand()<<15)+rand();}
	Z initialize(){szz=1;}
	I getcount(I t){return t!=NIL?cnt[t]:0;}
	I getsum(I t){return t!=NIL?sum[t]:0;}
	I getmin(I t){return t!=NIL?mim[t]:oo;}
	Z push(I t){
		if(t!=NIL){
			if(rev[t]){
				rev[t]=false;
				if(lch[t]!=NIL)rev[lch[t]]^=1;
				if(rch[t]!=NIL)rev[rch[t]]^=1;
				swap(lch[t],rch[t]);
			}
			if(acc[t]){
				val[t]+=acc[t];
				if(lch[t]!=NIL)acc[lch[t]]+=acc[t];
				if(rch[t]!=NIL)acc[rch[t]]+=acc[t];
				acc[t]=0;
			}
		}
	}
	Z update(I t){
		if(t!=NIL){
			cnt[t]=getcount(lch[t])+getcount(rch[t])+1;
			sum[t]=getsum(lch[t])+getsum(rch[t])+val[t];
			I mc=min(getmin(lch[t]),getmin(rch[t]));
			mim[t]=min(mc,val[t]);
		}
	}
	I newnode(I v,I l,I r){
		assert(szz<MAXS);
		val[szz]=v;
		mim[szz]=v;
		lch[szz]=l;
		rch[szz]=r;
		update(szz);
		return szz++;
	}
	I build(I b,I e){//WARNING: Call root=build(0,n-1)
		if(b>e)return NIL;
		I m=(b+e)>>1;
		return newnode(arr[m],build(b,m-1),build(m+1,e));
	}
	Z split(I t,I &l,I &r,I cnt){
		if(t==NIL)l=r=NIL;
		else{
			push(t);
			I tmp=getcount(lch[t]);
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
	I merge(I l,I r){
		if(l==NIL or r==NIL)return l==NIL?r:l;
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
	Z insert(I idx,I val){
		if(idx>getcount(root))return;
		I n1,n2;
		split(root,n1,n2,idx);
		root=merge(n1,newnode(val,NIL,NIL));
		root=merge(root,n2);
	}
	Z erase(I idx){
		if(getcount(root)<=idx)return;
		I n1,n2,n3;
		split(root,n1,n2,idx);
		split(n2,n2,n3,1);
		root=merge(n1,n3);
	}
	Z reverse(I l,I r){
		I n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		rev[n2] ^= 1;
		root=merge(n1,n2);
		root=merge(root,n3);
	}
	Z rotate(I l,I r,I k){
		if(l > r)return;
		I n1,n2,n3,n4;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		k %= getcount(n2);
		split(n2,n2,n4,getcount(n2)- k);
		root=merge(n1,n4);
		root=merge(root,n2);
		root=merge(root,n3);
	}
	I sumquery(I l,I r){
		I n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		I ans=getsum(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}
	Z sumquery(I l,I r,I v){
		I n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		acc[n2]+=v;
		root=merge(n1,n2);
		root=merge(root,n3);
	}
	I minquery(I l,I r){
		I n1,n2,n3;
		split(root,n1,n2,l);
		split(n2,n2,n3,r-l+1);
		I ans=getmin(n2);
		root=merge(n1,n2);
		root=merge(root,n3);
		return ans;
	}
	I reversortfind(I a){
		I l,r,m;
		l=a-1;
		r=szz-1;
		while(l<r){
			m=(l+r)/2;
			if(minquery(a-1,m)==a)r=m;
			else l=m+1;
		}
		return l;
	}
};

/*
	 	QUERY TYPES:
		1. ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example,performing "ADD 2 4 1" on {1,2,3,4,5} results in {1,3,4,5,5}
		2. REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example,performing "REVERSE 2 4" on {1,2,3,4,5} results in {1,4,3,2,5}
		3. REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example,performing "REVOLVE 2 4 2" on {1,2,3,4,5} results in {1,3,4,2,5}
		4. INSERT x P: insert P after Ax. For example,performing "INSERT 2 4" on {1,2,3,4,5} results in {1,2,4,3,4,5}
		5. DELETE x: delete Ax. For example,performing "DELETE 2" on {1,2,3,4,5} results in {1,3,4,5}
		6. MIN x y: what is the minimum number in sub-sequence {Ax ... Ay}. For example,the correct answer to "MIN 2 4" on {1,2,3,4,5} is 2
		7. SUM x y: what is the sum of all numbers in sub-sequence {Ax...Ay}. For example,the answer to "SUM 3 5" on {1,2,3,4,5} is 12
	*/

Z az(){
	in>>treap::arr[i];
	treap::initialize();
	treap::root=treap::build(0,n-1);
}