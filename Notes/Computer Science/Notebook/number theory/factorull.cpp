// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
ULL modmultiply(ULL a,ULL b,ULL mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*ULL(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
ULL modpower(ULL a,ULL b,ULL mod){
	ULL ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(ULL n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	ULL aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(ULL a:aaa){
		ULL ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
ULL pollard(ULL n){
	auto f=[n](ULL x){return modmultiply(x,x,n)+1;};
	ULL x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VULL factor(ULL n){
	if(n==1)return{};
	if(isprime(n))return{n};
	ULL x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPULL primefactorisationof(ULL n){
	VULL avull=factor(n);
	VPULL avpull;
	for(ULL aull:avull){
		if(sz(avpull)==0 or aull!=avpull[sz(avpull)-1].first){
			avpull.add({aull,1});
		}
		else{
			avpull[sz(avpull)-1].second++;
		}
	}
	return avpull;
}

VULL factorsof(ULL n){
	VPULL avpull=primefactorisationof(n);
	VULL avull,bvull;
	VVULL avvull;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avpull)<15)avpull.add({1,0});
	for(a0=0;a0<15;a0++){
		bvull=VULL(0);
		ULL cull=1;
		for(a1=0;a1<=avpull[a0].second;a1++){
			bvull.add(cull);
			cull*=avpull[a0].first;
		}
		avvull.add(bvull);
	}
	for(a0=0;a0<=avpull[0].second;a0++){
	for(a1=0;a1<=avpull[1].second;a1++){
	for(a2=0;a2<=avpull[2].second;a2++){
	for(a3=0;a3<=avpull[3].second;a3++){
	for(a4=0;a4<=avpull[4].second;a4++){
	for(a5=0;a5<=avpull[5].second;a5++){
	for(a6=0;a6<=avpull[6].second;a6++){
	for(a7=0;a7<=avpull[7].second;a7++){
	for(a8=0;a8<=avpull[8].second;a8++){
	for(a9=0;a9<=avpull[9].second;a9++){
	for(a10=0;a10<=avpull[10].second;a10++){
	for(a11=0;a11<=avpull[11].second;a11++){
	for(a12=0;a12<=avpull[12].second;a12++){
	for(a13=0;a13<=avpull[13].second;a13++){
	for(a14=0;a14<=avpull[14].second;a14++){
		avull.add(avvull[0][a0]*avvull[1][a1]*avvull[2][a2]*avvull[3][a3]*avvull[4][a4]*avvull[5][a5]*avvull[6][a6]*avvull[7][a7]*avvull[8][a8]*avvull[9][a9]*avvull[10][a10]*avvull[11][a11]*avvull[12][a12]*avvull[13][a13]*avvull[14][a14]);
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	sort(all(avull));
	return avull;
}

VULL factorsofset(VULL avull){ // Can be improved with Greatest Common Divisor analysis.
	VULL bvull=factorsof(avull[0]);
	for(I a=1;a<sz(avull);a++){
		VULL cvull=factorsof(avull[a]);
		SETULL asetull;
		for(auto dude1:bvull){
			for(auto dude2:cvull){
				asetull.insert(dude1*dude2);
			}
		}
		cvull=VULL(0);
		for(auto dude1:asetull)cvull.add(dude1);
		bvull=cvull;
	}
	return bvull;
}