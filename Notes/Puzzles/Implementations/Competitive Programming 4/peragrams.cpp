    in>>as;
    I freq[26]={0};
    for(a=0;a<sz(as);a++){
        freq[as[a]-'a']++;
    }
    I numodd=0;
    for(a=0;a<26;a++){
        if(freq[a]%2==1)numodd++;
    }
    numodd--;
    if(numodd<0)numodd=0;
    out<<numodd<<nl;