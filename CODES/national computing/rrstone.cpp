    #include<iostream>
    #include<cstdio>
    using namespace std;
    long long int i,j,k,n,a[100000],mx=0,smx=0,m;
    int main()
    {

scanf("%lld",&n);
scanf("%lld",&k);
    if(k==0)
        {  for(i=0;i<n;i++)
             {scanf("%lld",&j);
            printf("%lld ",j);}}
    else{
    for(i=0;i<n;i++)
    {
    scanf("%lld",&a[i]);
        if(a[i]>mx)
    mx=a[i];
    }
if(k!=0){
    for(i=0;i<n;i++)
    {
    a[i]=mx-a[i];
    if(smx<a[i])
    smx=a[i];
    }
    if(k%2==0)
        for(i=0;i<n;i++)
        a[i]=smx-a[i];
}
    for(i=0;i<n;i++)
    printf("%lld ",a[i]);
    }
    printf("\n");
    return 0;
    }

