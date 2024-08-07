from functools import reduce
def chineseremainder(n,a):
	sum=0
	prod=reduce(lambda a,b:a*b,n)
	for n_i,a_i in zip(n,a):
		p=prod//n_i
		sum+=a_i*mulinv(p,n_i)*p
	return sum%prod

def mulinv(a,b):
	b0=b
	x0,x1=0,1
	if b==1:return 1
	while a>1:
		q=a//b
		a,b=b,a%b
		x0,x1=x1-q*x0,x0
	if x1<0:x1+=b0
	return x1

n=[3,5,7]
a=[2,3,2]
print(chineseremainder(n,a))