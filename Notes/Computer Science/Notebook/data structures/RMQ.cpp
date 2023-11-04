/*
Use as auxiliary in older codes.
Description: Range Minimum Queries on an array.
Returns min(av[a], av[a + 1], ... av[b - 1]) in constant time.
Usage:
	RMQ rmq(values);
	rmq.query(inclusive, exclusive);
Time: O[|av| * log |av| + Q]
*/
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

// ----------

/*
Use for inclusive rather than exclusive Right boundary bound.
Description: Range Minimum Queries on an array.
Returns min(av[a], av[a + 1], ... av[b]) in constant time.
Usage:
	RMQ rmq(values);
	rmq.query(inclusive,inclusive);
Time: O[|av| * log |av| + Q]
*/
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
	T query(I a,I b){ //[a,b]
		b++;
		assert(a<b); //or return inf if a==b
		I d=31-__builtin_clz(b-a);
		return min(c[d][a],c[d][b-(1<<d)]);
	}
};