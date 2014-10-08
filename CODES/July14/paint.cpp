#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;
int c;
double E[55][110];
double Expected(int k , int a)
{
    if(E[k][a]!=-1 )
        return E[k][a];
    if(k==0)
    {
        E[k][a]=1;
        return 1;
    }
    if(k==1)
    {
        double sol=0;
        sol = static_cast<double>(a)/2;
        for(int i=1; i<=c-1; i++)
        {
            sol=sol + 1/(2.0*c) * static_cast<double>(static_cast<int>(a*i)%c);
        }
        E[k][a]=sol;
        return sol;
    }
    double sol=0;
    if(a%c!=0)
        sol = (Expected(k-1,a)/2.0);

    for(int i=1; i<=c-1; i++)
    {
        sol+=(1/(2.0*c))*Expected(k-1,(i*a)%c);
    }
    E[k][a]=sol;
      for(int i=0; i<4; i++)
            {for(int j=0; j<4; j++)
               cout<< E[i][j]<<"\t";
               cout<<endl;
               }

    return sol;
}
        int start[55],end[55];
        int n,k,count[55];
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<55; i++)
            for(int j=0; j<110; j++)
                E[i][j]=-1;

        scanf("%d %d %d",&n,&c,&k);
        //cin>>n>>c>>k;
        //for(int i=0; i<55; i++)
          //  count[i]=0;
          memset(count,0,sizeof(count));
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&start[i],&end[i]);
            //cin>>start[i]>>end[i];
            for(int j=start[i]; j<=end[i]; j++)
                count[j]++;
        }
        double sol=0;
        for(int i=1; i<=n; i++)
            {   double te=Expected(count[i],1);
                printf("i= %d  expec = %lf\n",i,te);
                sol+=te;//Expected(count[i],1);}
    }
        printf("%lf\n", sol );

    }
    return 0;

}
