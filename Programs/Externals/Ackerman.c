#include<stdio.h>
#include<conio.h>
int a(int m,int n);
int main()
{
printf("valueis =%d",a(10,5));
return 0;
}


int a(int m,int n)
{
if(m==0)
{
printf("m=%d     n=%d\n",m,n);
return n+1;
}
else if((n==0))
{
printf("2nd m=%d     n=%d\n",m,n);
return a(m-1,n);
}
else if((n!=0))
{
printf("3rd m=%d     n=%d\n",m,n);
getch();
return a(m-1,a(m,n-1));
}
return n;
}
