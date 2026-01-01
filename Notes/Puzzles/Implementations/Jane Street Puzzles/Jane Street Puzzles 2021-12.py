import math
P=0
maxrounds=100
#Code 0.1834376509 as the probability this process lasts more than 100 rounds is tiny. So casework brute force on the tuples of rounds where each player loses. Due to isomorphism with a uniform random partial permutation ordering. The error term could be written out in terms of maxrounds [for example one can probably produce an upper bound on the error term by a sum of something in terms of binomials, factorials, and perhaps geometric series which is greater than this error term].
for a in range(2,maxrounds):
	for b in range(1,maxrounds):
		for c in range(1,maxrounds):
			subcaseP=1
			shot=1
			round=1
			while round<=max(a,b,c):
				if a>round:
					subcaseP*=1/shot
					shot+=1
				elif a==round:
					subcaseP*=(shot-1)/shot
					shot+=1
				if b>round:
					subcaseP*=1/shot
					shot+=1
				elif b==round:
					subcaseP*=(shot-1)/shot
					shot+=1
				if c>round:
					subcaseP*=1/shot
					shot+=1
				elif c==round:
					subcaseP*=(shot-1)/shot
					shot+=1
				if round<max(a,b,c):
					subcaseP*=1/shot
					shot+=1
				round+=1
			P+=subcaseP
print('%.20f'%P)
# Floating Point
# 0.183437650861763446
# WolframAlpha Implementation:
# (-5/4)*(cos(1) + sin(1)) + (1/2)*e^(-1) + (e^(-1/2))*(cos(sqrt(3)/2) + 5/sqrt(3)*sin(sqrt(3)/2))
# 0.1834376508617635082218116032333643656107234717196259389467155188184498495528602612589908940522458429125627896233336507460936278079953583109075648892064483881399798453128353026780570990104988572161718891397728128709305863003211044606557655593869447458717838740285173830185000275553299711005541577927946400621698894361509524689932715068069625122919721819004971983466621109609818301748411631434674350058752392595168915015982486946183736978006924930880638714084435505337833702425710598426271303028102270934681244325018644...