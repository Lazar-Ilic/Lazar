import random

l=0
r=1
z=0
while z<100:
	m1=l+(r-l)*1/3
	m2=l+(r-l)*2/3
	# Test the value of m1 versus m2 I guess.
	wins=0
	losses=0
	for a in range(10000000): # Can change for improved precision.
		score1=0
		score2=0
		while score1<m1:
			score1+=random.uniform(0,1)
		while score2<m2:
			score2+=random.uniform(0,1)
		if score1>1:
			score1=0
		else:
			score1+=random.uniform(0,1)
		if score2>1:
			score2=0
		else:
			score2+=random.uniform(0,1)
		if score1>score2:
			wins+=1
		elif score2>score1:
			losses+=1
	if wins>losses:
		r=m2
	elif losses>wins:
		l=m1
	print(wins/(wins+losses),losses/(wins+losses))
	print(l,r)
	z+=1

"""
https://math.stackexchange.com/questions/111314/choose-a-random-number-between-0-and-1-and-record-its-value-keep-doing-it-u

https://mathworld.wolfram.com/UniformSumDistribution.html

https://stats.stackexchange.com/questions/193990/approximate-e-using-monte-carlo-simulation

So this sort of program right here can immediately help to inform us to give us some like OK estimator for the True underlying around 0.4 but we might need to like actually take the relevant integrals and compare them directly in terms of a sup function and the True underlying degenerated P[0] value and so on and so on. So the number is like around 0.41 or whatever...

OK so we repeatedly take that integral of what was that remainder and umm sum up those integrals and then we get that overall integral to compare I guess directly in terms of Win P like we must have something uh something errrm is greater than whatever... oh like the PDF I guess so we need to convert between the PDF and back again or whatever...

https://math.stackexchange.com/questions/3101264/distribution-at-first-time-a-sum-reaches-a-threshold

Oh gee Yikes I think that like the actual probability is like related again to a simplex that is to say the sum of the relevant simplices so like the umm actual matter here is that it is like uh take each time step is like some infinite sum of the simplex generating the sum Rightward of the threshold... OKOKOK so essentially we first consider that dude from 0 and then after that it is like the old... uh simplex captured and then Rightward dude...

http://websites.umich.edu/~dineshk/math_stuff/min_num_rv_threshold.pdf

https://mathoverflow.net/questions/10567/number-of-uniform-rvs-needed-to-cross-a-threshold

OK so essentially we need to sum that integral from A to 1 and from 1 to 1+A essentially for each of the simplices... the relevant PDF integrals that is...

OKOKOK so the actual underling function is just 1 on [0,1] obviously then shifted as relevant and integrated on the relevant regions is like uh...

For each value in the range the underlying DF is like uh simply the sum of ugh it is like a integral of the simplex itself taken to the Right... but I think it is then just like the sum of the relevant hitting parts that is to say that like uh the actual distribution underlying the [A,1] range should be straight up flat I think because like each contribution from each dude in the [0,A] range bumping up over the bound is still uniform summation and then it is actually the uh final Probability of going over the threshold however is more like in the uh actual ugh like [1,1+A] range is the fascinating summation of the ugh integrals of the relevant values leading into that point is like the [1] point takes all possible values and then the [1+A] point would only force off something else... gives us the relative norming on the underlying DF.

0.5609148409134099 0.43908515908659
0 0.6666666666666666
0.48064094095822424 0.5193590590417757
0.2222222222222222 0.6666666666666666
0.5075649169897144 0.4924350830102856
0.2222222222222222 0.5185185185185185
0.4945118339248502 0.5054881660751498
0.32098765432098764 0.5185185185185185
0.5004296496332359 0.49957035036676406
0.32098765432098764 0.4526748971193415
0.49824596250659114 0.5017540374934089
0.36488340192043894 0.4526748971193415
0.499764715542878 0.5002352844571221
0.3941472336534065 0.4526748971193415
0.5002128408706575 0.4997871591293425
0.3941472336534065 0.43316567596402983
0.49992657707191995 0.50007342292808
0.40715338109028093 0.43316567596402983
0.5000857443752973 0.49991425562470276
0.40715338109028093 0.42449491100611353
0.500088153385736 0.499911846614264
0.40715338109028093 0.41871440103416935
0.49997009973258505 0.5000299002674149
0.4110070544049104 0.41871440103416935
0.4999881510409055 0.5000118489590946
0.41357616994799673 0.41871440103416935
0.5000337347816259 0.49996626521837406
0.41357616994799673 0.4170016573387785

OKOKOK so that is like the integral from B to A of all of those simplices and their underlying DFs is like the summation of umm oh Jeez Louise this is simple Stoopid Super Simple like the Delta in the CDF of the Irwin-Hall Distribution or whatever so that is like...

x^n/n!

A^n/n! is the raw level on [A,1]

[A^n-B^n]/n!

Integral from 

OKOKOK so maybe the value is Ae on [A,1]

OKOKOK

So maybe we do not do that maybe we simply say that the value is actually uh like on [A,1] it should be like 1+ some other stuff is like...

No CDF is a strong route via which to go I think it is like...

e^A on [A,1] actually and like
e^A-e^B on (1,1+A] actually...
e^A-e^[B-1] that is to say.

So um that is OK and dandy and all that so what we want is like uh OKOKOK so the actual matter is that A needs to be better than A and A+-epsilon means that like the Probability of Winning is uh like...

OKOKOK and that is actually the raw PDF I think uh with actual integral 1

integral from 1 to 1+A of e^A-e^(x-1)

https://www.wolframalpha.com/input?i=integral+from+1+to+1%2BA+of+e%5EA-e%5E%28x-1%29

Means that the P we both draw a 0 would be like the only case there is no winner so like...

Uh maybe if we take some relative CDF integral we get it somehow like uh we need some relative CDF integrals to be uh greater than others is like uh... oh OKOKOK so the actual relevant case here is simply that uh it is like uh

[1-A]*e^A*[1-[1-[A+0.001]]*e^[A+0.001]] + [1/2][P Both In Range] + 

>

[1-[A+0.001]]*e^[A+0.001]*[1-[1-A]*e^A] + [1/2][P Both In Range] +

Or:

[1-A]*e^A*[1-[1-[A+0.001]]*e^[A+0.001]]+[1-A]*e^A*[1-[A+0.001]]*e^[A+0.001]*[A^2+A+1]*0.001/[6*[1-A]]>[1-[A+0.001]]*e^[A+0.001]*[1-[1-A]*e^A]+[1-[1-A]*e^A*[1-[A+0.001]]*e^[A+0.001]*[A^2+A+1]*[A^2+A+1]*0.001/[6*[1-A]]]

Or:

[1-[1-[A+10^(-20)]]*e^[A+10^(-20)]]/[[1-[A+10^(-20)]]*e^[A+10^(-20)]]+10^(-20)/[1-A]*[A^2+A+1]/6=[1-[1-A]*e^A]/[[1-A]*e^A]+10^(-20)/[1-A]*[1-[A^2+A+1]/6]

And similarly...

[1-[1-[A+10^(-50)]]*e^[A+10^(-50)]]/[[1-[A+10^(-50)]]*e^[A+10^(-50)]]+10^(-50)/[1-A]*[A^2+A+1]/6=[1-[1-A]*e^A]/[[1-A]*e^A]+10^(-50)/[1-A]*[1-[A^2+A+1]/6]

0.41619535485823622345

1-(1-0.41619535485823622345)*e^0.41619535485823622345

https://www.wolframalpha.com/input?i=1-%281-0.41619535485823622345%29*e%5E0.41619535485823622345

0.114845886
"""