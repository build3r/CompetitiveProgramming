//Sum of array of elements using recursion
#include<iostream>
using namespace std;
int sum(int *k,int n);
int main()
{
    int a[100],n,i=0,f=0;
    cout<<"enter vnumber of elements\n";
    cin>>n;
    while(i++<n)
    cin>>a[i];
    f=sum(a,n);
    cout<<"the sum is:"<<f<<endl;
    return 0;
}
int sum(int *a,int n)
{
    int i=0,s=0;
    i++;
    if(n<=0)
    return s;
    else
    {
       // cout<<"\n  s:"<<s<<"  n:"<<n<<"   a:"<<a[n]<<endl;
    s= a[n] + sum((a++),n-1);
    }
}
