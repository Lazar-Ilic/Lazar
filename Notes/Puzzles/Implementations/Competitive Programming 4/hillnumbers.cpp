    in>>al;
    precomputechose(100);
    while(al!=0){
        av.add(al%10);
        al/=10;
    }
    av.add(0);
    reverse(all(av));
    a=-1;
    b=-1;
    c=1;
    for(d=0;d<sz(av)-1 and c;d++){
        if(av[d+1]<av[d]){
            c=0;
            a=d;
        }
    }
    c=1;
    for(d=sz(av)-1;d>1 and c;d--){
        if(av[d]>av[d-1]){
            c=0;
            b=d;
        }
    }
    if(!(a==-1 or b==-1 or a>=b)){
        out<<-1<<nl;
        return;
    }
    I hillyet=0;
    al=0;
    L DP[10][20]={0};
    for(a=0;a<=9;a++){
        DP[a][1]=1;
    }
    for(b=2;b<=19;b++){
        for(a=0;a<=9;a++){
            for(c=a;c<=9;c++){
                DP[a][b]+=DP[c][b-1];
            }
            DP[a][b]+=chose[a-1+b-1][b-1];
        }
    }
    for(a=1;a<sz(av);a++){
        if(av[a]<av[a-1])hillyet=1;
        if(hillyet){
            al+=chose[av[a]-1+sz(av)-a][sz(av)-a];
        }
        else{
            for(b=av[a]-1;b>=av[a-1];b--){
                al+=DP[b][sz(av)-a];
            }
            al+=chose[av[a-1]-1+sz(av)-a][sz(av)-a];
        }
    }
    out<<al<<nl;