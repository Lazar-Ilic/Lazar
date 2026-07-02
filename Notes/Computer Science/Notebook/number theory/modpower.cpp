const L mod=1000000007; // faster if const
L modpower(L a,L b){//Noam527
	L ans=1;
	for(;b;a=a*a%mod,b/=2)
		if(b&1)ans=ans*a%mod;
	return ans;
}