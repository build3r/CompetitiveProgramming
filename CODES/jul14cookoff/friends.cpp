#include <cstdio>
#include <iostream>
using namespace std;

int graph[2001][2001];
int state[2001];


void dfs(int v,int n)
{
    int i;
    state[v]=1;
    for(i=1; i<=n; i++)
        if(graph[v][i] && !state[i])
        {

            state[i]=1;
            dfs(i,n);
        }
}
    int i,j,k,n;
    long long int ct;
    char arr[2005];
int main(void)
{

    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%s",arr);
        for(j=0; j<n; j++)
        {

            if(arr[j]=='1')
                graph[i][j+1]=1;
        }
    }

    ct =0;
    for(i=1; i<n; i++)
    {
        dfs(i,n);
        for(j=i+1; j<=n; j++)
        {
            if(graph[i][j]==0 && state[j]==1)
            {

                ct+=2;

            }
        }
        for(k=0; k<=n; k++)
            state[k]=0;
    }
    printf("%lld\n",ct);
    return 0;
}
