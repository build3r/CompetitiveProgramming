#include<stdio.h>
#include<string.h>
int t[100];
void table(char *s);
int main()
{
    int i,j,k,n,m;
    char txt[200]="SHABAZ AHMED IS GOING TO LEAVE FOOTPRINTS ON THE SANDS OF TIME",s[100]="AHMED";

    /*printf("Text\n");
    scanf("%s",txt);
    printf("pattern\n");
    scanf("%s",s);*/
    table(s);
    m=strlen(s);
    n=strlen(txt);
    i=m-1;
    while(i<n)
    {
        k=0;
        while(k<m && (s[m-1-k]==txt[i-k]))
        k++;
        if(k==m)
        {
         printf("Mattch found at: %d",i-m+1);
         return 0;
        }
         else
         i=i+t[txt[i]];
    }
printf("Pattern Not found\n");
return 0;
}
void table(char *s)
{
    int l,i,j,k;
    l=strlen(s);
    for(i=0;i<100;i++)
    t[i]=l;
    for(i=0;i<l-2;i++)
    t[s[i]]=l-1-i;
//for(i=0;i<100;i++)
    //printf("The shift for %c is :  %d\n",i,t[i]);
return;
}
