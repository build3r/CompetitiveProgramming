#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007LL
#define ll unsigned long long
int distinct[105];
map<int,int> mp;
int main()
{
    int n,i,j,k,l,t,m,p,a[11][101];
    vector<int>shirt[11];
    unsigned long long dp[11][101][101],ans;
    char s[11][1001];
    scanf("%d",&t);
    while(t--)
    {

        memset(distinct,0,sizeof(distinct));
        scanf("%d",&n);
            for(i=0; i<=11; i++)
                shirt[i].clear();
        cin.ignore();
        for(i=0; i<=10; i++)
            for(j=0; j<=100; j++)
                for(k=0; k<=100; k++)
                {
                    dp[i][j][k]=0LL;
                }
        for(i=0; i<=10; i++)
            for(j=0; j<=100; j++)
                a[i][j]=0;
        for(i=0; i<n; i++)
        {
            gets(s[i]);
            l=strlen(s[i]);
            for(j=0; j<l; j++)
            {
                p=0;
                for(; j<l; j++)
                {
                    if(s[i][j]==' ')
                        break;
                    p=(p*10)+(s[i][j]-48);
                }
                distinct[p]=1;
                shirt[i].push_back(p);
            }
        }
        int dist=0;
        for(i=1;i<101;i++)
        {
            if(distinct[i]==1)
                dist++;
        }
        if(dist<n)
        {
            cout<<0<<endl;
            continue;
        }

        if(n==1)
        {
            printf("%d\n",(int)shirt[0].size());
            shirt[0].clear();
            continue;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<shirt[i].size(); j++)
                a[i][shirt[i][j]]=1;
        }


        {
            dp[0][0][0]=(ll)shirt[0].size();
            for(i=1; i<=100; i++)
                dp[0][i][0]=dp[0][0][0];
            for(i=0; i<shirt[0].size(); i++)
                dp[0][shirt[0][i]][0]--;
            for(i=0; i<=100; i++)
            {
                for(j=1; j<=100; j++)
                    if(j!=i)
                        if(a[0][j]==1)
                            dp[0][i][j]=1;
            }
            for(i=1; i<n-1; i++)
            {
                ans=0LL;
                for(j=0; j<shirt[i].size(); j++)
                {
                    ans=(ans+dp[i-1][shirt[i][j]][0])%mod;
                    dp[i][0][shirt[i][j]]+=dp[i-1][shirt[i][j]][0];
                    for(k=1; k<=100; k++)
                        dp[i][0][k]+=dp[i-1][shirt[i][j]][k];
                }
                dp[i][0][0]=ans;

                for(j=1; j<=100; j++)
                {
                    ans=0LL;
                    for(k=0; k<shirt[i].size(); k++)
                    {
                        if(shirt[i][k]!=j)
                        {
                            ans=(ans+dp[i-1][shirt[i][k]][0]-dp[i-1][shirt[i][k]][j])%mod;
                            dp[i][j][shirt[i][k]]+=(dp[i-1][shirt[i][k]][0]-dp[i-1][shirt[i][k]][j]);
                            for(p=1; p<=100; p++)
                                if(p!=shirt[i][k]&&p!=j)
                                {
                                    dp[i][j][p]+=dp[i-1][shirt[i][k]][p];
                                    dp[i][j][p]-=(dp[i-1][0][p]-dp[i-1][j][p]);
                                }
                        }
                    }
                    for(p=1; p<=100; p++)
                        if(p!=j)
                            dp[i][j][p]+=(dp[i-1][0][p]-dp[i-1][j][p]);
                    dp[i][j][0]=ans;
                }
            }
            ans=0LL;
            for(i=0; i<shirt[n-1].size(); i++)
                ans=(ans+dp[n-2][shirt[n-1][i]][0])%mod;

            printf("%lld\n",ans%mod);
        }
    }
    return 0;
}
