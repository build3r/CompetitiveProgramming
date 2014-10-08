#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    bool b=1;
    cout<<boolalpha<<b<<endl;
    cout<<hex<<100<<endl;
    cout<<showbase<<100<<endl;
    cout<<dec<<noshowbase<<setw(10)<<right<<99<<endl;
    cout<<setw(10)<<left<<setfill('*')<<100<<endl;
    cout<<scientific<<100.12<<endl;
    //cout<<showpos<<showpoint<<100<<endl;
    cout<<uppercase<<100.12<<endl;
    cout<<setiosflags(ios::showbase);
    cout<<hex<<101;
    return 0;
}
