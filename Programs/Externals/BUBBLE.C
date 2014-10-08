#include<stdio.h>
#include<conio.h>
void main()
{
int a[50],n,i,j,temp;
clrscr();
printf("Enter the order of matrix a\n");
scanf("%d",&n);
printf("Enter the elements of matrix a\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 {
 for(j=0;j<n-1;j++)
 {
 if(a[j]>a[j+1])
 {
 temp=a[j+1];
 a[j+1]=a[j];
 a[j]=temp;
 }
 }
 }
 printf("The sorted elements are\n");
 for(i=0;i<n;i++)
 printf("%d\n",a[i]);
 getch();
}
