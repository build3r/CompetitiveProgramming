#include<stdio.h>
typedef struct
{
    int i,j;
    char n[100];
}r;
int main()
{ FILE *fp;
 r s;
if((fp=fopen("c:\st.dat","wb"))==NULL)
printf("error file open\n");
else
{
    scanf("%s %d %d",s.n,&s.i,&s.j);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    fp=fopen("c:\st.dat","rb");
    fread(&s,sizeof(s),1,fp);
    printf("%s %d %d",s.n,s.i,s.j);
    fclose(fp);
}
//int a,b,c,d;
//char name[100],n[100];

/*if((fp=fopen("C:\yum.txt","w"))==NULL)
printf("error file open\n");
else
//fp=fopen("C:\yum.txt","w");
{
    scanf("%s %d %d",name,&a,&b);
    fprintf(fp,"%s\n %d\n %d",name,a,b);
    fclose(fp);
    fp=fopen("C:\yum.txt","r");
    fscanf(fp,"%s %d %d",n,&c,&d);
    printf("name=%s\na=%d\nb=%d\n",n,c,d);
    fclose(fp);
}*/
return 0;
}
