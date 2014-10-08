#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cstdio>
    using namespace std;
short int own[10005];
int c[10005];
int i, t, j, b, n, q, x, y, opt, mx=0;
int main() {


    //freopen("in.txt","r",stdin);
    cin>>t;
    while (t--) {
        mx=0;
        cin>>n;


        for (i = 1; i <= n; i++) {

            cin>>c[i];
            own[i] = i;
        }


        cin>>q;
        for (i = 0; i<q; i++) {

            /* cout<<"Own = ";
            for(j=1;j<=n;j++)
            cout<<own[j]<<" ";
            cout<<endl;*/
            cin>>opt;
            if (!opt) {
                cin>>x>>y;
                b = 0;
                    x=own[x];
                    y=own[y];
                    if(mx<y)
                        mx=y;
                    if(mx<x)
                        mx=x;
               /* while (own[x] != x) {

                    v[b] = x;
                    b++;
                    x = own[x];

                }

                for (j = 0; j < b; j++) {
                    own[v[j]] = x;


                }
                b = 0;
                while (own[y] != y) {

                    v[b] = y;
                    b++;
                    y = own[y];

                }

                for (j = 0; j < b; j++) {
                    own[v[j]] = y;
                }*/
                if (own[x] == own[y])
                    {
                    cout << "Invalid query!\n";
                    continue;
                }
                if (c[x] > c[y])
                    {
                    own[y] = x;
                    for(int i=1;i<=mx;i++)
                    {
                        if(own[i]==y)
                            own[i]=x;
                    }
                }
                else if (c[x] < c[y])
                {
                    own[x] = y;
                     for(int i=1;i<=mx;i++)
                    {
                        if(own[i]==x)
                            own[i]=y;
                    }

                }
                else
                    continue;
            }
             else
            {
                cin>>x;

               /* b = 0;
                while (own[x] != x) {
                    v[b] = x;
                    b++;

                    //
                    x = own[x];

                }
                for (j = 0; j < b; j++) {
                    own[v[j]] = x;

                }*/



                cout << own[x] << endl;
            }
        }
    }
    return 0;
}
