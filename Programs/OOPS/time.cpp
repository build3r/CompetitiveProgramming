#include<iostream>
using namespace std;
class time
{
    int h,m,s;
    public:
    time(){h=m=s=0;}
    time(int i,int j,int k)
    {
        h=i;
        m=j;
        s=k;
    }
    time add(time t1,time t2)
    {
        time temp;
        temp.s=(t1.s+t2.s)%60;
        temp.m=((t1.m+t2.m)%60)+((t1.s+t2.s)/60);
        temp.h=t1.h+t2.h+(t1.m+t2.m)/60;
        return temp;
    }
    void dis()
    {
        cout<<"Toatal time is\n";
        cout<<"HOUR:MIN:SEC\n";
        cout<<"  "<<h<<":"<<m<<":"<<s<<endl;
    }
};

int main()
{
    time t1(5,57,35),t2(4,4,35),t3;
    t3=t3.add(t1,t2);
    t3.dis();
    return 0;
}
