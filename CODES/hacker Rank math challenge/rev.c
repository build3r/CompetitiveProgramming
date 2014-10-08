#include<stdio.h>
int main()
{
    int n,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        //n=n-1;]
        /*if(k==(n/2))
        {
            if(n&1)
                printf("%d\n",n);
            else
            {
                printf("%d\n",n-1);
            }
        }

       else */if(k<(n/2))
        {
            printf("%d\n",(((k+1)*2))-1);
        }
        else
        {
            printf("%d\n",((n-k)*2)-1 -1);
        }
    }
    return 0;
}
