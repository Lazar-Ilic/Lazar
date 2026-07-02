    while(getline(in,as)){
        a=stoi(as);
        if(a==1){
            out<<1<<nl;
        }
        else out<<2*(a-1)<<nl;
    }