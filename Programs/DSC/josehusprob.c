#include<stdio.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node *next;
};
typedef struct node *np;
void josephus(np list);
np list=NULL;
np getnode()
{
    np p;
   p=(np)malloc(sizeof(struct node));
   return p;
}
int i=0;
void ins(np p,char x)
{
    np q;

    q=getnode();
    q->info=x;
    if(i==1)
    {
     q->next=q;
     list=q;

    }
else
 {
  q->next=p->next;
   p->next=q;
   list=q;

 }
}

void del(np p)
{
    np q;
    q=p->next;
    printf("The unlucky soldier is:%c\n",q->info);
    p->next=q->next;
    free(q);
}

np fin(char x,np list)
{
    np q=list;
    q=q->next;
    if(x==q->info)
    return list;
    do
    {
        if(q->next->info==x)
        {
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
        printf("\n->%c\n",p->info);
    }while(p!=list);
}


int main()
{
    char x;
    printf("Enter the names and $ to stop\n");
    while(x!='$')
    {
        fflush(stdin);

        scanf("%c",&x);
        if(x!='$')
        ins(list,x);
    }
    printf("order of soldiers is\n");
    dis(list);
    josephus(list);
    return 0;
}

void josephus(np list)
{
    int n=0,k;
    np x=list;
    char c;
    printf("select n\n");
    scanf("%d",&n);
    name:
    printf("Enter th name to start with\n");
    fflush(stdin);
    scanf("%c",&c);
    list=fin(c,x);
    if(list==NULL)
    {
        printf("the soldier does not exist in th list\n");
        goto name;
    }
    else
    {
    printf("The order in wich soldiers are eliminated is\n");
    while(list!=list->next)
    {
        for(k=1;k<n;k++)
        list=list->next;
        del(list);
    }
    printf("The soldier wich escapes is %c\n",list->info);
    free(list);
    }
}
