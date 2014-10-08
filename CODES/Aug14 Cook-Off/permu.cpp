
#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m,i,j,k;
        cin>>n>>m;
        int v[100002];
        for(i=0; i<n; i++)
        {
            cin>>k;
            v[i]=k;
        }
        for(i=0; i<m; i++)
        {
            cin>>j>>k;
            //if(j<=k)
                sort(v+(j-1),v+(k-1));
         for(int j=0; j<n; j++)
            cout<<v[j];
            cout<<endl;
        }

        for(i=0; i<n; i++)
            cout<<v[i];
        int flag=0;
        for(i=0; i<n-1; i++)
        {
            if(v[i]>v[i+1])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
            cout<<"Possible"<<"\n";
        else
            cout<<"Impossible"<<"\n";
    }

    return 0;
}
