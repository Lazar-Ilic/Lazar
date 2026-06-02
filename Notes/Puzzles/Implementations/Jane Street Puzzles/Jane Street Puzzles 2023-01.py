lim=100
av=[]
m=0
for a in range(lim+1):
	for b in range(lim+1):
		for c in range(lim+1):
			for d in range(lim+1):
				z=1
				aa=a
				bb=b
				cc=c
				dd=d
				while aa+bb+cc+dd!=0:
					z+=1
					aaa=abs(aa-bb)
					bbb=abs(bb-cc)
					ccc=abs(cc-dd)
					ddd=abs(dd-aa)
					aa=aaa
					bb=bbb
					cc=ccc
					dd=ddd
				if m==0 or z>m or (z==m and a+b+c+d<av[0]+av[1]+av[2]+av[3]):
					m=z
					av=[a,b,c,d]
print(m) # 14
print(av) # 0 7 20 44