// Description: Disjoint-set data structure with undo. If undo is not needed, skip st, time() and rollback().
// Usage: int t = uf.time(); ...; uf.rollback(t);
// Time: $O(log N)$
STR dsudelete{//Lukas Polacek,Simon Lindholm
	V e;
	VP st;
	dsudelete(I n):e(n,-1){}
	I size(I x){return -e[find(x)];}
	I find(I x){return e[x]<0 ? x:find(e[x]);}
	I time(){return sz(st);}
	Z rollback(I t){
		for(I i=time();i-->t;)
			e[st[i].first]=st[i].second;
		st.resize(t);
	}
	B join(I a,I b){
		a=find(a),b=find(b);
		if(a==b)return false;
		if(e[a]>e[b])swap(a,b);
		st.push_back({a,e[a]});
		st.push_back({b,e[b]});
		e[a]+=e[b];e[b]=a;
		return true;
	}
};