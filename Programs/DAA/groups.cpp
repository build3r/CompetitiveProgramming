#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n,j,k,t,i,l=0,m=0;
    int s[2005]={0},z[2005];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>z[i];
    for(i=0;i<n;i++)
    {
        s[z[i]]=1;
        for(k=0;k<2004;k++)
        if((s[k]!=s[k+1])&&s[k]==1)
        l++;
        cout<<l<<endl;
        l=0;
    }
    return 0;
}
