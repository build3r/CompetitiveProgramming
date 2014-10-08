#include<stdio.h>
#include<stdlib.h>
#define size 3

int q[size],front = -1,rear = -1;

void insert(int x)
{
   if(front == -1)
     front = rear =0;
   if( rear == size )
     printf("queue overflow\n");
   else
     q[rear++] = x;
}

int qdelete()
{
    int i,max,pos = 0;

    if(rear == front)
     {
      printf("queue underflow \n");
      return -1;
      }
    else
    {
      for(i = 0; i < size; i++)
      {
        if(q[pos]<q[i])
          pos = i;
      }
     max = q[pos];
      for(i = pos; i < (size - 1); i++)
         q[i]=q[i+1];
         q[i]=-999;
         rear--;
    return max;
   }
}

void display()
{
  int i;
   for(i = front ;i < rear; i++)
   {
     if(q[i] == -999)
       break;
     else
      printf("%d - ",q[i]);
   }
   printf("\n");
}

void main()
{
   int ch,a,i;
   for(i = 0; i < size; i++)
      q[i]=-999;
   while(1)
  {
   printf("enter your choice  :\n");
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
       a = qdelete();
       if(a != -1)
         printf("deleted element :%d\n",a);
       display();
     break;

     case 3:
       exit(0);

     default :
      printf("wrong choice\n");

    }
  }
}



