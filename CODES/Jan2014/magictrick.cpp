#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    unsigned long long int l[1000],temp,c,a,b;
    int t,n,j,i;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>l[i];
            cin>>a>>b>>c;
        cin>>s;
            for(i=0;i<s.length();i++)
            {
                if(s[i]=='R')
                    for(int k=0,j=i+1;j<=n/2;j++,k++)
                {
                    temp=l[j];
                    l[j]=l[n-k];
                    l[n-k]=temp;
                }
                else if(s[i]=='A')
                {
                    for(j=i+1;j<=n;j++)
                        l[j]=l[j]+a;
                }
                else if(s[i]=='M')
                {
                    for(j=i+1;j<=n;j++)
                        l[j]=((l[j]%c)*(b%c))%c;
                }
                     for(j=1;j<=n;j++)
                                {
                                    l[j]=l[j]%c;
                                }
            }
            for(i=1;i<=n;i++)
            {
                cout<<l[i]%c<<" ";
            }
            cout<<endl;

    }
}
