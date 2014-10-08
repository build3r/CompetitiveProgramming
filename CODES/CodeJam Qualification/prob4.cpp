#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,n,cheat,fair,j,f,p,k;
    float a[1002],b[1002];
    freopen("in.txt","r",stdin);
    freopen("outmy.txt","w",stdout);
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
     p=cheat=fair=f=0;
      printf("Case #%d: ",ca);
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
      /*for(i=0;i<n;i++)
            printf("%0.3f ",a[i]);
            cout<<endl;
            for(i=0;i<n;i++)
            printf("%0.3f ",b[i]);
            cout<<endl;*/
            k=0;
            for(i=0;i<n;i++)
            {
               if(a[k]<b[i])
               {
                   k++;
               }
            }
            fair=n-(k);
            if(b[0]>a[n-1])
            {
                cout<<"0"<<" "<<fair<<endl;
            }
            else if(a[0]>b[n-1])
            {

              cout<<n<<" "<<fair<<endl;
            }
            else{
                p=0;
                int y=0;
            for(i=0;i<n;i++)
            {


                if(a[i]<b[p])
                {



                    b[n-(y)-1]=0;
                     f++;
                     y++;
                }
                else
                {


                    p++;

                }
            }
            cout<<n-f<<" "<<fair<<endl;
            }
    }
    return 0;
}
