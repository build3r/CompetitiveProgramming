#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,j;
clrscr();
printf("pascal triangle\n");
printf("enter the num of rows\n");
scanf("%d",&n);
 for(i=0;i<=n;i++)
 {
 for(j=1;j<=n-i;j++)
 printf(" ");
 for(j=1;j<=i;j++)
 printf("%d",j);
 for(j=i-1;j>0;j--)
 printf("%d",j);
 printf("\n");
 }
 printf("\n");
 getch();
}
