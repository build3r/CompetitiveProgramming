#include<iostream>
#include<cmath>
using namespace std;
long long int fn(long long int n,long long int k,long long int m)
{
    long long int i,prev=0;
    int flag=0;
   if(k==1)
       return n;
    for(i=1;i<=m;i++)
    {
        if(n%k==0)
        {
            flag++;
            n=n/k;
        }
        else
        {
            if(i<m && flag>1)
                {
                if(i%2==0)
                   return n*k;
                   else
                    return n;
                   }
            n=n*k;
        }
    }
    return n;
}

int main()
{
    long long int n,m,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        cout<<fn(n,k,m)<<endl;
    }
    return 0;
}

