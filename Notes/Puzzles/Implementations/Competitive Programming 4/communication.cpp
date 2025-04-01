    in>>a;
    for(b=0;b<=255;b++){
        amii.insert({((b bx (b<<1))%256),b});
    }
    for(b=0;b<a;b++){
        in>>c;out<<amii[c]<<" ";
    }
    out<<nl;