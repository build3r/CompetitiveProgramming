#include<stdio.h>
int hsort[25],n,i;
void bottomupheap(int,int);
void heapify();
int main()
{
	int temp;
	printf("enter no. of element: \n");
	scanf("%d",&n);
	printf("enter elements to be sorted\n");
	for(i=1;i<=n;i++)
		scanf("%d",&hsort[i]);
	heapify();
	for(i=n;i>=2;i--)
	{
		temp=hsort[1];
		hsort[1]=hsort[i];
		hsort[i]=temp;
		bottomupheap(1,i-1);
	}
	printf("sorted array:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",hsort[i]);
	return 0;
}
void heapify()
{
	int i;
	for(i=n/2;i>=1;i--)
		bottomupheap(i,n);
}
void bottomupheap(int i,int n)
{
	int j,element;
	j=2*i;
	element=hsort[i];
	while(j<=n)
	{
		if((j<n)&&(hsort[j]<hsort[j+1]))
		j=j++;
		if(element>=hsort[j])
		break;
		hsort[j/2]=hsort[j];
		j=2*j;
	}
	hsort[j/2]=element;
}
