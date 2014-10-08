#include<iostream>
#include<cstring>
using namespace std;
ostream & login(ostream &shabaz)
{
    //shabaz<<"checking    \a";
    shabaz<<"enter password\n";
    return shabaz;
}
char pwd[50];
istream &operator>>(istream &in,char pwd[50])
{
    cout<<"inoverloaded fn\n";
cin>>pwd;
return in;
    //strcpy(pass,pwd);
}

int main()
{
    int i=0;
    do
    {
        if(i!=0)
        cout<<"beep....!!!\n";
        i++;
        cout<<login;
        cin>>pwd;
    }while(strcmp(pwd,"tesla"));
    cout<<"logon sucessfull\n";
    return 0;
}
