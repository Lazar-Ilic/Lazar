# Note that Python native integer handling is strong however sometimes for 96 bits of precision it is much simpler and easier to use the C++ programming language and the 96-bit long double data type.
p = 998244353
factorials = [0] * 2000001
factorialsmax = 0
def factorial(al):
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
#n,a,b=map(int,input().split())
n=3
a=1
b=2
avv=[[0 for c in range(b)] for d in range(a+1)]
# Probabilities for prefix of size a+b
# Should add up directly in ring and not 0 out here with P~0.001
avv[0][0]=1
numerator1=(a+expp(2,n-a)-2)%p
numerator2=(b+expp(2,n-b)-2)%p
denominator=(numerator1+numerator2)%p
print(numerator1,numerator2)
inverses=[0 for c in range(a+b)]
inverses[0]=1
for c in range(1,a+b):
	inverses[c]=inverse(denominator-c+1)%p
for c in range(1,a+1):
	avv[c][0]=avv[c-1][0]*(numerator1-c+1)*inverses[c]%p
answer=avv[a][0]
for d in range(1,b):
	avv[0][d]=avv[0][d-1]*(numerator2-d+1)*inverses[d]%p
	for c in range(1,a):
		# Compute value
		avv[c][d]=(avv[c-1][d]*(numerator1-c+1)*inverses[c+d]+avv[c][d-1]*(numerator2-d+1)*inverses[c+d])%p
	avv[a][d]=(avv[a-1][d]*(numerator1-a+1)*inverses[a+d])%p
	# Add to answer
	answer=(answer+avv[a][d])%p
print(answer)
print(avv)
for a in range(121):
	if((a*inverse(120))%p==124780545):
		print(a)
	elif((a*inverse(120))%p==898419918):
		print(a)
	elif((a*inverse(120))%p==199648871):
		print(a)
	elif((a*inverse(120))%p==798595483):
		print(a)

#UGH could be easier OKOKOK reduces to arbitrary dude on like Ath level and non dependent dude on Bth level I think... but probably some number theoretic computation based around the permutation of the exponent too after realising some fairly deep structure here about the Probabilities. Think dunno the ugh number of ways to order once we pick like dependent upstream and downstream sets of those 2 dudes is like fixed due to a relative ordering so it suffices to choose how many ways we can pick ugh like this Uth value is < Vth value an then sum up some binomial computation on the number of upstream and downstream dudes quite simply I think. It is just like well ugh computing over all the dudes might be kind of tricky ugh I mean summing over from a to b of a to b of 2^5000 is way too much... but then sum over ways to choose whatever whatever inequality of course. Of course there are [A-1] upstream and [B-1] upstream dudes for each is maybe simple and then ugh compute the downstream depending on the actual explicit values is still like for a sum of a casework is still like a brutal massive binomial sum but hockey stick identity might work quite frankly ugh. And need ugh so it is lowkey like there is a chain leading into the expansion which is lowkey maybe like ummm selecting ugh simply case into the like [A+B+2^[]-1+2^[-1]] dudes i.e. [A-1+B-1+2^[n-A-1]+2^[n-B-1]] dudes and then selecting from there... ugh think it is actually more like [A+B+2^[n-A-1]+2^[n-B-1]] dudes we select those 2 chains from etc. etc. perhaps say we have chosen now and it does not matter actually the A value the B value and the chains but from there ugh it is still like the casework on the number of permutations inducing that ugh which is like to say ugh the actual evaluation still here has to do with what what but like ugh multiply by the other selection too I think. So still it reduces I think into a WLOG about breaking down a partition into like ugh still the multiplicity on the downstreams do not matter from there so it is still like something about ugh they don't matter they are always the same it reduces still into this selection of the partition. Sum from A=A to the top of like ugh selecting the upstream oh it must be like sum from A=A to A+B or whatever if A is going to be < the B value due to induced upstream. Oh well all the dudes from 1 to the AA value are upstream and inclusive so there ugh maybe it is a like simple summation from 1+A to 1+A+B or whatever on the way to select the upstream chain and then force the rest and then select the rest which is like still a simple binary searchy thingy I think with low bottom counts that can be manually executed. And then sum from 1+A+1 to 1+A+B+1 or whatever the less you know in denominator. Ugh write this summation out and evaluate if it is a hockeystick instance I guess... not onsighting the bijection here today unfortunately but I think that it might be right there in sight. Each of these cases certainly leaves some like product of the ways to select the downstream chain to the B value from the remainder and then fixes all dudes in that interim into the downstream chain from a but then we are still left with some other term so it is like sum of [dude choose whatever]*[2^[]-dude choose 2^[blah]-whatever] which is still wait wait wait basically this is still like simply picking the downstream dudes I think. Ugh think it ugh suffices after picking a to simply pick the downstream dudes which is a huge cluster fuck of basically like a [2^[blah]-d choose 2^[blah]-2] and then the remainder chain for B is also fixed ugh. Well taking this all modulo p obviously immediately provides some like ugh ugh ugh modulo p computation should be pretty trivial here in O[p] for each instance is too high still. Still just like even considering Lucas's Theorem here is non trivial. Except even that still will not work because actually we need to be preserving the count of the number of powers of p in the numerator and denominator with respect to the final actual division of the representation of the true underlying fraction that is to say this is still nontrivial. Oh wait from there it is then as easy as simply seeing that this is in fact like equivalent with choosing ugh I think ugh this summation itself is like a summation of ugh maybe there is still a simple bijection here somehow where we like shift any additional ugh no that will not work. Probability distribution of order statistic in sampling without replacement e.g. variation on German Tank Problem task with Ath order statistic from set of size A+2^blah-2 out of A+B+2^blah-2+2^blah-2. Perhaps the Python programming language could actually help me with this here task and DP dunno just how to use arbitrary precision but I think maybe in O[n^2] time is trivial... frankly dunno if any of the first 5000 powers of 2 are actually within 5002 of a multiple of p... seems likely to not be the case actually... I think we can just naturally process this unfolding the first A+B letters and doing it in an DP doing the count until we halt e.g. or simply doing yeah yeah the first A+B and adding up along the rows and columns there. In any case yeah yeah yeah think we can simply compute the probability for each step and note that like probabilities sum in the ring I think so ugh keep it simple.