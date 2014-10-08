#include<stdio.h>
#define max 20


typedef struct
{
int it[max];
int t1,t2;
}stack;

void dis(stack s);
int empty(stack s,int st);
void push(stack *s,int st);
int pop(stack *s,int st);

int main()
{
stack s;
s.t1=-1;
s.t2=max;
int opt,st=0;
while(opt!=4)
{
printf("enter the stack u want\n");
scanf("%d",&st);
printf("enter 1=pop\n2=push\n3=dis[lay\n4=exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:if(empty(s,st))
       printf("************the stack is empty************\n");
       else
       printf("the item %d is popped\n",pop(&s,st));
	break;
case 2:push(&s,st);
	break;
case 3:dis(s);
	break;
case 4:break;
}
}
return 0;
}



int empty(stack s,int st)
{
if((st==1 && s.t1==-1)||(st==2 && s.t2==max))
return 1;
else
return 0;
}

int pop(stack *s,int st)
{
int i=0;
if(st==1)
{
 i=s->it[s->t1];
(s->t1)--;
}
else
{
i=s->it[(s->t2)++];
}
return i;
}

void push(stack *s,int st)
{
int x;
if(((s->t2)-(s->t1))==1)
{
printf("******************stack over flow**********************\n");
}
else
{
printf("enter the item\n");
scanf("%d",&x);
if(st==1)
{
s->it[++(s->t1)]=x;
}
else
s->it[--(s->t2)]=x;
}
}

void dis(stack s)
{
int i;
printf("the elments in stack 1 are\n");
for(i=s.t1;i>=0;i--)
printf("%d\n",s.it[i]);
printf("the elements in stack 2 are\n");
for(i=(s.t2);i<max;i++)
printf("%d\n",s.it[i]);
}



