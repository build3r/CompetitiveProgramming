#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
      int t,i,n,l,p,m,j,k,flag,chk;
    string temp;
    vector<string> curr,need;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        chk=0;
        cin>>n>>l;
        short needi[40]={0},curri[40]={0};

        for(i=0;i<n;i++)
        {
            cin>>temp;
            curr.push_back(temp);
        }
        for(i=0;i<n;i++)
        {
            cin>>temp;
            need.push_back(temp);
        }
        sort(curr.begin(),curr.end());
        sort(need.begin(),need.end());
        j=0;
        for(i=0;i<l;i++)
          {
               memset(needi,0,sizeof(needi));
                memset(curri,0,sizeof(curri));
            flag=0;
            for(k=0;k<n;k++)
                {
                    for(m=0;m<n;m++)
                    if(curr[k][i]==need[m][i] && !needi[k] && !curri[m])
                    {
                        needi[k]=1;
                        curri[m]=1;
                        flag++;
                        break;

                    }
                }
                memset(needi,0,sizeof(needi));
                memset(curri,0,sizeof(curri));
                if(flag<n)
                {
                    flag=0;
            for(p=0;p<n;p++)
            {
                cout<<"curr["<<p<<"] = "<<curr[p]<<"  i=  "<<i<<"curr[p][i]"<<curr[p][0]<<endl;
                if(curr[p][i]=='0')
                curr[p][i]='1';
            else
                curr[p][i+1]='0';
                cout<<"curr["<<p<<"] = "<<curr[p]<<endl;
            }
                for(k=0;k<n;k++)
                {
                    for(m=0;m<n;m++)
                    if(curr[k][i]==need[m][i]  )
                    {
                        if(!needi[k] && !curri[m])
                        {
                        needi[k]=1;
                        curri[m]=1;
                        flag++;
                        break;
                        }
                        else
                        {
                            cout<<"failed bcoz of bit vec\n";
                        }
                    }
                }
                cout<<"flag = "<<flag<<endl;
                if(flag<n)
                {
                    cout<<"Imposiible man\n";
                }
                else
                    {
                        chk++;
                        cout<<"Indirect match\n";
                    }

                }
                else
                    {
                        cout<<"direct match\n";
                        chk++;
                    }
            }
            if(chk==l)
                cout<<"possible chk= "<<chk<<endl;
            else
                cout<<"impossible chk= "<<chk<<endl;


        curr.clear();
        need.clear();
        cout<<endl<<endl;
    }
    return 0;
}
