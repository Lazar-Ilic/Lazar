# Can compress down further from 11 x 11 to 8 x 8 due to symmetry in the
# 1, 2 and 2, 1 cases etc. e.g.

p = 3141592653
a = 		  [ [ 0, 4,12, 0, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 2, 0, 2, 1, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 2, 2, 0, 1, 0, 0, 0],
				[ 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 2, 0, 0, 0, 0, 2, 1, 0],
				[ 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 1],
				[ 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0],
				[ 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
for b in range(7):
	aa = [[0 for e in range(11)] for f in range (11)]
	for c in range(11):
		for d in range(11):
			e = 0
			for f in range(11):
				e += a[c][f] * a[f][d] % p
			aa[c][d] = e
	a = aa
	for c in range(11):
		for d in range(11):
			a[c][d] = a[c][d] % p
answer = 0
for b in range(11):
	answer += a[0][b]
answer = answer % p
print(answer)
# 24: 2524614399
# 256: 920321499

# Fails due to overflow.

import numpy as np
p = 3141592653
a = np.matrix([ [ 0, 4,12, 0, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 2, 0, 2, 1, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 2, 2, 0, 1, 0, 0, 0],
				[ 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 2, 0, 0, 0, 0, 2, 1, 0],
				[ 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 1],
				[ 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0],
				[ 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
				[ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
				, dtype = np.int64) # dtype = object failed.
for b in range(7):
	a = np.matmul(a,a)
	for c in range(11):
		for d in range(11):
			a[c,d] = a[c,d] % p
answer = 0
for b in range(11):
	answer += a[0,b]
answer = answer % p
print(answer)
print(a)
print(a.dtype)