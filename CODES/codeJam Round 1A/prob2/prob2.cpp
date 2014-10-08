#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
short tr[1000][1000];
int main()
{
    int n,t,i,j,k,flag;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
        cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        flag=0;
        memset(tr,0,sizeof(tr));
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>j>>k;
            tr[j][k]=1;
        }
        for(i=0;i<1000;i++)
        {
            flag=0;
            for(j=0;j<1000;j++)
            {
                if(tr[i][j])
                    flag++;
            }
        }
    }
    return 0;
}

