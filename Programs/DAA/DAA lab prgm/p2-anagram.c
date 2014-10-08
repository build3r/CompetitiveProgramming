#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s1[20],s2[20];
    int i,j;
    printf("enter 1st word: ");
    scanf("%s",s1);
    printf("enter 2nd word: ");
    scanf("%s",s2);
    i=0;
    while(s1[i]!='\0')
    {
        j=0;
        while(s2[j]!='\0')
        {
            if(s1[i]==s2[j] && s1[i]!=' ')
            {
                s1[i]=' ';
                s2[j]=' ';
                break;
            }
            j++;
        }
        i++;
    }
    if(strcmp(s1,s2))
        printf("Not Anagram\n");
    else
        printf("Anagram\n");
    return 0;
}
