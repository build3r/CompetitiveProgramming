#include<bits/stdc++.h>
#include<unordered_set>//fetch in O(1)
#define MAX 100005
#define MAX2 200005
#define MAXX 200010
#define MAXX2 200010
using namespace std;
typedef long long LL;
unordered_map<LL,int> tlbitmap,tlbitmap2,tlbitmap3,tlbitmap4;
int Xqueryarr1[MAX],Xqueryarr2[MAX],Yqueryarr1[MAX],Yqueryarr2[MAX],arrayX[MAX2],arrayY[MAX2];
int ix1arr[MAX],ix2arr[MAX],iy1arr[MAX],iy2arr[MAX],indxarr[MAX],mapindx[MAX],total[MAX];
int lbit[MAX2],rbit[MAX2],tim[MAX];
int dbit[MAX2],ubit[MAX2];
int x1,x2,Y1,Y2,indx,numi=0,numq=0,numd=0,ttl,ch1,ch2,ch3;
int q;
char c;
inline void scan(int *a)
{
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
inline void Write(int a)
{
    char snum[20];
    LL i=0;
    do
    {
        snum[i++]=a%10+48;
        a=a/10;
    }
    while(a!=0);
    i=i-1;
    while(i>=0)
        putchar(snum[i--]);
    putchar('\n');
}
bool cmp1(pair<int,int> a,pair<int,int> b)
{
    return (a.first < b.first);
}

inline int bsrch(int l,int r, int q, int* array)
{
    int strt = l, end = r,mid;

    while (strt < end)
    {
        mid = ((strt + end+1)>>1);

        if (q > array[mid])
            strt = mid;
        else if(q <= array[mid])
            end = mid -1;
    }
    return (strt+1);
}

inline void Update(int x, int* bit,int val) // add 1 from x to n
{
    while (x <= (2*MAX -3))
    {
        // cout<<1;
        bit[x] += val;
        x += (x&(-x));
    }
}

inline int Query(int x, int * bit) // value at x
{

    int ans = 0;
    while(x>0)
    {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

inline int TDQuery(int x, int y)
{
    int ans = 0,z;
    while(x>0)
    {
        z=y;
        while (z>0)
        {
            ans += tlbitmap[MAXX*x + z];
            z -= (z&(-z));
        }

        x -= (x&(-x));
    }
    return ans;
}

inline void TDUpdate(int x, int y, int val)
{
    int z;
    while (x <= (2*MAX -3))
    {
        z=y;
        while(z <= (2*MAX - 3))
        {
            tlbitmap[MAXX*x + z] += val;
            z += (z&(-z));
        }
        x += (x&(-x));
    }

}

inline int TDQuery2(int x, int y)
{
    int ans = 0,z;
    while(x>0)
    {
        z=y;
        while (z>0)
        {
            ans += tlbitmap2[MAXX*x + z];
            z -= (z&(-z));
        }

        x -= (x&(-x));
    }
    return ans;
}

inline void TDUpdate2(int x, int y, int val)
{
    int z;
    while (x <= (2*MAX -3))
    {
        z=y;
        while(z <= (2*MAX - 3))
        {
            tlbitmap2[MAXX*x + z] += val;
            z += (z&(-z));
        }
        x += (x&(-x));
    }

}

inline int TDQuery3(int x, int y)
{
    int ans = 0,z;
    while(x>0)
    {
        z=y;
        while (z>0)
        {
            ans += tlbitmap3[MAXX*x + z];
            z -= (z&(-z));
        }

        x -= (x&(-x));
    }
    return ans;
}

inline void TDUpdate3(int x, int y, int val)
{
    int z;
    while (x <= (2*MAX -3))
    {
        z=y;
        while(z <= (2*MAX - 3))
        {
            tlbitmap3[MAXX*x + z] += val;
            z += (z&(-z));
        }
        x += (x&(-x));
    }

}

inline int TDQuery4(int x, int y)
{
    int ans = 0,z;
    while(x>0)
    {
        z=y;
        while (z>0)
        {
            ans += tlbitmap4[MAXX*x + z];
            z -= (z&(-z));
        }

        x -= (x&(-x));
    }
    return ans;
}

inline void TDUpdate4(int x, int y, int val)
{
    int z;
    while (x <= (2*MAX -3))
    {
        z=y;
        while(z <= (2*MAX - 3))
        {
            tlbitmap4[MAXX*x + z] += val;
            z += (z&(-z));
        }
        //bit[x] += val;
        x += (x&(-x));
    }

}
inline void BOTTOMLEFT()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] += TDQuery(Xqueryarr1[ch1]-1,Yqueryarr1[ch1]-1);
            ch1++;
        }
        else if(tim[i]==1)
        {
            TDUpdate(ix2arr[ch2],iy2arr[ch2],1);
            ch2++;
        }
        else
        {
            TDUpdate(ix2arr[indxarr[ch3]],iy2arr[indxarr[ch3]],-1);
            ch3++;
        }
    }
}

inline void BOTTOMRIGHT()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] += TDQuery2(MAX - Xqueryarr2[ch1]-1,Yqueryarr1[ch1]-1);
            ch1++;
        }
        else if(tim[i]==1)
        {
            TDUpdate2(MAX - ix1arr[ch2],iy2arr[ch2],1);
            ch2++;
        }
        else
        {
            TDUpdate2(MAX - ix1arr[indxarr[ch3]], iy2arr[indxarr[ch3]],-1);
            ch3++;
        }
    }
}

inline void TOPRIGHT()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] += TDQuery3(MAX - Xqueryarr2[ch1]-1,MAX - Yqueryarr2[ch1] - 1);
            ch1++;
        }
        else if(tim[i]==1)
        {
            TDUpdate3(MAX - ix1arr[ch2], MAX - iy1arr[ch2],1);
            ch2++;
        }
        else
        {
            TDUpdate3(MAX - ix1arr[indxarr[ch3]], MAX - iy1arr[indxarr[ch3]],-1);
            ch3++;
        }
    }
}

inline void TOPLEFT()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] += TDQuery4(Xqueryarr1[ch1]-1,MAX - Yqueryarr2[ch1]-1);
            ch1++;
        }
        else if(tim[i]==1)
        {
            TDUpdate4(ix2arr[ch2],MAX - iy1arr[ch2],1);
            ch2++;
        }
        else
        {
            TDUpdate4(ix2arr[indxarr[ch3]], MAX - iy1arr[indxarr[ch3]],-1);
            ch3++;
        }
    }
}

inline void LEFTMINUS()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] -= Query(Xqueryarr1[ch1]-1,lbit);
            ch1++;
        }
        else if(tim[i]==1)
        {
            Update(ix2arr[ch2],lbit,1);
            ch2++;
        }
        else
        {
            Update(ix2arr[indxarr[ch3]],lbit,-1);
            ch3++;
        }
    }
}

inline void RIGHTMINUS()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] -= Query(MAX - Xqueryarr2[ch1] - 1,rbit);
            ch1++;
        }
        else if (tim[i]==1)
        {
            Update(MAX - ix1arr[ch2],rbit,1);
            ch2++;
        }
        else
        {
            Update(MAX - ix1arr[indxarr[ch3]],rbit,-1);
            ch3++;
        }
    }
}

inline void DOWNMINUS()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] -= Query(Yqueryarr1[ch1]-1,dbit);
            ch1++;
        }
        else if(tim[i]==1)
        {
            Update(iy2arr[ch2],dbit,1);
            ch2++;
        }
        else
        {
            Update(iy2arr[indxarr[ch3]],dbit,-1);
            ch3++;
        }
    }
}

inline void TOPMINUS()
{
    ch1=1,ch2=1,ch3=1;
    for(int i=1; i<=q; i++)
    {
        if (tim[i]==3)
        {
            total[ch1] -= Query(MAX - Yqueryarr2[ch1] - 1,ubit);
            ch1++;
        }
        else if (tim[i]==1)
        {
            Update(MAX - iy1arr[ch2],ubit,1);
            ch2++;
        }
        else
        {
            Update(MAX - iy1arr[indxarr[ch3]],ubit,-1);
            ch3++;
        }
    }
}




int main()
{
    //cin>>q;
    //scan(&q);
ios_base::sync_with_stdio(false);
    scanf("%d",&q);
    ttl=0;
    for (int i=0; i<=MAX2; i++)
    {
        lbit[i] = rbit[i] = dbit[i] = ubit[i] = 0;
    }
   //cout<<"dff\n";
    for (int i=1; i<=q; i++)
    {
        //scanf("%c ",&c);
        //c=getchar();
        cin>>c;
        //cout<<"gh\n";
        if (c=='I')
        {
            tim[i]=1;
            ttl++;
            numi++;
            scan(&ix1arr[numi]);
            scan(&iy1arr[numi]);
            scan(&ix2arr[numi]);
            scan(&iy2arr[numi]);
            //cin>>x1>>Y1>>x2>>Y2;
            arrayX[(numi<<1)+(numq<<1)-1] = ix1arr[numi];
            arrayX[(numi<<1)+(numq<<1)] = ix2arr[numi];
            arrayY[(numi<<1)+(numq<<1)-1] = iy1arr[numi];
            arrayY[(numi<<1)+(numq<<1)] = iy2arr[numi];
            mapindx[i] = numi;
        }
        else if (c=='D')
        {
            tim[i]=2;
            ttl--;
            numd++;
            scan(&indx);
            //cin>>indx;
            indxarr[numd] = mapindx[indx];
        }
        else
        {
            tim[i]=3;
            numq++;
            total[numq] =ttl;

            scan(&Xqueryarr1[numq]);
            scan(&Yqueryarr1[numq]);
            scan(&Xqueryarr2[numq]);
            scan(&Yqueryarr2[numq]);
            //cin>>x1>>Y1>>x2>>Y2;
            arrayX[(numi<<1)+(numq<<1)-1] = Xqueryarr1[numq];
            arrayX[(numi<<1)+(numq<<1)] = Xqueryarr2[numq];
            arrayY[(numi<<1)+(numq<<1)-1] = Yqueryarr1[numq];
            arrayY[(numi<<1)+(numq<<1)] = Yqueryarr2[numq];
        }
    }

    sort(arrayX+1,arrayX + (numi<<1) + (numq<<1)+1);
    sort(arrayY+1,arrayY + (numi<<1) + (numq<<1)+1);

    for (int i=1; i<=numi; i++)
    {
        ix1arr[i] = bsrch(0,(numi<<1)+(numq<<1),ix1arr[i],arrayX);
        ix2arr[i] = bsrch(0,(numi<<1)+(numq<<1),ix2arr[i],arrayX);
        iy1arr[i] = bsrch(0,(numi<<1)+(numq<<1),iy1arr[i],arrayY);
        iy2arr[i] = bsrch(0,(numi<<1)+(numq<<1),iy2arr[i],arrayY);
    }
    for (int i=1; i<=numq; i++)
    {
        Xqueryarr1[i] = bsrch(0,(numi<<1)+(numq<<1),Xqueryarr1[i],arrayX);
        Xqueryarr2[i] = bsrch(0,(numi<<1)+(numq<<1),Xqueryarr2[i],arrayX);
        Yqueryarr1[i] = bsrch(0,(numi<<1)+(numq<<1),Yqueryarr1[i],arrayY);
        Yqueryarr2[i] = bsrch(0,(numi<<1)+(numq<<1),Yqueryarr2[i],arrayY);
    }
    //LEFT-MINUS
    LEFTMINUS();
    //RIGHT-MINUS
    RIGHTMINUS();
    //DOWN-MINUS
    DOWNMINUS();
    //TOP-MINUS
    TOPMINUS();
    //BOTTOM-LEFT
    tlbitmap.rehash(1000000);
    tlbitmap2.rehash(1000000);
    tlbitmap3.rehash(1000000);
    tlbitmap4.rehash(1000000);
    tlbitmap.reserve(200009);
    tlbitmap2.reserve(200009);
    tlbitmap3.reserve(200009);
    tlbitmap4.reserve(200009);
    // tlbitmap.clear();
    BOTTOMLEFT();
    //BOTTOM-RIGHT
    //tlbitmap.clear();
    BOTTOMRIGHT();
    //TOP-LEFT
    //tlbitmap.clear();
    TOPLEFT();
    //TOP-RIGHT
    //tlbitmap.clear();
    TOPRIGHT();
    // test1();

    for (int i=1; i<=numq; i++)
    {
        Write(total[i]);
    }



}

