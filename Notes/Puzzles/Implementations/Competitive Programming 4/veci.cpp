    in>>as;
    for(a=0;a<sz(as);a++)av.add(a);
    m=INT_MAX;
    do{
        bs="";
        for(a=0;a<sz(as);a++)bs+=as[av[a]];
        if(stoi(bs)>stoi(as) and stoi(bs)<m)m=stoi(bs);
    }while(nextpermutation(all(av)));
    if(m==INT_MAX)out<<0<<nl;
    else out<<m<<nl;