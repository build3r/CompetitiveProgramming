#include<iostream>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
  ll c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main()
{
    ll x,y,t,m,n,i,j;
    ll h,k,r,u=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        k= n*m;
        x = n/2 + n%2;
        y = m/2 + m%2;

        h =  x*(m-y) + y*(n-x);
        if(h==0)
        {
            cout<<0<<"/"<<1<<endl;
        }
        else if(n%2==0 || m%2==0)
        {
            cout<<1<<"/"<<2<<endl;
        }
        else
        {

            r=gcd(h,k);
            cout<<h/r<<"/"<<k/r<<endl;

        }
    }
    return 0;
}
