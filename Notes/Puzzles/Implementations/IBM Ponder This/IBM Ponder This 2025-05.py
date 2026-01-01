isprime=[1]*100000001
primes=[]
spf=[0]*100000001
order=[0]*100000001
def sieve(a):
	isprime[0]=0
	isprime[1]=0
	for b in range(2,a+1):
		if isprime[b]:
			primes.append(b)
			spf[b]=b
		c=len(primes)
		d=0
		while d<c and b*primes[d]<=a and primes[d]<=spf[b]:
			isprime[b*primes[d]]=0
			spf[b*primes[d]]=primes[d]
			d+=1
	for b in range(2,a+1):
		if isprime[b]:
			order[b]=1
		elif (int(b/spf[b]))%spf[b]!=0:
			order[b]=1
		else:
			order[b]=1+order[int(b/spf[b])]
	return 0
def primefactorsof(a):
	a=int(a)
	av=[]
	while a!=1:
		if len(av)==0 or spf[int(a)]!=av[int(len(av)-1)]:
			av.append(spf[int(a)])
		a/=spf[int(a)]
	return av
def primefactorisationof(a):
	a=int(a)
	avp=[]
	while a!=1:
		if len(avp)==0 or spf[int(a)]!=avp[int(len(avp)-1)][0]:
			avp.append([spf[int(a)],1])
		elif spf[int(a)]==avp[int(len(avp)-1)][0]:
			avp[int(len(avp)-1)][1]+=1
		a/=spf[int(a)]
	return avp
def factorsof(a):
	av=[]
	avp=primefactorisationof(a)
	while len(avp)<15:
		avp.append([1,0])
	avv=[]
	for a1 in range(15):
		bv=[]
		ccc=1
		for a2 in range(1+avp[a1][1]):
			bv.append(ccc)
			ccc*=avp[a1][0]
		avv.append(bv)
	for a1 in range(1+avp[0][1]):
		for a2 in range(1+avp[1][1]):
			for a3 in range(1+avp[2][1]):
				for a4 in range(1+avp[3][1]):
					for a5 in range(1+avp[4][1]):
						for a6 in range(1+avp[5][1]):
							for a7 in range(1+avp[6][1]):
								for a8 in range(1+avp[7][1]):
									for a9 in range(1+avp[8][1]):
										for a10 in range(1+avp[9][1]):
											for a11 in range(1+avp[10][1]):
												for a12 in range(1+avp[11][1]):
													for a13 in range(1+avp[12][1]):
														for a14 in range(1+avp[13][1]):
															for a15 in range(1+avp[14][1]):
																av.append(avv[0][a1]*avv[1][a2]*avv[2][a3]*avv[3][a4]*avv[4][a5]*avv[5][a6]*avv[6][a7]*avv[7][a8]*avv[8][a9]*avv[9][a10]*avv[10][a11]*avv[11][a12]*avv[12][a13]*avv[13][a14]*avv[14][a15])
	av.sort()
	return av

sieve(1000000)

def modinv(a, p):
	return pow(a, p - 2, p)

def gauss_elimination_mod_p(A, b, p):
	n = len(A)
	m = len(A[0])
	Ab = [row[:] + [b[i]] for i, row in enumerate(A)]
	for col in range(m):
		pivot_row = None
		for row in range(col, n):
			if Ab[row][col] % p != 0:
				pivot_row = row
				break
		if pivot_row is None:
			continue
		Ab[col], Ab[pivot_row] = Ab[pivot_row], Ab[col]
		inv = modinv(Ab[col][col], p)
		Ab[col] = [(val * inv) % p for val in Ab[col]]
		for row in range(col + 1, n):
			factor = Ab[row][col]
			Ab[row] = [(Ab[row][i] - factor * Ab[col][i]) % p for i in range(m + 1)]
	x = [0] * m
	for i in reversed(range(m)):
		if Ab[i][i] == 0:
			x[i] = 0
			continue
		x[i] = Ab[i][-1]
		for j in range(i + 1, m):
			x[i] = (x[i] - Ab[i][j] * x[j]) % p
	return x

# Solve:
# 2x + 3y ≡ 6 mod 7
# 4x +  y ≡ 5 mod 7

# DADBDDCDBC

A=[
[0,5,7,0,5,3,0,0],
[8,5,0,0,2,0,0,5],
[7,4,0,5,2,0,0,0],
[7,0,9,0,0,1,1,0],
[0,0,8,7,4,3,0,0],
[0,0,2,5,0,5,5,0],
[0,5,0,4,6,7,0,0],
[0,0,7,1,0,8,8,0]]
b=[2412,7624,637,761,2216,3499,4008,5534]

for pp in primes:
	if pp>7625:
		solution=gauss_elimination_mod_p(A,b,pp)
		if solution[0]*solution[2]*solution[4]*solution[6]%pp==6545 and solution[0]*solution[1]*solution[2]*solution[3]*solution[4]*solution[5]*solution[6]*solution[7]%pp==1:
			print(pp,solution)

# Think A Good Starting Point For The Next Task Is To Consider The String Where We Take The Majority On Each Task And Then Twiddle Around A Bit
#CCCDDCAADCCCBBDABDBAD 9/21
#ADDACCADDDDBACDDBADCD 11/21
#DCBABBAADDACBBAAAABDC 12/21
#ACAAABABDDDBACAABADDC 11/21
#CABAAAABDBDCCBDCBDBCC 12/21
#DDDADCADDBDABBDBCADCC 12/21
#ACDBBDAADDDABDCBCBCAC 9/21
#AABCBDACDBADBDDCDACCB 10/21
#BABBBBABAABCBDBCDACCA 9/21
#ACCBABADDDDDBBCDDBACC 12/21
#ACDBCBBDBDDCBCCADBCAA 9/21

#ACDABBABDBDCBDCCBADCC

#ADDACCADDDDBACDDBADCD 11/21
#ACAAABABDDDBACAABADDC 11/21
#DCBABBAADDACBBAAAABDC 12/21
#CABAAAABDBDCCBDCBDBCC 12/21
#DDDADCADDBDABBDBCADCC 12/21
#ACCBABADDDDDBBCDDBACC 12/21

#ACDAABADDDBABDABACACC

# Let Us Try It Out

#ACBADBADDDDCBBDCBACCC

#OKOKOK So This Works Indeed

import itertools

def match_count(s1, s2):
    return sum(a == b for a, b in zip(s1, s2))

def evaluate(candidate, references, targets):
    return sum((match_count(candidate, ref) - target) ** 2
               for ref, target in zip(references, targets))

def tweak_string(s, positions, replacements):
    s_list = list(s)
    for pos, rep in zip(positions, replacements):
        s_list[pos] = rep
    return ''.join(s_list)

def local_search(initial, references, targets, max_iters=10000):
    best = initial
    best_score = evaluate(best, references, targets)
    alphabet = list(set(''.join(references + [initial])))

    for _ in range(max_iters):
        improved = False
        for positions in itertools.combinations(range(len(initial)), 3):
            for replacements in itertools.product(alphabet, repeat=3):
                candidate = tweak_string(best, positions, replacements)
                score = evaluate(candidate, references, targets)
                if score < best_score:
                    best = candidate
                    best_score = score
                    improved = True
                    break
            if improved:
                break
        if not improved:
            break
    return best, best_score

# 🔧 Updated references and targets
references = [
    "CCCDDCAADCCCBBDABDBAD",  # 9
    "ADDACCADDDDBACDDBADCD",  # 11
    "DCBABBAADDACBBAAAABDC",  # 12
    "ACAAABABDDDBACAABADDC",  # 11
    "CABAAAABDBDCCBDCBDBCC",  # 12
    "DDDADCADDBDABBDBCADCC",  # 12
    "ACDBBDAADDDABDCBCBCAC",  # 9
    "AABCBDACDBADBDDCDACCB",  # 10
    "BABBBBABAABCBDBCDACCA",  # 9
    "ACCBABADDDDDBBCDDBACC",  # 12
    "ACDBCBBDBDDCBCCADBCAA",  # 9
]

target_vector = [9, 11, 12, 11, 12, 12, 9, 10, 9, 12, 9]

# Starting string
initial = "ACDAABADDDBABDABACACC"

# 🔍 Run local search
result, score = local_search(initial, references, target_vector)
print("Best result:", result)
print("Final error score (0 = perfect):", score)

#ACBADBADDDDCBBDCBACCC

pp=8999
avv=[5698,1616,1338,7821,4461,2156,7559,5812,794,2595,1640,6779,8362,4605,420,8724,3669,1869,7516,1386,4529]
bvv=[5146,3720,2548,6624,4662,5107,3916,2344,6215,3641,1583,6541,3828,5598,1275,4415,8973,6723,8246,1569,5503]
A=[[0 for a in range(21)] for b in range(21)]
for a in range(21):
	al=1
	for b in range(21):
		A[a][b]=al
		al=(al*avv[a])%pp
solution=gauss_elimination_mod_p(A,bvv,pp)
print(solution) # [7352, 1175, 1922, 4515, 3465, 6040, 6699, 3453, 5291, 7410, 7917, 4894, 722, 8521, 6491, 4372, 1199, 4562, 2104, 5783, 1]
print(sum(solution)%pp) # 3898