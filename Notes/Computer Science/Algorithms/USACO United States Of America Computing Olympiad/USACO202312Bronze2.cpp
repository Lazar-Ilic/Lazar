#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e;
	string as;
	vector<int> av;
	b=INT_MAX; // Minimum odd length.
	cin>>a>>as;
	for(c=0;c<a;c++){
		d=0;
		while(c<a and as[c]=='1'){
			d++;
			c++;
		}
		if(d>0){c--;av.push_back(d);}
		if(d>0 and (d==c+1 or c==a-1))b=min(b,2*d-1);
		else if(d>0 and d-1+d%2<b)b=d-1+d%2;
	}
	if((int)av.size()==0)cout<<0<<endl;
	else if((int)av.size()==1)cout<<1<<endl;
	else{
		e=0;
		for(auto dude:av){
			e+=dude/b+(dude%b!=0);
		}
		cout<<e<<endl;
	}
}