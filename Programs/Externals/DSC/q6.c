#include<stdio.h>
#include<string.h>
#include<ctype.h>

int alnum(char c)// doesnot exist in GNU library
{
   if(isalpha(c))
   return(1);
   else if(((int)c-48>=0)&&(((int)c-48)<=9))
   return(1);
   else
   return(0);
}

int value(char op)
{
   switch(op)
   {
     case '+':
     case '-':
     return 1;

     case '*':
     case '/':
     return 2;

     case '$':
     return 3;
   }
  return 0;
}

int precedence(char op ,char ops)
{
   int x,y;
   x=value(op);
   y=value(ops);
   return((x<=y)?1:0);
}

int main()
{
   char e[30],oprstk[10],ans[30];
   int top=-1,i,ct=0;
   printf("enter a expression :");
   scanf("%s",e);
   for(i=0;i<strlen(e);i++)
   {
    if(alnum(e[i]))
      ans[ct++]=e[i];
    else if(top==-1)
      oprstk[++top]=e[i];
    /*else if(e[i]=='(')
      oprstk[++top]=e[i];
    else if(e[i]==')')
      {
        while(oprstk[top]!='(')
         ans[ct++]=oprstk[top--];
         top--;//remove the bracket from oprstk
       }*/
    else
      {
        while(1)
        {
        if(precedence(e[i],oprstk[top]))//presidence lower than stack persidence
          ans[ct++]=oprstk[top--];
         else
        {
          oprstk[++top]=e[i];
          break;
        }
        }
      }
    }
   while(top>-1)
    ans[ct++]=oprstk[top--];
   ans[ct]='\0';
   printf("%s",ans);
   return 0;
}




