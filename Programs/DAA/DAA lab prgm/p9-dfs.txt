#include <stdio.h>
#include <stdlib.h>
int a[20][20],visited[20],n;
void dfs(int v)
{
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i])
        {
            printf("\n %d->%d",v,i);
            dfs(i);
        }
}
int main()
{
    int i,j,v,count=0;
    printf("\n Enter number of vertices: ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    dfs(v);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
        {
            printf("\n Graph is not connected");
            return 0;
        }
    printf("\n Graph is connected");
    return 0;
}
