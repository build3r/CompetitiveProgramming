#include<stdio.h>
#include<stdlib.h>

#define size 5

int main()
{
  char *str,*name[size];
  int i,n;

  scanf("%d",&n); // trying to scan 'n' from the user is resulting in seg fault in FEDORA 16
  fflush(stdin);
  for(i = 0; i < n; i++)
  {
    str = (char*)malloc(20*sizeof(char));
    printf("enter  a name :\n");
    gets(str);
    name[i]=str;
  }

  printf("the entered names  :\n");
  for(i = 0; i < n; i++)
     puts(name[i]);
     return 0;
}

