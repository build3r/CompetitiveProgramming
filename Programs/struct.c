#include<stdio.h>
typedef struct
{
    char s[50];
    long int sal;
    struct dob
    {
        int day,mon,yr;
    }db;
}st;
void dis(st *p);
int main()
{
    st s1[2],*p;
    int i=2;
    p=&s1;

    //scanf("%d",&s1.db.day);
    //printf("%d",s1.db.day);
    while(i--)
    {
    scanf("%s %ld %d %d %d",p->s,&((*p).sal),&p->db.day,&p->db.mon,&(p->db.yr));
    p++;
    }
    dis(&s1);
return 0;
}
void dis(st *p)
{
    int i=2;
    while(i--)
    {
        printf("%s %ld %d %d %d",p->s,p->sal,p->db.day,p->db.mon,p->db.yr);
        p++;
    }
    return;
}
