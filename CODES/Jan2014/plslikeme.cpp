#include<iostream>
using namespace std;
int main()
{
    unsigned long long int l,d,s,c;
    int t;
    cin>>t;
    while(t--)
    { int flag=0;
        cin>>l>>d>>s>>c;
        if(s>=l)
            cout<<"ALIVE AND KICKING\n";
        else
        {
            while(d>1)
            {
                s=s+c*s;
                if(s>=l)
                {
                    cout<<"ALIVE AND KICKING\n";
                    flag=1;
                    break;
                }
                d--;
            }
            if(flag==0)
            {
                cout<<"DEAD AND ROTTING\n";
            }
        }

    }
    return 0;

}
