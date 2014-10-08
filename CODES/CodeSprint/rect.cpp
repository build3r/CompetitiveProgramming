#include<bits/stdc++.h>
using namespace std;
int getDistance(int x1, int y1, int x2, int y2)
{
    int temp = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return temp;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    int x,y,x1,y1,x2,y2,test;
    cin>>test;
    while(test--)
    {
        int ans[4],mi=0;
        cin>>x>>y>>x1>>y1>>x2>>y2;

                    ans[0] = abs(y1-y);//getDistance(x,y,x,y1);
                    ans[1] = abs(y2-y);//getDistance(x,y,x,y2);
                ans[2] = abs(x1-x);//getDistance(x,y,x,y1);
                ans[3] = abs(x2-x);//getDistance(x,y,x,y2);
            //sort(ans,ans,ans+3);
            mi = ans[0];
            for(int i=1;i<3;i++)
            {
                if(ans[i]<mi)
                    mi=ans[i];
            }
            cout<<mi<<endl;

    }
    return 0;
}
