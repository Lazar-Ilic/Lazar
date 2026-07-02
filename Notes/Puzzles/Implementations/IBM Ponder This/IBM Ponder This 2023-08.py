import math
av=[1,36]
bv=[0,math.log(36)]
while (av[len(av)-1]-1)*(av[len(av)-1]-1)//av[len(av)-2] < 10**500:
	av.append((av[len(av)-1]-1)*(av[len(av)-1]-1)//av[len(av)-2])
	bv.append(math.log((av[len(av)-1]-1)*(av[len(av)-1]-1)//av[len(av)-2]))
	print(len(bv)+(math.log(10)*(10**100))//(bv[len(bv)-1]-bv[len(bv)-2]))
print(av)
print(len(av))

# PARI-GP:
\p 2500
a=1
b=36
c=2
g=10^100
h=10^1000
f()=
{
	d=(b-1)*(b-1)/a;
	c+=1;
	a=b;
	b=d;
	print(floor(c+(log(10)*g-log(b))/(log(b)-log(a))));
	if(b<h,f());
}
f()
quit()
#6531240347184892454849237722169246600586075961192434058882920840740253494104859805019550623847957752