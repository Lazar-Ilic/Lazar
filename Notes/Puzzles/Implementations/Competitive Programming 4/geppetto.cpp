    in>>a>>b;
    for(c=0;c<b;c++){
        in>>d>>e;
        avp.add({d,e});
    }
    c=0;
    for(d=0;d<(1<<a);d++){
        e=1;
        for(P ap:avp){
            if((d ba (1<<(ap.first-1))) and (d ba (1<<(ap.second-1))))e=0;
        }
        if(e)c++;
    }
    out<<c<<nl;