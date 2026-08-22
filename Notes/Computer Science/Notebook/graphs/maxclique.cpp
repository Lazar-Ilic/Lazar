// Description: Quickly finds a maximum clique of a graph (given as symmetric bitset matrix; self-edges not allowed). Can be used to find a maximum independent set by finding a clique of the complement graph.
// Time: Runs in about 1s for n=155 and worst case random graphs (p=.90). Runs faster for sparse graphs.
STR maxclique{//chilli,SJTU,Janez Konc
	D limit=0.025,pk=0;
	STR vertex{I i,d=0;};
	vector<bitset<200>> e;
	vector<vertex> y;
	VV c;
	V qmax,q,s,old;
	Z initialize(vector<vertex>& r){
		for(auto& v:r)v.d=0;
		for(auto& v:r)for(auto j:r)v.d+=e[v.i][j.i];
		sort(all(r),[](auto a,auto b){return a.d>b.d;});
		I mxD=r[0].d;
		rep(i,0,sz(r))r[i].d=min(i,mxD)+1;
	}
	Z expand(vector<vertex>& z,I lev=1){
		s[lev]+=s[lev-1]-old[lev];
		old[lev]=s[lev-1];
		while(sz(z)){
			if(sz(q)+z.back().d<=sz(qmax))return;
			q.push_back(z.back().i);
			vector<vertex> t;
			for(auto v:z)if(e[z.back().i][v.i])t.push_back({v.i});
			if (sz(t)){
				if(s[lev]++/++pk<limit)initialize(t);
				I j=0,mxk=1,mnk=max(sz(qmax)-sz(q)+1,1);
				c[1].clear(),c[2].clear();
				for(auto v:t){
					I k=1;
					auto f=[&](I i){return e[v.i][i];};
					while(any_of(all(c[k]),f))k++;
					if(k>mxk)mxk=k,c[mxk+1].clear();
					if(k<mnk)t[j++].i=v.i;
					c[k].push_back(v.i);
				}
				if(j>0)t[j-1].d=0;
				rep(k,mnk,mxk+1)for(I i:c[k])
					t[j].i=i,t[j++].d=k;
				expand(t,lev+1);
			}else if(sz(q)>sz(qmax))qmax=q;
			q.pop_back(),z.pop_back();
		}
	}
	V maxclique(){initialize(y),expand(y);return qmax;}
	maxclique(vector<bitset<200>> conn):e(conn),c(sz(e)+1),s(sz(c)),old(s){
		rep(i,0,sz(e))y.push_back({i});
	}
};