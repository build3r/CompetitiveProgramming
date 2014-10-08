#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,flag;
    int h[150];
    char s[100001];
  scanf("%s",s);
    {
        flag=0;
        memset(h,0,sizeof(h));
        j=strlen(s);
        for(i=0;i<j;i++)
        {
            h[s[i]]++;
        }
        for(i=50;i<150;i++)
        {
            if(h[i]%2!=0)
            {
              flag++;
            }
        }
        if(flag>1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
