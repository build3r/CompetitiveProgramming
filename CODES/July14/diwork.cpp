#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>


using namespace std;
vector <int> v(1);
int findSet(int i) { return (v[i] == i) ? i : (v[i] = findSet(v[i])); }
void unionSet(int i, int j) { v[findSet(i)] = findSet(j); }

int main()
{
	int t,n,q,i,x,y,a,c1,c2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		v.resize(n+1);
		for(i=0;i<n+1;i++)
		v[i]=i;
		int s[n+1];
		for(i=1;i<=n;i++)
		scanf("%d",&s[i]);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&a);
			if(a==0)
			{
				scanf("%d",&x);
				scanf("%d",&y);
				c1=findSet(x);
				c2=findSet(y);
				if(c1==c2)	printf("Invalid query!\n");
				else if(s[c1]>s[c2])	unionSet(c2,c1);
				else if(s[c2]>s[c1])	unionSet(c1,c2);
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",findSet(x));
			}
		}
	}
	return 0;
}
