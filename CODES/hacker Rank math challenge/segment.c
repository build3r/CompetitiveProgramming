#include<stdio.h>
int min(double x1, double x2)
{
   if( x1<x2)
    return x1;
   else
    return x2;
}
int max(double x1, double x2)
{
    if(x1>x2)
        return x1;
    else
        return x2;
}
int main()
{
    int x1,y1,x2,y2,xm,ym,t,x,y;
    double A1,A2,B1,B2,C1,C2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&xm,&ym);
        A1 = ym;
        B1 = xm;
        C1 = A1*xm+B1*ym;
        A2 = y2-y1;
        B2 = x2-x1;
        C2 = A2*x1+B2*y1;
        double det = A1*B2 - A2*B1;
        if(det == 0){
            if(x1==0 || y1==0 x1==xm || y1==ym || x2==0 || y2==0 || x2==xm || y2==ym )
            printf("NO\n");
            else
            printf("YES\n");

            continue;
        }else{
             x = (B2*C1 - B1*C2)/det;
             y = (A1*C2 - A2*C1)/det;
            //printf("x = %ld   y= %ld \n",x,y);
        }
        if((x<min(x1,x2) || x>max(x1,x2) || x<min(xm,0) || x>max(xm,0)) || (y<min(y1,y2) || y>max(y1,y2) || y<min(ym,0) || y>max(ym,0)))
       printf("YES\n");
        else
            printf("NO\n");
    }
     return 0;
}
