// Description: Sums of mod'ed arithmetic progressions. \texttt{modsum(to, c, k, m)} = $\sum_{i=0}^{\mathrm{to}-1}{(ki+c) \% m}$. \texttt{divsum} is similar but for floored division.
// Time: O(log m), with a large constant.
ULL sumsq(ULL to){return to/2*((to-1)|1);}
/// ^ written in a weird way to deal with overflows correctly
ULL divsum(ULL to,ULL c,ULL k,ULL m){//Simon Lindholm
	ULL res=k/m*sumsq(to)+c/m*to;
	k%=m;c%=m;
	if(!k)return res;
	ULL to2=(to*k+c)/m;
	return res+(to-1)*to2-divsum(to2,m-1-c,m,k);
}
L modsum(ULL to,L c,L k,L m){
	c=((c%m)+m)%m;
	k=((k%m)+m)%m;
	return to*c+k*sumsq(to)-m*divsum(to,c,k,m);
}