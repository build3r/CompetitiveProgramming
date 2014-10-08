#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;

   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);

   // Return the maximum of two cases: (1) nth item included (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

int main()
{
    int n,tem,mx,tim[1000],marks[1000],total;

        cin>>n;
        cin>>total;
        for(int i=0;i<n;i++)
            {cin>>marks[i];}

        for(int i=0;i<n;i++)
            cin>>tim[i];
            mx=0;
            int l=0;
            marks[n-1]=marks[n-1]*2;
            tem=knapSack(total,tim,marks,n);
            //marks[n-1]=marks[i]/2;
            if(tem>mx)
                mx=tem;

            cout<<mx<<endl;
        return 0;
}
