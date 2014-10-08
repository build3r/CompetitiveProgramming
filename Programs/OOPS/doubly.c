#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *n;
    struct node *p;
};
struct node *start=NULL,*last=NULL,*ne,*temp;

void app(int x)
{
    ne=(struct node *)malloc(sizeof(struct node));
    ne->info=x;
    ne->n=NULL;
    ne->p=NULL;
    if(start==NULL)
    start=last=ne;
    else
    {
        last->n=ne;
        ne->p=last;
        last=ne;
    }
}
void del()
{
    if(last==NULL)
    {
        printf("No Nodes Exist\n");
        return;
    }
    if(last->p==NULL)
    {
        temp=last;
        start=last=NULL;
        free(temp);
    }
    else
    {
    temp=last;
    last->p->n=NULL;
    last=last->p;
    free(temp);
    }
}

void dis()
{
    temp=start;
    if(start==NULL)
    {
        printf("Empty list\n");
        return;
    }
    do
    {
        printf("->%d",temp->info);
        temp=temp->n;
    }while(temp!=NULL);
}
int main()
{

  int ch=0,a,x;
  while(ch!=3)
 {
   printf("\nenter your choice :\n");
   printf(" 1.append \n 2. delete\n 3. exit\n ");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
      printf("enter the element to be appended :\n");
      scanf("%d",&a);
      app(a);
      dis();
    break;

    case 2:
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
}
