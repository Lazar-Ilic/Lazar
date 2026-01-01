L chose[1001][1001]; // Can set as needed or use VV from main() or az(). And use I not L.
Z precomputechose(I a){
	I b,c;
	chose[0][0]=1;
	for(b=1;b<=a;b++){
		chose[b][0]=1;
		for(c=1;c<=b;c++)chose[b][c]=(chose[b-1][c-1]+chose[b-1][c])%p;
	}
}
Z precomputechose2(I a,I b){ // Through [a choose b] inclusive.
	I c,d;
	chose[0][0]=1;
	for(c=1;b<=a;b++){
		chose[c][0]=1;
		for(d=1;d<=b;d++)chose[c][d]=(chose[c-1][d-1]+chose[c-1][d])%p;
	}
}
L achose[10001];
Z precomputeachose(L al){
	L bl,cl;
	achose[0]=1;
	achose[al]=1;
	for(bl=1;bl<=(al/2);bl++){
		cl=achose[bl-1]*(al+1-bl)%p*inverse(bl)%p;
		achose[bl]=cl;
		achose[al-bl]=cl;
	}
}
L aexp[10001];
Z precomputeaexp(L al){
	I a;
	aexp[0]=1;
	for(a=1;a<=al;a++){
		aexp[a]=(aexp[a-1]*al)%p;
	}
}
L pinverses[2000001];
Z precomputepinverses(L al){
	I a;
	pinverses[1]=1;
	for(a=2;a<al;a++){
		pinverses[a]=al-(al/a)*pinverses[al%a]%al;
	}
}
L stirling[5001][5001];
Z precomputestirling(){
	I a,b;
	stirling[0][0]=1;
	for(a=1;a<=5000;a++){
		for(b=1;b<=a;b++){
			stirling[a][b]=((a-1)*stirling[a-1][b]+stirling[a-1][b-1])%p;
		}
	}
}
//Z precomputechose(I a)
//Z precomputeachose(L al)
//Z precomputepinverses(L al)
//Z precomputeaexp(L al)
//Z precomputepinverses(L al)
//Z precomputestirling()