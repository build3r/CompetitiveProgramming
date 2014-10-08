//Sum of array of elements using recursion
#include<iostream>
using namespace std;
int sum(int *k,int n);
int main()
{
    int a[100],n,i=0;
    cout<<"enter vnumber of elements\n";
    cin>>n;
    while(i++<n)
    cin>>a[i];
    i=sum(a,n);
    cout<<"the sum is:"<<i<<endl;
    return 0;
}

int sum(int *a,int n)
{
    int i=0,s=0;
    if(i==n)
    return s;
    else
    s=s+(k+(i++));
}
