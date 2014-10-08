#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    char p[20],t[20];
    int i,j,n,m;
    printf("enter string: ");
    scanf("%s",t);
    n=strlen(t);
    printf("enter substring: ");
    scanf("%s",p);
    m=strlen(p);
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m && p[j]==t[i+j])
            j++;
        if(j==m)
        {
            printf("substring found at location %d",i+1);
            return 0;
        }
    }
    printf("substring not found\n");
    return 0;
}
