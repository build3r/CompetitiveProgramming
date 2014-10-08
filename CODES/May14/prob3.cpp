#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t,i,len,ope=0,cn=0;
    string s;
    cin>>t;
    while(t--)
    {
        ope=cn=0;
        cin>>s;
        len=s.length();
        for(i=0;i<len;i++)
        {
            if(ope==0 && s[i]=='>')
            {
                break;
            }
            if(s[i]=='<')
                ope++;
            if(s[i]=='>')
            {
                ope--;
                cn++;
            }
        }
        if(ope==0)
        cout<<cn*2<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
