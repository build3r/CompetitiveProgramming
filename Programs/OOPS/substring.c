#include<stdio.h>
int slen(char *s)
{
    int i=0;
    while(s[i])
    {
        i++;
    }
    return i;
}

int strc(char *s ,char *t)
{
   int i=0;
   while(s[i] != '\0')
   {
     if(t[i] != s[i])
     {
     return 1;
     }
     i++;
   }
   return 0;
}

int main()
{
    char s[20],sub[20];
    int i=0;
    printf("Enter string\n");
    gets(s);
    printf("Enter substring\n");
    gets(sub);
    while(s[i]!='\0')
    {
        if(strc(sub,&s[i])== 0)
      {
        printf("the substring exists \n");
        return 0;
      }
        i++;
    }
    printf("Substring not found\n");
    return 0;
}
