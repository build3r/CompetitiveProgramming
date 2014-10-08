#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,i,j,ans=0;
    char s[120];
    int gem[150];
    bool saw[150];
    memset(gem,0,sizeof(gem));
    scanf("%d",&n);
    j=n;
    while(n--)
    {
        memset(saw,0,sizeof(saw));
        scanf("%s",s);
        for(i=0;s[i];i++)
        {
            if(!saw[s[i]])
            {
                gem[s[i]]+=1;
                saw[s[i]]=1;
            }
        }
    }
    for(i='a';i<='z';i++)
    {

        if(gem[i]==j)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
