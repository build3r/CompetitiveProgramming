#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size],front = -1,rear = -1;

void insert(int x)
{

  rear = (++rear)%(size);
   if(front == -1)
    {
      q[rear] = x;
      front = 0;
    }
  else if( rear  == front )
    {
     printf("queue overflow\n");
     exit(0);
    }
    else
    {
     q[rear] = x;
    }
}

void delete()
{
  if(rear == front)
  {
    printf("queue underflow\n");
    exit(0);
  }
  else
   front++;
}

void display()
{
  int i=front;
  while(i != rear)
  {
    printf("%d ",q[i]);
    i = (++i)%(size);
  }

  printf("%d\n",q[i]);
}

void main()
{
  insert(1);
  display();
  insert(2);
  display();
  insert(3);
  display();
  insert(4);
  display();
  insert(5);
  display();
  delete();
  display();
  insert(6);
  delete();
  display();
  insert(7);
  display();
}

