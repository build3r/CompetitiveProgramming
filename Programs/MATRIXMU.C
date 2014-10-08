#include<stdio.h>
#include<conio.h>
void main()
{
int a[50][50],b[50][50],c[50][50],i,j,m,n,p,q,temp;
clrscr();
printf("enter the order of matrix a\n");
scanf("%d %d", &m,&n);
printf("order of b\n");
scanf("%d %d",&p,&q);
if(p==m && n==q)
{
printf("enter the element of matrix a \n");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("enter elements matrix b\n");
for(i=0;i<p;i++)
for(j=0;j<q;j++)
scanf("%d",&b[i][j]);
for(i=0;i<m;i++)
for(j=0;j<n;j++)
{
 c[i][j]=(a[i][j])*(b[i][j]);
 temp=c[i][j];
 c[i][j]=a[i][j]*b[i][j];
 c[i][j]=temp+c[i][j];
}
printf("the sum is\n");
for(i=0;i<m;i++)
{
printf("\n\n");
for(j=0;j<n;j++)
printf("%d\t",c[i][j]);
}
}
else
{
printf("addition not possible\n");
}
getch();
}
