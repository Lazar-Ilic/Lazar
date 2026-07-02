# The key is that for each sub strategy the probability of winning from that strategy must be 1/3 because that is the overall winning probability and in the Nash Equilibrium we are getting equal odds on all sub strategies or else it would make sense and we would be incentivised to shift probability mass around from one strategy to another. But upon the observation that we either do that given strategy or a smoothing argument to an 8 wide strategy it then becomes clear.

# ----------

# Compute P of winning from 8 state actually... by noting that we are a random instance of such a dude and adding up over all of the cases for when there were only 0s... otherwise a contradiction emerges as there would be a 1 dude already out contradiction.

maximus=25
choose=[[0 for a in range(maximus)] for b in range(maximus)]
choose[0][0]=1
for a in range(1,maximus):
	choose[a][0]=1
	for b in range(1,maximus):
		choose[a][b]=choose[a-1][b-1]+choose[a-1][b]
p=0.99956049
aa=0
bb=0
for a in range(1,25):
	bb+=a*choose[24][a]*((1-p)**(a))*((p)**(24-a))
	cc=0
	# Need probability of having at least x gaps from 24-a 1s hitting.
	av=[0,0,0,0,0,0,0,0,0]

	av[1]=choose[8][1]*((7/8)**(24-a))-choose[8][2]*((6/8)**(24-a))+choose[8][3]*((5/8)**(24-a))-choose[8][4]*((4/8)**(24-a))+choose[8][5]*((3/8)**(24-a))-choose[8][6]*((2/8)**(24-a))+choose[8][7]*((1/8)**(24-a))-choose[8][8]*((0/8)**(24-a))

	av[2]=choose[8][2]*((6/8)**(24-a))-2*choose[8][3]*((5/8)**(24-a))+3*choose[8][4]*((4/8)**(24-a))-4*choose[8][5]*((3/8)**(24-a))+5*choose[8][6]*((2/8)**(24-a))-6*choose[8][7]*((1/8)**(24-a))+7*choose[8][8]*((0/8)**(24-a))
	
	av[3]=choose[8][3]*((5/8)**(24-a))-3*choose[8][4]*((4/8)**(24-a))+6*choose[8][5]*((3/8)**(24-a))-10*choose[8][6]*((2/8)**(24-a))+15*choose[8][7]*((1/8)**(24-a))-21*choose[8][8]*((0/8)**(24-a))
	
	av[4]=choose[8][4]*((4/8)**(24-a))-4*choose[8][5]*((3/8)**(24-a))+10*choose[8][6]*((2/8)**(24-a))-20*choose[8][7]*((1/8)**(24-a))+35*choose[8][8]*((0/8)**(24-a))
	
	av[5]=choose[8][5]*((3/8)**(24-a))-5*choose[8][6]*((2/8)**(24-a))+15*choose[8][7]*((1/8)**(24-a))-35*choose[8][8]*((0/8)**(24-a))
	
	av[6]=choose[8][6]*((2/8)**(24-a))-6*choose[8][7]*((1/8)**(24-a))+21*choose[8][8]*((0/8)**(24-a))
	
	av[7]=choose[8][7]*((1/8)**(24-a))-7*choose[8][8]*((0/8)**(24-a))
	
	av[8]=choose[8][8]*((0/8)**(24-a))

	if a==24:
		av[1]=choose[8][1]*((7/8)**(24-a))-choose[8][2]*((6/8)**(24-a))+choose[8][3]*((5/8)**(24-a))-choose[8][4]*((4/8)**(24-a))+choose[8][5]*((3/8)**(24-a))-choose[8][6]*((2/8)**(24-a))+choose[8][7]*((1/8)**(24-a))-choose[8][8]

		av[2]=choose[8][2]*((6/8)**(24-a))-2*choose[8][3]*((5/8)**(24-a))+3*choose[8][4]*((4/8)**(24-a))-4*choose[8][5]*((3/8)**(24-a))+5*choose[8][6]*((2/8)**(24-a))-6*choose[8][7]*((1/8)**(24-a))+7*choose[8][8]

		av[3]=choose[8][3]*((5/8)**(24-a))-3*choose[8][4]*((4/8)**(24-a))+6*choose[8][5]*((3/8)**(24-a))-10*choose[8][6]*((2/8)**(24-a))+15*choose[8][7]*((1/8)**(24-a))-21*choose[8][8]

		av[4]=choose[8][4]*((4/8)**(24-a))-4*choose[8][5]*((3/8)**(24-a))+10*choose[8][6]*((2/8)**(24-a))-20*choose[8][7]*((1/8)**(24-a))+35*choose[8][8]

		av[5]=choose[8][5]*((3/8)**(24-a))-5*choose[8][6]*((2/8)**(24-a))+15*choose[8][7]*((1/8)**(24-a))-35*choose[8][8]

		av[6]=choose[8][6]*((2/8)**(24-a))-6*choose[8][7]*((1/8)**(24-a))+21*choose[8][8]

		av[7]=choose[8][7]*((1/8)**(24-a))-7*choose[8][8]
		
		av[8]=choose[8][8]
	print(av)
	for b in range(1,min(a,8)):
		cc+=b*(av[b]-av[b+1])
	cc+=min(a,8)*av[min(a,8)]
	aa+=cc*choose[24][a]*((1-p)**(a))*((p)**(24-a))
print(aa/bb)