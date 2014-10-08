#include<stdio.h>
#include<conio.h>
int main()
{
int a[50],n,i,j,temp;
//clrscr();
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("Enter the elements of a array\n");
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
 return 0;
 }
