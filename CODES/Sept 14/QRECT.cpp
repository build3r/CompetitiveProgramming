#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define gc getchar()
long long n,m, a[200002],C[200002], q, l, k,X,Y;

long long data[200002];
long long ans[200002];
long long sum[200002];
long long sum2[200002];
long long K = 150;

inline long long inp()
{
    long long n=0,s=1;
    char c;
    for(c=gc; c<48||c>58; c=gc)
        if(c=='-')s=-1;
    for(; c>47&&c<59; c=gc)
        n=n*10+c-48;
    return n*s;
}
inline void Write(long long int a)
{
    char snum[20];
    int i=0;
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

inline void add(long long pos, long long val)
{
    for(; pos < k; pos |= (pos + 1)) sum[pos] += val;
}
inline long long fnd(long long pos)
{
    long long ans = 0;
    for(; pos >= 0; (pos &= (pos + 1))--) ans += sum[pos];
    return ans;
}
inline void add2(long long pos, long long val)
{
    for(; pos >= 0; (pos &= (pos + 1))--) sum2[pos] += val;
}
inline long long fnd2(long long pos)
{
    long long ans = 0;
    for(; pos < k; pos |= (pos + 1)) ans += sum2[pos];
    return ans;
}

int main()
{

    scanf("%lld %lld", &n,&q);
    for(int i = 0; i < n; i++)
    {
        //scanf("%lld", &a[i]);
        a[i]=inp();
        data[i] = a[i];
        C[i]=a[i];
    }
    sort(data, data + n);
    k = unique(data, data + n) - data;
    //cout<<"k = "<<k<<endl;
    for(int i = 0; i < n; i++) a[i] = lower_bound(data, data + k, a[i]) - data;


    for(int i = 0; i < k; ++i) sum[i] = sum2[i] = 0;
//Finding inversion count of array

    long long l = 0, r = -1, tot=0,inv=0;
    while(r < n-1)
    {
        ++r;
        add(a[r], 1);
        add2(a[r], 1);
        tot += fnd2(a[r] + 1);
    }
    while(r > n-1)
    {
        add(a[r], -1);
        add2(a[r], -1);
        tot -= fnd2(a[r] + 1);
        --r;
    }
    while(l > 0)
    {
        --l;
        add(a[l], 1);
        add2(a[l], 1);
        tot += fnd(a[l] - 1);
    }
    while(l < 0)
    {
        add(a[l], -1);
        add2(a[l], -1);
        tot -= fnd(a[l] - 1);
        ++l;
    }

// for(ll i = 0; i < q; ++i) {
// printf("%d\n", tot);
// }
    //printf("\n");
//finding inversion count for all (X,Y) swaps
    for(int j=0; j<q; j++)
    {
        inv=tot;
        X=inp();
        Y=inp();
        X--;
        Y--;
        if(X==Y || C[X]==C[Y])
        {
            inv=inv;
        }
        else if(X<Y)
        {
            for(int i=X; i<Y-1; i++)
            {
                if(C[i+1]>C[X])inv++;
                if(C[i+1]<C[X])inv--;
                if(C[i+1]>C[Y])inv--;
                if(C[i+1]<C[Y])inv++;
            }

            if(C[X]>C[Y])
                inv-=1;
            else
                inv+=1;
        }
        else
        {
            for(int i=X; i>Y+1; i--)
            {
                if(C[i-1]>C[X])inv--;
                if(C[i-1]<C[X])inv++;
                if(C[i-1]>C[Y])inv++;
                if(C[i-1]<C[Y])inv--;
            }

            if(C[X]>C[Y])
                inv+=1;
            else
                inv-=1;
        }
        Write(inv);
        //printf("%lld\n", inv);
    }
    return 0;
}
