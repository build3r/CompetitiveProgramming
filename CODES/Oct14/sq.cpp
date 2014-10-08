#include <bits/stdc++.h> /* build3r */

#define ll int
using namespace std;
#define gc getchar//_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = gc());
    if(c=='-')
    {
        neg=1;
        c=gc();
    }
    for(; c>47 && c<58; c = gc())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x=-x;
}
vector<ll>posn[1000005];
vector<ll>posp[1000005];
bool search(ll x, ll y)
{
    if(x>=0)
    {
        ll mid, left = 0 ;
        if(x>1000000)
            return false;
        ll right = posp[x].size();
        while (left < right)
        {
            mid = left + (right - left)/2;
            if (y > posp[x][mid])
            {
                left = mid+1;
            }
            else if (y < posp[x][mid])
            {
                right = mid;
            }
            else
            {
                return true;
            }
        }
    }
    else
    {
        ll mid, left = 0 ;
        if((x*(-1))>1000000)
            return false;
        ll right = posn[x*(-1)].size();
        while (left < right)
        {
            mid = left + (right - left)/2;
            if (y > posn[x*(-1)][mid])
            {
                left = mid+1;
            }
            else if (y < posn[x*(-1)][mid])
            {
                right = mid;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    ll t,n,k,l,i,j,m,step,temp,sum;
    scanint(n);
    if(n==0)
        printf("4");
    else if(n==1)
    {
        ll x[n];
        ll y[n];
        scanint(x[0]);
        scanint(y[0]);
        printf("3");
    }
    else if(n>=2)
    {
        ll x[n+1];
        ll y[n+1];
        for(i=0; i<n; i++)
        {
            scanint(x[i]);
            scanint(y[i]);
            ll flag;
            if(x[i]>=0)
            {
                flag=0;
                posp[x[i]].push_back(y[i]);
                j=posp[x[i]].size()-1;
            }
            else
            {
                flag=1;
                posn[x[i]*(-1)].push_back(y[i]);
                j=posn[x[i]*(-1)].size()-1;
            }
            if(flag==1)
            {
                while(j>0)
                {
                    if(posn[x[i]*(-1)][j]<posn[x[i]][j-1])
                    {
                        temp=posn[x[i]*(-1)][j-1];
                        posn[x[i]*(-1)][j-1]=posn[x[i]*(-1)][j];
                        posn[x[i]*(-1)][j]=temp;
                    }
                    else
                        break;
                    j--;
                }
            }
            else
            {
                while(j>0)
                {
                    if(posp[x[i]][j]<posp[x[i]][j-1])
                    {
                        temp=posp[x[i]][j-1];
                        posp[x[i]][j-1]=posp[x[i]][j];
                        posp[x[i]][j]=temp;
                    }
                    else
                        break;
                    j--;
                }
            }
        }
//        for(i=0;i<n;i++)
//        {
//
//        }
        ll modx,mody;
        ll flag=0;
        ll counter=2;
        ll a,b,c,d,e,f;
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                modx=x[j]-x[i];
                mody=y[j]-y[i];
                a=search(x[i]-mody,y[i]+modx);
                b=search(x[j]-mody,y[j]+modx);
                c=search(x[i]+mody,y[i]-modx);
                d=search(x[j]+mody,y[j]-modx);
                if((a==1 && b==1)||(c==1 && d==1))
                {
                    flag=1;
                    counter=4;
                    break;
                }
                else if(a==1||b==1||c==1||d==1)
                {
                    counter=3;
                }
                if((modx%2==0 && mody%2==0)||((modx%2==1 && mody%2==1)))
                {
                    e=search((x[i]+x[j]-mody)/2,(y[i]+y[j]+modx)/2);
                    f=search((x[i]+x[j]+mody)/2,(y[i]+y[j]-modx)/2);
                    if(e==1 && f==1)
                    {
                        flag=1;
                        counter=4;
                        break;
                    }
                    else if(e==1||f==1)
                    {
                        counter=3;
                    }
                }
            }
            if(flag==1)
                break;
        }
        printf("%d",4-counter);
    }
    return 0;
}
