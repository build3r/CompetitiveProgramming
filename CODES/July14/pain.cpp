#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
double E[55][110];
int c;
double Expected(int k , int a)
{

    if(k<=0)
        return 0;
    if(E[k][a] !=-1)
        return E[k][a];
    if(k==1)
    {
        double solution=0;
        solution = static_cast<double>(a)/2;
        for(int i=1; i<=c-1; i++)
        {
            solution=solution + 1/(2.0*c) * static_cast<double>(static_cast<int>(a*i)%c);
        }
        E[k][a]=solution;
        return solution;
    }
    double solution = (Expected(k-1,a)/2.0);
    for(int i=1; i<=c-1; i++)
    {
        solution+=(1/(2.0*c))*Expected(k-1,i);
    }
    return solution;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<55; i++)
            for(int j=0; j<110; j++)
                E[i][j]=-1;
        int start[55],end[55];
        int n,k,count[55];
        cin>>n>>c>>k;
        for(int i=0; i<55; i++)
            count[i]=0;
        for(int i=0; i<k; i++)
        {
            cin>>start[i]>>end[i];
            for(int j=start[i]; j<=end[i]; j++)
                count[j]++;
        }
        for(int i=1; i<=n; i++)
        {

            cout<<count[i]<<" ";
        }
        cout<<endl;
        double solution=0;

        for(int i=1; i<=n; i++)
            solution=solution+Expected(count[i],1);
        cout<<solution<<endl;

    }

}
