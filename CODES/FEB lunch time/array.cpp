#include<iostream>
#include<cmath>
using namespace std;
 long long int mod_pow(long long int num, long long int pow, long long int mod)
{
    long long int test;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = (test * num) % mod;
        num = (num * num) % mod;
    }

    return test;

}
int main()
{
    short int t;
    long long int a[100001],i,j,n;
    cin>>t;
    while(t--)
    {
        j=1;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int max=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]==max)
            {
                j++;
            }
            if(a[i]>max)
            {
                max=a[i];
                j=1;
            }
        }
        if(j<30)
            cout<<pow(2,j)-1<<endl;
else
        cout<<mod_pow(2,j,1000000007)-1<<endl;

    }
    return 0;
}
