    #include<bits/stdc++.h>
    #include<stdlib.h>
    #include<cstdio>
    using namespace std;
    #define clr(x) x.clear()
    #define For(i,a,b) for(i=a;i<b;i++)
    #define loop(i,b) for(i=0;i<b;i++)
    #define Loop(i,b) for(i=1;i<=b;i++)
    #ifndef ONLINE_JUDGE
    #define gc getchar
    #else
    #define gc getchar_unlocked
    #endif
    const int MOD=1e9+7;
    typedef pair<int,int> PII;
    typedef vector<PII> VPII;
    typedef vector<int> VI;
    typedef long long LL;
    LL expo(LL a, LL b){
    if (b==1)
    return a;
    if (b==2)
    return (a*a)%MOD;

    if (b%2==0){
    return expo(expo(a,b/2)%MOD,2)%MOD;
    }
    else{
    return a*expo(expo(a,(b-1)/2)%MOD,2)%MOD;
    }
    }
    int main()
    {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    scanf("%d",&n);
    int a[n+1][2];
    memset(a,-1,sizeof a);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i][0]);

    set< LL> ss;
    for(int i=1;i<=n;i++)
    {

    if(a[i][1]==-1)
    {
    int p=i;
    long long c=0;
    while(a[i][0]!=a[p][1])
    {
    a[p][1]=a[i][0];
    p=a[p][0];
    c++;
    }
    ss.insert(c);
    }
    }
    LL res=1;
    vector<int> factor[100000];
    {

    for(set<LL>::iterator i=ss.begin();(i)!=ss.end();i++)
    {
    int k=*i;
    for(int l=2;k!=1;l++)
    {
    int g=0;
    if(k%l==0)
    {
    while(k%l==0)
    {
    k=k/l;
    g++;
    }
    if(factor[l].size()==0)
    factor[l].push_back(g);
    else
    {
    if(factor[l][0]<g)
    factor[l][0]=g;
    }

    }

    }
    }
    }

    for(LL i=2;i<100000;i++)
    {
    if(factor[i].size()>0)
    res*=expo(i,factor[i][0])%MOD;
    }
    printf("%lld\n",res);
    ss.clear();

    }
    return 0;
    }
