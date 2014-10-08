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
            prev=x/gen;
            curr=curr+c/gen;
            gen+=f;
            curr+=x/gen;
            if(curr>prev)
            {
                flag=1;
                curr=prev;
            }
        }
        cout<<curr<<endl;
    }
    return 0;
}
