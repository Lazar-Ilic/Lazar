// Description: Push-relabel using the highest label selection rule and the gap heuristic. Quite fast in practice. To obtain the actual flow, look at positive values only.
// Time: O(V^2 * E^(1/2))
STR pushrelabel{//Simon Lindholm
	STR edge{
		I dest, back;
		L f, c;
	};
	vector<vector<edge>> g;
	VL ec;
	vector<edge*> cur;
	VV hs; V H;
	pushrelabel(I n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
	Z addedge(I s, I t, L cap, L rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}
	Z addflow(edge& e, L f) {
		edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	L generate(I s, I t) {
		I v = sz(g); H[s] = v; ec[t] = 1;
		V co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (edge& e : g[s]) addflow(e, e.c);
		for (I hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			I u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addflow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	B leftofcut(I a){return H[a] >= sz(g);}
};