
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
   int n,p,j,i,l[100],a[100];
   printf("Enter the value of n:\n");
   scanf("%d",&n);
for(i=2;i<=n;i++)
a[i]=i;
for(p=2;p*p<=n;p++)
{
    if(a[p]!=0)
    {
        j=p*p;
        while(j<=n)
        {
            a[j]=0;
            j=j+p;
        }
    }
}
i=0;
for(p=2;p<=n;p++)
{
    if(a[p]!=0)
    {
        l[i++]=a[p];
        printf("%d\n",l[i-1]);
    }
}
return 0;
}
