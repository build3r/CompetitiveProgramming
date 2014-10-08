#include<stdio.h>
int main()
{

    long long int n,i,mi=99999999999999999;

    scanf("%lld",&n);
    long int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]<mi)
            mi=a[i];
    }
    i=mi;
    if(i%2==0)
        i-=1;
    for(;i>0;i-=2)
    {
        if(mi%i==0)
        {
            printf("%ll5d\n",i);
            return 0;
        }
    }
}
