#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,i,j,k,f,a[5][5],b[5][5],c1,c2;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
        f=0;
        printf("Case #%d: ",ca);
        cin>>c1;
        for(i=1;i<=4;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
        cin>>c2;
        for(i=1;i<=4;i++)
        {
           cin>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4];
        }
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(a[c1][i]==b[c2][j])
                    {f++;

                    k=a[c1][i];
                    }
            }
        }
        if(f>1)
            cout<<"Bad magician!\n";
        else if(f==1)
            cout<<k<<endl;
            else
                cout<<"Volunteer cheated!\n";

    }
    return 0;
}
