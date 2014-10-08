#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,k,a[20][20],n;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
            }
        }
    }
    printf("Floyd's shortest path is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
