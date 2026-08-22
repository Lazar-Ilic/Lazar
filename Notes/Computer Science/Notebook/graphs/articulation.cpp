I numvertices;
V graph[100001];
I processed[100001];
V timein,low;
I timer;
SET articulations;
Z dfs(I a,I b=-1){
	processed[a]=1;
	timein[a]=low[a]=timer;
	timer++;
	I c=0;
	for(I d:graph[a]){
		if(d==b)continue;
		if(processed[d])low[a]=min(low[a],timein[d]);
		else{
			dfs(d,a);
			low[a]=min(low[a],low[d]);
			if(low[d]>=timein[a] and b!=-1)articulations.insert(a);
			c++;
		}
	}
	if(b==-1 and c>1)articulations.insert(a);
}
Z articulation(){
	timer=0;
	timein=V(numvertices+1,-1);
	low=V(numvertices+1,-1);
	for(I a=1;a<=numvertices;a++){
		if(!processed[a])dfs(a);
	}
}