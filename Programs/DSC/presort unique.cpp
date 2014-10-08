#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[10000],n,i;
    cout<<"Enter th numer of elemts\n";
    time_t(seed);
    cin>>n;
    i=0;
    while(i<n)
    a[i++]=rand()%100;
    cout<<"The original array is\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
    sort(a,a+n);
    //cout<<"\nThe sorted array is\n";
    //for(i=0;i<n;i++)
   // cout<<a[i]<<"\t";
    for(i=0;i<n-2;i++)
    if(a[i]==a[i+1])
    {
        cout<<"\nArray is not unique\n";
        goto out;
    }
    cout<<"\nThe arrray is unique\n";
    out:
    return 0;
}
