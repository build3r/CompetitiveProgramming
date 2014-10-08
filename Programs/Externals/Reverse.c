#include<stdio.h>
int main()
{
int rev=0,a;
scanf("%d",&a);
while(a)
{
rev=(rev+(a%10))*10;
a=a/10;
}
printf("\n the size is %d",sizeof(a));
printf("\nthe reverse is %d",rev/10);
return 0;
}