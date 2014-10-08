#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *np;

np getnode()
{
    np p;
   p=(np)malloc(sizeof(struct node));
   return p;
}

void ins(np p,int x)
{
    np q;
    q=getnode();
    q->info=x;
        q->next=p->next;
    p->next=q;
}

void del(np p)
{
    np q;
    if(p->next==NULL)
    {
        printf("no nodes \n");
    }
    else
    {
        q=p->next;
        printf("the delete node's info is %d\n",q->info);
        p->next=q->next;
        free(q);
    }
}

np fin(int x,np list)
{
    np q=list;
    do
    {
        if(q->info==x)
        return q;
        q=q->next;
    }while(q!=NULL);
    return NULL;

}

void dis(np list)
{
    np p=list;
    do
    {
        p=p->next;
        printf("\n->%d\n",p->info);
    }while(p->next!=NULL);
}

int main()
{
    np p=NULL,list=NULL;
    list=getnode();
    list->info=0;
    list->next=NULL;
    int c=0,x;
    while(c!=6)
    {
        printf("\n1.insert f\t2.delf\t3.ins after\t4.del after\t5.display\t6.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter ele to insert\n");
                   scanf("%d",&x);
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
                       del(p);
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
