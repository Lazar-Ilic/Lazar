// Description: Given $z$ and a real number $x \ge 0$, finds the closest rational approximation $p/q$ with $p, q \le z$. It will obey $|p/q - x| \le 1/qz$. For consecutive convergents, $p_{k+1}q_k - q_{k+1}p_k = (-1)^k$. ($p_k/q_k$ alternates between $>x$ and $<x$.) If $x$ is rational, $y$ eventually becomes $\infty$; if $x$ is the root of a degree $2$ polynomial the $a$'s eventually become cyclic.
// Time: O(log z)
PL approximate(D x,L z){
	L e=0,f=1,i=1,j=0,inf=LLONG_MAX;D y=x;
	for(;;){
		L lim=min(i?(z-e)/i:inf,j?(z-f)/j:inf),a=(L)floor(y),b=min(a,lim),g=b*i+e,h=b*j+f;
		if(a>b){
			// If b > a/2, we have a semi-convergent that gives us a
			// better approximation; if b = a/2, we *may* have one.
			// Return {i, j} here for a more canonical approximation.
			return (abs(x-(D)g/(D)h)<abs(x-(D)i/(D)j))?make_pair(g,h):make_pair(i,j);
		}
		if(abs(y=1/(y-(D)a))>3*z)return {g,h};
		e=i;i=g;f=j;j=h;
	}
}