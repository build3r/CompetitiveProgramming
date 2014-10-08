#include <stdio.h>
#define mod 10000007
int fib(long long int n)
{
    unsigned long long int i,j=1,k=5,l=1;
    if(n==2)
        return k;
    for(i=1;i<n-1;i++)
    {
        l=2*j+k;
        j=k%mod;
        k=l%mod;
    }
    return l;
}


int main()
{
  int n,t;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%lld",&n);
  printf("%d\n", fib(n));
  }
  return 0;
}
