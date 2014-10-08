#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
#define gc getchar
inline int scan(){bool f=0; register int c = gc();if(c=='-') f=1; int x=0;for(;c<'0'||c>'9';c=gc());for(;c>='0'&&c<='9';c=gc()){x=(x<<1)+(x<<3)+c-'0';}if(f)return -x; return x;}
int a[100002],m,i,j,k,l,r,n,te,t;
int main()
{
    scanf("%d",&t);
    //t=scan();
    while(t--)
    {

        scanf("%d %d",&n,&m);
        //n=scan();
        //m=scan();
        a[0]=n+1;
        for(i=1;i<=n;i++)
        {
            //scanf("%d",a+i);
            a[i]=scan();
        }
        pair<int,int> p[m];
        //memset(b,0,sizeof(b));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&l,&r);
            //l=scan();
            //r=scan();
            p[i].first=l;
            p[i].second=r;
        }
        sort(p,p+m);
     //   for(i=0;i<m;i++)
    // cout<<p[i].first<<"   "<<p[i].second<<endl;
         pair<int,int> np[m];
         k=0;
        for(i=0;i<m-1;i++)
        {
            if(p[i].first!=p[i+1].first)
            {
                if(p[i].second<=p[i+1].first)
                {
                    np[k].first=p[i].first;
                    np[k].second=p[i].second;
                    k++;
                }
                else
                    {
                        cout<"in else\n";
                        int mx=p[i].second;
                        while(mx>p[i+1].second && i<m-1)
                        {
                            cout<"in while\n";
                            mx=p[i+1].second;
                            i++;
                        }
                    np[k].first=p[i].first;
                    np[k].second=p[i].second;
                    k++;
                    }
            }
            //else if((p[i].first>))
        }
        np[k].first=p[m-1].first;
                np[k].second=p[m-1].second;
                k++;
        //cout<<"k="<<k<<endl;
        for(i=0;i<k;i++)
            {
                cout<<np[i].first<<"   "<<np[i].second<<endl;
                for(int jj=np[i].first;jj<np[i].second;jj++)
                    for(int kk=jj+1;kk<=np[i].second;kk++)
                {
                    if(a[kk]==jj)
                    {
                        a[kk]=a[jj];
                        a[jj]=jj;
                    }
                }
               // sort((&a[0]+(np[i].first)),(&a[0]+(np[i].second)));
               for(j=1;j<=n;j++)
                {
                    //cout<<"setrw4tyera\n";
                   cout<<a[j]<<"  ";
                }
                cout<<endl;
            }

        for(i=1;i<=n;i++)
        {
           // cout<<a[i]<<"  ";
            if(a[i]!=i)
            {
                printf("Impossible\n");
                break;
            }
        }
        if(i>n)
        {
            printf("Possible\n");
        }
    }
    return 0;
}
