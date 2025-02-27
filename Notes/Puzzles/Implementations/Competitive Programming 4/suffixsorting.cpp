    while(getline(in,as) and getline(in,bs)){
        bs+=' ';
        av.clear();
        for(a=0;a<sz(bs);a++){
            if(bs[a]==' '){
                av.add(stoi(cs));
                cs="";
            }
            else{
                cs+=bs[a];
            }
        }
        suffixarray asfx(as);
        bv=asfx.sfxarray;
        for(a=1;a<sz(av);a++){
            out<<bv[av[a]+1]<<" ";
        }
        out<<nl;
    }