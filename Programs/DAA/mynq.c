#include<stdio.h>
int count;
int place(int x[],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if((x[i]==x[k]) || (i-x[i]==k-x[k]) || (i+x[i]==k+x[k]))
        return 0;
    }
    return 1;
}


void print(int x[],int n)
{
    int i,j;
    for(i=0;i<=n;i++)
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

void nqueens(int n)
{
    int x[20],i,k;
    k=1;
    x[k]=0;
    while(k!=0)
    {
        x[k]++;
        while((x[k]<=n)&&(!place(x,k)))
        x[k]++;
        if(x[k]<=n)
        {
            if(k==n)
            {
                count++;
                getch();
                print(x,n);
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
