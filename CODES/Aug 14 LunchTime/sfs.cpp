#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
  int D[524288];
    //int X[524288];
int main()
{
    long long int t,h,n,m,a,b,ind,previ,curr,pans;
    int tem;
    //cin>>t;
    scanf("%lld",&t);

    double ans;
    while(t--)
    {

        pans=0;
        scanf("%lld",&h);
        scanf("%lld %lld",&n,&m);
        scanf("%lld %lld %lld",&a,&b,&ind);

        //cin>>h;
        //cin>>n>>m;
       // D.resize(m);
        //cin>>a>>b>>ind;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&D[i]);
            //cin>>D[i];
            //D.push_back(tem);
        }
        previ=0ll;
        for(int i=1; i<n; i++)
        {

            curr=(previ+D[ind]);
            pans+=((h)*(curr-previ));
            previ=curr;
            ind=(a*ind+b)%m;
           // cout<<ans<<"  xgdfx"<<endl;
        }
       /* X[0]=0;
        for(int i=1;i<n;i++)
        {
            X[i]=X[i-1]+D[ind];
            ind=(a*ind+b)%m;
        }
        for(int i=1; i<n; i++)
        {
            ans+=(0.5)*(double(h)*double(X[i]-X[i-1]));
        }*/
        ans= pans*0.5;
        printf("%.1f\n",ans);
    }
    return 0;
}

