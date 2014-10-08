#include<iostream>
using namespace std;
int main()
{
    long long int i,j,k,n,a[100000],mx=0,smx=0,m;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>mx)
            mx=a[i];
    }
    for(j=0;j<k;j++)
    {
        for(i=0;i<n;i++)
        {
            a[i]=mx-a[i];
            if(smx<a[i])
                smx=a[i];
        }
        mx=smx;
        smx=0;

    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
