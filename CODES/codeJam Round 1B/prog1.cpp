    #include<bits/stdc++.h>
    #include<iostream>
    #define s(n) scanf("%d",&n)
    #define sl(n) scanf("%lld",&n)
    #define p(n) printf("%d\n",n)
    #define mod 1000000007
    #define ll long long
    using namespace std;
    ll gcd(ll a,ll b)
    {
    if(a%b==0)
    return b;
    else
    return gcd(b,a%b);
    }
    int main()
    {
    char str[101][101];
    int fre1[101][27];
    int t,k,i,f,j,len,ans;
    char ch;
    int p,q,tmp,tmp1;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>t;

    for(k=1;k<=t;++k)
    {
    ans=0;

    int n;
    int a[11];
    int f1=1;

    cin>>n;
    memset(fre1,0,sizeof(fre1));
    for(i=1;i<=n;++i)
    a[i]=i;
    for(i=1;i<=n;++i)
    {
    cin>>str[i];
    }
    cout<<"working1"<<endl;
    for(i=1;i<=n;++i)
    {
    for(j=0;j<strlen(str[i]);++j)
    {
    tmp=(int)str[i][j]-96;
    if(fre1[i][tmp]==0)
    fre1[i][tmp]++;
    else{
    if(str[i][j]!=str[i][j-1])
    {
    f1=0;
    break;
    }
    }
    }
    }
    int fre[27];


    cout<<"Case #"<<k<<": ";

    if(f1==1)
    {
int yut=0;
    do
    {

        cout<<"whil"<<yut++<<endl;

    memset(fre,0,sizeof(fre));
    int f=1;
    for(j=1;j<=26;++j)
    {

    fre[j]=fre1[a[1]][j];
    }
    for(i=2;i<=n;++i)
    {
    int ct=0;
    for(j=1;j<=26;++j)
    {
    if(fre1[a[i]][j]==1 && fre[j]==1)
    {

    ct++;
    }

    }
    if(ct>=2)
    {

    f=0;
    break;
    }
    else if(ct==1)
    {

    if(str[a[i]][0]!=str[a[i-1]][strlen(str[a[i-1]])-1])
    {


    f=0;
    break;
    }
    }
    for(j=1;j<=26;++j)
    {
    if(fre1[a[i]][j]==1)
    {
    fre[j]=1;
    }
    }

    }
    if(f)
    {

    ans++;
    }
    }while(next_permutation(a+1,a+n+1));
    }
    cout<<ans<<endl;





    }
    return 0;
    }
