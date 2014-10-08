#include<stdio.h>
#include<stdlib.h>
int a[20][20],weight[20],cost[20],value;
int mfk(int i,int j)
{
    int s,t;
    if(a[i][j]<0)
    {
        if(j<weight[i])
        {
            value=mfk(i-1,j);
        }
        else
        {
            s=mfk(i-1,j);
            t=cost[i]+mfk(i-1,j-weight[i]);
            if(t>s)
            value=t;
            else
            value=s;
        }
        a[i][j]=value;
    }
    return a[i][j];
}

int main()
{
  int i,j,n,capacity;

  for(i = 0; i < 20; i++)
  {
    for(j = 0; j < 20; j++)
     a[i][j] = -1;
  }
  for(i = 0; i < 20; i++)
     a[i][0] = a[0][i] = 0;

   printf("enter the number of items :\n");
   scanf("%d",&n);
   printf("enter the item details :\n ");
   for(i = 0; i < n; i++)
   {
     printf("item %d :\n",i+1);
     printf("enter the weight :");
     scanf("%d",&weight[i]);
     printf("enter the cost :");
     scanf("%d",&cost[i]);
    }
    printf("enter the total capacity of the knapsack :");
    scanf("%d",&capacity);

    printf("the maximum cost : %d\n",mfk(n,capacity));
    return 0;
 }
