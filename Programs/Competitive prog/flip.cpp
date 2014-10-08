#include<iostream>
using namespace std;
int main()
{
    unsigned long long int a[100002],u,v,i,j,k,m,n,s;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        cin>>a[i];
        cin>>m;
        for(k=0;k<m;k++)
        {
            s=0;
            cin>>u>>v;
            for(i=u;i<=v;i++)
            {
                for(j=i;j<=v;j++)
                {
                    s+=a[i]*a[j];
                }
            }
            cout<<s<<endl;
        }
    }
    return 0;
}
