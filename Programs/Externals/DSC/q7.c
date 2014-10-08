#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
int powr(int a,int b)
{
  int i,p = 1;
  for(i = 0; i < b; i++ )
     p *= a;
   return p;
}

int digit(char c)
{
  int x= (int)(c-48);
  return((x >= 0)&&(x <= 9))? 1:0;
}
int solv(int a,int b,char c)
{
  switch(c)
  {
    case '+':
    return (a+b);
    case '-':
    return(a-b);
    case '*':
    return(a*b);
    case '/':
    return(a/b);
    case '$':
    return (pow(a,b));
  }
  return 0;
}

void main()
{
  int a,b,opndstk[20],top=-1,i;
  char e[30];
  printf("enter an expression :\n");
  scanf("%s",e);
   for(i = 0;i < strlen(e) ; i++)
   {
     if(digit(e[i]))
        opndstk[++top] = (int)(e[i]-48);
     else
     {
       b = opndstk[top--];
       a = opndstk[top];
       opndstk[top] = solv(a,b,e[i]);
     }
   }
  printf("answer : %d\n",opndstk[top]);
}



