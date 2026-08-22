    while(scanf("%d",&a)==1){
        if(a<0){
            out<<"-1 ";
            a*=-1;
        }
        for(b=2;b<=sqrt(a);b++){
            if(a%b==0){
                c=0;
                while(a%b==0){
                    c++;
                    a/=b;
                }
                out<<b;
                if(c>1)out<<"^"<<c;
                out<<" ";
            }
        }
        if(a!=1){
            out<<a<<" ";
        }
        out<<nl;
    }