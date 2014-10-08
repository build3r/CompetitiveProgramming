#include<stdio.h>
int w[10],v[10],s[20][20],c,val;
int mfk(int ,int );
int main()
{
    int i,j,k,n;
    printf("Enter the no. of eles\n");
    scanf("%d",&n);
    printf("enter the weights and values\n");
    for(i=0;i<n;i++)
    scanf("%d %d",&w[i],&v[i]);
    for(i=0;i<n;i++)
    printf("%d %d\n",w[i],v[i]);
    printf("enter the capacity\n");
    scanf("%d",&c);
    for(i=0;i<20;i++)
    s[0][i]=0;
    for(i=0;i<10;i++)
    s[i][0]=0;
    for(i=1;i<20;i++)
    for(j=1;j<10;j++)
    s[i][j]=-1;
    printf("the max value that can be stored is %d\n\n\n",mfk(n,c));
    for(i=0;i<n;i++)
    {printf("\n");
    for(j=0;j<c;j++)
    printf("%d\t",s[i][j]);
    }

    return 0;
}

int mfk(int i,int j)
{
    int l=0,m=0;
    if(s[i][j]<0)
    {
       // printf("Inside if s[i][j]=%d\n",s[i][j]);
        if(j<w[i-1])
        val=mfk(i-1,j);
        else
        {
                l=mfk(i-1,j);
                m=(v[i-1]+mfk(i-1,(j-w[i-1])));
                printf("l=%d  m=%d\n",l,m);
                if(l>m)
             s[i][j]=val=l;
            else
             s[i][j]=val=m;
        }
    }
    printf("i=%d j=%d s[i][j]=%d\n ",i,j,s[i][j]);
    return s[i][j];
}
