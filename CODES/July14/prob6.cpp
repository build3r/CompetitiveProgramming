#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<cstdio>
#include<algorithm>



using namespace std;
typedef int ll;
    int t,n,m,p[1001],x[1001][1001],y[1001],i,v[1001],k,j;
int main()
{
    cin>>t;
    while(t--)
    {
        int found=0;
        int count=0;
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            cin>>p[i];
        }

        if(m==1 || m==2)
        {
            printf("No Solution");
            if(t!=0) printf("\n");
            continue;
        }

        for(i=0; i<n; i++)
        {
            y[p[i]]=i;
            v[i]=0;
        }

        for(i=0; i<n; i++)
        {
            if(v[i]==0)
            {
                int l=count;
                int it=i;
                int q=0;
                while(v[it]==0)
                {
                    q++;
                    v[it]=1;
                    it=y[it];
                }
                if(q==1 || q==2)
                {
                    found=1;
                    break;
                }
                vector<int> temp(q,q+1);
                temp[q-1]=1;
                it=i;
                for(j=0; j<q; j++)
                {
                    x[it][0]=l+1;
                    for(k=1; k<m; k++)
                    {
                        x[it][k]=x[it][k-1]+temp[(j+k-1)%q];
                    }
                    it=y[it];
                    l++;
                }
                count+=q*m;
            }
        }
        if(found==1)
        {
            printf("No Solution");
            if(t!=0) printf("\n");;
            continue;
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                printf("%d",x[i][j]);
                if(j!=m-1) printf(" ");
            }
            if(t!=0 || i!=n-1)printf("\n");;
        }
    }
    return 0;
}
