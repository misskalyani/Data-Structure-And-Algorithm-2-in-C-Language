#include<stdio.h>
int main()
{
	int a[20][20],i,n,j,sum_indegree,sum_outdegree,total;
	printf("Enter Limit : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("Enter Edge Betwwen v%d v%d : ",i,j);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("\nAjacency Matrix::\n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" \t%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\nVertex\tsum of indegree\tsum of outdegree\ttotal\n");
	for(i=1;i<=n;i++)
	{
		sum_indegree=sum_outdegree=0;
		for(j=1;j<=n;j++)
		{
			sum_indegree=sum_indegree+a[j][i];
			sum_outdegree=sum_outdegree+a[i][j];
		}
		printf("\nv%d\t    \t%d\t    \t%d\t    \t%d\t",i,sum_indegree,sum_outdegree,sum_indegree+sum_outdegree);
	}
}
