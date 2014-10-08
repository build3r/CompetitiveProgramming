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
    //cout<<"Enter the sequence\n";

    cin>>x;
    for(i=0;x[i]!='\0';i++)
    {
        if(x[i]=='0') zc++;
        else oc++;
    }
    cout<<"zc:"<<zc<<" oc:"<<oc<<endl;
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
                if(zero==0)
                    lastzero.push(i);
                else
                {
                    x[i]='0';
                    zero--;
                }
                if(!lastone.empty())
                {
                    j=lastone.front();
                    lastone.pop();
                    x[j]='1';
                    //lastone.push(i);
                }
                else
                    one++;
            }
        }
        else
        {
            if(x[i]=='1' )
            {
                if(!lastone.empty())
                {
                    int j=lastone.front();
                    lastone.pop();
                    x[j]='1';
                    lastone.push(i);
                }

            }
            else
            {
                if(one==0)
                    lastone.push(i);
                else
                {
                    x[i]='1';
                    one--;
                }
                if(!lastzero.empty())
                {
                    j=lastzero.front();
                    lastzero.pop();
                    x[j]='0';
                    //lastzero.push(i);
                }
                else
                    zero++;
            }
        }
    }
    for(j=i-zero-1;x[j]!='\0';j++)
        x[j]='0';
     for(j=i-one;x[j]!='\0';j++)
        x[j]='1';
   /* zc=0;oc=0;
    for(i=0;x[i]=='0'||x[i]=='1';i++)
    {
        if(x[i]=='0') zc++;
        else oc++;
    }*/
    //cout<<"one:"<<one<<" zero:"<<zero<<endl;
    //for(i=1;x[i-1]!='\0';i++)
      //  cout<<i;
    cout<<endl;
    cout<<x<<endl<<endl;
    }
    return 0;
}
