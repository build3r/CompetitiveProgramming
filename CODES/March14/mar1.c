    #include<stdio.h>
    int main()
    {
     int t,n,f=0,max=0,mi=0,i,j,v=0;
    scanf("%d",&t);
    while(t--)
    { v=max=mi=f=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&j);
    if(max<=j)
    {
    max=j;
    mi=i;
    v=max+i;
    }
    if((v-(i-mi))<j)
    {
        v+=(i-mi);
        mi=i;
        f=1;
        cout<<"v = "<<v<<endl;
    }
    }
    if(f)
        v--;

    printf("%d\n",v);
    }
    return 0;
    }
