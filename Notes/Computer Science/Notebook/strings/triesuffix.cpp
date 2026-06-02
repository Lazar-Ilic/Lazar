// Description: Ukkonen's algorithm for online suffix tree construction. Each node contains indices [l,r) into the string, and a list of child nodes. Suffixes are given by traversals of this tree, joining [l,r) substrings. The root is 0 (has l=-1,r=0), non-existent children are -1. To get a complete tree, append a dummy symbol -- otherwise it may contain an incomplete path (still useful for substring matching, though).
// Time: O(26N)
STR triesuffix{
	enum{z=200010,alphasize=26}; // z ~ 2*maxlen+10
	I toi(C c){return c-'a';}
	S a; // v = cur node, q = cur position
	I t[z][alphasize],l[z],r[z],y[z],s[z],v=0,q=0,m=2;
	Z ukkadd(I i,I c){suff:
		if(r[v]<=q){
			if(t[v][c]==-1){t[v][c]=m;l[m]=i;
				y[m++]=v;v=s[v];q=r[v];goto suff;}
			v=t[v][c];q=l[v];
		}
		if(q==-1 or c==toi(a[q]))q++;else{
			l[m+1]=i;y[m+1]=m;l[m]=l[v];r[m]=q;
			y[m]=y[v];t[m][c]=m+1;t[m][toi(a[q])]=v;
			l[v]=q;y[v]=m;t[y[m]][toi(a[l[m]])]=m;
			v=s[y[m]];q=l[m];
			while(q<r[m]){v=t[v][toi(a[q])];q+=r[v]-l[v];}
			if(q==r[m])s[m]=v;else s[m]=m+2;
			q=r[v]-(q-r[m]);m+=2;goto suff;
		}
	}
	triesuffix(S a):a(a){
		fill(r,r+z,sz(a));
		memset(s,0,sizeof s);
		memset(t,-1,sizeof t);
		fill(t[1],t[1]+alphasize,0);
		s[0]=1;l[0]=l[1]=-1;r[0]=r[1]=y[0]=y[1]=0;
		rep(i,0,sz(a))ukkadd(i,toi(a[i]));
	}
	// example: find longest common substring (uses alphasize = 28)
	P best;
	I lcs(I node,I i1,I i2,I olen){
		if(l[node]<=i1 and i1<r[node])return 1;
		if(l[node]<=i2 and i2<r[node])return 2;
		I mask=0,len=node?olen+(r[node]-l[node]):0;
		rep(c,0,alphasize)if(t[node][c]!=-1)
			mask|=lcs(t[node][c],i1,i2,len);
		if(mask==3)best=max(best,{len,r[node]-len});
		return mask;
	}
	static P LCS(S s,S t){
		triesuffix st(s+(C)('z'+1)+t+(C)('z'+2));
		st.lcs(0,sz(s),sz(s)+1+sz(t),0);
		return st.best;
	}
};