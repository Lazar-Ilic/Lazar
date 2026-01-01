// Description: z[x] computes the length of the longest common prefix of s[i:] and s, except z[0] = 0. [abacaba -> 0010301]

// Time: O[n]

V maxprefix(S as){//chilli
	V z(sz(as));
	I l = -1, r = -1;
	rep(i,1,sz(as)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(as) && as[i + z[i]] == as[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

//--------------------------------------------------------------------

V maxprefix(S as){
	V av(sz(as));
	I a,b,c;
	b=0;
	c=0;
	for(a=1;a<sz(as);a++){
		av[a]=max(0,min(av[a-b],c-a+1));
		while(a+av[a]<sz(as) and as[av[a]]==as[a+av[a]]){
			b=a;
			c=a+av[a];
			av[a]++;
		}
	}
	return av;
}