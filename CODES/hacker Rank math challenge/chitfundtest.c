#include<stdio.h>
int main()
{
    int cs=0,i;
    double ans=0.0;
    for( i=1;i<=25;i++)
    {
        cs+=4000;
        ans+=cs*0.03;
        printf("cs = %d  interest=%lf\n",cs,ans);

    }
    printf("cs = %d  interest=%lf\n",cs,ans);
}
