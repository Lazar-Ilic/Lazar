VVB generatepaths(I a,I b){
	VVVVB avvvvb(a,VVVB(b,VVB(0,VB(0))));
	I c,d;
	for(c=1;c<a;c++){
		VB avb;
		for(d=0;d<c;d++)avb.add(0);
		avvvvb[c][0].add(avb);
	}
	for(c=1;c<b;c++){
		VB avb;
		for(d=0;d<c;d++)avb.add(1);
		avvvvb[0][c].add(avb);
	}
	for(c=1;c<a;c++){
		for(d=1;d<b;d++){
			for(VB avb:avvvvb[c-1][d]){
				avb.add(0);
				avvvvb[c][d].add(avb);
			}
			for(VB avb:avvvvb[c][d-1]){
				avb.add(1);
				avvvvb[c][d].add(avb);
			}
		}
	}
	return avvvvb[a-1][b-1];
}

//----------

	VVB avvb=generatepaths(10,10);
	for(VB dude:avvb){
		for(B dude2:dude)out<<dude2;
		out<<nl;
	}