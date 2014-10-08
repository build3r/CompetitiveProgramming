#include<iostream>
using namespace std;
int main()
{
    long long int i,j,t,ac=0,rc=0,gcd;
    unsigned long long int n,s,rf,ms,mrf;
    cin>>t;
    while(t--)
    {
        rc=0;
        gcd=1;
        cin>>n>>ms>>mrf;
        for(i=0;i<n;i++)
        {
            cin>>s>>rf;
            if(s>ms || rf>mrf)
                rc++;
        }
        cin>>ac;
         { for(int j=1;j<=ac && j<=rc;j++){

if(ac%j==0 && rc%j == 0 ){

                     gcd=j;
   }
    }
    cout<<rc/gcd<<"/"<<ac/gcd<<endl;
    }
    }
    return 0;
}

