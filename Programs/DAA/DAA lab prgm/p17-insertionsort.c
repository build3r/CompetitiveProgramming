#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,v,a[20];
    printf("enter the number of element:\n");
    scanf("%d",&n);
    printf("enter element in array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && v<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
    printf("sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}