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
int d[100005],n,m;
int main()
{
    //FST;
    INPT
    {
        cin>>n;
         long long int ans=0;
        for(int i=0;i<n;i++)
            cin>>d[i];
        int i=0,j=0;
        for(int k=0;k<n-1;k++)
        {
//            cout<<"D array\n";
//            for(int i=0;i<n;i++)
//            cout<<d[i]<<" ";
//            cout<<endl;
            if(d[k]<0 && d[k]!=0)
            {
                for(int h=k+1;h<n;h++)
                {
                    if(d[h]>0 && d[h]!=0)
                    {
                       //ans += (d[h]+d[k]) * abs(h-k);
                       if(abs(d[h])==abs(d[k]) )
                            {
                                ans += abs(d[h]) * abs(h-k);
                                d[h]=d[k]=0;
                                break;
                            }
                       else if(abs(d[h])>abs(d[k]) )
                            {
                                ans += abs(d[k]) * abs(h-k);
                                d[h]= d[h]+d[k];
                                d[k]=0;
                                break;
                            }
                       else
                            {
                                ans += abs(d[h]) * abs(h-k);
                                d[k] = d[k]+d[h];
                                d[h]=0;
                            }
                    }

                }

            }
            else if(d[k]>0 && d[k]!=0)
            {
//                cout<<"positive\n";
                for(int h=k+1;h<n;h++)
                {

                    if(d[h]<0 && d[h]!=0)
                    {

                       if(abs(d[h])==abs(d[k]))
                            {
//                                cout<<"ans eq = "<<ans<<endl;
                                ans += abs(d[k]) * abs(h-k);
                                d[h]=d[k]=0;
                                break;
                            }
                       else if(abs(d[k])>abs(d[h]))
                            {
                                ans += abs(d[h]) * abs(h-k);
                                d[k]= d[h]+d[k];
                                d[h]=0;
                            }
                       else
                            {
//                                cout<<"ans din = "<<ans<<endl;
                                ans += abs(d[k]) * abs(h-k);
                                d[h] = d[k]+d[h];
                                d[k]=0;
                                break;
                            }
                    }


                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


