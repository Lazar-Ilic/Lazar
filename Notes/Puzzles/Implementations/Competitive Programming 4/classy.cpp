    in>>a;
    VPS avps;
    for(b=0;b<a;b++){
        in>>as>>bs>>ds;
        avs=split(bs,"-");
        cs="";
        for(c=sz(avs)-1;c>=0;c--){
            if(avs[c]=="upper")cs+="0";
            else if(avs[c]=="middle")cs+="1";
            else cs+="2";
        }
        for(c=9;c>=sz(avs);c--){
            cs+="1";
        }
        avps.add({cs,as.substr(0,sz(as)-1)});
    }
    sort(all(avps));
    for(PS aps:avps){
        out<<aps.second<<nl;
    }
    out<<"=============================="<<nl;