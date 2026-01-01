isprime=[1]*100000001
primes=[]
spf=[0]*100000001
order=[0]*100000001
def sieve(a):
	isprime[0]=0
	isprime[1]=0
	for b in range(2,a+1):
		if isprime[b]:
			primes.append(b)
			spf[b]=b
		c=len(primes)
		d=0
		while d<c and b*primes[d]<=a and primes[d]<=spf[b]:
			isprime[b*primes[d]]=0
			spf[b*primes[d]]=primes[d]
			d+=1
	for b in range(2,a+1):
		if isprime[b]:
			order[b]=1
		elif (int(b/spf[b]))%spf[b]!=0:
			order[b]=1
		else:
			order[b]=1+order[int(b/spf[b])]
	return 0
def primefactorsof(a):
	a=int(a)
	av=[]
	while a!=1:
		if len(av)==0 or spf[int(a)]!=av[int(len(av)-1)]:
			av.append(spf[int(a)])
		a/=spf[int(a)]
	return av
def primefactorisationof(a):
	a=int(a)
	avp=[]
	while a!=1:
		if len(avp)==0 or spf[int(a)]!=avp[int(len(avp)-1)][0]:
			avp.append([spf[int(a)],1])
		elif spf[int(a)]==avp[int(len(avp)-1)][0]:
			avp[int(len(avp)-1)][1]+=1
		a/=spf[int(a)]
	return avp
def factorsof(a):
	av=[]
	avp=primefactorisationof(a)
	while len(avp)<15:
		avp.append([1,0])
	avv=[]
	for a1 in range(15):
		bv=[]
		ccc=1
		for a2 in range(1+avp[a1][1]):
			bv.append(ccc)
			ccc*=avp[a1][0]
		avv.append(bv)
	for a1 in range(1+avp[0][1]):
		for a2 in range(1+avp[1][1]):
			for a3 in range(1+avp[2][1]):
				for a4 in range(1+avp[3][1]):
					for a5 in range(1+avp[4][1]):
						for a6 in range(1+avp[5][1]):
							for a7 in range(1+avp[6][1]):
								for a8 in range(1+avp[7][1]):
									for a9 in range(1+avp[8][1]):
										for a10 in range(1+avp[9][1]):
											for a11 in range(1+avp[10][1]):
												for a12 in range(1+avp[11][1]):
													for a13 in range(1+avp[12][1]):
														for a14 in range(1+avp[13][1]):
															for a15 in range(1+avp[14][1]):
																av.append(avv[0][a1]*avv[1][a2]*avv[2][a3]*avv[3][a4]*avv[4][a5]*avv[5][a6]*avv[6][a7]*avv[7][a8]*avv[8][a9]*avv[9][a10]*avv[10][a11]*avv[11][a12]*avv[12][a13]*avv[13][a14]*avv[14][a15])
	av.sort()
	return av

#sieve(100000000)
#print(factorsof(1000))
#Runtime on Colab is ~ 150s
#Can store locally to avoid.