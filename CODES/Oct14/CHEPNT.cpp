#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,k,count=0,LU;
    cin>>n>>m>>k;
    int arr[n+1][m+1],x,y;
    vector < pair < pair <int,int> ,int> > v;
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=m;j++)
                arr[i][j]=0;
    }
    for(int i=0;i<k;i++)
    {
            cin>>x>>y;
            arr[x][y]=1;
    }
//    cout<<"Before"<<endl;
//    for(int i=1;i<=n;i++)
//    {
//           {
//            for(int j=1;j<=m;j++)
//                cout<<arr[i][j]<<" ";
//           }
//           cout<<"\n";
//    }
    //cout<<"hello"<<endl;
    for(int i=n;i>0;i--)
    {
            for(int j=m;j>0;j--)
            {
                    if(arr[i][j]!=1)
                    {
                                    int p=i,q=j;
                                   // cout<<" p ="<<p<<" q="<<q<<"    ";
                                    while(arr[i][q]!=1 && q!=1)q--;
                                    while(arr[p][j]!=1 && p!=1)p--;
                                   // cout<<" p ="<<p<<" q="<<q<<endl;
                                    if(p<=q)
                                    {
                                           for(int k=p;k<=i;k++)
                                           arr[k][j]=1;
                                           LU = 1;
                                    }
                                   else  if(p>=q)
                                    {
                                           for(int k=q;k<=j;k++)
                                           arr[i][k]=1;
                                           LU = 0;
                                    }
                                  //  cout<<i<<" "<<j<<endl;
                                    count++;
                                    v.push_back(make_pair(make_pair(i,j),LU));

                    }
            }
    }
//    cout<<"after"<<endl;
//        for(int i=1;i<=n;i++)
//    {
//           {
//            for(int j=1;j<=m;j++)
//                cout<<arr[i][j]<<" ";
//           }
//           cout<<"\n";
//    }
    cout<<count<<endl;
    vector< pair < pair<int,int> , int > >::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
                                      cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
    }

    return 0;
}
