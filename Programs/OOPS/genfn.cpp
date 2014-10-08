#include<iostream>
using namespace std;
template <class x>
void com(x *a,int c,int b,int e)
{
    int i=0;
    for(i=e+1;i<c;i++,b++)
    a[b]=a[i];
    for(;b<c;b++)
    a[b]=(x)0;
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    double b[10]={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
    cout<<"Original int array\n";
    for(int i=0;i<10;i++)
    cout<<a[i]<<' ';
    com(a,10,4,8);
    cout<<"\nThe compacted array of ints is\n";
    for(int i=0;i<10;i++)
    cout<<a[i]<<' ';
    cout<<showpoint;
    cout<<"\nOriginal double array\n";
    for(int i=0;i<10;i++)
    cout<<b[i]<<' ';
    com(b,10,2,8);
    cout<<"\nThe compacted array of doubles is\n";
    for(int i=0;i<10;i++)
    cout<<b[i]<<" ";
    return 0;
}
