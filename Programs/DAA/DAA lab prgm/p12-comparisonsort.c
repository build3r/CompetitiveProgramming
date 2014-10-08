#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,a[10],count[10],s[10];
    printf("enter the number of element:\n");
    scanf("%d",&n);
    printf("enter element in array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                count[i]++;
            else
                count[j]++;
        }
    }
    for(i=0;i<n;i++)
        s[count[i]]=a[i];
    printf("sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",s[i]);
    return 0;
}
