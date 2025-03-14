# Mathematically one can reduce the search space a little and compute and store multiplicities via binomial coefficients. Firstly note there are [[25] choose [5,5,5,5,5]] relevant orderings. By symmetry it suffices to count 5!=120 multiplied by the number of ways for the first child to get more of the first candy, the second the second, etc. Note that the multiplicities and relevant partitions of 5 are:

# 5/1   5
# 20/4  4 1
# 20/4  3 2
# 30/6  3 1 1
# 20/4  2 1 1 1

# Now one can compute the multiplicity of relevant suborderings inductively where the relevant information to store is the number of candies in each partition/bucket since that will uniquely determine the number of ways to insert candies in the future. For example after round 1:

# M[5][0][0][0][0]=1
# M[4][1][0][0][0]=25
# M[4][0][1][0][0]=25
# ...

# After round 2 though:

# M[5][5][0][0][0]=126
# ...

import math
factorials=[1 for a in range(26)]
for a in range(1,26):
	factorials[a]=a*factorials[a-1]
choose=[[0 for a in range(6)] for b in range(6)]
choose[0][0]=1
for a in range(1,6):
	choose[a][0]=1
	for b in range(1,6):
		choose[a][b]=choose[a-1][b-1]+choose[a-1][b]
N=[[[[[0 for a in range(6)] for b in range(6)] for c in range(6)] for d in range(6)] for e in range(6)]
N[0][0][0][0][0]=1
avv=[
[5,0,0,0,0],
[4,1,0,0,0],
[4,0,1,0,0],
[4,0,0,1,0],
[4,0,0,0,1],
[3,2,0,0,0],
[3,0,2,0,0],
[3,0,0,2,0],
[3,0,0,0,2],
[3,1,1,0,0],
[3,1,0,1,0],
[3,1,0,0,1],
[3,0,1,1,0],
[3,0,1,0,1],
[3,0,0,1,1],
[2,1,1,1,0],
[2,1,1,0,1],
[2,1,0,1,1],
[2,0,1,1,1],
]
dude=[0,0,0,0,0]
for z in range(5):
	M=[[[[[0 for a in range(6)] for b in range(6)] for c in range(6)] for d in range(6)] for e in range(6)]
	for dude2 in avv:
		for b in range(5):
			dude[b]=dude2[(b-z)%5]
		for b in range(0,1+5-dude[0]):
			for c in range(0,1+5-dude[1]):
				for d in range(0,1+5-dude[2]):
					for e in range(0,1+5-dude[3]):
						for f in range(0,1+5-dude[4]):
							M[b+dude[0]][c+dude[1]][d+dude[2]][e+dude[3]][f+dude[4]]+=N[b][c][d][e][f]*choose[5-b][dude[0]]*choose[5-c][dude[1]]*choose[5-d][dude[2]]*choose[5-e][dude[3]]*choose[5-f][dude[4]]
	N=M
a=N[5][5][5][5][5]*120
b=factorials[25]/(factorials[5]**5)
print(int(a)//int(math.gcd(int(a),int(b))),int(b)//int(math.gcd(int(a),int(b))))
print(a/b)