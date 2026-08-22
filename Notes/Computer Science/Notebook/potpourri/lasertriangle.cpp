/*
So say for example we are interested in generating a LASER triangle and only need to use the previous 3 rows in some other structure too would be like uh if a LASER triangle is like a uh Pascal's Triangle but with a depth-2 recursion then something like:
*/

avv=VV(n,V(3));
// Fill in avv[][0] and avv[][1]
for(b=2;b<=m;b++){
	// Edge cases.
	d=b%3;
	for(c=1;c<n-1;c++)bvv[c][d]=(bvv[c-1][(d-1+3)%3]+bvv[c][(d-1+3)%3]+bvv[c+1][(d-1+3)%3]+bvv[c-1][(d-2+3)%3]+bvv[c+1][(d-2+3)%3])%p;
	// Process with respect to this dude.
	// Sum up whatever multiplied by bvv[][d] as needed is bvv[][b] in a more memory wasting implementation without cyclically shifting around as needed.
}