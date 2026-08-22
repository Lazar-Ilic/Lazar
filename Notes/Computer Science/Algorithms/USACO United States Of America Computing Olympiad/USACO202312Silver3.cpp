#include <bits/stdc++.h>
using namespace std;

int main() {
	// Simple Dynamic Program based on basically uh imagining all possible changes of 1 character and uh without loss of generality call it like position 2 with respect to the underlying note that each deviant state is -2 -1 1 or 2 in fact and then check each time basically start at [0][0] with a maximum of 0 and propagate forward only relevantly. OK upon re reading it becomes clear this will not work as each target can only be shot once. So we need to process somehow from Left to Right normally maybe and also somehow process back Right to Left so... track each possible dude from Right to Left for sure inserting in reverse basically as Right as possible when the shot occurs so that way we have accurate reads processing Left to Right. After this I could potentially hop in the mixture on some SIE Securities Industry Essentials review and preparations... note taking in .txt to ACe that one soon... and the MCAT Medical College Admission Test. To get in to -2 position we must change a 'R' to a 'L' and to get to -1 we must change a F to a L or a R to a F... logically cased out somehow.
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,g,h,x,y,z;
	vector<int> av,bv,cv;
	string as;
	cin>>a>>b;
	vector<bool> avb(2*b+1),bvb(2*b+1);
	for(c=0;c<a;c++){
		cin>>d;
		avb[d+b]=1; // Target at location.
	}
	cin>>as;
	av=vector<int>(b+1); // Positions normally...
	bv=vector<int>(2*b+1,-1); // Earliest time shot normally.
	cv=vector<int>(b+1);
	z=0; // Normal total count shot.
	vector<pair<int,int>> avp; // Indices of times first shot ugh to -- later off of.
	for(c=1;c<=b;c++){
		if(as[c-1]=='L')av[c]=av[c-1]-1;
		else if(as[c-1]=='R')av[c]=av[c-1]+1;
		else{
			av[c]=av[c-1];
			if(avb[av[c]+b] and bv[av[c]+b]==-1){
				bv[av[c]+b]=c;
				avp.push_back({c,av[c]+b});
				z++;
			}
		}
		cv[c]=z; // Score if live in normal round...
	}
	int answer=z;
	y=z;
	x=(int)avp.size()-1;
	for(c=b;c>=1;c--){
		// Compute potential if we flipped this position from R to L somehow and all others behind it ugh to the right of it I mean...
		if(as[c-1]=='R')answer=max(answer,y);
		if(as[c-1]=='F' and av[c]-2+b>=0 and avb[av[c]-2+b] and bvb[av[c]-2+b]==0){
			bvb[av[c]-2+b]=1;
			if(bv[av[c]-2+b]>=c or bv[av[c]-2+b]==-1)y++;
		}
		while(x>=0 and avp[x].first==c){
			// Process to y-- as relevant here.
			if(!bvb[avp[x].second])y--;
			x--;
		}
	}
	y=z;
	x=(int)avp.size()-1;
	bvb=vector<bool> (2*b+1);
	for(c=b;c>=1;c--){
		if(as[c-1]=='L')answer=max(answer,y);
		if(as[c-1]=='F' and av[c]+2+b<=2*b and avb[av[c]+2+b] and bvb[av[c]+2+b]==0){
			bvb[av[c]+2+b]=1;
			if(bv[av[c]+2+b]>=c or bv[av[c]+2+b]==-1)y++;
		}
		while(x>=0 and avp[x].first==c){
			// Process to y-- as relevant here.
			if(!bvb[avp[x].second])y--;
			x--;
		}
	}
	y=z;
	x=(int)avp.size()-1;
	bvb=vector<bool> (2*b+1);
	for(c=b;c>=1;c--){
		if(as[c-1]=='R')answer=max(answer,y+(av[c]-1+b>=0 and avb[av[c]-1+b] and bvb[av[c]-1+b]==0 and (bv[av[c]-1+b]==-1 or bv[av[c]-1+b]>=c)));
		if(as[c-1]=='F')answer=max(answer,y-((bv[av[c]+b]>=c) and bvb[av[c]+b]==0));
		if(as[c-1]=='F' and av[c]-1+b>=0 and avb[av[c]-1+b] and bvb[av[c]-1+b]==0){
			bvb[av[c]-1+b]=1;
			if(bv[av[c]-1+b]>=c or bv[av[c]-1+b]==-1)y++;
		}
		while(x>=0 and avp[x].first==c){
			// Process to y-- as relevant here.
			if(!bvb[avp[x].second])y--;
			x--;
		}
	}
	y=z;
	x=(int)avp.size()-1;
	bvb=vector<bool> (2*b+1);
	for(c=b;c>=1;c--){
		if(as[c-1]=='L')answer=max(answer,y+(av[c]+1+b<=2*b and avb[av[c]+1+b] and bvb[av[c]+1+b]==0 and (bv[av[c]+1+b]==-1 or bv[av[c]+1+b]>=c)));
		if(as[c-1]=='F')answer=max(answer,y-((bv[av[c]+b]>=c) and bvb[av[c]+b]==0));
		if(as[c-1]=='F' and av[c]+1+b<=2*b and avb[av[c]+1+b] and bvb[av[c]+1+b]==0){
			bvb[av[c]+1+b]=1;
			if(bv[av[c]+1+b]>=c or bv[av[c]+1+b]==-1)y++;
		}
		while(x>=0 and avp[x].first==c){
			// Process to y-- as relevant here.
			if(!bvb[avp[x].second])y--;
			x--;
		}
	}
	cout<<answer<<endl;
}