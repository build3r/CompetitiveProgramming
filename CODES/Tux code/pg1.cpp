#include<iostream>
#include<algorithm>
using namespace std;
void sor(int &a);
int main()
{
    long int a[10][15],t,i,j,mi=99999999,ind,bal;
    cin>>t;
    while(t--)
    {
        mi=99999999;
        for(i=0;i<10;i++)
            {for(j=0;j<15;j++)
            {cin>>a[i][j];

            }
                long int l;
    for(int m=0;m<15;m++)
        for(int n=m+1;n<15;n++)
    {
        if(a[i][m]>a[i][n])
        {
          l=a[i][m];
          a[i][m]=a[i][n];
          a[i][n]=l;
        }
    }
            }

            for(i=0;i<10;i++)
            {
//                cout<<"a[i][14] a[i][0]   "<<a[i][14]<<"   "<<a[i][0]<<endl;
                if((a[i][14]-a[i][0])<=mi)
                {

                    mi=bal=(a[i][14]-a[i][0]);
                    ind=i+1;
                }
            }

            cout<<ind<<" "<<bal<<endl;


    }
    return 0;
}

