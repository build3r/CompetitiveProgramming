#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int clen=0,plen=0,n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    if(n==0 && a[0]==0)
        cout<<"0"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
                clen++;
            else
            {
                if(clen>plen)
                {
                    plen=clen;
                    clen=0;
                }
                else
                    clen=0;
            }
        }
        if(plen>clen)
            cout<<plen<<endl;
        else
            cout<<clen<<endl;
    }
    return 0;
}
