VS split(S as,S bs){
    size_t a=0,b,c=sz(bs);S cs;VS res;
    while((b=as.find(bs,a))!=string::npos){
        cs=as.substr(a,b-a);a=b+c;res.push_back(cs);
    }
    res.push_back(as.substr(a));
    return res;
}