#include<stdio.h>
int a[5][10][10];
int main()
{
    int i,j,k,n,min;
    printf("No. of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[0][i][j]);
    for(k=1;k<=n;k++)
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   { min=999;
       if((a[k-1][i][j])<(a[k-1][i][k]+a[k-1][k][j]))
       min=a[k-1][i][j];
       else
       min=a[k-1][i][k]+a[k-1][k][j];
   a[k][i][j]=min;
   }

   printf("The final matrix is\n");
   for(i=1;i<=n;i++)
   {    printf("\n");
       for(j=1;j<=n;j++)
       printf("%d\t",a[n][i][j]);
   }
   return 0;
}
