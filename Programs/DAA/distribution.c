#include<stdio.h>
int main()
{
int a[10],n,u,l,i,d[10],s[10],j;
printf("enter the size of array\n");
scanf("%d",&n);
printf("enter the elements of array\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter values for l and u\n");
scanf("%d%d",&l,&u);
for(j=0;j<=u-l;j++)
d[j]=0;
for(i=0;i<n;i++)
d[a[i]-l]=d[a[i]-l]+1;
for(j=1;j<=u-l;j++)
d[j]=d[j-1]+d[j];
for(i=n-1;i>=0;i--)
{
j=a[i]-l;
s[d[j]-1]=a[i];
d[j]=d[j]-1;
}
for(i=0;i<n;i++)
printf("%d\t",s[i]);
return 0;
}

