#include <bits/stdc++.h>
using namespace std;

vector<int> topsort(const vector<vector<int>>& graph){
	vector<int> indegree((int)graph.size()),ret;
	for(auto& li:graph)for(int x:li)indegree[x]++;
	queue<int> q;
	for(int a=0;a<(int)graph.size();a++)if(indegree[a]==0)q.push(a);
	while(!q.empty()){
		int a=q.front();
		ret.push_back(a);
		q.pop();
		for(int b:graph[a])if(--indegree[b]==0)q.push(b);
	}
	return ret;
}

int main() {
	// In particular each connected component must produce a DAG Directed Acyclic Graph at which point we may simply Dynamic Program somehow once we find the DAG with a Breadth First Search and direction and bottoms up children approach here maybe. Consider a modified Diameter search in the tree going down and up in reverse maybe as the edges. Well actually any top node must be a dude who has no incoming edges and so we may simply start the Breadth First Search from all top dudes in each connected component as Level 0 oh uh the level does really not matter too much as long as we track children accurately. Or uh we can instead associate each dude assign level later as the maximum possible level ugh... processing order... can use {level} in the Breadth First Search priority queue maybe ugh... set might be easier here... or could use priority queue and then uh also a vector of levels so we only process if the level is confirmed oh no that will not work ugh... need the vector of levels though to destroy and reinsert from the set or whatever ugh... can we instead now I implemented up 1 and 3 and returned to this task can we simply oh no we can not... in any case each dude can be uh oh never mind we may simply do the usual canonical DAG Directed Acyclic Graph algorithm works here just fine ugh... and then Bottoms Up Dynamic Programming... so it is not actually that simple here unless we sort the roads by value and then preprocess somehow to snag the lexicographically minimal dude because uh... comparing down 2 branches would require the entire branch history ugh... and this could Exceed Time Limit clearly ugh... but it might not so it is worth a try anyways... each time we compare can take a while ugh... but after that we merge off somehow in the up swing so it might be OK on the so-called amortised analysis. Or instead maybe we could uh somehow go top down somehow... or bottoms up and for each dude for sure can identify its maximal path length, minimal chain first value, pointer to minimum chain index, and sum...
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	cin>>a>>b;
	vector<vector<int>> avv(a,vector<int>(0));
	map<pair<int,int>,int> edges;
	for(c=0;c<b;c++){
		cin>>d>>e>>f;
		d--;e--;
		edges.insert({{d,e},f});
		avv[d].push_back(e);
	}
	vector<int> topsorted=topsort(avv); // Process through in reverse order Bottoms Up.
	vector<vector<long long>> avvl(a,vector<long long>(4));
	for(c=a-1;c>=0;c--){
		d=topsorted[c]; // Dude we are processing now.
		if((int)(avv[d]).size()==0){
			// Dude has 0 kids.
			avvl[d]={0,0,-1,0};
		}
		else{
			e=0; // Maximum of path lengths of children.
			f=INT_MAX; // Minimum to edge length.
			g=INT_MAX; // Minimum minimal from the set hitting e,f
			for(auto child:avv[d]){
				if(avvl[child][0]>e){
					e=avvl[child][0];
					f=edges[{d,child}];
					g=avvl[child][1];
				}
				else if(avvl[child][0]==e and edges[{d,child}]<f){
					f=edges[{d,child}];
					g=avvl[child][1];
				}
				else if(avvl[child][0]==e and edges[{d,child}]==f and avvl[child][1]<g){
					g=avvl[child][1];
				}
			}
			avvl[d][0]=e+1;
			avvl[d][1]=f;
			long long lol=f;
			vector<int> av(0);
			vector<int> bv(0); // Copy the upstream parent in place.
			vector<int> cv,dv;
			for(auto child:avv[d]){
				if(avvl[child][0]==e and edges[{d,child}]==f and avvl[child][1]==g){
					av.push_back(child);
					bv.push_back(child);
				}
			}
			while((int)av.size()>1){
				// Include a checker here if we are at the bottom and the max found was 0 then we just halt and pick 1 arbitrarily...
				if(avvl[av[0]][0]==0){
					av=vector<int>(0);
				}
				else{
					f=INT_MAX;
					for(auto dude:av){
						if(avvl[dude][1]<f)f=avvl[dude][1];
					}
					cv=vector<int>(0);
					dv=vector<int>(0);
					for(g=0;g<(int)av.size();g++){
						if(avvl[av[g]][1]==f){
							dv.push_back(bv[g]);
							cv.push_back(avvl[av[g]][2]);
						}
					}
					av=cv;
					bv=dv;
				}
			}
			avvl[d][2]=bv[0];
			avvl[d][3]=lol+avvl[bv[0]][3];
		}
	}
	for(c=0;c<a;c++){
		cout<<avvl[c][0]<<" "<<avvl[c][3]<<endl;
	}
}