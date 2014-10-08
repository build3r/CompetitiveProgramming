#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *next;
};

struct node *front , *rear , *save, *temp, *new;

void insert(int x)
{
   new = (struct node *)malloc(sizeof(struct node));
   new -> next = NULL;
   new -> info = x;

   if(front == NULL)
     front = rear = new;
   else
   {
     rear -> next = new;
     rear = rear -> next;
   }
}

void delete()
{
  if(front == NULL)
    printf("queue underflow \n");
  else
  {
     save = front;
     front = front -> next;
     free(save);
  }
}

void display()
{
   temp = front;
   if(front == NULL)
     printf("the queue is empty\n");
   else
   {
     while(temp != NULL)
     {
       printf("%d ",temp -> info);
       temp = temp -> next;
     }
     printf("\n");
   }
}


void main()
{
   front = rear = NULL;
   int ch,a;
  while(1)
  {
   printf("enter your choice :\n");
   printf("1.insert\n2.delete\n3.exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
       printf("enter the element to be inserted :\n");
       scanf("%d",&a);
       insert(a);
       display();
     break;

     case 2:
       delete();
       display();
     break;

    case 3:
      exit(0);

    default :
    printf("wrong choice\n");
   }
 }
}
