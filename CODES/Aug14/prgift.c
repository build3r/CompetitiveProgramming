#include<stdio.h>
#include<string.h>
int main()
{
    int a[102], count[102],t,k,n,i;
    scanf("%d",&t);
    while(t--)
    {
        memset(count,0,sizeof(count));
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            count[a[i]]=1;
        }
        for(i=2;i<n;i+=2)
        {
            if(count[i])
            k--;
        }
        if(k<=0)
        {
            printf("YES\n");
        }
        else
        printf("NO\n");
    }
return 0;
}
