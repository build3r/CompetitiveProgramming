#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str1[100],str2[100],*p;
    //int k=0;
    //scanf("%s",str1);
    //fflush(stdin);
    gets(str1);
    //str2=str1;
    //gets(str2);
    p=str1;
    p=strtok(str1," ");
    //printf("\n->%s\n",p);
    while(p)
    {
        printf("\n->%s\n",p);
        p=strtok(NULL," ");
    }
    //printf("\nstr1=%s\nsearched=%s\n",str1,strstr(str1,"Ahmed"));
    return 0;
}
