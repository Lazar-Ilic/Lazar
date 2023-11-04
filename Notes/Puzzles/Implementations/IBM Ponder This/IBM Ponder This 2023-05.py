import math
k=5
n=2**20
#av=[2*a/(n-1)-1 for a in range(n)] # x values.
answer=0
for t in range(5):
	avv=[[] for a in range(2**k)]
	for a in range(n):
		avv[math.floor((2**k)*(math.sin((a+1)*(t+1))-math.floor(math.sin((a+1)*(t+1)))))].append(a)
	for a in range(2**k):
		value=0
		for b in avv[a]:
			value+=2*b/(n-1)-1
		answer+=value*value*(2**t)/((2**k)-1)
print(answer) # 52390.27440217222 and 

# C++:

	k=5;
	I ktwo=1<<k;
	n=1<<30;
	LD answer=0;
	for(t=0;t<5;t++){
		avl=VL(ktwo,0);
		bvl=VL(ktwo,0);
		for(a=0;a<n;a++){c=floor((ktwo)*(sin(LD(a+1)*(t+1))-floor(sin(LD(a+1)*(t+1)))));avl[c]+=a;bvl[c]++;} // Can be optimised further.
		LD partialanswer=0;
		for(a=0;a<ktwo;a++)partialanswer+=(LD(2)*avl[a]/(n-1)-bvl[a])*(LD(2)*avl[a]/(n-1)-bvl[a]);
		answer+=partialanswer*(1<<t)/((1<<k)-1);
	}
	out<<setprecision(15)<<answer<<nl; // 52390.2744021636 and 156033.940866479