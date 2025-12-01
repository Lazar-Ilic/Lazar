import math
a=1*2*3*4*6*7*8*9*2*2*3*3*7*7
for b in range(1,100000000):
	c=a*b*b*b
	cc=c
	z=1
	av=[0 for d in range(10)]
	av[0]=1
	av[5]=1
	while cc>0 and z==1:
		if cc%10==0 or cc%10==5:
			z=0
		else:
			av[cc%10]=1
			cc//=10
	if z==1:
		y=1
		cc=c
		ccc=c
		while cc>0 and y==1:
			if ccc%(cc%10)!=0:
				y=0
			else:
				ccc//=(cc%10)
				cc//=10
		if y==1:
			#print(c,ccc)
			cccc=ccc
			for d in range(10):
				if av[d]==0:
					if cccc%d!=0:
						y=0
					else:
						cccc//=d
			if y==1:
				for d in range(2,10):
					while cccc%d==0:
						cccc//=d
			if y==1 and cccc==1:
				cccc=c
				ccccc=c
				while cccc%2==0 and ccccc>0:
					cccc//=2
					ccccc//=10
				print(c,ccc,cccc)
				for d in range(1,1000):
					e=d*cccc
					bv=[0 for f in range(10)]
					cccccc=ccc
					x=1
					while e>0 and x==1:
						if e%10==0 or e%10==5 or cccccc%(e%10)!=0:
							x=0
						else:
							cccccc//=(e%10)
							bv[e%10]==1
							e//=10
					for f in range(10):
						if av[f]==0 and bv[f]==0:
							x=0
					if x==1 and cccccc==1:
						print(d*cccc,c,ccc)

# OK
49787136 196 194481
146313216 56448 285768
1316818944 7938 1285956
4161798144 21504 4064256
84276412416 163296 41150592
149824733184 32256 36578304
189621927936 10752 46294416
12646729138176 345744 771895089
36877862166921216 7001316 562711519881
764699349893278334976 263424 364637064882888

for a in range(31):
	for b in range(a+1,31):
		for c in range(31):
			for d in range(c+1,31):
				if a!=c and a!=d and b!=c and b!=d and (((10**31)-1)//9+(10**a)+(10**b)+6*(10**c)+6*(10**d))%194481==0:
					print((((10**31)-1)//9+(10**a)+(10**b)+6*(10**c)+6*(10**d)))

# OK
1111121111111111711111171111112
1117111111111117211111111111211
1111111117111111111111121172111
1111171111112111171111111121111
1171121111111111112111117111111
1172111117121111111111111111111
1111217171211111111111111111111
2111111121711111111111111171111
2121171111111111111111171111111

# Leads to 111111111711111111111112117211149787136 for example... is a 39 digit number uh...

# [2,7,7,9,9] or [2,7,7,9,3,3] or [2,7,7,3,3,3,3]

# This code should not be too far from memory-optimal one would think...

# But is certainly far from optimal. Should also store the product and modular remainder of the sum so that way recomputing is easy and fast. Let us try this again for better performance.

import copy
avv=[[]]
ccc=56448
cccc=285768
for f in range(40):
	print(f,len(avv))
	bvv=[]
	for av in avv:
		prod=1
		for dude in av:
			prod*=dude
		for g in range(1,10):
			if g!=5 and ccc%(prod*g)==0:
				cv=copy.deepcopy(av)
				cv.append(g)
				bvv.append(cv)
				if ccc==prod*g:
					summ=0
					for h in range(len(cv)):
						summ+=cv[h]*(10**h)
					if summ%cccc==0:
						print(cv)
	avv=bvv

# 3317111311137121316818944

# 1817198712146313216

# OK

764699349893278334976 263424 364637064882888
29397611921776166928384 546852789 897143918511235563
621728893661379481829376 542126592 37057929853283136

# Chinese Remainder Theorem?

# Can certainly confirm say something like that there does not exist a solution of length 100 by uh... oh never mind Fast Fourier Transformation here is not good... there might be some cases where one could potentially fairly easily and quickly verify 0 solutions by naively kind of even mixing in repeats and thus then getting the stronger conclusion if there are 0 solutions for a more general case.

# Oh I misread the task we need the digit product of A to be a perfect cube.

6273179136 21952 12252303
72236924928 13824 35271936
128421199872 110592 31352832

# For slightly better performance.

import copy
avv=[[1,0]]
ccc=56448
cccc=285768
for f in range(40):
	print(f,len(avv))
	bvv=[]
	for av in avv:
		for g in range(1,10):
			if g!=5 and ccc%(av[0]*g)==0:
				cv=copy.deepcopy(av)
				cv[0]*=g
				cv[1]+=g*(10**f)
				cv.append(g)
				bvv.append(cv)
				if ccc==cv[0] and cv[1]%cccc==0:
					print(cv)
	avv=bvv

# 8419411123272236924928