#include<stdio.h>
int main()
{
	int a[20][20],i,n,j;
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
}
