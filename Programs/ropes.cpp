#include<iostream>
#include<string.h>

using namespace std;
int main()
{
             string s[1000];

             int q;
             int i,j;
             int n;
             cin>>q;
             while(q--)
             {
                          cin>>n;
                          cin.get();

                          for(i=0;i<n;i++)
                          {
                          getline(cin,s[i]);

                          }

                          string t;

                          for(i=0;i<n-1;i++)
                          {
                                       for(j=i+1;j<n;j++)
                                       {
                                                    if((int)(s[i][0])>(int)(s[j][0]))
                                                    {
                                                                 t=s[i];
                                                                 s[i]=s[j];
                                                                 s[j]=t;
                                                    }
                                                    if((int)(s[i][0])==(int)(s[j][0]))
                                                    {
                                                                 if((s[i].size())>(s[j].size()))
                                                                 {
                                                                   t=s[i];
                                                                   s[i]=s[j];
                                                                   s[j]=t;
                                                                   }
                                                                   }

                                       }
                          }
                          for(i=0;i<n;i++)
                          {
                                       cout<<s[i]<<endl;
                          }
             }

                          return 0;
             }


