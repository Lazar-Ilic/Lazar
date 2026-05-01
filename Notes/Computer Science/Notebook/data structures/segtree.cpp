I segtree[524288];
I segtreesize;
I comp(I a,I b){
    //return a+b;
    //return max(a,b);
    //return min(a,b);
    //return gcd(a,b);
    //return lcm(a,b);
}
Z build(V av){
    I a;
    segtreesize=262144;
    for(a=0;a<sz(av);a++){
        segtree[a+segtreesize]=av[a];
    }
    for(a=segtreesize-1;a>0;a--){
        segtree[a]=comp(segtree[2*a],segtree[2*a+1]);
    }
}
I rangeq(I a,I b){
    a+=segtreesize;
    b+=segtreesize;
    //I c=0;
    //I c=segtree[e];
    while(a<=b){
        if(a%2==1){
            c=comp(c,segtree[a++]);
        }
        if(b%2==0){
            c=comp(c,segtree[b--]);
        }
        a/=2;
        b/=2;
    }
    return c;
}
Z modify(I a,I b){
    a+=segtreesize;
    segtree[a]=b;
    for(a/=2;a>=1;a/=2){
        segtree[a]=comp(segtree[2*a],segtree[2*a+1]);
    }
}
//I segtree[], I segtreesize
//I comp(I a,I b)
//Z build(V a)
//I rangeq(I a,I b)
//Z modify(I a,I b)