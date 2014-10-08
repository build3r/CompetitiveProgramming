#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<char, char> mymap;
    string s;
    int i,j,k,n,t,lpos,rpos;
    char x,y;
    cin>>t;
    while(t--)
    {
        mymap.clear();
        s.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            mymap[x]=y;
        }
        cin>>s;
        int len=s.length();
        for(i=0;i<len;i++)
        {
            if(mymap.find(s[i])!=mymap.end())
            {
                s[i]=mymap[s[i]];
            }
        }
        lpos=0;
        rpos=len-1;
        for(i=0;i<len;i++)
        {

            if(s[i]=='0')
                {lpos++;
                    continue;}
            else
                break;

        }
        for(i=len-1;i>=0;i--)
        {
            if(s[i]=='0')
                {rpos--;
                    continue;}
            else if(s[i]=='.')
            {
                rpos--;
                break;
            }
                else
                break;


        }
        for(i=lpos;i<=rpos;i++)
            cout<<s[i];
        cout<<endl;
     /*   if(len==1)
        cout<<s<<endl;
        else
            {
        cout<<"lpos = "<<lpos<<"rpos  = "<<rpos<<endl;
        cout<<s.substr(lpos,rpos)<<endl;
            }*/
    }
return 0;
}
