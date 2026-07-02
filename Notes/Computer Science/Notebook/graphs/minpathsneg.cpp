// Description: Calculates shortest paths from s in a graph that might have negative edge weights. Unreachable nodes get dist=inf; nodes reachable through negative-weight cycles get dist=-inf. Assumes V^2 * max |wi| < ~2^63
// Time: O(E*V)
const L inf=LLONG_MAX;
STR edge{I a,b,w,s(){return a<b?a:-a;}};
STR node{L dist=inf;I prev=-1;};
Z minpathsneg(vector<node>& nodes,vector<edge>& eds,I s) {//Simon Lindholm
	nodes[s].dist=0;
	sort(all(eds),[](edge a,edge b){return a.s()<b.s();});
	I lim=sz(nodes)/2+2; // /3+100 with shuffled vertices
	rep(i,0,lim)for(edge ed:eds){
		node cur=nodes[ed.a],&dest=nodes[ed.b];
		if(abs(cur.dist)==inf)continue;
		L d=cur.dist+ed.w;
		if(d<dest.dist){
			dest.prev=ed.a;
			dest.dist=(i<lim-1?d:-inf);
		}
	}
	rep(i,0,lim)for(edge e:eds){
		if(nodes[e.a].dist==-inf)nodes[e.b].dist=-inf;
	}
}

//--------------------------------------------------------------------

Z az(){
    in>>a>>b;
	vector<node> nodes=vector<node>(a+1);
	vector<edge> eds;
	for(d=0;d<b;d++){
		in>>e>>f>>g;
		edge aee=edge();
		aee.a=e;
		aee.b=f;
		aee.w=-g;
		eds.add(aee);
	}
	minpathsneg(nodes,eds,1);
	if(nodes[a].dist==-inf)out<<-1<<nl;
	else out<<-nodes[a].dist<<nl;
}