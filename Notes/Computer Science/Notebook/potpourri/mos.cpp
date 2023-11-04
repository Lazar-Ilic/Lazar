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
    m=0; // value variable, here it was a maximum
    V freq(a,0); // often useful
    V freqmult(2*a+1,0);
    freqmult[a+0]=a+1;
    for(c=0;c<sz(bvp);c++){ // process each query in mos order
        if(l<bvp[c].first-1){
            while(l<bvp[c].first-1){ // left pointer increasing
                l++;
                freqmult[a+freq[av[l]]]--;
                freqmult[a+freq[av[l]]-1]++;
                if(m==freq[av[l]] and freqmult[a+freq[av[l]]]==0){m--;}
                freq[av[l]]--;
            }
        }
        else if(l>bvp[c].first-1){ // left pointer decreasing
            while(l>bvp[c].first-1){
                freqmult[a+freq[av[l]]]--;
                freqmult[a+freq[av[l]]+1]++;
                if(m==freq[av[l]]){m++;}
                freq[av[l]]++;
                l--;
            }
        }
        if(r<bvp[c].second){ // right pointer increasing
            while(r<bvp[c].second){
                r++;
                freqmult[a+freq[av[r]]]--;
                freqmult[a+freq[av[r]]+1]++;
                if(m==freq[av[r]]){m++;}
                freq[av[r]]++;
            }
        }
        else if(r>bvp[c].second){ // right pointer decreasing
            while(r>bvp[c].second){
                freqmult[a+freq[av[r]]]--;
                freqmult[a+freq[av[r]]-1]++;
                if(m==freq[av[r]] and freqmult[a+freq[av[r]]]==0){m--;}
                freq[av[r]]--;
                r--;
            }
        }
        // interval evaluation stored for output
        if(2*m-(r-l)>1){output.insert({bvp[c],2*m-(r-l)});}
        else{output.insert({bvp[c],1});};
    }
    for(c=0;c<sz(avp);c++){
        out<<output[avp[c]]<<nl;
    }
}
//Z mos(V av,VP avp) is {V,queries}