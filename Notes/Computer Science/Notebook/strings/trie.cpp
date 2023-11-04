I trie[1000001][26];
B stop[1000001];
I ct=0;
Z insert(S as){
    I a=0,b;
    for(b=0;b<sz(as);b++){
        if(!trie[a][as[b]-'a'])trie[a][as[b]-'a']=++ct;
        a=trie[a][as[b]-'a'];
    }
    stop[a]=1;
}
I dp[5001];
I search(I a,S as){
    I b=0,c=0,d;
    for(d=a;d<sz(as);d++) {
        if(!trie[b][as[d]-'a'])return c;
        b=trie[b][as[d]-'a'];
        if(stop[b]){
            (c+=dp[d+1])%=p;
        }
    }
    return c;
}