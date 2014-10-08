#include<stdio.h>
int main()
{
    long int i,j,t,ac=0,rc=0,gcd;
    unsigned long long int n,s,rf,ms,mrf;
    scanf("%d",&t);
    while(t--)
    {
        rc=0;
        scanf("%d %d %d",&n,&ms,&mrf);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&s,&rf);
            if(s>ms || rf>mrf)
                rc++;
        }
        scanf("%d",&ac);
        if(rc==0)
            printf("0\n");
        else if(rc%ac==0)
        {
            printf("%d\n",rc/ac);
        }

        else { for( j=1;j<=ac && j<=rc;j++){

if(ac%j==0 && rc%j == 0 ){

                     gcd=j;
   }
    }
    printf("%d/%d\n",rc/gcd,ac/gcd);
    }
    }
    return 0;
}

