    in>>a>>as>>bs;
    b=0;
    for(c=0;c<sz(as);c++){
        if(as[c]==bs[c])b++;
    }
    out<<min(a,b)+min(sz(as)-a,sz(as)-b)<<nl;