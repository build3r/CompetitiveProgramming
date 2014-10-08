#include<stdio.h>
#include<conio.h>
int t[20],n,he,h[100],k,i,j,v;
void heap()
{
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=h[k];
        he=0;
        while(!he && 2*k<=n)
        {
            j=2*k;
            if(j<n)
               {
                   if(h[j]<h[j+1])
                   j++;

               }
               if(v>=h[j])
               he=1;
               else
               {h[k]=h[j];
               k=j;
               }

        }
        h[k]=v;

    }
}
/*int heap()
{
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        h=0;
        while(!h && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                {
                    j++;
                }
            }
            if(v>=H[j])
            {
                h=1;
            }
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
    return 0;
}*/
int main()
{
    int x;
    time_t(seed);
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        h[x]=rand()%100;
        //scanf("%d",&h[x]);
    }
    printf("enter the elements\n");
      for(x=1;x<=n;x++)
    {
        printf("%d ",h[x]);
    }
    printf("\n");
    heap();
    for(x=1;x<=n;x++)
    {
        printf("%d  ",h[x]);
    }
    printf("\n");
    while(n>=0)
    {
        t[x++]=h[1];
        h[1]=h[n];
        n--;
        heap();
    }
    for(k=x-1;k>=0;k--)
    {
        printf("->%d\t",t[k]);
    }
    return 0;
}
