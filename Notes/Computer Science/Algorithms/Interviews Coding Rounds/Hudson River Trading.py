import numpy as np
import scipy as sci
import pandas as pd
import sklearn as sk

# Practice some quick implementations here.

# ~Probability That Sum Of 100 Dice Rolls > 400 Coin Flips

av=[0 for a in range(601)]
av[0]=1
for a in range(100): # 100 Rolls Of The Dice
	for b in range(600,-1,-1):
		av[b]=0
		for c in range(1,min(7,b+1)):
			av[b]+=av[b-c]
bv=[0 for a in range(401)]
bv[0]=1
for a in range(400): # Flips Of The Coin
	for b in range(400,0,-1):
		bv[b]=bv[b]+bv[b-1]
cv=np.convolve(av,bv)
al=0
bl=0
for a in range(1001): # Number Of Dice Sum > Number Of Heads
# If And Only If Number Of Dice Sum + [400 - Number Of Heads] > 400
# If And Only If Due To Central Symmetry Around 200 Of Coin Binomial Distribution
	bl+=cv[a]
	if a>400:
		al+=cv[a]
print(al/bl) # 0.9999999999999925
print(al,"/",bl) # 1687031935884952358635901260596768992556514843074018966951618927301226600144828385193859991343108559939175156632763916142752221303114311065118761888777271903411115643172845588621211690835827626964326 / 1687031935884965030423865513001811026747194505266742417112773243035088793573924838842984610630991784467694332097273458389727477718575850821326229891871032151386690763060738361583538557010745413861376

# Compute If Vector Is All Sums Of 2 Fibonaccis

def allfibonaccisums(av):
	for a in av:
		if(a<2):
			return False
	return True

# Compute Rectangles In Points Vector With Duplicates Removed

def rectangles(avp):
	answer=0
	asetp=set()
	multiplicities={}
	for ap in avp:
		asetp.add((ap[0],ap[1]))
	bvp=list(asetp) # Removes duplicates if desired.
	for a in range(len(bvp)-1):
		for b in range(a+1,len(bvp)):
			atuple=(bvp[a][0]+bvp[b][0],bvp[a][1]+bvp[b][1],(bvp[a][0]-bvp[b][0])*(bvp[a][0]-bvp[b][0])+(bvp[a][1]-bvp[b][1])*(bvp[a][1]-bvp[b][1])) # Stronger Than Epsilons On Doubles
			# Can Instead Hash Map Tuples Into Vectors Of Pairs
			if atuple in multiplicities:
				multiplicities[atuple]+=1
			else:
				multiplicities[atuple]=1
	for akey in multiplicities:
		answer+=(multiplicities[akey])*(multiplicities[akey]-1)//2
		# Here Output Or Store Relevant Pairs From Vector Of Pairs
	return answer

avp=[[5,0],[5,0],[-5,0],[3,4],[-3,-4],[4,3],[-4,-3]]
print(rectangles(avp)) # 3

# Sum Of All 2 Digit Numbers In Range Without 7s And 8s

global av
# av=[,,...,] Can Declare Perhaps
av=[0 for a in range(200)]
for a in range(-99,100):
	# Process a
	av[a+100]=av[a+99]
	if ((a<-89) or (a>-70 and a<70) or (a>89)) and ((a<0 and a%10!=3 and a%10!=2) or (a>0 and a%10!=7 and a%10!=8)):
		av[a+100]+=a
def sumofnumbers(a,b): # [a,b] Range Query
	if b<a:
		return -13370 # Error Condition
	if a<-99:
		a=-99
	if b<-99:
		return 0
	if a>99:
		return 0
	if b>99:
		b=99
	return av[b+100]-av[a+100-1]

print(sumofnumbers(70,130)) # 750
print(sumofnumbers(70,98)) # 651
print(sumofnumbers(130,70)) # -13370