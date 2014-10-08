#include<stdio.h>
void heasort(int *a,int *b,int n);
void heapbup(int *h,int n);
int main()
{
     int a[1000],b[1000],n,i;
    printf("Enter th numer of elemts\n");
    time_t(seed);
    scanf("%d",&n);
    i=1;
    while(i<n)
    a[i++]=rand()%100;
    printf("The original array is\n");
    for(i=1;i<n;i++)
    printf("%d\t",a[i]);
    heasort(a,b,n);
    printf("\nThe sorted array is\n");
    for(i=1;i<n;i++)
    printf("%d\t",b[i]);
    return 0;
}

void heapbup(int *h,int n)
{
    int i,v,k,j,flag=0;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=h[k];
        flag=0;
        while(!flag && (2*k)<=n)

         {

            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                j++;
            }
            if(v>=h[j])
            flag=1;
            else
            {
                h[k]=h[j];
                k=j;
            }
            h[k]=v;
         }

    }
}

void heasort(int *a,int *b,int n)
{
    int t,i,j;
for(i=n;i>=1;i--)

{
    heapbup(a,i-1);
    printf("\nThe heap\n");
    for(j=1;j<i;j++)
    printf("%d\t",a[j]);

    t=a[1];
    a[1]=a[i-1];
    b[i-1]=t;
}

}
