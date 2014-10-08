#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int> mp;
    int j=2;
    int l=3;
    for(int i='a';i<='z';i++)
    {
        for(int k=0;k<l;k++)
        {
            if(j>4)
            if(j%2==0)
                l=4;
            else
                l=3;
            mp[i] = j;
            i++;
            if(i>'z')
                break;
        }
        i--;
        j++;

    }
    mp['s']=7;
    mp['y']=9;
    mp['z']=9;
    for(int i='a';i<='z';i++)
       printf("%c  %d\n",i,mp[i]);
    int t,i;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        int len = s.length();
        for(i=0;i<len;i++)
        {
            cout<<mp[s[i]];
        }
        cout<<endl;
    }
    return 0;
}
