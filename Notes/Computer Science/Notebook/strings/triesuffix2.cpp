const I a=1000000;
S trie;
I b[a][26],d[a],e[a],f[a],g[a],h,i,j,k;
Z add(I c){
    suff:;
    if(e[h]<i){
        if(b[h][c]==-1){b[h][c]=j;d[j]=k;f[j++]=h;h=g[h];i=e[h]+1;  goto suff;}
        h=b[h][c];i=d[h];
    }
    if(i==-1 or c==trie[i]-'a')i++;else{
        d[j+1]=k;f[j+1]=j;d[j]=d[h];e[j]=i-1;f[j]=f[h];b[j][c]=j+1;
		b[j][trie[i]-'a']=h;d[h]=i;f[h]=j;b[f[j]][trie[d[j]]-'a']=j;
		j+=2;h=g[f[j-2]];i=d[j-2];
        while(i<=e[j-2]){h=b[h][trie[i]-'a'];i+=e[h]-d[h]+1;}
        if(i==e[j-2]+1)g[j-2]=h;
		else g[j-2]=j; 
        i=e[h]-(i-e[j-2])+2;goto suff;
    }
}
Z build(){
    j=2;h=0;i=0;fill(e,e+a,sz(trie)-1);g[0]=1;
    d[0]=-1;e[0]=-1;d[1]=-1;e[1]=-1;
    memset(b,-1,sizeof b);
    fill(b[1],b[1]+26,0);
    for(k=0;k<sz(trie);++k)add(trie[k]-'a');
}