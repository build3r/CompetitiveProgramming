#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int t,l1,f,l2,i,j;
    char s3[16],s1[16],s2[16];
    cin>>t;
    while(t--)
    {
        f=0;
        cin>>s1>>s2;
        l1=strlen(s1);
        l2=strlen(s2);
        if(strcmp(s1,s2)==0)
        {
            cout<<"YES\n";
            continue;
        }
        if(l1!=l2)
        {
            cout<<"NO\n";
            continue;
        }
        for(i=1;i<l1;i++)
        {
            int k=0;
            for(j=i;j<l1;j++)
                s3[k++]=s1[j];
                for(j=0;j<i;j++)
                s3[k++]=s1[j];
            s3[k]='\0';
            if(strcmp(s2,s3)==0)
            {
                cout<<"YES\n";
                f=1;
                break;
            }
        }
        if(!f)
            cout<<"NO\n";
    }
    return 0;
}
