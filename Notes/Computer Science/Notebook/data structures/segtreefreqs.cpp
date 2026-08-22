MII segtree[524288];
I segtreesize;
MII segtreecomp(MII a,MII b){
    MII c;
    c.clear();
    c=a;
    for(auto bb:b){
        if(c.find(bb.first)==c.end()){
            c.insert({bb.first,bb.second});
        }
        else{
            c[bb.first]+=bb.second;
        }
    }
    return c;
}
Z buildsegtree(VMII a){
    segtreesize=262144;
    for(I b=0;b<sz(a);b++){
        segtree[b+segtreesize]=a[b];
    }
    for(I b=segtreesize-1;b>0;b--){
        segtree[b]=segtreecomp(segtree[2*b],segtree[2*b+1]);
    }
}
MII segtreerangeq(I a,I b){
    a+=segtreesize;
    b+=segtreesize;
    MII c;
    c.clear();
    while(a<=b){
        if(a%2==1){
            c=segtreecomp(c,segtree[a++]);
        }
        if(b%2==0){
            c=segtreecomp(c,segtree[b--]);
        }
        a/=2;
        b/=2;
    }
    return c;
}
Z segtreemodify(I a,I b){
    a+=segtreesize;
    MII c;
    c.clear();
    c.insert({b,1});
    segtree[a]=c;
    for(a/=2;a>=1;a/=2){
        segtree[a]=segtreecomp(segtree[2*a],segtree[2*a+1]);
    }
}
//MII segtree, I segtreesize
//MII segtreecomp(MII a,MII b)
//Z buildsegtree(VMII a)
//MII segtreerangeq(I a,I b)
//Z segtreemodify(I a,I b)