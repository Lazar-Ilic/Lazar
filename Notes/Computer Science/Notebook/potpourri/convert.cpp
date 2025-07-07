PSL convert(S as,I from,I to){
	V av(sz(as));
	I a;
	L al=0;
	S bs;
	PSL apsl;
	for(a=sz(as)-1;a>=0;a--){
		if(as[a]>='0' and as[a]<='9')av[a]=as[a]-'0';
		else av[a]=as[a]-'A'+10;
		if(av[a]>=from)return {"-1",-1};
		al+=pow(L(from),sz(as)-1-a)*av[a];
	}
	apsl.second=al;
	while(al!=0){
		if(al%to<=9)bs+=C('0'+al%to);
		else bs+=C('A'-10+al%to);
		al/=to;
	}
	reverse(all(bs));
	apsl.first=bs;
	return apsl;
}