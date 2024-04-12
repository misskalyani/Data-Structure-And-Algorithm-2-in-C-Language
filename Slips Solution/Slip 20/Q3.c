#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
	int data[MAX];
	int front,rear; 
}queue;
void initq(queue*q)
{
	q->rear=q->front=-1;
}
int isempty(queue*q)
{
    return (q->rear==q->front);
}
void addq(queue*q,int n)
{
	 q->data[++q->rear] = n;	
}
int delq(queue*q)
{
	 return (q -> data[++q -> front]);   
}
void bfs(int a[10][10],int n)
{
	int i,v,w,j;
	int visited[10]={0};
	queue q;
	initq(&q);
	printf("\nBFS TRAVEL :: \n");
	v=0;
	visited[v]=1;
	addq(&q,v);
	while(!isempty(&q))
	{
		v=delq(&q);
		printf("v%d\t",v+1);
		for(w=0;w<n;w++)
		{
			if((a[v][w]==1) && (visited[w]==0))
			{
				addq(&q,w);
				visited[w]=1;
			}
		}
	}
}

int main()
{
	int a[10][10]={
				  {0,0,1,1,0},
				  {0,0,1,0,1},
				  {0,1,0,0,0},
				  {0,0,0,0,1},
				  {0,0,0,0,0},
				  };
     bfs(a,5);
}
