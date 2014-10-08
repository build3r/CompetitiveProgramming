#include <stdio.h>
#include <stdlib.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
    visited[v]=1;
    //q[++r]=v;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&&!visited[i])
        q[++r]=i;
    }
    if(f<=r)
    bfs(q[++f]);
}
/*void bfs(int v)
{
    visited[v]=1;
    for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i])
            q[++r]=i;
    if(f<=r)
        bfs(q[f++]);
}*/
int main()
{
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    printf("\n Enter graph data in matrix form:\n");
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    bfs(v);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
        {
            printf("\n Graph is not connected");
            return 0;
        }
    printf("\n Graph is connected");
    return 0;
}
