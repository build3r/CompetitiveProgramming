#include<stdio.h>
void mergesort(int *a,int ,int );
void merge(int *a,int *b,int ,int ,int ,int ,int *c);
int main()
{
    int a[10]={1,5,7,3,2,6,9,4,8,5},i;
    printf("atrts\n");
    scanf("%d",&i);
    printf("the original list\n");
    i=0;
    while(i<10)
    printf("%d\t",a[i++]);
    printf("\nAfter Merge sort\n");
    i=0;
    mergesort(a,0,9);
    while(i<10)
    printf("%d\t",a[i++]);
    return 0;
}

void mergesort(int *a,int l,int h)
{
  int i=0;
  int len=h-l+1;
  int piv=0;
  int m1=0,m2=0;
  int work[len];
  if(l==h)
  return;
  piv=(l+h)/2;
  mergesort(a,l,piv);
  mergesort(a,piv+1,h);
  for(i=0;i<len;i++)
  work[i]=a[l+i];
  m1=0;
  m2=piv-l+1;
  for(i=0;i<len;i++)
   {
       if(m2<=h-l)
       if(m1<=piv-l)
       if(work[m1]>work[m2])
       a[i+l]=work[m2++];
       else a[i+l]=work[m1++];
       else a[i+l]=work[m2++];
       else a[i+l]=work[m1++];
   }
}


/*void mergesort(int *a,int l,int h)
{
int i,m[10],n[10];
    if(h>1)
    {

    for(i=0;i<h/2;i++)
    m[i]=a[i];
    for(i=h/2;i<h;i++)
    n[i]=a[i];
    mergesort(m,0,h/2);
    mergesort(n,0,h/2);
    merge(m,n,0,h-1,0,h-1,a);
    }
    return;
}

void merge(int *m,int *n,int l1,int h1,int l2,int h2,int *a)
{
    int g=0,i=0,j=0,k=0;
    printf("h1=%d   h2=%d\n",h1,h2);
    while(i<h1 && j<h2)
    {
        if(m[i]<=n[j])
        a[k]=m[i++];
        else
        a[k]=n[j++];
        k++;
    }
    if(i==h1)
    for(g=j;g<h2;g++)
    a[k++]=n[g];
    else
    for(g=i;g<h1;g++)
    a[k++]=m[g];
    return;
}
*/
