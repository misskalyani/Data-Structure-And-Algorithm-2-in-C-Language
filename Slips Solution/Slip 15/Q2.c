#include<stdio.h>
#include<stdlib.h>
int cost[8][8]={
			   {0,999,999,999,999,999,999,999},
			   {30,0,999,999,999,999,999,999},
			   {100,80,0,999,999,999,999,999},
			   {999,999,120,0,999,999,999,999},
			   {999,999,999,150,0,25,999,999},
			   {999,999,999,100,999,0,90,140},
			   {999,999,999,999,999,9990,100},
			   {170999,999,999,999,999,999,0},
		       };
void dijekstra(int v,int n)
{
	int i,j,u,w,count,min;
	int distance[10],visited[10]={0};
	visited[v]=1;
	for(i=0;i<n;i++)
	{
		distance[i]=cost[v][i];
	}
	count=2;
	while(count<n)
	{
		min=999;
		for(i=0;i<n;i++)
			if(visited[i]==0 && distance[i]<min)
			{
				min=distance[i];
				u=i;
			}
		visited[u]=1;
		for(w=0;w<n;w++)
			if(distance[u]+cost[u][w]<distance[w])
				distance[w]=distance[u]+cost[u][w];
		count++;		
	}
	printf("\nShortest Distance from vertex %d are : \n",v);
	for(i=0;i<n;i++)
	    printf("%d\t",distance[i]);
}
void main()
{
	dijekstra(4,8);
}
