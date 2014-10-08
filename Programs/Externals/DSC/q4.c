#include<stdio.h>
#include<stdlib.h>
struct node
{
   int info;
   struct node *prev;
   struct node *next;
};

struct node *start,*temp,*ne,*save;

void create(int x)
{
  ne= (struct node *)malloc(sizeof(struct node));
  ne ->prev = NULL;
  ne ->next = NULL;
  ne ->info = x;
}

void append(int x)
{
  
   create(x);
   if(start == NULL)
      start = ne;
   else
    {
      temp = start;
      while(temp -> next != NULL)
          temp = temp -> next;
          
          
          
      temp -> next = ne;
      ne-> prev = temp;
     }
}


int addafter(int x,int y)
{
   create(y);
   temp = start;

   while(temp -> info != x)
   {
      if(temp  == NULL)
      {
        printf("the specified element doesnot exist\n");
        return -1;
      }
     temp = temp -> next;
   }

   save = temp -> next;
   temp -> next = ne;
   ne -> prev = temp;
   ne -> next = save;
   save -> prev = ne;

   return -1;
} 
       
void display()
{
  temp = start;
  while(temp!= NULL)
  {
    printf("%d - ",temp -> info);
    temp = temp -> next;
   }
 printf("\n");
}



void deleteafter(int x)
{
  temp = start;
   while(temp -> info != x)
   {
     if(temp == NULL)
     {
       printf("the specified element doesnot exist\n");
       return;
     }
     temp = temp -> next;
   }
   temp = temp -> next; // to push temp to the next node after the found node 
   save = temp;
   temp = save -> next;
   ne = save -> prev;
   temp -> prev = ne;
   ne -> next = temp;
   free(save);
}

void delet()
{
   temp = start;
   if(temp == NULL)
      printf("there are no elements to be deleted \n");
   else
   {
     while(temp -> next != NULL)
       temp = temp -> next;

     save = temp -> prev;
     if(save == NULL)
     {
       free(temp);
       start = NULL;
     }
     else
     {
      save -> next = NULL;
      free(temp);
     }
    }
}
   
int main()
{

  int ch,a,x;
  while(ch!=5)
 {
   printf("enter your choice :\n");
   printf(" 1.append \n 2. add after\n 3. delete\n 4. delete after\n 5. exit\n ");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
      printf("enter the element to be appended :\n");
      scanf("%d",&a);
      append(a);
      display();
    break;

    case 2:
      printf("enter the element after which the new element has to be added :\n");
      scanf("%d",&x);
      printf("enter the element to be added :\n");
      scanf("%d",&a);
      addafter(x,a);
      display();
    break;
   
    case 3:
     delet();
     display();
    break;
    
    case 4:
      printf("enter the element to be deleted after :\n");
      scanf("%d",&a);
      deleteafter(a);
      display();
    break;

    case 5:
     printf("Now exiting\n");
     break;

   default :
   printf("wrong choice\n");
  }
 }  
}











  
