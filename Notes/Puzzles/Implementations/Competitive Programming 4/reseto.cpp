    in>>a>>b;
    av=V(a+1);
    av[0]=av[1]=1;
    c=0;
    d=2;
    while(c<b){
        while(av[d])d++;
        for(e=d;e<=a and c<b;e+=d){
            if(!av[e]){
                av[e]=1;
                c++;
                if(c==b)out<<e<<nl;
            }
        }
    }