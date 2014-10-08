#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b) ? a:b

int a[20][20],weight[20],cost[20],value;

int knapsack(int n,int capacity)
{
  if(a[n][capacity] < 0)
  {
     if(capacity < weight[n-1])
        value =  knapsack(n-1,capacity);
     else
        value =  max(knapsack(n-1,capacity) , cost[n-1] + knapsack(n-1,capacity - weight[n-1]));
     a[n][capacity] = value;
  }
  return(a[n][capacity]);
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

    printf("the maximum cost : %d\n",knapsack(n,capacity));
    return 0;
 }
