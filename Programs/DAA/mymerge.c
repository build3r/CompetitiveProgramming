#include<stdio.h>
#include<conio.h>
int mergesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
    return 0;
}
int merge(int a[],int low,int mid,int high)
{
    int t[100],i=low,m=mid+1,l=low,h=high,k;
    while((l<=mid) && (m<=high))
    {
        if(a[l]<a[m])
        {
            t[i]=a[l];
            l++;
        }
        else
        {
            t[i]=a[m];
            m++;
        }
        i++;
    }
    if(l>mid)
    {
        for(k=m;k<=high;k++)
        {
            t[i++]=a[k];
        }
    }
    else
    {
        for(k=l;k<=mid;k++)
        {
            t[i++]=a[k];
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=t[k];
    }
    return 0;
}
int main()
{
    int n,i,a[100];
    printf("enter the array size\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    printf("The elements\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nsorted..!!\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
return 0;
}
