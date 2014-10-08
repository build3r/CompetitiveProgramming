#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *np;

np list=NULL;
np getnode()
{
    np p;
   p=(np)malloc(sizeof(struct node));
   return p;
}
int i=0,flag=0;
void ins(np p,int x)
{
    np q;

    q=getnode();
    q->info=x;
    if(i==1)
    {
     q->next=q;
     if(flag!=1)
     {list=q;
     }
     flag=0;
     printf("inside if\n");
    }
else
 {
     printf("in else\n");
  q->next=p->next;
   p->next=q;
   if(flag!=1)
     {list=q;
     }
     flag=0;
 }
}

void del(np p)
{
    np q;
    q=p->next;
    printf("the delete node's info is %d\n",q->info);
    p->next=q->next;
    free(q);
}

np fin(int x,np list)
{
    np q=list;
    q=q->next;
    do
    {
        if(q->info==x)
        {
            flag=1;
        return q;
        }
        q=q->next;
    }while(q!=list);
    return NULL;

}

void dis(np list)
{
    np p=list;
    do
    {   p=p->next;
        printf("\n->%d\n",p->info);
    }while(p!=list);
}


int main()
{
    np p=NULL;
    int c=0,x;
    while(c!=6)
    {
        printf("\n1.insert end\t2.delf\t3.ins after\t4.del after\t5.display\t6.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter ele to insert\n");
                   scanf("%d",&x);
                   i++;
                   ins(list,x);
                   break;
            case 2:del(list);
                   break;
            case 3:printf("enter ele to ins after\n");
                   scanf("%d",&x);
                   p=fin(x,list);
                   if(p==NULL)
                   printf("No node found\n");
                   else
                   {
                       printf("enter data of new node\n");
                       scanf("%d",&x);
                       ins(p,x);
                   }
                   break;
           case 4:printf("enter ele to ins after\n");
                   scanf("%d",&x);
                   p=fin(x,list);
                   if(p==NULL)
                   printf("No node found\n");
                   else
                   {
                       del(p);
                   }
                   break;
          case 5:dis(list);
                 break;
          case 6:printf("Tired huh.....???\n");
                 break;
          default:printf("Wrong input\n");
        }
    }
    return 0;
}

