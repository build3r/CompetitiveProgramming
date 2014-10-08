#include <bits/stdc++.h>
using namespace std;

#define FST ios_base::sync_with_stdio(0)
#define INPT int t; cin>>t; while(t--)
#define FOR(i, a, b) for(i = a; i < b ; i++)
#define FORI(it, v) for(it = v.begin(); it != v.end(); it++)
#define VT(t) vector<t>
#define VTI(t) vector<t>::iterator
#define SZ(v) v.size()
#define CLR(v) v.clear()
#define PB(a) push_back(a)
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define MTTI(t1,t2) map<t1,t2>::iterator
#define F(it) it->first
#define S(it) it->second

typedef long long int ll;
int n11,n12,n13,n21,n22,n23,n31,n32,n33,n41,n42,n43,n51,n52,n53,n61,n62,n63;
bool checker[100][100][100];

bool rem1()
{
    if(n11>0)
        {
            n11--;
            return true;
        }
        else
            return false;

}

bool rem2()
{
    if(n12>0)

        {
            n12--;
                    return true;
        }
        else
            return false;

}

bool rem3()
{
    if(n13>0)
       {

        n13--;
                    return true;
        }
        else
            return false;

}

bool rem12()
{
    if(n21>0 && n22>0)
       {

       n21--;

        n22--;
                    return true;
        }
        else
            return false;
}

bool rem22()
{
    if(n23>0 && n22>0)
       {
        n23--;
        n22--;
         return true;
       }
       else
            return false;

}
bool rem32()
{
    if(n23>0 && n21>0)
     {

     n23--;

        n21--;
                 return true;
       }
       else
            return false;
}
bool rem33()
{
        if(n31>0 && n32>0 && n33>0)
       {

        n31--;
        n32--;
        n33--;
                         return true;
       }
       else
            return false;
}
bool willLoose()
{
    printf("n11=%d n12=%d n13=%d && n21=%d n22=%d n23=%d && n31=%d n32=%d n33 = %d\n",n11,n12,n13,n21,n22,n23,n31,n32,n33);
    if(((n11+n12+n13 == 1) && (n21+n22+n23 == 1)) && (n31+n32+n33 == 1))
        return true;
    else
    {
        if(rem1())
        {willLoose();}
        if(rem2())
        willLoose();
        if(rem3())
        willLoose();
        if(rem12())
        willLoose();
        if(rem22())
        willLoose();
        if(rem32())
        willLoose();
        if(rem33())
        willLoose();
    }
    return false;
}
int main()
{
    //FST;
   INPT
    {
        memset(checker,1,sizeof(checker));
        cin>>n11>>n12>>n13;
        n21=n31=n41=n51=n61=n11;
        n22=n32=n42=n52=n62=n12;
        n23=n33=n43=n53=n63=n13;
        if(willLoose())
        {
            cout<<"Aishwarya\n";
        }
        else
        {
            cout<<"Ashima\n";
        }

    }
    return 0;
}


