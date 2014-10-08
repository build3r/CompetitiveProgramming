#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
 unsigned int v[300005];
int main()
{
    unsigned int n,i,j,mx,temp;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%u",&v[i]);
    }
    sort(v,v+n);
    mx=0;
        for(i=0;i<n-1;i++)
        {

                temp=v[i]&v[i+1];
                if(mx<temp)
                mx=temp;
        }
        printf("%u\n",mx);
    return 0;
}
