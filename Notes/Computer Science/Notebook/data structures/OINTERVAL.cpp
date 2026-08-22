I aa[300000];
STR OINTERVAL{//Rachit Jain
	I lo,hi;
	OINTERVAL *l,*r;
	V b;
	// numbers are in range [x,y]
	// array indices are [from,to)
	OINTERVAL(I *from,I *to,I x,I y){
		lo=x,hi=y;
		if(lo==hi or from>=to)return;
		I mid=(lo+hi)/2;
		auto f=[mid](I x){return x<=mid;};
		b.reserve(to-from+1);
		b.add(0);
		for(auto it=from;it!=to;it++)b.add(b.back()+f(*it));
		auto pivot=stable_partition(from,to,f);
		l=new OINTERVAL(from,pivot,lo,mid);
		r=new OINTERVAL(pivot,to,mid+1,hi);
	}
	I kth(I l,I r,I k){ // kth smallest element in [l,r]
		if(l>r)return 0;
		if(lo==hi)return lo;
		I inleft=b[r]-b[l-1];
		I lb=b[l-1];
		I rb=b[r];
		if(k<=inleft)return this->l->kth(lb+1,rb,k);
		return this->r->kth(l-lb,r-rb,k-inleft);
	}
	I LTE(I l,I r,I k){ // count in [l,r] Less than or equal to k
		if(l>r or k<lo)return 0;
		if(hi<=k)return r-l+1;
		I lb=b[l-1],rb=b[r];
		return this->l->LTE(lb+1,rb,k)+this->r->LTE(l-lb,r-rb,k);
	}
	I count(I l,I r,I k){ // count in [l,r] equal to k
		if(l>r or k<lo or k>hi)return 0;
		if(lo==hi)return r-l+1;
		I lb=b[l-1],rb=b[r],mid=(lo+hi)/2;
		if(k<=mid)return this->l->count(lb+1,rb,k);
		return this->r->count(l-lb,r-rb,k);
	}
	~OINTERVAL(){delete l;delete r;}
};

Z az(){
	in>>a;
	for(b=1;b<=a;b++){
		in>>aa[b];
	}
	OINTERVAL aoi(aa+1,aa+a+1,1,1000000);
	out<<aoi.kth(l,r,k)<<nl;
	out<<aoi.LTE(l,r,k)<<nl;
	out<<aoi.count(l,r,k)<<nl;
}