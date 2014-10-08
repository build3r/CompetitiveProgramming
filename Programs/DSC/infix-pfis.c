#include<stdio.h>
#include<conio.h>
typedef struct
{
    char c[40];
    int top;
}opst;
opst op;
int prcd(char sym)
{
    int i=0,k;
    k=op.top;
    printf("Inoperand stack   top=%d\n",op.top);
    while(k!=-1)
    {
        printf("->%c\n",op.c[k]);
        k--;
    }
    printf("Smbol=%c\n",sym);

    switch(op.c[op.top])
          {
              case '+':
              case '-':{
                        switch(sym)
                        {
                            case '+':
                        case '-':
                        case ')':
                                i=1;
                               break;
                        case '*':
                        case '/':
                        case  '(':
                        case '$':i=0;
                        break;
                        }
                       }break;
                       printf("......................................................................\n");
            case '*':
            case '/':
            {
                switch(sym)
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case ')':
                    i=1;
                    break;
                    case '$':
                    case '(':i=0;
                    break;
                    }break;
            }
            case '$':
            {
                switch(sym)
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case ')':
                    case '$':i=1;
                             break;
                case '(':i=0;
                          break;
                }break;
            }
            case ')':i=1;
            break;
            case '(':i=0;
            printf("......................................................................\n");
            break;
        }
return i;
}

void push(char sym)
{
    op.c[++op.top]=sym;
}
char pop()
{
    int k;
    if(op.top==-1)
    {
        printf("stack empty");
    }
    else
    {
    k=op.c[op.top];
    op.top=op.top-1;
    return k;
    }
}
int main()
{
    int i=0,j=0;
    op.top=-1;
    char s[50],post[50];
    scanf("%s",s);
    while(s[i]!='\0')
    {
        if(isdigit(s[i]))
        {
           // printf("inside if\n" );
        post[j++]=s[i];
        }
        else
        {
            //printf("inside else\n");
            if(op.top==-1)
            {
                push(s[i]);
            }
            else
            {
                int k=prcd(s[i]);
                printf("preced returned %d\n",k);
                if(k)
                {
                    printf("inside preced\n");
                char c=pop();
                printf("pop reatuerned %c\n",c);
                post[j++]=c;
                }

                push(s[i]);
            }

            }
            i++;

        }
    //printf("inside operand stack\n");
   // i=op.top;
    //while(i--!=-1)
   // {
   //     printf("%c\n",op.c[i]);

   // }
      while(op.top!=-1)
            {
                post[j++]=pop();

            }
    printf("infix:%s \npostfix=%s\n",s,post);
return 0;
}

