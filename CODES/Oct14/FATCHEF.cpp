#include <bits/stdc++.h>
using namespace std;

#define FST ios_base::sync_with_stdio(0)
#define INPT int t; cin>>t; while(t--)
#define FOR(i, a, b) for(i = a; i < b ; i++)
#define FORI(it, v) for(it = v.begin(); it != v.end(); it++)
#define VT(t) vector<t>
#define VTI(t) vector<t>::iterator
#define SZ(v) v.size()
#define CLR(v) v.clear()
#define PB(a) push_back(a)
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define MTTI(t1,t2) map<t1,t2>::iterator
#define F(it) it->first
#define S(it) it->second

using namespace std;
int  main(){
	int t,m,n,temp;
	char c;
	FST;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[n+1];
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=m;i++){
			cin>>c>>temp;
			arr[temp]=c;
		}
		int i=1;
		while(!arr[i] && i<n)i++;
		temp=arr[i];
		int first=i;
		long long int ans=1;
		i++;

		for(;i<=n;i++){
			if(arr[i] && arr[i]!=arr[first]){
				ans=(ans*(i-first))% 1000000009;
				first=i;

				}
			else if(arr[i])first=i;

		}
		cout<<ans<<endl;
	}

return 0;
}
