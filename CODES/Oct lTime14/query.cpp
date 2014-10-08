#include<bits/stdc++.h>
using namespace std;
int n,tt,i,l,ch,r,p,d,m;
int a[100000];
int main()
{
   // ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>m;
    while(m--)
    {
        cin>>ch;
        if(ch==1)
        {
            cin>>l>>r>>p;
            for(int i=l-1;i<=r-1;i++)
            {
                if(a[i]%p==0)
                    a[i]/=p;
            }
        }
        else if(ch==2)
        {
            cin>>l>>d;
            a[l-1]=d;
        }
    }
    for(i=0;i<n-1;i++)
    cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
 return 0;
}
