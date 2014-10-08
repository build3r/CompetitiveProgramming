#include<stdio.h>
#include<string.h>
int main()
{
char s[50],temp[50];
int i=0,j=0;
gets(s);
i=strlen(s);
while(i--)
temp[j++]=s[i];
temp[j]='\0';
printf("The rev is: %s",temp);
return 0;
}