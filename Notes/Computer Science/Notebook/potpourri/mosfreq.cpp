Z mos(V av,VP avp){
    I a,b,c,d,l,r,m;
    VP bvp;
    bvp=avp; // pairs of queries
    a=sz(av);
    b=I(pow(a,0.5));
    VVP avvp(a/b+1);
    sort(bvp.begin(),bvp.end()); // the preprocessing of queries
    for(c=0;c<sz(bvp);c++){
        avvp[bvp[c].first/b].add({bvp[c].second,bvp[c].first});
    }
    for(c=0;c<a/b+1;c++){
        sort(avvp[c].begin(),avvp[c].end());
    }
    bvp.clear();
    for(c=0;c<a/b+1;c++){
        if(sz(avvp[c])>0){
            for(d=0;d<sz(avvp[c]);d++){
                bvp.add({avvp[c][d].second,avvp[c][d].first});
            }
        }
    }
    MPI output; // map the queries pairs into their output
    l=-1; // left pointer
    r=-1; // right pointer
    m=0; // value variable, here it is number distinct
    V freq(200000); // often useful
    for(c=0;c<sz(bvp);c++){ // process each query in mos order
        if(l<bvp[c].first-1){
            while(l<bvp[c].first-1){ // left pointer increasing
                l++;
                freq[av[l]]--;
				if(freq[av[l]]==0)m--;
            }
        }
        else if(l>bvp[c].first-1){ // left pointer decreasing
            while(l>bvp[c].first-1){
                freq[av[l]]++;
				if(freq[av[l]]==1)m++;
                l--;
            }
        }
        if(r<bvp[c].second){ // right pointer increasing
            while(r<bvp[c].second){
                r++;
                freq[av[r]]++;
				if(freq[av[r]]==1)m++;
            }
        }
        else if(r>bvp[c].second){ // right pointer decreasing
            while(r>bvp[c].second){
                freq[av[r]]--;
				if(freq[av[r]]==0)m--;
                r--;
            }
        }
        // interval evaluation stored for output
        output.insert({bvp[c],m});
    }
    for(c=0;c<sz(avp);c++){
        out<<output[avp[c]]<<nl;
    }
}
//Z mos(V av,VP avp) is {V,queries}

//--------------------------------------------------------------------

Z az(){
    in>>a>>b;
	e=-1;
	for(c=0;c<a;c++){
		in>>d;
		if(!amii.count(d)){
			e++;
			amii.insert({d,e});
			av.add(e);
		}
		else av.add(amii[d]);
	}
	for(c=0;c<b;c++){
		in>>d>>e;d--;e--;
		avp.add({d,e});
	}
	mos(av,avp);
}