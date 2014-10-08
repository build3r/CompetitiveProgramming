#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,a[5],b[5],sum,val,i,x,m;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
        val=1;
    i=0;
        while(i<4)
        {
            m = 1;
            x=0;sum=0;
            while(b[i]>0)
            {
            sum=sum+(b[i]%10)*m;
            x++;
            b[i]=b[i]/10;
            m*=2;
            }
            if(sum!=a[i])
            {
                val=0;
                break;
            }
            i++;
        }
                if(val==1)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;

}
