#include<stdio.h>
#include<string.h>
#define MAX 100005
const long long int mod=1000000007;
//long long  int A2[1000000]
long long int gcd( long long int a, long long int b)
{
    while( b != 0)
    {
        long long int  t = b;
        b= a %t;
        a = t;
    }
    return a;
}
long long int lcm( long long int a,  long long int b)
{
    return (a/gcd(a,b))%mod*(b%mod);
}
/*long int lcms(long int  l , long int * A2)
{
   long  int     i;
    long int result;
    result = 1;
    for (i = 0; i < l; i++)
        result = lcm(result, A2[i])%1000000007;
    return result;
}*/

int n;
long long int a[MAX],num1[MAX],A2[MAX],hash[MAX],vis[100005],g=0,k;
long long int i,pos,temp1,pos1,temp,m=1,c;
long long int count=0;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        g=count=0;
        memset(hash,0,sizeof(hash));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        A2[i]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            //num1[i]=a[i];
            A2[i]=1;
            //hash[i]=0;
        }
        for(i=1; i<=n; i++)
        {
            c=1;
            if(!vis[i])
            {
                k=a[i];
                vis[k]=1;
                while(i!=k)
                {
                    vis[k]=1;
                    k=a[k];
                    c++;
                }
            }

            /*for(i=1; i<=n; i++)
            {

                if((num1[i])!=-1)
                {
                    count++;
                    pos1=i;
                    temp1=num1[pos1];
                    while(1)
                    {
                        pos1=temp1;
                        if(pos1==i)
                        {
                            num1[pos1];
                            break;
                        }
                        temp1=num1[pos1];
                        num1[pos1]=-1;
                        m++;
                    }

                }*/
                if(hash[c]<1)
                {
                    A2[g]=c;
                    hash[c]++;
                    if(g==0)
                        k=A2[0];
                    if(k>1)
                        k=lcm(k,A2[g])%mod;
                    g++;
                }
                // A2[i]=m;
                c=1;

            }
            //            for(i=0;i<g;i++)
            //	printf("%d ",A2[i]);
            //  long int k;
            //  k=lcms(g,A2)%1000000007;
            printf("%lld\n",k);
        }


        return 0;
    }
