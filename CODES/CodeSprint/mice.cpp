#include<bits/stdc++.h>
using namespace std;
int tt;
int mice[131075],hole[131075],i,j,ans=0,n,m,pos=0,temp,mx=-1;
int main()
{

    cin>>tt;
    while(tt--)
    {
        ans=0,n,m;
        int prev=INT_MAX;
        pos=0,temp;
        mx=-1;
        cin>>n>>m;
        for(i=1; i<=n; i++)
            cin>>mice[i];
        for(i=1; i<=m; i++)
        cin>>hole[i];
        sort(mice+1,mice+n+1);
        sort(hole+1,hole+m+1);
        for(i=1; i<=n; i++)
        {
            pos=i;
            temp=abs(mice[i]-hole[pos]);
            while(pos<m)
            {
                if(abs(mice[i]-hole[pos+1])>temp) break;
                pos++;
                temp=abs(mice[i]-hole[pos]);
            }
            if(abs(mice[i]-hole[pos])>mx) mx=abs(mice[i]-hole[pos]);
        }
        cout<<mx<<endl;
    }
    return 0;
}
