#include <bits/stdc++.h>
using namespace std;

int main() {
	// Would seem like first we can process through pairs and sort to get the weights and quantities in order and then basically just run a simulation should probably work uh layer by layer somehow basically just want to uh greedy it up so insert like the first M dudes at layer 1 uh... inserting in to a priority queue maybe {height, 1, multiplicity} somehow and then every step through we keep on operating on uh... basically pop a dude out and then either 1 breaks uh if this is the bottom actionable dude then we cover cover whatever and pop back in splits in to 2 dudes is still like a priority queue stack size is under limit and at the end we process through popping summing up like layer * multiplicity for each dude in the thingy I think. That is to say that basically a well implemented naive greedy simulation here ought to work OK.
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	long long a,b,c,d,e,f,g,h,i,j,k,l,z;
	priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>> apq;
	pair<long long,pair<long long,long long>> appp,bppp,cppp;
	vector<pair<long long,long long>> avp;
	cin>>a>>b>>c;
	for(d=0;d<a;d++){
		cin>>e>>f;
		avp.push_back({-e,f});
	}
	sort(avp.begin(),avp.end());
	apq.push({avp[0].first-c,{0,b}});
	if(c>=100000){
		for(d=0;d<a;d++){
		e=avp[d].first;
		f=avp[d].second;
		while(f>0 and e>=(apq.top()).first+c){
			appp=apq.top();
			apq.pop();
			bppp={e,{(appp.second).first+1,min(f,(appp.second).second)}};
			f-=(bppp.second).second;
			apq.push(bppp);
			if((bppp.second).second<(appp.second).second){
				cppp={appp.first,{(appp.second).first,(appp.second).second-(bppp.second).second}};
				apq.push(cppp);
			}
		}
	}
	}
	else{
		for(d=0;d<a;d++){
			e=avp[d].first;
			f=avp[d].second;
			g=((apq.top()).second).first;
			while(f>0 and e>=(apq.top()).first+c and g==(((apq.top()).second).first)){
				appp=apq.top();
				apq.pop();
				f-=(appp.second).second;
			}
			if(f<0){
				apq.push({appp.first,{(appp.second).first,-f}});
				f=0;
			}
			apq.push({e,{g+1,avp[d].second-f}});
			h=f;
			while(f>0 and e>=(apq.top()).first+c and g+1==(((apq.top()).second).first)){
				appp=apq.top();
				apq.pop();
				f-=(appp.second).second;
			}
			if(f<0){
				apq.push({appp.first,{(appp.second).first,-f}});
				f=0;
			}
			if(h-f>0)apq.push({e,{g+2,h-f}});
		}
	}
	long long al=0;
	while(!apq.empty()){
		appp=apq.top();
		apq.pop();
		al+=(long long)(appp.second).first*(appp.second).second;
	}
	cout<<al<<endl;
}