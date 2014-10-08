#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[10],i,j,n,t;
    printf("enter size of array: \n");
    scanf("%d",&n);
    printf("enter element in array: \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}
