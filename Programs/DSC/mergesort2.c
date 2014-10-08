#include<stdio.h>
void mergesort(int *a,int ,int );
void merge(int *a,int *b,int *c,int p,int q);
int main()
{
    int a[100000],i,n;
    time_t(seed);
    printf("Enter no.of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    a[i]=rand()%1000;
    printf("the original list\n");
    i=0;
    while(i<n)
    printf("%d\t",a[i++]);
    printf("\nAfter Merge sort\n");
    i=0;
    mergesort(a,0,n);
    while(i<n)
    printf("%d\t",a[i++]);
    return 0;
}

void mergesort(int *a,int l,int h)
{
int i,b[h],c[h];
    if(h>1)
    {

    for(i=0;i<h/2;i++)
    b[i]=a[i];
    for(i=(h/2);i<h;i++)
    c[i-h/2]=a[i];
    mergesort(b,0,h/2);
    mergesort(c,0,(h-h/2));
    merge(a,b,c,h/2,(h-h/2));
    }
    return;
}

void merge(int *a,int *b,int *c,int p,int q)
{
    int g=0,i=0,j=0,k=0;
    //printf("h1=%d   h2=%d\n",h1,h2);
    while(i<p && j<q)
    {
        if(b[i]<=c[j])
        a[k++]=b[i++];
        else
        a[k++]=c[j++];
    }
    if(i==p)
    for(g=j;g<q;g++)
    a[k++]=c[g];
    else
    for(g=i;g<p;g++)
    a[k++]=b[g];
    return;
}
