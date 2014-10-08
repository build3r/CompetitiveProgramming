#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *next;
};

struct node *start,*temp,*new,*list;
void ins(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->info=x;
    new->next=list->next;
    list->next=new;
    list=new;
    (start->info)++;
}
void dis()
{
    temp=start->next;
    if(start->next==start)
    {
        printf("List is empty\n");
        return;
    }
    printf("There are %d NODES \n",start->info);
    do
    {
        printf("->%d",temp->info);
        temp=temp->next;
    }while(temp!=start);
}

void del()
{
    if(start->next==start)
    {
        printf("Nothing to delete\n");
        return;
    }
    temp=start->next;
    printf("The element deleted is %d\n",temp->info);
    start->next=temp->next;
    (start->info)--;
    free(temp);
}

int main()
{
   start = (struct node *)malloc(sizeof(struct node));
   start -> info =0;
   start ->next = start;
   list=start;
   int ch=0,a;
  while(ch!=3)
  {
   printf("\nenter your choice :\n");
   printf("1.insert\n2.delete\n3.exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
       printf("enter the element to be inserted :\n");
       scanf("%d",&a);
       ins(a);
       dis();
     break;

     case 2:
       printf("enter the element to be deleted :\n");
       //scanf("%d",&a);
       del();
       dis();
     break;

    case 3:
      printf("Now exiting\n");
      break;

    default :
    printf("wrong choice\n");
   }
 }
 return 0;
}
