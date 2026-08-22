#include <bits/stdc++.h>
using namespace std;

int main() {
	// Of course any dude which appears in neither can be made to work and then we need to create 2 vectors for each direction and the offset multiplicity to maximise in O[n].
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,z;
	cin>>a>>b;
	vector<bool> avb(a);
	vector<int> av(b),bv(a,-1),cv(b),dv(a,-1),ev(b),fv(b);
	for(c=0;c<b;c++){
		cin>>av[c];
		av[c]--;
		avb[av[c]]=1;
		bv[av[c]]=c;
	}
	for(c=0;c<b;c++){
		cin>>cv[c];
		cv[c]--;
		avb[cv[c]]=1;
		dv[cv[c]]=c;
	}
	for(c=0;c<a;c++){
		if(bv[c]!=-1 and dv[c]!=-1){
			ev[(bv[c]-dv[c]+b)%b]++;
			fv[(bv[c]+dv[c])%b]++;
		}
	}
	z=0;
	for(auto dude:ev)if(dude>z)z=dude;
	for(auto dude:fv)if(dude>z)z=dude;
	for(auto dude:avb)if(dude==0)z++;
	cout<<z<<endl;
}