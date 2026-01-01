L factorials[2000001];
I factorialsmax;
L factorial(L al){
	L bl;
	factorials[0]=1;
	if(al<=factorialsmax){
		return factorials[al];
	}
	else{
		for(bl=factorialsmax+1;bl<=al;bl++){
			factorials[bl]=factorials[bl-1]*bl%p;
		}
		factorialsmax=al;
		return factorials[al];
	}
}
L inverse(L al){
	L bl=1;
	I a=p-2;
	while(a!=0){
		if(a%2==1){
			bl=bl*al%p;
		}
		al=al*al%p;
		a/=2;
	}
	return bl;
}
L inversefactorials[2000001];
B inversefactorialsaux[2000001];
L inversefactorial(L al){
	if(inversefactorialsaux[al]==0){
		inversefactorialsaux[al]=1;
		inversefactorials[al]=inverse(factorial(al));
	}
	return inversefactorials[al];
}
// For [A choose B] with A Big And B Small Do Numerator Product In Loop A*.../[B!]
L choose(L al,L bl){
	if(bl>al or bl<0 or al<0)return 0;
	return factorial(al)*inversefactorial(bl)%p*inversefactorial(al-bl)%p;
}
L multinomial(L al,VL avl){
	I a;
	al=factorial(al);
	for(a=0;a<sz(avl);a++){
		al=(al*inversefactorial(avl[a]))%p;
	}
	return al;
}
L exp(L al,L bl){
	L cl=1;
	while(bl>0){
		if(bl%2==1){
			cl=cl*al%p;
		}
		al=al*al%p;
		bl/=2;
	}
	return cl;
}
L exppp(L al,L bl,L cl){ // (Base,Exponent,Modulus)
	UI128 dl=1;
	while(bl>0){
		if(bl%2==1){
			dl=dl*al%cl;
		}
		al=(UI128)al*al%cl;
		bl/=2;
	}
	return dl;
}

// If needed can replace factorialsmax with L and also set a const L limitt=10000000000; depending upon the machine and execution and also switch it up from memory allocation like this to a pair of VLs declared later in loop in main or az(){} to be memory allocated there clearing 64GB of RAM or 128GB RAM.