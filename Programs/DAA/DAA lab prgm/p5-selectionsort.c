#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[10],i,j,min,n,t;
    printf("enter size of array: \n");
    scanf("%d",&n);
    printf("enter element in array: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }
    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}
