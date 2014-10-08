#include <stdio.h>
#include<math.h>
#include <stdlib.h>
int main()
{
    int a[20],l[20],i,j,k,n;
    printf("enter the value of n: ");
    scanf("%d",&n);
    k=sqrt(n);
    for(i=2;i<=n;i++)
        a[i]=i;
    for(i=2;i<=k;i++)
    {
        if(a[i]!=0)
        {
            j=i*i;
            while(j<=n)
            {
                a[j]=0;
                j=j+i;
            }
        }
    }
    k=0;
    for(i=2;i<=n;i++)
    {
        if(a[i]!=0)
        {
            l[k]=a[i];
            k++;
        }
    }
    printf("prime no. are:  ");
    for(i=0;i<k;i++)
        printf("%d   ",l[i]);
    printf("\n");
    return 0;
}
