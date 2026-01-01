    STP astp;
    while(getline(in,as)){
        bs="";
        for(a=0;a<sz(as);a++){
            if(as[a]!=' ')bs+=as[a];
        }
        suffixarray ax(bs);
        av=ax.lcp;
        av.add(0);
        bv=V(sz(bs));
        while(!astp.empty())astp.pop();
        for(a=0;a<sz(av);a++){
            z=-1;
            while(!astp.empty() and av[a]<(astp.top()).first){
                //process and pop
                ap=astp.top();
                z=ap.second;
                astp.pop();
                if(a-ap.second>bv[ap.first])bv[ap.first]=a-ap.second;
            }
            if(z!=-1)astp.push({av[a],z});
            if(astp.empty() or (!astp.empty() and av[a]>(astp.top()).first))astp.push({av[a],a});
        }
        m=0;
        for(a=sz(bv)-1;a>=0;a--){
            if(bv[a]>m)m=bv[a];
            bv[a]=m;
        }
        a=1;
        while(a<sz(bv) and bv[a]>0){
            out<<1+bv[a]<<nl;
            a++;
        }
        out<<nl;
    }