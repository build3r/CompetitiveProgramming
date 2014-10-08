#include<stdio.h>
int main()
{
    unsigned long long a;
    int k;
    scanf("%llu",&a);
    k=a%6llu;
    if(k==0 || k==1 || k==3)
        printf("yes");
    else
        printf("no");
    return 0;

}
