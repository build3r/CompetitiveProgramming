#include<iostream>
using namespace std;
int main()
{
    int i,t,j,be,n;
    double d,u,m,r,c,nor,pl,tem;
    cin>>t;
    while(t--)
    {
        be=0;
        tem=0;
        cin>>d>>u;
        cin>>n;
        nor=d*u;
        for(i=1;i<=n;i++)
        {
            cin>>m>>r>>c;
            pl=(nor-(r*u + c/m));
            if(pl>tem)
            {
                tem=pl;
                be=i;
            }
        }
        cout<<be<<endl;
    }
    return 0;
}
