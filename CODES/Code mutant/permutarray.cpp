#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,a[1000],b[1000],i,j,k;
    short int t,flag;
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b, b+n, std::greater<int>());
        for(i=0;i<n;i++)
        {
            if(a[i]+b[i]<k)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
