// Description: Data structure for computing lowest common ancestors in a tree (with 0 as root). ccc should be an adjacency list of the tree, either directed or undirected.
// Time: O(N log N + Q)
template<class T>
struct RMQ{//Johan Sannemo,pajenegod
	vector<vector<T>> c;
	RMQ(const vector<T>& av):c(1,av){
		for(I w=1,k=1;w*2<=sz(av);w*=2,++k){
			c.emplace_back(sz(av)-w*2+1);
			rep(j,0,sz(c[k]))
				c[k][j]=min(c[k-1][j],c[k-1][j+w]);
		}
	}
	T query(I a,I b){ //[a,b)
		assert(a<b); //or return inf if a==b
		I d=31-__builtin_clz(b-a);
		return min(c[d][a],c[d][b-(1<<d)]);
	}
};
STR LCA{// 0 AS ROOT!!!
	I T=0;
	V time,path,ret,depth;
	RMQ<I> rmq;
	LCA(VV& ccc):time(sz(ccc)),depth(sz(ccc)),rmq((dfs(ccc,0,-1),ret)){}
	Z dfs(VV& ccc,I v,I par){
		time[v]=T++;
		for(I y:ccc[v])if(y!=par){
			path.add(v);
			ret.add(time[v]);
			depth[y]=1+depth[v];
			dfs(ccc,y,v);
		}
	}
	I lca(I a,I b){
		if(a==b)return a;
		tie(a,b)=minmax(time[a],time[b]);
		return path[rmq.query(a,b)];
	}
	I distance(I a,I b){
		return depth[a]+depth[b]-2*depth[lca(a,b)];
	}
};