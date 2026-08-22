in>>a>>b;
    av=V(a);
    for(c=0;c<a;c++)in>>av[c];
    sort(all(av));
    if(b==1){
        c=0;
        d=a-1;
        while(c<d){
            if(av[c]+av[d]==7777){
                out<<"Yes"<<nl;
                return;
            }
            else if(av[c]+av[d]<7777)c++;
            else d--;
        }
        out<<"No"<<nl;
    }
    else if(b==2){
        c=1;
        for(d=1;d<a;d++){
            if(av[d]==av[d-1])c=0;
        }
        if(c)out<<"Unique"<<nl;
        else out<<"Contains duplicate"<<nl;
    }
    else if(b==3){
        c=1;
        for(d=1;d<a;d++){
            if(av[d]==av[d-1]){
                c++;
                if(c>a/2){
                    out<<av[d]<<nl;
                    return;
                }
            }
            else c=1;
        }
        out<<-1<<nl;
    }
    else if(b==4){
        if(a%2==1)out<<av[a/2]<<nl;
        else out<<av[a/2-1]<<" "<<av[a/2]<<nl;
    }
    else{
        for(c=0;c<a;c++){
            if(av[c]>=100 and av[c]<=999)out<<av[c]<<" ";
        }
        out<<nl;
    }