#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#define pb push_back
using namespace std;
vector<int>::iterator it;
stack<int> st;
int n,m,i,j,x,y,v;
vector<int> graph[1001],graphrev[1001];
int adj[2001][2001];
int visited[2001];
int c=0;
void dfs(vector<int> graph[],int v)
{

    visited[v]=1;

    for(it=graph[v].begin(); it!=graph[v].end(); it++)
    {
        if(!visited[*it])
            dfs(graph,*it);
    }
}
void toposort(vector<int> graph[],int v)
{
    c++;

    visited[v]=1;
    for(it=graph[v].begin(); it!=graph[v].end(); it++)
    {
        if(!visited[*it])
            toposort(graph,*it);
    }
    st.push(v);
}
int main()
{

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {

        for(j=0; j<n; j++)
            scanf("%d",&adj[i][j]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {

            if(adj[i][j]==1)
            {
                graph[i].pb(j);
                graphrev[j].pb(i);
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(!visited[i])
            toposort(graph,i);
    }

    for(i=0; i<=n; i++)
        visited[i]=0;
    long long ans=0;
    while(!st.empty())
    {
        v=st.top();
        st.pop();
        if(visited[v])
            continue;
        dfs(graphrev,v);
        ans+=c*(c-1)/2;
        c=0;
    }
    printf("%lld\n",ans);
    return 0;
}
