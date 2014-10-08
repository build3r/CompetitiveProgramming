#include<iostream>
using namespace std;
int main()
{
    int t;
    long long int j,i,a[100003],b[100003],n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=2;i<100003;i++)
        {a[i]=i;
         b[i]=0;
        }
        for(i=2;(i*i)<=100003;i++)
        {
            if(a[i]!=0)
            j=i*i;
            while(j<=100003)
            {
                a[j]=0;
                j=j+i;
            }
        }
        j=0;
        for(i=2;i<=100003;i++)
        {
            if(a[i]!=0)
            {
                b[j++]=a[i];
            }
        }
        for(i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<endl;
    }
}
