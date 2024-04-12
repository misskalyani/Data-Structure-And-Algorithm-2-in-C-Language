#include<stdio.h>
#include<stdlib.h>
void recdfs(int m[5][5],int n ,int v)
{
	int w;
	static int visited[20]={0};
	visited[v]=1;
	printf("v%d",v+1);
	for(w=0;w<n;w++)
	{
		if((m[v][w]==1) &&(visited[w]==0))
		recdfs(m,n,w);
	}
}
void main()
{
	int m[20][20],i,n,j;
	printf("Enter Limit : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			m[i][j]=0;
			if(i!=j)
			{
				printf("Enter Edge Betwwen v%d v%d : ",i,j);
				scanf("%d",&m[i][j]);
			}
		}
	}
	printf("\nAjacency Matrix::\n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" \t%d",m[i][j]);
		}
		printf("\n");
	}
	printf("\n the depth first search traverse is : ");
	recdfs(m,5,0);
}

