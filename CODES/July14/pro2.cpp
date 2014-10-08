#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i,t,j,x,y;
    cin>>t;
    while(t--)
    {
        long long int c=0ll;
        cin>>x>>y;
        x=abs(x);
        y=abs(y);
        if(x==0 && y==0)
            c=0ll;
        else if(y==0)
        {
            if(x==1)
                c=3ll;

            else
            {
                c=(x-x/2ll)*3;
                c+=x/2ll;
            }
        }
        else if(x==0)
        {
              if(y==1)
                c=1ll;

            else
            {
                c=(y/2ll)*3;
                c+=y-y/2ll;
            }
        }
        else if(abs(x)==abs(y)){
            c=2ll*x;

        }
        else
        {
            if(x>y)
            {
                c=y*2ll;
                int k=x-y;
                c+=(k-k/2)*3ll;
                c+=k/2;


            }
                        else
            {
                c=abs(x)*2ll;

                int k=y-x;
                c+=(k-k/2);
                c+=(k/2)*3ll;

            }
        }
        cout<<c<<endl;
    }
    return 0;
}
