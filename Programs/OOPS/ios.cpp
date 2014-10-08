#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    bool b=0;
    cout.setf(ios::boolalpha);
    cout<<b<<endl;
  cout.hex;
  cout<<100<<endl;
   cout<<ios::basefield<<101<<endl;
   cout.width(50);
   cout.setf(ios::right);
   cout.fill('#');
   cout<<97<<endl;
  return 0;
}
