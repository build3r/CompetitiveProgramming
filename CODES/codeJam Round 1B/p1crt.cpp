#include <cstdio>
#include<cmath>


long long int gcd(long long int m,long long int n)
{
long long int r;
while(1)
{
r = m % n;
if(r == 0)
break;
m = n;
n = r;
}


return n;
}

int rec(long long int a,long long int q)
{
if(((float)a/q)>=1/2.0)
return 1;
else
{
return 1+rec(2*a,q);
}
}


int isPowerOfTwo(long long int n)
{if (n == 0)
return 0;
while (n != 1)
{
if (n%2 != 0)
return 0;
n = n/2;
}
return 1;
}

int main(void) {
int count,i,ans;
long long int a, q,z;
char dummy;
	    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
scanf("%d",&count);
for(i=1;i<=count;i++)
{
scanf("%lld%c%lld",&a,&dummy,&q);
z=gcd(a,q);
a=a/z;
q=q/z;
if(isPowerOfTwo(q))
{
// power= log10(q)/log10(2);
// printf("%d\n",power);
// if(((float)a/q)>1/2.0)
// {
// printf("Case #%d: %d\n",i,power);
// }
// else
// printf("Case #%d: %d\n",i,power+1);
ans=rec(a,q);
printf("Case #%d: %d\n",i,ans);

}
else
printf("Case #%d: impossible\n",i);	}
return 0;
}
