#include<iostream>
#include<sort>
using namespace std;
int main()
{
    int a[100],n,i;
    cin>>n;
    i=n
    while(i<n)
    a[i]=rand()%100;
    cout<<"The original array is\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
    sort(a.begin(),a.end());
    cout<<"The sorted array is\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
    return 0;
}
