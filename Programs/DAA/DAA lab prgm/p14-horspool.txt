#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
int t[max];
void shifttable(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<max;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]]=m-1-j;
}
int horspool(char s[],char p[])
{
    int i,j,k,m,n;
    n=strlen(s);
    m=strlen(p);
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m) && (p[m-1-k]==s[i-k]))
            k++;
        if(k==m)
            return (i-m+1);
        else
            i+=t[s[i]];
    }
    return -1;
}
int main()
{
    char s[50],p[50];
    int pos;
    printf("enter text :\n");
    gets(s);
    printf("enter pattern:\n");
    gets(p);
    shifttable(p);
    pos=horspool(s,p);
    if(pos>=0)
        printf("Pattern found at position %d\n",pos+1);
    else
        printf("Pattern not found in text\n");
    return 0;
}