#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
int main()
{
  int t,n,i,j,x,y,ans,px,py,f;
  scanf("%d",&t);
  while(t--)
  {
  f=0;
  px=py=ans=0;
    scanf("%d %d",&x,&y);
    if(x==0 && y==0)
    {
    printf("YES\n");
    break;
    }
    if(x%2==0)
    px=1;
    if(y%2==0)
    py=1;
    if(x>0 && y>0)
    {
        if(px)
        {
            if(py)
            {
                if(x<y)
                f=1;
            }
            else
            {
                f=0;
            }
        }
        else
        {
            if(py)
            f=1;
            else
            {
                if(x<=y)
                f=1;
            }
        }
    }
    if(x<0 && y>0)
    {
        if(px)
        {
            if(py)
            f=1;
            else
            {
                if(y<x)
                f=1;
            }

        }
        else
        {
            if(py)
            {
                if(y>x)
                f=1;
            }
            else
            f=0;
        }
    }
    if(x<0 && y<0)
    {
        if(px)
        {
            if(py)
            f=1;
            else
            {
                if(x>y)
                f=1;
            }
        }
        else
        {
            if(py)
            {
                if(y>x)
                f=1;
                else
                f=0;
            }
        }
    }
    else
    {
        if(px)
        {
            if(py)
            {
                if(y>=x)
                {
                    f=1;
                }
            }
            else
            {
                f=0;
            }
        }
        else
        {
            if(py)
            f=1;
            else
            if(x>y)
            {
                f=1;
            }
        }
    }
    if(f==1)
    printf("YES\n");
    else
    printf("NO\n");
  }
return 0;
}
