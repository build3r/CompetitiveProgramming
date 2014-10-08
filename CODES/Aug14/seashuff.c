
#include<stdio.h>
int a[100000];
int main()
{
    int n,i,s1,s2,d1,d2,t1,t2,l,r;
    scanf("%d",&n);
    s1=s1=0;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(i<(n/2))
            s1+=a[i];
        else
            s2+=a[i];
    }
    d1=s1-s2;
    printf("1\n");
    l=n/2;
    r=n;
    while(l>0 && r<=n)
    {
        if(d1>0)
        {
            t1=s1-a[l-1];
            t1=t1+a[r-1];
            t2=s2-a[r-1];
            t2=t2+a[l-1];
            if(abs(t1-t2)<abs(d2))
                {printf("%d %d ",l,r);
                    return 0;
                }
            else
            {
                l--;
            }
        }
        else
        {
            t1=s1-a[l-1];
            t1=t1+a[r-1];
            t2=s2-a[r-1];
            t2=t2+a[l-1];
            if(abs(t1-t2)<abs(d2))
                {printf("%d %d ",l,r);
                    return 0;
                }
            else
            {
            r++;
            }
        }
    }
    printf("%d %d\n ",(rand()%(n/2)),(n/2)+(rand()%(n/2)));

    return 0;
}
