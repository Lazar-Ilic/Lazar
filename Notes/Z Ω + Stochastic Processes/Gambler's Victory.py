import numpy as np

# Martingale for general 1 dimensional halting bounded walk Markov process chain and levelvalues also implicitly yields the halting probabilities for any pair of bounds inside these bounds. And any starting point as well.
# Naive simulation will not converge on the true underlying P so rapidly if say the expected hitting time is very large and each simulation takes a long time to run.
# State value constructed Martingale can work for some other state transition graphs. However, of course the other useful point is that constant applies even when there does not exist such an underlying state value correspondence. And in some settings one wants to represent a simpler construction of bets based upon other task specifics rather than a state value correspondence such as this one. Or rather, in some settings such a state may be history dependent and computationally intractable.
# Matrix inversion works in the general Markov process setting see Stochastic Processes Notes or Putnam Notes.
# There is a sense in which this is computationally equivalent with matrix inversion in this case too however a naive matrix inversion may have runtime O((a+b)^3) whereas this program has:
# Runtime O(a+b)
# Memory O(a+b)
# Visualisation And Comments Mine:
# https://en.wikipedia.org/wiki/Gambler%27s_ruin#Unfair_coin_flipping

# In the continuous Brownian Motion setting with Feynman-Kac or the Exponential Martingale as the drift is 0.2 one computes that the probability is [e^[2*5*0.2]-1]/[e^[2*5*0.2]-e^[-2*10*0.2]]~0.866813 whereas in this setting it is ~0.8703

startstate=5
startstate-=1
leftP=0
rightP=0
# A positivity check here implies this works. Can check edge conditions for P=1,0 cases or infinite expected hitting time case due to never hitting.
transitionPs=[[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6],[0.4,0.6]]
statesize=len(transitionPs)
levelvalues=np.zeros(statesize+2)

# This works by initializing the starting level value and neighbouring values at -p,0,q thus producing the requisite 0 Expected Value from starting state and also, in the linear equations, strictly monotone increasing and decreasing value chains up and down the chain.
levelvalues[startstate+2]=transitionPs[startstate][0]
levelvalues[startstate]=-transitionPs[startstate][1]
for a in range(startstate+1,statesize):
	# Solve the math equation for levelvalues[a+2]:
	# levelvalues[a]=transitionPs[a][0]*levelvalues[a-1]+transitionPs[a][1]*levelvalues[a+1]
	levelvalues[a+2]=(levelvalues[a+1]-transitionPs[a][0]*levelvalues[a])/transitionPs[a][1]
for a in range(startstate-1,-1,-1):
	levelvalues[a]=(levelvalues[a+1]-transitionPs[a][1]*levelvalues[a+2])/transitionPs[a][0]
# Solve the math equation for leftP:
# leftP*levelvalues[0]+(1-leftP)*levelvalues[statesize+1]=1
# Rearranges to leftP*(levelvalues[0]-levelvalues[statesize+1])=-levelvalues[statesize+1]
leftP=-levelvalues[statesize+1]/(levelvalues[0]-levelvalues[statesize+1])
#print(levelvalues)
rightP=1-leftP

print(leftP,rightP)

# There exists another, perhaps more natural O(a+b) and O(a+b) algorithm which will produce the probabilities for each possible starting point in the chain as well as the expected hitting times and it functions by starting at one end and producing these expressions in terms of a constant and a coefficient for each term down the chain upon which it resolves as a simple linear equation in P[1] and E[1] respectively. This should also naturally induce these aforementioned probabilities for any starting point and bounds inside these bounds.

# What is the expected number of die rolls until the first instance of 6 sixes in a row?

# This is a Markov process with the relevant states being on a streak of 0 sixes, 1 six, 2 sixes, etc. in a row. Each state either leads to the next state in the chain or recurses to the starting null state except for the termination/hitting. Casework on number of sixes prior to to this next recurrence gives:

# X = (1-p)(X+1)+p(1-p)(X+2)+...+p^(n-1)(1-p)(X+n)+p^n(n)
# = (1+p+p^2+...+p^(n-1))/p^n = (1-p^n)/(p^n(1-p)) = 55986

# For a more general similarly structured Markov chain one could iterate down the chain, keeping a partial probability stored, and produce the linear equation in terms of a constant and coefficient to resolve in O[n].

# How many races will one play in Mario Kart Double Dash prior to getting an all cups maximum score of 160 for acing through, supposing that one quits and restarts any time one loses a race? Global minimum of 16 for me, I never lose. How many interview rounds will one go through prior to signing an offer? Yikes.

# Positivity check here to ensure finitude.
transitionPs=[1/6,1/6,1/6,1/6,1/6,1/6]
Xcoefficient=0
constantterm=0
Pofreachingstate=1
for a in range(1,1+len(transitionPs)):
	Xcoefficient+=Pofreachingstate*(1-transitionPs[a-1])
	constantterm+=a*(Pofreachingstate*(1-transitionPs[a-1]))
	Pofreachingstate*=transitionPs[a-1]
constantterm+=(len(transitionPs))*Pofreachingstate
print((constantterm)/(1-Xcoefficient))

# In terms of a system of linear equations:

# 55986 = A = 1+(5/6)*A+(1/6)*B
# 55980 = B = 1+(5/6)*A+(1/6)*C
# 55944 = C = 1+(5/6)*A+(1/6)*D
# 55728 = D = 1+(5/6)*A+(1/6)*E
# 54432 = E = 1+(5/6)*A+(1/6)*F
# 46656 = F = 1+(5/6)*A

# In terms of the usual matrix inversion:

#  1    0    0    0    0    0   0
#  0   5/6  1/6   0    0    0   0
#  0   5/6   0   1/6   0    0   0
#  0   5/6   0    0   1/6   0   0
#  0   5/6   0    0    0   1/6  0
#  0   5/6   0    0    0    0  1/6
# 1/6  5/6   0    0    0    0   0

# (I-Q)^{-1} can be computed with the following terse code.

# WolframAlpha Implementation:

# Inverse {{1/6,-1/6,0,0,0,0},{-5/6,1,-1/6,0,0,0},{-5/6,0,1,-1/6,0,0},{-5/6,0,0,1,-1/6,0},{-5/6,0,0,0,1,-1/6},{-5/6,0,0,0,0,1}} =

# 46656 | 7776 | 1296 | 216 | 36 | 6
# 46650 | 7776 | 1296 | 216 | 36 | 6
# 46620 | 7770 | 1296 | 216 | 36 | 6
# 46440 | 7740 | 1290 | 216 | 36 | 6
# 45360 | 7560 | 1260 | 210 | 36 | 6
# 38880 | 6480 | 1080 | 180 | 30 | 6

# This produces the expected number of hittings and row sums yield the aforementioned values.