#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int i,j,k,n,len,p1,p2,cas=0;
        char s1[5000];
       // char c=' ';
        cin>>n;
       // n+=1;
        for(k=0;k<n;k++)
        {
        cout<<"Case #"<<k+1<<": ";
          lab:  gets(s1);
            len=strlen(s1);
            if(len==0)
                goto lab;
            p2=len-1;
           for(i=(len-1);i>=0;i--)
            {
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
