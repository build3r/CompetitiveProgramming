#include<stdio.h>
#include<conio.h>
int main()
{
    int a[20],s[20],d[20],n,l,u,i,j;
    printf("Enter the number of elements in an array: \n");
    scanf("%d",&n);
    printf("Enter the elements of an array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the value of l and u:\n");
    scanf("%d %d",&l,&u);
    for(j=0;j<=(u-l);j++)
    {
        d[j]=0;
    }
    for(i=0;i<n;i++)
    {
        d[a[i]-l]+=1;
    }
    for(j=1;j<=(u-l);j++)
    {
        d[j]+=d[j-1];
    }
    for(i=(n-1);i>=0;i--)
    {
        j=a[i]-l;
        s[d[j]-1]=a[i];
        d[j]-=1;
    }
    printf("Sorted list is as follows:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",s[i]);
    }
    return 0;
}