// Description: Aho-Corasick automaton, used for multiple pattern matching. Initialize with AhoCorasick ac(patterns); the automaton start node will be at index 0. find(word) returns for each position the index of the longest word that ends there, or -1 if none. findAll(-, word) finds all words (up to N^(3/2) many if no duplicate patterns) that start at each position (shortest first). Duplicate patterns are allowed; empty patterns are not. To find the longest words that start at each position, reverse all input. For large alphabets, split each symbol into chunks, with sentinel bits for symbol boundaries.
// Time: construction takes O(26N), where N= sum of length of patterns. find(x) is O(N), where N=length of x. findAll is O(NM)

//--------------------------------------------------------------------

//I patterncount[500001];
//I patternindex[500001];
STR stringsmatch{//Simon Lindholm
	enum{alpha=26,first ='a'}; // CHANGE THIS!!!
	STR node{// nmatches is optional
		I back,next[alpha],start=-1,end=-1,nmatches=0;
		node(I v){memset(next,v,sizeof(next));}
	};
	vector<node> z;
	V backp;
	Z insert(S& s,I j){
		assert(!s.empty());
		I n=0;
		for(C c:s){
			I& m=z[n].next[c-first];
			if(m==-1){n=m=sz(z);z.emplace_back(-1);}
			else n=m;
		}
		if(z[n].end==-1)z[n].start=j;
		backp.push_back(z[n].end);
		z[n].end=j;
		z[n].nmatches++;
	}
	stringsmatch(VS& pat):z(1,-1){
		rep(i,0,sz(pat))insert(pat[i],i);
		z[0].back=sz(z);
		z.emplace_back(0);
		queue<I> q;
		for(q.push(0);!q.empty();q.pop()){
			I n=q.front(),prev=z[n].back;
			rep(i,0,alpha){
				I &ed=z[n].next[i],y=z[prev].next[i];
				if(ed==-1)ed=y;
				else{
					z[ed].back=y;
					(z[ed].end==-1?z[ed].end:backp[z[ed].start])
						=z[y].end;
					z[ed].nmatches+=z[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	V find(S word){
		I n=0;
		V res; // L count=0;
		for(C c:word){
			n=z[n].next[c-first];
			res.push_back(z[n].end);
			// count+=z[n].nmatches;
		}
		return res;
	}
	VV findall(VS& pat,S word){
		V r=find(word);
		VV res(sz(word));
		rep(i,0,sz(word)){
			I ind=r[i];
			while(ind!=-1){
				res[i-sz(pat[ind])+1].push_back(ind); // can remove
				//if(patterncount[ind]==0)patternindex[ind]=i-sz(pat[ind])+1; 
				//patterncount[ind]++;
				// count incidences of patterns in avs/VS& pat
				ind=backp[ind];
			}
		}
		return res;
	}
};

//--------------------------------------------------------------------

Z az(){
    in>>as>>a;
    for(b=0;b<a;b++){
        in>>bs;
        avs.add(bs);
    }
    stringsmatch aho(avs);
    avv=aho.findall(avs,as);
    for(a=0;a<sz(avv);a++){
        for(b=0;b<sz(avv[a]);b++){
            av[avv[a][b]]++;
        }
    }
    for(a=0;a<sz(av);a++){
        out<<av[a]<<nl;
    }
}