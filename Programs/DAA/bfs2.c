#include<stdio.h>
#include<conio.h>
int main()
{
    int q[20],a[20][20],r[20],st=0,ed=0,start,n,i,j;
    printf("\nEnter the value of n ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            r[i]=0;
        }
    }
    printf("\nEnter the start node ");
    scanf("%d",&start);
    q[ed++]=start-1;
    r[start-1]=1;
    printf("\nNodes reachable from the origin(%d) are %d ",start,start);
    while(st!=ed)
    {
        for(i=0;i<n;i++)
        {
            if((r[i]==0)&&a[q[st]][i]==1)
            {
                q[ed++]=i;
                r[i]=1;
                printf("%d ",i+1);
            }
        }
        st++;
    }
    if(ed!=n)
    {
        printf("\nAll nodes are not reachable from origin!!");
    }
    return 0;
}
