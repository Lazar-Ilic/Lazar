# Can solve for the discrete stable state which recurses into itself here which is the asymptotic approaching limiting case behaviour. Here is a little simulatory implementation which can reveal precisely how rapidly these things occur in a human legible way.

avv=[0 for a in range(12)]
avv[0]=12
for a in range(10000000):
	for b in range(11):
		avv[b]=11*avv[b+1]/12
	avv[11]=1
	avv[0]=0
	avv[0]=12-sum(avv)
print(avv[0]/12)

# 0.3839952305608769