#include<iostream>
using namespace std;
int main()
{
    char s[50][50];
    int t,i,j,k,mi,r,c,co=0;;
    cin>>t;
    while(t--)
    {
        mi=co=0;
        cin>>r>>c;
        for(i=1;i<=r;i++)
            cin>>s[i];
        for(i=2;i<r;i++)
        for(j=2;j<c;j++)
        {
            mi=0;
            k=j-1;
            while(k!=0 && s[i][k]!='#')
            {mi++;
             k--;
            }
            if(mi<=1)
                continue;
                mi=0;
            k=j+1;
            while(k!=c+1 && s[i][k]!='#')
            {
                mi++;

                k++;
            }
            if(mi<=1)
                continue;
            k=i-1;
            mi=0;
            while(k!=0 && s[k][j]!='#')
            {
                mi++;
                k--;
            }
             if(mi<=1)
                continue;
                mi=0;
            k=i+1;
            while(k!=r+1 && s[k][j]!='#')
            {
                mi++;
                k++;
            }
             if(mi<=1)
                continue;
                co++;
        }
        cout<<co<<endl;
    }
    return 0;
}
