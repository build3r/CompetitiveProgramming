#include<stdio.h>
#include<conio.h>
#include<time.h>
void quick(int a[],int l,int h)
{
    int s;
    if(l<h)
    {
        s=part(a,l,h);
        quick(a,l,s-1);
        quick(a,s+1,h);
    }
}
int part(int a[],int l,int h)
{
    int p=a[l],left=l,right=h,t;
    left++;
    while(left<=right)
    {
        while(a[left]<p)
        left++;
        while(a[right]>p)
        right--;
        if(left<right)
        {
            t=a[left];
            a[left]=a[right];
            a[right]=t;
        }
    }
    a[l]=a[right];
    a[right]=p;
    return right;
}
int main()
{
    int n,i,l,h,a[100];
    time_t(seed);
    printf("enter the array size\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    l=0;
    h=n-1;
    printf("The array\n");
    for(i=0;i<n;i++)
    {
     //   a[i]=rand()%100;
     printf("%d ",a[i]);
    }
    quick(a,l,h);
    printf("sorted..!!\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
