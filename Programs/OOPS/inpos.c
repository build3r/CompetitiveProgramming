#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node
{
  char data;
  struct node *next;
};
struct node *start=NULL,*temp,*ne;

void push(char c)
{
    ne=(struct node *)malloc(sizeof(struct node));
    ne->data=c;
    ne->next=NULL;
    if(start==NULL)
    start=ne;
    else
    {
        ne->next=start;
        start=ne;
    }
}

char pop()
{
 if(start==NULL)
 {
     printf("NOthing to pop\n");
     return;
 }
    char f;
    f=start->data;
    temp=start;
    start=start->next;
    free(temp);
    return f;
}

int val(char op)
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
}
void dis()
{
    temp=start;
    do
    {
        printf("->%c",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
int prc(char op)
{
    char top=start->data;
    int x,y;
   x=val(op);
   y=val(top);
   return((x<=y)?1:0);
}
int main()
{
    char in[20]={0},pos[20]={0};
    int i=0,j=0,k=0;
    printf("Enter infix string\n");
    scanf("%s",in);
    while(in[i]!=NULL)
    {
        if(isdigit(in[i]))
        {
            //printf("In digit\n");
        pos[j++]=in[i];
        }
        else
        {
            if(start==NULL)
            push(in[i]);
            else
            {
                k=prc(in[i]);
                if(k==1)
                pos[j++]=pop();
                push(in[i]);
            }
            //.push(in[i]);
        }

        i++;
    }
    dis();
    while(start!=NULL)
    {
        pos[j++]=pop();
    }
    pos[j]='\0';
    printf("\nThe postfix string is :\n%s",pos);
    return 0;
}
