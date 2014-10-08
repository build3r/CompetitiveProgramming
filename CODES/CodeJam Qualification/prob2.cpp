#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,i,j;
    double c,f,x,crc,flag,prev,curr,gen=2;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
        flag=0;
        prev=curr=0;
        gen=2;
        crc=0;
        printf("Case #%d: ",ca);
        cin>>c>>f>>x;

        while(!flag)
        {
            prev=curr+x/gen;
            curr=curr+c/gen;
            gen+=f;
            curr+=x/gen;
            //cout<<prev<<"   check   "<<curr<<endl;
            if(curr>prev)
            {
                flag=1;
                curr=prev;
            }
            if(!flag)
                curr-=x/gen;
        }
        printf("%.6lf\n",curr);
    }
    return 0;
}
