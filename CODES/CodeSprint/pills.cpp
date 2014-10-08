#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
    if(n<k)
        return 0;
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
    int t,arr[100000],i;
    long long int n,sum,m,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        sum = 0ll;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum>m)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            ans = Binomial(m-n,n,mod)%mod;
            cout<<ans<<endl;
            for(i=0;i<n;i++)
            {
                ans += Binomial(m-sum,arr[i],mod)%mod;
                ans = ans%mod;
                cout<<ans<<endl;
            }
        }
        cout<<ans%mod<<endl;

    }
}
