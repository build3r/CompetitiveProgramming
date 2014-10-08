#include<stdio.h>
typedef struct
{
    int item[20],f,r;
}queue;
queue q1;
void insert(int x);
int rem(void);
int empty();
void display();
int main()
{
    q1.f=0;q1.r=1;
    int x,c=0;
    while(c!=4)
    {
    printf("\nenter choice 1.insert   2.rem 3.dis 4.exit");
    scanf("%d",&c);
    switch(c)
    {
        case 1: printf("\nenter element to insert\n");
                scanf("%d",&x);
                insert(x);
                break;

        case 2:x=empty();
               if(x==1)
               printf("queue is empty\n");
               else printf("the element removed is:%d",rem());
               break;
       case 3:display();
       break;
       default:printf("Wrong Choice\n");
           }
    }
    return 0;
}

int empty()
{
    if(q1.r-q1.f==1)
    return 1;
    else
    return 0;
}

int rem()
{

    int it;
    if(q1.f==20)
    q1.f=0;
    it=q1.item[q1.f];
    q1.f++;
    return it;
}


void insert(int x)
{
    if(q1.r==q1.f)
    printf("\nQue is full\n");
    else
    {
      q1.item[q1.r-1]=x;
      q1.r++;
    }
    if(q1.r==20)
    q1.r=0;
}
void display()
{
    int i=q1.f;
    while(i!=q1.r-1)
    {
        printf("\n%d",q1.item[i]);
        i++;
        if(i==20)
        i=0;
    }
    printf("queue end\n");
}
