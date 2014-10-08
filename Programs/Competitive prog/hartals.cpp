#include<iostream>
using namespace std;
short int f[3651]={0};
int main()
{
    short int h[100];
    int t,i,n,c,p,k,j=0,m=0;
    cin>>t;
    while(t--)
    {
        c=0;
        j=0;
        m=0;
        cin>>n;
        cin>>p;
        for(i=1;i<=p;i++)
        cin>>h[i];
        for(i=1;i<=n;i++)
        {
            j++;
            if(j==7)
            {
                m++;
                j=0;
            }
            if(((i-m)%6==0) || (i%7==0))
            {
                 //cout<<"i="<<i<<endl;
            }

            else
            for(k=1;k<=p;k++)
            {
                if(i%h[k]==0)
                {  // cout<<"i= "<<i<< "h[k]="<<" "<<h[k]<<endl;
                    f[i]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            //cout<<f[i]<<"  ";
            if(f[i]==1)
            c++;
            f[i]=0;
        }
        cout<<c<<endl;
    }
}
