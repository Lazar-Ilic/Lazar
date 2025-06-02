    in>>a;
    av=V(a);
    bv=V(a);
    for(b=0;b<a;b++)in>>av[b];
    for(b=0;b<a;b++)in>>bv[b];
    if(inversions(av)%2==inversions(bv)%2)out<<"Possible"<<nl;
    else out<<"Impossible"<<nl;