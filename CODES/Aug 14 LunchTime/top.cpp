#include<iostream>
using namespace std;
class EmoticonsDiv2
{
    public: int printSmiles (int n)
    {
        int ans=0;
        if(n&1)
        return n;
        else
        {
            if((n&(n-1))==0)
            {
                while(n=n>>1)
                ans++;
                return ans*2;
            }
            else
            {
                int i=1,temp=0,ans=999999999,ct=0;
                while(i<n)
                {

                    if(n%i==0)
                        {

                            temp = ct * 2 + ((n-(i))/( i )) ;
                        }
                    cout<<"temp "<<temp<<endl;
                    if(temp<ans)
                    {
                        ans = temp;
                    }
                    ct++;
                    i=i<<1;
                }
                return ans;
            }
        }
    }
};
int main()
{
    EmoticonsDiv2 test;
    int n,t=10;
    while(t--)
    {
        cin>>n;
        cout<<test.printSmiles(n)<<endl;

    }
    return 0;
}
