#include<stdio.h>
#include<conio.h>
int b[20][20],d[20][20],c,n;
int  main()
{
    int a[20][20]={{0,5,9999,6,9999},{5,0,1,3,9999},{9999,1,0,4,6},{6,3,4,0,2},{9999,9999,6,2,0}};
    int e[20][3];
    int nod=0,val=0,i,j,k,t,m=0,posx,posy;
    //clrscr();
    printf("\nEnter the value of n ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix ");
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=(i==j?0:a[i][j]);
            m=m+(b[i][j]?1:0);
            c[i][j]=0;
            d[i][j]=0;
        }
    }*/
    c=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i!=j&&a[i][j]!=9999)
            {
               e[c][0]=i;
               e[c][1]=j;
               e[c][2]=a[i][j];
               c++;
//printf("\n %d  %d %d",e[i][0],e[i][1],e[i][2]);

            }
        }
    }
     printf("\nbefore sort c=%d\n\n",c);
      for(i=0;i<c;i++)
    printf("\n %d  %d %d",e[i][0],e[i][1],e[i][2]);

    for(i=0;i<c;i++)
    {
        for(j=0;j<c-i-1;j++)
        {
            if(e[j+1][2]<e[j][2])
            {
                //printf("Inside if\n");
                t=e[j+1][2];
                e[j+1][2]=e[j][2];
                e[j][2]=t;
                t=e[j+1][0];
                e[j+1][0]=e[j][0];
                e[j][0]=t;
                t=e[j+1][1];
                e[j+1][1]=e[j][1];
                e[j][1]=t;

            }
        }

    }
    printf("\nAfter sort c=%d\n",c);
    for(i=0;i<c;i++)
    printf("\n %d  %d %d",e[i][0],e[i][1],e[i][2]);
    for(i=0;i<c;i++)
    {
        if(i<2)
        {
            printf("If\n");
            b[e[i][0]][e[i][1]]=e[i][2];
            b[e[i][1]][e[i][0]]=e[i][2];
            d[e[i][0]][e[i][1]]=1;
            d[e[i][1]][e[i][0]]=1;
            val=val+e[i][2];
        }
        else
        {
            if(!cy(e,i,d))
            {
                printf("Cycle=false\n");
                 b[e[i][0]][e[i][1]]=e[i][2];
            b[e[i][1]][e[i][0]]=e[i][2];
            d[e[i][0]][e[i][1]]=1;
            d[e[i][1]][e[i][0]]=1;
            val=val+e[i][2];
            }
        }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d    ",b[i][j]);

        }
        printf("\n");
    }
    printf("Maximum tree size is %d\n",val);
    return 0;
}

int cy(int e[20][3],int h,int f[20][20])
{
    printf("in cy\n");
    int j,i,k;
    int g[20][20];
      for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            g[i][j]=d[i][j];
        }
    }
    g[e[h][0]][e[h][1]]=1;
    g[e[h][1]][e[h][0]]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",g[i][j]);
        }
        printf("\n");
    }
        for(k=2;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]==1)
                g[i][j]=1;
                else if(g[i][k]==1)
                if(g[k][j]==1)
                g[i][j]=1;
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",g[i][j]);
        }
        printf("\n");
    }
    if(g[e[h][0]][e[h][0]]==g[e[h][0]][e[h][0]]==1)
    return 1;
    else
    return 0;
}
