// ChingYunH Ching Yun Hsu
// Fascinating case study on an early Rank 37 Round from her.

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
struct box
{
  int t,p,s,num;
}task[100000];
priority_queue<box> pq; long long int Time[100000],r[100000]; int n;
bool operator >(const box & a,const box & b)
{
  return a.p > b.p;
}
bool operator <(const box & a,const box & b)
{
  return a.p < b.p;
}
int cmp(const void *p,const void *q)
{
  if((*(struct box*)p).t != (*(struct box*)q).t)
    return (*(struct box*)p).t - (*(struct box*)q).t;
  return (*(struct box*)q).p - (*(struct box*)p).p;
}
int comp(const void *p,const void *q)
{
  return (*(int*)p) - (*(int*)q);
}
void work()
{
  long long int tm=0; int i=1;
  while(pq.size() || i<n)
    {
      while(task[i].t <= tm && i<=n)
	{
	  pq.push(task[i]); i++;
	}
      if(pq.size() == 0 && i<=n)
	{
	  tm = task[i].t;
	  continue;
	}
      box u = pq.top(); pq.pop();
      if(i<=n && tm+u.s > task[i].t)
	{
	  u.s -= task[i].t-tm;
	  tm = task[i].t; pq.push(u); pq.push(task[i]); 
	  i++;
	}
      else
	{
	  tm = u.s+tm;
	  Time[u.num] = tm;
	}
    }
}
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i,left,right,mid,x,xx; long long int T;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      cin>>task[i].t>>task[i].s>>task[i].p; task[i].num = i;
      if(task[i].p == -1) x = i;
      else r[i] = task[i].p;
    }
  cin>>T; r[x] = 0;
  qsort(r+1,n,sizeof(r[0]),comp);
  qsort(task+1,n,sizeof(task[0]),cmp);
  for(xx=1;xx<=n;xx++) if(task[xx].num == x) break;
  left = 1; right = n;
  while(right >= left)
    {
      mid = (left+right)>>1;
      while(r[mid+1] == r[mid]+1) mid++;
      task[xx].p = r[mid]+1;
      work();
      if(Time[x] == T)
	{
	  cout<<task[xx].p<<'\n';
	  for(i=1;i<=n;i++)
	    cout<<Time[i]<<' ';
	  break;
	}
      else if(Time[x] < T) right = mid-1;
      else left = mid+1;
    }
}
