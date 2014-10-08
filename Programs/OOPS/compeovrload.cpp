#include<iostream>
using namespace std;
class comp
{
    int r,i;
    public:
    friend istream &operator>>(istream &shab,comp &x);
    friend comp operator+(comp &,comp &);
    friend ostream &operator<<(ostream &shab,comp &x);
};
istream &operator>>(istream &shab,comp &x)
{
    cout<<"enter real and imaginary part\n";
    shab>>x.r>>x.i;
    return shab;
}
ostream &operator<<(ostream &shab,comp &x)
{
    cout<<"complex number is\n";
    shab<<x.r<<"+i"<<x.i<<endl;
    return shab;
}

comp operator+(comp &x,comp &y)
{
    comp temp;
    temp.r=x.r+y.r;
    temp.i=x.i+y.i;
    return temp;
}
int main()
{
    comp t1,t2,t3;
    cin>>t1;
    cin>>t2;
    cout<<t1;
    cout<<t2;
    t3=t1+t2;
    cout<<t3;
    return 0;
}
