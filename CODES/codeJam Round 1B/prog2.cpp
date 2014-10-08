#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int l,tst,i,j,cnt,cas=1;
    long long int p,q,g,tem;
    string s;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>tst;
    for(cas=1;cas<=tst;cas++)
    {
        p=q=cnt=0;
        cin>>s;
        l=s.length();
        j=s.find('/');
        for(i=0;i<j;i++)
        {
            tem=1;
            for(int k=0;k<(j-i-1);k++)
        {
            tem*=10;
        }
            p=p+((s[i]-'0')*tem);

        }
        q=0;
        for(i=j+1;i<l;i++)
        {  tem=1;
            for(int k=0;k<(l-i-1);k++)
        {
            tem*=10;
        }
            q=q+((s[i]-'0')* tem);
        }

        if(q%2!=0)
        {
            cout<<"Case #"<<cas<<": ""impossible\n";
        }
        else
        {
            while(p<q)
            {

                q/=2;
               // cout<<"q = "<<q<<" p = "<<p<<endl;
                cnt++;
            }
            cout<<"Case #"<<cas<<": "<<cnt<<endl;
        }

    }
    return 0;
}
