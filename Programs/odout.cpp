/*#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,i,a[101];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        for(i=1;i<n;i++)
        {
            if(a[i-1]==a[i])
                i++;
            else
                cout<<a[i-1]<<" ";
        }
        if(a[n-2]!=a[n-1])
            cout<<a[n-1]<<" ";
        cout<<endl;
    }
}
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <sstream>
#include <fstream>
#include <functional>
#include <numeric>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#define vi vector<int>
#define v2di vector< vector<int> >

#define fR(i,L,U) for( int i=L; i<U; ++i )
#define f0R(i,U) for( int i=0; i<U; ++i)

#define ull unsigned long long int
#define ll long long int

#define DEBUG 0
#define FILEOP 0

using namespace std;

int main(int argc, char** argv)
{
#if FILEOP
	ifstream f (argv[1]);

	if( f.is_open() ){
		while( f.good() ){
			// File operations
		}
	}
#endif

	int t;
	cin>>t;
	while(t--)
	{
		int n, i, num;

		map<int, int> count_map;
		set<int> unique_set;
		set<int>::iterator it;

		cin>>n;
		for (i = 0; i < n; i++) {
			cin>>num;
			unique_set.insert(num);
			if(count_map.count(num) > 0)
				count_map[num]++;
			else
				count_map[num] = 1;
		}

		for ( it = unique_set.begin(); it != unique_set.end(); it++ )
		{
			if((count_map[*it] % 2) == 1)
			{
				cout<<*it<<endl;
				break;
			}
		}
	}

	return 0;
}
