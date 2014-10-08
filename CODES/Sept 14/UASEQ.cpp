#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
vector<bool> opt(100006);
set<int> dset;
map<int,int> dcount;
void updateopt(int a0,int d)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==(a0 + (i-1)*d))
            opt[i]=true;
    }
}



int main()
{
    int k,i,ai,d,fd=99999999,fa=99999999;
    scanf("%d %d",&n,&k);
    //opt.resize(n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
       // cout<<"i = "<<i<<endl;
        if(opt[i]==true)
        {
              //  cout<<"opt true\n";
                continue;
        }
        else
        {
           // cout<<"opt false\n";
            ai=a[i];
            for(int j= i;j<=n;j++)
            {
               // cout<<"j = "<<j<<endl;
                if(i==j) continue;
                int temp=(a[j]-ai);
              // cout<<"temp = "<<temp<<endl;
               if(i==0)
               {
                    dset.insert(temp);
                    dcount[temp] = dcount[temp] + 1;
                    continue;
               }
                if((((temp))%i)==0)
                {
                   // cout<<"temp/j  = "<<temp/j<<endl;
                    dset.insert(temp/(j-i));
                   // cout<<"current counof "<<temp/(j-i) <<"  =  "<<dcount[temp/(j-i)]<<endl;
                      dcount[temp/(j-i)] = dcount[temp/(j-i)] + 1;
                     // cout<<"after counof "<<temp/(j-i) <<"  =  "<<dcount[temp/(j-i)]<<endl;
                }

            }
//            cout<<"first loop done\n";
            for(int j= i;j>0;j--)
            {
//                cout<<"j = "<<j<<endl;
                if(j==i) continue;
                int temp=(ai-a[j]);
//
//                cout<<"2 loop temp = "<<temp<<endl;
                if(j==0)
                {
                    dset.insert(temp);
                    dcount[temp] = dcount[temp] + 1;
                    continue;
                }
                if(((temp)%i)==0)
                {
                   // cout<<"inserting temp/(j-i)"<<temp/(j-i)<<endl;
                    dset.insert(temp/(j-i));

                    dcount[temp/(j-i)] = dcount[temp/(j-i)] + 1;
                }
            }
            for (set<int>::iterator it=dset.begin(); it!=dset.end(); ++it)
            {
//                cout<<"came till set check;\n";
                cout<<"The value of d = " <<(*it)<< " count  "<<dcount[*it]<<endl;
                int req_changes = (n-dcount[*it]-1);
                cout<<"req_changes = "<<req_changes<<endl;
                if(req_changes>k) continue;
                else
                    {
                        int a0 = ai - (i-1)* (*it);
                        if(a0<fa)
                        {
                            fa=a0;
                            fd= (*it);
                           cout<<"updating fa = "<<fa<<"  fd = "<<fd<<endl;
                            updateopt(a0, (*it));
                        }
                        else if(a0 == fa)
                        {
                            if(fd> (*it))
                                {
                                    fd = (*it);
                                   cout<<"updating fa = "<<fa<<"  fd = "<<fd<<endl;
                                    updateopt(a0, (*it));
                                }
                        }
                    }
            }
            dcount.clear();
            dset.clear();
        }

    }
    for(int i=1;i<=n;i++)
        printf("%d ",(fa+(i-1)*fd));
    printf("\n");
    return 0;

}
