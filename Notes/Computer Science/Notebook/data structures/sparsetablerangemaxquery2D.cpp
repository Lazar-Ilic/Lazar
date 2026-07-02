// https://codeforces.com/blog/entry/53810

deque<int> Q;
void Push(int x){
	while(Q.size() && Q.back()<x)
		Q.pop_back();
	Q.push_back(x);
}
int A[1005][1005],Best[1005][1005];
long long S[1005][1005];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			cin >> A[i][j];
			S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
		}
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		for(int i = 1; i <= n; ++i) {
			Q.clear();
			for(int j = 1; j <= m; ++j) {
				Push(A[i][j]);
				if(j >= b) {
					Best[i][j] = Q.front();
					if(Q.front() == A[i][j - b + 1])
						Q.pop_front();
				}
			}
		}
		long long ans = 1e18;
		for(int j = b; j <= m; ++j){
			Q.clear();
			for(int i = 1; i <= n; ++i){
				Push(Best[i][j]);
				if(i >= a){
					ans = min(ans, 1LL * a * b * Q.front() - S[i][j] + S[i - a][j] + S[i][j - b] - S[i - a][j - b]);
					if(Q.front() == Best[i - a + 1][j])
						Q.pop_front();
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

//----------

#include <bits/stdc++.h>
#define ll long long
//#define CLOCKS_PER_SEC 1500
#define maxe(a,b) a>b?(a):(b)
using namespace std;

int a[1010][1010],x,y,m,n,sum[1010][1010],opr;
int rmq[1001][1001][11][11];

inline int get_max(int a,int b,int c,int d)
{
    opr+=3;
    return max(a,max(b,max(c,d)));
}

int preprocess()
{
   int i,j,k,l=1,z;


   for(i=0;(1<<i) <=n;i++)
    for(j=0;(1<<j) <=m;j++)
     for(k=1;k+(1<<i)-1 <= n;k++)
      for(l=1;l+(1<<j)-1 <=m;l++)
        {
        if( i==0 && j==0)
            rmq[k][l][i][j]=a[k][l];
        else if( i==0)
            rmq[k][l][i][j]=max(rmq[k][l][i][j-1],rmq[k][l+(1<<(j-1))][i][j-1]);
        else if( j==0)
            rmq[k][l][i][j]=max(rmq[k][l][i-1][j],rmq[k+(1<<(i-1))][l][i-1][j]);
        else
            rmq[k][l][i][j]=max(rmq[k][l][i-1][j-1],max(rmq[k+(1<<(i-1))][l][i-1][j-1],max(rmq[k][l+(1<<(j-1))][i-1][j-1],rmq[k+(1<<(i-1))][l+(1<<(j-1))][i-1][j-1])));

        }
}

int maxx(int a,int b,int x,int y)
{
    int kx=(float)log(x-a+1)/log(2);
    //int kx=31 - __builtin_clz(x-a+1);
    int ky=(float)log(y-b+1)/log(2);
    //int ky=31 - __builtin_clz(y-b+1);

    //cout<<"kx"<<kx<<"ky"<<ky<<endl;
    //cout<<"returning"<<get_max(rmq[a][b][kx][ky],rmq[x-(1<<kx)+1][b][kx][ky],rmq[a][y-(1<<ky)+1][kx][ky],rmq[x-(1<<kx)+1][y-(1<<ky)+1][kx][ky])<<endl;
    return get_max(rmq[a][b][kx][ky],rmq[x-(1<<kx)+1][b][kx][ky],rmq[a][y-(1<<ky)+1][kx][ky],rmq[x-(1<<kx)+1][y-(1<<ky)+1][kx][ky]);
}
int main()
{
    int q,i,j,sol=1e9,ex,ey,tot;


    //ios::sync_with_stdio(false);
    //setvbuf(stdin, NULL, _IOFBF, 32768);
    //setvbuf(stdout, NULL, _IOFBF, 32768);
    //freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]),sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    //clock_t tStart = clock();
    preprocess();
    /*for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cout<<rmq[i][j][0][0]<<" ";
            */
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    //printf("opr %d\n",opr);
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d%d",&x,&y);
        sol=1e9;
        for(i=1;i<=n-x+1;i++)
            for(j=1;j<=m-y+1;j++)
                {
                    ex=i+x-1;
                    ey=j+y-1;
                    tot=sum[ex][ey]-sum[ex-x][ey]-sum[ex][ey-y]+sum[ex-x][ey-y];
                    //cout<<"tot"<<tot<<"maxx"<<maxx(i,j,ex,ey);
                    sol=min(sol,maxx(i,j,ex,ey)*x*y-tot);
                    //vis[i][j]=0;
                }

        printf("%d\n",sol);

    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}