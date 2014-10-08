#include<stdio.h>
int main()
{
    long long int n,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0ll;
        while(n>1)
        {
            if((n&1))
            {
                ans=ans+1ll;
            }
            //ans+=n/2ll;
            n=n>>1;
            ans=ans+n;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
