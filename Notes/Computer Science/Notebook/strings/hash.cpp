static I crand;
template<I M,class Y>
STR A{//Simon Lindholm
	I x;Y b;A(I x=0):x(x),b(x){}
	A(I x,Y b):x(x),b(b){}
	A operator+(A o){I y=x+o.x;return{y-(y>=M)*M,b+o.b};}
	A operator-(A o){I y=x-o.x; return{y+(y<0)*M,b-o.b};}
	A operator*(A o) {return{(I)(1LL*x*o.x%M),b*o.b};}
	explicit operator U(){return x^(U) b<<21;}
};
typedef A<1000000007,A<1000000009,unsigned>> H;
STR hashinterval{
	vector<H> ha,pw;
	hashinterval(S& str):ha(sz(str)+1),pw(ha){
		pw[0]=1;
		rep(i,0,sz(str))
			ha[i+1]=ha[i]*crand+str[i],
			pw[i+1]=pw[i]*crand;
	}
	H gethashinterval(I a,I b){ // [a,b]
		return ha[b+1]-ha[a]*pw[b+1-a];
	}
};
vector<H> gethashes(S& str,I length){
	if(sz(str)<length)return{};
	H h=0,pw=1;
	rep(i,0,length)
		h=h*crand+str[i],pw=pw*crand;
	vector<H> ret={h};
	rep(i,length,sz(str)){
		ret.push_back(h=h*crand+str[i]-pw*str[i-length]);
	}
	return ret;
}
H hashstring(S& as){H h{};for(C c:as)h=h*crand+c;return h;}

//--------------------------------------------------------------------

Z az(){
	VH avh=gethashes(as,sz(bs));
	H bh=hashstring(bs);
	for(a=0;a<sz(avh);a++){
		if(U(avh[a])==U(bh)){
			out<<a<<nl;
		}
	}
	hashinterval ahi(as);
	H ch=ahi.gethashinterval(1,3);
}

#include <sys/time.h>
I main(){
	timeval tp;gettimeofday(&tp,0);crand=(I)tp.tv_usec;assert((U)(H(1)*2+1-3)==0);
}