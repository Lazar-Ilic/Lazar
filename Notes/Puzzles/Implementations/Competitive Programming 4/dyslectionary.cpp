    m=0;
    while(getline(in,as)){
        if(sz(as)==0){
            sort(all(avs));
            for(b=0;b<sz(avs);b++){
                for(a=0;a<m-sz(avs[b]);a++){
                    out<<" ";
                }
                reverse(all(avs[b]));
                out<<avs[b]<<nl;
            }
            out<<nl;
            avs.clear();
            m=0;
        }
        else{
            reverse(all(as));
            avs.add(as);
            if(sz(as)>m)m=sz(as);
        }
    }
    sort(all(avs));
    for(b=0;b<sz(avs);b++){
        for(a=0;a<m-sz(avs[b]);a++){
            out<<" ";
        }
        reverse(all(avs[b]));
        out<<avs[b]<<nl;
    }