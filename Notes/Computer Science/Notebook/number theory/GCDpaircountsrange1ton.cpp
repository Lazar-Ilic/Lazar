	avl=VL(n+1);
	for(al=n;al>=1;al--){
		avl[al]=(n/al)*((n/al)-1)/2;
		for(bl=2*al;bl<=n;bl+=al){
			avl[al]-=avl[bl];
		}
	}

//----------

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> dp(n+1);
        for(ll i=n;i>=1;i--){
            dp[i]=(n/i)*((n/i)-1)/2;
            for(ll j=2*i;j<=n;j+=i){
                dp[i]-=dp[j];
            }
        }
        ll x=0;
        for(ll i=n;i>=2;i--){
            if(m<i-1){
                continue;
            }
            ll k=m/(i-1);
            ll l=dp[i]/(i-1);
            m-=min(k,l)*(i-1);
            x+=min(k,l)*i;
            if(m==0){
                break;
            }
        }
        if(m){
            cout<<-1<<endl;
        }
        else{
            cout<<x<<endl;
        }
    }
}