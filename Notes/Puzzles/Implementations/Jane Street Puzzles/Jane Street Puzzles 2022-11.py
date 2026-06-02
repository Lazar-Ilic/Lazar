import math
m=10
av=[]
for a in range(-8,9):
	for b in range(-8,9):
		for c in range(-8,9):
			for d in range(-8,9):
				for e in range(-8,9):
					f=0
					g=0
					if a<0:
						f+=(-a)
					else:
						g+=a
					if b<0:
						f+=(-b)
					else:
						g+=b
					if c<0:
						f+=(-c)
					else:
						g+=c
					if d<0:
						f+=(-d)
					else:
						g+=d
					if e<0:
						f+=(-e)
					else:
						g+=e
					if f<=8 and g<=8 and (f+g)%2==0:
						# TOFIX "BLAH" if(math.sqrt((a+b*math.cos(2*math.pi*1/5)+c*math.cos(2*math.pi*2/5)+d*math.cos(2*math.pi*3/5)+e*math.cos(2*math.pi*4/5))**2+(b*math.sin(2*math.pi*1/5)+c*math.sin(2*math.pi*2/5)+d*math.sin(2*math.pi*3/5)+e*math.sin(2*math.pi*4/5))**2)>BLAH and math.sqrt((a+b*math.cos(2*math.pi*1/5)+c*math.cos(2*math.pi*2/5)+d*math.cos(2*math.pi*3/5)+e*math.cos(2*math.pi*4/5))**2+(b*math.sin(2*math.pi*1/5)+c*math.sin(2*math.pi*2/5)+d*math.sin(2*math.pi*3/5)+e*math.sin(2*math.pi*4/5))**2)<m):
							m=math.sqrt((a+b*math.cos(2*math.pi*1/5)+c*math.cos(2*math.pi*2/5)+d*math.cos(2*math.pi*3/5)+e*math.cos(2*math.pi*4/5))**2+(b*math.sin(2*math.pi*1/5)+c*math.sin(2*math.pi*2/5)+d*math.sin(2*math.pi*3/5)+e*math.sin(2*math.pi*4/5))**2)
							av=[a,b,c,d,e]
print(m)
print(av)

# 0.1387573 seems OK