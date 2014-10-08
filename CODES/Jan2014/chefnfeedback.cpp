#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        if((s.find("010")<100000) || (s.find("101")<100000))
           cout<<"Good\n";
           else
            cout<<"Bad\n";
    }
    return 0;
}
