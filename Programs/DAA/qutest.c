#include<stdio.h>
#include<time.h>
int a[10000];
void quick(int *a,int l,int r);
int partition(int *a,int l,int r);
int main()
{
    int i,n,t;
    time_t(seed);
    printf("Enter no.of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    //scanf("%d",&a[i]);
    a[i]=rand()%100;
    ///a[i]=rand()%100;
    printf("\nelements b4 sorting\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    quick(a,0,n-1);
    printf("\nelements after sorting\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}

void quick(int *a,int l,int r)
{
    int s;
    if(l<r)
    {
    s=partition(a,l,r);
    quick(a,l,s-1);
    quick(a,s+1,r);
    }
    return;
}

int partition(int *a,int l,int r)
{
    int t,p=a[l],i=l+1,j=r;
while(i<=j)
{
    while(a[i]<p)
    i++;
    while(a[j]>p)
    j--;
    if(i<j)
    {
    t=a[i];
    a[i]=a[j];
    a[j]=t;
    }
}
    t=a[l];
    a[l]=a[j];
    a[j]=t;
return j;
}

/*void quick(int l,int r)
{
    int s=0;
    if(l<r)
    {
        s=partition(l,r);
        quick(l,s-1);
        quick(s+1,r);
    }
    return;
}

int partition(int l,int r)
{
    int p=a[l],t,i=l+1,j=r;
    while(i<j)
    {
        if(a[i]<p)
        i++;
        if(a[j]>p)
        j++;
        if(i<j)
        {
         t=a[i];
         a[i]=a[j];
         a[j]=t;
        }
    }
         t=a[l];
         a[l]=a[j];
         a[j]=t;
         return j;
}*/
