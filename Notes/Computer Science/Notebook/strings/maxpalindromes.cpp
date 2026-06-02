// Description: For each position in a string, computes ppp[0][i] = half length of longest even palindrome around pos i, ppp[1][i] = longest odd (half rounded down)
// Time: O(N)
VV maxpalindromes(const S& s){//adamant
	I n=sz(s);
	VV ppp={V(n+1),V(n)};
	rep(z,0,2)for(I i=0,l=0,r=0;i<n;i++){
		I t = r-i+!z;
		if(i<r)ppp[z][i]=min(t,ppp[z][l+t]);
		I left=i-ppp[z][i],right=i+ppp[z][i]-!z;
		while(left>=1 && right+1<n && s[left-1]==s[right+1])
			ppp[z][i]++,left--,right++;
		if(right>r)l=left,r=right;
	}
	return ppp;
}
//ppp[0][a] contains max/2 around a-1/2
//ppp[1][a] contains (max-1)/2 around a