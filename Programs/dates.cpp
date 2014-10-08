#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cctype>
#include<cassert>
#include<cstring>

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>

#include<cmath>
#include<algorithm>
#include<functional>
#include<numeric>
#include<limits>

#include<string>
#include<vector>
#include<map>
#include<set>

#define mod 100000007

using namespace std;

long long *d=new long long[100004];
long long ge()
{
    d[1]=0;d[2]=1;
     //if(n==1)return 0;
     //if(n==2)return 1;
     for(int i = 3; i< 100004 ; i++)
     d[i]=(((i-1)%mod) * ((d[i-1]+d[i-2])%mod)) %mod ;
}

int main()
{
    ge();

    int t ; cin>>t;
    while(t--){
    long long n ; cin>>n;
    cout<<d[n]<<endl;
    }
}
