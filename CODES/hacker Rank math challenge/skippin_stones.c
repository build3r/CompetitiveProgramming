#include<stdio.h>
#include<math.h>
int root(long long int n)
{
    double t,e=0.0,frac;
    t=sqrt(1+8*n);
    frac = t - ((long)t);
    printf("%lf\n",t);
    if((frac-e)==0)
    {
        t=t-1;
            return t/2;
    }
    else
        return 0;

}
int main()
{
    int t;
    long long int n,ans,i,te;
    scanf("%d",&t);
    while(t--)
    {
        int f=1;
        scanf("%lld",&n);
        f=root(n);
        if(f==0)
        {
            printf("Better Luck Next Time\n");
        }
        else
        {
            printf("Go On Bob %d\n",f);
        }


    }
    return 0;
}
