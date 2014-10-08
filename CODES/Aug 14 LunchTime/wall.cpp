#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a);(i) < (b) ;(i)++)
#define IN(n) scanf("%d",&(n))


  int d[524288];
vector<int> x;
int main()
{
    int t;
     int h,n,m,a,b,ind,previ,curr;
	scanf("%d",&t);
	while(t--)
	{
		x.clear();
		//d.clear();
        scanf("%d",&h);
        scanf("%d %d",&n,&m);
        scanf("%d %d %d",&a,&b,&ind);
		int temp;
		for(int i=0;i<m;i++)
		{
            scanf("%d",&d[i]);
		}
		x.push_back(0);
		bool mv=false;
		long long sum=0;
		int j=1;
		for(int i=1;i<n;i++)
		{
      			x.push_back(x[j-1]+d[ind]);
      			ind = (a*ind+b)%m;
      			j++;
      			if(mv)
      			{
      				sum	+=(x[2]-x[0]);
      				int k=x[2];
      				x.clear();
      				x.push_back(k);
      				j=1;
      			}
      			mv=!mv;
		}
		int size = x.size();
		if(size%2==0)
		{
			sum=sum+(x[1]-x[0]);
		}
		double ans = 0.5*h*sum;
		printf("%0.1f\n",ans);

	}
	return 0;
}
