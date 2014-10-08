#include<stdio.h>
#include<stdlib.h>

int strl(char *s)
{
   int i = 0;
   while(*(s + i++)!='\0');
   return i;
}

int strc(char *s ,char *t)
{
   int i=0;
   while(s[i] != '\0')
   {
     if(t[i] != s[i])
     return (s[i]-t[i]);
     i++;
   }
   return 0;
}

 int main()
{
   char substr[10],str[20];
   int i,j,len,lens,flg;
   printf("enter a string :\n");
   scanf("%s",str);
   printf("enter the substring :\n");
   scanf("%s",substr);

   len = strl(str);

   for(i = 0; i < len; i++)
   {
     if(str[i] == substr[0])
     {
      if(strc(substr,&str[i])== 0)
      {
        printf("the substring exists \n");
        exit(0);
      }
    }
   }
   printf("the substring doesnot exist\n");
 }

