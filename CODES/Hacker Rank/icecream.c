#include<stdio.h>
int main()
{
    int t,n,m.i,j,c[10000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",c[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
        {
            if(m==c[i]+c[j])
                printf("%d %d\n",i+1,j+1);
        }
    }
    return 0;
}
