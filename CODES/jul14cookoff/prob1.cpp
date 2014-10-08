#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <set>
using namespace std;
int t,n,k,mx;
set<int> st;
pair<std::set<int>::iterator,bool> ret;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        st.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            st.insert(k);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
