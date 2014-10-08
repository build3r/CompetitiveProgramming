#include<stdio.h>
#include<conio.h>
struct prioq
{
int dist,pr,s;
};
void dis(struct prioq p[20],int source,int dest)
{
if(dest==source)
{
printf("%d",source);
return;
}
dis
(p,source,p[dest].s);
printf("->%d",dest);
}
int main()
{
struct prioq p[20];
int i,j,n,k,min,pos,source,a[20][20];
printf("\nEnter the value of n ");
scanf("%d",&n);
printf("\nEnter the adjacency matrix ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
p[i].pr=0;
}
printf("\nEnter the source node ");
scanf("%d",&source);
for(i=0;i<n;i++)
{
p[i].s=source;
p[i].dist=a[source][i];
}
pos=source;
for(j=0;j<n;j++)
{
    i=pos;
    p[i].pr=-1;
    min=9999;
    for(k=0;k<n;k++)
    {
        if(p[i].dist+a[i][k]<p[k].dist)
        {
            p[k].dist=p[i].dist+a[i][k];
            p[k].s=i;
        }
        if(p[k].pr!=-1 && p[k].dist<min)
        {
            pos=k;
            min=p[k].dist;
        }
    }
}
printf("The shortest distances are\n");
for(i=0;i<n;i++)
{
    if(source == i)
    printf("%d -> %d",i,i);
    else
    dis(p,source,i);
    printf("     dist= %d\n",p[i].dist);
}
return 0;
}
