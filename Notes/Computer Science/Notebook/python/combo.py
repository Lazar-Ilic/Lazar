# Note that Python native integer handling is strong however sometimes for 96 bits of precision it is much simpler and easier to use the C++ programming language and the 96-bit long double data type.
p = 1000000007
factorials = [0] * 2000001
factorialsmax = 0
def factorial(al):
	global factorials, factorialsmax
	factorials[0] = 1
	if al <= factorialsmax:
		return factorials[al]
	else:
		for bl in range(factorialsmax + 1, al + 1):
			factorials[bl] = (factorials[bl-1] * bl) % p
		factorialsmax = al
		return factorials[al]
def inverse(al):
	bl = 1
	a = p-2
	while a != 0:
		if a%2 == 1:
			bl = (bl * al) % p
		al = (al * al) % p
		a = a // 2
	return bl
inversefactorials = [0] * 2000001
inversefactorialsaux = [0] * 2000001
def inversefactorial(al):
	global inversefactorials, inversefactorialsaux
	if inversefactorialsaux[al] == 0:
		inversefactorialsaux[al] = 1
		inversefactorials[al] = inverse(factorial(al))
	return inversefactorials[al]
def choose(al, bl):
	if bl>al:
		return 0
	return factorial(al) * inversefactorial(bl) * inversefactorial(al - bl) % p
def multinomial(al, avl):
	al = factorial(al)
	for a in range(0, len(avl)):
		al = al * inversefactorial(avl[a]) % p
	return al
def expp(al, bl):
	cl = 1
	while bl > 0:
		if bl%2 == 1:
			cl = cl * al % p
		al = al * al % p
		bl = bl // 2
	return cl
def exppp(a,b,y): # Python Native: pow(a,b,y)
	c = 1
	while b > 0:
		if b%2 == 1:
			c = c * a % y
		a = a * a % y
		b = b // 2
	return c