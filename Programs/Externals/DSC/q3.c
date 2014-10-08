#include<stdio.h>
#include<stdlib.h>
#undef new

struct node
{
  int data;
  struct node *next;
};

struct node *start, *new, *t;

void append(int x);
int length(struct node *p);

void main()
{
   start = NULL;
   append(1);
   append(2);
   append(3);
   printf("lenght of the linklist :%d",length(start));
}

void append(int x)
{
   new =(struct node*)malloc(sizeof(struct node));
   new ->next = NULL;
   new ->data = x;
   if(start == NULL)
      start = new;
   else
   {
     t =start;
     while(t->next !=NULL)
          t = t->next;
     t->next = new;
   }
}

int length(struct node *p)
{
  static int len = 0;
  if(p==NULL)
    return(len);
  else
  {
    length(p->next);
    len++;
   }
}


