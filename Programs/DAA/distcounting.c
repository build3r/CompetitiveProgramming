#include<stdio.h>
void disti(int *,int ,int);
int s[20];
int d[10];
int main()
{
    int a[10]={10,11,10,12,11,13,12,13,10,11},i;
   // printf("atrts\n");
    //scanf("%d",&i);
    printf("the original list\n");
    i=0;
    while(i<10)
    printf("%d\t",a[i++]);
    disti(a,10,13);
    printf("\nAfter Disti Count sort\n");
    i=0;
    while(i<10)
    printf("%d\t",s[i++]);
    return 0;
}

void disti(int *a,int l,int u)
{
    int i,j,k;
    for(i=0;i<10;i++)
    d[a[i]-l]++;
    for(j=0;j<=u-l;j++)
    d[j]=d[j-1]+d[j];
    for(i=9;i>=0;i--)
    {
        j=a[i]-l;
        s[d[j]-1]=a[i];
        d[j]--;
    }
}
