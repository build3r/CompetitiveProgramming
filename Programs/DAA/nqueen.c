
#include<conio.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
static int count;          //to keep count of no. of solutions


void print_soln(int n, int x[])
{
int i,j;
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		if(j==x[i])
			printf("Q ");
		else
			printf("X ");
	}
	printf("\n");
}
printf("\n");
}

int place(int x[], int k)  //to check whether a Q can be placed
{
int i,j;
for(i=1;i<k;i++)
	if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k])
		return FALSE;
return TRUE;
}


void nqueens(int n)
{
int x[20],k=1,i;
x[k]=0;
while(k!=0)
{
	x[k]=x[k]+1;
	while((x[k]<=n)&&(!place(x,k)))
		x[k]=x[k]+1;
	if(x[k]<=n)
	{
		if(k==n)
		{
			count++;
			getch();
			print_soln(n,x);
		}
		else
		{
			k++;
			x[k]=0;
		}
	}
	else
		k--;
}
return;
}


int main()
{
int n;
//clrscr();
printf("enter number of queens");
scanf("%d",&n);
printf("solutions:\n");
nqueens(n);
printf("\nno of solutions : %d",count);
//getch();
return 0;
}
