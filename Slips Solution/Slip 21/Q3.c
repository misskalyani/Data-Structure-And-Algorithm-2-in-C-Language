#include<stdio.h>
#include<conio.h>
int i,n,j,min,u,v,a,b;	
int cost[10][10],visited[10]= {0},ne=1,mincost=0;
void main()
{
	printf("\nEnter n Number Of Vertex : ");
	scanf("%d",&n);
	printf("\nEnter Graph in the matrix format : \n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
		
     }
     printf("\nAdjacency Matrix :: \n");
     for(i=1;i<=n;i++)
     {
     	for(j=1;j<=n;j++)
     	{
     		printf("%d\t",cost[i][j]);
		 }
		 printf("\n");
	 }
		visited[1]=1;
		printf("\n");
		for(ne=1;ne<=n;ne++)
		{
			for(i=1,min=999;i<=n;i++)
			{	
				for(j=1;j<=n;j++)
				{
				
					if(cost[i][j]<min && visited[j]==0)
					{
				    	min=cost[i][j];
						a=u=i;
						b=v=j;	
					}
				}
			}
					if(visited[u]==0 || visited[v]==0)
					{
						printf("\n Edge %d : (%d %d) min : %d",ne,a,b,min);
						mincost+=min;
						visited[v]=1;
					}
					cost[a][b]=cost[b][a]=999;
		        
		}
		printf("\n Minimum Cost = %d",mincost);
	
}
