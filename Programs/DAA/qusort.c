#include<stdio.h>
void quick(int *a,int l,int r);
int partition(int *a,int l,int r);
int main()
{
    int a[20]={2,5,4,1,3,9,6,7,8,0},i;
    printf("elements b4 sorting\n");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    quick(a,0,9);
    printf("elements after sorting\n");
    for(i=0;i<10;i++)
    printf("%d\t",a[i]);
    return 0;
}

void quick(int *a,int l,int r)
{
    int i,s;
    if(l<r)
    {
    s=partition(a,l,r);
    printf("\n");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    //printf("after part\n l=%d    r=%d    s%d",l,r,s);
    quick(a,l,s-1);
   // for(i=0;i<10;i++)
   // printf("%d\t",a[i]);
    quick(a,s+1,r);
   // for(i=0;i<10;i++)
   // printf("%d\t",a[i]);
    }
    return;
}

int partition(int *a,int l,int r)
{
    int t,p=a[l],i=l+1,j=r;
    //fflush(stdin);

   printf("in part  p=%d \n",p);
    /*do
    {
        do
        i++;
        while(a[i]>=p);
        do
        j--;
        while(a[j]<=p);
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }while(i>=j);
    t=a[i];
    a[i]=a[j];
    a[j]=t;
    t=a[l];
    a[l]=a[j];
    a[j]=t;
    return j;
*/
while(i!=j)
{
for(;a[i]<p ||i<r ;i++)
{

}
for(;a[j]>p;j--)
{

}
if(i<j)
{
    t=a[i];
    a[i]=a[j];
    a[j]=t;
}
if(i>j)
{
    t=a[l];
    a[l]=a[j];
    a[j]=t;
}
}
return i;
}
