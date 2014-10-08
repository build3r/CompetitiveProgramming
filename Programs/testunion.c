#include<stdio.h>
typedef union
{
    int a[2],b;
}s;

int main()
{
    s d;

    printf("size:%d",sizeof(d));
    scanf("%d",&d.a[0]);
    printf("a=%d\n",d.a[0]);
    scanf("%d",&d.b);
    printf("b=%d\n",d.b);
    printf("a=%d\n",d.a[0]);
    return 0;
}
