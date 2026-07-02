// Runtime: O[V^2]
B findmatch(I i,const VVB &w,V &mr,V &mc,V &seen){
	for(I j=0;j<sz(w[i]);j++){
		if(w[i][j] and !seen[j]){
			seen[j]=true;
			if(mc[j]<0 or findmatch(mc[j],w,mr,mc,seen)){
				mr[i]=j;
				mc[j]=i;
				return true;
			}
		}
	}
	return false;
}
I bipartitematching(const VVB &w,V &mr,V &mc){
	mr=V(sz(w),-1);
	mc=V(sz(w[0]),-1);
	I ct=0;
	for(I i=0;i<sz(w);i++){
		V seen(w[0].size());
		if(findmatch(i,w,mr,mc,seen))ct++;
	}
	return ct;
}

//--------------------------------------------------------------------

Z az(){	
	// Misread on https://codeforces.com/contest/1798/problem/B in particular winners are supposed to be banned from future days.
	in>>a;
	VVB avvb(a+50000,VB(a+50000));
	for(d=0;d<a;d++){ // a days you want to schedule up.
		in>>e;
		for(f=0;f<e;f++){
			in>>g;
			g--;
			avvb[d][a+g]=1; // Dude g can play on day a.
		}
	}
	if(bipartitematching(avvb,av,bv)<a){
		out<<-1<<nl;
		return;
	}
	for(c=0;c<a;c++){
		out<<av[c]-a+1<<" "; // The dude scheduled for day c+1.
	}
	out<<nl;
}