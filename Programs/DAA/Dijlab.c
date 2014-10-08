#include<stdio.h>
#include<conio.h>
int c[10][10], d[10], s[10], n, dist[10], temp[10];
int main()
{
	int i, j, k, min, tot;
	//clrscr();
 printf("\nEnter number of nodes:");
	scanf("%d", &n);
  printf("\n Enter the cost matrix no path then enter 99:\n");
	for (i =1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
		  printf("\t Enter cost from % d to % d:", i, j);
		  fflush(stdin
           );
			scanf("%d ", &c[i][j]);
		}
//	clrscr();
  printf("\nThe matrix is:\n ");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%5d ", c[i][j]);
		printf("\n ");
	}
	for (i = 1; i <= n; i++)
	{
		dist[i] = i;
		d[i] = c[1][i];
	}
	s[1] = 1;
	dist[1] = 99;
  printf("\nThe shortest distance is:");
	for (i = 2; i <= n; i++)
	{
		min = mindist();
		s[i] = min;
		dist[min] = 99;
		for (j = 2; j <= n; j++)
		{
			if (dist[j] != 99)
			{
				if (d[j] > d[min] + c[min][j])
					d[j] = d[min] + c[min][j];
			}
		}
		printf("\n \t ");
		for (k = 1; k <= n; k++)
		{
			if (k <= i)
				printf("%d ", s[k]);
			else printf(" ");
		}
		printf("\t \t ");
	}
	printf("\n \t");
	for (i = 2; i <= n; i++)
	{
	  printf("\nCost from 1 ->%d:", i);
		if (d[i] >= 99)
			printf("INF ");
		else
		printf("%d ", d[i]);
		//getch();
		return 0;
	}
}

int mindist()
{
	int i, min = 100, ret;
	for (i = 1; i <= n; i++)
	{
		if (dist[i] == 99)
			continue;
		if (d[i] < min)
		{
			min = d[i];
			ret = i;
		}
	}
	return (ret);
}
