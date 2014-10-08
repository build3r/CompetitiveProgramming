#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> ed[100005],edr[100005];
int dist[100005];
pair<int,int>arr[100007];

#define INF 100005

int min_rev_path(int n)
{
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(1,0));
    dist[1]=0;
    while(!pq.empty())
    {
        pair<int,int> u=pq.top();
        pq.pop();
//if(u.second>=-dist[u.first])
//{
        int x=u.first;//rev=u.second;
        for(int i=0; i<ed[x].size(); i++)
        {
            int next=ed[x][i];
            if(dist[next]>dist[x])
            {
                dist[next]=dist[x];
                pq.push(make_pair(next,-dist[next]));
            }
        }
        for(int i=0; i<edr[x].size(); i++)
        {
            int next=edr[x][i];
            if(dist[next]>dist[x]+1)
            {
                dist[next]=dist[x]+1;
                pq.push(make_pair(next,-dist[next]));
            }
        }
//}
    }
    if(dist[n]==INF)
        return -1;
    return dist[n];
}
int main()
{
    int n,m;
    //freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    //cout<<n<<"  tg  "<<m<<endl
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==1 && b==n)
        {
            printf("0\n");
            return 0;
        }
        if((a-b)!=0)
        {
            arr[i].first=a;
            arr[i].second=b;
        }
    }
    sort(arr,arr+n);
    ed[arr[0].first].push_back(arr[0].second);
    edr[arr[0].second].push_back(arr[0].first);
    for(int i=1; i<m; i++)
    {
        int u=arr[i].first,v=arr[i].second;
        if(u!=arr[i-1].first||v!=arr[i-1].second)
        {
            ed[u].push_back(v);
            edr[v].push_back(u);
        }
    }
    printf("%d\n",min_rev_path(n));

}
