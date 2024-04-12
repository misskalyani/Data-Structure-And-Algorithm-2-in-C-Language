
#include<stdio.h>
int g[10][10],visited[10]={0},n;
void dfs(int i)
{
	int j;
	printf("\n%d\t\n",i);
	visited[i]=1;
	for(j=1;j<=n;j++)
	{
		if(g[i][j]==1   &&    visited[j]==0)
		{
		 	dfs(j);
		}
	}
}
int main()
{
	int i,j;
	printf("ENter LImit :: ");
	scanf("%d",&n);
	printf("Adjacency Matrix Of Graph is ::\n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("\t%d",&g[i][j]);
			
		}
	}
	dfs(1);
}
