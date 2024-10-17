limit=100
av=[0 for a in range(1+limit)]
av[1]=1
factorials=[1 for a in range (1+limit)]
for a in range(2,1+limit):
	factorials[a]=a*factorials[a-1]
	denominator=(2**a)-1
	for b in range(1,a):
		av[a]+=av[b]*factorials[a]/(factorials[b]*factorials[a-b]*denominator)
print(av)