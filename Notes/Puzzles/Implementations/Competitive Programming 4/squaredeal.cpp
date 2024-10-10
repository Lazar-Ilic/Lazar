    in>>a>>b>>c>>d>>e>>f;
    if(a*a!=a*b+c*d+e*f){
        out<<"NO"<<nl;
        return;
    }
    if((c==e and ((c==a and d+f==a-b) or (c==a-b and d+f==a))) or (c==f and ((c==a and d+e==a-b) or (c==a-b and d+e==a))) or (d==e and ((d==a and c+f==a-b) or (d==a-b and c+f==a))) or (d==f and ((d==a and c+e==a-b) or (d==a-b and c+e==a))))out<<"YES"<<nl;
    else out<<"NO"<<nl;