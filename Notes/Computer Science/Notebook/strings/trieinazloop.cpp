	// https://atcoder.jp/contests/abc377/tasks/abc377_g
	in>>a;
	avv=VV(1000000,V(27)); // Score followed by references to locations of children.
	z=1; // Next Unused Memory Block In avv
	for(b=0;b<a;b++){
		in>>as;
		// Insert In To Trie And Compute Minimum Cost
		m=INT_MAX;
		c=0; // Current Location To Examine For dth Character In String
		for(d=0;d<=sz(as);d++){
			m=min(m,sz(as)-d+avv[c][0]);
			avv[c][0]=min(avv[c][0],sz(as)-d);
			if(d<sz(as)){
				if(avv[c][as[d]-'a'+1]!=0)c=avv[c][as[d]-'a'+1];
				else{
					avv[c][as[d]-'a'+1]=z;
					avv[z][0]=1000000;
					c=z;
					z++;
				}
			}
		}
		out<<m<<nl;
	}