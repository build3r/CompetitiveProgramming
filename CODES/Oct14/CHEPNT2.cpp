#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,k;
int color[100][100],white_neb[100][100];
int range_row[101][1000];
int range_col[101][1000];
int freq_of_size[101];
int chk_row[100][100],chk_col[100][100];

void init_chk()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			chk_row[i][j]=0;
			chk_col[i][j]=0;
		}
	}
}

void set_IWN()
{
	int i,j,right,down,set_row,set_col;
	int count=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(color[i][j]==1 && chk_row[i][j]==0)
			{
				count=1;
				right=j+1;

				while(white_neb[i][right]==1)
				{
					count++;
					right++;
				}

				for(set_row=j ; set_row<right ; set_row++)
				{
					white_neb[i][set_row]=count;
					chk_row[i][set_row]=1;
				}
			}

			if(color[i][j]==1 && chk_col[i][j]==0)
			{
				count=0;
				down=i+1;

				while(white_neb[down][j]==1)
				{
					count++;
					down++;
				}

				for(set_col=i ; set_col<down ; set_col++)
				{
					white_neb[set_col][j]=count;
					chk_col[set_col][j]=1;
				}
			}
		}
	}





}

void find_steps(int black_row[],int black_col[])
{

}

int main()
{
	int i,j;

	cin>>n>>m>>k;

	int black_row[k],black_col[k];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			color[i][j]=1;
			white_neb[i][j]=0;
		}
	}

	for(i=0;i<k;i++)
	{
		cin>>black_row[i]>>black_col[i];
		color[black_row[i]-1][black_col[i]-1]=0;
	}

	init_chk();
	set_IWN();
	//find_steps(black_row,black_col);
	return 0;
}
