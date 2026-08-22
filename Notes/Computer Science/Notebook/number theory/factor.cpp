// Description: Pollard-Rho randomised factorisation algorithm. Returns prime factors of a number, in arbitrary order [e.g. 2299 -> {11, 19, 11}].
// Time: O[n^[1/4]], less for numbers with small factors
L modmultiply(L a,L b,L mod){//chilli,SJTU,pajenegod
	L ret=a*b-mod*L(1.L/mod*a*b);
	return ret+mod*(ret<0)-mod*(ret>=(L)mod);
}
L modpower(L a,L b,L mod){
	L ans=1;
	for(;b;a=modmultiply(a,a,mod),b/=2)
		if(b&1)ans=modmultiply(ans,a,mod);
	return ans;
}
B isprime(L n){
	if(n<2 or n%6%4!=1)return (n|1)==3;
	L aaa[]={2,325,9375,28178,450775,9780504,1795265022},
	    s=__builtin_ctzll(n-1),d=n>>s;
	for(L a:aaa){
		L ppp=modpower(a%n,d,n),i=s;
		while(ppp!=1 and ppp!=n-1 and a%n and i--)
			ppp=modmultiply(ppp,ppp,n);
		if(ppp!=n-1 and i!=s)return 0;
	}
	return 1;
}
L pollard(L n){
	auto f=[n](L x){return modmultiply(x,x,n)+1;};
	L x=0,y=0,t=30,prd=2,i=1,q;
	while(t++%40 or __gcd(prd,n)==1){
		if(x==y)x=++i,y=f(x);
		if((q=modmultiply(prd,max(x,y)-min(x,y),n)))prd=q;
		x=f(x),y=f(f(y));
	}
	return __gcd(prd, n);
}
VL factor(L n){
	if(n==1)return{};
	if(isprime(n))return{n};
	L x=pollard(n);
	auto l=factor(x),r=factor(n/x);
	l.insert(l.end(),all(r));
	sort(all(l));
	return l;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){
	VPL avpl=primefactorisationof(n);
	VL avl={1};
	for(auto primefactor:avpl){
		VL bvl;
		L al=1;
		for(int a=0;a<primefactor.second;a++){
			al*=primefactor.first;
			bvl.add(al);
		}
		for(int a=sz(avl)-1;a>=0;a--){
			for(auto multiplier:bvl)avl.add(avl[a]*multiplier);
		}
	}
	sortify(avl);
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
}

//----------

/*
Warning this code will Time Limit Exceeded by a factor of around 5x maybe on runtime if executed in competition on CodeForces...
*/


I maximum=400001; // SSRS_
V spf(maximum+1,-1);
V primes;

VL factor(L n){
	VL avl;
	while(n>1){
		avl.add(spf[n]);
		n/=spf[n];
	}
	sortify(avl);
	return avl;
}

VPL primefactorisationof(L n){
	VL avl=factor(n);
	VPL avpl;
	for(L al:avl){
		if(sz(avpl)==0 or al!=avpl[sz(avpl)-1].first){
			avpl.add({al,1});
		}
		else{
			avpl[sz(avpl)-1].second++;
		}
	}
	return avpl;
}

VL factorsof(L n){ // Could plausibly be improved quite non trivially by considering sharper underlying execution and memory handling and also potentially even better handling if desiring the factorsof multiple different numbers at the same time.
	VPL avpl=primefactorisationof(n);
	VL avl,bvl;
	VVL avvl;
	I a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
	while(sz(avpl)<15)avpl.add({1,0});
	for(a0=0;a0<15;a0++){
		bvl=VL(0);
		L cl=1;
		for(a1=0;a1<=avpl[a0].second;a1++){
			bvl.add(cl);
			cl*=avpl[a0].first;
		}
		avvl.add(bvl);
	}
	for(a0=0;a0<=avpl[0].second;a0++){
	for(a1=0;a1<=avpl[1].second;a1++){
	for(a2=0;a2<=avpl[2].second;a2++){
	for(a3=0;a3<=avpl[3].second;a3++){
	for(a4=0;a4<=avpl[4].second;a4++){
	for(a5=0;a5<=avpl[5].second;a5++){
	for(a6=0;a6<=avpl[6].second;a6++){
	for(a7=0;a7<=avpl[7].second;a7++){
	for(a8=0;a8<=avpl[8].second;a8++){
	for(a9=0;a9<=avpl[9].second;a9++){
	for(a10=0;a10<=avpl[10].second;a10++){
	for(a11=0;a11<=avpl[11].second;a11++){
	for(a12=0;a12<=avpl[12].second;a12++){
	for(a13=0;a13<=avpl[13].second;a13++){
	for(a14=0;a14<=avpl[14].second;a14++){
		avl.add(avvl[0][a0]*avvl[1][a1]*avvl[2][a2]*avvl[3][a3]*avvl[4][a4]*avvl[5][a5]*avvl[6][a6]*avvl[7][a7]*avvl[8][a8]*avvl[9][a9]*avvl[10][a10]*avvl[11][a11]*avvl[12][a12]*avvl[13][a13]*avvl[14][a14]);
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
	sort(all(avl));
	return avl;
}

VL factorsofset(VL avl){ // Can be improved with Greatest Common Divisor analysis.
	VL bvl=factorsof(avl[0]);
	for(I a=1;a<sz(avl);a++){
		VL cvl=factorsof(avl[a]);
		SETL asetl;
		for(auto dude1:bvl){
			for(auto dude2:cvl){
				asetl.insert(dude1*dude2);
			}
		}
		cvl=VL(0);
		for(auto dude1:asetl)cvl.add(dude1);
		bvl=cvl;
	}
	return bvl;
}


Z az(){
	C ac,bc,cc,dc,ec,fc,gc,hc,ic,jc,kc,lc,mc;
	D ad,bd,cd,dd,ed,fd,gd,hd,id,jd,kd,ld,md;
	I a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,q,r,s,t,u,v,w,x,y,z;
	L al,bl,cl,dl,el,fl,gl,hl,il,jl,kl,ll,ml;
	S as,bs,cs,ds,es,fs,gs,hs,is,js,ks,ls,ms;
	V av,bv,cv,dv,ev,fv,gv,hv,iv,jv,kv,lv,mv;
	P ap,bp,cp,dp,ep,fp,gp,hp,ip,jp,kp,lp,mp;
	VD avd,bvd,cvd,dvd,evd,fvd,gvd,hvd,ivd,jvd,kvd,lvd,mvd;
	VL avl,bvl,cvl,dvl,evl,fvl,gvl,hvl,ivl,jvl,kvl,lvl,mvl;
	VS avs,bvs,cvs,dvs,evs,fvs,gvs,hvs,ivs,jvs,kvs,lvs,mvs;
	VV avv,bvv,cvv,dvv,evv,fvv,gvv,hvv,ivv,jvv,kvv,lvv,mvv;
	VB avb,bvb,cvb,dvb,evb,fvb,gvb,hvb,ivb,jvb,kvb,lvb,mvb;
	VP avp,bvp,cvp,dvp,evp,fvp,gvp,hvp,ivp,jvp,kvp,lvp,mvp;
	PL apl,bpl,cpl,dpl,epl,fpl,gpl,hpl,ipl,jpl,kpl,lpl,mpl;
	VVL avvl,bvvl,cvvl,dvvl,evvl,fvvl,gvvl,hvvl,ivvl,jvvl;
	VVV avvv,bvvv,cvvv,dvvv,evvv,fvvv,gvvv,hvvv,ivvv,jvvv;
	VVB avvb,bvvb,cvvb,dvvb,evvb,fvvb,gvvb,hvvb,ivvb,jvvb;
	SET aset,bset,cset,dset,eset,fset,gset,hset,iset,jset;
	USET auset,buset,cuset,duset,euset,fuset,guset,huset;
	MSET amset,bmset,cmset,dmset,emset,fmset,gmset,hmset;
	MII amii,bmii,cmii,dmii,emii,fmii,gmii,hmii,imii,jmii;
	UMII aumii,bumii,cumii,dumii,eumii,fumii,gumii,humii;
	DQ adq,bdq,cdq,ddq,edq,fdq,gdq,hdq,idq,jdq,kdq,ldq,mdq;
	Q aq,bq,cq,dq,eq,fq,gq,hq,iq,jq,kq,lq,mq;
	PQ apq,bpq,cpq,dpq,epq,fpq,gpq,hpq,ipq,jpq,kpq,lpq,mpq;
	ST ast,bst,cst,dst,est,fst,gst,hst,ist,jst,kst,lst,mst;
	MINPQ aminpq,bminpq,cminpq,dminpq,eminpq,fminpq,gminpq;

/*
Post Contest Analysis:


Test + Additional Input:


Analysis:

*/

	for(a=2;a<=maximum;a++){
		if(spf[a]==-1){
			primes.add(a);
			for(b=a;b<=maximum;b+=a){
				if(spf[b]==-1)spf[b]=a;
			}
		}
	}
}

I main(){zz();I a=1;in>>a;while(a--){az();}}