#include<stdio.h>
#include<conio.h>
void q(int);
int main()
{
//clrscr();
q(3);
//getch();
return 0;
}
void q(int n)
{
if(n>0)
{
printf("0");
q(n-1);
printf("1");
q(n-1);
}
}
