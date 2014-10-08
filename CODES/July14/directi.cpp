#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<list>
#include<algorithm>
#define SIZE 10
using namespace std;


void fill_map(int wt[],int start,int last,int sum,map<int,int> &m)
{
    if(start > last)
    return;
    int i;
    for(i = start; i <= last; i++)
    {
        m[sum+wt[i]] = i;
        fill_map(wt,i+2,last,sum+wt[i],m);
    }
}

void find_combination(int w)
{
    int wt[SIZE],i,sum1,sum2;
    wt[0] = 1;
    wt[1] = 3;
    for(i = 2; i < SIZE; i++)
    wt[i] = 2*wt[i-1] + wt[i-2];
    map<int,int>m;
    list<int>l;
    fill_map(wt,0,SIZE-1,0,m);
    map<int,int>::iterator it;
    map<int,int>::iterator ip;
    it = m.find(w);
    if(it != m.end())
    {
         sum1 = w;
        while(sum1)          //sum not zero
        {
        l.push_front(m[sum1]);
        sum1 -= wt[m[sum1]];
        }
        //now display and return
        while(!l.empty())
        {
            cout<<wt[l.front()]<<endl;
            l.pop_front();
        }
        return;
    }

    it = m.begin();
    while(it != m.end())
    {
        sum1 = it->first;          //this goes on right pan along with given weight w
        ip = m.find(w+sum1);    //check if we have w+sum1 in the map
        if(ip != m.end())
        {
            //first print for sum2
            sum2 = w+sum1;
            while(sum2)
            {
                l.push_front(m[sum2]);
                sum2 -= wt[m[sum2]];
            }
            while(!l.empty())
            {
                cout<<wt[l.front()]<<endl;
                l.pop_front();
            }
            //now do for right pane that has w already
            while(sum1)
            {
                l.push_front(m[sum1]);
                sum1 -= wt[m[sum1]];
            }
            while(!l.empty())
            {
                cout<<endl<<wt[l.front()];
                l.pop_front();
            }
            return;      //we are done
        }
        it++;      //else proceed to next
    }

}
int main()
{
    find_combination(100);
}
