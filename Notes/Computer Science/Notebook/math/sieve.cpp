// Better In Loop
Z az(){
	I maximum=10000000; // SSRS_
	V spf(maximum+1,-1);
	V primes;
	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}

	in>>a;
	for(b=0;b<a;b++){
		in>>c>>d;
		if(gcd(c,d)>1){
			out<<0<<nl;
		}
		else if(c==d-1){
			out<<-1<<nl;
		}
		else{
			e=d-c;
			m=INT_MAX;
			while(e>1){
				f=spf[e];
				m=min(m,(f-(c%f)));
				e/=f;
			}
			out<<m<<nl;
		}
	}
}

// ----------

VB isprime(1000001,true);
VL primes;
VL spf(1000001);
VL order(1000001);
Z sieve(L al){
    isprime[0]=isprime[1]=false;
    I c;
    for(L b=2;b<=al;b++){
        if(isprime[b]){
            primes.add(b);
            spf[b]=b;
        }
        c=sz(primes);
        for(L d=0;d<c && b*primes[d]<=al && primes[d]<=spf[b];d++){
            isprime[b*primes[d]]=false;
            spf[b*primes[d]]=primes[d];
        }
    }
	for(L b=2;b<=al;b++){
		if(isprime[b]){
			order[b]=1;
		}
		else if((b/spf[b])%spf[b]!=0){
			order[b]=1;
		}
		else{
			order[b]=1+order[b/spf[b]];
		}
	}
}
 
V primefactorsof(I a){
	V av;
	while(a!=1){
		if(sz(av)==0 or spf[a]!=av[sz(av)-1])av.add(spf[a]);
		a/=spf[a];
	}
	return av;
}
 
VP primefactorisationof(I a){
	VP avp;
	while(a!=1){
		if(sz(avp)==0 or spf[a]!=avp[sz(avp)-1].first)avp.add({spf[a],1});
		else if(spf[a]==avp[sz(avp)-1].first)avp[sz(avp)-1].second++;
		a/=spf[a];
	}
	return avp;
}

V factorsof(I n){
	VP avp=primefactorisationof(n);
	V av,bv;
	VV avv;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avp)<15)avp.add({1,0});
	for(a0=0;a0<15;a0++){
		bv=V(0);
		I c=1;
		for(a1=0;a1<=avp[a0].second;a1++){
			bv.add(c);
			c*=avp[a0].first;
		}
		avv.add(bv);
	}
	for(a0=0;a0<=avp[0].second;a0++){
	for(a1=0;a1<=avp[1].second;a1++){
	for(a2=0;a2<=avp[2].second;a2++){
	for(a3=0;a3<=avp[3].second;a3++){
	for(a4=0;a4<=avp[4].second;a4++){
	for(a5=0;a5<=avp[5].second;a5++){
	for(a6=0;a6<=avp[6].second;a6++){
	for(a7=0;a7<=avp[7].second;a7++){
	for(a8=0;a8<=avp[8].second;a8++){
	for(a9=0;a9<=avp[9].second;a9++){
	for(a10=0;a10<=avp[10].second;a10++){
	for(a11=0;a11<=avp[11].second;a11++){
	for(a12=0;a12<=avp[12].second;a12++){
	for(a13=0;a13<=avp[13].second;a13++){
	for(a14=0;a14<=avp[14].second;a14++){
		av.add(avv[0][a0]*avv[1][a1]*avv[2][a2]*avv[3][a3]*avv[4][a4]*avv[5][a5]*avv[6][a6]*avv[7][a7]*avv[8][a8]*avv[9][a9]*avv[10][a10]*avv[11][a11]*avv[12][a12]*avv[13][a13]*avv[14][a14]);
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
	sort(all(av));
	return av;
}