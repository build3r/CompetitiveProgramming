#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top, *ne, *save;

void push(int x)
{
  ne= (struct node*)malloc(sizeof(struct node));
  ne-> next = NULL;
  ne ->data=x;

  if(top == NULL)
  top = ne;
  else
  {
     save = top;
     top = ne;
     top ->next =save;
   }
}

void pop()
{
   if(top == NULL)
   printf("stack underflow\n");
   else
   {
     save = top;
     top = top ->next;
     free(save);
    }
}

void display()
{
   save = top;
   if(save == NULL)
     printf("stack is empty\n");
   else
  {
    while(save != NULL)
    {
     printf("%d ",save -> data);
     save = save -> next;
     }
     printf("\n");
  }
}

int main()
{
   int ch,a;
   top = NULL;
  while(ch!=3)
  {
   printf("enter your choice :\n");
   printf("1.push\n2.pop\n3.exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
       printf("enter the element to be pushed :\n");
       scanf("%d",&a);
       push(a);
       display();
     break;

     case 2:
       pop();
       display();
     break;

    case 3:
      break;

    default :
    printf("wrong choice\n");
   }
 }
 return 0;
}
