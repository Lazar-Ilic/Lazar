#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,f;
	long long al,el;
	cin>>a>>b;
	vector<long long> avl(a);
	for(c=0;c<a;c++){
		cin>>avl[c];
	}
	for(c=0;c<b;c++){
		cin>>d;
		el=0;
		for(f=0;f<a and el<d;f++){
			al=max(el,avl[f]);
			avl[f]+=max((long long)0,min(avl[f],(long long)d)-el);
			el=al;
		}
	}
	for(auto dude:avl)cout<<dude<<endl;
}