#include<stdio.h>
int own[10005],c[10005];
int i,t,j,b,n,q,x,y,opt;
int v[10005];
int main()
{

// freopen("in.txt","r",stdin);
scanf("%d",&t);
while(t--)
{

scanf("%d",&n);


for(i=1; i<=n; i++)
{

scanf("%d",&c[i]);
own[i]=i;
}

scanf("%d",&q);
for(i=0; i<q; i++)
{
scanf("%d",&opt);
if(!opt)
{

scanf("%d %d",&x,&y);
b=0;

while(own[x]!=x)
{

v[b]=x;
b++;
x=own[x];

}

for(j=0; j<b; j++)
{
own[v[j]]=x;

}
b=0;
while(own[y]!=y)
{
v[b]=y;
b++;
y=own[y];

}

for(j=0; j<b; j++)
{
own[v[j]]=y;
}
if(x==y)
{
printf("Invalid query!\n");
continue;
}
if(c[x]>c[y])
{
own[y]=x;
}
else if(c[x]<c[y])
{
own[x]=y;
}
else
continue;
}
else
{
scanf("%d",&x);
b=0;
while(own[x]!=x)
{
v[b]=x;
b++;

//
x=own[x];

}
for(j=0; j<b; j++)
{
own[v[j]]=x;

}
printf("%d\n",x);
}
}
}
return 0;
}
