#include<stdio.h>
int a[10][10]={{0,0,0,0,0}},vis[10],n,s;
void dfs(int );
int main()
{
    int i,j,k;
    printf("No. of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    printf("Enter starting vertex\n");
    scanf("%d",&k);
 //  for(i=1;i<=n;i++)
    {
   // printf("In main\n"
    //if(vis[i]==0)
    dfs(k);
    }
    return 0;
}

void dfs(int k)
{
    int i,j;
    vis[k]=1;
    for(i=1;i<=n;i++)
    {
        if(a[k][i] && !vis[i])

        {
            printf("\n%d -> %d\n",k,i);
            dfs(i);
        }

    }

}
