#include <bits/stdc++.h>
//#include<unordered_map>
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
map< pair<int,int> , int > mp;
int xy[2005][2],n,p1x,p2x,p3x,p1y,p2y,p3y;
ll d1,d2,d3;
int main()
{
    //FST;
    pair<int,int> pii;
    int ans=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>xy[i][1]>>xy[i][2];
        pii.first=xy[i][1];
        pii.second=xy[i][2];
        mp[pii] = 1;
    }
    if(n==0)
        ans=4;
    else if(n==1)
        ans=3;
    else if(n==2)
        ans = 2;
    else
    {
        for(int i=0;i<n-2;i++)
        {
            p1x=xy[i][1];
            p1y=xy[i][2];
            for(int j=i+1;j<n-1;j++)
            {
                p2x=xy[j][1];
                p2y=xy[j][2];
                d1 =  (ll)(p2x-p1x)*(p2x-p1x) + (p2y-p1y)*(p2y-p1y);
                for(int k=j+1;k<n;k++)
                {
                    p3x=xy[k][1];
                    p3y=xy[k][2];
                    d2 =(ll) (p2x-p3x)*(p2x-p3x) + (p2y-p3y)*(p2y-p3y);
                   // cout<<"Check = "<<(p2x-p3x)*(p2x-p3x) + (p2y-p3y)*(p2y-p3y);
                    d3 =(ll) (p3x-p1x)*(p3x-p1x) + (p3y-p1y)*(p3y-p1y);
//                    printf("p1x = %d p1y = %d  \n",p1x,p1y);
//                    printf("p2x = %d p2y = %d  \n",p2x,p2y);
//                    printf("p3x = %d p3y = %d  \n",p3x,p3y);
//                    printf("D1 = %lld D2 = %lld  D3 = %lld\n",d1,d2,d3);
                    if(d1==d2)
                    { //p2 90
                        int a1 = p2x - p1x;
                        int a2 = p3x - p2x;
                        int b1 = p2y - p1y;
                        int b2 = p3y - p2y;
                        if((a1*a2 + b1 * b2)==0)
                        {
                           int A=p1y-p3y;
                           int B=p3x-p1x;
                            int C=-p1y*(p3x-p1x)-p1x*(p1y-p3y);
                           int a = p2x,b=p2y;
                            int cp1,cp2;
                            cp1 = (a*B*B - a*A*A - 2*b*A*B - 2*A*C)/(A*A +B*B);
                            cp2 = (b*A*A - b*B*B - 2*a*A*B - 2*B*C)/(A*A +B*B);
                            //cp1 = p1x;
                            //cp2 = p3y;
                            pii.first = cp1;
                            pii.second = cp2;
                            //printf("3 cp1 %d cp2 %d\n",cp1,cp2);
                            if(mp[pii]==1)
                            {
                                //printf("1 cp1 %d cp2 %d\n",cp1,cp2);
                                ans = 0;
                                goto display;
                            }
                            else
                                ans = 1;
                        }
                    }
                    else if(d1==d3)
                    {//p1 90
                        int a1 = p2x - p1x;
                        int a2 = p3x - p1x;
                        int b1 = p1y - p3y;
                        int b2 = p1y - p3y;
                        if((a1*a2 + b1 * b2)==0)
                        {
                           int A = p2y-p3y;
                           int B = p3x-p2x;
                           int C = -p2y*(p3x-p2x)-p2x*(p2y-p3y);
                           int a = p1x,b=p1y;
                            int cp1,cp2;
                            cp1 = (a*B*B - a*A*A - 2*b*A*B - 2*A*C)/(A*A +B*B);
                            cp2 = (b*A*A - b*B*B - 2*a*A*B - 2*B*C)/(A*A +B*B);
                            pii.first = cp1;
                            pii.second = cp2;
                            //printf("3 cp1 %d cp2 %d\n",cp1,cp2);
                            if(mp[pii]==1)
                            {
                                //printf("2 cp1 %d cp2 %d\n",cp1,cp2);
                                ans = 0;
                                goto display;
                            }
                            else
                                ans = 1;
                        }
                    }
                    else if(d2 == d3)
                    {//p3
                        int a1 = p3x - p2x;
                        int a2 = p1x - p3x;
                        int b1 = p3y - p2y;
                        int b2 = p1y - p3y;
                        if((a1*a2 + b1 * b2)==0)
                        {
                           int A = p2y - p1y;
                           int B = p1x-p2x;
                           int C = -p2y * (p1x-p2x)-p2x*(p2y-p1y);
                           int a = p3x,b=p3y;
                            int cp1,cp2;
                            cp1 = (a*B*B - a*A*A - 2*b*A*B - 2*A*C)/(A*A +B*B);
                            cp2 = (b*A*A - b*B*B - 2*a*A*B - 2*B*C)/(A*A +B*B);
                            pii.first = cp1;
                            pii.second = cp2;
                            //printf("3 cp1 %d cp2 %d\n",cp1,cp2);
                            if(mp[pii]==1)
                            {

                                ans = 0;
                                goto display;
                            }
                            else
                                ans = 1;
                        }
                    }

                }
            }
        }
    }
    if(ans==-1)
    {
        ans = 2;
    }
    display:
        cout<<ans<<endl;
    return 0;
}



