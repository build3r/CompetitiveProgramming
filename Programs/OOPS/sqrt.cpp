#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
ostream &fi(ostream &stream)
{
    int i=30;
    while(i--)
    stream<<"*";
    stream<<endl;
    return stream;
}
using namespace std;
int main()
{
    cout<<"Number\t->  sqrt\n"<<fi;
    //cout<<unsetfill;
       for(int i=0;i<11;i++)
   {   cout<<setw(7)<<left<<i;
       cout<<"\t->  "<<sqrt(i)<<endl;
   }
}
