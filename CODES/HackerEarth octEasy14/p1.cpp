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

typedef long long int ll;

int main()
{
    FST;
    string s;
    long long int a,b;
    cin>>s;
    int len=s.length();
   INPT
    {
        cin>>a>>b;
        if(s[(a-1)%len]==s[(b-1)%len])
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }
    return 0;
}

