#include<iostream>
#include<cstdio>
using namespace std;
int a[100002],r,m,i,j,k,n,te,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&l,&r);
            for(j=l;j<=r;j++)
            {
                for(k=j;k<=r;k++)
                {
                    if(a[k]==j)         //if number in trhe range swap
                    {
                        te=a[k];
                        a[k]=j;
                        a[j]=te;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]!=i)
            {
                printf("Impossible\n");
                break;
            }
        }
        if(i>n)
        {
            printf("possible\n");
        }
    }
    return 0;
}
