#include<stdio.h>
void indegree(int a[20][20],int n)
{
	int i,j,ind;
	for(i=1;i<=n;i++)
	{
		ind=0;
		for(j=1;j<=n;j++)
		{
			ind=ind+a[j][i];
		}
		printf("\nIndeggre v%d=%d",i,ind);
		
	}
	
}
void outdegree(int a[20][20],int n)
{
	int i,j,outd;
	for(i=1;i<=n;i++)
	{
		outd=0;
		for(j=1;j<=n;j++)
		{
			outd=outd+a[i][j];
		}
		printf("\nOutdegree v%d=%d",i,outd);
		
	}
	
}
void totaldegree(int a[20][20],int n)
{
	int i,j,total;
	for(i=1;i<=n;i++)
	{
		total=0;
		for(j=1;j<=n;j++)
		{
			total=total+a[i][j]+a[j][i];
		}
		printf("\nTotaldegree v%d=%d",i,total);
		
	}
	
}
int main()
{
	int a[20][20],i,n,j;
	printf("Enter Limit : ");
	scanf("%d",&n);
	printf("Enter Graph in the matrix format : \n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	}
   indegree(a,n);
   outdegree(a,n);
   totaldegree(a,n);

}
