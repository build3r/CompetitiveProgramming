#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int t=100;
    while(t--){
    queue<int> lastone,lastzero;
    char x[100];
    int zero=0,one=0,i,j,zc=0,oc=0;
    cin>>x;
    for(i=0;x[i]!='\0';i++)
        {if(x[i]=='0')
        zc++;
    else
        oc++;
        }

        cout<<"zero's="<<zc<<"\tone's="<<oc<<endl;
        for(i=0;x[i]!='\0';i++)
        {
            if(i%2==0)
            {
                if(x[i]=='0')
                {
                    if(!lastzero.empty())
                    {
                        j=lastzero.front();
                        lastzero.pop();
                        x[j]='0';
                        lastzero.push(i);
                    }
                }
                else
                {

                     if(!lastone.empty())
                    {
                    j=lastone.front();
                    lastone.pop();
                    x[j]='1';
                    }
                    else
                        one++;
                    if(zero==0)
                    lastzero.push(i);
                    else{
                        x[i]='0';
                        zero--;
                    }
            }
        }
        else
        {
            if(x[i]=='1')
            {
                if(!lastone.empty())
                {
                    j=lastone.front();
                    lastone.pop();
                    x[j]='1';
                    lastone.push(i);
                }
                if(zero>0)
                {
                    x[i]='0';
                    zero--;
                }

            }
            else
            {
                 if(!lastzero.empty())
                {
                    j=lastzero.front();
                    lastzero.pop();
                    x[j]='0';
                    //lastzero.push(i);
                }
                else
                    zero++;

                if(one>0)
                {
                    x[i]='1';
                    one--;
                }
                else
                    lastone.push(i);

            }
            }

    }
    cout<<x<<endl<<endl;

}
return 0;
}
