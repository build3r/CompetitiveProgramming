#include<stdio.h>
int a[10][10]={{0,0,0,0,0},{0,0,0,1,0},{0,0,0,1,0},{0,1,1,0,1},{0,0,0,1,0}},q[10],vis[10],n,f=0,r=-1;
void bfs(int );
int main()
{
    int i,j,k;
    printf("No. of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    //for(i=1;i<=n;i++)
    //for(j=1;j<=n;j++)
   //scanf("%d",&a[i][j]);
    printf("Enter starting vertex\n");
    scanf("%d",&k);
     for(i=1;i<=n;i++)
    {
        if(!vis[i])
    bfs(i);
    }
    return 0;
}

void bfs(int k)
{
    int i=1,j,h;
    vis[k]=1;
    q[++r]=k;
    while(f!=r)
          {
              while(i++<=n)
          {
              if(a[k][i] && !vis[i])
          {   vis[i]=1;
              q[++r]=i;
          }
          }
          j=f;
          while(j++!=r)
          {
          printf("\n%d-> %d \n",q[++f]);
          }
          }
}
