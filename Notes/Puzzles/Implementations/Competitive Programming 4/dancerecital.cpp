    in>>a;
    for(b=0;b<a;b++){
        in>>as;
        c=0;
        for(d=0;d<sz(as);d++){
            c=(c bo (1<<(as[d]-'A')));
        }
        av.add(c);
    }
    for(b=0;b<a;b++){
        bv.add(b);
    }
    m=INT_MAX;
    do{
        b=0;
        for(c=1;c<a;c++){
            b+=subsetsize(av[bv[c-1]] ba av[bv[c]]);
        }
        if(b<m)m=b;
    }while(nextpermutation(all(bv)));
    out<<m<<nl;