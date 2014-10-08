#include<stdio.h>
#include<string.h>
int main()
{
    int t,h[150],c,i;
    char a[10002],b[10002];
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%s",a);
        scanf("%s",b);
        memset(h,0,sizeof(h));
        for(i=0;a[i];i++)
        {
            h[a[i]]++;
        }
        for(i=0;b[i];i++)
        {
            if(h[b[i]]!=0)
                {h[b[i]]--;
                    c++;
                }
        }
        printf("%d\n",c);
    }
    return 0;
}
