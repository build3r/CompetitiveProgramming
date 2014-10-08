
    #include<iostream>
    #include<cstring>
    #include<cstdio>

    typedef long long int lol;
    typedef unsigned long long int ull;

    using namespace std;

    int gcd(int x,int y)
    {
    if(y==0) return x;
    return gcd(y,x%y);
    }

    int a[2004][2004];

    int main()
    {
        cout<<"sdf"<<endl;
    int n;
    cin>>n;
    int deg[2005]={0};
    char str[2009][2009];
    for(int i=0;i<n;i++)
    {
    cin>>str[i];
    for(int j=0;j<n;j++)
    {
    if(str[i][j]=='1') deg[i]++;
    }
    }
    //for(int i=0;i<n;i++) cout<<deg[i]<<" ";
    // cout<<"\n";
    lol ans=0;
    for(int i=0;i<n;i++)
    {
    lol s=0;
    for(int j=0;j<n;j++)
    {
    if(str[i][j]=='1') s+=deg[j];
    }
    ans=ans+s-deg[i];
    }
    cout<<ans<<"\n";

    return 0;
    }
