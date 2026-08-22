    in>>a;
    I values[11][11]={0};
    for(b=0;b<a;b++){
        in>>values[0][b];
    }
    c=1;
    for(b=1;b<a and c;b++){
        d=1;
        for(e=0;e<a-b;e++){
            values[b][e]=values[b-1][e+1]-values[b-1][e];
            if(values[b][e]!=values[b][0])d=0;
        }
        if(d){
            c=0;
            out<<b<<" ";
            values[b][a-b]=values[b][a-b-1];
            for(e=b-1;e>=0;e--){
                values[e][a-e]=values[e][a-e-1]+values[e+1][a-e-1];
            }
            out<<values[0][a]<<nl;
        }
    }