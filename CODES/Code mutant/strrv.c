#include<stdio.h>
int main()
{
    char s[1001];
    int i,j,k,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=m-1;j>=0;j--)
                printf("%c",s[i][j]);
                printf("\n");
        }

    }
    return 0;
}
