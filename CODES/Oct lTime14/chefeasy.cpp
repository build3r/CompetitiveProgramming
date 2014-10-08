#include<bits/stdc++.h>
using namespace std;
int n,tt,i;
long long mx=0ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>tt;
    while(tt--)
    {
        mx=0ll;
        cin>>n;
        int a[n+2];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n, std::greater <int>() );
        for(i=0;i<n;i+=2)
        {
            //cout<<"i = "<<i<<" a[i] = "<<a[i]<<endl;
            mx+=a[i];
        }
        cout<<mx<<endl;
    }

    return 0;
}
