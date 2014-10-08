#include<stdio.h>
int fact(int n)
{
int x,y;
if(n==0)
return 1;
x=n-1;
y=fact(x);
return (n*y);
}

int main()
{
int n;
scanf("%d",&n);
n=fact(n);
printf("\nfact=%d",n);
return 0;
}
