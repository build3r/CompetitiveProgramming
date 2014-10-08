#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,a[1000],b[1000],i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n-1;i++)
        {
            b[i]=a[i+1]-a[i];
        }
        sort(b,b+n-1);
        if(b[n-2]<=0)
        {
            cout<<"UNFIT\n";
        }
        else
        cout<<b[n-2]<<endl;
    }
    return 0;
}
