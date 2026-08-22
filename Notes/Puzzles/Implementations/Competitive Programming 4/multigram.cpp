    in>>as;
    a=sz(as);
    for(b=1;b<=sqrt(a);b++){
        if(a%b==0){
            av.add(b);
            av.add(a/b);
        }
    }
    sort(all(av));
    L polynomial[26]={0};
    L freq[26]={0};
    L values[sz(as)+1]={0};
    polynomial[0]=1;
    for(b=1;b<=25;b++){
        polynomial[b]=(100000*polynomial[b-1])%p;
    }
    for(b=0;b<a;b++){
        freq[as[b]-'a']++;
        values[b+1]=(values[b]+polynomial[as[b]-'a'])%p;
    }
    I notsolved=1;
    for(b=0;b<sz(av) and notsolved;b++){
        if(av[b]<a){
            c=av[b];
            al=values[c];
            I caseopen=1;
            for(d=2;d<=(a/c) and caseopen;d++){
                if((al*d)%p!=values[d*c])caseopen=0;
            }
            if(caseopen){
                notsolved=0;
            }
        }
    }
    if(notsolved){
        out<<-1<<nl;
        return;
    }
    out<<as.substr(0,c)<<nl;