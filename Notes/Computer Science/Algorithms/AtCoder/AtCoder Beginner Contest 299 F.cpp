/*
Seems like if we take S+S' then this precise condition like morphs in to ungh no no no palindrome would be cool to use here somehow with respect to ungh cyclicity I think umm maybe can like consider ending points and uh reverse ungh like try 100 cases of flipping and uh compute the uh max palindromes is like uh oh never mind subsequence.

OK there exists tons of related literature and I could Credence 0.9 smash this one out in 240 minutes but not in-round today here I think. Onsighted G go for it.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
inline int add(int x, int y){x+=y; if(x>=mod)x-=mod; return x;}
inline int sub(int x, int y){ x-= y; if(x<0) x+=mod; return x;}
const int N = 205;
int dp[N][N];
inline int cnt(string s1, string s2){
	int l1 = s1.length(), l2 = s2.length();
	for(int i = 0;i<=l1;i++) for(int j = 0;j<=l2;j++) dp[i][j] = 1;
	for(int i = l1-1;i>=1;i--)
		for(int j = l2-1;j>=1;j--){
			dp[i][j] = sub(add(dp[i][j+1],dp[i+1][j]),dp[i+1][j+1]);
			if(s1[i]==s2[j]) dp[i][j] = add(dp[i][j], dp[i+1][j+1]);
		}
	int ans = 0;
	for(int i = 0;i<l2;i++) if(s2[i] == s1[0]) ans = add(ans, dp[1][i+1]);
	return ans;	
}
int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t;
	//cin>>t;
	t=1;
	while(t--){
		string s;
		cin>>s;
		int l = s.length();
		int ans= 0;
		for(int i = 1;i<=l-1;i++){
			string s1 = s.substr(0,i), s2 = s.substr(i,l-i);
			ans = add(ans,cnt(s2,s1));
		}
		cout << ans << endl;
	}
}