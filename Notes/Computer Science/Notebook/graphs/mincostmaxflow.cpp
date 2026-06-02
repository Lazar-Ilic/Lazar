// Description: Min-cost max-flow. cap[i][j] != cap[j][i] is allowed; double edges are not. If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported. To obtain the actual flow, look at positive values only.
// Time: Approximately O(E^2)
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
const L inf = numeric_limits<L>::max()/4;
//SET children[500];
STR MCMF{//Stanford
	I N;VV edges,revedges;VVL capacity,flow,cost;V seen;VL distance,pi;VP parent;
	MCMF(I N):
		N(N),edges(N),revedges(N),capacity(N,VL(N)),flow(capacity),cost(capacity),seen(N),distance(N),pi(N),parent(N){}
	Z addedge(I from, I to, L capacity, L cost){
		this->capacity[from][to] = capacity;
		this->cost[from][to] = cost;
		edges[from].push_back(to);
		revedges[to].push_back(from);
	}
	Z path(I s){
		fill(all(seen),0);
		fill(all(distance),inf);
		distance[s] = 0;L di;
		__gnu_pbds::priority_queue<pair<L,I>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});
		auto relax = [&](I i, L capacity, L cost, I dir) {
			L val = di - pi[i] + cost;
			if (capacity && val < distance[i]) {
				distance[i] = val;
				parent[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-distance[i], i});
				else q.modify(its[i], {-distance[i], i});
			}
		};
		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = distance[s] + pi[s];
			for (I i : edges[s]) if (!seen[i])
				relax(i, capacity[s][i] - flow[s][i], cost[s][i], 1);
			for (I i : revedges[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + distance[i], inf);
	}
	PL maxflow(I source,I sink){
		L totalflow=0,totalcost=0;
		while (path(source),seen[sink]){
			L fl=inf;
			for(I p,r,x=sink;tie(p,r)=parent[x],x!=source;x=p){
				fl=min(fl,r?capacity[p][x]-flow[p][x]:flow[x][p]);
			}
			totalflow+=fl;
			for(I p,r,x=sink;tie(p,r)=parent[x],x!=source;x=p){
				if(r){
					flow[p][x]+=fl;
					//children[p].insert(x);
				}
				else{
					flow[x][p]-=fl;
					//children[x].erase(p);
				}
			}
		}
		for(I i=0;i<N;i++){
			for(I j=0;j<N;j++){
				totalcost+=cost[i][j]*flow[i][j];
			}
		}
		return {totalflow,totalcost};
	}
	// If some costs can be negative, call this before maxflow:
	Z negcosts(I source){ // (otherwise, leave this out)
		fill(all(pi), inf); pi[source] = 0;
		I it = N, ch = 1; L v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != inf)
				for (I to : edges[i]) if (capacity[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

//--------------------------------------------------------------------

Z az(){
	in>>a>>b;
	MCMF amax(a);
	for(c=0;c<b;c++){
		in>>d>>e>>f>>g;
		amax.addedge(d,e,f,g);
	}
	amax.negcosts(0);
	PL apl=amax.maxflow(0,a-1);
	out<<apl.first<<nl<<apl.second<<nl;
	for(b=0;b<sz(amax.edges);b++){
		for(c=0;c<sz(amax.edges[b]);c++){
			//process edge from b to amax.edges[b][c] like
			//amax.flow[b][amax.edges[b][c]]==1 works
			//check coherence of b and amax.edges[b][c]
		}
	}
}