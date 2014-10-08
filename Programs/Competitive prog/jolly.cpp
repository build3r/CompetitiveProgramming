#include<iostream>
using namespace std;
int main()
{
    long int a[3000];
    int n,i,k,f[3000];
    while(cin>>n)
    {
        //cout<<"n="<<n<<endl;
        for(i=1;i<n+1;i++)
        {
            cin>>a[i];
            f[i]=0;
        }
        if(n==1)
        {cout<<"Jolly\n";
        continue;}
        for(i=1;i<n;i++)
        {
            k=(a[i])-(a[i+1]);
             if(k<0)
            k=k*-1;
            if(k==0)
            {cout<<"Not jolly\n";
            break;}
            f[k]=1;
        }

        for(i=1;i<n;i++)
        {
            if(f[i]==0)
            {cout<<"Not jolly\n";
            break;}
        }
        if(i==n)
        cout<<"Jolly\n";
    }
    return 0;
}
