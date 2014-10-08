#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<stdint.h>
#include<unistd.h>
#include<utility>
#include<fstream>
#include<sstream>

#include<stack>
#include<cstdio>
#include<ctime>

using namespace std;
#define x first
#define y second
#define VI vector<int>
#define pii pair<int,int>
#define inf 1000000000
#define L(s) ((int)(s).size())
#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()

typedef int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define N 100
class FastInput
{
public:
    FastInput()
    {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext()
    {
        if (m_dataOffset == m_dataSize)
        {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0')
            {
                if (m_v != 0x80000000)
                {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;)
            {
                if (m_buffer[i] >= '0')
                {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                }
                else
                {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    }
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
FastInput in;
ll T,n,C,p,q,temp;
ll v;
struct Node
{
    int rot[12];
    int rotby;
};
int a[800010];
Node M[4000010];
int str[4];
int tryCount=0;
int rotateQuery(int node, int qi, int qj, int iterator_k, int j,ll c)
{
    if (qj < iterator_k || qi > j)
    {
        cout<<"tuned negative\n";
        c = c -v;
        if(c<0)
        {
            while(c<0)c+=12;
        }
        if(c==0) return 0;

        M[node].rotby = (M[node].rotby + c)%12;
        return 0;
    }
    if (qi <=iterator_k && qj >= j)
    {
        M[node].rotby = (c+M[node].rotby)%12;

    }
    else
    {
        ll mid = (iterator_k + j)>> 1;
        ll left = node*2;
        ll right = left +1;
        ll rotatedby = (c+M[node].rotby)%12;
        rotateQuery(node*2, qi, qj, iterator_k, mid,rotatedby);
        rotateQuery(node*2 + 1, qi, qj, mid + 1, j,rotatedby);
        ll l1 = M[left].rotby;
        ll r1 = M[right].rotby;
        for(int k=0; k<=11; k++)
        {
cout<<" at: "<<iterator_k<<" "<<j<<" "<<M[left].rot[l1]<<" with : "<<M[right].rot[r1]<<endl;
            M[node].rot[k] = max(M[left].rot[l1],M[right].rot[r1]);
            l1++;
            r1++;
            if(l1>=12) l1 -=12;
            if(r1>=12) r1 -=12;
cout<<" at : "<<iterator_k<<" "<<j<<" maxt at : "<<iterator_k<<M[node].rot[k]<<endl;
        }
        M[node].rotby = 0;
    }


}

void turnAround(int naaam,Node &node)
{
    bool flag = false;
    node.rot[0] = naaam;
    if(naaam==0)
    {
        for(int iterator_k=1; iterator_k<=11; iterator_k++) node.rot[iterator_k] = 0;
        return;
    }
    if(naaam<0)
    {
        flag = true;
        naaam = -naaam;
    }

    tryCount = 0;
    while(naaam>0)
    {
        str[tryCount] = naaam%10;
        naaam =naaam/10;
        tryCount++;
    }
    for(int iterator_k=0; iterator_k<=tryCount/2 - 1; iterator_k++)
    {
        swap(str[iterator_k],str[tryCount-iterator_k-1]);
    }
    int rnum = 0;
    for(int iterator_k=1; iterator_k<=11; iterator_k++)
    {
        for(int j=0; j<=tryCount-2; j++)
        {
            swap(str[j],str[j+1]);
        }
        rnum =0;
        for(int j=0; j<=tryCount-1; j++)
        {
            rnum = rnum*10 + str[j];
        }
        if(flag) node.rot[iterator_k] = -rnum;
        else node.rot[iterator_k] = rnum;
cout<<"rot: "<<iterator_k<<" "<<node.rot[iterator_k]<<endl;
    }
}

void init(int node, int iterator_k, int j)
{
 cout<<"node = "<<node<<" itera_k = "<<iterator_k<<" j= "<<j<<endl<<endl;
    if (iterator_k == j)
    {
        turnAround(a[iterator_k],M[node]);
        M[node].rotby = 0;

    }
    else
    {
        ll mid = (iterator_k + j) / 2;
        ll left = node * 2;
        ll right = left + 1;
cout<<" mid = "<<mid<<" left= "<<left<<" right= "<<right<<endl;
        init(left, iterator_k, mid);
cout<<"initializing right\n";
        init(right, mid + 1, j);

//int l1= M[left].rcount,r1 = M[right].rcount;
        for(int cur=0; cur<=11; cur++)
        {
//cout<<" finding max with : "<<M[left].rot[cur%l1]<<" and "<<M[right].rot[cur%12]<<" l1:"<<l1<<" "<<r1<<endl;
            M[node].rot[cur] = max(M[left].rot[cur],M[right].rot[cur]);
cout<<" Maximum at "<<iterator_k<<" "<<j<<" with rot: "<<cur<<" is " <<M[node].rot[cur]<<endl;
        }
        M[node].rotby =0;

    }
}


ll sumQuery(int node,int qi,int qj,int iterator_k,int j,ll c)
{
    if(qj<iterator_k || qi>j)
    {
        return -11111;
    }
    if(qi<=iterator_k && j<=qj)
    {
        return M[node].rot[(M[node].rotby+c)%12] ;
    }
    else
    {
        ll mid = (iterator_k + j) >>1;
        ll net_value = 0;
        net_value = sumQuery(node * 2, qi, qj, iterator_k, mid,c+(ll)M[node].rotby);
        net_value = max(net_value,sumQuery(node * 2 + 1, qi, qj, mid + 1, j,c+(ll)M[node].rotby));
        return net_value;
    }
}
int main()
{
//cin>>n;
//

    scanf("%d",&n);
//n=in.ReadNext();
    for(int iterator_k=0; iterator_k<=n-1; iterator_k++)
    {
        scanf("%d",&a[iterator_k]); //cout<<"arr "<<a[iterator_k]<<endl;
    }
    init(1,0,n-1);
//cout<<sumQuery(1,0,3,0,n-1,0);
    scanf("%d",&C);
//cin>>C;
//C=in.ReadNext();
//cout<<"no of queries "<<C<<endl;
    for(int j=1; j<=C; j++)
    {
//temp=in.ReadNext();
//cout<<"option "<<temp<<endl;
        scanf("%d",&temp);
//cin>>temp;
        if(temp)
        {
//printf("%ll",)
//cin>>p;
//cin>>q;
//p=in.ReadNext();;
//q=in.ReadNext();
//cout<<"q print "<<p<<" q= "<<q<<endl;
            scanf("%d %d",&p,&q);
            printf("%d\n",sumQuery(1,p,q,0,n-1,0));
        }
        else
        {
//cin>>p;
//cin>>q;
//cin>>v;
            scanf("%d %d %d",&p,&q,&v);
//p=in.ReadNext();
//q=in.ReadNext();
//v=in.ReadNext();
//cout<<"rotate q "<<p<<" "<<q<<" "<<v<<endl;
            rotateQuery(1,p,q,0,n-1,v);
//cout<<"processed :"<<j<<endl;
        }
    }


}
