#include <bits/stdc++.h>
using namespace std;

int main() {
	// Seems potentially like a simple enough formulaic approach would work here uh a binary search or rather ternary search on unimodality perhaps in conjunction with some kind of lowerbound structures in place for handling summations of distances... or maybe even a uh uh uh oh we may simply take those arrays 2 arrays in O[10^6] to capture the distance left and distance right from this start point and then do a ternary search upon those dudes. Kind of awkward here realising that maybe in Platinum there could be a sharper version I uh frankly think sorting the queries... if I ACe this Gold round I might take the time to implement up a sorted queries offline so that way we smooth from like Left to Right or whatever could honestly consider ugh what an interesting side task maybe inspires me to write up a new one for next month's public GitHub push but a task where we basically sort queries offline and then ugh compute for query 0 then query Q-1 then query [Q-1]/2 and so on and so on basically is even faster than going Query 0 Query 1 Query 2 yadda which can have runtime up to like n*log[r] when we can speed it up to like worst case log[r]+2log[r/2]+4log[r/4]+... is nontrivially faster. So maybe I will code up that skeleton later and save it but focus on ACing this round task simply and minimally. I might later even write up that task somehow try to nail in the details such that you have to produce that idea in round to ACe the task. I could maybe even mock it up in CodeForces Polygon system to demonstrate or ping it onwards to the Educational team maybe if they want a free task contribution from me inspired by this one right here. In any case I since realised that here in this particular task we need to like ternary search each sub range I think around the critical point y. OK I still uh am not sure I misread the task and am not sure about multiplicity or unique here from the task statement so may as well assume worst case. Oh wait there is still like some sort of uh quasi continuity there ensured I think uh... oh wait is unimodality here even ensured uh... oh wait OKOKOK it is not a theorem that in general sum of unimodal would be unimodal but here the underlying cost function is conveniently like a each dude is inducing the same kind of uh modified V shape at which point the derivative would be uh... WLOG rounded off at the relevant points uh to 0 uh it is like uh... starts - and as we go from left to right can only flip flop upwards as each dude flips at its point from - to + means the derivative in fact goes from - to + and is 0 in the minimum necessarily yes. Oh gee now that I have made that insight I think this task has become much easier in fact uh... can just compute the point where the derivative flips from negative to >=0 and do it... sort the queries or not uh. Sum the indices of the dudes to the left and to the right strictly should work here.
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,g,h,x,y,z;
	long long dl,el,fl;
	cin>>a;
	vector<int> av(a);
	for(b=0;b<a;b++)cin>>av[b];
	sort(av.begin(),av.end());
	vector<long long> avl(a),bvl(a);
	for(b=1;b<a;b++)avl[b]=avl[b-1]+av[b-1];
	for(b=a-2;b>=0;b--)bvl[b]=bvl[b+1]+av[b+1];
	cin>>b;
	if(a==1){
		for(c=0;c<b;c++)cout<<0<<endl;
		return 0;
	}
	for(c=0;c<b;c++){
		cin>>dl>>el;
		// Need the ceiling of the intersection point with 0=(a-1-x)*e-(x)*d representing x dudes to the left ugh is (a-1-x)*e=x*d OK so like ceiling of e*(a-1)/(d+e)
		f=el*(a-1)/(dl+el)+((el*(a-1))%(dl+el)!=0);
		// Minor error here which can be repaired later.
		if(f-1>=0)g=f-1;
		else g=f;
		if(f+1<a)h=f+1;
		else h=f;
		cout<<min(dl*((long long)f*av[f]-avl[f])+el*(bvl[f]-(long long)(a-1-f)*(av[f])),min(dl*((long long)g*av[g]-avl[g])+el*(bvl[g]-(long long)(a-1-g)*(av[g])),dl*((long long)h*av[h]-avl[h])+el*(bvl[h]-(long long)(a-1-h)*(av[h]))))<<endl;
	}
}