
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 100007
#define MOD 1000000007

using namespace std;

vector <int> edges [N];
vector <int> rEdges [N];
vector <int> sortedNode;

bool vis [N];

long long len[N];

long long gcd(long long a,long long b) {
	if (a<b) return gcd(b, a) ;
	if (a%b==0) return b;
	else return gcd (b, a%b);
}

int gcdArray(long long arr[], int start, int end) {
	if ((end-start)==1) return (gcd(arr[start], arr[end-1]));
	else return (gcd(arr[start], gcdArray(arr, start+1, end)));
}


void dfs1 (int x)
{
    vis [x] = true;

    for ( size_t u = 0; u < edges [x].size(); u++ ) {
        if ( !vis [edges [x] [u]] )
            dfs1(edges [x] [u]);
    }

    sortedNode.push_back(x);
}

void dfs2 (int x, int c)
{
    vis [x] = false;
    len[c]++;
    for ( size_t u = 0; u < rEdges [x].size(); u++ ) {
        if ( vis [rEdges [x] [u]] )
            dfs2(rEdges [x] [u], c);
    }
}

int main ()
{
    int t ; cin>>t ;
    while(t--) {
    	int n;
		cin>>n ;
    	   for ( int i = 0; i < N; i++ ) {
        edges [i].clear();
        rEdges [i].clear();
    }

    sortedNode.clear();
	memset (len, 0, sizeof len);
    memset (vis, false, sizeof vis);

    	for ( int i = 0; i < n ; i++ ) {
    	    int a; cin>>a;

    	    edges [i].push_back(a-1);
        	rEdges [a-1].push_back(i);
    	}

    	for ( int i = 0; i < n; i++ ) {
        	if ( !vis [i] )
        	    dfs1 (i);
    	}

    	int componentId = 0;

    	for ( int i = sortedNode.size() - 1; i >= 0; i-- ) {
        	if ( vis [sortedNode [i]] )
         		dfs2(sortedNode [i], componentId++);
    	}
		/*for(int i=0 ; i < componentId; ++i) {
			cout<<len[i]<<" ";
		}
		cout<<endl;*/
        sort(len, len+componentId);

		//if((sizeof(len) / sizeof(long long))==1) cout<<len[0]<<endl;
        int x = gcdArray(len, 0, componentId);

	    for (int i = 0; i < componentId; ++i){
            len[i] /= x;
        }
        int res=1;
        for (int i = 0; i < componentId; ++i){
            res = (res*len[i])%MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
