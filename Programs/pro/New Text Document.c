#include<stdio.h>
int main()
{
    char *str;
    int len=0,i=0;
    gets(str);
    while(str[i])
    {len++;
    i++;
    }
    for(i=len-1;i>=0;i--)
    printf("%c",str[i]);
    return 0;
}
