#include<stdio.h>
#include<string.h>

void table(char *s, int *t);
int main()
{
    int i,j,k,n,m;
    char txt[200]="JIM_SAW_ME_IN_A_BARBERSHOP",s[100]="BARBER";
    int tab[500];
    /*printf("Text\n");
    scanf("%s",txt);
    printf("pattern\n");
    scanf("%s",s);*/
    table(s,tab);
    m=strlen(s);
    n=strlen(txt);
    i=m;
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
         i=i+tab[txt[i]];
    }
printf("Pattern Not found\n");
return 0;
}
void table(char *s,int *tab)
{
    int l,i,j,k;
    l=strlen(s);
    for(i=0;i<l-2;i++)
    tab[s[i]]=l-1-2;
    for(i=0;i<500;i++)
    tab[i]=1;
    printf("The shift for %c is :  %d\n",i,tab[i]);
return;
}
