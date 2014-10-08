#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char a[1000005],c;
inline void inp(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for (; ((c < 48 or c > 57) and c != '-');) c = getchar_unlocked();
    for (; c > 47 and c < 58; c = getchar_unlocked()) x = (x << 1) + (x << 3) + c - 48;
}
int main()
{
    int n,q,len,i;
    char c;
    string s,temp;
    inp(q);
    while(q--)
    {
        char c = '#';
        while (c != '+' and c != '?') c = getchar_unlocked();
        if(c=='+')
        {
            inp(i);
            scanf("%s", a);
            //scanf("%d",&i);
           // cin>>temp;
            s.insert(i,a);
        }
        else if(c=='?')
        {
            inp(i);
            inp(len);
            //scanf("%d",&i);
           // scanf("%d",&len);
            //cin>>i;
            //cin>>len;
            puts(s.substr(i-1, len).c_str());
            //cout<<s.substr(i-1,len)<<endl;
        }
    }
    return 0;
}

