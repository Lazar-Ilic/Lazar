#include <bits/stdc++.h>
using namespace std;

int main() {
	// At first I misread the task statement and had basically midkey interpreted it as a question where instead of precise ranking permutation we instead just had inequalities... like we need dude i to be behind at least j dudes or at most j dudes... at which point it would become a little bit of a trickier task. As it stands we simply note that for the desired permutation to hold we need each inequality to hold and each of those are simply linear at which point we just need to keep track of the minimum and maximum possible times through each dude and then output the minimum if it is viable or else -1 earlier on the moment it becomes broken works OK.
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,z;
	cin>>a;
	for(b=0;b<a;b++){
		cin>>c;
		vector<long long> av(c),bv(c),cv(c),dv(c);
		for(d=0;d<c;d++)cin>>av[d];
		for(d=0;d<c;d++)cin>>bv[d];
		for(d=0;d<c;d++){
			cin>>cv[d];
			dv[cv[d]]=d;
		}
		long long al,bl,cl;
		al=0; // Minimum number of days.
		bl=LLONG_MAX; // Maximum number of days.
		z=1;
		for(d=0;d<c-1 and z;d++){
			// Check infinite interval or compute 1 sided range.
			e=dv[d];
			f=dv[d+1];
			if(bv[e]==bv[f] and av[e]<=av[f]){cout<<-1<<endl;z=0;}
			else if((av[e]<=av[f] and bv[e]>bv[f]) or (av[e]>=av[f] and bv[e]<bv[f])){
				if(av[e]<=av[f] and bv[e]>bv[f])al=max(al,(av[f]-av[e])/(bv[e]-bv[f])+1);
				else bl=min(bl,(av[e]-av[f])/(bv[f]-bv[e])-((av[e]-av[f])%(bv[f]-bv[e])==0));
				if(al>bl){cout<<-1<<endl;z=0;}
			}
		}
		if(z)cout<<al<<endl;
	}
}