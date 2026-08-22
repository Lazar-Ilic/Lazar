// Description: Finds the lexicographically smallest rotation of a string.
// Time: O(N)
// Usage:
//  rotate(v.begin(), v.begin()+minrotation(v), v.end());
I minrotation(S as){//Stjepan Glavina
	I a=0,N=sz(as);as+=as;
	rep(b,0,N)rep(k,0,N){
		if(a+k==b or as[a+k]<as[b+k]){b+=max(0,k-1);break;}
		if(as[a+k]>as[b+k]){a=b;break;}
	}
	return a;
}