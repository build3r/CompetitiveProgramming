#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<stdint.h>
#include<unistd.h>
#include<utility>
#include<fstream>
#include<sstream>
#include<unordered_map>

#include<stack>
#include<cstdio>
#include<ctime>

using namespace std;
#define mod  1000000009ll
#define gc getchar
inline int scan(){bool f=0; register int c = gc();if(c=='-') f=1; int x=0;for(;c<'0'||c>'9';c=gc());for(;c>='0'&&c<='9';c=gc()){x=(x<<1)+(x<<3)+c-'0';}if(f)return -x; return x;}


int dp[1000002];
unordered_map<int,int> freq;
int h[1000001],diff[1000001];

int main()
{
    int t;//=scan();

     //   cout<<"t= "<<t<<endl;
    //t=in.ReadNext();
    scanf("%d",&t);
    while(t--)
    {
        int n;//=scan();
       // cout<<"n= "<<n<<endl;
        scanf("%d",&n);

        int mindiff=9999999;
        int maxdiff=-9999999;
        scanf("%d",h+0);
        for(int i=1; i<n; i++)
        {
            //h[i]=in.ReadNext();
            scanf("%d",h+i);
            diff[i-1]=h[i]-h[i-1];
            //h[i]=scan();
           // cout<<"h[i] = "<<h[i]<<endl;
        }
           mindiff= *min_element(diff,diff+n);
           maxdiff= *max_element(diff,diff+n);
            //out<<"max = "<<maxdiff<<"min = "<<mindiff<<endl;

       /*for(int i=0; i<n-1; i++)
        {
            diff[i]=h[i+1]-h[i];
            if(mindiff>diff[i])
                mindiff=diff[i];
            if(maxdiff<diff[i])
                maxdiff=diff[i];
        }
        cout<<"max = "<<maxdiff<<"min = "<<mindiff<<endl;*/
        int total = maxdiff-mindiff+1;
        freq.clear();
        int addfactor = -mindiff;

        for(int i=0; i<n-1; i++)
            diff[i]+=addfactor;

        dp[0]=1;
        for(int i=1; i<=n-1; i++)
        {
            dp[i] = (2*dp[i-1])%mod;
            bool flag=0;
                if(freq.find(diff[i-1])!=freq.end())
                    flag=1;
            if(flag)
                dp[i]-=dp[freq[diff[i-1]]-1];
            if(dp[i]<0)
                dp[i]+=mod;
            if(flag)
                freq[diff[i-1]]=i;
            else
                freq.insert({diff[i-1],i});
        }

        printf("%d\n",dp[n-1]-1);
    }
    return 0;
}
