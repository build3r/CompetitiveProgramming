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
#define gc getchar_unlocked
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,n) for(int i=(0);i<(n);i++)
#define TR(v,it) for(typeof(v.begin()) it(v.begin()) ; it != v.end() ; it++)
#define SZ(v) ((int)(v.size()))
#define CLEAR(a) memset((a),0,sizeof(a))
#define S(n) scanf("%d", &n)
#define P(k) printf("%d\n", k)
#define fastS(n) scanint(&n)
#define pb push_back
#define mp make_pair
//#define ll uint32_t
#define VI vector<int>
#define PII pair<int, int>
#define ft first
#define sd second
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define inf (1<<30)
#define PNL printf("\n")
#define md 1299689
#define bigger(a,b) (a>b?a:b)
#define smaller(a,b) (a<b?a:b)
#define positive(a) (bigger(a,-a))


//WHOSOEVER READING IT: IGNORE THE I/O
//I/O Source: http://discuss.codechef.com/questions/870/alternative-to-using-printf-repeatedly
//IO STARTS

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
class FastOutput
{
public:
    FastOutput()
    {
        m_dataOffset = 0;
    }
    ~FastOutput()
    {
    }
    void Flush()
    {
        if (m_dataOffset)
        {
            if (write(1, m_data, m_dataOffset));
            m_dataOffset = 0;
        }
    }
    void PrintUint(uint32_t v, char d)
    {
        if (m_dataOffset + 11 > sizeof(m_data)) Flush();
        if (v < 100000)
        {
            if (v < 1000)
            {
                if (v < 10)
                {
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 1;
                }
                else if (v < 100)
                {
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 2;
                }
                else
                {
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 3;
                }
            }
            else
            {
                if (v < 10000)
                {
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 4;
                }
                else
                {
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 5;
                }
            }
        }
        else
        {
            if (v < 100000000)
            {
                if (v < 1000000)
                {
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 6;
                }
                else if (v < 10000000)
                {
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 7;
                }
                else
                {
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 8;
                }
            }
            else
            {
                if (v < 1000000000)
                {
                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 9;
                }
                else
                {
                    m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 10;
                }
            }
        }
        m_data[m_dataOffset++] = d;
    }
    void PrintChar(char d)
    {
        if (m_dataOffset + 1 > sizeof(m_data)) Flush();
        m_data[m_dataOffset++] = d;
    }
    void PrintStr(int i)
    {
        if(i==0)
        {
            PrintChar('N');
            PrintChar('o');
        }
        else
        {
            PrintChar('Y');
            PrintChar('e');
            PrintChar('s');
        }
        PrintChar('\n');
    }
    void ReplaceChar(int offset, char d)
    {
        m_data[m_dataOffset + offset] = d;
    }
public:
    uint8_t m_data[3268];
    size_t m_dataOffset;
};

//I/O Ends


//FastInput g_fi;
FastInput gin;
long long int pointer[800002];
char str[800002][10];
int main()
{
    long long int n,i,j,mx,q,c,l,r,f,k,len;
    int val1;
    char s[10];
   // n=gin.ReadNext();
    memset(pointer,0,sizeof(pointer));
//cout<<"n= "<<n<<endl;
//cout<<"n = "<<n<<endl;
scanf("%lld",&n);

    for(i=0; i<n-1; i++)
    {
       // cin>>str[i];
scanf("%s ",str[i]);
// cout<<" s "<<i<<" ="<<str[i]<<endl;
    }
    scanf("%s",str[n-1]);
   // q=gin.ReadNext();
// cout<<"q = "<<q<<endl;
scanf("%lld",&q);
    while(q--)
    {
        c=gin.ReadNext();
//scanf("%lld %lld %lld",&c,&l,&r);
        if(c==0)
        {
//scanf("%lld",&f);

            l=gin.ReadNext();
            r=gin.ReadNext();
           f=gin.ReadNext();
            for(i=l; i<=r; i++)
            {
                pointer[i]=(pointer[i]+f) % strlen(str[i]);
//cout<<"ponter of "<<i<<" at = "<<pointer[i]<<endl;
            }
        }
        else
        {
            mx=0;
            l=gin.ReadNext();
            r=gin.ReadNext();
//cout<<"\ncurret Array: \n";
            for(i=l; i<=r; i++)
            {
//len=strlen(str[i]);
                val1=0ll;
            for(j=pointer[i]; str[i][j]!='\0'; j++)
                {

                        val1*=10ll;
                    val1+=str[i][j]-'0';
                }
                for(j=0; j<pointer[i]; j++)
                    {
                        val1*=10ll;
                        val1+=str[i][j]-'0';
                    }
//while(()!='\0');
               /* for(j=pointer[i]; str[i][j]!='\0'; j++)
                {
                    s[k++]=str[i][j];

                }
//cout<<"half parth = "<<s<<endl;
// k--;
                for(j=0; j<pointer[i]; j++)
                    s[k++]=str[i][j];
                s[k]='\0';
//cout<<"shifted S = "<<s<<endl;
                val1=atoi(s);
//cout<<val1<<endl;*/
                if(val1>mx)
                    mx=val1;

            }
            printf("%lld\n",mx);
        }
    }
// int value = atoi(myString); //value = 45
//cout<<"value "<<value<<endl;
    return 0;
}
