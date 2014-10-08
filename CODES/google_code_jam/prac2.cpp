#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,k,f,c,n,a[2001];
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n;
    for(int nn=1;nn<=n;nn++)
    {
        f=0;
        printf("Case #%d: ",nn);
        cin>>c;
        cin>>k;
        for(i=0;i<k;i++)
            cin>>a[i];
        for(i=0;i<k;i++)
            {for(j=i+1;j<k;j++)
            {
                if((c-a[i]-a[j])==0)
                {cout<<i+1<<" "<<j+1<<endl;
                 f=1;
                }

            }
            if(f)
                break;
            }
    }
    return 0;
}
