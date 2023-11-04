// Description: Builds suffix array for a string.
// Time: O(n log n)
STR suffixarray{//罗穗骞,chilli
	V sfx,lcp;
	suffixarray(S& s,I lim=256){
		I n=sz(s)+1,k=0,a,b;
		V x(all(s)+1),y(n),ws(max(n,lim)),rank(n);
		sfx=lcp=y,iota(all(sfx),0);
		for (I j=0,z=0;z<n;j=max(1,j*2),lim=z){
			z=j,iota(all(y),n-j);
			rep(i,0,n)if(sfx[i]>=j)y[z++]=sfx[i]-j;
			fill(all(ws),0);
			rep(i,0,n)ws[x[i]]++;
			rep(i,1,lim)ws[i]+=ws[i-1];
			for(I i=n;i--;)sfx[--ws[x[y[i]]]]=y[i];
			swap(x,y),z=1,x[sfx[0]]=0;
			rep(i,1,n)a=sfx[i-1],b=sfx[i],x[b]=(y[a]==y[b] && y[a+j]==y[b+j])?z-1:z++;
		}
		rep(i,1,n)rank[sfx[i]]=i;
		for(I i=0,j;i<n-1;lcp[rank[i++]]=k)
			for(k && k--,j=sfx[rank[i]-1];s[i+k]==s[j+k];k++);
	}
};