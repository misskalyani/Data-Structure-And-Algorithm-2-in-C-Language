#include<stdio.h>
#define n 4
void printmatrix(int cost[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cost[i][j]==999)
				printf("%4s","INF");
			else
				printf("%4d",cost[i][j]);
		}
		printf("\n");
	}
}
void floydwarshall(int cost[][n])
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][k]+cost[k][j]<cost[i][j])
					cost[i][j]=cost[i][k]+cost[k][j];
			}
		}
	}
	printmatrix(cost);
}
int main()
{
	int cost[4][4]={
				    {0,8,999,1},
					{999,0,1,999},
					{4,999,0,999},
					{999,2,9,0},	
				   };
	floydwarshall(cost);
}
