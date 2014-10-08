#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int t,h[250]={0};
    bool flag;
    long int i,j;
    string p,s;
    cin>>t;
    while(t--)
    {
        for(i=97;i<123;i++)
            h[i]=0;
        flag=1;
        cin>>p;
        cin>>s;
        j=s.length();
        for(i=0;i<j;i++)
        {
            h[s[i]]++;
        }
        j=p.length();
        for(i=0;i<j;i++)
        {
            if(h[p[i]])
            {
                h[p[i]]--;
            }
            else
            {
                cout<<"NO\n";
                flag=0;
                break;
            }

        }
        if(flag)
         cout<<"YES\n";
    }
    return 0;
}
