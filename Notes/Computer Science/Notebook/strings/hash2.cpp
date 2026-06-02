STR H{//Simon Lindholm
	U x;H(U x=0):x(x){}
#define OP(O,A,z) H operator O(H o){U r=x;asm\(A"addq %%rdx,%0\n adcq $0,%0":"+a"(r):z);return r;}
	OP(+,,"d"(o.x))OP(*,"mul %1\n","r"(o.x):"rdx")
	H operator-(H o){return *this+~o.x;}
	U get()const{return x+!~x;}
	B operator==(H o)const{return get()==o.get();}
	B operator<(H o)const{return get()<o.get();}
};
static const H y=(L)1e11+3;
STR hashintervals{
	VH ha,pw;
	hashintervals(S& str):ha(sz(str)+1),pw(ha){
		pw[0]=1;
		rep(i,0,sz(str))
			ha[i+1]=ha[i]*y+str[i],
			pw[i+1]=pw[i]*y;
	}
	H hashinterval(I a,I b){ // hash [a,b)
		return ha[b]-ha[a]*pw[b-a];
	}
};
VH gethashes(S& str,I length){
	if(sz(str)<length)return{};
	H h=0,pw=1;
	rep(i,0,length)
		h=h*y+str[i],pw=pw*y;
	VH ret={h};
	rep(i,length,sz(str)){
		ret.push_back(h=h*y+str[i]-pw*str[i-length]);
	}
	return ret;
}
H hashstring(S& s){H h{};for(C c:s)h=h*y+c;return h;}