// Description: Given a weighted bipartite graph, matches every node on the left with a node on the right such that no nodes are in two matchings and the sum of the edge weights is minimal. Takes cost[N][M], where cost[i][j] = cost for L[i] to be matched with R[j] and returns (min cost, match), where L[i] is matched with R[match[i]]. Negate costs for max cost.
// Time: O(N^2*M)
PIV mincostmatching(const VV &a){//Benjamin Qi,chilli
	if(a.empty())return{0,{}};
	I n=sz(a)+1,m=sz(a[0])+1;
	V u(n),v(m),ppp(m),ans(n-1);
	rep(i,1,n){
		ppp[0]=i;
		I j0=0; // add "dummy" worker 0
		V dist(m,INT_MAX),pre(m,-1);
		VB done(m+1);
		do{
			done[j0]=true;
			I i0=ppp[j0],j1,delta=INT_MAX;
			rep(j,1,m)if(!done[j]){
				auto cur=a[i0-1][j-1]-u[i0]-v[j];
				if(cur<dist[j])dist[j]=cur,pre[j]=j0;
				if(dist[j]<delta)delta=dist[j],j1=j;
			}
			rep(j,0,m){
				if(done[j])u[ppp[j]]+=delta,v[j]-=delta;
				else dist[j]-=delta;
			}
			j0=j1;
		}while(ppp[j0]);
		while(j0){ // update alternating path
			I j1=pre[j0];
			ppp[j0]=ppp[j1],j0 =j1;
		}
	}
	rep(j,1,m)if(ppp[j])ans[ppp[j]-1]=j-1;
	return{-v[0],ans}; // min cost
}

//----------

// Description: Given a weighted bipartite graph, matches every node on the left with a node on the right such that no nodes are in two matchings and the sum of the edge weights is minimal. Takes cost[N][M], where cost[i][j] = cost for L[i] to be matched with R[j] and returns (min cost, match), where L[i] is matched with R[match[i]]. Negate costs for max cost.
// Time: O(N^2*M)
D mincostmatching(const VVD &a){//Benjamin Qi,chilli
	if(a.empty())return 0;
	I n=sz(a)+1,m=sz(a[0])+1;
	VD u(n),v(m),ppp(m),ans(n-1);
	rep(i,1,n){
		ppp[0]=i;
		I j0=0; // add "dummy" worker 0
		V dist(m,INT_MAX),pre(m,-1);
		VB done(m+1);
		do{
			done[j0]=true;
			I i0=ppp[j0],j1,delta=INT_MAX;
			rep(j,1,m)if(!done[j]){
				auto cur=a[i0-1][j-1]-u[i0]-v[j];
				if(cur<dist[j])dist[j]=cur,pre[j]=j0;
				if(dist[j]<delta)delta=dist[j],j1=j;
			}
			rep(j,0,m){
				if(done[j])u[ppp[j]]+=delta,v[j]-=delta;
				else dist[j]-=delta;
			}
			j0=j1;
		}while(ppp[j0]);
		while(j0){ // update alternating path
			I j1=pre[j0];
			ppp[j0]=ppp[j1],j0 =j1;
		}
	}
	rep(j,1,m)if(ppp[j])ans[ppp[j]-1]=j-1;
	return -v[0]; // min cost
}