#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int i,j=0,n,len=0,k=0;
    string a,b,c;
    scanf("%d",&n);
    cin>>a;
    cin>>b;
    b=b+b;
    len=a.length();
    if(n<10000){
    for(i=1;i<len;i++)
    {

        {c=a.substr(0,i);
        k=j;
        j=b.find(c);
        if(j==string::npos)
        {
            printf("%d\n",k);
            break;
        }
        }

    }
    }
    else
    {
        for(i=len;i>0;i--)
        {
            c=a.substr(0,i);
            j=b.find(c);
        if(j!=string::npos)
        {
            printf("%d\n",j);
            break;
        }
        }
    }
    return 0;

}
