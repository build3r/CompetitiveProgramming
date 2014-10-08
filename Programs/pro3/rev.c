#include<stdio.h>
int main()
{
    char str[50];
    int len=0,i;
    gets(str);
    while(str)
    len++;
    for(i=len-1;i>=0;i--)
    printf("%c",str[i]);
    return 0;
}
