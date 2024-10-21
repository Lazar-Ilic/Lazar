STR DSU{//Benjamin Qi
	V av;
	DSU(I a){av=V(a,-1);}
	I get(I a){while(av[a]>-1){a=av[a];}return a;}
	B sameset(I a,I b){return get(a)==get(b);}
	I size(I a){return -av[get(a)];}
	B unite(I a,I b){
		a=get(a),b=get(b);if(a==b)return 0;
		if(av[a]>av[b])swap(a,b);
		av[a]+=av[b];av[b]=a;return 1;
	}
};
//dsu(I a)
//I get(I a)
//B sameset(I a,I b)
//I size(I a)
//B unite(I a,I b)