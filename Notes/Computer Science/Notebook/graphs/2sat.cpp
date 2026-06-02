// Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type (a or b) and (!a or c) and (d or !b) and ... becomes true, or reports that it is unsatisfiable. Negated variables are represented by bit-inversions !x.
// Usage:
//  TwoSat ts(number of boolean variables);
//  ts.either(0, !3); // Var 0 is true or var 3 is false
//  ts.setValue(2); // Var 2 is true
//  ts.atMostOne({0,!1,2}); // <= 1 of vars 0, !1 and 2 are true
//  ts.solve(); // Returns true iff it is solvable
//  ts.values[0..m-1] holds the assigned values to the vars
// Time: O(m+E), where m is the number of boolean variables, and E is the number of clauses.
STR 2sat{//Emil Lenngren,Simon Lindholm
	I m;
	VV gr;
	V values; // 0 = false, 1 = true
	2sat(I n=0):m(n),gr(2*n){}
	I addvariable(){ // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return m++;
	}
	Z either(I f,I j){
		f=max(2*f,-1-2*f);
		j=max(2*j,-1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	Z setvalue(I x){either(x,x);}
	Z atmostone(const V& li){ // (optional)
		if (sz(li) <= 1) return;
		I cur=~li[0];
		rep(i,2,sz(li)){
			I next=addvariable();
			either(cur,~li[i]);
			either(cur,next);
			either(~li[i],next);
			cur=~next;
		}
		either(cur,~li[1]);
	}
	V val,comp,z;I time=0;
	I dfs(I i){
		I low=val[i]=++time,x;z.push_back(i);
		for(I e:gr[i])if(!comp[e])
			low=min(low,val[e] ?: dfs(e));
		if(low==val[i]){
			do{
			x=z.back();z.pop_back();
			comp[x]=low;
			if(values[x>>1]==-1)values[x>>1]=x&1;
			}while(x!=i);
		}
		return val[i]=low;
	}
	B solve(){
		values.assign(m,-1);
		val.assign(2*m,0);comp=val;
		rep(i,0,2*m)if(!comp[i])dfs(i);
		rep(i,0,m)if(comp[2*i]==comp[2*i+1])return 0;
		return 1;
	}
};