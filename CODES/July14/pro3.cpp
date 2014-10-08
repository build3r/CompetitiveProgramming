#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};



int main()
{
int t,i,j,n,k,p,o;
//freopen("in.txt","r",stdin);
vector<pair<int, int> > v;
vector<int> y;
y.push_back(0);
    cin>>n>>k>>p;

    for(i=1;i<=n;i++)
    {
        cin>>j;
        y.push_back(j);
        v.push_back(make_pair(i,j));

    }

    sort(v.begin(), v.end(), sort_pred());

//for(i=0;i<n;i++)
  //  cout<<"f = "<<v[i].first<<"    s = "<<v[i].second<<endl;
    y[v[0].first]=v[0].first;
    t=v[0].first;
    for(i=0;i<n-1;i++)
    {
        if((v[i+1].second-v[i].second)<=k)
        {
                y[v[i+1].first]=t;
        }
        else{
            t=v[i+1].first;
            y[v[i+1].first]=t;
        }
    }

    //for(i=1;i<=n;i++)
  //  cout<<"i = "<<i<<"  y[i] = "<<y[i]<<endl;

    for(j=0;j<p;j++)
    {
        int a,b;
        cin>>a>>b;
        if(y[a]==y[b])
        {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
  /*  bool f=1,s=0;
    for(j=0;j<p;j++)
    {
        s=f=0;
        int a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"Yes\n";
            continue;
        }
       long long int l,h,m;
        if(y[a]<y[b])
            t=y[a];
        else
            t=y[b];
        l=0ll;
        h=n;

        while(l<=h)
        {
            //cout<<"searching  m = "<<m<<"l ="<<l<<"h= "<<h<<endl;

            m=(l+h)/2;
            if(v[m].second==t)
            {
                t=m;
                s=1;
                //cout<<"found\n";
                break;


            }
            if(v[m].second<t)
            {
                l=m+1;
            }
            else
                h=m-1;
        }

                for(int h=t+1;h<n;h++)
                {
                    if((v[h].second - v[h-1].second)<=k )
                    {
                        if(v[h].first==b || v[h].first==a)
                            {
                                cout<<"Yes"<<endl;
                                f=1;
                            }
                        else
                            continue;
                    }
                    else
                    {
                        break;

                    }
                }


            if(s){
            if(!f)
            {
                cout<<"No\n";

            }
            }
        }*/
    return 0;
}
