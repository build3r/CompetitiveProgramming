#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <set>
using namespace std;
int main()
{
    //freopen("in","r",stdin);

    unsigned int n,m,q,low,high,peak;
    cin>>n>>m;
    //scanf("%d %d",&n,&m);
    low=n+2;
    peak=(2*n)+1;
    while(m--)
    {
        cin>>q;
        //scanf("ll%d",&q);
        if(q<low)
            printf("0\n");

        else if(q==peak)
                cout<<n<<endl;

            else if(q<peak)
            cout<<(n-(peak-q))<<endl;

            else if(q>peak)
            {
                cout<<(n-(q-peak))<<endl;

            }


    }
    return 0;
}
