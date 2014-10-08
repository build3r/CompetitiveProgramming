#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
    char s[100];
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(isalpha(s[i]))
           {if(isupper(s[i]))
            cout<<(char)tolower(s[i]);
            else
                cout<<(char)toupper(s[i]);
           }
           else
            cout<<s[i];

    }
    cout<<endl;

}
