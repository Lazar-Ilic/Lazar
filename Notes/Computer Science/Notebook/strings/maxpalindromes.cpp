// Description: For each position in a string, computes p[0][i] = half length of longest even palindrome around pos i, p[1][i] = longest odd (half rounded down)
// Time: O(N)
array<V,2> maxpalindromes(const S& s){//adamant
	I n=sz(s);
	array<V,2> p={V(n+1),V(n)};
	rep(z,0,2)for(I i=0,l=0,r=0;i<n;i++){
		I t = r-i+!z;
		if(i<r)p[z][i]=min(t,p[z][l+t]);
		I left=i-p[z][i],right=i+p[z][i]-!z;
		while(left>=1 && right+1<n && s[left-1]==s[right+1])
			p[z][i]++,left--,right++;
		if(right>r)l=left,r=right;
	}
	return p;
}
//ap[0][a] contains max/2 around a-1/2
//ap[1][a] contains (max-1)/2 around a