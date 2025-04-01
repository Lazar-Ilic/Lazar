const L inf=1LL<<62;
vector<tuple<I,I,I>> edges; // {aver,bver,weight}
L distance[a+1]={0};
I parent[a+1]={0};
for(d=1;d<=a;d++){
	distance[d]=inf;
}
distance[1]=0; 
for(d=1;d<=a;d++){
    c=0;
    for(auto [aver,bver,weight]: edges){
        if(distance[aver]+weight<distance[bver]){
            distance[bver]=distance[aver]+weight;
            parent[bver]=aver;
            c=bver;
        }
    }
}
if(!c)//there exists a negative cycle
else{
    //continue
}