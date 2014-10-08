#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int pr[]={2,3,5,7};
map<int,int> mp;
long long binomialCoeff(long long int n, long long int k)
{
   long long int res = 1ll;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (long long int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int main()
{
    int t,n,tmp;
    long long int ans=0ll,t2,cnt=0;
    int f[]={0,0,0,0};

        ans=0ll;
        for(int j=0;j<4;j++)
            mp[j]=0;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            sort(a,a+n-1);
int i;
for(int k=0;k<4;k++){
        cnt=0ll;
        for( i=1;i<n;i++)
        {
            if(a[i-1]<a[i])
            {

        for(int j=0;j<4;j++)
            f[j]=0;
            t2=a[i-1];
            while(t2>0)
            {
                tmp=t2%10ll; if(tmp==pr[k])
                        {
                            if(!f[k])
                            {   f[k]=1;
                                cnt++;
                            }
                        }

                t2/=10ll;
            }
        }
        }
                        for(int j=0;j<4;j++)
            f[j]=0;
            t2=a[i-1];
            while(t2>0)
            {
                tmp=t2%10ll; if(tmp==pr[k])
                        {
                            if(!f[k])
                            {   f[k]=1;
                                cnt++;
                            }
                        }

                t2/=10ll;
            }

                    if(cnt <3ll) ;
            else
            {
                ans+=binomialCoeff(cnt,3ll);
            }

}



        cout<<ans<<endl;

    return 0;
}
