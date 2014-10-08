#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    	freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int i,j,k,n,l1,p1,p2,cas=0;
        char s1[200];
        char c=' ';
        cin>>n;
        while(n--)
        {   cas++;
            gets(s1);
            l1=strlen(s1);
            p2=l1-1;
            cout<<"Case #"<<cas<<": ";
            for(i=l1-1;i>=0;i--)
            {
                    //cout<<s1[i]<<endl;
                if(s1[i]==' ' || i==0)
                {
                    j=i+1;
                    if(i==0)
                    j=0;
                    for(;j<=p2;j++)
                       {

                        cout<<s1[j];}
                    cout<<" ";
                    p2=i-1;
                }
            }
            cout<<endl;

        }
        return 0;
}
