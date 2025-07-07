//Description: Given a rooted tree and a subset S of nodes, compute the minimal subtree that contains all the nodes by adding all (at most $|S|-1$) pairwise LCA's and compressing edges. Returns a list of (par, orig\_index) representing a tree rooted at 0. The root points to itself.
// Time: O(|S| log |S|)
template<class T>
STR RMQ{//Simon Lindholm
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (I pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(I a, I b) { //[a,b)
		assert(a < b); // or return inf if a == b
		I dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
STR LCA {
	I T = 0;
	V time,path,ret,depth;
	RMQ<I> rmq;
	LCA(VV& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	Z dfs(VV& C, I v, I par) {
		time[v] = T++;
		for(I y:C[v])if(y!=par){
			path.add(v);
			ret.add(time[v]);
			depth[y]=1+depth[v];
			dfs(C,y,v);
		}
	}
	I lca(I a,I b){
		if(a==b)return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	I distance(I a,I b){
		return depth[a]+depth[b]-2*depth[lca(a,b)];
	}
};
VP compresstree(LCA& alca, const V& subset) {
	static V rev;rev.resize(sz(alca.time));
	V li=subset,&T=alca.time;
	auto cmp=[&](I a,I b){return T[a]<T[b];};
	sort(all(li),cmp);
	I m=sz(li)-1;
	rep(i,0,m){
		I a=li[i],b=li[i+1];
		li.push_back(alca.lca(a,b));
	}
	sort(all(li),cmp);
	li.erase(unique(all(li)),li.end());
	rep(i,0,sz(li))rev[li[i]]=i;
	VP ret={P(0,li[0])};
	rep(i,0,sz(li)-1){
		I a=li[i],b=li[i+1];
		ret.emplace_back(rev[alca.lca(a,b)],b);
	}
	return ret;
}