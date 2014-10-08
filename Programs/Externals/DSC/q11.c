#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *next;
};

struct node *start,*temp,*new,*save;

void insert(int x)
{
   new = (struct node *)malloc(sizeof(struct node));
   new -> info = x;
   
 temp = start -> next;
   while(temp -> next != start)
      temp = temp -> next;
   temp -> next = new;
   new -> next = start;
   (start -> info)++;
}

int delete(int x)
{
  temp = start -> next;
   save = start;
   while(temp ->info != x)
   {
    if(temp -> next == start)
    {
      printf("invalid element \n");
      return;
     }
    save = temp;
    temp = temp -> next;
   }
  save -> next = temp -> next;
  free(temp);
  (start -> info)--;
  return;
}

void display()
{
   temp = start -> next;
    while(temp -> next != start)
    {
      printf("%d - ",temp -> info);
      temp = temp -> next;
     }
     printf("%d \n",temp -> info);
     printf("number of nodes : %d\n",start -> info);
}

void main()
{
   start = (struct node *)malloc(sizeof(struct node));
   start -> info =0;
   start ->next = start;
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
       printf("enter the element to be deleted :\n");
       scanf("%d",&a);
       delete(a);
       display();
     break;

    case 3:
      exit(0);
    
    default :
    printf("wrong choice\n");
   }
 }
}
