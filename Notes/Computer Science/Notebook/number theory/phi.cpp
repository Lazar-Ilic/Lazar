// Description: phi function is defined as phi(n)=# of positive integers <=n that are coprime with n
const I lim=5000001;
I phi[lim];
Z calculatephi(){//Håkan Terelius
	rep(i,0,lim)phi[i]=i&1?i:i/2;
	for(I i=3;i<lim;i+=2)if(phi[i]==i)
		for(I j=i;j<lim;j+=i)phi[j]-=phi[j]/i;
}