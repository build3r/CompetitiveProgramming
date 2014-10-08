#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,sum,n;

    string s;
    char skip;
    cin>>t;
    while(t--)
    {
        cin>>s;
        map<char,int> mp;
        sum =0;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            mp[s[i]]++;
            sum  += s[i]- 97 + 1;
        }
        //cout<<"sum  "<<sum<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>skip;
           // cout<<"skip  "<<skip<<" mp "<<mp[skip]<<endl;
            sum -= (skip - 97 +1)*mp[skip];
            mp[skip] = 0;
        }
        cout<<sum<<endl;
    }
    return 0;
}
