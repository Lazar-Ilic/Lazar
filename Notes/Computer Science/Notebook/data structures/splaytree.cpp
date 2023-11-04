STR splaytree{
	STR node{I ch[2]={0,0},v=0;B flip=0;I sz=0;};
	vector<node> t;
	splaytree(I n):t(n+1){
		for(I i=1;i<=n;++i)pull(i);
	}
	Z push(I x){
		if(!x or !t[x].flip)return;
		I l=t[x].ch[0],r=t[x].ch[1];
    	t[l].flip^=1,t[r].flip^=1;
    	swap(t[x].ch[0],t[x].ch[1]);
    	t[x].flip=0;
  	}
  	Z pull(I x){
    	if(!x)return;
    	I l=t[x].ch[0],r=t[x].ch[1];
    	t[x].sz=1+t[l].sz+t[r].sz;
  	};
  	Z set(I x,I d,I y){
    	t[x].ch[d]=y;t[y].v=x;pull(x); 
  	}
  	Z splay(I x){
    	auto dir=[&](I x){
      	I v=t[x].v;if(!v)return -1;
      	return t[v].ch[0]==x?0:t[v].ch[1]==x?1:-1;
    	};
		auto rotate=[&](I x){
      	I y=t[x].v,z=t[y].v,dx=dir(x),dy=dir(y);
      	set(y,dx,t[x].ch[!dx]);set(x,!dx,y);
      	if(~dy)set(z,dy,x); 
      	t[x].v=z;
    	};
    	for(push(x);~dir(x);){
      		I y=t[x].v,z=t[y].v;
      		push(z);push(y);push(x);
      		I dx=dir(x),dy=dir(y);
      		if(~dy)rotate(dx!=dy?x:y);
      		rotate(x);
    	}
  	}
  	Z join(I l,I r){
    	if(!l or !r)return;
    	for(push(l);t[l].ch[1];l=t[l].ch[1],push(l));
    	splay(l);splay(r);assert(t[l].ch[1]==0);set(l,1,r);
  	}
};

Z az(){
	in>>n;
	splaytree asplay(n);
	V av(n);
	for(i=0;i<n;++i)in>>av[i];
	for(i=1;i<n;++i)asplay.set(av[i],0,av[i-1]);
 	out<<n-1<<'\n';
	for(i=1;i<n;++i){
		asplay.splay(i);
		I l=asplay.t[i].ch[0],r=asplay.t[i].ch[1];
		out<<i<<" "<<i+asplay.t[l].sz<<'\n';
		asplay.t[l].flip^=1;
		asplay.set(i,0,0);asplay.set(i,1,0);
		asplay.join(l,r);
  	}
}