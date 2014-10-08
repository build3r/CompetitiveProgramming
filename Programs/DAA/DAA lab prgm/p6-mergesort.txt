#include <stdio.h>
#include <stdlib.h>
#define max 20
void mergesort(int arr[],int low,int mid,int high);
void partition(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        partition(arr,l,mid);
        partition(arr,mid+1,h);
        mergesort(arr,l,mid,h);
    }
}
void mergesort(int arr[],int low,int mid,int high)
{
    int i,m,k,l,temp[max];
    l=low;
    i=low;
    m=mid+1;
    while(l<=mid && m<=high)
    {
        if(arr[l]<=arr[m])
        {
            temp[i]=arr[l];
            l++;
        }
        else
        {
            temp[i]=arr[m];
            m++;
        }
        i++;
    }
    if(l>mid)
    {
        while(m<=high)
        {
            temp[i]=arr[m];
            i++;m++;
        }
    }
    else
    {
        while(l<=mid)
        {
            temp[i]=arr[l];
            i++;l++;
        }
    }
    for(k=low;k<=high;k++)
        arr[k]=temp[k];
}
int main()
{
    int arr[10],i,n;
    printf("enter size of array: \n");
    scanf("%d",&n);
    printf("enter element in array: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    partition(arr,0,n-1);
    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}
