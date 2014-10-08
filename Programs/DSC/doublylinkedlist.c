#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next,*prev;
};

typedef struct node *np;

np getnode()
{
    np p;
   p=(np)malloc(sizeof(struct node));
  // printf("Inside getnode\n");
   return p;
}
int k=0;
void ins(np p,int x)
{

    np q;
    q=getnode();
    //printf("after getnode\n");
    q->info=x;
    q->prev=p;
    q->next=p->next;
    if(k>1 && q->next!=NULL)
    {
    q->next->prev=q;

  // printf("in ins q->prev points %u\n",q->next->prev);
    }
      //  printf("wat q->next points %u\n",(q->next));
        //printf("after next\n");

    p->next=q;

}

void del(np p)
{
    np q;
    if(p->next==NULL)
    {
        printf("last node cant delete\n");
    }
    else
    {
        q=p->next;
        printf("the delete node's info is %d\n",p->next->info);
        p->next=q->next;
        if(q->next!=NULL)
        q->next->prev=q->prev;
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
    //printf("Element not found\n");
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
void disrev(np p)
{
    //int l;
    do
    {
        p=p->next;
    }while(p->next!=NULL);
   //printf("->%d\n",p->info);
    //scanf("%d",&l);
    do
    {//printf("p->prev points:%d\n",p->prev);
        printf("->%d\n",p->info);
        p=p->prev;
    }while(p->prev!=NULL);
}

int main()
{
    np p=NULL,list;
    list=getnode();
    list->info=0;
    list->next='\0';
    list->prev='\0';
    int c=0,x;
    while(c!=7)
    {
        printf("\n1.insert front\t2.delfront\t3.ins after\t4.del after\t5.display\t6.Dis rev\t7.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter ele to insert\n");
                   scanf("%d",&x);
                   k++;
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
          case 6:disrev(list);
                 break;
          case 7:printf("Tired huh.....???\n");
                 break;
          default:printf("Wrong input\n");
        }
    }
    return 0;
}
