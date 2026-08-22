    in>>as;
    I freq[26]={0};
    for(a=0;a<sz(as);a++){
        freq[as[a]-'a']++;
    }
    I numodd=0;
    for(a=0;a<26;a++){
        if(freq[a]%2==1)numodd++;
    }
    if(numodd>1){
        out<<"Impossible"<<nl;
        return;
    }
    a=0;
    for(b=0;b<sz(as)/2;b++){
        if(as[b]!=as[sz(as)-1-b]){
            ac=as[b];
            bc=as[sz(as)-1-b];
            c=b+1;
            while(c<sz(as) and as[c]!=bc)c++;
            d=sz(as)-1-b-1;
            while(d>=0 and as[d]!=ac)d--;
            if(c-b<sz(as)-1-b-d){
                a+=c-b;
                for(e=c;e>b;e--){
                    swap(as[e],as[e-1]);
                }
            }
            else{
                a+=sz(as)-1-b-d;
                for(e=d;e<sz(as)-1-b;e++){
                    swap(as[e],as[e+1]);
                }
            }
        }
    }
    out<<a<<nl;