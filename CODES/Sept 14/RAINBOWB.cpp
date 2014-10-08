#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long Pow(long long a, long long x, long long p)
{
    long long res = 1;
    while(x > 0)
    {
        if( x % 2 != 0)
        {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long long Inverse(long long a, long long p)
{
    return Pow(a, p-2, p);
}
long long Binomial(long long n, long long k, long long p)
{
    long long numerator = 1;
    for (int i=0; i<k; i++)
    {
        numerator = (numerator * (n-i) ) % p;
    }
    long long denominator = 1;
    for (int i=1; i<=k; i++)
    {
        denominator = (denominator * i) % p;
    }
    return ( numerator*Inverse(denominator,p) ) % p;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long ans=0;
    for(int i=1; i<=(n-12); i++)
    {
        if((n-i)%2==0)
        {
            int mad=(n-i)/2-1;
            ans+=Binomial(mad,5,mod)%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
