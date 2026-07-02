phi=[0]*10000001
for a in range(0,1+10000000):
	phi[a]=a
for a in range(2,1+10000000):
	if phi[a]==a:
		for b in range (a,1+10000000,a):
			phi[b]=phi[b]-phi[b]//a