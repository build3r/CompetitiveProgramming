#include<stdio.h>
int main()
{
    int i,j;
    char str[50],sub[50];
    gets(str);
    gets(sub);
    i=0;
       j=stst(str,sub);
       if(j==-1)
       printf("string was not found\n");
       else
       printf("Match was fount at %d th pos\n",j);
       return 0;
}

int stst(char str[],char sub[])
{
    int i=0,j=0,k=0,flag=0;
    while(str[i]!=NULL)
    {
        j=0;
        flag=0;
        k=i;
        while(sub[j]!=NULL)
        {

            flag=flag+(str[k++]-sub[j++]);
            //printf("Flag=%d\n",flag);
        }
        if(flag==0)
        return i;
        i++;
    }
return -1;
}
