#include <bits/stdc++.h>
using namespace std;

int main() {
	// Immediately it becomes clear that the first bit uniquely forces that bit in the matrix and from there on out we may compute a ugh array of booleans and O[n^3] may or may not be ACcepted here but I should know these metrics and numerics off the top of my dome to be sure. Technically we may get like better performance somehow with Fast Fourier Transformation or optimised matrix multiplication and this is worth considering if I face a harder Platinum version maybe.
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);
	int a,b,c,d,e,f,g,h,x,y,z;
	vector<int> av,bv,cv;
	string as;
	cin>>a;
	vector<string> avs(a-1);
	vector<vector<bool>> avvb(a,vector<bool>(a));
	for(b=0;b<a-1;b++){
		cin>>as;
		avs[b]=as;
	}
	for(b=a-2;b>=0;b--){
		// Process string avs[b] pointing b upwards.
		if(avs[b][0]=='1')avvb[b][b+1]=1;
		for(c=b+2;c<=a-1;c++){
			y=0;
			for(d=b+1;d<c;d++)if(avvb[b][d] and avs[d][c-d-1]=='1')y++;
			if(y%2!=(int)(avs[b][c-b-1]-'0'))avvb[b][c]=1;
		}
	}
	z=0;
	for(auto dude1:avvb)for(auto dude2:dude1)if(dude2)z++;
	cout<<z<<endl;
}