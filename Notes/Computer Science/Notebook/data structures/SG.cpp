// Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
// Time: O(log N)
STR SG{//Lucian Bicsi
	//0 1 inf -inf etc. for function coherence
	//static constexpr L unit = 0;
	//static constexpr L unit = 1;
	//static constexpr L unit = 1000000000000000001;
	//static constexpr L unit = -1000000000000000001;
	L f(L a, L b){ // any associative function
		//return (a+b)%p;//unit 0
		//return a+b;//unit 0
		//return min(a,b);//unit 1000000000000000001
		//return max(a,b);//unit -1000000000000000001
		//return (a bx b);//unit 0
		//return gcd(a,b);//unit 0
		//return lcm(a,b);//unit 0
	}
	VL s;L n;
	SG(L n=0,L def=unit):s(2*n,def),n(n){}
	Z update(L position,L value){
		for (s[position+=n]=value;position/=2;)
			s[position]=f(s[position*2],s[position*2+1]);
	}
	L query(L a,L b){ // query [a,b]
		b++;
		L left=unit,right=unit;
		for(a+=n,b+=n;a<b;a/=2,b/=2){
			if(a%2)left=f(left,s[a++]);
			if(b%2)right=f(s[--b],right);
		}
		return f(left,right);
	}
};

// ----------

// Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
// Time: O(log N)
STR SG{//Lucian Bicsi
	//0 1 inf -inf etc. for function coherence
	static constexpr L unit = 0;
	//static constexpr L unit = 1;
	//static constexpr L unit = 1000000000000000001;
	//static constexpr L unit = -1000000000000000001;
	L f(L a, L b){ // any associative function
		//return (a+b)%p;//unit 0
		return a+b;//unit 0
		//return min(a,b);//unit 1000000000000000001
		//return max(a,b);//unit -1000000000000000001
		//return (a bx b);//unit 0
		//return gcd(a,b);//unit 0
		//return lcm(a,b);//unit 0
	}
	VL s;L n;
	SG(L n=0,L def=unit):s(2*n,def),n(n){}
	Z update(L position,L value){
		for (s[position+=n]=value;position/=2;)
			s[position]=f(s[position*2],s[position*2+1]);
	}
	L query(L a,L b){ // query [a,b]
		b++;
		L left=unit,right=unit;
		for(a+=n,b+=n;a<b;a/=2,b/=2){
			if(a%2)left=f(left,s[a++]);
			if(b%2)right=f(s[--b],right);
		}
		return f(left,right);
	}
};



	SG asg(5);
	asg.update(1,3);
	asg.update(2,5);
	out<<asg.query(0,1)<<endl; // 3
	out<<asg.query(1,4)<<endl; // 8