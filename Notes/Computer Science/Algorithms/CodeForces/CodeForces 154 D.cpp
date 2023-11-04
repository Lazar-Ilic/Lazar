// ctzsm
// Interesting case study on fast robust C++

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m,k;
char t[405][405];
int sum[405][405];
int sam[405];
int cnt[26];
int main(int argc, char** argv) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= n; ++i){
        scanf("%s",t[i] + 1);
    }
    for(int i = 1;i <= n; ++i){
        for(int j = 1;j <= m; ++j){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if(t[i][j] == 'a') sum[i][j] ++;
        }
    }
    long long ans = 0;
    for(int y1 = 1;y1 <= n; ++y1){
        for(int y2 = y1 + 1;y2 <= n; ++y2){
            memset(cnt,0,sizeof(cnt));
            for(int x1 = 1;x1 <= m; ++x1){
                sam[x1] = sum[y2][x1] - sum[y1-1][x1];
            }
            for(int x1 = 0,x2 = 1;x2 <= m; ++x2){
                if(t[y1][x2] == t[y2][x2]){
                    int ch = t[y1][x2] - 'a';
                    while(x1 + 1 < x2 && sam[x2] - sam[x1] > k){
                        if(t[y1][x1 + 1] == t[y2][x1 + 1]){
                            cnt[t[y1][x1 + 1] - 'a'] --;
                        }
                        x1++;
                    }
                    ans += cnt[ch];
                    cnt[ch] ++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

