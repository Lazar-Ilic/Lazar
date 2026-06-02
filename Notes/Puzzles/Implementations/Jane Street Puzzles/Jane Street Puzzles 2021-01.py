# Another simpler way is to convolve the relevant generating functions. This gives the number of ways to choose sets to the left and right of the partridge for each partridge index if all dudes are distinct e.g. for a maximum of 3 we multiply in code [1+2x+x^2][1+3x+3x^2+x^3][1+4x+6x^2+4x^3][1+5x+10x^2+10x^3]... and then further multiply out by the relevant factorials for arranging these 2 subsets with a b![77-b]! term prior to adding to our answer multiplied with the relevant maximum actual value term.

import numpy as np
import math
factorials=[1 for a in range(79)]
for a in range(1,79):
	factorials[a]=a*factorials[a-1]
answer=0
avv=[np.ones(a) for a in range(1,14)]
for a in range(3,14):
	for b in range(0,a):
		avv[a-1][b]=factorials[a-1]//(factorials[a-1-b]*factorials[b])
av=np.zeros(78)
for a in range(2,14):
	bv=np.array([1])
	for b in range(3,14):
		bv=np.convolve(avv[b-1][0:min(a,b)],bv)
	for b in range(1,bv.size):
		answer+=(bv[b]-av[b])*(a-1)*factorials[b]*factorials[77-b]
		# add to answer
	cv=np.zeros(78)
	av=np.concatenate((bv,cv),axis=0)
print(int(answer),int(factorials[78]))
print(int(answer)//int(math.gcd(int(answer),int(factorials[78]))),int(factorials[78])//int(math.gcd(int(answer),int(factorials[78]))))
answer/=factorials[78]
print(answer)