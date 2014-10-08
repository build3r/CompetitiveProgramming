#include<stdio.h>
int a[15];
int main()
{
    int i,j,n,k,w;
    printf("enter no of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w);

        k=j=w%13;

        if(a[j]==0)
        a[j++]=w;
        else
        while(++j!=k)
           {
               if(j>=13)
               j=0;
              //printf("%d   %d   ",j,k);
               if(a[j]==0)
               {
                   a[j]=w;
                   break;
               }

           }
           if(j==k)
           {printf("failed to insert\n");
           return 1;
           }

    }
    printf("The closed hash is\n");
    for(i=0;i<13;i++)
    {
        printf("->%d",a[i]);
    }
    return 0;
}
