I lcs(S as,S bs){
	I a,b;
	I aa[sz(as)][sz(bs)];
	for(a=0;a<sz(as);a++){
		fill(aa[a],aa[a]+sz(bs),0);
	}
	for(a=0;a<sz(as);a++){
		if(as[a]==bs[0]){
			aa[a][0]=1;
		}
		if(a!=0){
			aa[a][0]=max(aa[a][0],aa[a-1][0]);
		}
	}
	for(a=0;a<sz(bs);a++){
		if(as[0]==bs[a]){
			aa[0][a]=1;
		}
		if(a!=0){
			aa[0][a]=max(aa[0][a],aa[0][a-1]);
		}
	}
	for(a=1;a<sz(as);a++){
		for(b=1;b<sz(bs);b++){
			if(as[a]==bs[b]){
				aa[a][b]=aa[a-1][b-1]+1;
			}
			else{
				aa[a][b]=max(aa[a-1][b],aa[a][b-1]);
			}
		}
	}
	return aa[sz(as)-1][sz(bs)-1];
}

I lcs(V av,V bv){
	I a,b;
	I aa[sz(av)][sz(bv)];
	for(a=0;a<sz(av);a++){
		fill(aa[a],aa[a]+sz(bv),0);
	}
	for(a=0;a<sz(av);a++){
		if(av[a]==bv[0]){
			aa[a][0]=1;
		}
		if(a!=0){
			aa[a][0]=max(aa[a][0],aa[a-1][0]);
		}
	}
	for(a=0;a<sz(bv);a++){
		if(av[0]==bv[a]){
			aa[0][a]=1;
		}
		if(a!=0){
			aa[0][a]=max(aa[0][a],aa[0][a-1]);
		}
	}
	for(a=1;a<sz(av);a++){
		for(b=1;b<sz(bv);b++){
			if(av[a]==bv[b]){
				aa[a][b]=aa[a-1][b-1]+1;
			}
			else{
				aa[a][b]=max(aa[a-1][b],aa[a][b-1]);
			}
		}
	}
	return aa[sz(av)-1][sz(bv)-1];
}