import random
def primetest(d,n):
	a=2+random.randint(1,n-4)
	x=pow(a,d,n)
	if x==1 or x==n-1:
		return True
	while d!=n-1:
		x=x*x%n
		d*=2
		if x==1:
			return False
		if x==n-1:
			return True
	return False
def isprime(n,k):
	if n<=1 or n==4:
		return False
	if n<=3:
		return True
	d=n-1
	while d%2==0:
		d//=2
	for i in range(k):
		if primetest(d,n)==False:
			return False
	return True

numiterations=100
for n in range(10**100,10**100+10**4):
	if isprime(n,numiterations):
		print(n)