#include<iostream>
#include<algorithm>
using namespace std;
int nc(int ,int );
int fact(int );
int main()
{
    int t,k,m=0,n=0,i,a[11],c=1;
    cin>>t;
    while(t--)
    {
        m=n=0;
        c=1;
        for(i=0;i<11;i++)
        cin>>a[i];
        cin>>k;
        sort(&a[0],&a[10]);
       // for(i=10;i>=0;i--)
       // cout<<a[i]<<endl;
        //cout<<"blah\n";
        for(i=10;i>=0 && k>0;i--)
        {
            if(a[i]!=a[i-1])
            {
                 if(m>0)
              {
                 if(m<k)
                {k-=m;
                m=0;
                }
                else
                {
                    m=m+1;
                    //cout<<m<<"\t"<<k<<endl;
                    c=nc(m,k);
                    m=k=0;
                }
                continue;
               }
            else
                k--;
            }
            else
            m++;
        }
        cout<<c<<endl;

    }
    return 0;
}

int nc(int n,int r)
{
    int k;
    //cout<<"in nc\n";
     k=(fact(n)/(fact(n-r)*fact(r)));
   // cout<<"k="<<k<<endl;
    return k;
}
int fact(int n)
{
   // cout<<"in fact n="<<n<<endl;
    int i=1;
    if(n==0 || n==1)
    return 1;
    while(n)
    {
        i=i*n;
        n--;
    }
    return i;
}
