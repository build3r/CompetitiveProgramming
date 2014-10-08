
#include<iostream>
using namespace std;
int main()
{
    int test;
    int n,i,j,k,a[1001],m;
    cin>>test;
    while(test--)
    {
        cin>>n;
        if(n<4)
        cout<<n<<endl;
        else
        {
            i=0;
            while(n>3)
            {
                m=n%4;
                a[i]=m;
                n=n/4;
                i++;
            }
              cout<<n;
        for(k=i-1;k>=0;k--)
        cout<<a[k];
        cout<<endl;
        }


    }
    return 0;
}
