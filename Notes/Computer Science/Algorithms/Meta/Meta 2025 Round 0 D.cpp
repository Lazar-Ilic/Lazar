#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
void finder(int a,const vector<vector<pair<int,int>>>& adj,vector<bool>& visited,vector<int>& component){
	stack<int> s;
	s.push(a);
	visited[a]=true;
	component.push_back(a);
	while(!s.empty()){
		int u=s.top();
		s.pop();
		for(const auto& edge:adj[u]){
			int v=edge.first;
			if(!visited[v]){
				visited[v]=true;
				s.push(v);
				component.push_back(v);
			}
		}
	}
}
void solve(int testcase){
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> edges(M+1);
	vector<vector<pair<int,int>>> adj(N+1);
	for(int i=1;i<=M;++i){
		int u,v;
		cin>>u>>v;
		edges[i]={u,v};
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
	}
	vector<char> assignment(M+1,'0');
	vector<bool> visited(N+1,false);
	vector<bool> used(M+N/2+2,false);
	int nextv=M+1;
	for(int i=1;i<=N;++i){
		if(!visited[i]&&!adj[i].empty()){
			vector<int> component;
			finder(i,adj,visited,component);
			vector<int> odds;
			for(int node:component){
				if(adj[node].size()%2!=0){
					odds.push_back(node);
				}
			}
			int start=i;
			if(!odds.empty()){
				start=odds[0];
			}
			for(int j=2;j<(int)odds.size();j+=2){
				int u=odds[j];
				int v=odds[j+1];
				adj[u].push_back({v,nextv});
				adj[v].push_back({u,nextv});
				nextv++;
			}
			vector<int> tour;
			stack<pair<int,int>> stour;
			stour.push({start,0});
			vector<int> point(N+1,0);
			while(!stour.empty()){
				int u=stour.top().first;
				int to=stour.top().second;
				int nextv=-1;
				int nexte=0;
				while(point[u]<adj[u].size()){
					auto [vc,ec]=adj[u][point[u]];
					point[u]++;
					if(!used[ec]){
						nextv=vc;
						nexte=ec;
						break;
					}
				}
				if(nextv!=-1){
					used[nexte]=true;
					stour.push({nextv,nexte});
				}
				else{
					stour.pop();
					if(to!=0){
						tour.push_back(to);
					}
				}
			}
			reverse(tour.begin(),tour.end());
			char day='1';
			for(int dude:tour){
				if(dude<=M){
					assignment[dude]=day;
				}
				day='2'-day+'1';
			}
			for(size_t j=2;j<odds.size();j+=2){
				adj[odds[j]].pop_back();
				adj[odds[j+1]].pop_back();
			}
		}
	}
	long long answer=0;
	vector<int> av(N+1,0),bv(N+1,0);
	for(int i=1;i<=M;++i){
		if(edges[i].first==0)continue;
		auto [u,v]=edges[i];
		if(assignment[i]=='1'){
			av[u]++;
			av[v]++;
		}
		else{
			if(assignment[i]=='0')assignment[i]='2';
			bv[u]++;
			bv[v]++;
		}
	}
	for(int i=1;i<=N;++i)answer+=(long long)av[i]*av[i]+(long long)bv[i]*bv[i];
	cout<<"Case #"<<testcase<<": "<<answer<<" ";
	for(int i=1;i<=M;++i)cout<<assignment[i];
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
	int testcases;
	cin>>testcases;
	for(int a=1;a<=testcases;a++)solve(a);
	return 0;
}